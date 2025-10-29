void __fastcall __noreturn _quit(int a1, int a2)
{
  void *(*v2)(void *); // r2
  pthread_t newthread[2]; // [sp+4h] [bp-8h] BYREF

  LOWORD(v2) = 27757;
  HIWORD(v2) = (unsigned int)&loc_16C1C >> 16;
  if ( !pthread_create(newthread, 0, v2, 0) )
  {
    if ( a2 )
    {
      cgtime(&total_tv_end);
      if ( !opt_realquiet && successful_connect )
        print_summary();
    }
    if ( forkpid > 0 )
    {
      kill(forkpid, 15);
      forkpid = 0;
    }
    pthread_cancel(newthread[0]);
    exit(a1);
  }
  exit(1);
}
