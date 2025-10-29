unsigned __int8 *__fastcall ser_string(char *s, int *slen)
{
  size_t v4; // r4
  unsigned __int8 *v5; // r0
  unsigned __int8 *v6; // r5
  int *v8; // lr
  int v9; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // lr
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  v4 = strlen(s);
  v5 = (unsigned __int8 *)malloc(v4 + 9);
  v6 = v5;
  if ( !v5 )
  {
    LOWORD(v8) = 16168;
    HIWORD(v8) = (unsigned int)"hex2bin str truncated" >> 16;
    v9 = *v8;
    v10 = v8[1];
    v11 = v8[2];
    v12 = v8[3];
    v8 += 4;
    *(_DWORD *)tmp42 = v9;
    *(_DWORD *)&tmp42[4] = v10;
    *(_DWORD *)&tmp42[8] = v11;
    *(_DWORD *)&tmp42[12] = v12;
    v13 = *v8;
    v14 = v8[1];
    v15 = v8[2];
    v16 = v8[3];
    v17 = v8[4];
    *(_DWORD *)&tmp42[16] = v13;
    *(_DWORD *)&tmp42[20] = v14;
    *(_DWORD *)&tmp42[24] = v15;
    *(_DWORD *)&tmp42[28] = v16;
    *(_WORD *)&tmp42[32] = v17;
    tmp42[34] = BYTE2(v17);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( v4 <= 0xFC )
  {
    *v5 = v4;
    memcpy(v5 + 1, s, v4);
    *slen = v4 + 1;
    return v6;
  }
  else
  {
    if ( v4 < 0x10000 )
    {
      *v5 = -3;
      *(_WORD *)(v5 + 1) = __rev16(v4);
      memcpy(v5 + 3, s, v4);
      *slen = v4 + 3;
    }
    else
    {
      *v5 = -2;
      *(_DWORD *)(v5 + 1) = bswap32(v4);
      memcpy(v5 + 5, s, v4);
      *slen = v4 + 5;
    }
    return v6;
  }
}
