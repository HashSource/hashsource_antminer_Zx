void __fastcall _bin2hex(char *s, const unsigned __int8 *p, size_t len)
{
  const unsigned __int8 *v3; // r6
  const unsigned __int8 *v4; // r1
  char *v5; // r4
  unsigned int v6; // t1

  if ( (int)len <= 0 )
  {
    *s = 0;
  }
  else
  {
    v3 = &p[len - 1];
    v4 = p - 1;
    v5 = s + 2;
    do
    {
      v6 = *++v4;
      v5 += 2;
      *(v5 - 4) = _func___12024[(v6 >> 4) + 84];
      *(v5 - 3) = _func___12024[(*v4 & 0xF) + 84];
    }
    while ( v4 != v3 );
    s[2 * len] = 0;
  }
}
