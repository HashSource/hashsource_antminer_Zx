uint32_t __cdecl rt_ringbuffer_get(rt_ringbuffer *rb, uint8_t *ptr, uint16_t length)
{
  uint32_t size; // [sp+14h] [bp+14h]

  pthread_mutex_lock(&rb->ringbuf_lock);
  size = rt_ringbuffer_data_len(rb);
  if ( rb->ringbuffer_type == ringbuffer_type::POLL_TYPE )
  {
    if ( !size )
    {
      pthread_mutex_unlock(&rb->ringbuf_lock);
      return 0;
    }
    if ( length > size )
      length = size;
  }
  else if ( rb->ringbuffer_type == ringbuffer_type::BLOCK_TYPE )
  {
    while ( length > size )
    {
      pthread_cond_wait(&rb->notempty, &rb->ringbuf_lock);
      size = rt_ringbuffer_data_len(rb);
    }
  }
  if ( rb->buffer_size - (*((_WORD *)rb + 2) >> 1) <= length )
  {
    memcpy(ptr, &rb->buffer_ptr[*((_WORD *)rb + 2) >> 1], rb->buffer_size - (*((_WORD *)rb + 2) >> 1));
    memcpy(
      &ptr[rb->buffer_size - (*((_WORD *)rb + 2) >> 1)],
      rb->buffer_ptr,
      length - (rb->buffer_size - (*((_WORD *)rb + 2) >> 1)));
    *((_BYTE *)rb + 4) = *((_BYTE *)rb + 4) & 0xFE | ((*((_BYTE *)rb + 4) & 1) == 0);
    *((_WORD *)rb + 2) = *((_WORD *)rb + 2) & 1
                       | (2 * ((length + (*((_WORD *)rb + 2) >> 1) - rb->buffer_size) & 0x7FFF));
    pthread_cond_signal(&rb->notfull);
    pthread_mutex_unlock(&rb->ringbuf_lock);
  }
  else
  {
    memcpy(ptr, &rb->buffer_ptr[*((_WORD *)rb + 2) >> 1], length);
    *((_WORD *)rb + 2) = *((_WORD *)rb + 2) & 1 | (2 * ((length + (*((_WORD *)rb + 2) >> 1)) & 0x7FFF));
    pthread_mutex_unlock(&rb->ringbuf_lock);
    pthread_cond_signal(&rb->notfull);
  }
  return length;
}
