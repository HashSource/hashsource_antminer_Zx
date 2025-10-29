void __fastcall set_miner_name(char *name)
{
  FILE *v2; // r4
  FILE *v3; // r4
  char rbuf1[128]; // [sp+0h] [bp-1084h] BYREF
  char tmp42[4100]; // [sp+80h] [bp-1004h] BYREF

  v2 = fopen("/usr/bin/compile_time", "r");
  memset(rbuf1, 0, sizeof(rbuf1));
  fgets(rbuf1, 128, v2);
  fclose(v2);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "rbuf1 %s\n", rbuf1);
    applog(5, tmp42, 0);
  }
  v3 = fopen("/usr/bin/compile_time", "w");
  fputs(rbuf1, v3);
  fprintf(v3, "Antminer %s\n", name);
  fclose(v3);
}
