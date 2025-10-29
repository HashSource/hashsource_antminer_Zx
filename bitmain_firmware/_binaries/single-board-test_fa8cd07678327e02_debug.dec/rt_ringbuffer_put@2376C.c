uint32_t __cdecl rt_ringbuffer_put(rt_ringbuffer *rb, const uint8_t *ptr, uint16_t length)
{
  unsigned __int16 buffer_size; // r4
  unsigned __int16 v5; // r4
  uint16_t size; // [sp+16h] [bp+16h]

  pthread_mutex_lock(&rb->ringbuf_lock);
  buffer_size = rb->buffer_size;
  size = buffer_size - rt_ringbuffer_data_len(rb);
  if ( rb->ringbuffer_type == ringbuffer_type::POLL_TYPE )
  {
    if ( !size )
    {
      pthread_mutex_unlock(&rb->ringbuf_lock);
      return 0;
    }
    if ( size < (unsigned int)length )
      length = size;
  }
  else if ( rb->ringbuffer_type == ringbuffer_type::BLOCK_TYPE )
  {
    while ( size < (unsigned int)length )
    {
      pthread_cond_wait(&rb->notfull, &rb->ringbuf_lock);
      v5 = rb->buffer_size;
      size = v5 - rt_ringbuffer_data_len(rb);
    }
  }
  if ( rb->buffer_size - (*((_WORD *)rb + 3) >> 1) <= length )
  {
    memcpy(&rb->buffer_ptr[*((_WORD *)rb + 3) >> 1], ptr, rb->buffer_size - (*((_WORD *)rb + 3) >> 1));
    memcpy(
      rb->buffer_ptr,
      &ptr[rb->buffer_size - (*((_WORD *)rb + 3) >> 1)],
      length - (rb->buffer_size - (*((_WORD *)rb + 3) >> 1)));
    *((_BYTE *)rb + 6) = *((_BYTE *)rb + 6) & 0xFE | ((*((_BYTE *)rb + 6) & 1) == 0);
    *((_WORD *)rb + 3) = *((_WORD *)rb + 3) & 1
                       | (2 * ((length + (*((_WORD *)rb + 3) >> 1) - rb->buffer_size) & 0x7FFF));
  }
  else
  {
    memcpy(&rb->buffer_ptr[*((_WORD *)rb + 3) >> 1], ptr, length);
    *((_WORD *)rb + 3) = *((_WORD *)rb + 3) & 1 | (2 * ((length + (*((_WORD *)rb + 3) >> 1)) & 0x7FFF));
  }
  pthread_cond_signal(&rb->notempty);
  pthread_mutex_unlock(&rb->ringbuf_lock);
  return length;
}
