void __cdecl _bin2hex(char *s, const unsigned __int8 *p, size_t len)
{
  char *v3; // r2
  int i; // [sp+14h] [bp+14h]

  for ( i = 0; i < (int)len; ++i )
  {
    *s = hex_6251[p[i] >> 4];
    v3 = s + 1;
    s += 2;
    *v3 = hex_6251[p[i] & 0xF];
  }
  *s = 0;
}
