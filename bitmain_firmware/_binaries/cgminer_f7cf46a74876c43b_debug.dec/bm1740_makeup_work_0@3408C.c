// Alternative name is 'bm1740_makeup_work.part.6'
int __fastcall bm1740_makeup_work_0(uint8_t *str, int len)
{
  unsigned int v3; // r2
  uint8_t *v4; // r1
  int v5; // t1

  v3 = 0xFFFF;
  str[2] = str[2] & 0x1F | 0x20;
  *(_WORD *)str = -21931;
  v4 = str + 2;
  do
  {
    v5 = *v4++;
    v3 = (unsigned __int16)(*(_WORD *)&_FUNCTION___15596[2 * (v5 ^ (v3 >> 8)) + 100] ^ ((_WORD)v3 << 8));
  }
  while ( v4 != str + 144 );
  *((_WORD *)str + 72) = ((_WORD)v3 << 8) | (v3 >> 8);
  return 146;
}
