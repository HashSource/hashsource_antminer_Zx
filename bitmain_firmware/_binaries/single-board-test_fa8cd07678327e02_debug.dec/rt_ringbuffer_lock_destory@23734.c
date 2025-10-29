void __cdecl rt_ringbuffer_lock_destory(rt_ringbuffer *rb)
{
  pthread_mutex_destroy(&rb->ringbuf_lock);
  if ( rb->ringbuffer_type == ringbuffer_type::BLOCK_TYPE )
  {
    pthread_cond_destroy(&rb->notfull);
    pthread_cond_destroy(&rb->notempty);
  }
}
