char *__fastcall bin2hex(const unsigned __int8 *p, size_t len)
{
  size_t v2; // r5
  size_t v5; // r3
  char *v6; // r0
  char *v7; // r6
  char *v8; // r5
  const unsigned __int8 *v9; // r0
  int v10; // r7
  char *v11; // r2
  unsigned int v12; // t1
  char v13; // r3
  int v15; // r3
  const char *v16; // r2
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  v2 = 2 * len;
  v5 = (2 * len + 1) & 3;
  if ( (int)(2 * len + 1) <= 0 )
    v5 = -(-(2 * len + 1) & 3);
  v6 = (char *)calloc(v2 + 1 + 4 - v5, 1u);
  v7 = v6;
  if ( !v6 )
  {
    LOWORD(v15) = 15984;
    LOWORD(v16) = 16008;
    HIWORD(v15) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    HIWORD(v16) = (unsigned int)"y: %s" >> 16;
    snprintf(tmp42, 0x1000u, v16, v15, "bin2hex", 920);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( (int)len > 0 )
  {
    v9 = p - 1;
    LOWORD(v10) = 13056;
    HIWORD(v10) = (unsigned int)"0.0" >> 16;
    v11 = v7 + 2;
    do
    {
      v12 = *++v9;
      v11 += 2;
      v13 = *(_BYTE *)(v10 + (v12 >> 4) + 84);
      *(v11 - 3) = *(_BYTE *)((v12 & 0xF) + v10 + 84);
      *(v11 - 4) = v13;
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
