void *__cdecl __noreturn nonce_scanhash_loop(void *args)
{
  pthread_t send_id; // [sp+8h] [bp+8h] BYREF
  runtime_base_t *runtime; // [sp+Ch] [bp+Ch]

  runtime = (runtime_base_t *)args;
  while ( 1 )
  {
    if ( runtime->start_recv )
    {
      pthread_create(&send_id, 0, (void *(*)(void *))nonce_scanhash, args);
      pthread_join(send_id, 0);
      usleep(0x3E8u);
    }
    else
    {
      pthread_testcancel();
      usleep(0x186A0u);
    }
  }
}
