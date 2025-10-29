void __fastcall b58tobin(unsigned __int8 *b58bin, const char *b58)
{
  uint32_t v2; // r4
  size_t v5; // r0
  unsigned __int8 v6; // r1
  const char *v7; // lr
  const char *v8; // r12
  int v9; // t1
  uint32_t *v10; // r2
  unsigned int v11; // r0
  __int64 v12; // r0
  unsigned __int8 *v13; // r3
  uint32_t *v14; // r2
  unsigned __int8 *v15; // r7
  unsigned int v16; // t1
  int v17; // [sp+0h] [bp-20h] BYREF
  uint32_t bin32[7]; // [sp+4h] [bp-1Ch] BYREF

  v2 = 0;
  memset(bin32, 0, sizeof(bin32));
  v5 = strlen(b58);
  v6 = v5;
  if ( v5 )
  {
    v7 = b58 - 1;
    v8 = &b58[v5 - 1];
    while ( 1 )
    {
      v9 = *(unsigned __int8 *)++v7;
      v10 = &bin32[6];
      v11 = *(_DWORD *)&_func___12024[4 * v9 + 1160];
      while ( 1 )
      {
        v12 = 58LL * v2 + v11;
        *v10-- = v12;
        v11 = HIDWORD(v12);
        if ( &v17 == (int *)v10 )
          break;
        v2 = *v10;
      }
      if ( v8 == v7 )
        break;
      v2 = bin32[6];
    }
    v6 = bin32[0];
    v5 = bswap32(bin32[1]);
  }
  v13 = b58bin + 1;
  v14 = &bin32[1];
  *b58bin = v6;
  v15 = b58bin + 25;
  while ( 1 )
  {
    *(_DWORD *)v13 = v5;
    v13 += 4;
    if ( v13 == v15 )
      break;
    v16 = v14[1];
    ++v14;
    v5 = bswap32(v16);
  }
}
