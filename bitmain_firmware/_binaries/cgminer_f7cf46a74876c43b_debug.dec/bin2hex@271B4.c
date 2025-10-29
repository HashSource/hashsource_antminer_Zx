char *__fastcall bin2hex(const unsigned __int8 *p, size_t len)
{
  size_t v2; // r5
  size_t v5; // r3
  char *v6; // r0
  char *v7; // r6
  char *v8; // r5
  const unsigned __int8 *v9; // r0
  char *v10; // r2
  unsigned int v11; // t1
  char v12; // r3
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  v2 = 2 * len;
  v5 = (2 * len + 1) & 3;
  if ( (int)(2 * len + 1) <= 0 )
    v5 = -(-(2 * len + 1) & 3);
  v6 = (char *)calloc(v2 + 1 + 4 - v5, 1u);
  v7 = v6;
  if ( !v6 )
  {
    snprintf(tmp42, 0x1000u, "Failed to calloc in %s %s():%d", "util.c", "bin2hex", 920);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( (int)len > 0 )
  {
    v9 = p - 1;
    v10 = v7 + 2;
    do
    {
      v11 = *++v9;
      v10 += 2;
      v12 = _func___12024[(v11 >> 4) + 84];
      *(v10 - 3) = _func___12024[(v11 & 0xF) + 84];
      *(v10 - 4) = v12;
    }
    while ( v9 != &p[len - 1] );
    v8 = &v7[v2];
  }
  else
  {
    v8 = v6;
  }
  *v8 = 0;
  return v7;
}
