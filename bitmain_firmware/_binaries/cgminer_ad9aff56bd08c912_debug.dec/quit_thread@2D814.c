void *__fastcall __noreturn quit_thread(void *userdata)
{
  int *v1; // r4
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r1
  int *v7; // r0
  int v8; // r1
  const char *v9; // r2
  int *v10; // r0
  int v11; // r1
  const char *v12; // r2
  char tmp42[4096]; // [sp+10h] [bp-1004h] BYREF

  if ( !pthread_mutex_lock(&quit_restart_lock) )
  {
    if ( !pthread_mutex_unlock(&quit_restart_lock) )
    {
      selective_yield();
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v1) = 21448;
        HIWORD(v1) = (unsigned int)"irst go" >> 16;
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
        tmp42[20] = v6;
        applog(7, tmp42, 0);
      }
      kill_work();
    }
    v10 = _errno_location();
    LOWORD(v11) = 20356;
    LOWORD(v12) = -920;
    HIWORD(v11) = (unsigned int)&_func___11888.__data.__nusers >> 16;
    HIWORD(v12) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v12, *v10, v11, &_func___12372.__align + 2, 4938);
    applog(3, tmp42, 1);
    quit(1);
  }
  v7 = _errno_location();
  LOWORD(v8) = 20356;
  LOWORD(v9) = -968;
  HIWORD(v8) = (unsigned int)&_func___11888.__data.__nusers >> 16;
  HIWORD(v9) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
  snprintf(tmp42, 0x1000u, v9, *v7, v8, &_func___12372.__align + 2, 4937);
  applog(3, tmp42, 1);
  quit(1);
}
