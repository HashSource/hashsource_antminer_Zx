void __fastcall b58tobin(unsigned __int8 *b58bin, const char *b58)
{
  uint32_t v2; // r4
  size_t v5; // r0
  unsigned __int8 v6; // r1
  const char *v7; // lr
  int v8; // r8
  const char *v9; // r12
  int v10; // t1
  uint32_t *v11; // r2
  unsigned int v12; // r0
  __int64 v13; // r0
  unsigned __int8 *v14; // r3
  uint32_t *v15; // r2
  unsigned __int8 *v16; // r7
  unsigned int v17; // t1
  int v18; // [sp+0h] [bp-20h] BYREF
  uint32_t bin32[7]; // [sp+4h] [bp-1Ch] BYREF

  v2 = 0;
  memset(bin32, 0, sizeof(bin32));
  v5 = strlen(b58);
  v6 = v5;
  if ( v5 )
  {
    v7 = b58 - 1;
    LOWORD(v8) = 13056;
    v9 = &b58[v5 - 1];
    while ( 1 )
    {
      v10 = *(unsigned __int8 *)++v7;
      v11 = &bin32[6];
      HIWORD(v8) = (unsigned int)"0.0" >> 16;
      v12 = *(_DWORD *)(v8 + 4 * v10 + 1160);
      while ( 1 )
      {
        v13 = 58LL * v2 + v12;
        *v11-- = v13;
        v12 = HIDWORD(v13);
        if ( &v18 == (int *)v11 )
          break;
        v2 = *v11;
      }
      if ( v9 == v7 )
        break;
      v2 = bin32[6];
    }
    v6 = bin32[0];
    v5 = bswap32(bin32[1]);
  }
  v14 = b58bin + 1;
  v15 = &bin32[1];
  *b58bin = v6;
  v16 = b58bin + 25;
  while ( 1 )
  {
    *(_DWORD *)v14 = v5;
    v14 += 4;
    if ( v14 == v16 )
      break;
    v17 = v15[1];
    ++v15;
    v5 = bswap32(v17);
  }
}
