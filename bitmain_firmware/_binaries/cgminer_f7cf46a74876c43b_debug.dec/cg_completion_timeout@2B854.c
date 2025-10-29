bool __fastcall cg_completion_timeout(void *fn, void *fnarg, int timeout)
{
  cgsem_t *v6; // r0
  cgsem_t *v7; // r5
  int v8; // r4
  pthread_t pthread[2]; // [sp+Ch] [bp-8h] BYREF

  v6 = (cgsem_t *)malloc(0x18u);
  v7 = v6;
  if ( v6 )
  {
    cgsem_init(v6, "util.c", "cg_completion_timeout", 3977);
    v7[1].__align = (int)fn;
    *(&v7[1].__align + 1) = (int)fnarg;
    pthread_create(pthread, 0, completion_thread, v7);
    v8 = cgsem_mswait(v7, timeout, "util.c", "cg_completion_timeout", 3983);
    if ( v8 )
    {
      pthread_cancel(pthread[0]);
    }
    else
    {
      pthread_join(pthread[0], 0);
      free(v7);
    }
    LOBYTE(v6) = v8 == 0;
  }
  return (char)v6;
}
