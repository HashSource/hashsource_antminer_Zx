void __cdecl rt_ringbuffer_init(rt_ringbuffer *rb, uint8_t *pool, int16_t size, ringbuffer_type_t ringbuffer_type)
{
  *((_WORD *)rb + 2) &= 1u;
  *((_BYTE *)rb + 4) = *((_BYTE *)rb + 4) & 0xFE | ((*((_WORD *)rb + 2) & 2) != 0);
  *((_WORD *)rb + 3) &= 1u;
  *((_BYTE *)rb + 6) = *((_BYTE *)rb + 6) & 0xFE | ((*((_WORD *)rb + 3) & 2) != 0);
  rb->buffer_ptr = pool;
  rb->buffer_size = size & 0xFFFC;
  rb->ringbuffer_type = ringbuffer_type;
  pthread_mutex_init(&rb->ringbuf_lock, 0);
  if ( rb->ringbuffer_type == ringbuffer_type::BLOCK_TYPE )
  {
    pthread_cond_init(&rb->notfull, 0);
    pthread_cond_init(&rb->notempty, 0);
  }
}
