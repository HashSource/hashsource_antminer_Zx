RINGBUFFER_STATE __cdecl rt_ringbuffer_status(rt_ringbuffer *rb)
{
  if ( *((_WORD *)rb + 2) >> 1 == *((_WORD *)rb + 3) >> 1 )
    return (*((_BYTE *)rb + 4) & 1) != (*((_BYTE *)rb + 6) & 1);
  else
    return rt_ringbuffer_state::RT_RINGBUFFER_HALFFULL;
}
