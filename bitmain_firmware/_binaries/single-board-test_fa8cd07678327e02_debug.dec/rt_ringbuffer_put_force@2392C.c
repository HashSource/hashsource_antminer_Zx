uint32_t __cdecl rt_ringbuffer_put_force(rt_ringbuffer *rb, const uint8_t *ptr, uint16_t length)
{
  unsigned __int16 buffer_size; // r4
  uint16_t space_length; // [sp+16h] [bp+16h]

  pthread_mutex_lock(&rb->ringbuf_lock);
  buffer_size = rb->buffer_size;
  space_length = buffer_size - rt_ringbuffer_data_len(rb);
  if ( length > (unsigned int)space_length )
    length = rb->buffer_size;
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
    if ( length > (unsigned int)space_length )
    {
      *((_BYTE *)rb + 4) = *((_BYTE *)rb + 4) & 0xFE | ((*((_BYTE *)rb + 4) & 1) == 0);
      *((_WORD *)rb + 2) = *((_WORD *)rb + 2) & 1 | (2 * ((*((_WORD *)rb + 3) >> 1) & 0x7FFF));
    }
  }
  else
  {
    memcpy(&rb->buffer_ptr[*((_WORD *)rb + 3) >> 1], ptr, length);
    *((_WORD *)rb + 3) = *((_WORD *)rb + 3) & 1 | (2 * ((length + (*((_WORD *)rb + 3) >> 1)) & 0x7FFF));
    if ( length > (unsigned int)space_length )
      *((_WORD *)rb + 2) = *((_WORD *)rb + 2) & 1 | (2 * ((*((_WORD *)rb + 3) >> 1) & 0x7FFF));
  }
  pthread_cond_signal(&rb->notempty);
  pthread_mutex_unlock(&rb->ringbuf_lock);
  return length;
}
