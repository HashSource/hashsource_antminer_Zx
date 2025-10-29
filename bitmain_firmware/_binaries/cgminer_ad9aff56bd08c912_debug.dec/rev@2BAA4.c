void __fastcall rev(unsigned __int8 *s, size_t l)
{
  size_t v2; // r3
  unsigned __int8 *v3; // r4
  unsigned __int8 *v4; // r0
  unsigned __int8 v5; // r5
  unsigned __int8 v6; // t1
  unsigned __int8 v7; // t1

  if ( l != 1 )
  {
    v2 = 0;
    v3 = s - 1;
    v4 = &s[l];
    do
    {
      ++v2;
      v6 = *++v3;
      v5 = v6;
      v7 = *--v4;
      *v3 = v7;
      *v4 = v5;
    }
    while ( v2 < ~v2 + l );
  }
}
