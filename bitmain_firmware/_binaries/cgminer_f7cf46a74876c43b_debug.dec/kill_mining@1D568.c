void kill_mining()
{
  int i; // r4
  thr_info *thread; // r0
  thr_info *v2; // r5
  pthread_t pth; // r0
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "Killing off mining threads");
    applog(7, tmp42, 1);
  }
  if ( mining_threads > 0 )
  {
    for ( i = 0; mining_threads > i; ++i )
    {
      while ( 1 )
      {
        thread = get_thread(i);
        v2 = thread;
        if ( thread )
        {
          if ( thread->pth )
            break;
        }
        thr_info_cancel(thread);
LABEL_8:
        if ( mining_threads <= ++i )
          return;
      }
      thr_info_cancel(thread);
      pth = v2->pth;
      if ( !pth )
        goto LABEL_8;
      pthread_join(pth, 0);
    }
  }
}
