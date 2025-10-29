int __cdecl makeup_work_pkg(uint8_t *str, uint8_t *work_str)
{
  uint16_t crc16; // [sp+Ah] [bp+Ah]

  work_str[2] = work_str[2] & 0x1F | 0x20;
  *work_str = 85;
  work_str[1] = -86;
  crc16 = CRC16_v1(work_str + 2, 142);
  *((_WORD *)work_str + 72) = HIBYTE(crc16) | (crc16 << 8);
  memcpy(str, work_str, 0x92u);
  return 146;
}
