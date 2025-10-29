void kill_mining()
{
  int *v0; // r5
  int v1; // r0
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r1
  int v6; // r2
  int i; // r4
  thr_info *thread; // r0
  thr_info *v9; // r5
  pthread_t pth; // r0
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v0) = 1140;
    HIWORD(v0) = (unsigned int)"ning threads" >> 16;
    v1 = *v0;
    v2 = v0[1];
    v3 = v0[2];
    v4 = v0[3];
    v0 += 4;
    *(_DWORD *)tmp42 = v1;
    *(_DWORD *)&tmp42[4] = v2;
    *(_DWORD *)&tmp42[8] = v3;
    *(_DWORD *)&tmp42[12] = v4;
    v5 = v0[1];
    v6 = v0[2];
    *(_DWORD *)&tmp42[16] = *v0;
    *(_DWORD *)&tmp42[20] = v5;
    *(_WORD *)&tmp42[24] = v6;
    tmp42[26] = BYTE2(v6);
    applog(7, tmp42, 1);
  }
  if ( mining_threads > 0 )
  {
    for ( i = 0; mining_threads > i; ++i )
    {
      while ( 1 )
      {
        thread = get_thread(i);
        v9 = thread;
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
      pth = v9->pth;
      if ( !pth )
        goto LABEL_8;
      pthread_join(pth, 0);
    }
  }
}
