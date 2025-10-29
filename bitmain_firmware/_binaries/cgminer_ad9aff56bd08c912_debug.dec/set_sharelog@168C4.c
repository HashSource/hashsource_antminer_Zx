char *__fastcall set_sharelog(char *arg)
{
  int v2; // r0
  bool v3; // zf
  const char *v5; // r1
  const char *v6; // r2
  const char *v7; // r1
  int v8; // r5
  const char *v9; // r2
  int *v10; // r4
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r1
  char *r; // [sp+4h] [bp-1008h] BYREF
  char tmp42[4096]; // [sp+8h] [bp-1004h] BYREF

  r = &byte_59414;
  v2 = strtol(arg, &r, 10);
  v3 = v2 == 0;
  if ( v2 >= 0 )
    v3 = *r == 0;
  if ( v3 )
  {
    LOWORD(v7) = 22912;
    v8 = v2;
    HIWORD(v7) = (unsigned int)"ected%" >> 16;
    sharelog_file = fdopen(v2, v7);
    if ( sharelog_file || !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    LOWORD(v9) = -3300;
    HIWORD(v9) = (unsigned int)"%u=0x%08x for work=%s" >> 16;
    snprintf(tmp42, 0x1000u, v9, v8);
    goto LABEL_12;
  }
  if ( *arg != 45 || arg[1] )
  {
    LOWORD(v5) = 22912;
    HIWORD(v5) = (unsigned int)"ected%" >> 16;
    sharelog_file = fopen(arg, v5);
    if ( sharelog_file || !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    LOWORD(v6) = -3224;
    HIWORD(v6) = (unsigned int)"Standard output missing for share log" >> 16;
    snprintf(tmp42, 0x1000u, v6, arg);
LABEL_12:
    applog(3, tmp42, 0);
    return 0;
  }
  sharelog_file = (FILE *)stdout;
  if ( stdout || !use_syslog && !opt_log_output && opt_log_level <= 2 )
    return 0;
  LOWORD(v10) = -3264;
  HIWORD(v10) = (unsigned int)"f%s" >> 16;
  v11 = *v10;
  v12 = v10[1];
  v13 = v10[2];
  v14 = v10[3];
  v10 += 4;
  *(_DWORD *)tmp42 = v11;
  *(_DWORD *)&tmp42[4] = v12;
  *(_DWORD *)&tmp42[8] = v13;
  *(_DWORD *)&tmp42[12] = v14;
  v15 = *v10;
  v16 = v10[1];
  v17 = v10[2];
  v18 = v10[3];
  v10 += 4;
  *(_DWORD *)&tmp42[16] = v15;
  *(_DWORD *)&tmp42[20] = v16;
  *(_DWORD *)&tmp42[24] = v17;
  *(_DWORD *)&tmp42[28] = v18;
  v19 = v10[1];
  *(_DWORD *)&tmp42[32] = *v10;
  *(_WORD *)&tmp42[36] = v19;
  applog(3, tmp42, 0);
  return 0;
}
