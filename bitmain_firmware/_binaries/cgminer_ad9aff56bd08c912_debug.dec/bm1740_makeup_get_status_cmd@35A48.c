// Alternative name is 'bm1740_makeup_get_status_cmd.part.3'
// local variable allocation has failed, the output may be wrong!
int __fastcall bm1740_makeup_get_status_cmd(
        uint8_t *str,
        uint32_t str_len,
        uint8_t all,
        uint8_t chip_addr,
        uint8_t regaddr)
{
  unsigned __int8 v6; // r0
  int v7; // r1
  int v9; // [sp+0h] [bp-Ch] BYREF
  int chip_addra; // [sp+4h] [bp-8h] OVERLAPPED

  *(_WORD *)((char *)&chip_addra + 1) = __PAIR16__(BYTE2(chip_addra), chip_addr) & 0x1FFF;
  LOBYTE(chip_addra) = all;
  LOWORD(v9) = -21931;
  BYTE2(v9) = (16 * (str_len & 1)) | 0x42;
  HIBYTE(v9) = 5;
  v6 = CRC5((unsigned __int8 *)&v9 + 2, 0x20u);
  BYTE2(chip_addra) = BYTE2(chip_addra) & 0xE0 | v6 & 0x1F;
  v7 = chip_addra;
  *(_DWORD *)str = v9;
  *((_WORD *)str + 2) = v7;
  str[6] = BYTE2(v7);
  return 7;
}
