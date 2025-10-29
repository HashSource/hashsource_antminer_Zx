void __cdecl bm174x_pm_handle(uint8_t *str, int len, uint8_t chainid)
{
  char tmp42[1027]; // [sp+20h] [bp+10h] BYREF
  uint8_t crc5; // [sp+423h] [bp+413h]
  pmonitor_respond *pm; // [sp+424h] [bp+414h]

  pm = (pmonitor_respond *)str;
  crc5 = CRC5_v1(str + 2, 8 * (len - 3) + 3);
  if ( crc5 == (*((_BYTE *)pm + 8) & 0x1F) )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(
        tmp42,
        0x400u,
        "pmonitor[%02x] %02x %02x %02x %02x\n",
        pm->chip_addr,
        pm->pm_data[0],
        pm->pm_data[1],
        pm->pm_data[2],
        pm->pm_data[3]);
      applog(2, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level >= 0 )
  {
    snprintf(tmp42, 0x400u, "%s chain%d CRC error crc = %02x\n", "bm174x_pm_handle", chainid, crc5);
    applog(0, tmp42, 0);
  }
}
