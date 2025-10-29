int __fastcall sub_55470(unsigned __int8 *a1)
{
  char *v1; // r2
  unsigned __int8 *v2; // r3
  int v3; // r12
  int v4; // r0
  int v5; // r1
  unsigned __int8 *v6; // r1
  int i; // r3
  int v8; // r9
  int v9; // r3
  unsigned int v10; // r6
  unsigned int v11; // r5
  int v12; // r6
  _BYTE *v13; // r2
  _BYTE *v14; // r5
  int v15; // r6
  _BYTE *v16; // r7
  _BYTE *v17; // r11
  _BYTE *v18; // r12
  int v19; // r1
  int v20; // r8
  int v21; // r4
  int v22; // r12
  int v23; // r0
  int v24; // r1
  int v25; // r4
  int v26; // r12
  unsigned __int8 *v27; // r2
  int k; // r3
  int result; // r0
  int v30; // [sp+0h] [bp-B8h] BYREF
  int v31; // [sp+4h] [bp-B4h]
  int j; // [sp+8h] [bp-B0h]
  char *v33; // [sp+Ch] [bp-ACh]
  int v34; // [sp+10h] [bp-A8h]
  unsigned __int8 *v35; // [sp+14h] [bp-A4h]
  _DWORD v36[7]; // [sp+18h] [bp-A0h]
  char v37; // [sp+34h] [bp-84h] BYREF
  _BYTE var44[100]; // [sp+74h] [bp-44h] BYREF

  v1 = &v37;
  v2 = a1;
  v35 = a1;
  do
  {
    v3 = v2[43];
    v4 = v2[42];
    v5 = (v2[41] << 16) + (v2[40] << 24);
    v2 += 4;
    *((_DWORD *)v1 + 1) = v5 + v3 + (v4 << 8);
    v1 += 4;
  }
  while ( v1 != var44 );
  v6 = v35;
  for ( i = 0; i != 8; ++i )
    v36[i] = *(_DWORD *)&v6[i * 4];
  for ( j = 0; j != 64; j += 16 )
  {
    v8 = 0;
    v9 = 7;
    v33 = (char *)&unk_6C580 + 4 * j;
    do
    {
      v20 = v9 - 1;
      v21 = v36[((_BYTE)v9 - 3) & 7];
      v22 = v36[(v9 - 1) & 7];
      v23 = __ROR4__(v21, 6) ^ __ROR4__(v21, 11) ^ __ROR4__(v21, 25);
      v24 = (v22 ^ v36[((_BYTE)v9 - 2) & 7]) & v21 ^ v22;
      v25 = v36[v9 & 7];
      v26 = *(_DWORD *)&v33[v8];
      if ( j )
      {
        v10 = *(_DWORD *)&var44[4 * ((5 - (_BYTE)v9) & 0xF) + 4];
        v11 = *(_DWORD *)&var44[4 * ((-8 - (_BYTE)v9) & 0xF) + 4];
        v31 = *(_DWORD *)&var44[4 * (-v9 & 0xF) + 4];
        v30 = __ROR4__(v10, 17) ^ __ROR4__(v10, 19);
        v34 = __ROR4__(v11, 7);
        v31 += *(_DWORD *)&var44[v8 + 4];
        v12 = v31 + (v30 ^ (v10 >> 10)) + (v34 ^ __ROR4__(v11, 18) ^ (v11 >> 3));
      }
      else
      {
        v12 = *(int *)((char *)&v30 + v8 + 56);
      }
      *(_DWORD *)&var44[v8 + 4] = v12;
      v13 = &var44[4 * (v9 & 7) + 68];
      v14 = &var44[4 * (((_BYTE)v9 - 4) & 7) + 68];
      v15 = v25 + v26 + v23 + v24 + v12;
      v16 = &var44[4 * (((_BYTE)v9 - 7) & 7) + 68];
      *((_DWORD *)v13 - 40) = v15;
      v17 = &var44[4 * (((_BYTE)v9 - 6) & 7) + 68];
      v18 = &var44[4 * (((_BYTE)v9 - 5) & 7) + 68];
      *((_DWORD *)v14 - 40) += v15;
      --v9;
      v19 = *((_DWORD *)v16 - 40);
      v8 += 4;
      *((_DWORD *)v13 - 40) += (__ROR4__(v19, 2) ^ __ROR4__(v19, 13) ^ __ROR4__(v19, 22))
                             + ((v19 | *((_DWORD *)v17 - 40)) & *((_DWORD *)v18 - 40) | v19 & *((_DWORD *)v17 - 40));
    }
    while ( v20 != -9 );
  }
  v27 = v35;
  for ( k = 0; k != 8; ++k )
  {
    result = *(_DWORD *)&v27[k * 4];
    *(_DWORD *)&v27[k * 4] = result + v36[k];
  }
  return result;
}
