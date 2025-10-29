int __fastcall test_work_current(int a1)
{
  int v3; // r1
  int v4; // r4
  int v5; // r3
  int v6; // r2
  int v7; // r0
  int v8; // r4
  _DWORD *v9; // r3
  int v10; // r4
  size_t v11; // r0
  int v12; // r3
  size_t v13; // r6
  unsigned __int8 *v14; // r12
  int v15; // r0
  unsigned int v16; // lr
  unsigned int v17; // r5
  int v18; // r10
  int v19; // r7
  int v20; // r2
  unsigned __int8 *v21; // r9
  int v22; // r3
  unsigned int v23; // r5
  unsigned int v24; // r3
  int v25; // r2
  unsigned int v26; // r1
  unsigned int v27; // r3
  int v28; // r2
  unsigned int v29; // r1
  unsigned int v30; // r3
  size_t v31; // r4
  int *v32; // r0
  const char *v33; // r2
  int v34; // r1
  char *v35; // r0
  block *v36; // r11
  unsigned int v37; // r3
  block *v38; // r5
  UT_hash_handle *v39; // lr
  int v40; // r7
  UT_hash_handle *v41; // r3
  UT_hash_handle *v42; // r2
  unsigned int v43; // r12
  UT_hash_handle *next; // r6
  ptrdiff_t hho; // r4
  int v46; // r1
  int v47; // r0
  UT_hash_handle *v48; // r4
  bool v49; // zf
  void *v50; // r8
  int v51; // r8
  char *v52; // r6
  bool v53; // zf
  UT_hash_handle *v54; // r9
  int v55; // r2
  UT_hash_table *tbl; // r0
  int v57; // r2
  unsigned int v58; // r3
  unsigned int v59; // r5
  int v60; // r4
  unsigned int v61; // r3
  unsigned int v62; // r5
  int v63; // r4
  UT_hash_handle *hh_head; // r4
  int v65; // r5
  char *v66; // r4
  _BOOL4 v67; // r3
  UT_hash_table *v68; // r4
  int v69; // r7
  unsigned int v70; // r6
  UT_hash_table *v71; // r3
  size_t v72; // r0
  unsigned int v73; // r9
  unsigned __int8 *v74; // r10
  int v75; // r4
  int v76; // r1
  int v77; // r0
  int v78; // r3
  unsigned __int8 *v79; // r8
  int v80; // r12
  unsigned int v81; // r1
  unsigned int v82; // r3
  int v83; // r2
  unsigned int v84; // r3
  unsigned int v85; // r1
  int v86; // r2
  unsigned int v87; // r3
  unsigned int v88; // r1
  unsigned int v89; // r7
  int v90; // r3
  unsigned int v91; // r6
  unsigned int v92; // r7
  int v93; // r3
  unsigned int v94; // r6
  unsigned int v95; // r7
  int v96; // r3
  unsigned int v97; // r3
  int v98; // r3
  UT_hash_handle *v99; // r2
  UT_hash_bucket *v100; // r2
  UT_hash_handle *v101; // r1
  UT_hash_bucket *v102; // r2
  __int64 v103; // r2
  UT_hash_table *v104; // r4
  UT_hash_bucket *v105; // r6
  unsigned int num_items; // r0
  unsigned int v107; // r3
  UT_hash_table *v108; // r3
  unsigned int num_buckets; // r4
  int v110; // r8
  UT_hash_handle *v111; // r5
  UT_hash_handle *v112; // r7
  int v113; // r4
  UT_hash_bucket *v114; // r9
  unsigned int v115; // r1
  UT_hash_handle *v116; // r3
  UT_hash_table *v117; // r3
  unsigned int nonideal_items; // r2
  unsigned int v119; // r1
  bool v120; // cc
  unsigned int ineff_expands; // r2
  UT_hash_table *v122; // r3
  char v123; // r3
  unsigned __int64 v124; // r0
  double v125; // d8
  const char *v126; // r2
  struct tm *v127; // r0
  const char *v128; // r2
  int v129; // r7
  char *v130; // r3
  int v131; // t1
  const char *v132; // r2
  int v133; // r1
  int v134; // r2
  int v135; // r3
  int v136; // r1
  int v137; // r2
  int v138; // r3
  int v139; // r1
  ptrdiff_t v140; // r9
  void *v141; // r6
  char *v142; // r6
  block *v143; // r4
  char *prev; // r0
  UT_hash_table *v145; // r5
  UT_hash_handle *v146; // r2
  ptrdiff_t v147; // r1
  block *v148; // r6
  UT_hash_table *v149; // r0
  int v150; // r1
  UT_hash_bucket *v151; // r0
  UT_hash_handle *hh_next; // r2
  UT_hash_handle *hh_prev; // r3
  UT_hash_table *v154; // r0
  UT_hash_bucket *v155; // r0
  char *v156; // r6
  int v157; // r0
  const char *v158; // r2
  int v159; // r1
  int v160; // r2
  int v161; // r3
  int v162; // r1
  int v163; // r2
  int v164; // r3
  pool *v165; // r4
  int *v166; // r0
  int v167; // r1
  const char *v168; // r2
  char *v169; // r3
  const char *v170; // r2
  time_t *v171; // r6
  time_t v172; // r0
  time_t v173; // r1
  time_t v174; // r2
  time_t v175; // r3
  time_t v176; // r1
  time_t v177; // r2
  time_t v178; // r3
  char *v179; // r3
  const char *v180; // r2
  time_t *v181; // r6
  time_t v182; // r0
  time_t v183; // r1
  time_t v184; // r2
  time_t v185; // r3
  time_t v186; // r0
  time_t v187; // r1
  time_t v188; // r2
  time_t v189; // r3
  time_t v190; // r0
  time_t v191; // r1
  time_t v192; // r2
  time_t v193; // r3
  time_t v194; // r1
  time_t *v195; // r4
  time_t v196; // r0
  time_t v197; // r1
  time_t v198; // r2
  time_t v199; // r3
  time_t v200; // r1
  int *v201; // r0
  int v202; // r1
  const char *v203; // r2
  const char *v204; // r2
  int *v205; // r0
  const char *v206; // r2
  int v207; // r1
  int *v208; // r0
  int v209; // r1
  const char *v210; // r2
  int *v211; // r0
  int v212; // r1
  const char *v213; // r2
  int *v214; // r0
  int v215; // r1
  const char *v216; // r2
  int *v217; // r0
  int v218; // r1
  const char *v219; // r2
  UT_hash_bucket *buckets; // r0
  int v221; // [sp+14h] [bp-1090h]
  _DWORD *v223; // [sp+24h] [bp-1080h]
  UT_hash_handle *p_hh; // [sp+28h] [bp-107Ch]
  unsigned int i; // [sp+28h] [bp-107Ch]
  int block_no; // [sp+2Ch] [bp-1078h]
  int v227; // [sp+3Ch] [bp-1068h] BYREF
  int v228; // [sp+40h] [bp-1064h]
  int v229; // [sp+44h] [bp-1060h]
  int v230; // [sp+48h] [bp-105Ch]
  int v231; // [sp+4Ch] [bp-1058h]
  int v232; // [sp+50h] [bp-1054h]
  int v233; // [sp+54h] [bp-1050h]
  int v234; // [sp+58h] [bp-104Ch]
  char s[12]; // [sp+5Ch] [bp-1048h] BYREF
  char v236; // [sp+68h] [bp-103Ch] BYREF
  time_t str; // [sp+A0h] [bp-1004h] BYREF
  time_t v238; // [sp+A4h] [bp-1000h]
  time_t v239; // [sp+A8h] [bp-FFCh]
  time_t v240; // [sp+ACh] [bp-FF8h]
  time_t v241; // [sp+B0h] [bp-FF4h]
  time_t v242; // [sp+B4h] [bp-FF0h]
  time_t v243; // [sp+B8h] [bp-FECh]
  time_t v244; // [sp+BCh] [bp-FE8h]
  time_t v245; // [sp+C0h] [bp-FE4h]
  time_t v246; // [sp+C4h] [bp-FE0h]
  time_t v247; // [sp+C8h] [bp-FDCh]
  time_t v248; // [sp+CCh] [bp-FD8h]
  time_t v249; // [sp+D0h] [bp-FD4h]
  __int16 v250; // [sp+D4h] [bp-FD0h]
  char v251; // [sp+D6h] [bp-FCEh]

  v221 = *(unsigned __int8 *)(a1 + 1770);
  if ( *(_BYTE *)(a1 + 1770) )
    return v221;
  v3 = *(_DWORD *)(a1 + 32);
  v228 = *(_DWORD *)(a1 + 28);
  v4 = *(_DWORD *)(a1 + 12);
  v231 = *(_DWORD *)(a1 + 16);
  v5 = *(_DWORD *)(a1 + 8);
  v6 = *(_DWORD *)(a1 + 20);
  v232 = v4;
  v7 = *(_DWORD *)(a1 + 24);
  v8 = *(_DWORD *)(a1 + 4);
  v233 = v5;
  v9 = *(_DWORD **)(a1 + 1748);
  v227 = v3;
  v229 = v7;
  v230 = v6;
  v234 = v8;
  v223 = v9;
  _bin2hex(s, (const unsigned __int8 *)&v227, 0x20u);
  if ( pthread_rwlock_rdlock(&blk_lock) )
  {
    v166 = _errno_location();
    LOWORD(v167) = -3136;
    LOWORD(v168) = -232;
    HIWORD(v167) = (unsigned int)"iner" >> 16;
    HIWORD(v168) = (unsigned int)"" >> 16;
    snprintf((char *)&str, 0x1000u, v168, *v166, v167, "block_exists", 5347);
    goto LABEL_12;
  }
  if ( blocks )
  {
    LOWORD(v10) = -16657;
    v11 = strlen(s);
    v12 = -1640531527;
    v13 = v11;
    if ( v11 <= 0xB )
    {
      HIWORD(v10) = -275;
      v15 = -1640531527;
      v16 = v13;
      v21 = (unsigned __int8 *)s;
    }
    else
    {
      v14 = (unsigned __int8 *)&v236;
      v15 = -1640531527;
      HIWORD(v10) = -275;
      v16 = v13;
      v17 = -1640531527;
      do
      {
        v18 = *(v14 - 6);
        v16 -= 12;
        v19 = *(v14 - 7);
        v20 = *(v14 - 10);
        v21 = v14;
        v22 = *(v14 - 2);
        v14 += 12;
        v23 = v17 + (v18 << 16) + (v19 << 8) + *(v14 - 20) + (*(v14 - 17) << 24);
        v24 = *(v14 - 16) + (v22 << 16) + (*(v14 - 15) << 8) + (*(v14 - 13) << 24) + v10;
        v25 = ((v20 << 16) + (*(v14 - 23) << 8) + *(v14 - 24) + (*(v14 - 21) << 24) - v23 - v24 + v15) ^ (v24 >> 13);
        v26 = (v23 - v24 - v25) ^ (v25 << 8);
        v27 = (v24 - v25 - v26) ^ (v26 >> 13);
        v28 = (v25 - v26 - v27) ^ (v27 >> 12);
        v29 = (v26 - v27 - v28) ^ (v28 << 16);
        v30 = (v27 - v28 - v29) ^ (v29 >> 5);
        v15 = (v28 - v29 - v30) ^ (v30 >> 3);
        v17 = (v29 - v30 - v15) ^ (v15 << 10);
        v10 = (v30 - v15 - v17) ^ (v17 >> 15);
      }
      while ( v16 > 0xB );
      v12 = (v29 - v30 - v15) ^ (v15 << 10);
    }
    v31 = v10 + v13;
    switch ( v16 )
    {
      case 1u:
        goto LABEL_58;
      case 2u:
        goto LABEL_57;
      case 3u:
        goto LABEL_56;
      case 4u:
        goto LABEL_55;
      case 5u:
        goto LABEL_54;
      case 6u:
        goto LABEL_53;
      case 7u:
        goto LABEL_52;
      case 8u:
        goto LABEL_51;
      case 9u:
        goto LABEL_50;
      case 0xAu:
        goto LABEL_49;
      case 0xBu:
        v31 += v21[10] << 24;
LABEL_49:
        v31 += v21[9] << 16;
LABEL_50:
        v31 += v21[8] << 8;
LABEL_51:
        v12 += v21[7] << 24;
LABEL_52:
        v12 += v21[6] << 16;
LABEL_53:
        v12 += v21[5] << 8;
LABEL_54:
        v12 += v21[4];
LABEL_55:
        v15 += v21[3] << 24;
LABEL_56:
        v15 += v21[2] << 16;
LABEL_57:
        v15 += v21[1] << 8;
LABEL_58:
        v15 += *v21;
        break;
      default:
        break;
    }
    v55 = v15 - v12;
    tbl = blocks->hh.tbl;
    v57 = (v55 - v31) ^ (v31 >> 13);
    v58 = (v12 - v31 - v57) ^ (v57 << 8);
    v59 = (v31 - v57 - v58) ^ (v58 >> 13);
    v60 = (v57 - v58 - v59) ^ (v59 >> 12);
    v61 = (v58 - v59 - v60) ^ (v60 << 16);
    v62 = (v59 - v60 - v61) ^ (v61 >> 5);
    v63 = (v60 - v61 - v62) ^ (v62 >> 3);
    hh_head = tbl->buckets[(tbl->num_buckets - 1)
                         & ((v62 - v63 - ((v61 - v62 - v63) ^ (v63 << 10)))
                          ^ (((v61 - v62 - v63) ^ (v63 << 10)) >> 15))].hh_head;
    if ( hh_head )
    {
      v65 = -tbl->hho;
      while ( 1 )
      {
        v66 = (char *)hh_head + v65;
        if ( !v66 )
          goto LABEL_10;
        if ( v13 == *((_DWORD *)v66 + 23) && !memcmp(*((const void **)v66 + 22), s, v13) )
          break;
        hh_head = (UT_hash_handle *)*((_DWORD *)v66 + 21);
        if ( !hh_head )
          goto LABEL_10;
      }
      if ( !pthread_rwlock_unlock(&blk_lock) )
      {
        selective_yield();
        if ( !memcmp(v223 + 142, &v227, 0x20u) )
        {
          v67 = 1;
        }
        else
        {
          v157 = memcmp(&v227, current_block, 0x20u);
          v67 = opt_debug;
          if ( !v157 )
          {
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              snprintf((char *)&str, 0x1000u, "Pool %d now up to date", *v223);
              applog(7, (const char *)&str, 0);
            }
            v221 = 1;
            v159 = v228;
            v160 = v229;
            v161 = v230;
            v223[142] = v227;
            v223[143] = v159;
            v223[144] = v160;
            v223[145] = v161;
            v162 = v232;
            v163 = v233;
            v164 = v234;
            v223[146] = v231;
            v223[147] = v162;
            v223[148] = v163;
            v223[149] = v164;
            goto LABEL_69;
          }
          if ( opt_debug )
          {
            if ( use_syslog || opt_log_output || opt_log_level > 6 )
            {
              LOWORD(v158) = 4316;
              HIWORD(v158) = (unsigned int)"cation" >> 16;
              snprintf((char *)&str, 0x1000u, v158, *v223);
              applog(7, (const char *)&str, 0);
            }
            else
            {
              v221 = opt_log_output;
            }
LABEL_69:
            if ( *(_BYTE *)(a1 + 1768) )
            {
              v120 = (unsigned int)(pool_strategy_0 - 3) > 1;
              *(_DWORD *)(a1 + 1824) = ++work_block;
              if ( !v120 || (v165 = *(pool **)(a1 + 1748), v165 == current_pool()) )
              {
                if ( *(_BYTE *)(a1 + 1772) )
                {
                  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                  {
                    snprintf((char *)&str, 0x1000u, "Stratum from pool %d requested work restart", *v223);
                    applog(7, (const char *)&str, 0);
                  }
                }
                else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  v169 = &byte_59414;
                  LOWORD(v170) = 4408;
                  if ( *(_BYTE *)(a1 + 1812) )
                    v169 = "GBT ";
                  HIWORD(v170) = (unsigned int)"tum from pool %d requested work restart" >> 16;
                  snprintf((char *)&str, 0x1000u, v170, v169, **(_DWORD **)(a1 + 1748));
                  applog(7, (const char *)&str, 0);
                }
                restart_threads();
              }
            }
            goto out;
          }
        }
        v221 = v67;
        goto LABEL_69;
      }
      goto LABEL_11;
    }
  }
LABEL_10:
  if ( pthread_rwlock_unlock(&blk_lock) )
  {
LABEL_11:
    v32 = _errno_location();
    LOWORD(v33) = -348;
    LOWORD(v34) = -3136;
    HIWORD(v33) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
    HIWORD(v34) = (unsigned int)"iner" >> 16;
    snprintf((char *)&str, 0x1000u, v33, *v32, v34, "block_exists", 5349);
    goto LABEL_12;
  }
  selective_yield();
  v35 = (char *)calloc(0x68u, 1u);
  v36 = (block *)v35;
  if ( !v35 )
  {
    LOWORD(v195) = 4016;
    HIWORD(v195) = (unsigned int)"han 10 minutes, declaring DEAD!" >> 16;
    v196 = *v195;
    v197 = v195[1];
    v198 = v195[2];
    v199 = v195[3];
    v195 += 4;
    str = v196;
    v238 = v197;
    v239 = v198;
    v240 = v199;
    v200 = v195[1];
    v241 = *v195;
    LOWORD(v242) = v200;
    applog(3, (const char *)&str, 1);
    _quit(1, 1);
  }
  strcpy(v35, s);
  v37 = new_blocks;
  v36->block_no = new_blocks;
  new_blocks = v37 + 1;
  block_no = pthread_rwlock_wrlock(&blk_lock);
  if ( block_no )
  {
    v201 = _errno_location();
    LOWORD(v202) = -3136;
    LOWORD(v203) = -1020;
    HIWORD(v202) = (unsigned int)"iner" >> 16;
    HIWORD(v203) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
    snprintf((char *)&str, 0x1000u, v203, *v201, v202, "test_work_current", 5414);
    goto LABEL_12;
  }
  v38 = blocks;
  if ( !blocks )
  {
    v36->hh.key = v36;
    v36->hh.next = 0;
    v36->hh.keylen = strlen(v36->hash);
    goto LABEL_184;
  }
  if ( blocks->hh.tbl->num_items <= 6 )
  {
    v36->hh.key = v36;
    v36->hh.next = 0;
    v36->hh.keylen = strlen(v36->hash);
LABEL_81:
    p_hh = &v36->hh;
    v38->hh.tbl->tail->next = v36;
    v36->hh.prev = (char *)v38->hh.tbl->tail - v38->hh.tbl->hho;
    v38->hh.tbl->tail = &v36->hh;
    v68 = v38->hh.tbl;
    goto LABEL_82;
  }
  v39 = &blocks->hh;
  v40 = 1;
  while ( 2 )
  {
    v41 = v39;
    v39 = 0;
    v42 = 0;
    v43 = 0;
    do
    {
      ++v43;
      if ( v40 )
      {
        next = (UT_hash_handle *)v41->next;
        if ( next && (hho = v38->hh.tbl->hho, (next = (UT_hash_handle *)((char *)next + hho)) != 0) )
        {
          v46 = 1;
          do
          {
            if ( v46 == v40 )
            {
              v47 = v46;
              goto LABEL_27;
            }
            next = (UT_hash_handle *)next->next;
            ++v46;
            if ( !next )
              break;
            next = (UT_hash_handle *)((char *)next + hho);
          }
          while ( next );
          v47 = v40;
        }
        else
        {
          v47 = v40;
          v46 = 1;
        }
      }
      else
      {
        next = v41;
        v47 = 0;
        v46 = 0;
      }
LABEL_27:
      v48 = v41;
      v41 = next;
      while ( v46 )
      {
        v53 = v41 == 0;
        if ( v41 )
          v53 = v47 == 0;
        if ( v53 )
        {
          if ( !v48 )
            goto LABEL_161;
          v54 = (UT_hash_handle *)v48->next;
          if ( v54 )
            v54 = (UT_hash_handle *)((char *)v54 + v38->hh.tbl->hho);
        }
        else
        {
          v140 = v38->hh.tbl->hho;
          if ( (char *)*(void **)((char *)&v48[3].prev - v140) - (char *)*(void **)((char *)&v41[3].prev - v140) > 0 )
          {
            v141 = v41->next;
            v51 = (int)v141 + v140;
            if ( !v141 )
            {
              v51 = 0;
              --v47;
              if ( !v42 )
                goto LABEL_156;
              goto LABEL_35;
            }
LABEL_34:
            --v47;
            if ( !v42 )
            {
LABEL_156:
              v42 = v41;
              v41 = (UT_hash_handle *)v51;
              goto LABEL_157;
            }
LABEL_35:
            v42->next = (char *)v41 - v38->hh.tbl->hho;
            if ( v41 )
            {
LABEL_36:
              v52 = (char *)v42 - v38->hh.tbl->hho;
              v42 = v41;
              v41 = (UT_hash_handle *)v51;
              goto LABEL_37;
            }
            v42 = 0;
            v41 = (UT_hash_handle *)v51;
            continue;
          }
          if ( !v48 )
          {
LABEL_161:
            v54 = v48;
            goto LABEL_45;
          }
          v142 = (char *)v48->next;
          v54 = (UT_hash_handle *)&v142[v140];
          if ( !v142 )
            v54 = 0;
        }
LABEL_45:
        --v46;
        if ( v42 )
        {
          if ( v48 )
          {
            v51 = (int)v41;
            v41 = v48;
            v156 = (char *)v48 - v38->hh.tbl->hho;
            v48 = v54;
            v42->next = v156;
            goto LABEL_36;
          }
          v42->next = 0;
          v42 = 0;
          v48 = v54;
          continue;
        }
        v42 = v48;
        v48 = v54;
LABEL_157:
        v39 = v42;
        v52 = 0;
        if ( !v42 )
          continue;
LABEL_37:
        v42->prev = v52;
      }
      v49 = v47 == 0;
      if ( v47 )
        v49 = v41 == 0;
      if ( !v49 )
      {
        v50 = v41->next;
        if ( v50 )
          v51 = (int)v50 + v38->hh.tbl->hho;
        else
          v51 = v46;
        goto LABEL_34;
      }
    }
    while ( v41 );
    if ( v42 )
      v42->next = 0;
    if ( v43 > 1 )
    {
      v40 *= 2;
      if ( !v39 )
      {
        v42 = 0;
        break;
      }
      continue;
    }
    break;
  }
  v38->hh.tbl->tail = v42;
  v143 = (block *)((char *)v39 - v38->hh.tbl->hho);
  prev = (char *)v143->hh.prev;
  blocks = v143;
  block_no = v143->block_no;
  if ( !prev )
  {
    v148 = (block *)v143->hh.next;
    v145 = v143->hh.tbl;
    if ( !v148 )
    {
      buckets = v145->buckets;
      v38 = 0;
      free(buckets);
      free(v143->hh.tbl);
      blocks = 0;
      goto LABEL_183;
    }
    v147 = v145->hho;
    v146 = &v143->hh;
    if ( v143 == (block *)((char *)v145->tail - v147) )
      goto LABEL_238;
LABEL_242:
    v38 = v148;
    blocks = v148;
    goto LABEL_174;
  }
  v145 = v143->hh.tbl;
  v146 = &v143->hh;
  v147 = v145->hho;
  if ( v143 != (block *)((char *)v145->tail - v147) )
    goto LABEL_173;
LABEL_238:
  v145->tail = (UT_hash_handle *)&prev[v147];
  prev = (char *)v143->hh.prev;
  if ( !prev )
  {
    v148 = (block *)v143->hh.next;
    goto LABEL_242;
  }
  v147 = v143->hh.tbl->hho;
LABEL_173:
  v38 = v143;
  *(_DWORD *)&prev[v147 + 8] = v143->hh.next;
  v148 = (block *)v143->hh.next;
LABEL_174:
  v149 = v38->hh.tbl;
  if ( v148 )
  {
    *(_DWORD *)&v148->hash[v149->hho + 4] = v143->hh.prev;
    v149 = v38->hh.tbl;
  }
  v150 = (v149->num_buckets - 1) & v143->hh.hashv;
  --v149->buckets[v150].count;
  v151 = v38->hh.tbl->buckets;
  if ( v151[v150].hh_head == v146 )
    v151[v150].hh_head = v143->hh.hh_next;
  hh_next = v143->hh.hh_next;
  hh_prev = v143->hh.hh_prev;
  if ( hh_prev )
  {
    hh_prev->hh_next = hh_next;
    hh_next = v143->hh.hh_next;
  }
  if ( hh_next )
    hh_next->hh_prev = v143->hh.hh_prev;
  --v38->hh.tbl->num_items;
LABEL_183:
  free(v143);
  v36->hh.key = v36;
  v36->hh.next = 0;
  v36->hh.keylen = strlen(v36->hash);
  if ( v38 )
    goto LABEL_81;
LABEL_184:
  v36->hh.prev = 0;
  blocks = v36;
  v154 = (UT_hash_table *)malloc(0x2Cu);
  v68 = v154;
  v36->hh.tbl = v154;
  if ( !v154 )
    goto LABEL_256;
  memset(&v154->num_items, 0, 0x20u);
  p_hh = &v36->hh;
  v68->tail = &v36->hh;
  v68->num_buckets = 32;
  v68->log2_num_buckets = 5;
  v68->hho = 68;
  v155 = (UT_hash_bucket *)calloc(0x180u, 1u);
  v68->buckets = v155;
  if ( !v155 )
    goto LABEL_256;
  v38 = v36;
  v68->signature = -1609490463;
LABEL_82:
  v69 = -17973521;
  v70 = -1640531527;
  ++v68->num_items;
  v71 = v38->hh.tbl;
  v36->hh.hashv = -17973521;
  v36->hh.tbl = v71;
  v72 = strlen(v36->hash);
  v73 = v72;
  if ( v72 <= 0xB )
  {
    v75 = -1640531527;
    v79 = (unsigned __int8 *)v36;
  }
  else
  {
    v74 = (unsigned __int8 *)&v36->hash[12];
    v75 = -1640531527;
    do
    {
      v76 = *(v74 - 2);
      v73 -= 12;
      v77 = *(v74 - 3);
      v78 = *(v74 - 6);
      v79 = v74;
      v80 = *(v74 - 7);
      v74 += 12;
      v81 = (v76 << 16) + (v77 << 8) + *(v74 - 16) + (*(v74 - 13) << 24) + v69;
      v82 = (v78 << 16) + (v80 << 8) + *(v74 - 20) + (*(v74 - 17) << 24) + v70;
      v83 = ((*(v74 - 22) << 16) + (*(v74 - 23) << 8) + *(v74 - 24) + (*(v74 - 21) << 24) - v81 - v82 + v75)
          ^ (v81 >> 13);
      v84 = (v82 - v81 - v83) ^ (v83 << 8);
      v85 = (v81 - v83 - v84) ^ (v84 >> 13);
      v86 = (v83 - v84 - v85) ^ (v85 >> 12);
      v87 = (v84 - v85 - v86) ^ (v86 << 16);
      v88 = (v85 - v86 - v87) ^ (v87 >> 5);
      v75 = (v86 - v87 - v88) ^ (v88 >> 3);
      v70 = (v87 - v88 - v75) ^ (v75 << 10);
      v69 = (v88 - v75 - v70) ^ (v70 >> 15);
      v36->hh.hashv = v69;
    }
    while ( v73 > 0xB );
    v72 = strlen(v36->hash);
  }
  v89 = v69 + v72;
  v36->hh.hashv = v89;
  switch ( v73 )
  {
    case 1u:
      goto LABEL_97;
    case 2u:
      goto LABEL_96;
    case 3u:
      goto LABEL_95;
    case 4u:
      goto LABEL_94;
    case 5u:
      goto LABEL_93;
    case 6u:
      goto LABEL_92;
    case 7u:
      goto LABEL_91;
    case 8u:
      goto LABEL_90;
    case 9u:
      goto LABEL_89;
    case 0xAu:
      goto LABEL_88;
    case 0xBu:
      v89 += v79[10] << 24;
      v36->hh.hashv = v89;
LABEL_88:
      v89 += v79[9] << 16;
      v36->hh.hashv = v89;
LABEL_89:
      v89 += v79[8] << 8;
      v36->hh.hashv = v89;
LABEL_90:
      v70 += v79[7] << 24;
LABEL_91:
      v70 += v79[6] << 16;
LABEL_92:
      v70 += v79[5] << 8;
LABEL_93:
      v70 += v79[4];
LABEL_94:
      v75 += v79[3] << 24;
LABEL_95:
      v75 += v79[2] << 16;
LABEL_96:
      v75 += v79[1] << 8;
LABEL_97:
      v75 += *v79;
      break;
    default:
      break;
  }
  v90 = (v75 - v70 - v89) ^ (v89 >> 13);
  v91 = (v70 - v89 - v90) ^ (v90 << 8);
  v92 = (v89 - v90 - v91) ^ (v91 >> 13);
  v93 = (v90 - v91 - v92) ^ (v92 >> 12);
  v94 = (v91 - v92 - v93) ^ (v93 << 16);
  v95 = (v92 - v93 - v94) ^ (v94 >> 5);
  v96 = (v93 - v94 - v95) ^ (v95 >> 3);
  v97 = (v95 - v96 - ((v94 - v95 - v96) ^ (v96 << 10))) ^ (((v94 - v95 - v96) ^ (v96 << 10)) >> 15);
  v36->hh.hashv = v97;
  v98 = v97 & (v38->hh.tbl->num_buckets - 1);
  ++v38->hh.tbl->buckets[v98].count;
  v99 = v38->hh.tbl->buckets[v98].hh_head;
  v36->hh.hh_prev = 0;
  v36->hh.hh_next = v99;
  v100 = v38->hh.tbl->buckets;
  v101 = v100[v98].hh_head;
  v102 = &v100[v98];
  if ( v101 )
  {
    v101->hh_prev = p_hh;
    v102 = &v38->hh.tbl->buckets[v98];
  }
  v102->hh_head = p_hh;
  v103 = *(_QWORD *)&v38->hh.tbl->buckets[v98].count;
  if ( (unsigned int)v103 >= 10 * (HIDWORD(v103) + 1) )
  {
    v104 = v36->hh.tbl;
    if ( v104->noexpand != 1 )
    {
      v105 = (UT_hash_bucket *)calloc(24 * v104->num_buckets, 1u);
      if ( v105 )
      {
        num_items = v104->num_items;
        v107 = num_items >> (*(_QWORD *)&v104->log2_num_buckets + 1);
        if ( ((2 * v104->num_buckets - 1) & num_items) != 0 )
          ++v107;
        v104->ideal_chain_maxlen = v107;
        v36->hh.tbl->nonideal_items = 0;
        v108 = v36->hh.tbl;
        num_buckets = v108->num_buckets;
        if ( num_buckets )
        {
          v110 = 0;
          for ( i = 0; i < num_buckets; ++i )
          {
            v111 = v108->buckets[v110].hh_head;
            if ( v111 )
            {
              while ( 1 )
              {
                v112 = v111->hh_next;
                v113 = (2 * num_buckets - 1) & v111->hashv;
                v114 = &v105[v113];
                v115 = v114->count + 1;
                v114->count = v115;
                if ( v115 > v108->ideal_chain_maxlen )
                {
                  ++v108->nonideal_items;
                  v114->expand_mult = v114->count / v36->hh.tbl->ideal_chain_maxlen;
                }
                v111->hh_prev = 0;
                v111->hh_next = v105[v113].hh_head;
                v116 = v105[v113].hh_head;
                if ( v116 )
                  v116->hh_prev = v111;
                v105[v113].hh_head = v111;
                v108 = v36->hh.tbl;
                if ( !v112 )
                  break;
                num_buckets = v108->num_buckets;
                v111 = v112;
              }
              num_buckets = v108->num_buckets;
            }
            ++v110;
          }
        }
        free(v108->buckets);
        v36->hh.tbl->num_buckets *= 2;
        ++v36->hh.tbl->log2_num_buckets;
        v36->hh.tbl->buckets = v105;
        v117 = v36->hh.tbl;
        nonideal_items = v117->nonideal_items;
        v119 = v117->num_items;
        v120 = nonideal_items > v119 >> 1;
        if ( nonideal_items <= v119 >> 1 )
          ineff_expands = 0;
        else
          ineff_expands = v117->ineff_expands;
        if ( v120 )
          ++ineff_expands;
        v117->ineff_expands = ineff_expands;
        v122 = v36->hh.tbl;
        if ( v122->ineff_expands > 1 )
          v122->noexpand = 1;
        goto LABEL_124;
      }
LABEL_256:
      exit(-1);
    }
  }
LABEL_124:
  v123 = 8 * (29 - *(_BYTE *)(a1 + 72));
  LODWORD(v124) = 0xFFFF << v123;
  HIDWORD(v124) = (0xFFFF << (v123 - 32)) | (0xFFFFu >> (32 - v123));
  v125 = (double)v124 / (double)(bswap32(*(_DWORD *)(a1 + 72)) & 0xFFFFFF);
  if ( v125 != current_diff )
  {
    suffix_string((unsigned __int64)v125, block_diff, 8u, 0);
    current_diff = v125;
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v204) = 4040;
      HIWORD(v204) = (unsigned int)"g DEAD!" >> 16;
      snprintf((char *)&str, 0x1000u, v204, block_diff);
      applog(7, (const char *)&str, 0);
    }
  }
  if ( pthread_rwlock_unlock(&blk_lock) )
  {
    v205 = _errno_location();
    LOWORD(v206) = -348;
    LOWORD(v207) = -3136;
    HIWORD(v206) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
    HIWORD(v207) = (unsigned int)"iner" >> 16;
    snprintf((char *)&str, 0x1000u, v206, *v205, v207, "test_work_current", 5430);
    goto LABEL_12;
  }
  selective_yield();
  if ( block_no && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v126) = 4064;
    HIWORD(v126) = (unsigned int)"k_current OOM" >> 16;
    snprintf((char *)&str, 0x1000u, v126, block_no);
    applog(7, (const char *)&str, 0);
  }
  if ( pthread_mutex_lock(&ch_lock.mutex) )
  {
    v208 = _errno_location();
    LOWORD(v209) = -3136;
    LOWORD(v210) = -968;
    HIWORD(v209) = (unsigned int)"iner" >> 16;
    HIWORD(v210) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf((char *)&str, 0x1000u, v210, *v208, v209, "set_curblock", 5324);
    goto LABEL_12;
  }
  if ( pthread_rwlock_wrlock(&ch_lock.rwlock) )
  {
    v214 = _errno_location();
    LOWORD(v215) = -3136;
    LOWORD(v216) = -1020;
    HIWORD(v215) = (unsigned int)"iner" >> 16;
    HIWORD(v216) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
    snprintf((char *)&str, 0x1000u, v216, *v214, v215, "set_curblock", 5324);
    goto LABEL_12;
  }
  cgtime(&block_timeval);
  strcpy(current_hash, s);
  str = block_timeval.tv_sec;
  *(_DWORD *)current_block = v227;
  *(_DWORD *)&current_block[4] = v228;
  *(_DWORD *)&current_block[8] = v229;
  *(_DWORD *)&current_block[12] = v230;
  *(_DWORD *)&current_block[16] = v231;
  *(_DWORD *)&current_block[20] = v232;
  *(_DWORD *)&current_block[24] = v233;
  *(_DWORD *)&current_block[28] = v234;
  v127 = localtime(&str);
  LOWORD(v128) = 4096;
  HIWORD(v128) = (unsigned int)" to %s" >> 16;
  snprintf(blocktime, 0x20u, v128, v127->tm_hour, v127->tm_min, v127->tm_sec);
  if ( pthread_rwlock_unlock(&ch_lock.rwlock) )
  {
    v211 = _errno_location();
    LOWORD(v212) = -3136;
    LOWORD(v213) = -348;
    HIWORD(v212) = (unsigned int)"iner" >> 16;
    HIWORD(v213) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
    snprintf((char *)&str, 0x1000u, v213, *v211, v212, "set_curblock", 5329);
    goto LABEL_12;
  }
  v129 = pthread_mutex_unlock(&ch_lock.mutex);
  if ( v129 )
  {
    v217 = _errno_location();
    LOWORD(v218) = -3136;
    LOWORD(v219) = -920;
    HIWORD(v218) = (unsigned int)"iner" >> 16;
    HIWORD(v219) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf((char *)&str, 0x1000u, v219, *v217, v218, "set_curblock", 5329);
LABEL_12:
    applog(3, (const char *)&str, 1);
    _quit(1, 1);
  }
  selective_yield();
  v130 = current_hash;
  do
  {
    v131 = (unsigned __int8)*v130++;
    if ( v131 != 48 )
      break;
    ++v129;
  }
  while ( v129 != 57 );
  strncpy(prev_block, &current_hash[v129], 8u);
  prev_block[8] = 0;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v132) = 4116;
    HIWORD(v132) = (unsigned int)"k %d from database" >> 16;
    snprintf((char *)&str, 0x1000u, v132, current_hash, block_diff);
    applog(7, (const char *)&str, 0);
  }
  v133 = v228;
  v134 = v229;
  v135 = v230;
  v49 = new_blocks == 1;
  v223[142] = v227;
  v223[143] = v133;
  v223[144] = v134;
  v223[145] = v135;
  v136 = v232;
  v137 = v233;
  v138 = v234;
  v223[146] = v231;
  v223[147] = v136;
  v223[148] = v137;
  v223[149] = v138;
  if ( !v49 )
  {
    v139 = *(unsigned __int8 *)(a1 + 1768);
    *(_DWORD *)(a1 + 1824) = ++work_block;
    if ( v139 )
    {
      if ( *(_BYTE *)(a1 + 1772) )
      {
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf((char *)&str, 0x1000u, "Stratum from pool %d detected new block", *v223);
          applog(7, (const char *)&str, 0);
        }
      }
      else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        v179 = &byte_59414;
        LOWORD(v180) = 4184;
        if ( *(_BYTE *)(a1 + 1812) )
          v179 = "GBT ";
        HIWORD(v180) = (unsigned int)"Stratum from pool %d detected new block" >> 16;
        snprintf((char *)&str, 0x1000u, v180, v179, **(_DWORD **)(a1 + 1748));
        applog(7, (const char *)&str, 0);
      }
    }
    else if ( have_longpoll )
    {
      if ( !*((_BYTE *)v223 + 924) && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v181) = 4228;
        HIWORD(v181) = (unsigned int)"NGPOLL from pool %d detected new block" >> 16;
        v182 = *v181;
        v183 = v181[1];
        v184 = v181[2];
        v185 = v181[3];
        v181 += 4;
        str = v182;
        v238 = v183;
        v239 = v184;
        v240 = v185;
        v186 = *v181;
        v187 = v181[1];
        v188 = v181[2];
        v189 = v181[3];
        v181 += 4;
        v241 = v186;
        v242 = v187;
        v243 = v188;
        v244 = v189;
        v190 = *v181;
        v191 = v181[1];
        v192 = v181[2];
        v193 = v181[3];
        v181 += 4;
        v245 = v190;
        v246 = v191;
        v247 = v192;
        v248 = v193;
        v194 = v181[1];
        v249 = *v181;
        v250 = v194;
        v251 = BYTE2(v194);
        applog(7, (const char *)&str, 0);
      }
    }
    else if ( !*((_BYTE *)v223 + 924) && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v171) = 4284;
      HIWORD(v171) = (unsigned int)"ed on network before pool notification" >> 16;
      v172 = *v171;
      v173 = v171[1];
      v174 = v171[2];
      v175 = v171[3];
      v171 += 4;
      str = v172;
      v238 = v173;
      v239 = v174;
      v240 = v175;
      v176 = v171[1];
      v177 = v171[2];
      v178 = v171[3];
      v241 = *v171;
      v242 = v176;
      v243 = v177;
      LOWORD(v244) = v178;
      applog(7, (const char *)&str, 0);
    }
    restart_threads();
    v221 = 1;
  }
out:
  *(_BYTE *)(a1 + 1768) = 0;
  return v221;
}
