void *__cdecl __noreturn check_nonce_loop(void *args)
{
  pthread_t send_id; // [sp+8h] [bp+8h] BYREF
  runtime_base_t *runtime; // [sp+Ch] [bp+Ch]

  runtime = (runtime_base_t *)args;
  while ( 1 )
  {
    if ( runtime->start_recv )
    {
      pthread_create(&send_id, 0, (void *(*)(void *))check_nonce, args);
      pthread_join(send_id, 0);
      usleep(0x1388u);
    }
    else
    {
      usleep(0x186A0u);
    }
  }
}
