void *__fastcall restart_thread_0(void *userdata)
{
  int *v1; // r4
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r1
  int *v8; // r0
  int v9; // r1
  const char *v10; // r2
  int *v11; // r0
  int v12; // r1
  const char *v13; // r2
  char tmp42[4096]; // [sp+10h] [bp-1004h] BYREF

  if ( pthread_mutex_lock(&quit_restart_lock) )
  {
    v8 = _errno_location();
    LOWORD(v9) = 20356;
    LOWORD(v10) = -968;
    HIWORD(v9) = (unsigned int)&_func___11888.__data.__nusers >> 16;
    HIWORD(v10) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v10, *v8, v9, &_func___12372.__align + 5, 4951);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_mutex_unlock(&quit_restart_lock) )
  {
    v11 = _errno_location();
    LOWORD(v12) = 20356;
    LOWORD(v13) = -920;
    HIWORD(v12) = (unsigned int)&_func___11888.__data.__nusers >> 16;
    HIWORD(v13) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v13, *v11, v12, &_func___12372.__align + 5, 4952);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v1) = 21472;
    HIWORD(v1) = (unsigned int)" remaining %d (sendc=%d)" >> 16;
    v2 = *v1;
    v3 = v1[1];
    v4 = v1[2];
    v5 = v1[3];
    v1 += 4;
    *(_DWORD *)tmp42 = v2;
    *(_DWORD *)&tmp42[4] = v3;
    *(_DWORD *)&tmp42[8] = v4;
    *(_DWORD *)&tmp42[12] = v5;
    v6 = v1[1];
    *(_DWORD *)&tmp42[16] = *v1;
    *(_DWORD *)&tmp42[20] = v6;
    applog(7, tmp42, 0);
  }
  app_restart();
  return 0;
}
