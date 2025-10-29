int __cdecl makeup_get_status_cmd(uint8_t *str, uint32_t str_len, uint8_t all, uint8_t chip_addr, uint8_t regaddr)
{
  unsigned __int8 v6; // r0
  char tmp42[1024]; // [sp+18h] [bp+10h] BYREF
  get_status_cmd_t get_status_cmd; // [sp+418h] [bp+410h] BYREF

  if ( str_len > 6 )
  {
    memset(&get_status_cmd, 0, sizeof(get_status_cmd));
    *(_BYTE *)&get_status_cmd = *(_BYTE *)&get_status_cmd & 0x1F | 0x40;
    *(_BYTE *)&get_status_cmd = *(_BYTE *)&get_status_cmd & 0xEF | (16 * (all & 1));
    *(_BYTE *)&get_status_cmd = *(_BYTE *)&get_status_cmd & 0xF0 | 2;
    get_status_cmd.length = 5;
    get_status_cmd.chip_addr = chip_addr;
    get_status_cmd.regaddr = regaddr;
    v6 = CRC5_v1((unsigned __int8 *)&get_status_cmd, 0x20u);
    *((_BYTE *)&get_status_cmd + 4) = *((_BYTE *)&get_status_cmd + 4) & 0xE0 | v6 & 0x1F;
    *str = 85;
    str[1] = -86;
    *(get_status_cmd_t *)(str + 2) = get_status_cmd;
    return 7;
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      snprintf(tmp42, 0x400u, "%s input param error: str length = %u\n", "makeup_get_status_cmd", 7);
      applog(0, tmp42, 0);
    }
    return -1;
  }
}
