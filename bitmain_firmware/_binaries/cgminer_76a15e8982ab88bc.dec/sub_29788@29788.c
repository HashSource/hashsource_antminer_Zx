bool __fastcall sub_29788(_BYTE *a1, unsigned __int8 *a2, int a3)
{
  int v3; // r3
  int v4; // r12
  unsigned __int8 *v5; // r1
  char *v6; // r3
  char *v7; // r12
  int v8; // r12
  bool v9; // zf
  int v10; // r3
  int v11; // r12
  int v12; // r3
  char v14[4100]; // [sp+0h] [bp-1004h] BYREF

  v3 = *a2;
  if ( !*a2 )
    return a3 == 0;
  if ( a3 )
  {
    v4 = a2[1];
    if ( a2[1] )
    {
      v5 = a2 + 2;
      v6 = &aClearSock[4 * v3];
      v7 = &aClearSock[4 * v4];
      while ( 1 )
      {
        v10 = *((_DWORD *)v6 + 27);
        v11 = *((_DWORD *)v7 + 27);
        if ( (v11 | v10) < 0 )
          break;
        --a3;
        *a1++ = v11 | (16 * v10);
        v12 = *v5;
        v9 = v12 == 0;
        v6 = &aClearSock[4 * v12];
        if ( v9 )
          return a3 == 0;
        if ( !a3 )
          return 0;
        v8 = v5[1];
        v5 += 2;
        v9 = v8 == 0;
        v7 = &aClearSock[4 * v8];
        if ( v9 )
          goto LABEL_11;
      }
      if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
      {
        strcpy(v14, "hex2bin scan failed");
        sub_385C8(3, v14, 0);
        return 0;
      }
    }
    else
    {
LABEL_11:
      if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
      {
        strcpy(v14, "hex2bin str truncated");
        sub_385C8(3, v14, 0);
      }
    }
  }
  return 0;
}
