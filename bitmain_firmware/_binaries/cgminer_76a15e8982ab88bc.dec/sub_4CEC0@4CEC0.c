int __fastcall sub_4CEC0(int *a1, unsigned int a2)
{
  int v2; // r5
  int v3; // r9
  int v5; // r6
  int v6; // r0
  int v7; // r1
  char *v8; // r0
  _DWORD *v9; // r2
  int v10; // r0
  int v11; // r4
  int v12; // r3
  int v13; // r5
  int v14; // r11
  int v15; // r0
  int v16; // r1
  char *v17; // r6
  int v18; // r9
  int v19; // r0
  int i; // r3
  char *j; // r3
  int v22; // r4
  _BYTE *v24; // r12
  int v25; // r3
  int v26; // t1
  size_t v27; // r6
  int v28; // r12
  size_t v29; // r4
  unsigned int v30; // r5
  int v31; // r9
  int v32; // r3
  int v33; // r12
  int v34; // r9
  char *v35; // r0
  int v36; // r9
  char *v37; // r1
  bool v38; // zf
  char *v39; // r3
  int v40; // r3
  int k; // r6
  int v42; // r9
  unsigned int *v43; // r0
  char *v44; // r4
  int *v45; // r6
  int v46; // r9
  int v47; // r0
  unsigned int v48; // t1
  _BYTE *v49; // r0
  size_t v50; // r6
  unsigned int v51; // r5
  int v52; // r12
  int v53; // r9
  size_t v54; // r4
  int v55; // r12
  int m; // r3
  int v57; // r9
  char *v58; // r0
  int v59; // r9
  char *v60; // r1
  char *v61; // r3
  int v62; // r2
  char *v63; // r0
  unsigned int v64; // r1
  unsigned int v65; // r3
  char *v66; // lr
  _BYTE *v67; // r0
  _WORD *v68; // r5
  _BYTE *v69; // r0
  int v70; // r1
  int v71; // r2
  int v72; // r3
  int v73; // r1
  int v74; // r2
  int v75; // r3
  int v76; // t1
  unsigned int v77; // [sp+0h] [bp-78h]
  int v78; // [sp+Ch] [bp-6Ch]
  int v79; // [sp+Ch] [bp-6Ch]
  int v80; // [sp+Ch] [bp-6Ch]
  unsigned int v81; // [sp+10h] [bp-68h]
  unsigned int v82; // [sp+10h] [bp-68h]
  int v83; // [sp+14h] [bp-64h]
  unsigned int nmemb; // [sp+18h] [bp-60h]
  int v85; // [sp+1Ch] [bp-5Ch]
  size_t v86; // [sp+1Ch] [bp-5Ch]
  int v87; // [sp+1Ch] [bp-5Ch]
  int v88; // [sp+20h] [bp-58h]
  int v89; // [sp+24h] [bp-54h]
  int v90; // [sp+28h] [bp-50h]
  int v91; // [sp+28h] [bp-50h]
  char *ptr; // [sp+2Ch] [bp-4Ch]
  void *v93; // [sp+30h] [bp-48h]
  char *v94; // [sp+34h] [bp-44h]
  int v95; // [sp+44h] [bp-34h]
  int v96; // [sp+48h] [bp-30h]
  int v97; // [sp+4Ch] [bp-2Ch]
  unsigned int v98; // [sp+54h] [bp-24h] BYREF
  int v99; // [sp+58h] [bp-20h] BYREF
  int v100; // [sp+5Ch] [bp-1Ch]
  int v101; // [sp+60h] [bp-18h]
  int v102; // [sp+64h] [bp-14h]
  int v103; // [sp+68h] [bp-10h]
  int v104; // [sp+6Ch] [bp-Ch]
  int v105; // [sp+70h] [bp-8h]
  __int16 v106; // [sp+74h] [bp-4h] BYREF
  char v107; // [sp+77h] [bp-1h] BYREF
  _BYTE v108[28]; // [sp+78h] [bp+0h] BYREF
  __int16 v109; // [sp+94h] [bp+1Ch]
  _BYTE src[31]; // [sp+98h] [bp+20h] BYREF
  char v111; // [sp+B7h] [bp+3Fh] BYREF
  _BYTE v112[1336]; // [sp+B8h] [bp+40h] BYREF
  char v113; // [sp+5F7h] [bp+57Fh] BYREF
  _BYTE v114[2040]; // [sp+5F8h] [bp+580h] BYREF
  _BYTE v115[1992]; // [sp+DF8h] [bp+D80h] BYREF
  int v116; // [sp+15F8h] [bp+1580h] BYREF

  v2 = a1[1];
  v3 = *a1;
  v5 = v2 + 1;
  v93 = (void *)a1[2];
  v6 = sub_59AC8(*a1, v2 + 1);
  v77 = v6 + 1;
  v81 = v6;
  dword_739D0 = 3;
  v7 = ((v6 + 1) << v2) + 7;
  if ( (v6 + 1) << v2 >= 0 )
    v7 = v77 << v2;
  sub_4CCBC(a2, v7 >> 3, (int)v114, 2048, v77, 1u);
  v99 = 0;
  v100 = 0;
  v101 = 0;
  v102 = 0;
  v103 = 0;
  v104 = 0;
  v105 = 0;
  v106 = 0;
  ptr = (char *)malloc(0x4400u);
  v8 = (char *)malloc(0x4400u);
  v9 = v114;
  memset(v108, 0, sizeof(v108));
  v109 = 0;
  v94 = v8;
  v10 = 0;
  while ( ++v10 != 512 )
  {
    if ( *v9 == v9[1] )
    {
LABEL_27:
      v22 = 1;
      goto LABEL_21;
    }
    v24 = &v114[4 * v10];
    v25 = v10;
    while ( ++v25 != 512 )
    {
      v26 = *((_DWORD *)v24 + 1);
      v24 += 4;
      if ( *v9 == v26 )
        goto LABEL_27;
    }
    ++v9;
  }
  v11 = 0;
  v12 = v81 + 7;
  if ( (int)(v81 + 7) < 0 )
    v12 = v81 + 14;
  v13 = 0;
  v14 = (v12 >> 3) * v5;
  v15 = sub_59AC8(512, v3);
  v16 = v3 + 7;
  v17 = ptr;
  if ( v3 >= 0 )
    v16 = v3;
  v85 = v3;
  v90 = v14 + 4;
  v89 = v16 >> 3;
  v83 = v15;
  v88 = v3 * v15 / 8;
  do
  {
    v18 = 4 * v13;
    v78 = bswap32(*(_DWORD *)&v114[4 * v13]);
    v19 = sub_59AC8(v78, v83);
    sub_4CC58(v93, v19, v115, v88);
    sub_4CCBC((unsigned int)&v115[v85 * (v78 % v83) / 8], v89, (int)v112, v14, v81, 0);
    if ( v14 )
    {
      for ( i = 0; ; LOBYTE(v11) = *((_BYTE *)&v99 + i) )
      {
        *((_BYTE *)&v99 + i) = v11 ^ v112[i];
        if ( v14 == ++i )
          break;
      }
      v11 = (unsigned __int8)v99;
    }
    ++v13;
    memcpy(v17, v112, v14);
    *(_DWORD *)&v17[v14] = *(_DWORD *)&v114[v18];
    v17 += v90;
  }
  while ( v13 != 512 );
  for ( j = (char *)&v99 + 1; ; v11 = (unsigned __int8)*(j - 1) )
  {
    ++j;
    if ( v11 )
    {
      v22 = 2;
      goto LABEL_21;
    }
    if ( j == &v107 )
      break;
  }
  v27 = 4;
  v99 = 0;
  v95 = 9;
  v100 = 0;
  nmemb = 512;
  v101 = 0;
  v102 = 0;
  v103 = 0;
  v104 = 0;
  v105 = 0;
  v106 = 0;
  v97 = v85;
  while ( 1 )
  {
    v86 = v27 + v14;
    qsort(ptr, nmemb, v27 + v14, compar);
    if ( nmemb )
    {
      v96 = 2 * v27;
      v28 = 0;
      v29 = v27 + v14;
      v30 = 0;
      v31 = 0;
      do
      {
        if ( v14 )
        {
          v32 = 0;
          v33 = v86 * v28;
          do
          {
            v108[v32] = ptr[v29 + v32] ^ ptr[v33 + v32];
            ++v32;
          }
          while ( v14 != v32 );
        }
        else
        {
          v33 = v86 * v28;
        }
        v79 = v33;
        v34 = (2 * v27 + v14) * (v31 >> 1);
        ++v30;
        v35 = &v94[v34];
        v36 = v34 + v14;
        memcpy(v35, v108, v14);
        memcpy(&v94[v36], &ptr[v79 + v14], v27);
        v37 = &ptr[v14 + v29];
        v29 += 2 * v86;
        memcpy(&v94[v36 + v27], v37, v27);
        v31 = 2 * v30;
        v28 = 2 * v30;
      }
      while ( 2 * v30 < nmemb );
    }
    else
    {
      v30 = 0;
      v96 = 2 * v27;
    }
    v38 = v95-- == 1;
    dword_739D0 += 3;
    if ( v38 )
      break;
    v39 = ptr;
    nmemb = v30;
    v27 = v96;
    ptr = v94;
    v94 = v39;
  }
  v40 = v95;
  do
  {
    *(_DWORD *)&v115[v40] = bswap32(*(_DWORD *)&v94[v14 + v40]);
    v40 += 4;
  }
  while ( v40 != 2048 );
  for ( k = 0; k != 9; ++k )
  {
    v42 = 0;
    do
    {
      v43 = (unsigned int *)&v115[4 * v42];
      v42 += 2 << k;
      sub_4CE5C(v43, 1 << k);
    }
    while ( v42 <= 511 );
  }
  v44 = v94;
  v45 = (int *)v115;
  do
  {
    v46 = *v45;
    v47 = sub_59AC8(*v45, v83);
    sub_4CC58(v93, v47, v112, v88);
    sub_4CCBC((unsigned int)&v112[v97 * (v46 % v83) / 8], v89, (int)src, v14, v81, 0);
    v48 = *v45++;
    v98 = bswap32(v48);
    memcpy(v44, src, v14);
    *(_DWORD *)&v44[v14] = v98;
    v49 = sub_29688((int)v44, 34);
    v44 += v90;
    free(v49);
  }
  while ( v45 != &v116 );
  v50 = 4;
  v91 = 9;
  v82 = 512;
  while ( 1 )
  {
    if ( v82 )
    {
      v52 = 0;
      v87 = 2 * v50;
      v51 = 0;
      v53 = 0;
      v54 = v50 + v14;
      do
      {
        v55 = (v50 + v14) * v52;
        if ( v14 )
        {
          for ( m = 0; m != v14; ++m )
            v108[m] = v94[v54 + m] ^ v94[v55 + m];
        }
        v80 = v55;
        v57 = (2 * v50 + v14) * (v53 >> 1);
        ++v51;
        v58 = &ptr[v57];
        v59 = v57 + v14;
        memcpy(v58, v108, v14);
        memcpy(&ptr[v59], &v94[v80 + v14], v50);
        v60 = &v94[v14 + v54];
        v54 += 2 * (v50 + v14);
        memcpy(&ptr[v59 + v50], v60, v50);
        v53 = 2 * v51;
        v52 = 2 * v51;
      }
      while ( 2 * v51 < v82 );
    }
    else
    {
      v87 = 2 * v50;
      v51 = 0;
    }
    v38 = v91-- == 1;
    dword_739D0 += 3;
    if ( v38 )
      break;
    v61 = v94;
    v82 = v51;
    v50 = v87;
    v94 = ptr;
    ptr = v61;
  }
  v62 = v91;
  v63 = &v111;
  v64 = v91;
  v65 = v91;
  do
  {
    v66 = &ptr[v14 + v62];
    if ( v65 <= 7 )
    {
      v62 += 4;
      v65 += 21;
      v64 = ((v66[1] & 0x1F) << 16) | ((unsigned __int8)v66[2] << 8) | (v64 << 21) | (unsigned __int8)v66[3];
    }
    v65 -= 8;
    *++v63 = v64 >> v65;
  }
  while ( v63 != &v113 );
  v67 = sub_29688((int)v112, 1344);
  v68 = (_WORD *)((char *)&v98 + 3);
  free(v67);
  v69 = sub_29688((int)ptr, v87 + v14);
  free(v69);
  v70 = *((_DWORD *)ptr + 1);
  v71 = *((_DWORD *)ptr + 2);
  v72 = *((_DWORD *)ptr + 3);
  v99 = *(_DWORD *)ptr;
  v100 = v70;
  v101 = v71;
  v102 = v72;
  v73 = *((_DWORD *)ptr + 5);
  v74 = *((_DWORD *)ptr + 6);
  v75 = *((_DWORD *)ptr + 7);
  v103 = *((_DWORD *)ptr + 4);
  v104 = v73;
  v105 = v74;
  v106 = v75;
  while ( 1 )
  {
    v76 = *((unsigned __int8 *)v68 + 1);
    v68 = (_WORD *)((char *)v68 + 1);
    v22 = v76;
    if ( v76 )
      break;
    if ( v68 == (__int16 *)((char *)&v106 + 1) )
      goto LABEL_21;
  }
  v22 = 3;
LABEL_21:
  free(ptr);
  free(v94);
  return v22;
}
