void __fastcall print_bin(uint8_t *cmd, size_t len)
{
  char *v2; // r0
  char *v3; // r4
  const char *v4; // r2
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  v2 = bin2hex(cmd, len);
  v3 = v2;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v4) = 20752;
    HIWORD(v4) = (unsigned int)"mcast join failed (%s)%s" >> 16;
    snprintf(tmp42, 0x1000u, v4, v2);
    applog(5, tmp42, 0);
    free(v3);
  }
  else
  {
    free(v2);
  }
}
