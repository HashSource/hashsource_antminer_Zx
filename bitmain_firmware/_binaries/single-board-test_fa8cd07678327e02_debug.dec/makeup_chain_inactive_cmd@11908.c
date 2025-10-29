int __cdecl makeup_chain_inactive_cmd(uint8_t *str, uint32_t str_len)
{
  unsigned __int8 v3; // r0
  char tmp42[1024]; // [sp+10h] [bp+8h] BYREF
  chain_inactive_cmd_t chain_inactive_cmd; // [sp+410h] [bp+408h] BYREF

  if ( str_len > 6 )
  {
    memset(&chain_inactive_cmd, 0, sizeof(chain_inactive_cmd));
    *(_BYTE *)&chain_inactive_cmd = *(_BYTE *)&chain_inactive_cmd & 0x1F | 0x40;
    *(_BYTE *)&chain_inactive_cmd |= 0x10u;
    *(_BYTE *)&chain_inactive_cmd = *(_BYTE *)&chain_inactive_cmd & 0xF0 | 3;
    chain_inactive_cmd.length = 5;
    v3 = CRC5_v1((unsigned __int8 *)&chain_inactive_cmd, 0x20u);
    *((_BYTE *)&chain_inactive_cmd + 4) = *((_BYTE *)&chain_inactive_cmd + 4) & 0xE0 | v3 & 0x1F;
    *str = 85;
    str[1] = -86;
    *(chain_inactive_cmd_t *)(str + 2) = chain_inactive_cmd;
    return 7;
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      snprintf(tmp42, 0x400u, "%s input param error: str length = %u\n", "makeup_chain_inactive_cmd", 7);
      applog(0, tmp42, 0);
    }
    return -1;
  }
}
