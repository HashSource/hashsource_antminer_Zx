// Alternative name is 'bm1740_makeup_set_address_cmd.constprop.22'
int __fastcall bm1740_makeup_set_address_cmd(uint8_t *str, uint32_t str_len, uint8_t chip_addr)
{
  unsigned __int8 v4; // r0
  char v5; // r2
  uint8_t v6; // r2
  int v8; // [sp+0h] [bp-Ch] BYREF
  char v9; // [sp+4h] [bp-8h]

  HIWORD(v8) = (unsigned __int8)str_len;
  v9 = 0;
  LOWORD(v8) = 1344;
  v4 = CRC5((unsigned __int8 *)&v8, 0x20u);
  v5 = v9;
  *(_WORD *)str = -21931;
  v6 = v5 & 0xE0 | v4 & 0x1F;
  *(_DWORD *)(str + 2) = v8;
  str[6] = v6;
  return 7;
}
