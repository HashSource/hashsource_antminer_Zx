int __cdecl makeup_set_config_cmd(
        uint8_t *str,
        uint32_t str_len,
        uint8_t all,
        uint8_t chip_addr,
        uint8_t regaddr,
        uint32_t regdata)
{
  unsigned __int8 v7; // r0
  int v8; // r1
  char tmp42[1024]; // [sp+18h] [bp+10h] BYREF
  set_config_cmd_t set_config_cmd; // [sp+41Ch] [bp+414h] BYREF

  if ( str_len > 0xA )
  {
    memset(&set_config_cmd, 0, sizeof(set_config_cmd));
    *(_BYTE *)&set_config_cmd = *(_BYTE *)&set_config_cmd & 0x1F | 0x40;
    *(_BYTE *)&set_config_cmd = *(_BYTE *)&set_config_cmd & 0xEF | (16 * (all & 1));
    *(_BYTE *)&set_config_cmd = *(_BYTE *)&set_config_cmd & 0xF0 | 1;
    set_config_cmd.length = 9;
    set_config_cmd.chip_addr = chip_addr;
    set_config_cmd.regaddr = regaddr;
    *(_DWORD *)set_config_cmd.regdata = bswap32(regdata);
    v7 = CRC5_v1((unsigned __int8 *)&set_config_cmd, 0x40u);
    *((_BYTE *)&set_config_cmd + 8) = *((_BYTE *)&set_config_cmd + 8) & 0xE0 | v7 & 0x1F;
    *str = 85;
    str[1] = -86;
    v8 = *(_DWORD *)set_config_cmd.regdata;
    *(_DWORD *)(str + 2) = set_config_cmd;
    *(_DWORD *)(str + 6) = v8;
    str[10] = *((_BYTE *)&set_config_cmd + 8);
    return 11;
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      snprintf(tmp42, 0x400u, "%s input param error: str length = %u\n", "makeup_set_config_cmd", 11);
      applog(0, tmp42, 0);
    }
    return -1;
  }
}
