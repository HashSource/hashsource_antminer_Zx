// Alternative name is 'bm1740_makeup_set_config_cmd.constprop.21'
// local variable allocation has failed, the output may be wrong!
int __fastcall bm1740_makeup_set_config_cmd(
        uint8_t *str,
        uint32_t str_len,
        uint8_t all,
        uint8_t chip_addr,
        uint32_t regaddr,
        uint32_t regdata)
{
  unsigned __int8 v7; // r0
  int v8; // r1
  int v9; // r2
  int v11; // [sp+4h] [bp-10h] BYREF
  __int64 chip_addra; // [sp+8h] [bp-Ch] OVERLAPPED

  LOBYTE(chip_addra) = all;
  BYTE1(chip_addra) = chip_addr;
  BYTE2(v11) = (16 * (str_len & 1)) | 0x41;
  *(_DWORD *)((char *)&chip_addra + 2) = bswap32(regaddr);
  BYTE6(chip_addra) &= 0x1Fu;
  LOWORD(v11) = -21931;
  HIBYTE(v11) = 9;
  v7 = CRC5((unsigned __int8 *)&v11 + 2, 0x40u);
  BYTE6(chip_addra) = BYTE6(chip_addra) & 0xE0 | v7 & 0x1F;
  v9 = HIDWORD(chip_addra);
  v8 = chip_addra;
  *(_DWORD *)str = v11;
  *((_DWORD *)str + 1) = v8;
  *((_WORD *)str + 4) = v9;
  str[10] = BYTE2(v9);
  return 11;
}
