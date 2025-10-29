// Alternative name is 'bm1740_makeup_chain_inactive_cmd.constprop.19'
int __fastcall bm1740_makeup_chain_inactive_cmd(uint8_t *str, uint32_t str_len)
{
  unsigned __int8 v3; // r0
  char v4; // r2
  uint8_t v5; // r2
  chain_inactive_cmd_t chain_inactive_cmd; // [sp+0h] [bp-8h] BYREF

  *(_WORD *)&chain_inactive_cmd.reserve1 = 0;
  *((_BYTE *)&chain_inactive_cmd + 4) = 0;
  *(_WORD *)&chain_inactive_cmd = 1363;
  v3 = CRC5((unsigned __int8 *)&chain_inactive_cmd, 0x20u);
  v4 = *((_BYTE *)&chain_inactive_cmd + 4);
  *(_WORD *)str = -21931;
  v5 = v4 & 0xE0 | v3 & 0x1F;
  *(_DWORD *)(str + 2) = chain_inactive_cmd;
  str[6] = v5;
  return 7;
}
