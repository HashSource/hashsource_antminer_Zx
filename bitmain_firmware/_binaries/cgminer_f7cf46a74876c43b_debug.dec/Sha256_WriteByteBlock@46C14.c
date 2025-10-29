void __fastcall Sha256_WriteByteBlock(CSha256 *p)
{
  uint32_t *v1; // r6
  unsigned __int8 *v2; // r5
  int v3; // r3
  CSha256 *v4; // r2
  _DWORD *v5; // r3
  uint32_t v6; // t1
  int v7; // r1
  int v8; // r10
  const uint32_t *v9; // r11
  const uint32_t *v10; // r9
  int v11; // lr
  int i; // r5
  int v13; // t1
  int v14; // r2
  int v15; // r7
  int v16; // r3
  int v17; // r1
  unsigned int v18; // r7
  unsigned int v19; // r10
  int v20; // r7
  int v21; // r1
  _DWORD *v22; // r2
  _DWORD *v23; // r3
  _DWORD *v24; // r6
  int v25; // r1
  _DWORD *v26; // r12
  _DWORD *v27; // r7
  int v28; // r5
  int v29; // t1
  _DWORD *v30; // r2
  CSha256 *v31; // r11
  uint32_t v32; // r3
  uint32_t v33; // t1
  int v34; // t1
  int v35; // [sp+34h] [bp-6Ch]
  CSha256 *v36; // [sp+38h] [bp-68h]
  _DWORD v37[8]; // [sp+40h] [bp-60h] BYREF
  char v38; // [sp+60h] [bp-40h] BYREF
  uint32_t data32[16]; // [sp+64h] [bp-3Ch] BYREF
  _DWORD v40[17]; // [sp+A4h] [bp+4h] BYREF

  v1 = (uint32_t *)&v38;
  v2 = (unsigned __int8 *)p;
  do
  {
    v3 = v2[41];
    v2 += 4;
    v1[1] = (v3 << 16) + (v2[36] << 24) + v2[39] + (v2[38] << 8);
    ++v1;
  }
  while ( &data32[15] != v1 );
  v4 = (CSha256 *)((char *)p - 4);
  v5 = v37;
  do
  {
    v6 = v4->state[1];
    v4 = (CSha256 *)((char *)v4 + 4);
    v5[1] = v6;
    ++v5;
  }
  while ( &p->state[7] != (uint32_t *)v4 );
  v7 = 1116352408;
  v37[0] = (char *)p - 4;
  v8 = 0;
  v9 = K;
  v36 = v4;
  while ( 1 )
  {
    v10 = v9;
    v11 = 0;
    v35 = v8;
    for ( i = v7; ; i = v13 )
    {
      v14 = v37[((4 - (_BYTE)v11) & 7) + 1];
      v15 = v37[((6 - (_BYTE)v11) & 7) + 1];
      v16 = __ROR4__(v14, 11) ^ __ROR4__(v14, 6) ^ __ROR4__(v14, 25);
      v17 = (v37[((5 - (_BYTE)v11) & 7) + 1] ^ v15) & v14 ^ v15;
      if ( v35 )
      {
        v18 = v40[((_BYTE)v11 - 2) & 0xF];
        v19 = v40[((_BYTE)v11 - 15) & 0xF];
        v20 = v40[((_BYTE)v11 - 7) & 0xF]
            + v40[v11]
            + (__ROR4__(v18, 19) ^ __ROR4__(v18, 17) ^ (v18 >> 10))
            + (__ROR4__(v19, 18) ^ __ROR4__(v19, 7) ^ (v19 >> 3));
      }
      else
      {
        v20 = data32[v11];
      }
      v40[v11] = v20;
      v21 = v17 + v16;
      v22 = &v40[((7 - (_BYTE)v11) & 7) + 16];
      v23 = &v40[((3 - (_BYTE)v11) & 7) + 16];
      v24 = &v40[(-v11 & 7) + 16];
      v25 = v21 + *(v22 - 40) + v20 + i;
      *(v22 - 40) = v25;
      v26 = &v40[((1 - (_BYTE)v11) & 7) + 16];
      v27 = &v40[((2 - (_BYTE)v11++) & 7) + 16];
      *(v23 - 40) += v25;
      v28 = *(v24 - 40);
      *(v22 - 40) += ((v28 | *(v26 - 40)) & *(v27 - 40) | *(v26 - 40) & v28)
                   + (__ROR4__(v28, 13) ^ __ROR4__(v28, 2) ^ __ROR4__(v28, 22));
      if ( v11 == 16 )
        break;
      v13 = v10[1];
      ++v10;
    }
    v8 = v35 + 16;
    if ( v35 == 48 )
      break;
    v29 = v9[16];
    v9 += 16;
    v7 = v29;
  }
  v30 = v37;
  v31 = (CSha256 *)v37[0];
  do
  {
    v33 = v31->state[1];
    v31 = (CSha256 *)((char *)v31 + 4);
    v32 = v33;
    v34 = v30[1];
    ++v30;
    v31->state[0] = v32 + v34;
  }
  while ( v36 != v31 );
}
