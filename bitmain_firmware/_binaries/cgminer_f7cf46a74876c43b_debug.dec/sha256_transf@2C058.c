void __fastcall sha256_transf(sha256_ctx *ctx, const unsigned __int8 *message, unsigned int block_nb)
{
  unsigned __int8 *v3; // r0
  uint32_t *v4; // r5
  uint32_t *v5; // r4
  int v6; // r3
  int v7; // r6
  int v8; // r1
  int v9; // t1
  uint32_t v10; // r5
  uint32_t *v11; // r3
  uint32_t v12; // t1
  sha256_ctx *v13; // r0
  sha256_ctx **v14; // r3
  uint32_t *v15; // r2
  sha256_ctx *v16; // t1
  int v17; // r12
  uint32_t v18; // r3
  uint32_t v19; // r6
  uint32_t v20; // r10
  uint32_t v21; // r9
  uint32_t v22; // r7
  uint32_t v23; // r8
  uint32_t v24; // r11
  uint32_t v25; // lr
  uint32_t v26; // r2
  uint32_t v27; // r4
  uint32_t v28; // r3
  uint32_t v29; // r5
  uint32_t v30; // r1
  uint32_t *v31; // r3
  sha256_ctx **v32; // r1
  sha256_ctx *v33; // t1
  bool v34; // zf
  const unsigned __int8 *sub_block; // [sp+4h] [bp-164h]
  uint32_t *v36; // [sp+8h] [bp-160h]
  const unsigned __int8 *v37; // [sp+14h] [bp-154h]
  uint32_t *h; // [sp+18h] [bp-150h]
  sha256_ctx *v39; // [sp+1Ch] [bp-14Ch] BYREF
  uint32_t wv[8]; // [sp+20h] [bp-148h] BYREF
  uint32_t w[64]; // [sp+40h] [bp-128h] BYREF

  if ( (int)block_nb > 0 )
  {
    h = ctx->h;
    sub_block = message;
    v37 = &message[64 * block_nb];
    v39 = ctx + 1;
    do
    {
      v3 = (unsigned __int8 *)sub_block;
      v4 = &wv[7];
      v5 = w;
      do
      {
        v6 = v3[1];
        v7 = v3[2];
        v8 = v3[3];
        v9 = *v3;
        v3 += 4;
        v4[1] = (v6 << 16) | (v7 << 8) | v8 | (v9 << 24);
        ++v4;
      }
      while ( &w[15] != v4 );
      do
      {
        v10 = v5[14];
        v11 = v5;
        v12 = v5[1];
        ++v5;
        v5[15] = (__ROR4__(v10, 19) ^ __ROR4__(v10, 17) ^ (v10 >> 10))
               + v11[9]
               + *v11
               + (__ROR4__(v12, 18) ^ __ROR4__(v12, 7) ^ (v12 >> 3));
      }
      while ( &w[48] != v5 );
      v13 = v39;
      v14 = &v39;
      v15 = h;
      do
      {
        v16 = (sha256_ctx *)*v15++;
        v14[1] = v16;
        ++v14;
      }
      while ( v13 != (sha256_ctx *)v15 );
      v36 = v15;
      v17 = 0;
      v18 = wv[7];
      v19 = wv[4];
      v20 = wv[5];
      v21 = wv[6];
      v22 = wv[0];
      v23 = wv[1];
      v25 = wv[2];
      v24 = wv[3];
      while ( 1 )
      {
        v26 = (v21 & ~v19 ^ v20 & v19) + (__ROR4__(v19, 11) ^ __ROR4__(v19, 6) ^ __ROR4__(v19, 25)) + w[v17];
        v27 = sha256_k[v17++];
        v28 = v18 + v26 + v27;
        v29 = v24 + v28;
        v30 = (__ROR4__(v22, 13) ^ __ROR4__(v22, 2) ^ __ROR4__(v22, 22)) + ((v25 ^ v23) & v22 ^ v25 & v23) + v28;
        v24 = v25;
        v18 = v21;
        if ( v17 == 64 )
          break;
        v25 = v23;
        v21 = v20;
        v23 = v22;
        v20 = v19;
        v22 = v30;
        v19 = v29;
      }
      wv[0] = v30;
      wv[1] = v22;
      v31 = h;
      v32 = &v39;
      wv[7] = v21;
      wv[4] = v29;
      wv[5] = v19;
      wv[6] = v20;
      wv[2] = v23;
      wv[3] = v25;
      do
      {
        v33 = v32[1];
        ++v32;
        *v31++ += (uint32_t)v33;
      }
      while ( v36 != v31 );
      v34 = v37 == sub_block + 64;
      sub_block += 64;
    }
    while ( !v34 );
  }
}
