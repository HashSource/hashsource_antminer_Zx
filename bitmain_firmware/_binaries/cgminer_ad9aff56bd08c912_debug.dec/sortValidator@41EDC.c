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
  int (*v33)(const void *, const void *); // r3
  uint8_t *v34; // r8
  int v35; // r9
  uint8_t *v36; // r5
  uint8_t *v37; // r11
  int v38; // r7
  int v39; // lr
  uint8_t *v40; // r0
  uint8_t *v41; // r4
  uint8_t *v42; // r12
  char v43; // r3
  char v44; // t1
  char v45; // t1
  int v46; // r4
  uint8_t *v47; // r0
  int v48; // r4
  uint8_t *v49; // r1
  uint8_t *v50; // r3
  uint8_t *v51; // r2
  uint32_t *v52; // r8
  unsigned int v53; // t1
  int k; // r10
  uint32_t *v55; // r7
  int v56; // r6
  uint32_t *v57; // r7
  uint8_t *v58; // r5
  signed int v59; // t1
  int v60; // r4
  int v61; // r0
  int v62; // r4
  unsigned int v63; // r4
  const unsigned __int8 *v64; // r0
  char *v65; // r0
  uint8_t *v66; // r9
  size_t v67; // r8
  int v68; // r7
  size_t v69; // r3
  int v70; // r11
  uint8_t *v71; // r10
  uint8_t *v72; // r5
  int v73; // lr
  uint8_t *v74; // r0
  uint8_t *v75; // r4
  uint8_t *v76; // r12
  char v77; // r3
  char v78; // t1
  char v79; // t1
  int v80; // r4
  uint8_t *v81; // r0
  size_t v82; // r4
  uint8_t *v83; // r1
  uint8_t *v84; // r3
  int v85; // r4
  uint8_t *v86; // r6
  unsigned int v87; // r2
  unsigned int v88; // r3
  char *v89; // r0
  uint8_t *v90; // r7
  int v91; // r1
  char *v92; // r0
  char *v93; // r0
  int v94; // r1
  int v95; // r2
  int v96; // r3
  int v97; // r1
  int v98; // r2
  int v99; // r3
  uint8_t *v100; // r3
  int v101; // t1
  size_t x_size_0; // [sp+8h] [bp-5E0h]
  uint32_t x_size_0a; // [sp+8h] [bp-5E0h]
  blake2b_state *digest; // [sp+Ch] [bp-5DCh]
  size_t digesta; // [sp+Ch] [bp-5DCh]
  size_t in_len; // [sp+10h] [bp-5D8h]
  int v107; // [sp+14h] [bp-5D4h]
  int v108; // [sp+14h] [bp-5D4h]
  size_t hashLen; // [sp+18h] [bp-5D0h]
  uint8_t *x; // [sp+1Ch] [bp-5CCh]
  uint8_t *xc; // [sp+20h] [bp-5C8h]
  int v112; // [sp+28h] [bp-5C0h]
  int v113; // [sp+28h] [bp-5C0h]
  size_t x_size; // [sp+2Ch] [bp-5BCh]
  size_t v115; // [sp+30h] [bp-5B8h]
  int v116; // [sp+34h] [bp-5B4h]
  int (*compar)(const void *, const void *); // [sp+3Ch] [bp-5ACh]
  int n; // [sp+44h] [bp-5A4h]
  uint8_t vHash[30]; // [sp+48h] [bp-5A0h] BYREF
  char v120; // [sp+66h] [bp-582h] BYREF
  uint8_t tmp_hash[30]; // [sp+68h] [bp-580h] BYREF
  unsigned __int8 hash[31]; // [sp+88h] [bp-560h] BYREF
  char v123; // [sp+A7h] [bp-541h] BYREF
  uint8_t tmpHash_0[1340]; // [sp+A8h] [bp-540h] BYREF
  char v125; // [sp+5E4h] [bp-4h] BYREF
  char v126; // [sp+5E7h] [bp-1h] BYREF
  uint32_t indices[512]; // [sp+5E8h] [bp+0h] BYREF
  uint8_t tmpHash[2040]; // [sp+DE8h] [bp+800h] BYREF
  int v129; // [sp+15E4h] [bp+FFCh] BYREF

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
  v18 = (uint32_t *)&v125;
  v19 = x_size_0 + 14;
  if ( (int)(x_size_0 + 7) >= 0 )
    v19 = x_size_0 + 7;
  v20 = v4 * (v19 >> 3);
  v21 = x;
  v107 = 512 / v3;
  in_len = v3 / 8;
  v112 = v20 + 4;
  hashLen = 512 / v3 * v3 / 8;
  do
  {
    v22 = v18[1];
    ++v18;
    v23 = bswap32(v22);
    v24 = v3 * (v23 % v107);
    generateHash(digest, v23 / v107, tmpHash, hashLen);
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
    v21 += v112;
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
  LOWORD(v33) = 7457;
  v34 = xc;
  HIWORD(v33) = ((unsigned int)&loc_41CEE + 3) >> 16;
  n = v3;
  compar = v33;
  v116 = 9;
  x_size = 512;
  while ( 1 )
  {
    qsort(x, x_size, v20 + v32, compar);
    v35 = 2 * (v20 + v32);
    v36 = &x[v20 + v32 + v20];
    v37 = &x[v20];
    v38 = 0;
    x_size = ((x_size - 1) >> 1) + 1;
    do
    {
      v39 = 2 * v38;
      if ( v20 )
      {
        v40 = &v36[-v20];
        v41 = tmp_hash;
        v42 = &v37[~v20];
        do
        {
          v44 = *v40++;
          v43 = v44;
          v45 = *++v42;
          *v41++ = v43 ^ v45;
        }
        while ( v36 != v40 );
      }
      ++v38;
      v46 = (v20 + v32 + v32) * (v39 >> 1);
      v47 = &v34[v46];
      v48 = v46 + v20;
      memcpy(v47, tmp_hash, v20);
      v49 = v37;
      v37 += v35;
      memcpy(&v34[v48], v49, v32);
      memcpy(&v34[v48 + v32], v36, v32);
      v36 += v35;
    }
    while ( v38 != x_size );
    v32 *= 2;
    compare_size += 3;
    if ( !--v116 )
      break;
    v50 = x;
    x = v34;
    v34 = v50;
  }
  xc = v34;
  v51 = &v34[v20 - 4];
  v52 = &indices[511];
  do
  {
    v53 = *((_DWORD *)v51 + 1);
    v51 += 4;
    v52[1] = bswap32(v53);
    ++v52;
  }
  while ( &v129 != (int *)v52 );
  v115 = v20;
  for ( k = 0; k != 9; ++k )
  {
    v55 = (uint32_t *)tmpHash;
    v56 = 0;
    do
    {
      v56 += 2 << k;
      sort_pair(v55, 1 << k);
      v55 += 2 << k;
    }
    while ( v56 < 512 );
  }
  v57 = &indices[511];
  v58 = xc;
  do
  {
    v59 = v57[1];
    ++v57;
    v60 = n * (v59 % v107);
    generateHash(digest, v59 / v107, tmpHash_0, hashLen);
    v61 = v60 + 7;
    v8 = v60 < 0;
    v62 = v60 & ~(v60 >> 31);
    if ( v8 )
      v62 = v61;
    expandArray(&tmpHash_0[v62 >> 3], in_len, hash, v115, x_size_0, 0);
    v63 = bswap32(*v57);
    memcpy(v58, hash, v115);
    *(_DWORD *)&v58[v115] = v63;
    v64 = v58;
    v58 += v112;
    v65 = bin2hex(v64, 0x22u);
    free(v65);
  }
  while ( v57 != v52 );
  v66 = x;
  v67 = 4;
  x_size_0a = 512;
  v108 = compare_size + 3;
  v113 = compare_size + 30;
  while ( 1 )
  {
    v68 = 0;
    v69 = v115 + 2 * v67;
    v70 = 2 * (v69 - v67);
    v71 = &xc[v115];
    v72 = &xc[v115 + v69 - v67];
    digesta = v69;
    x_size_0a = ((x_size_0a - 1) >> 1) + 1;
    do
    {
      v73 = 2 * v68;
      if ( v115 )
      {
        v74 = &v72[-v115];
        v75 = tmp_hash;
        v76 = &v71[~v115];
        do
        {
          v78 = *v74++;
          v77 = v78;
          v79 = *++v76;
          *v75++ = v77 ^ v79;
        }
        while ( v72 != v74 );
      }
      ++v68;
      v80 = digesta * (v73 >> 1);
      v81 = &v66[v80];
      v82 = v80 + v115;
      memcpy(v81, tmp_hash, v115);
      v83 = v71;
      v71 += v70;
      memcpy(&v66[v82], v83, v67);
      memcpy(&v66[v82 + v67], v72, v67);
      v72 += v70;
    }
    while ( x_size_0a != v68 );
    v67 *= 2;
    compare_size = v108;
    v108 += 3;
    if ( v113 == v108 )
      break;
    v84 = xc;
    xc = v66;
    v66 = v84;
  }
  v85 = 0;
  v86 = &v66[v115];
  v87 = 0;
  v88 = 0;
  v89 = &v123;
  x = v66;
  do
  {
    if ( v88 <= 7 )
    {
      v90 = &v86[v85];
      v88 += 21;
      v91 = v86[v85 + 3];
      v85 += 4;
      v87 = v91 | (v87 << 21) | (v90[2] << 8) | ((v90[1] & 0x1F) << 16);
    }
    v88 -= 8;
    *++v89 = v87 >> v88;
  }
  while ( &v126 != v89 );
  v92 = bin2hex(tmpHash_0, 0x540u);
  free(v92);
  v93 = bin2hex(v66, digesta);
  free(v93);
  v94 = *((_DWORD *)v66 + 1);
  v95 = *((_DWORD *)v66 + 2);
  v96 = *((_DWORD *)v66 + 3);
  *(_DWORD *)vHash = *(_DWORD *)v66;
  *(_DWORD *)&vHash[4] = v94;
  *(_DWORD *)&vHash[8] = v95;
  *(_DWORD *)&vHash[12] = v96;
  v97 = *((_DWORD *)v66 + 5);
  v98 = *((_DWORD *)v66 + 6);
  v99 = *((_DWORD *)v66 + 7);
  *(_DWORD *)&vHash[16] = *((_DWORD *)v66 + 4);
  *(_DWORD *)&vHash[20] = v97;
  *(_DWORD *)&vHash[24] = v98;
  *(_WORD *)&vHash[28] = v99;
  v100 = vHash;
  while ( 1 )
  {
    v101 = *v100++;
    v15 = v101;
    if ( v101 )
      break;
    if ( &v120 == (char *)v100 )
      goto failed;
  }
  v15 = 3;
failed:
  free(x);
  free(xc);
  return v15;
}
