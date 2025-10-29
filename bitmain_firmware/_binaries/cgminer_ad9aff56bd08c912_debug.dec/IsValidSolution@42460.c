int __fastcall IsValidSolution(blake2b_state *base_state, unsigned __int8 *soln)
{
  uint32_t *v4; // r5
  char *v5; // r11
  uint32_t *v6; // r4
  unsigned int v7; // t1
  int v8; // r6
  bool v9; // nf
  int v10; // r6
  uint32_t v11; // r6
  uint32_t v12; // r1
  uint32_t v13; // r2
  uint32_t v14; // r3
  uint32_t v15; // r0
  uint32_t v16; // r1
  uint32_t v17; // r2
  const unsigned __int8 *v18; // r0
  char *v19; // r0
  size_t v20; // r8
  size_t v21; // r9
  int v22; // r10
  const uint8_t *v23; // r5
  const uint8_t *v24; // r6
  const uint8_t *v25; // r2
  const uint8_t *v26; // r3
  int v27; // r0
  int v28; // t1
  int v29; // t1
  const uint8_t *v30; // r7
  const uint8_t *v31; // r12
  uint8_t *v32; // r0
  char v33; // r3
  char v34; // t1
  char v35; // t1
  int v36; // r4
  char *v37; // r0
  size_t v38; // r4
  uint8_t *v39; // r3
  int v41; // r4
  const char *v42; // r0
  const char *v44; // r0
  const char *v45; // r0
  eh_index i; // [sp+Ch] [bp-880h]
  const uint8_t *src; // [sp+10h] [bp-87Ch]
  size_t n; // [sp+14h] [bp-878h]
  unsigned int v49; // [sp+1Ch] [bp-870h]
  int v50; // [sp+20h] [bp-86Ch]
  uint8_t *x; // [sp+24h] [bp-868h]
  size_t v52; // [sp+28h] [bp-864h]
  uint8_t hash[30]; // [sp+34h] [bp-858h] BYREF
  uint8_t vhash[48]; // [sp+54h] [bp-838h] BYREF
  char v55; // [sp+84h] [bp-808h] BYREF
  uint32_t indices[512]; // [sp+88h] [bp-804h] BYREF

  x = (uint8_t *)malloc(0x4400u);
  v4 = (uint32_t *)(x + 30);
  v5 = (char *)malloc(0x4400u);
  memset(indices, 0, sizeof(indices));
  v6 = (uint32_t *)&v55;
  expandArray(soln, 0x540u, (unsigned __int8 *)indices, 0x800u, 0x15u, 1u);
  do
  {
    v7 = v6[1];
    ++v6;
    v8 = bswap32(v7);
    generateHash(base_state, v8 / 2, vhash, 0x32u);
    v9 = v8 < 0;
    v10 = v8 & 1;
    if ( v9 )
      v10 = -v10;
    expandArray(&vhash[25 * v10], 0x19u, hash, 0x1Eu, 0x14u, 0);
    v11 = *v6;
    v12 = *(_DWORD *)&hash[4];
    v13 = *(_DWORD *)&hash[8];
    v14 = *(_DWORD *)&hash[12];
    *(uint32_t *)((char *)v4 - 30) = *(_DWORD *)hash;
    *(uint32_t *)((char *)v4 - 26) = v12;
    *(uint32_t *)((char *)v4 - 22) = v13;
    v15 = *(_DWORD *)&hash[16];
    v16 = *(_DWORD *)&hash[20];
    v17 = *(_DWORD *)&hash[24];
    *(uint32_t *)((char *)v4 - 18) = v14;
    LOWORD(v14) = *(_WORD *)&hash[28];
    *(uint32_t *)((char *)v4 - 14) = v15;
    v18 = (const unsigned __int8 *)v4 - 30;
    *(uint32_t *)((char *)v4 - 10) = v16;
    *((_WORD *)v4 - 1) = v14;
    *(uint32_t *)((char *)v4 - 6) = v17;
    *v4 = v11;
    v4 = (uint32_t *)((char *)v4 + 34);
    v19 = bin2hex(v18, 0x22u);
    free(v19);
  }
  while ( v6 != &indices[511] );
  v20 = 30;
  v21 = 4;
  v22 = 512;
  n = 27;
  while ( 1 )
  {
    v49 = v22;
    if ( v22 )
      break;
    v21 *= 2;
    v52 = n;
LABEL_17:
    v20 -= 3;
    memcpy(x, v5, 0x4400u);
    n -= 3;
    memset(v5, 0, 0x4400u);
    if ( v20 == 3 )
    {
      if ( *x )
      {
LABEL_27:
        v41 = 2;
      }
      else
      {
        v39 = x;
        while ( &x[v52 - 1] != v39 )
        {
          if ( *++v39 )
            goto LABEL_27;
        }
        v41 = 0;
      }
      goto quit;
    }
  }
  v23 = x;
  v50 = 2 * (v20 + v21);
  v24 = &x[v20 + v21];
  v22 = 0;
  v52 = n;
  while ( 1 )
  {
    v25 = v24;
    i = 2 * v22;
    v26 = v23;
    do
    {
      v28 = *v26++;
      v27 = v28;
      v29 = *v25++;
      if ( v27 != v29 )
      {
        LOWORD(v42) = -21916;
        v41 = 2;
        HIWORD(v42) = (unsigned int)" ordered" >> 16;
        puts(v42);
        goto quit;
      }
    }
    while ( v23 + 3 != v26 );
    src = &v23[v20];
    if ( memcmp(&v24[v20], &v23[v20], v21) < 0 )
    {
      LOWORD(v44) = -22004;
      v41 = 2;
      HIWORD(v44) = (unsigned int)"len" >> 16;
      puts(v44);
      goto quit;
    }
    if ( !DistinctIndices(v23, v24, v20, v21) )
      break;
    v30 = v24;
    memset(vhash, 0, 0x1Eu);
    v31 = v23 - 1;
    v32 = vhash;
    do
    {
      v34 = *v30++;
      v33 = v34;
      v35 = *++v31;
      *v32++ = v33 ^ v35;
    }
    while ( v30 != &v24[v20] );
    ++v22;
    v36 = (n + 2 * v21) * (i >> 1);
    v23 += v50;
    v24 += v50;
    v37 = &v5[v36];
    v38 = v36 + n;
    memcpy(v37, &vhash[3], n);
    memcpy(&v5[v38], src, v21);
    memcpy(&v5[v38 + v21], v30, v21);
    if ( v49 <= i + 2 )
    {
      v21 *= 2;
      goto LABEL_17;
    }
  }
  LOWORD(v45) = -21952;
  v41 = 1;
  HIWORD(v45) = (unsigned int)"lid solution: Index tree incorrectly ordered" >> 16;
  puts(v45);
quit:
  free(x);
  free(v5);
  return v41;
}
