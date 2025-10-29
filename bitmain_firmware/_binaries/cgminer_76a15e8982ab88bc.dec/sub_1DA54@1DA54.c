int __fastcall sub_1DA54(int a1)
{
  int v1; // r11
  unsigned __int64 v2; // d17
  int v3; // r5
  int v4; // r4
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // lr
  int v10; // r4
  int v11; // r3
  int v12; // r12
  int v13; // r10
  size_t v14; // r0
  unsigned int v15; // r12
  unsigned __int8 *v16; // r3
  int v17; // r1
  size_t v18; // r4
  int v19; // r0
  unsigned int v20; // r2
  unsigned int v21; // r12
  int v22; // lr
  int v23; // r8
  int v24; // r7
  int v25; // r6
  unsigned int v26; // r0
  int v27; // r1
  unsigned int v28; // r12
  unsigned int v29; // r0
  int v30; // r1
  unsigned int v31; // r12
  unsigned int v32; // r0
  size_t v33; // r0
  _DWORD *v34; // r6
  int v35; // r1
  unsigned int v36; // r2
  unsigned int v37; // r3
  int v38; // r1
  unsigned int v39; // r2
  unsigned int v40; // r3
  int v41; // r1
  int v42; // r6
  char *v43; // r3
  char *v44; // r0
  int v45; // r7
  int v46; // r3
  int *v47; // r10
  int v48; // r6
  int v49; // r9
  int v50; // r2
  int v51; // r12
  int v52; // lr
  unsigned int v53; // r8
  int v54; // r3
  int v55; // r1
  int v56; // r0
  int *v57; // r0
  int v58; // r4
  bool v59; // zf
  int v60; // r3
  bool v61; // zf
  int v62; // r9
  int v63; // r3
  int v64; // r2
  int v65; // r0
  int v66; // r3
  _DWORD *v67; // r2
  int v68; // r3
  int v69; // r2
  int v70; // r3
  int v71; // r3
  _DWORD *v72; // r0
  _DWORD *v73; // r4
  void *v74; // r0
  int v75; // r3
  int v76; // r3
  int v77; // r1
  int v78; // r2
  int v79; // r3
  int v80; // r1
  int v81; // r2
  int v82; // r3
  int v83; // r11
  int v84; // r3
  unsigned int v85; // r10
  size_t v86; // r0
  unsigned int v87; // r9
  unsigned __int8 *v88; // r4
  int v89; // r8
  int v90; // r1
  int v91; // r12
  int v92; // r2
  int v93; // r0
  unsigned int v94; // r3
  unsigned int v95; // r10
  int v96; // r8
  unsigned int v97; // r2
  unsigned int v98; // r3
  int v99; // r1
  unsigned int v100; // r2
  unsigned int v101; // r3
  size_t v102; // r11
  int v103; // r0
  unsigned int v104; // r2
  unsigned int v105; // r3
  int v106; // r0
  unsigned int v107; // r2
  unsigned int v108; // r3
  unsigned int v109; // r0
  unsigned int v110; // r3
  _DWORD *v111; // r2
  int v112; // r3
  int v113; // r2
  int v114; // r2
  int v115; // r4
  size_t v116; // r6
  _DWORD *v117; // r0
  _DWORD *v118; // r8
  int v119; // r1
  unsigned int v120; // r6
  int v121; // r11
  int v122; // r5
  _DWORD *v123; // r4
  _DWORD *v124; // r10
  int v125; // r6
  char *v126; // r7
  unsigned int v127; // r3
  int v128; // r3
  _DWORD *v129; // r3
  unsigned int v130; // r1
  unsigned int v131; // r2
  bool v132; // cc
  int v133; // r2
  int v134; // r3
  signed int v135; // s16
  double v136; // r0
  double v137; // d8
  struct tm *v138; // r0
  int j; // r3
  int v140; // r1
  int v141; // r2
  int v142; // r3
  int v143; // r7
  int v144; // r1
  int v145; // r2
  int v146; // r3
  int v147; // r2
  char *v148; // r3
  unsigned __int64 v149; // r0
  int v150; // [sp+8h] [bp-107Ch]
  unsigned int i; // [sp+8h] [bp-107Ch]
  _DWORD *v152; // [sp+Ch] [bp-1078h]
  int v153; // [sp+10h] [bp-1074h]
  int v154; // [sp+14h] [bp-1070h]
  time_t timer; // [sp+18h] [bp-106Ch] BYREF
  int s2; // [sp+1Ch] [bp-1068h] BYREF
  int v157; // [sp+20h] [bp-1064h]
  int v158; // [sp+24h] [bp-1060h]
  int v159; // [sp+28h] [bp-105Ch]
  int v160; // [sp+2Ch] [bp-1058h]
  int v161; // [sp+30h] [bp-1054h]
  int v162; // [sp+34h] [bp-1050h]
  int v163; // [sp+38h] [bp-104Ch]
  char s[68]; // [sp+3Ch] [bp-1048h] BYREF
  char v165[4096]; // [sp+80h] [bp-1004h] BYREF

  v3 = a1;
  v152 = *(_DWORD **)(a1 + 1748);
  if ( *(_BYTE *)(a1 + 1770) )
    return 1;
  v6 = *(_DWORD *)(a1 + 28);
  v7 = *(_DWORD *)(a1 + 24);
  v8 = *(_DWORD *)(a1 + 20);
  v9 = *(_DWORD *)(a1 + 12);
  v10 = *(_DWORD *)(a1 + 16);
  s2 = *(_DWORD *)(a1 + 32);
  v11 = *(_DWORD *)(a1 + 4);
  v12 = *(_DWORD *)(a1 + 8);
  v161 = v9;
  v157 = v6;
  v162 = v12;
  v163 = v11;
  v158 = v7;
  v159 = v8;
  v160 = v10;
  sub_29630(s, (char *)&s2, 32);
  if ( pthread_rwlock_rdlock(&stru_740D0) )
    sub_B5E4("block_exists", 5347);
  v13 = dword_740F0;
  if ( dword_740F0 )
  {
    v14 = strlen(s);
    v15 = -1640531527;
    v16 = (unsigned __int8 *)s;
    v17 = -1640531527;
    v18 = v14;
    v132 = v14 > 0xB;
    v19 = -17973521;
    v20 = v18;
    if ( v132 )
    {
      do
      {
        v20 -= 12;
        v1 = v16[7];
        v21 = (v16[6] << 16) + (v16[5] << 8) + v16[4] + (v1 << 24) + v15;
        v22 = (v16[2] << 16) + (v16[1] << 8) + *v16;
        v23 = v16[3];
        v24 = v16[11];
        v25 = (v16[10] << 16) + (v16[9] << 8) + v16[8];
        v16 += 12;
        v26 = v25 + (v24 << 24) + v19;
        v27 = (v22 + (v23 << 24) - v21 - v26 + v17) ^ (v26 >> 13);
        v28 = (v21 - v26 - v27) ^ (v27 << 8);
        v29 = (v26 - v27 - v28) ^ (v28 >> 13);
        v30 = (v27 - v28 - v29) ^ (v29 >> 12);
        v31 = (v28 - v29 - v30) ^ (v30 << 16);
        v32 = (v29 - v30 - v31) ^ (v31 >> 5);
        v17 = (v30 - v31 - v32) ^ (v32 >> 3);
        v15 = (v31 - v32 - v17) ^ (v17 << 10);
        v19 = (v32 - v17 - v15) ^ (v15 >> 15);
      }
      while ( v20 > 0xB );
    }
    v33 = v19 + v18;
    switch ( v20 )
    {
      case 1u:
        goto LABEL_21;
      case 2u:
        goto LABEL_20;
      case 3u:
        goto LABEL_19;
      case 4u:
        goto LABEL_18;
      case 5u:
        goto LABEL_17;
      case 6u:
        goto LABEL_16;
      case 7u:
        goto LABEL_15;
      case 8u:
        goto LABEL_14;
      case 9u:
        goto LABEL_13;
      case 0xAu:
        goto LABEL_12;
      case 0xBu:
        v33 += v16[10] << 24;
LABEL_12:
        v33 += v16[9] << 16;
LABEL_13:
        v33 += v16[8] << 8;
LABEL_14:
        v15 += v16[7] << 24;
LABEL_15:
        v15 += v16[6] << 16;
LABEL_16:
        v15 += v16[5] << 8;
LABEL_17:
        v15 += v16[4];
LABEL_18:
        v17 += v16[3] << 24;
LABEL_19:
        v17 += v16[2] << 16;
LABEL_20:
        v17 += v16[1] << 8;
LABEL_21:
        v17 += *v16;
        break;
      default:
        break;
    }
    v34 = *(_DWORD **)(dword_740F0 + 68);
    v35 = (v17 - v15 - v33) ^ (v33 >> 13);
    v36 = (v15 - v33 - v35) ^ (v35 << 8);
    v37 = (v33 - v35 - v36) ^ (v36 >> 13);
    v38 = (v35 - v36 - v37) ^ (v37 >> 12);
    v39 = (v36 - v37 - v38) ^ (v38 << 16);
    v40 = (v37 - v38 - v39) ^ (v39 >> 5);
    v41 = (v38 - v39 - v40) ^ (v40 >> 3);
    v13 = *(_DWORD *)(*v34
                    + 12
                    * (((v40 - v41 - ((v39 - v40 - v41) ^ (v41 << 10)))
                      ^ (((v39 - v40 - v41) ^ (v41 << 10)) >> 15))
                     & (v34[1] - 1)));
    if ( !v13 )
      goto LABEL_24;
    do
    {
      v13 -= v34[5];
LABEL_24:
      if ( !v13 || v18 == *(_DWORD *)(v13 + 92) && !memcmp(*(const void **)(v13 + 88), s, v18) )
        break;
      v13 = *(_DWORD *)(v13 + 84);
    }
    while ( v13 );
  }
  if ( pthread_rwlock_unlock(&stru_740D0) )
    sub_B578("block_exists", 5349);
  off_72D18();
  if ( v13 )
  {
    if ( !memcmp(v152 + 142, &s2, 0x20u) )
    {
      v4 = 1;
    }
    else if ( !memcmp(&s2, dword_740FC, 0x20u) )
    {
      if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
      {
        snprintf(v165, 0x1000u, "Pool %d now up to date", *v152);
        sub_385C8(7, v165, 0);
      }
      v4 = 1;
      v77 = v157;
      v78 = v158;
      v79 = v159;
      v152[142] = s2;
      v152[143] = v77;
      v152[144] = v78;
      v152[145] = v79;
      v80 = v161;
      v81 = v162;
      v82 = v163;
      v152[146] = v160;
      v152[147] = v80;
      v152[148] = v81;
      v152[149] = v82;
    }
    else
    {
      v4 = (unsigned __int8)byte_75C49;
      if ( byte_75C49 )
      {
        if ( byte_77B70 || (v4 = (unsigned __int8)byte_75C48, byte_75C48) || dword_73504 > 6 )
        {
          v4 = 0;
          snprintf(v165, 0x1000u, "Stale data from pool %d", *v152);
          sub_385C8(7, v165, 0);
        }
      }
    }
    if ( *(_BYTE *)(v3 + 1768) )
    {
      v132 = (unsigned int)(dword_73D34 - 3) > 1;
      *(_DWORD *)(v3 + 1824) = ++dword_740CC;
      if ( !v132 || (v42 = *(_DWORD *)(v3 + 1748), v42 == sub_1D9A0()) )
      {
        if ( *(_BYTE *)(v3 + 1772) )
        {
          if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            snprintf(v165, 0x1000u, "Stratum from pool %d requested work restart", *v152);
            sub_385C8(7, v165, 0);
          }
        }
        else if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
        {
          v43 = "";
          if ( *(_BYTE *)(v3 + 1812) )
            v43 = "GBT ";
          snprintf(v165, 0x1000u, "%sLONGPOLL from pool %d requested work restart", v43, **(_DWORD **)(v3 + 1748));
          sub_385C8(7, v165, 0);
        }
        sub_17148();
      }
    }
    goto LABEL_41;
  }
  v44 = (char *)calloc(0x68u, 1u);
  v45 = (int)v44;
  if ( !v44 )
  {
    strcpy(v165, "test_work_current OOM");
    sub_385C8(3, v165, 1);
    sub_16BE0(1);
  }
  strcpy(v44, s);
  v46 = dword_78944++;
  *(_DWORD *)(v45 + 100) = v46;
  if ( pthread_rwlock_wrlock(&stru_740D0) )
    sub_B3C8("test_work_current", 5414);
  v47 = &dword_73A10;
  v48 = dword_740F0;
  if ( !dword_740F0 )
  {
    *(_DWORD *)(v45 + 76) = 0;
    *(_DWORD *)(v45 + 88) = v45;
    v153 = 0;
    *(_DWORD *)(v45 + 92) = strlen((const char *)v45);
    goto LABEL_105;
  }
  if ( *(_DWORD *)(*(_DWORD *)(dword_740F0 + 68) + 12) <= 6u )
  {
    *(_DWORD *)(v45 + 88) = v45;
    *(_DWORD *)(v45 + 76) = 0;
    v153 = 0;
    *(_DWORD *)(v45 + 92) = strlen((const char *)v45);
    goto LABEL_137;
  }
  v49 = dword_740F0 + 68;
  v50 = 1;
  while ( 2 )
  {
    v51 = v49;
    v49 = 0;
    v52 = 0;
    v53 = 0;
    do
    {
      ++v53;
      if ( v50 )
      {
        v54 = *(_DWORD *)(v51 + 8);
        if ( v54 )
        {
          v56 = *(_DWORD *)(*(_DWORD *)(v48 + 68) + 20);
          v55 = 1;
          for ( v54 += v56; v54; v54 += v56 )
          {
            if ( v55 == v50 )
              break;
            v54 = *(_DWORD *)(v54 + 8);
            ++v55;
            if ( !v54 )
              break;
          }
        }
        else
        {
          v55 = 1;
        }
      }
      else
      {
        v54 = v51;
        v55 = 0;
      }
      v57 = (int *)v51;
      v58 = v50;
      v51 = v54;
      while ( v55 )
      {
LABEL_69:
        v59 = v58 == 0;
        if ( v58 )
          v59 = v51 == 0;
        if ( v59 )
        {
          if ( !v57 )
            goto LABEL_128;
          v47 = (int *)v57[2];
          if ( v47 )
            v47 = (int *)((char *)v47 + *(_DWORD *)(*(_DWORD *)(v48 + 68) + 20));
LABEL_76:
          --v55;
          if ( !v52 )
            goto LABEL_125;
LABEL_77:
          if ( v57 )
          {
            *(_DWORD *)(v52 + 8) = (char *)v57 - *(_DWORD *)(*(_DWORD *)(v48 + 68) + 20);
            v60 = v52 - *(_DWORD *)(*(_DWORD *)(v48 + 68) + 20);
            v52 = (int)v57;
            v57 = v47;
            goto LABEL_79;
          }
          *(_DWORD *)(v52 + 8) = 0;
          v52 = 0;
          v57 = v47;
        }
        else
        {
          v76 = *(_DWORD *)(*(_DWORD *)(v48 + 68) + 20);
          v1 = *(_DWORD *)(v51 - v76 + 100);
          v47 = (int *)(*(int *)((char *)v57 - v76 + 100) - v1);
          if ( (int)v47 > 0 )
          {
            v1 = *(_DWORD *)(v51 + 8);
            if ( v1 )
              v1 += v76;
            goto LABEL_113;
          }
          if ( !v57 )
          {
LABEL_128:
            v47 = v57;
            goto LABEL_76;
          }
          v47 = (int *)v57[2];
          --v55;
          if ( v47 )
            v47 = (int *)((char *)v47 + v76);
          if ( v52 )
            goto LABEL_77;
LABEL_125:
          if ( v57 )
          {
            v52 = (int)v57;
            v60 = 0;
            v57 = v47;
            v49 = v52;
            goto LABEL_79;
          }
          v49 = 0;
          v57 = v47;
          v52 = 0;
        }
      }
      while ( 1 )
      {
        v61 = v51 == 0;
        if ( v51 )
          v61 = v58 == 0;
        if ( v61 )
          break;
        v75 = *(_DWORD *)(v51 + 8);
        if ( v75 )
          v47 = *(int **)(v48 + 68);
        else
          v1 = v55;
        if ( v75 )
        {
          v47 = (int *)v47[5];
          v1 = (int)v47 + v75;
        }
LABEL_113:
        --v58;
        if ( v52 )
        {
          v47 = v57;
          v57 = (int *)v51;
          v51 = v1;
          goto LABEL_77;
        }
        v52 = v51;
        v60 = 0;
        v51 = v1;
        v49 = v52;
LABEL_79:
        *(_DWORD *)(v52 + 4) = v60;
        if ( v55 )
          goto LABEL_69;
      }
    }
    while ( v51 );
    if ( v52 )
      *(_DWORD *)(v52 + 8) = 0;
    if ( v53 > 1 )
    {
      v50 *= 2;
      if ( !v49 )
      {
        v52 = 0;
        break;
      }
      continue;
    }
    break;
  }
  *(_DWORD *)(*(_DWORD *)(v48 + 68) + 16) = v52;
  v62 = v49 - *(_DWORD *)(*(_DWORD *)(v48 + 68) + 20);
  dword_740F0 = v62;
  v63 = *(_DWORD *)(v62 + 72);
  v153 = *(_DWORD *)(v62 + 100);
  if ( v63 || *(_DWORD *)(v62 + 76) )
  {
    v64 = *(_DWORD *)(v62 + 68);
    v65 = *(_DWORD *)(v64 + 20);
    if ( v62 == *(_DWORD *)(v64 + 16) - v65 )
    {
      *(_DWORD *)(v64 + 16) = v63 + v65;
      v63 = *(_DWORD *)(v62 + 72);
    }
    if ( v63 )
    {
      v48 = v62;
      *(_DWORD *)(v63 + *(_DWORD *)(*(_DWORD *)(v62 + 68) + 20) + 8) = *(_DWORD *)(v62 + 76);
      v66 = *(_DWORD *)(v62 + 76);
    }
    else
    {
      v66 = *(_DWORD *)(v62 + 76);
      v48 = v66;
      dword_740F0 = v66;
    }
    if ( v66 )
      *(_DWORD *)(v66 + *(_DWORD *)(*(_DWORD *)(v48 + 68) + 20) + 4) = *(_DWORD *)(v62 + 72);
    v67 = *(_DWORD **)(v48 + 68);
    v68 = 12 * ((v67[1] - 1) & *(_DWORD *)(v62 + 96));
    --*(_DWORD *)(*v67 + v68 + 4);
    v69 = **(_DWORD **)(v48 + 68);
    if ( *(_DWORD *)(v69 + v68) == v62 + 68 )
      *(_DWORD *)(v69 + v68) = *(_DWORD *)(v62 + 84);
    v70 = *(_DWORD *)(v62 + 80);
    if ( v70 )
      *(_DWORD *)(v70 + 16) = *(_DWORD *)(v62 + 84);
    v71 = *(_DWORD *)(v62 + 84);
    if ( v71 )
      *(_DWORD *)(v71 + 12) = *(_DWORD *)(v62 + 80);
    --*(_DWORD *)(*(_DWORD *)(v48 + 68) + 12);
  }
  else
  {
    v48 = 0;
    free(**(void ***)(v62 + 68));
    free(*(void **)(v62 + 68));
    dword_740F0 = 0;
  }
  free((void *)v62);
  *(_DWORD *)(v45 + 88) = v45;
  *(_DWORD *)(v45 + 76) = 0;
  *(_DWORD *)(v45 + 92) = strlen((const char *)v45);
  if ( !v48 )
  {
LABEL_105:
    *(_DWORD *)(v45 + 72) = 0;
    dword_740F0 = v45;
    v72 = malloc(0x2Cu);
    v73 = v72;
    *(_DWORD *)(v45 + 68) = v72;
    if ( v72 )
    {
      v150 = v45 + 68;
      *v72 = 0;
      v72[3] = 0;
      v72[4] = 0;
      v72[5] = 0;
      v72[6] = 0;
      v72[7] = 0;
      v72[8] = 0;
      v72[9] = 0;
      v72[10] = 0;
      v72[1] = 32;
      v72[4] = v45 + 68;
      v72[2] = 5;
      v72[5] = 68;
      v74 = malloc(0x180u);
      *v73 = v74;
      if ( v74 )
      {
        memset(v74, 0, 0x180u);
        v48 = v45;
        v73[10] = -1609490463;
        goto LABEL_138;
      }
    }
LABEL_251:
    exit(-1);
  }
LABEL_137:
  v150 = v45 + 68;
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v48 + 68) + 16) + 8) = v45;
  *(_DWORD *)(v45 + 72) = *(_DWORD *)(*(_DWORD *)(v48 + 68) + 16) - *(_DWORD *)(*(_DWORD *)(v48 + 68) + 20);
  *(_DWORD *)(*(_DWORD *)(v48 + 68) + 16) = v45 + 68;
  v73 = *(_DWORD **)(v48 + 68);
LABEL_138:
  v83 = -17973521;
  ++v73[3];
  v84 = *(_DWORD *)(v48 + 68);
  v85 = -1640531527;
  *(_DWORD *)(v45 + 96) = -17973521;
  *(_DWORD *)(v45 + 68) = v84;
  v86 = strlen((const char *)v45);
  v87 = v86;
  if ( v86 <= 0xB )
  {
    v89 = -1640531527;
    v88 = (unsigned __int8 *)v45;
  }
  else
  {
    v88 = (unsigned __int8 *)v45;
    v89 = -1640531527;
    do
    {
      v87 -= 12;
      v90 = (v88[2] << 16) + (v88[1] << 8) + *v88;
      v91 = v88[3];
      v92 = (v88[6] << 16) + (v88[5] << 8) + v88[4];
      v93 = v88[7];
      v94 = (v88[10] << 16) + (v88[9] << 8) + v88[8] + (v88[11] << 24) + v83;
      v88 += 12;
      v95 = v92 + (v93 << 24) + v85;
      v96 = (v90 + (v91 << 24) - v94 - v95 + v89) ^ (v94 >> 13);
      v97 = (v95 - v94 - v96) ^ (v96 << 8);
      v98 = (v94 - v96 - v97) ^ (v97 >> 13);
      v99 = (v96 - v97 - v98) ^ (v98 >> 12);
      v100 = (v97 - v98 - v99) ^ (v99 << 16);
      v101 = (v98 - v99 - v100) ^ (v100 >> 5);
      v89 = (v99 - v100 - v101) ^ (v101 >> 3);
      v85 = (v100 - v101 - v89) ^ (v89 << 10);
      v83 = (v101 - v89 - v85) ^ (v85 >> 15);
      *(_DWORD *)(v45 + 96) = v83;
    }
    while ( v87 > 0xB );
    v86 = strlen((const char *)v45);
  }
  v102 = v86 + v83;
  *(_DWORD *)(v45 + 96) = v102;
  switch ( v87 )
  {
    case 1u:
      goto LABEL_153;
    case 2u:
      goto LABEL_152;
    case 3u:
      goto LABEL_151;
    case 4u:
      goto LABEL_150;
    case 5u:
      goto LABEL_149;
    case 6u:
      goto LABEL_148;
    case 7u:
      goto LABEL_147;
    case 8u:
      goto LABEL_146;
    case 9u:
      goto LABEL_145;
    case 0xAu:
      goto LABEL_144;
    case 0xBu:
      v102 += v88[10] << 24;
      *(_DWORD *)(v45 + 96) = v102;
LABEL_144:
      v102 += v88[9] << 16;
      *(_DWORD *)(v45 + 96) = v102;
LABEL_145:
      v102 += v88[8] << 8;
      *(_DWORD *)(v45 + 96) = v102;
LABEL_146:
      v85 += v88[7] << 24;
LABEL_147:
      v85 += v88[6] << 16;
LABEL_148:
      v85 += v88[5] << 8;
LABEL_149:
      v85 += v88[4];
LABEL_150:
      v89 += v88[3] << 24;
LABEL_151:
      v89 += v88[2] << 16;
LABEL_152:
      v89 += v88[1] << 8;
LABEL_153:
      v89 += *v88;
      break;
    default:
      break;
  }
  v103 = (v89 - v85 - v102) ^ (v102 >> 13);
  v104 = (v85 - v102 - v103) ^ (v103 << 8);
  v105 = (v102 - v103 - v104) ^ (v104 >> 13);
  v106 = (v103 - v104 - v105) ^ (v105 >> 12);
  v107 = (v104 - v105 - v106) ^ (v106 << 16);
  v108 = (v105 - v106 - v107) ^ (v107 >> 5);
  v109 = v106 - v107 - v108;
  v110 = (v108 - (v109 ^ (v108 >> 3)) - ((v107 - v108 - (v109 ^ (v108 >> 3))) ^ ((v109 ^ (v108 >> 3)) << 10)))
       ^ (((v107 - v108 - (v109 ^ (v108 >> 3))) ^ ((v109 ^ (v108 >> 3)) << 10)) >> 15);
  *(_DWORD *)(v45 + 96) = v110;
  v111 = *(_DWORD **)(v48 + 68);
  v112 = 12 * (v110 & (v111[1] - 1));
  ++*(_DWORD *)(*v111 + v112 + 4);
  v113 = *(_DWORD *)(**(_DWORD **)(v48 + 68) + v112);
  *(_DWORD *)(v45 + 80) = 0;
  *(_DWORD *)(v45 + 84) = v113;
  v114 = **(_DWORD **)(v48 + 68) + v112;
  if ( *(_DWORD *)v114 )
  {
    *(_DWORD *)(*(_DWORD *)v114 + 12) = v150;
    v114 = **(_DWORD **)(v48 + 68) + v112;
  }
  *(_DWORD *)v114 = v150;
  if ( *(_DWORD *)(**(_DWORD **)(v48 + 68) + v112 + 4) >= (unsigned int)(10
                                                                       * (*(_DWORD *)(**(_DWORD **)(v48 + 68) + v112 + 8)
                                                                        + 1)) )
  {
    v115 = *(_DWORD *)(v45 + 68);
    if ( *(_DWORD *)(v115 + 36) != 1 )
    {
      v116 = 24 * *(_DWORD *)(v115 + 4);
      v117 = malloc(v116);
      v118 = v117;
      if ( !v117 )
        goto LABEL_251;
      memset(v117, 0, v116);
      *(_DWORD *)(v115 + 24) = (((2 * *(_DWORD *)(v115 + 4) - 1) & *(_DWORD *)(v115 + 12)) != 0)
                             + (*(_DWORD *)(v115 + 12) >> (*(_BYTE *)(v115 + 8) + 1));
      *(_DWORD *)(*(_DWORD *)(v45 + 68) + 28) = 0;
      v119 = *(_DWORD *)(v45 + 68);
      v120 = *(_DWORD *)(v119 + 4);
      if ( v120 )
      {
        v154 = v3;
        v121 = 0;
        v122 = v45;
        for ( i = 0; i < v120; ++i )
        {
          v123 = *(_DWORD **)(*(_DWORD *)v119 + v121);
          if ( v123 )
          {
            while ( 1 )
            {
              v124 = (_DWORD *)v123[4];
              v125 = 3 * ((2 * v120 - 1) & v123[7]);
              v126 = (char *)&v118[v125];
              v127 = *((_DWORD *)v126 + 1) + 1;
              *((_DWORD *)v126 + 1) = v127;
              if ( v127 > *(_DWORD *)(v119 + 24) )
              {
                ++*(_DWORD *)(v119 + 28);
                *((_DWORD *)v126 + 2) = *((_DWORD *)v126 + 1) / *(_DWORD *)(*(_DWORD *)(v122 + 68) + 24);
              }
              v123[3] = 0;
              v123[4] = v118[v125];
              v128 = v118[v125];
              if ( v128 )
                *(_DWORD *)(v128 + 12) = v123;
              v118[v125] = v123;
              v119 = *(_DWORD *)(v122 + 68);
              if ( !v124 )
                break;
              v120 = *(_DWORD *)(v119 + 4);
              v123 = v124;
            }
            v120 = *(_DWORD *)(v119 + 4);
          }
          v121 += 12;
        }
        v45 = v122;
        v3 = v154;
      }
      free(*(void **)v119);
      *(_DWORD *)(*(_DWORD *)(v45 + 68) + 4) *= 2;
      ++*(_DWORD *)(*(_DWORD *)(v45 + 68) + 8);
      **(_DWORD **)(v45 + 68) = v118;
      v129 = *(_DWORD **)(v45 + 68);
      v130 = v129[3];
      v131 = v129[7];
      v132 = v131 > v130 >> 1;
      if ( v131 <= v130 >> 1 )
        v133 = 0;
      else
        v133 = v129[8];
      if ( v132 )
        ++v133;
      v129[8] = v133;
      v134 = *(_DWORD *)(v45 + 68);
      if ( *(_DWORD *)(v134 + 32) > 1u )
        *(_DWORD *)(v134 + 36) = 1;
    }
  }
  LODWORD(v2) = 8 * (29 - *(unsigned __int8 *)(v3 + 72));
  v135 = bswap32(*(_DWORD *)(v3 + 72)) & 0xFFFFFF;
  LODWORD(v136) = sub_59F08(vshld_u64(0xFFFFu, v2));
  v137 = v136 / (double)v135;
  if ( v137 != dbl_72C20 )
  {
    LODWORD(v149) = sub_5A000(v137);
    sub_114B8(v149, byte_740F4, 8u, 0);
    dbl_72C20 = v137;
    if ( byte_75C49 )
    {
      if ( byte_77B70 || byte_75C48 || dword_73504 > 6 )
      {
        snprintf(v165, 0x1000u, "Network diff set to %s", byte_740F4);
        sub_385C8(7, v165, 0);
      }
    }
  }
  if ( pthread_rwlock_unlock(&stru_740D0) )
    sub_B578("test_work_current", 5430);
  off_72D18();
  if ( v153 && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(v165, 0x1000u, "Deleted block %d from database", v153);
    sub_385C8(7, v165, 0);
  }
  if ( pthread_mutex_lock(&stru_78800) )
    sub_B35C("set_curblock", 5324);
  if ( pthread_rwlock_wrlock(&stru_78818) )
    sub_B3C8("set_curblock", 5324);
  sub_2A7A4((struct timeval *)&dword_77E98);
  strcpy(dest, s);
  timer = dword_77E98;
  dword_740FC[0] = s2;
  dword_740FC[1] = v157;
  dword_740FC[2] = v158;
  dword_740FC[3] = v159;
  unk_7410C = v160;
  unk_74110 = v161;
  unk_74114 = v162;
  unk_74118 = v163;
  v138 = localtime(&timer);
  snprintf(byte_7411C, 0x20u, "[%02d:%02d:%02d]", v138->tm_hour, v138->tm_min, v138->tm_sec);
  if ( pthread_rwlock_unlock(&stru_78818) )
    sub_B578("set_curblock", 5329);
  if ( pthread_mutex_unlock(&stru_78800) )
    sub_B50C("set_curblock", 5329);
  off_72D18();
  for ( j = 0; j != 57; ++j )
  {
    if ( dest[j] != 48 )
      break;
  }
  strncpy(byte_7413C, &dest[j], 8u);
  byte_74144 = 0;
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(v165, 0x1000u, "New block: %s... diff %s", dest, byte_740F4);
    sub_385C8(7, v165, 0);
  }
  v140 = v157;
  v141 = v158;
  v142 = v159;
  v143 = dword_78944;
  v152[142] = s2;
  v152[143] = v140;
  v152[144] = v141;
  v152[145] = v142;
  v144 = v161;
  v145 = v162;
  v146 = v163;
  v152[146] = v160;
  v152[147] = v144;
  v152[148] = v145;
  v152[149] = v146;
  if ( v143 == 1 )
  {
    v4 = 0;
LABEL_41:
    *(_BYTE *)(v3 + 1768) = 0;
    return v4;
  }
  v147 = *(unsigned __int8 *)(v3 + 1768);
  *(_DWORD *)(v3 + 1824) = ++dword_740CC;
  if ( v147 )
  {
    if ( *(_BYTE *)(v3 + 1772) )
    {
      if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
      {
        snprintf(v165, 0x1000u, "Stratum from pool %d detected new block", *v152);
        sub_385C8(7, v165, 0);
      }
    }
    else if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      v148 = "";
      if ( *(_BYTE *)(v3 + 1812) )
        v148 = "GBT ";
      snprintf(v165, 0x1000u, "%sLONGPOLL from pool %d detected new block", v148, **(_DWORD **)(v3 + 1748));
      sub_385C8(7, v165, 0);
    }
  }
  else if ( byte_78AA1 )
  {
    if ( !*((_BYTE *)v152 + 924) && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      strcpy(v165, "New block detected on network before pool notification");
      sub_385C8(7, v165, 0);
    }
  }
  else if ( !*((_BYTE *)v152 + 924) && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    strcpy(v165, "New block detected on network");
    sub_385C8(7, v165, 0);
  }
  sub_17148();
  v4 = 1;
  *(_BYTE *)(v3 + 1768) = 0;
  return v4;
}
