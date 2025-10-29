unsigned int __fastcall sub_4CCBC(unsigned int a1, int a2, int a3, int a4, unsigned int a5, unsigned int a6)
{
  unsigned int result; // r0
  int v8; // r11
  int v9; // r4
  unsigned int v10; // r6
  unsigned int v11; // r5
  int v12; // t1
  _BYTE *v13; // r3
  unsigned int v14; // r3
  _BYTE *v15; // r2
  unsigned int v16; // [sp+0h] [bp-1Ch]
  int v18; // [sp+10h] [bp-Ch]

  if ( a5 <= 7 )
    _assert_fail("bit_len >= 8", "sort-verify.c", 0x40u, "expandArray");
  if ( a5 + 7 > 0x20 )
    _assert_fail("8 * sizeof(uint32_t) >= 7 + bit_len", "sort-verify.c", 0x41u, "expandArray");
  v16 = a6 + ((a5 + 7) >> 3);
  result = v16 * 8 * a2 / a5;
  if ( result != a4 )
    _assert_fail("out_len == 8 * out_width * in_len / bit_len", "sort-verify.c", 0x44u, "expandArray");
  if ( a2 )
  {
    v8 = 0;
    v18 = a3 + a6;
    v9 = a1 + a2;
    result = a1;
    v10 = 0;
    v11 = 0;
    do
    {
      v11 += 8;
      v12 = *(unsigned __int8 *)result++;
      v10 = v12 | (v10 << 8);
      if ( a5 <= v11 )
      {
        v11 -= a5;
        if ( a6 )
        {
          v13 = (_BYTE *)(a3 + v8);
          do
            *v13++ = 0;
          while ( v13 != (_BYTE *)(v18 + v8) );
        }
        if ( a6 < v16 )
        {
          v14 = v11 + 8 * (((a5 + 7) >> 3) + 0x1FFFFFFF);
          v15 = (_BYTE *)(a3 + v8 + a6);
          do
          {
            *v15++ = (v10 >> v14) & ((unsigned int)~(-1 << a5) >> (v14 - v11));
            v14 -= 8;
          }
          while ( v15 != (_BYTE *)(a3 + v16 + v8) );
        }
        v8 += v16;
      }
    }
    while ( result != v9 );
  }
  return result;
}
