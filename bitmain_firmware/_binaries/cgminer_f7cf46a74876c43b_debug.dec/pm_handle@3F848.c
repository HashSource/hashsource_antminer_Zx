void __fastcall pm_handle(uint8_t *str, int len, uint8_t chainid)
{
  int v4; // r5
  int v5; // r0
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  v4 = chainid;
  v5 = CRC5(str + 2, 8 * len - 21);
  if ( (str[8] & 0x1F) == v5 )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(
        tmp42,
        0x1000u,
        "chain[%d] asic[%d] %02x %02x %02x %02x\n",
        v4,
        (unsigned __int8)(str[7] / dev.addrInterval),
        str[3],
        str[4],
        str[5],
        str[6]);
      applog(7, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    snprintf(tmp42, 0x1000u, "%s chain%d CRC error crc = %02x\n", "pm_handle", v4, v5);
    applog(3, tmp42, 0);
  }
}
