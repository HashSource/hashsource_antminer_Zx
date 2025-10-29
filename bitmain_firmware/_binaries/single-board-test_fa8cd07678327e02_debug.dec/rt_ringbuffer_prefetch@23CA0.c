uint32_t __cdecl rt_ringbuffer_prefetch(rt_ringbuffer *rb, uint8_t *ptr, uint16_t length)
{
  uint32_t size; // [sp+14h] [bp+14h]

  size = rt_ringbuffer_data_len(rb);
  if ( !size )
    return 0;
  if ( length > size )
    length = size;
  if ( rb->buffer_size - (*((_WORD *)rb + 2) >> 1) <= length )
  {
    memcpy(ptr, &rb->buffer_ptr[*((_WORD *)rb + 2) >> 1], rb->buffer_size - (*((_WORD *)rb + 2) >> 1));
    memcpy(
      &ptr[rb->buffer_size - (*((_WORD *)rb + 2) >> 1)],
      rb->buffer_ptr,
      length - (rb->buffer_size - (*((_WORD *)rb + 2) >> 1)));
  }
  else
  {
    memcpy(ptr, &rb->buffer_ptr[*((_WORD *)rb + 2) >> 1], length);
  }
  return length;
}
