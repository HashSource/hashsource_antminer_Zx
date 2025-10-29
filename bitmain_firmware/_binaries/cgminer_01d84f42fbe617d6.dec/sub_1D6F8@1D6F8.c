int __fastcall sub_1D6F8(int a1)
{
  int v1; // r11
  unsigned __int64 v2; // d17
  int v3; // r5
  int v4; // r4
  int v6; // r8
  int v7; // lr
  int v8; // r12
  int v9; // r7
  int v10; // r6
  int v11; // r4
  int v12; // r3
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
  const char *v43; // r3
  char *v44; // r0
  int v45; // r7
  int v46; // r3
  int v47; // r6
  int v48; // r9
  int v49; // r2
  int v50; // r12
  int v51; // lr
  unsigned int v52; // r8
  int v53; // r3
  int v54; // r1
  int v55; // r0
  int v56; // r0
  int v57; // r4
  bool v58; // zf
  int v59; // r3
  bool v60; // zf
  int v61; // r9
  int v62; // r3
  int v63; // r2
  int v64; // r0
  int v65; // r3
  _DWORD *v66; // r2
  int v67; // r3
  int v68; // r2
  int v69; // r3
  int v70; // r3
  _DWORD *v71; // r0
  _DWORD *v72; // r4
  void *v73; // r0
  int v74; // r3
  int v75; // r3
  int v76; // r1
  int v77; // r2
  int v78; // r3
  int v79; // r1
  int v80; // r2
  int v81; // r3
  int v82; // r11
  int v83; // r3
  unsigned int v84; // r10
  size_t v85; // r0
  unsigned int v86; // r9
  unsigned __int8 *v87; // r4
  int v88; // r8
  int v89; // r1
  int v90; // r12
  int v91; // r2
  int v92; // r0
  unsigned int v93; // r3
  unsigned int v94; // r10
  int v95; // r8
  unsigned int v96; // r2
  unsigned int v97; // r3
  int v98; // r1
  unsigned int v99; // r2
  unsigned int v100; // r3
  size_t v101; // r11
  int v102; // r0
  unsigned int v103; // r2
  unsigned int v104; // r3
  int v105; // r0
  unsigned int v106; // r2
  unsigned int v107; // r3
  unsigned int v108; // r0
  unsigned int v109; // r3
  _DWORD *v110; // r2
  int v111; // r3
  int v112; // r2
  int v113; // r2
  int v114; // r4
  size_t v115; // r6
  _DWORD *v116; // r0
  _DWORD *v117; // r8
  int v118; // r1
  unsigned int v119; // r6
  int v120; // r11
  int v121; // r5
  _DWORD *v122; // r4
  _DWORD *v123; // r10
  int v124; // r6
  char *v125; // r7
  unsigned int v126; // r3
  int v127; // r3
  _DWORD *v128; // r3
  unsigned int v129; // r1
  unsigned int v130; // r2
  bool v131; // cc
  int v132; // r2
  int v133; // r3
  signed int v134; // s16
  double v135; // r0
  double v136; // d8
  struct tm *v137; // r0
  int j; // r3
  int v139; // r1
  int v140; // r2
  int v141; // r3
  int v142; // r1
  int v143; // r2
  int v144; // r3
  int v145; // r2
  const char *v146; // r3
  unsigned __int64 v147; // r0
  int v148; // [sp+8h] [bp-87Ch]
  unsigned int i; // [sp+8h] [bp-87Ch]
  _DWORD *v150; // [sp+Ch] [bp-878h]
  int v151; // [sp+10h] [bp-874h]
  int v152; // [sp+14h] [bp-870h]
  time_t timer; // [sp+18h] [bp-86Ch] BYREF
  int s2; // [sp+1Ch] [bp-868h] BYREF
  int v155; // [sp+20h] [bp-864h]
  int v156; // [sp+24h] [bp-860h]
  int v157; // [sp+28h] [bp-85Ch]
  int v158; // [sp+2Ch] [bp-858h]
  int v159; // [sp+30h] [bp-854h]
  int v160; // [sp+34h] [bp-850h]
  int v161; // [sp+38h] [bp-84Ch]
  char s[68]; // [sp+3Ch] [bp-848h] BYREF
  char v163[2052]; // [sp+80h] [bp-804h] BYREF

  v3 = a1;
  v150 = *(_DWORD **)(a1 + 260);
  if ( *(_BYTE *)(a1 + 282) )
    return 1;
  v6 = *(_DWORD *)(a1 + 28);
  v7 = *(_DWORD *)(a1 + 12);
  v8 = *(_DWORD *)(a1 + 8);
  v9 = *(_DWORD *)(a1 + 24);
  v10 = *(_DWORD *)(a1 + 20);
  v11 = *(_DWORD *)(a1 + 16);
  s2 = *(_DWORD *)(a1 + 32);
  v12 = *(_DWORD *)(a1 + 4);
  v159 = v7;
  v160 = v8;
  v161 = v12;
  v155 = v6;
  v156 = v9;
  v157 = v10;
  v158 = v11;
  sub_29460(s, (char *)&s2, 32);
  if ( pthread_rwlock_rdlock(&stru_61550) )
    sub_B76C("block_exists", 5325);
  v13 = dword_61570;
  if ( dword_61570 )
  {
    v14 = strlen(s);
    v15 = -1640531527;
    v16 = (unsigned __int8 *)s;
    v17 = -1640531527;
    v18 = v14;
    v131 = v14 > 0xB;
    v19 = -17973521;
    v20 = v18;
    if ( v131 )
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
    v34 = *(_DWORD **)(dword_61570 + 68);
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
  if ( pthread_rwlock_unlock(&stru_61550) )
    sub_B700("block_exists", 5327);
  off_60178();
  if ( v13 )
  {
    if ( !memcmp(v150 + 134, &s2, 0x20u) )
    {
      v4 = 1;
    }
    else if ( !memcmp(&s2, dword_6157C, 0x20u) )
    {
      if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
      {
        snprintf(v163, 0x800u, "Pool %d now up to date", *v150);
        sub_38438(7, v163, 0);
      }
      v4 = 1;
      v76 = v155;
      v77 = v156;
      v78 = v157;
      v150[134] = s2;
      v150[135] = v76;
      v150[136] = v77;
      v150[137] = v78;
      v79 = v159;
      v80 = v160;
      v81 = v161;
      v150[138] = v158;
      v150[139] = v79;
      v150[140] = v80;
      v150[141] = v81;
    }
    else
    {
      v4 = (unsigned __int8)byte_630C1;
      if ( byte_630C1 )
      {
        if ( byte_632F0 || (v4 = (unsigned __int8)byte_630C0, byte_630C0) || dword_60964 > 6 )
        {
          v4 = 0;
          snprintf(v163, 0x800u, "Stale data from pool %d", *v150);
          sub_38438(7, v163, 0);
        }
      }
    }
    if ( *(_BYTE *)(v3 + 280) )
    {
      v131 = (unsigned int)(dword_611AC - 3) > 1;
      *(_DWORD *)(v3 + 336) = ++dword_6136C;
      if ( !v131 || (v42 = *(_DWORD *)(v3 + 260), v42 == sub_1D644()) )
      {
        if ( *(_BYTE *)(v3 + 284) )
        {
          if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
          {
            snprintf(v163, 0x800u, "Stratum from pool %d requested work restart", *v150);
            sub_38438(7, v163, 0);
          }
        }
        else if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
        {
          v43 = "";
          if ( *(_BYTE *)(v3 + 324) )
            v43 = "GBT ";
          snprintf(v163, 0x800u, "%sLONGPOLL from pool %d requested work restart", v43, **(_DWORD **)(v3 + 260));
          sub_38438(7, v163, 0);
        }
        sub_16C8C();
      }
    }
    goto LABEL_41;
  }
  v44 = (char *)calloc(0x68u, 1u);
  v45 = (int)v44;
  if ( !v44 )
  {
    strcpy(v163, "test_work_current OOM");
    sub_38438(3, v163, 1);
    sub_16724(1);
  }
  strcpy(v44, s);
  v46 = dword_640BC++;
  *(_DWORD *)(v45 + 100) = v46;
  if ( pthread_rwlock_wrlock(&stru_61550) )
    sub_B550("test_work_current", 5392);
  v47 = dword_61570;
  if ( !dword_61570 )
  {
    *(_DWORD *)(v45 + 76) = 0;
    *(_DWORD *)(v45 + 88) = v45;
    v151 = 0;
    *(_DWORD *)(v45 + 92) = strlen((const char *)v45);
    goto LABEL_105;
  }
  if ( *(_DWORD *)(*(_DWORD *)(dword_61570 + 68) + 12) <= 6u )
  {
    *(_DWORD *)(v45 + 88) = v45;
    *(_DWORD *)(v45 + 76) = 0;
    v151 = 0;
    *(_DWORD *)(v45 + 92) = strlen((const char *)v45);
    goto LABEL_137;
  }
  v48 = dword_61570 + 68;
  v49 = 1;
  while ( 2 )
  {
    v50 = v48;
    v48 = 0;
    v51 = 0;
    v52 = 0;
    do
    {
      ++v52;
      if ( v49 )
      {
        v53 = *(_DWORD *)(v50 + 8);
        if ( v53 )
        {
          v55 = *(_DWORD *)(*(_DWORD *)(v47 + 68) + 20);
          v54 = 1;
          for ( v53 += v55; v53; v53 += v55 )
          {
            if ( v54 == v49 )
              break;
            v53 = *(_DWORD *)(v53 + 8);
            ++v54;
            if ( !v53 )
              break;
          }
        }
        else
        {
          v54 = 1;
        }
      }
      else
      {
        v53 = v50;
        v54 = 0;
      }
      v56 = v50;
      v57 = v49;
      v50 = v53;
      while ( v54 )
      {
LABEL_69:
        v58 = v57 == 0;
        if ( v57 )
          v58 = v50 == 0;
        if ( v58 )
        {
          if ( !v56 )
            goto LABEL_128;
          v13 = *(_DWORD *)(v56 + 8);
          if ( v13 )
            v13 += *(_DWORD *)(*(_DWORD *)(v47 + 68) + 20);
LABEL_76:
          --v54;
          if ( !v51 )
            goto LABEL_125;
LABEL_77:
          if ( v56 )
          {
            *(_DWORD *)(v51 + 8) = v56 - *(_DWORD *)(*(_DWORD *)(v47 + 68) + 20);
            v59 = v51 - *(_DWORD *)(*(_DWORD *)(v47 + 68) + 20);
            v51 = v56;
            v56 = v13;
            goto LABEL_79;
          }
          *(_DWORD *)(v51 + 8) = 0;
          v51 = 0;
          v56 = v13;
        }
        else
        {
          v75 = *(_DWORD *)(*(_DWORD *)(v47 + 68) + 20);
          v1 = *(_DWORD *)(v50 - v75 + 100);
          v13 = *(_DWORD *)(v56 - v75 + 100) - v1;
          if ( v13 > 0 )
          {
            v1 = *(_DWORD *)(v50 + 8);
            if ( v1 )
              v1 += v75;
            goto LABEL_113;
          }
          if ( !v56 )
          {
LABEL_128:
            v13 = v56;
            goto LABEL_76;
          }
          v13 = *(_DWORD *)(v56 + 8);
          --v54;
          if ( v13 )
            v13 += v75;
          if ( v51 )
            goto LABEL_77;
LABEL_125:
          if ( v56 )
          {
            v51 = v56;
            v59 = 0;
            v56 = v13;
            v48 = v51;
            goto LABEL_79;
          }
          v48 = 0;
          v56 = v13;
          v51 = 0;
        }
      }
      while ( 1 )
      {
        v60 = v50 == 0;
        if ( v50 )
          v60 = v57 == 0;
        if ( v60 )
          break;
        v74 = *(_DWORD *)(v50 + 8);
        if ( v74 )
          v13 = *(_DWORD *)(v47 + 68);
        else
          v1 = v54;
        if ( v74 )
        {
          v13 = *(_DWORD *)(v13 + 20);
          v1 = v74 + v13;
        }
LABEL_113:
        --v57;
        if ( v51 )
        {
          v13 = v56;
          v56 = v50;
          v50 = v1;
          goto LABEL_77;
        }
        v51 = v50;
        v59 = 0;
        v50 = v1;
        v48 = v51;
LABEL_79:
        *(_DWORD *)(v51 + 4) = v59;
        if ( v54 )
          goto LABEL_69;
      }
    }
    while ( v50 );
    if ( v51 )
      *(_DWORD *)(v51 + 8) = 0;
    if ( v52 > 1 )
    {
      v49 *= 2;
      if ( !v48 )
      {
        v51 = 0;
        break;
      }
      continue;
    }
    break;
  }
  *(_DWORD *)(*(_DWORD *)(v47 + 68) + 16) = v51;
  v61 = v48 - *(_DWORD *)(*(_DWORD *)(v47 + 68) + 20);
  dword_61570 = v61;
  v62 = *(_DWORD *)(v61 + 72);
  v151 = *(_DWORD *)(v61 + 100);
  if ( v62 || *(_DWORD *)(v61 + 76) )
  {
    v63 = *(_DWORD *)(v61 + 68);
    v64 = *(_DWORD *)(v63 + 20);
    if ( v61 == *(_DWORD *)(v63 + 16) - v64 )
    {
      *(_DWORD *)(v63 + 16) = v62 + v64;
      v62 = *(_DWORD *)(v61 + 72);
    }
    if ( v62 )
    {
      v47 = v61;
      *(_DWORD *)(v62 + *(_DWORD *)(*(_DWORD *)(v61 + 68) + 20) + 8) = *(_DWORD *)(v61 + 76);
      v65 = *(_DWORD *)(v61 + 76);
    }
    else
    {
      v65 = *(_DWORD *)(v61 + 76);
      v47 = v65;
      dword_61570 = v65;
    }
    if ( v65 )
      *(_DWORD *)(v65 + *(_DWORD *)(*(_DWORD *)(v47 + 68) + 20) + 4) = *(_DWORD *)(v61 + 72);
    v66 = *(_DWORD **)(v47 + 68);
    v67 = 12 * ((v66[1] - 1) & *(_DWORD *)(v61 + 96));
    --*(_DWORD *)(*v66 + v67 + 4);
    v68 = **(_DWORD **)(v47 + 68);
    if ( *(_DWORD *)(v68 + v67) == v61 + 68 )
      *(_DWORD *)(v68 + v67) = *(_DWORD *)(v61 + 84);
    v69 = *(_DWORD *)(v61 + 80);
    if ( v69 )
      *(_DWORD *)(v69 + 16) = *(_DWORD *)(v61 + 84);
    v70 = *(_DWORD *)(v61 + 84);
    if ( v70 )
      *(_DWORD *)(v70 + 12) = *(_DWORD *)(v61 + 80);
    --*(_DWORD *)(*(_DWORD *)(v47 + 68) + 12);
  }
  else
  {
    v47 = 0;
    free(**(void ***)(v61 + 68));
    free(*(void **)(v61 + 68));
    dword_61570 = 0;
  }
  free((void *)v61);
  *(_DWORD *)(v45 + 88) = v45;
  *(_DWORD *)(v45 + 76) = 0;
  *(_DWORD *)(v45 + 92) = strlen((const char *)v45);
  if ( !v47 )
  {
LABEL_105:
    *(_DWORD *)(v45 + 72) = 0;
    dword_61570 = v45;
    v71 = malloc(0x2Cu);
    v72 = v71;
    *(_DWORD *)(v45 + 68) = v71;
    if ( v71 )
    {
      v148 = v45 + 68;
      *v71 = 0;
      v71[3] = 0;
      v71[4] = 0;
      v71[5] = 0;
      v71[6] = 0;
      v71[7] = 0;
      v71[8] = 0;
      v71[9] = 0;
      v71[10] = 0;
      v71[1] = 32;
      v71[4] = v45 + 68;
      v71[2] = 5;
      v71[5] = 68;
      v73 = malloc(0x180u);
      *v72 = v73;
      if ( v73 )
      {
        memset(v73, 0, 0x180u);
        v47 = v45;
        v72[10] = -1609490463;
        goto LABEL_138;
      }
    }
LABEL_251:
    exit(-1);
  }
LABEL_137:
  v148 = v45 + 68;
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v47 + 68) + 16) + 8) = v45;
  *(_DWORD *)(v45 + 72) = *(_DWORD *)(*(_DWORD *)(v47 + 68) + 16) - *(_DWORD *)(*(_DWORD *)(v47 + 68) + 20);
  *(_DWORD *)(*(_DWORD *)(v47 + 68) + 16) = v45 + 68;
  v72 = *(_DWORD **)(v47 + 68);
LABEL_138:
  v82 = -17973521;
  ++v72[3];
  v83 = *(_DWORD *)(v47 + 68);
  v84 = -1640531527;
  *(_DWORD *)(v45 + 96) = -17973521;
  *(_DWORD *)(v45 + 68) = v83;
  v85 = strlen((const char *)v45);
  v86 = v85;
  if ( v85 <= 0xB )
  {
    v88 = -1640531527;
    v87 = (unsigned __int8 *)v45;
  }
  else
  {
    v87 = (unsigned __int8 *)v45;
    v88 = -1640531527;
    do
    {
      v86 -= 12;
      v89 = (v87[2] << 16) + (v87[1] << 8) + *v87;
      v90 = v87[3];
      v91 = (v87[6] << 16) + (v87[5] << 8) + v87[4];
      v92 = v87[7];
      v93 = (v87[10] << 16) + (v87[9] << 8) + v87[8] + (v87[11] << 24) + v82;
      v87 += 12;
      v94 = v91 + (v92 << 24) + v84;
      v95 = (v89 + (v90 << 24) - v93 - v94 + v88) ^ (v93 >> 13);
      v96 = (v94 - v93 - v95) ^ (v95 << 8);
      v97 = (v93 - v95 - v96) ^ (v96 >> 13);
      v98 = (v95 - v96 - v97) ^ (v97 >> 12);
      v99 = (v96 - v97 - v98) ^ (v98 << 16);
      v100 = (v97 - v98 - v99) ^ (v99 >> 5);
      v88 = (v98 - v99 - v100) ^ (v100 >> 3);
      v84 = (v99 - v100 - v88) ^ (v88 << 10);
      v82 = (v100 - v88 - v84) ^ (v84 >> 15);
      *(_DWORD *)(v45 + 96) = v82;
    }
    while ( v86 > 0xB );
    v85 = strlen((const char *)v45);
  }
  v101 = v85 + v82;
  *(_DWORD *)(v45 + 96) = v101;
  switch ( v86 )
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
      v101 += v87[10] << 24;
      *(_DWORD *)(v45 + 96) = v101;
LABEL_144:
      v101 += v87[9] << 16;
      *(_DWORD *)(v45 + 96) = v101;
LABEL_145:
      v101 += v87[8] << 8;
      *(_DWORD *)(v45 + 96) = v101;
LABEL_146:
      v84 += v87[7] << 24;
LABEL_147:
      v84 += v87[6] << 16;
LABEL_148:
      v84 += v87[5] << 8;
LABEL_149:
      v84 += v87[4];
LABEL_150:
      v88 += v87[3] << 24;
LABEL_151:
      v88 += v87[2] << 16;
LABEL_152:
      v88 += v87[1] << 8;
LABEL_153:
      v88 += *v87;
      break;
    default:
      break;
  }
  v102 = (v88 - v84 - v101) ^ (v101 >> 13);
  v103 = (v84 - v101 - v102) ^ (v102 << 8);
  v104 = (v101 - v102 - v103) ^ (v103 >> 13);
  v105 = (v102 - v103 - v104) ^ (v104 >> 12);
  v106 = (v103 - v104 - v105) ^ (v105 << 16);
  v107 = (v104 - v105 - v106) ^ (v106 >> 5);
  v108 = v105 - v106 - v107;
  v109 = (v107 - (v108 ^ (v107 >> 3)) - ((v106 - v107 - (v108 ^ (v107 >> 3))) ^ ((v108 ^ (v107 >> 3)) << 10)))
       ^ (((v106 - v107 - (v108 ^ (v107 >> 3))) ^ ((v108 ^ (v107 >> 3)) << 10)) >> 15);
  *(_DWORD *)(v45 + 96) = v109;
  v110 = *(_DWORD **)(v47 + 68);
  v111 = 12 * (v109 & (v110[1] - 1));
  ++*(_DWORD *)(*v110 + v111 + 4);
  v112 = *(_DWORD *)(**(_DWORD **)(v47 + 68) + v111);
  *(_DWORD *)(v45 + 80) = 0;
  *(_DWORD *)(v45 + 84) = v112;
  v113 = **(_DWORD **)(v47 + 68) + v111;
  if ( *(_DWORD *)v113 )
  {
    *(_DWORD *)(*(_DWORD *)v113 + 12) = v148;
    v113 = **(_DWORD **)(v47 + 68) + v111;
  }
  *(_DWORD *)v113 = v148;
  if ( *(_DWORD *)(**(_DWORD **)(v47 + 68) + v111 + 4) >= (unsigned int)(10
                                                                       * (*(_DWORD *)(**(_DWORD **)(v47 + 68) + v111 + 8)
                                                                        + 1)) )
  {
    v114 = *(_DWORD *)(v45 + 68);
    if ( *(_DWORD *)(v114 + 36) != 1 )
    {
      v115 = 24 * *(_DWORD *)(v114 + 4);
      v116 = malloc(v115);
      v117 = v116;
      if ( !v116 )
        goto LABEL_251;
      memset(v116, 0, v115);
      *(_DWORD *)(v114 + 24) = (((2 * *(_DWORD *)(v114 + 4) - 1) & *(_DWORD *)(v114 + 12)) != 0)
                             + (*(_DWORD *)(v114 + 12) >> (*(_BYTE *)(v114 + 8) + 1));
      *(_DWORD *)(*(_DWORD *)(v45 + 68) + 28) = 0;
      v118 = *(_DWORD *)(v45 + 68);
      v119 = *(_DWORD *)(v118 + 4);
      if ( v119 )
      {
        v152 = v3;
        v120 = 0;
        v121 = v45;
        for ( i = 0; i < v119; ++i )
        {
          v122 = *(_DWORD **)(*(_DWORD *)v118 + v120);
          if ( v122 )
          {
            while ( 1 )
            {
              v123 = (_DWORD *)v122[4];
              v124 = 3 * ((2 * v119 - 1) & v122[7]);
              v125 = (char *)&v117[v124];
              v126 = *((_DWORD *)v125 + 1) + 1;
              *((_DWORD *)v125 + 1) = v126;
              if ( v126 > *(_DWORD *)(v118 + 24) )
              {
                ++*(_DWORD *)(v118 + 28);
                *((_DWORD *)v125 + 2) = *((_DWORD *)v125 + 1) / *(_DWORD *)(*(_DWORD *)(v121 + 68) + 24);
              }
              v122[3] = 0;
              v122[4] = v117[v124];
              v127 = v117[v124];
              if ( v127 )
                *(_DWORD *)(v127 + 12) = v122;
              v117[v124] = v122;
              v118 = *(_DWORD *)(v121 + 68);
              if ( !v123 )
                break;
              v119 = *(_DWORD *)(v118 + 4);
              v122 = v123;
            }
            v119 = *(_DWORD *)(v118 + 4);
          }
          v120 += 12;
        }
        v45 = v121;
        v3 = v152;
      }
      free(*(void **)v118);
      *(_DWORD *)(*(_DWORD *)(v45 + 68) + 4) *= 2;
      ++*(_DWORD *)(*(_DWORD *)(v45 + 68) + 8);
      **(_DWORD **)(v45 + 68) = v117;
      v128 = *(_DWORD **)(v45 + 68);
      v129 = v128[3];
      v130 = v128[7];
      v131 = v130 > v129 >> 1;
      if ( v130 <= v129 >> 1 )
        v132 = 0;
      else
        v132 = v128[8];
      if ( v131 )
        ++v132;
      v128[8] = v132;
      v133 = *(_DWORD *)(v45 + 68);
      if ( *(_DWORD *)(v133 + 32) > 1u )
        *(_DWORD *)(v133 + 36) = 1;
    }
  }
  LODWORD(v2) = 8 * (29 - *(unsigned __int8 *)(v3 + 72));
  v134 = bswap32(*(_DWORD *)(v3 + 72)) & 0xFFFFFF;
  LODWORD(v135) = sub_493C8(vshld_u64(0xFFFFu, v2));
  v136 = v135 / (double)v134;
  if ( v136 != dbl_60080 )
  {
    LODWORD(v147) = sub_494C0(v136);
    sub_11130(v147, byte_61574, 8u, 0);
    dbl_60080 = v136;
    if ( byte_630C1 )
    {
      if ( byte_632F0 || byte_630C0 || dword_60964 > 6 )
      {
        snprintf(v163, 0x800u, "Network diff set to %s", byte_61574);
        sub_38438(7, v163, 0);
      }
    }
  }
  if ( pthread_rwlock_unlock(&stru_61550) )
    sub_B700("test_work_current", 5408);
  off_60178();
  if ( v151 && byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    snprintf(v163, 0x800u, "Deleted block %d from database", v151);
    sub_38438(7, v163, 0);
  }
  if ( pthread_mutex_lock(&stru_63F78) )
    sub_B4E4("set_curblock", 5302);
  if ( pthread_rwlock_wrlock(&stru_63F90) )
    sub_B550("set_curblock", 5302);
  sub_2B13C((struct timeval *)&dword_63618);
  strcpy(dest, s);
  timer = dword_63618;
  dword_6157C[0] = s2;
  dword_6157C[1] = v155;
  dword_6157C[2] = v156;
  dword_6157C[3] = v157;
  unk_6158C = v158;
  unk_61590 = v159;
  unk_61594 = v160;
  unk_61598 = v161;
  v137 = localtime(&timer);
  snprintf(byte_6159C, 0x20u, "[%02d:%02d:%02d]", v137->tm_hour, v137->tm_min, v137->tm_sec);
  if ( pthread_rwlock_unlock(&stru_63F90) )
    sub_B700("set_curblock", 5307);
  if ( pthread_mutex_unlock(&stru_63F78) )
    sub_B694("set_curblock", 5307);
  off_60178();
  for ( j = 0; j != 57; ++j )
  {
    if ( dest[j] != 48 )
      break;
  }
  strncpy(byte_615BC, &dest[j], 8u);
  byte_615C4 = 0;
  if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    snprintf(v163, 0x800u, "New block: %s... diff %s", dest, byte_61574);
    sub_38438(7, v163, 0);
  }
  v139 = v155;
  v140 = v156;
  v141 = v157;
  v58 = dword_640BC == 1;
  v150[134] = s2;
  v150[135] = v139;
  v150[136] = v140;
  v150[137] = v141;
  v142 = v159;
  v143 = v160;
  v144 = v161;
  v150[138] = v158;
  v150[139] = v142;
  v150[140] = v143;
  v150[141] = v144;
  if ( v58 )
  {
    v4 = 0;
LABEL_41:
    *(_BYTE *)(v3 + 280) = 0;
    return v4;
  }
  v145 = *(unsigned __int8 *)(v3 + 280);
  *(_DWORD *)(v3 + 336) = ++dword_6136C;
  if ( v145 )
  {
    if ( *(_BYTE *)(v3 + 284) )
    {
      if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
      {
        snprintf(v163, 0x800u, "Stratum from pool %d detected new block", *v150);
        sub_38438(7, v163, 0);
      }
    }
    else if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      v146 = "";
      if ( *(_BYTE *)(v3 + 324) )
        v146 = "GBT ";
      snprintf(v163, 0x800u, "%sLONGPOLL from pool %d detected new block", v146, **(_DWORD **)(v3 + 260));
      sub_38438(7, v163, 0);
    }
  }
  else if ( byte_64219 )
  {
    if ( !*((_BYTE *)v150 + 868) && byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      strcpy(v163, "New block detected on network before pool notification");
      sub_38438(7, v163, 0);
    }
  }
  else if ( !*((_BYTE *)v150 + 868) && byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    strcpy(v163, "New block detected on network");
    sub_38438(7, v163, 0);
  }
  sub_16C8C();
  v4 = 1;
  *(_BYTE *)(v3 + 280) = 0;
  return v4;
}
