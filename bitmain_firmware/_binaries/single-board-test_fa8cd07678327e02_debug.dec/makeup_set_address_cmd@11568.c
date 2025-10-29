int __cdecl makeup_set_address_cmd(uint8_t *str, uint32_t str_len, uint8_t chip_addr)
{
  unsigned __int8 v4; // r0
  char tmp42[1024]; // [sp+18h] [bp+10h] BYREF
  set_address_cmd_t set_address_cmd; // [sp+418h] [bp+410h] BYREF

  if ( str_len > 6 )
  {
    memset(&set_address_cmd, 0, sizeof(set_address_cmd));
    *(_BYTE *)&set_address_cmd = *(_BYTE *)&set_address_cmd & 0x1F | 0x40;
    *(_BYTE *)&set_address_cmd &= ~0x10u;
    *(_BYTE *)&set_address_cmd &= 0xF0u;
    set_address_cmd.length = 5;
    set_address_cmd.chip_addr = chip_addr;
    v4 = CRC5_v1((unsigned __int8 *)&set_address_cmd, 0x20u);
    *((_BYTE *)&set_address_cmd + 4) = *((_BYTE *)&set_address_cmd + 4) & 0xE0 | v4 & 0x1F;
    *str = 85;
    str[1] = -86;
    *(set_address_cmd_t *)(str + 2) = set_address_cmd;
    return 7;
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      snprintf(tmp42, 0x400u, "%s input param error: str length = %u\n", "makeup_set_address_cmd", 7);
      applog(0, tmp42, 0);
    }
    return -1;
  }
}
