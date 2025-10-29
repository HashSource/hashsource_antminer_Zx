void __fastcall _bin2hex(char *s, const unsigned __int8 *p, size_t len)
{
  const unsigned __int8 *v3; // r6
  const unsigned __int8 *v4; // r1
  int v5; // r5
  char *v6; // r4
  unsigned int v7; // t1

  if ( (int)len <= 0 )
  {
    *s = 0;
  }
  else
  {
    LOWORD(v5) = 13056;
    v3 = &p[len - 1];
    v4 = p - 1;
    HIWORD(v5) = (unsigned int)"0.0" >> 16;
    v6 = s + 2;
    do
    {
      v7 = *++v4;
      v6 += 2;
      *(v6 - 4) = *(_BYTE *)(v5 + (v7 >> 4) + 84);
      *(v6 - 3) = *(_BYTE *)((*v4 & 0xF) + v5 + 84);
    }
    while ( v4 != v3 );
    s[2 * len] = 0;
  }
}
