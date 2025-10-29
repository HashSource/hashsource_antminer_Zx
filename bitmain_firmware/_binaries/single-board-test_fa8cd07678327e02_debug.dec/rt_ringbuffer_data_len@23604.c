uint16_t __cdecl rt_ringbuffer_data_len(rt_ringbuffer *rb)
{
  RINGBUFFER_STATE v1; // r0

  v1 = rt_ringbuffer_status(rb);
  if ( v1 == rt_ringbuffer_state::RT_RINGBUFFER_EMPTY )
    return 0;
  if ( v1 == rt_ringbuffer_state::RT_RINGBUFFER_FULL )
    return rb->buffer_size;
  if ( *((_WORD *)rb + 3) >> 1 <= *((_WORD *)rb + 2) >> 1 )
    return (*((_WORD *)rb + 3) >> 1) - (*((_WORD *)rb + 2) >> 1) + rb->buffer_size;
  return (*((_WORD *)rb + 3) >> 1) - (*((_WORD *)rb + 2) >> 1);
}
