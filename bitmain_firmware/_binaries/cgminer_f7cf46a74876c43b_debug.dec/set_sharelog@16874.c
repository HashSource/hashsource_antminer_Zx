char *__fastcall set_sharelog(char *arg)
{
  int v2; // r0
  bool v3; // zf
  int v5; // r5
  char *r; // [sp+4h] [bp-1008h] BYREF
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  r = &byte_59398;
  v2 = strtol(arg, &r, 10);
  v3 = v2 == 0;
  if ( v2 >= 0 )
    v3 = *r == 0;
  if ( v3 )
  {
    v5 = v2;
    sharelog_file = fdopen(v2, "a");
    if ( sharelog_file || !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    snprintf(tmp42, 0x1000u, "Failed to open fd %u for share log", v5);
    goto LABEL_12;
  }
  if ( *arg != 45 || arg[1] )
  {
    sharelog_file = fopen(arg, "a");
    if ( sharelog_file || !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return 0;
    snprintf(tmp42, 0x1000u, "Failed to open %s for share log", arg);
LABEL_12:
    applog(3, tmp42, 0);
    return 0;
  }
  sharelog_file = (FILE *)stdout;
  if ( stdout || !use_syslog && !opt_log_output && opt_log_level <= 2 )
    return 0;
  strcpy(tmp42, "Standard output missing for share log");
  applog(3, tmp42, 0);
  return 0;
}
