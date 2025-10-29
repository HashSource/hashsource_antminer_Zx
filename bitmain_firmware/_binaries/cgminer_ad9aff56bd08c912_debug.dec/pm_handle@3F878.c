void __fastcall pm_handle(uint8_t *str, int len, uint8_t chainid)
{
  int v4; // r5
  int v5; // r0
  const char *v6; // r2
  const char *v7; // r2
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  v4 = chainid;
  v5 = CRC5(str + 2, 8 * len - 21);
  if ( (str[8] & 0x1F) == v5 )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v7) = -22392;
      HIWORD(v7) = (unsigned int)"fo full!!!" >> 16;
      snprintf(tmp42, 0x1000u, v7, v4, (unsigned __int8)(str[7] / dev.addrInterval), str[3], str[4], str[5], str[6]);
      applog(7, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    LOWORD(v6) = -22428;
    HIWORD(v6) = (unsigned int)"ror nonce. total = %u" >> 16;
    snprintf(tmp42, 0x1000u, v6, "pm_handle", v4, v5);
    applog(3, tmp42, 0);
  }
}
