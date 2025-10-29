void __fastcall sub_3E5A4(int a1)
{
  int v1; // r4
  __int16 *v2; // r6
  char v3; // r0
  bool v4; // zf
  int v5; // r12
  unsigned __int16 v7; // [sp+16h] [bp-FEAh] BYREF
  char s[4072]; // [sp+18h] [bp-FE8h] BYREF

  v1 = 0;
  v2 = &word_790B8[3 * a1 - 1];
  do
  {
    v3 = byte_76B48[v1];
    v7 = 0;
    sub_3E564(v3, &v7);
    v4 = byte_7AD48 == 0;
    v5 = v7;
    v2[1] = v7;
    ++v2;
    if ( !v4 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "chain %d asic = %d vol=%u\n", a1, v1, v5);
      sub_38730(5, s, 0);
    }
    ++v1;
  }
  while ( v1 != 3 );
}
