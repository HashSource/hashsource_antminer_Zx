void __fastcall Sha256_WriteByteBlock(CSha256 *p)
{
  uint32_t *v1; // r6
  unsigned __int8 *v2; // r5
  int v3; // r3
  CSha256 *v4; // r2
  _DWORD *v5; // r3
  uint32_t v6; // t1
  int v7; // r3
  int v8; // r1
  int v9; // r10
  int v10; // r11
  int v11; // r9
  int v12; // lr
  int i; // r5
  int v14; // t1
  int v15; // r2
  int v16; // r7
  int v17; // r3
  int v18; // r1
  unsigned int v19; // r7
  unsigned int v20; // r10
  int v21; // r7
  int v22; // r1
  _DWORD *v23; // r2
  _DWORD *v24; // r3
  _DWORD *v25; // r6
  int v26; // r1
  _DWORD *v27; // r12
  _DWORD *v28; // r7
  int v29; // r5
  int v30; // t1
  _DWORD *v31; // r2
  CSha256 *v32; // r11
  uint32_t v33; // r3
  uint32_t v34; // t1
  int v35; // t1
  int v36; // [sp+34h] [bp-6Ch]
  CSha256 *v37; // [sp+38h] [bp-68h]
  _DWORD v38[8]; // [sp+40h] [bp-60h] BYREF
  char v39; // [sp+60h] [bp-40h] BYREF
  uint32_t data32[16]; // [sp+64h] [bp-3Ch] BYREF
  _DWORD v41[17]; // [sp+A4h] [bp+4h] BYREF

  v1 = (uint32_t *)&v39;
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
  v5 = v38;
  do
  {
    v6 = v4->state[1];
    v4 = (CSha256 *)((char *)v4 + 4);
    v5[1] = v6;
    ++v5;
  }
  while ( &p->state[7] != (uint32_t *)v4 );
  LOWORD(v7) = -21776;
  v8 = 1116352408;
  HIWORD(v7) = (unsigned int)&blake2b_IV[2] >> 16;
  v38[0] = (char *)p - 4;
  v9 = 0;
  v10 = v7;
  v37 = v4;
  while ( 1 )
  {
    v11 = v10;
    v12 = 0;
    v36 = v9;
    for ( i = v8; ; i = v14 )
    {
      v15 = v38[((4 - (_BYTE)v12) & 7) + 1];
      v16 = v38[((6 - (_BYTE)v12) & 7) + 1];
      v17 = __ROR4__(v15, 11) ^ __ROR4__(v15, 6) ^ __ROR4__(v15, 25);
      v18 = (v38[((5 - (_BYTE)v12) & 7) + 1] ^ v16) & v15 ^ v16;
      if ( v36 )
      {
        v19 = v41[((_BYTE)v12 - 2) & 0xF];
        v20 = v41[((_BYTE)v12 - 15) & 0xF];
        v21 = v41[((_BYTE)v12 - 7) & 0xF]
            + v41[v12]
            + (__ROR4__(v19, 19) ^ __ROR4__(v19, 17) ^ (v19 >> 10))
            + (__ROR4__(v20, 18) ^ __ROR4__(v20, 7) ^ (v20 >> 3));
      }
      else
      {
        v21 = data32[v12];
      }
      v41[v12] = v21;
      v22 = v18 + v17;
      v23 = &v41[((7 - (_BYTE)v12) & 7) + 16];
      v24 = &v41[((3 - (_BYTE)v12) & 7) + 16];
      v25 = &v41[(-v12 & 7) + 16];
      v26 = v22 + *(v23 - 40) + v21 + i;
      *(v23 - 40) = v26;
      v27 = &v41[((1 - (_BYTE)v12) & 7) + 16];
      v28 = &v41[((2 - (_BYTE)v12++) & 7) + 16];
      *(v24 - 40) += v26;
      v29 = *(v25 - 40);
      *(v23 - 40) += ((v29 | *(v27 - 40)) & *(v28 - 40) | *(v27 - 40) & v29)
                   + (__ROR4__(v29, 13) ^ __ROR4__(v29, 2) ^ __ROR4__(v29, 22));
      if ( v12 == 16 )
        break;
      v14 = *(_DWORD *)(v11 + 4);
      v11 += 4;
    }
    v9 = v36 + 16;
    if ( v36 == 48 )
      break;
    v30 = *(_DWORD *)(v10 + 64);
    v10 += 64;
    v8 = v30;
  }
  v31 = v38;
  v32 = (CSha256 *)v38[0];
  do
  {
    v34 = v32->state[1];
    v32 = (CSha256 *)((char *)v32 + 4);
    v33 = v34;
    v35 = v31[1];
    ++v31;
    v32->state[0] = v33 + v35;
  }
  while ( v37 != v32 );
}
