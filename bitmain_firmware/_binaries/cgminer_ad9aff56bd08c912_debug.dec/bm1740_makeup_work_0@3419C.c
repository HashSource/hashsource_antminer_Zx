// Alternative name is 'bm1740_makeup_work.part.6'
int __fastcall bm1740_makeup_work_0(uint8_t *str, int len)
{
  uint8_t *v2; // r5
  uint8_t v3; // r3
  unsigned int v4; // r2
  uint8_t *v5; // r1
  int v6; // t1

  v2 = str;
  v3 = str[2];
  LOWORD(str) = 28216;
  v4 = 0xFFFF;
  v2[2] = v3 & 0x1F | 0x20;
  *(_WORD *)v2 = -21931;
  v5 = v2 + 2;
  do
  {
    v6 = *v5++;
    HIWORD(str) = (unsigned int)"s %s():%d" >> 16;
    v4 = (unsigned __int16)(*(_WORD *)&str[2 * (v6 ^ (v4 >> 8)) + 100] ^ ((_WORD)v4 << 8));
  }
  while ( v5 != v2 + 144 );
  *((_WORD *)v2 + 72) = ((_WORD)v4 << 8) | (v4 >> 8);
  return 146;
}
