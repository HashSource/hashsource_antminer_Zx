void __fastcall __noreturn _quit(int a1, int a2)
{
  pthread_t newthread[2]; // [sp+4h] [bp-8h] BYREF

  if ( !pthread_create(newthread, 0, killall_thread, 0) )
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
