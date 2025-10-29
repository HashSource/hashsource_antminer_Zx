void app_restart()
{
  const char *v0; // r2
  void *v1; // r0
  int *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    LOWORD(v0) = -2488;
    HIWORD(v0) = (unsigned int)"Invalid value passed to set temp cutoff" >> 16;
    snprintf(tmp42, 0x1000u, v0, packagename);
    applog(4, tmp42, 0);
  }
  LOWORD(v1) = -10839;
  HIWORD(v1) = (unsigned int)&loc_1D558 >> 16;
  cg_completion_timeout(v1, 0, 5000);
  cgtime(&total_tv_end);
  if ( forkpid > 0 )
  {
    kill(forkpid, 15);
    forkpid = 0;
  }
  execv(*initial_args, initial_args);
  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    LOWORD(v2) = -2460;
    HIWORD(v2) = (unsigned int)"temp cutoff" >> 16;
    v3 = *v2;
    v4 = v2[1];
    v5 = v2[2];
    v6 = v2[3];
    v2 += 4;
    *(_DWORD *)tmp42 = v3;
    *(_DWORD *)&tmp42[4] = v4;
    *(_DWORD *)&tmp42[8] = v5;
    *(_DWORD *)&tmp42[12] = v6;
    v7 = v2[1];
    v8 = v2[2];
    v9 = v2[3];
    *(_DWORD *)&tmp42[16] = *v2;
    *(_DWORD *)&tmp42[20] = v7;
    *(_DWORD *)&tmp42[24] = v8;
    *(_WORD *)&tmp42[28] = v9;
    applog(4, tmp42, 0);
  }
}
