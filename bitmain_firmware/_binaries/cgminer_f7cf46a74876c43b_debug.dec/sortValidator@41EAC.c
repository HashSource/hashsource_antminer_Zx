int __fastcall sortValidator(void *data, const unsigned __int8 *soln)
{
  int v2; // r4
  int v3; // r11
  int v4; // r6
  int v6; // r1
  int v7; // r3
  bool v8; // cf
  int v9; // r1
  uint32_t *v10; // r4
  int v11; // r0
  uint32_t v12; // r1
  uint32_t v13; // t1
  int v14; // r3
  int v15; // r4
  int v17; // r4
  uint32_t *v18; // r10
  int v19; // r3
  int v20; // r6
  uint8_t *v21; // r9
  unsigned int v22; // t1
  signed int v23; // r0
  int v24; // r5
  int v25; // r0
  int v26; // r5
  uint8_t *v27; // r2
  uint8_t *i; // r1
  char v29; // t1
  uint8_t *j; // r3
  int v31; // t1
  size_t v32; // r10
  uint8_t *v33; // r8
  int v34; // r9
  uint8_t *v35; // r5
  uint8_t *v36; // r11
  int v37; // r7
  int v38; // lr
  uint8_t *v39; // r0
  uint8_t *v40; // r4
  uint8_t *v41; // r12
  char v42; // r3
  char v43; // t1
  char v44; // t1
  int v45; // r4
  uint8_t *v46; // r0
  int v47; // r4
  uint8_t *v48; // r1
  uint8_t *v49; // r3
  uint8_t *v50; // r2
  uint32_t *v51; // r8
  unsigned int v52; // t1
  int k; // r10
  uint32_t *v54; // r7
  int v55; // r6
  uint32_t *v56; // r7
  uint8_t *v57; // r5
  signed int v58; // t1
  int v59; // r4
  int v60; // r0
  int v61; // r4
  unsigned int v62; // r4
  const unsigned __int8 *v63; // r0
  char *v64; // r0
  uint8_t *v65; // r9
  size_t v66; // r8
  int v67; // r7
  size_t v68; // r3
  int v69; // r11
  uint8_t *v70; // r10
  uint8_t *v71; // r5
  int v72; // lr
  uint8_t *v73; // r0
  uint8_t *v74; // r4
  uint8_t *v75; // r12
  char v76; // r3
  char v77; // t1
  char v78; // t1
  int v79; // r4
  uint8_t *v80; // r0
  size_t v81; // r4
  uint8_t *v82; // r1
  uint8_t *v83; // r3
  int v84; // r4
  uint8_t *v85; // r6
  unsigned int v86; // r2
  unsigned int v87; // r3
  char *v88; // r0
  uint8_t *v89; // r7
  int v90; // r1
  char *v91; // r0
  char *v92; // r0
  int v93; // r1
  int v94; // r2
  int v95; // r3
  int v96; // r1
  int v97; // r2
  int v98; // r3
  uint8_t *v99; // r3
  int v100; // t1
  size_t x_size_0; // [sp+8h] [bp-5E0h]
  uint32_t x_size_0a; // [sp+8h] [bp-5E0h]
  blake2b_state *digest; // [sp+Ch] [bp-5DCh]
  size_t digesta; // [sp+Ch] [bp-5DCh]
  size_t in_len; // [sp+10h] [bp-5D8h]
  int v106; // [sp+14h] [bp-5D4h]
  int v107; // [sp+14h] [bp-5D4h]
  size_t hashLen; // [sp+18h] [bp-5D0h]
  uint8_t *x; // [sp+1Ch] [bp-5CCh]
  uint8_t *xc; // [sp+20h] [bp-5C8h]
  int v111; // [sp+28h] [bp-5C0h]
  int v112; // [sp+28h] [bp-5C0h]
  size_t x_size; // [sp+2Ch] [bp-5BCh]
  size_t v114; // [sp+30h] [bp-5B8h]
  int v115; // [sp+34h] [bp-5B4h]
  int n; // [sp+44h] [bp-5A4h]
  uint8_t vHash[30]; // [sp+48h] [bp-5A0h] BYREF
  char v118; // [sp+66h] [bp-582h] BYREF
  uint8_t tmp_hash[30]; // [sp+68h] [bp-580h] BYREF
  unsigned __int8 hash[31]; // [sp+88h] [bp-560h] BYREF
  char v121; // [sp+A7h] [bp-541h] BYREF
  uint8_t tmpHash_0[1340]; // [sp+A8h] [bp-540h] BYREF
  char v123; // [sp+5E4h] [bp-4h] BYREF
  char v124; // [sp+5E7h] [bp-1h] BYREF
  uint32_t indices[512]; // [sp+5E8h] [bp+0h] BYREF
  uint8_t tmpHash[2040]; // [sp+DE8h] [bp+800h] BYREF
  int v127; // [sp+15E4h] [bp+FFCh] BYREF

  v2 = *((_DWORD *)data + 1);
  v3 = *(_DWORD *)data;
  v4 = v2 + 1;
  digest = (blake2b_state *)*((_DWORD *)data + 2);
  x_size_0 = *(_DWORD *)data / (v2 + 1);
  v6 = (v3 / (v2 + 1) + 1) << v2;
  v7 = v6 + 7;
  v8 = v6 < 0;
  v9 = v6 & ~(v6 >> 31);
  if ( v8 )
    v9 = v7;
  compare_size = 3;
  expandArray(soln, v9 >> 3, (unsigned __int8 *)indices, 0x800u, v3 / (v2 + 1) + 1, 1u);
  v10 = indices;
  memset(vHash, 0, sizeof(vHash));
  x = (uint8_t *)malloc(0x4400u);
  xc = (uint8_t *)malloc(0x4400u);
  memset(tmp_hash, 0, sizeof(tmp_hash));
  v11 = 0;
  while ( ++v11 != 512 )
  {
    v12 = *v10;
    v13 = v10[1];
    ++v10;
    if ( v12 == v13 )
    {
LABEL_9:
      v15 = 1;
      goto failed;
    }
    v14 = v11;
    while ( ++v14 != 512 )
    {
      if ( v12 == indices[v14] )
        goto LABEL_9;
    }
  }
  v17 = 0;
  v18 = (uint32_t *)&v123;
  v19 = x_size_0 + 14;
  if ( (int)(x_size_0 + 7) >= 0 )
    v19 = x_size_0 + 7;
  v20 = v4 * (v19 >> 3);
  v21 = x;
  v106 = 512 / v3;
  in_len = v3 / 8;
  v111 = v20 + 4;
  hashLen = 512 / v3 * v3 / 8;
  do
  {
    v22 = v18[1];
    ++v18;
    v23 = bswap32(v22);
    v24 = v3 * (v23 % v106);
    generateHash(digest, v23 / v106, tmpHash, hashLen);
    v25 = v24 + 7;
    v8 = v24 < 0;
    v26 = v24 & ~(v24 >> 31);
    if ( v8 )
      v26 = v25;
    expandArray(&tmpHash[v26 >> 3], in_len, tmpHash_0, v20, x_size_0, 0);
    if ( v20 )
    {
      v27 = tmpHash_0;
      for ( i = vHash; ; LOBYTE(v17) = *i )
      {
        v29 = *v27++;
        *i++ = v17 ^ v29;
        if ( v27 == &tmpHash_0[v20] )
          break;
      }
      v17 = vHash[0];
    }
    memcpy(v21, tmpHash_0, v20);
    *(_DWORD *)&v21[v20] = *v18;
    v21 += v111;
  }
  while ( v18 != &indices[511] );
  for ( j = vHash; ; ++j )
  {
    if ( v17 )
    {
      v15 = 2;
      goto failed;
    }
    if ( j == &vHash[29] )
      break;
    v31 = j[1];
    v17 = v31;
  }
  v32 = 4;
  memset(vHash, 0, sizeof(vHash));
  v33 = xc;
  n = v3;
  v115 = 9;
  x_size = 512;
  while ( 1 )
  {
    qsort(x, x_size, v20 + v32, compareSR);
    v34 = 2 * (v20 + v32);
    v35 = &x[v20 + v32 + v20];
    v36 = &x[v20];
    v37 = 0;
    x_size = ((x_size - 1) >> 1) + 1;
    do
    {
      v38 = 2 * v37;
      if ( v20 )
      {
        v39 = &v35[-v20];
        v40 = tmp_hash;
        v41 = &v36[~v20];
        do
        {
          v43 = *v39++;
          v42 = v43;
          v44 = *++v41;
          *v40++ = v42 ^ v44;
        }
        while ( v35 != v39 );
      }
      ++v37;
      v45 = (v20 + v32 + v32) * (v38 >> 1);
      v46 = &v33[v45];
      v47 = v45 + v20;
      memcpy(v46, tmp_hash, v20);
      v48 = v36;
      v36 += v34;
      memcpy(&v33[v47], v48, v32);
      memcpy(&v33[v47 + v32], v35, v32);
      v35 += v34;
    }
    while ( v37 != x_size );
    v32 *= 2;
    compare_size += 3;
    if ( !--v115 )
      break;
    v49 = x;
    x = v33;
    v33 = v49;
  }
  xc = v33;
  v50 = &v33[v20 - 4];
  v51 = &indices[511];
  do
  {
    v52 = *((_DWORD *)v50 + 1);
    v50 += 4;
    v51[1] = bswap32(v52);
    ++v51;
  }
  while ( &v127 != (int *)v51 );
  v114 = v20;
  for ( k = 0; k != 9; ++k )
  {
    v54 = (uint32_t *)tmpHash;
    v55 = 0;
    do
    {
      v55 += 2 << k;
      sort_pair(v54, 1 << k);
      v54 += 2 << k;
    }
    while ( v55 < 512 );
  }
  v56 = &indices[511];
  v57 = xc;
  do
  {
    v58 = v56[1];
    ++v56;
    v59 = n * (v58 % v106);
    generateHash(digest, v58 / v106, tmpHash_0, hashLen);
    v60 = v59 + 7;
    v8 = v59 < 0;
    v61 = v59 & ~(v59 >> 31);
    if ( v8 )
      v61 = v60;
    expandArray(&tmpHash_0[v61 >> 3], in_len, hash, v114, x_size_0, 0);
    v62 = bswap32(*v56);
    memcpy(v57, hash, v114);
    *(_DWORD *)&v57[v114] = v62;
    v63 = v57;
    v57 += v111;
    v64 = bin2hex(v63, 0x22u);
    free(v64);
  }
  while ( v56 != v51 );
  v65 = x;
  v66 = 4;
  x_size_0a = 512;
  v107 = compare_size + 3;
  v112 = compare_size + 30;
  while ( 1 )
  {
    v67 = 0;
    v68 = v114 + 2 * v66;
    v69 = 2 * (v68 - v66);
    v70 = &xc[v114];
    v71 = &xc[v114 + v68 - v66];
    digesta = v68;
    x_size_0a = ((x_size_0a - 1) >> 1) + 1;
    do
    {
      v72 = 2 * v67;
      if ( v114 )
      {
        v73 = &v71[-v114];
        v74 = tmp_hash;
        v75 = &v70[~v114];
        do
        {
          v77 = *v73++;
          v76 = v77;
          v78 = *++v75;
          *v74++ = v76 ^ v78;
        }
        while ( v71 != v73 );
      }
      ++v67;
      v79 = digesta * (v72 >> 1);
      v80 = &v65[v79];
      v81 = v79 + v114;
      memcpy(v80, tmp_hash, v114);
      v82 = v70;
      v70 += v69;
      memcpy(&v65[v81], v82, v66);
      memcpy(&v65[v81 + v66], v71, v66);
      v71 += v69;
    }
    while ( x_size_0a != v67 );
    v66 *= 2;
    compare_size = v107;
    v107 += 3;
    if ( v112 == v107 )
      break;
    v83 = xc;
    xc = v65;
    v65 = v83;
  }
  v84 = 0;
  v85 = &v65[v114];
  v86 = 0;
  v87 = 0;
  v88 = &v121;
  x = v65;
  do
  {
    if ( v87 <= 7 )
    {
      v89 = &v85[v84];
      v87 += 21;
      v90 = v85[v84 + 3];
      v84 += 4;
      v86 = v90 | (v86 << 21) | (v89[2] << 8) | ((v89[1] & 0x1F) << 16);
    }
    v87 -= 8;
    *++v88 = v86 >> v87;
  }
  while ( &v124 != v88 );
  v91 = bin2hex(tmpHash_0, 0x540u);
  free(v91);
  v92 = bin2hex(v65, digesta);
  free(v92);
  v93 = *((_DWORD *)v65 + 1);
  v94 = *((_DWORD *)v65 + 2);
  v95 = *((_DWORD *)v65 + 3);
  *(_DWORD *)vHash = *(_DWORD *)v65;
  *(_DWORD *)&vHash[4] = v93;
  *(_DWORD *)&vHash[8] = v94;
  *(_DWORD *)&vHash[12] = v95;
  v96 = *((_DWORD *)v65 + 5);
  v97 = *((_DWORD *)v65 + 6);
  v98 = *((_DWORD *)v65 + 7);
  *(_DWORD *)&vHash[16] = *((_DWORD *)v65 + 4);
  *(_DWORD *)&vHash[20] = v96;
  *(_DWORD *)&vHash[24] = v97;
  *(_WORD *)&vHash[28] = v98;
  v99 = vHash;
  while ( 1 )
  {
    v100 = *v99++;
    v15 = v100;
    if ( v100 )
      break;
    if ( &v118 == (char *)v99 )
      goto failed;
  }
  v15 = 3;
failed:
  free(x);
  free(xc);
  return v15;
}
