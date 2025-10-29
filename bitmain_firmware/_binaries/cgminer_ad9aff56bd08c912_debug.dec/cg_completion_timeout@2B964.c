bool __fastcall cg_completion_timeout(void *fn, void *fnarg, int timeout)
{
  cgsem_t *v6; // r0
  cgsem_t *v7; // r5
  const char *v8; // r1
  void *(*v9)(void *); // r2
  const char *v10; // r2
  int v11; // r4
  pthread_t pthread[2]; // [sp+Ch] [bp-8h] BYREF

  v6 = (cgsem_t *)malloc(0x18u);
  v7 = v6;
  if ( v6 )
  {
    LOWORD(v8) = 15984;
    HIWORD(v8) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    cgsem_init(v6, v8, "cg_completion_timeout", 3977);
    LOWORD(v9) = -18475;
    HIWORD(v9) = ((unsigned int)&loc_2B6C2 + 3) >> 16;
    v7[1].__align = (int)fn;
    *(&v7[1].__align + 1) = (int)fnarg;
    pthread_create(pthread, 0, v9, v7);
    LOWORD(v10) = 15984;
    HIWORD(v10) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    v11 = cgsem_mswait(v7, timeout, v10, "cg_completion_timeout", 3983);
    if ( v11 )
    {
      pthread_cancel(pthread[0]);
    }
    else
    {
      pthread_join(pthread[0], 0);
      free(v7);
    }
    LOBYTE(v6) = v11 == 0;
  }
  return (char)v6;
}
