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
  char *v33; // r0
  block *v34; // r11
  unsigned int v35; // r3
  block *v36; // r5
  UT_hash_handle *v37; // lr
  int v38; // r7
  UT_hash_handle *v39; // r3
  UT_hash_handle *v40; // r2
  unsigned int v41; // r12
  UT_hash_handle *next; // r6
  ptrdiff_t hho; // r4
  int v44; // r1
  int v45; // r0
  UT_hash_handle *v46; // r4
  bool v47; // zf
  void *v48; // r8
  int v49; // r8
  char *v50; // r6
  bool v51; // zf
  UT_hash_handle *v52; // r9
  int v53; // r2
  UT_hash_table *tbl; // r0
  int v55; // r2
  unsigned int v56; // r3
  unsigned int v57; // r5
  int v58; // r4
  unsigned int v59; // r3
  unsigned int v60; // r5
  int v61; // r4
  UT_hash_handle *hh_head; // r4
  int v63; // r5
  char *v64; // r4
  _BOOL4 v65; // r3
  UT_hash_table *v66; // r4
  int v67; // r7
  unsigned int v68; // r6
  UT_hash_table *v69; // r3
  size_t v70; // r0
  unsigned int v71; // r9
  unsigned __int8 *v72; // r10
  int v73; // r4
  int v74; // r1
  int v75; // r0
  int v76; // r3
  unsigned __int8 *v77; // r8
  int v78; // r12
  unsigned int v79; // r1
  unsigned int v80; // r3
  int v81; // r2
  unsigned int v82; // r3
  unsigned int v83; // r1
  int v84; // r2
  unsigned int v85; // r3
  unsigned int v86; // r1
  unsigned int v87; // r7
  int v88; // r3
  unsigned int v89; // r6
  unsigned int v90; // r7
  int v91; // r3
  unsigned int v92; // r6
  unsigned int v93; // r7
  int v94; // r3
  unsigned int v95; // r3
  int v96; // r3
  UT_hash_handle *v97; // r2
  UT_hash_bucket *v98; // r2
  UT_hash_handle *v99; // r1
  UT_hash_bucket *v100; // r2
  __int64 v101; // r2
  UT_hash_table *v102; // r4
  UT_hash_bucket *v103; // r6
  unsigned int num_items; // r0
  unsigned int v105; // r3
  UT_hash_table *v106; // r3
  unsigned int num_buckets; // r4
  int v108; // r8
  UT_hash_handle *v109; // r5
  UT_hash_handle *v110; // r7
  int v111; // r4
  UT_hash_bucket *v112; // r9
  unsigned int v113; // r1
  UT_hash_handle *v114; // r3
  UT_hash_table *v115; // r3
  unsigned int nonideal_items; // r2
  unsigned int v117; // r1
  bool v118; // cc
  unsigned int ineff_expands; // r2
  UT_hash_table *v120; // r3
  char v121; // r3
  unsigned __int64 v122; // r0
  double v123; // d8
  struct tm *v124; // r0
  int v125; // r7
  char *v126; // r3
  int v127; // t1
  int v128; // r1
  int v129; // r2
  int v130; // r3
  int v131; // r1
  int v132; // r2
  int v133; // r3
  int v134; // r1
  ptrdiff_t v135; // r9
  void *v136; // r6
  char *v137; // r6
  block *v138; // r4
  char *prev; // r0
  UT_hash_table *v140; // r5
  UT_hash_handle *v141; // r2
  ptrdiff_t v142; // r1
  block *v143; // r6
  UT_hash_table *v144; // r0
  int v145; // r1
  UT_hash_bucket *v146; // r0
  UT_hash_handle *hh_next; // r2
  UT_hash_handle *hh_prev; // r3
  UT_hash_table *v149; // r0
  UT_hash_bucket *v150; // r0
  char *v151; // r6
  int v152; // r0
  int v153; // r1
  int v154; // r2
  int v155; // r3
  int v156; // r1
  int v157; // r2
  int v158; // r3
  pool *v159; // r4
  int *v160; // r0
  char *v161; // r3
  char *v162; // r3
  int *v163; // r0
  int *v164; // r0
  int *v165; // r0
  int *v166; // r0
  int *v167; // r0
  int *v168; // r0
  UT_hash_bucket *buckets; // r0
  int v170; // [sp+14h] [bp-1090h]
  _DWORD *v172; // [sp+24h] [bp-1080h]
  UT_hash_handle *p_hh; // [sp+28h] [bp-107Ch]
  unsigned int i; // [sp+28h] [bp-107Ch]
  int block_no; // [sp+2Ch] [bp-1078h]
  int v176; // [sp+3Ch] [bp-1068h] BYREF
  int v177; // [sp+40h] [bp-1064h]
  int v178; // [sp+44h] [bp-1060h]
  int v179; // [sp+48h] [bp-105Ch]
  int v180; // [sp+4Ch] [bp-1058h]
  int v181; // [sp+50h] [bp-1054h]
  int v182; // [sp+54h] [bp-1050h]
  int v183; // [sp+58h] [bp-104Ch]
  char s[12]; // [sp+5Ch] [bp-1048h] BYREF
  char v185; // [sp+68h] [bp-103Ch] BYREF
  time_t str[1025]; // [sp+A0h] [bp-1004h] BYREF

  v170 = *(unsigned __int8 *)(a1 + 1770);
  if ( *(_BYTE *)(a1 + 1770) )
    return v170;
  v3 = *(_DWORD *)(a1 + 32);
  v177 = *(_DWORD *)(a1 + 28);
  v4 = *(_DWORD *)(a1 + 12);
  v180 = *(_DWORD *)(a1 + 16);
  v5 = *(_DWORD *)(a1 + 8);
  v6 = *(_DWORD *)(a1 + 20);
  v181 = v4;
  v7 = *(_DWORD *)(a1 + 24);
  v8 = *(_DWORD *)(a1 + 4);
  v182 = v5;
  v9 = *(_DWORD **)(a1 + 1748);
  v176 = v3;
  v178 = v7;
  v179 = v6;
  v183 = v8;
  v172 = v9;
  _bin2hex(s, (const unsigned __int8 *)&v176, 0x20u);
  if ( pthread_rwlock_rdlock(&blk_lock) )
  {
    v160 = _errno_location();
    snprintf(
      (char *)str,
      0x1000u,
      "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v160,
      "cgminer.c",
      "block_exists",
      5347);
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
      v14 = (unsigned __int8 *)&v185;
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
    v53 = v15 - v12;
    tbl = blocks->hh.tbl;
    v55 = (v53 - v31) ^ (v31 >> 13);
    v56 = (v12 - v31 - v55) ^ (v55 << 8);
    v57 = (v31 - v55 - v56) ^ (v56 >> 13);
    v58 = (v55 - v56 - v57) ^ (v57 >> 12);
    v59 = (v56 - v57 - v58) ^ (v58 << 16);
    v60 = (v57 - v58 - v59) ^ (v59 >> 5);
    v61 = (v58 - v59 - v60) ^ (v60 >> 3);
    hh_head = tbl->buckets[(tbl->num_buckets - 1)
                         & ((v60 - v61 - ((v59 - v60 - v61) ^ (v61 << 10)))
                          ^ (((v59 - v60 - v61) ^ (v61 << 10)) >> 15))].hh_head;
    if ( hh_head )
    {
      v63 = -tbl->hho;
      while ( 1 )
      {
        v64 = (char *)hh_head + v63;
        if ( !v64 )
          goto LABEL_10;
        if ( v13 == *((_DWORD *)v64 + 23) && !memcmp(*((const void **)v64 + 22), s, v13) )
          break;
        hh_head = (UT_hash_handle *)*((_DWORD *)v64 + 21);
        if ( !hh_head )
          goto LABEL_10;
      }
      if ( !pthread_rwlock_unlock(&blk_lock) )
      {
        selective_yield();
        if ( !memcmp(v172 + 142, &v176, 0x20u) )
        {
          v65 = 1;
        }
        else
        {
          v152 = memcmp(&v176, current_block, 0x20u);
          v65 = opt_debug;
          if ( !v152 )
          {
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              snprintf((char *)str, 0x1000u, "Pool %d now up to date", *v172);
              applog(7, (const char *)str, 0);
            }
            v170 = 1;
            v153 = v177;
            v154 = v178;
            v155 = v179;
            v172[142] = v176;
            v172[143] = v153;
            v172[144] = v154;
            v172[145] = v155;
            v156 = v181;
            v157 = v182;
            v158 = v183;
            v172[146] = v180;
            v172[147] = v156;
            v172[148] = v157;
            v172[149] = v158;
            goto LABEL_69;
          }
          if ( opt_debug )
          {
            if ( use_syslog || opt_log_output || opt_log_level > 6 )
            {
              snprintf((char *)str, 0x1000u, "Stale data from pool %d", *v172);
              applog(7, (const char *)str, 0);
            }
            else
            {
              v170 = opt_log_output;
            }
LABEL_69:
            if ( *(_BYTE *)(a1 + 1768) )
            {
              v118 = (unsigned int)(pool_strategy_0 - 3) > 1;
              *(_DWORD *)(a1 + 1824) = ++work_block;
              if ( !v118 || (v159 = *(pool **)(a1 + 1748), v159 == current_pool()) )
              {
                if ( *(_BYTE *)(a1 + 1772) )
                {
                  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                  {
                    snprintf((char *)str, 0x1000u, "Stratum from pool %d requested work restart", *v172);
                    applog(7, (const char *)str, 0);
                  }
                }
                else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  v161 = &byte_59398;
                  if ( *(_BYTE *)(a1 + 1812) )
                    v161 = "GBT ";
                  snprintf(
                    (char *)str,
                    0x1000u,
                    "%sLONGPOLL from pool %d requested work restart",
                    v161,
                    **(_DWORD **)(a1 + 1748));
                  applog(7, (const char *)str, 0);
                }
                restart_threads();
              }
            }
            goto out;
          }
        }
        v170 = v65;
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
    snprintf(
      (char *)str,
      0x1000u,
      "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v32,
      "cgminer.c",
      "block_exists",
      5349);
    goto LABEL_12;
  }
  selective_yield();
  v33 = (char *)calloc(0x68u, 1u);
  v34 = (block *)v33;
  if ( !v33 )
  {
    strcpy((char *)str, "test_work_current OOM");
    applog(3, (const char *)str, 1);
    _quit(1, 1);
  }
  strcpy(v33, s);
  v35 = new_blocks;
  v34->block_no = new_blocks;
  new_blocks = v35 + 1;
  block_no = pthread_rwlock_wrlock(&blk_lock);
  if ( block_no )
  {
    v163 = _errno_location();
    snprintf(
      (char *)str,
      0x1000u,
      "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v163,
      "cgminer.c",
      "test_work_current",
      5414);
    goto LABEL_12;
  }
  v36 = blocks;
  if ( !blocks )
  {
    v34->hh.key = v34;
    v34->hh.next = 0;
    v34->hh.keylen = strlen(v34->hash);
    goto LABEL_184;
  }
  if ( blocks->hh.tbl->num_items <= 6 )
  {
    v34->hh.key = v34;
    v34->hh.next = 0;
    v34->hh.keylen = strlen(v34->hash);
LABEL_81:
    p_hh = &v34->hh;
    v36->hh.tbl->tail->next = v34;
    v34->hh.prev = (char *)v36->hh.tbl->tail - v36->hh.tbl->hho;
    v36->hh.tbl->tail = &v34->hh;
    v66 = v36->hh.tbl;
    goto LABEL_82;
  }
  v37 = &blocks->hh;
  v38 = 1;
  while ( 2 )
  {
    v39 = v37;
    v37 = 0;
    v40 = 0;
    v41 = 0;
    do
    {
      ++v41;
      if ( v38 )
      {
        next = (UT_hash_handle *)v39->next;
        if ( next && (hho = v36->hh.tbl->hho, (next = (UT_hash_handle *)((char *)next + hho)) != 0) )
        {
          v44 = 1;
          do
          {
            if ( v44 == v38 )
            {
              v45 = v44;
              goto LABEL_27;
            }
            next = (UT_hash_handle *)next->next;
            ++v44;
            if ( !next )
              break;
            next = (UT_hash_handle *)((char *)next + hho);
          }
          while ( next );
          v45 = v38;
        }
        else
        {
          v45 = v38;
          v44 = 1;
        }
      }
      else
      {
        next = v39;
        v45 = 0;
        v44 = 0;
      }
LABEL_27:
      v46 = v39;
      v39 = next;
      while ( v44 )
      {
        v51 = v39 == 0;
        if ( v39 )
          v51 = v45 == 0;
        if ( v51 )
        {
          if ( !v46 )
            goto LABEL_161;
          v52 = (UT_hash_handle *)v46->next;
          if ( v52 )
            v52 = (UT_hash_handle *)((char *)v52 + v36->hh.tbl->hho);
        }
        else
        {
          v135 = v36->hh.tbl->hho;
          if ( (char *)*(void **)((char *)&v46[3].prev - v135) - (char *)*(void **)((char *)&v39[3].prev - v135) > 0 )
          {
            v136 = v39->next;
            v49 = (int)v136 + v135;
            if ( !v136 )
            {
              v49 = 0;
              --v45;
              if ( !v40 )
                goto LABEL_156;
              goto LABEL_35;
            }
LABEL_34:
            --v45;
            if ( !v40 )
            {
LABEL_156:
              v40 = v39;
              v39 = (UT_hash_handle *)v49;
              goto LABEL_157;
            }
LABEL_35:
            v40->next = (char *)v39 - v36->hh.tbl->hho;
            if ( v39 )
            {
LABEL_36:
              v50 = (char *)v40 - v36->hh.tbl->hho;
              v40 = v39;
              v39 = (UT_hash_handle *)v49;
              goto LABEL_37;
            }
            v40 = 0;
            v39 = (UT_hash_handle *)v49;
            continue;
          }
          if ( !v46 )
          {
LABEL_161:
            v52 = v46;
            goto LABEL_45;
          }
          v137 = (char *)v46->next;
          v52 = (UT_hash_handle *)&v137[v135];
          if ( !v137 )
            v52 = 0;
        }
LABEL_45:
        --v44;
        if ( v40 )
        {
          if ( v46 )
          {
            v49 = (int)v39;
            v39 = v46;
            v151 = (char *)v46 - v36->hh.tbl->hho;
            v46 = v52;
            v40->next = v151;
            goto LABEL_36;
          }
          v40->next = 0;
          v40 = 0;
          v46 = v52;
          continue;
        }
        v40 = v46;
        v46 = v52;
LABEL_157:
        v37 = v40;
        v50 = 0;
        if ( !v40 )
          continue;
LABEL_37:
        v40->prev = v50;
      }
      v47 = v45 == 0;
      if ( v45 )
        v47 = v39 == 0;
      if ( !v47 )
      {
        v48 = v39->next;
        if ( v48 )
          v49 = (int)v48 + v36->hh.tbl->hho;
        else
          v49 = v44;
        goto LABEL_34;
      }
    }
    while ( v39 );
    if ( v40 )
      v40->next = 0;
    if ( v41 > 1 )
    {
      v38 *= 2;
      if ( !v37 )
      {
        v40 = 0;
        break;
      }
      continue;
    }
    break;
  }
  v36->hh.tbl->tail = v40;
  v138 = (block *)((char *)v37 - v36->hh.tbl->hho);
  prev = (char *)v138->hh.prev;
  blocks = v138;
  block_no = v138->block_no;
  if ( !prev )
  {
    v143 = (block *)v138->hh.next;
    v140 = v138->hh.tbl;
    if ( !v143 )
    {
      buckets = v140->buckets;
      v36 = 0;
      free(buckets);
      free(v138->hh.tbl);
      blocks = 0;
      goto LABEL_183;
    }
    v142 = v140->hho;
    v141 = &v138->hh;
    if ( v138 == (block *)((char *)v140->tail - v142) )
      goto LABEL_238;
LABEL_242:
    v36 = v143;
    blocks = v143;
    goto LABEL_174;
  }
  v140 = v138->hh.tbl;
  v141 = &v138->hh;
  v142 = v140->hho;
  if ( v138 != (block *)((char *)v140->tail - v142) )
    goto LABEL_173;
LABEL_238:
  v140->tail = (UT_hash_handle *)&prev[v142];
  prev = (char *)v138->hh.prev;
  if ( !prev )
  {
    v143 = (block *)v138->hh.next;
    goto LABEL_242;
  }
  v142 = v138->hh.tbl->hho;
LABEL_173:
  v36 = v138;
  *(_DWORD *)&prev[v142 + 8] = v138->hh.next;
  v143 = (block *)v138->hh.next;
LABEL_174:
  v144 = v36->hh.tbl;
  if ( v143 )
  {
    *(_DWORD *)&v143->hash[v144->hho + 4] = v138->hh.prev;
    v144 = v36->hh.tbl;
  }
  v145 = (v144->num_buckets - 1) & v138->hh.hashv;
  --v144->buckets[v145].count;
  v146 = v36->hh.tbl->buckets;
  if ( v146[v145].hh_head == v141 )
    v146[v145].hh_head = v138->hh.hh_next;
  hh_next = v138->hh.hh_next;
  hh_prev = v138->hh.hh_prev;
  if ( hh_prev )
  {
    hh_prev->hh_next = hh_next;
    hh_next = v138->hh.hh_next;
  }
  if ( hh_next )
    hh_next->hh_prev = v138->hh.hh_prev;
  --v36->hh.tbl->num_items;
LABEL_183:
  free(v138);
  v34->hh.key = v34;
  v34->hh.next = 0;
  v34->hh.keylen = strlen(v34->hash);
  if ( v36 )
    goto LABEL_81;
LABEL_184:
  v34->hh.prev = 0;
  blocks = v34;
  v149 = (UT_hash_table *)malloc(0x2Cu);
  v66 = v149;
  v34->hh.tbl = v149;
  if ( !v149 )
    goto LABEL_256;
  memset(&v149->num_items, 0, 0x20u);
  p_hh = &v34->hh;
  v66->tail = &v34->hh;
  v66->num_buckets = 32;
  v66->log2_num_buckets = 5;
  v66->hho = 68;
  v150 = (UT_hash_bucket *)calloc(0x180u, 1u);
  v66->buckets = v150;
  if ( !v150 )
    goto LABEL_256;
  v36 = v34;
  v66->signature = -1609490463;
LABEL_82:
  v67 = -17973521;
  v68 = -1640531527;
  ++v66->num_items;
  v69 = v36->hh.tbl;
  v34->hh.hashv = -17973521;
  v34->hh.tbl = v69;
  v70 = strlen(v34->hash);
  v71 = v70;
  if ( v70 <= 0xB )
  {
    v73 = -1640531527;
    v77 = (unsigned __int8 *)v34;
  }
  else
  {
    v72 = (unsigned __int8 *)&v34->hash[12];
    v73 = -1640531527;
    do
    {
      v74 = *(v72 - 2);
      v71 -= 12;
      v75 = *(v72 - 3);
      v76 = *(v72 - 6);
      v77 = v72;
      v78 = *(v72 - 7);
      v72 += 12;
      v79 = (v74 << 16) + (v75 << 8) + *(v72 - 16) + (*(v72 - 13) << 24) + v67;
      v80 = (v76 << 16) + (v78 << 8) + *(v72 - 20) + (*(v72 - 17) << 24) + v68;
      v81 = ((*(v72 - 22) << 16) + (*(v72 - 23) << 8) + *(v72 - 24) + (*(v72 - 21) << 24) - v79 - v80 + v73)
          ^ (v79 >> 13);
      v82 = (v80 - v79 - v81) ^ (v81 << 8);
      v83 = (v79 - v81 - v82) ^ (v82 >> 13);
      v84 = (v81 - v82 - v83) ^ (v83 >> 12);
      v85 = (v82 - v83 - v84) ^ (v84 << 16);
      v86 = (v83 - v84 - v85) ^ (v85 >> 5);
      v73 = (v84 - v85 - v86) ^ (v86 >> 3);
      v68 = (v85 - v86 - v73) ^ (v73 << 10);
      v67 = (v86 - v73 - v68) ^ (v68 >> 15);
      v34->hh.hashv = v67;
    }
    while ( v71 > 0xB );
    v70 = strlen(v34->hash);
  }
  v87 = v67 + v70;
  v34->hh.hashv = v87;
  switch ( v71 )
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
      v87 += v77[10] << 24;
      v34->hh.hashv = v87;
LABEL_88:
      v87 += v77[9] << 16;
      v34->hh.hashv = v87;
LABEL_89:
      v87 += v77[8] << 8;
      v34->hh.hashv = v87;
LABEL_90:
      v68 += v77[7] << 24;
LABEL_91:
      v68 += v77[6] << 16;
LABEL_92:
      v68 += v77[5] << 8;
LABEL_93:
      v68 += v77[4];
LABEL_94:
      v73 += v77[3] << 24;
LABEL_95:
      v73 += v77[2] << 16;
LABEL_96:
      v73 += v77[1] << 8;
LABEL_97:
      v73 += *v77;
      break;
    default:
      break;
  }
  v88 = (v73 - v68 - v87) ^ (v87 >> 13);
  v89 = (v68 - v87 - v88) ^ (v88 << 8);
  v90 = (v87 - v88 - v89) ^ (v89 >> 13);
  v91 = (v88 - v89 - v90) ^ (v90 >> 12);
  v92 = (v89 - v90 - v91) ^ (v91 << 16);
  v93 = (v90 - v91 - v92) ^ (v92 >> 5);
  v94 = (v91 - v92 - v93) ^ (v93 >> 3);
  v95 = (v93 - v94 - ((v92 - v93 - v94) ^ (v94 << 10))) ^ (((v92 - v93 - v94) ^ (v94 << 10)) >> 15);
  v34->hh.hashv = v95;
  v96 = v95 & (v36->hh.tbl->num_buckets - 1);
  ++v36->hh.tbl->buckets[v96].count;
  v97 = v36->hh.tbl->buckets[v96].hh_head;
  v34->hh.hh_prev = 0;
  v34->hh.hh_next = v97;
  v98 = v36->hh.tbl->buckets;
  v99 = v98[v96].hh_head;
  v100 = &v98[v96];
  if ( v99 )
  {
    v99->hh_prev = p_hh;
    v100 = &v36->hh.tbl->buckets[v96];
  }
  v100->hh_head = p_hh;
  v101 = *(_QWORD *)&v36->hh.tbl->buckets[v96].count;
  if ( (unsigned int)v101 >= 10 * (HIDWORD(v101) + 1) )
  {
    v102 = v34->hh.tbl;
    if ( v102->noexpand != 1 )
    {
      v103 = (UT_hash_bucket *)calloc(24 * v102->num_buckets, 1u);
      if ( v103 )
      {
        num_items = v102->num_items;
        v105 = num_items >> (*(_QWORD *)&v102->log2_num_buckets + 1);
        if ( ((2 * v102->num_buckets - 1) & num_items) != 0 )
          ++v105;
        v102->ideal_chain_maxlen = v105;
        v34->hh.tbl->nonideal_items = 0;
        v106 = v34->hh.tbl;
        num_buckets = v106->num_buckets;
        if ( num_buckets )
        {
          v108 = 0;
          for ( i = 0; i < num_buckets; ++i )
          {
            v109 = v106->buckets[v108].hh_head;
            if ( v109 )
            {
              while ( 1 )
              {
                v110 = v109->hh_next;
                v111 = (2 * num_buckets - 1) & v109->hashv;
                v112 = &v103[v111];
                v113 = v112->count + 1;
                v112->count = v113;
                if ( v113 > v106->ideal_chain_maxlen )
                {
                  ++v106->nonideal_items;
                  v112->expand_mult = v112->count / v34->hh.tbl->ideal_chain_maxlen;
                }
                v109->hh_prev = 0;
                v109->hh_next = v103[v111].hh_head;
                v114 = v103[v111].hh_head;
                if ( v114 )
                  v114->hh_prev = v109;
                v103[v111].hh_head = v109;
                v106 = v34->hh.tbl;
                if ( !v110 )
                  break;
                num_buckets = v106->num_buckets;
                v109 = v110;
              }
              num_buckets = v106->num_buckets;
            }
            ++v108;
          }
        }
        free(v106->buckets);
        v34->hh.tbl->num_buckets *= 2;
        ++v34->hh.tbl->log2_num_buckets;
        v34->hh.tbl->buckets = v103;
        v115 = v34->hh.tbl;
        nonideal_items = v115->nonideal_items;
        v117 = v115->num_items;
        v118 = nonideal_items > v117 >> 1;
        if ( nonideal_items <= v117 >> 1 )
          ineff_expands = 0;
        else
          ineff_expands = v115->ineff_expands;
        if ( v118 )
          ++ineff_expands;
        v115->ineff_expands = ineff_expands;
        v120 = v34->hh.tbl;
        if ( v120->ineff_expands > 1 )
          v120->noexpand = 1;
        goto LABEL_124;
      }
LABEL_256:
      exit(-1);
    }
  }
LABEL_124:
  v121 = 8 * (29 - *(_BYTE *)(a1 + 72));
  LODWORD(v122) = 0xFFFF << v121;
  HIDWORD(v122) = (0xFFFF << (v121 - 32)) | (0xFFFFu >> (32 - v121));
  v123 = (double)v122 / (double)(bswap32(*(_DWORD *)(a1 + 72)) & 0xFFFFFF);
  if ( v123 != current_diff )
  {
    suffix_string((unsigned __int64)v123, block_diff, 8u, 0);
    current_diff = v123;
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf((char *)str, 0x1000u, "Network diff set to %s", block_diff);
      applog(7, (const char *)str, 0);
    }
  }
  if ( pthread_rwlock_unlock(&blk_lock) )
  {
    v164 = _errno_location();
    snprintf(
      (char *)str,
      0x1000u,
      "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v164,
      "cgminer.c",
      "test_work_current",
      5430);
    goto LABEL_12;
  }
  selective_yield();
  if ( block_no && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf((char *)str, 0x1000u, "Deleted block %d from database", block_no);
    applog(7, (const char *)str, 0);
  }
  if ( pthread_mutex_lock(&ch_lock.mutex) )
  {
    v165 = _errno_location();
    snprintf(
      (char *)str,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v165,
      "cgminer.c",
      "set_curblock",
      5324);
    goto LABEL_12;
  }
  if ( pthread_rwlock_wrlock(&ch_lock.rwlock) )
  {
    v167 = _errno_location();
    snprintf(
      (char *)str,
      0x1000u,
      "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v167,
      "cgminer.c",
      "set_curblock",
      5324);
    goto LABEL_12;
  }
  cgtime(&block_timeval);
  strcpy(current_hash, s);
  str[0] = block_timeval.tv_sec;
  *(_DWORD *)current_block = v176;
  *(_DWORD *)&current_block[4] = v177;
  *(_DWORD *)&current_block[8] = v178;
  *(_DWORD *)&current_block[12] = v179;
  *(_DWORD *)&current_block[16] = v180;
  *(_DWORD *)&current_block[20] = v181;
  *(_DWORD *)&current_block[24] = v182;
  *(_DWORD *)&current_block[28] = v183;
  v124 = localtime(str);
  snprintf(blocktime, 0x20u, "[%02d:%02d:%02d]", v124->tm_hour, v124->tm_min, v124->tm_sec);
  if ( pthread_rwlock_unlock(&ch_lock.rwlock) )
  {
    v166 = _errno_location();
    snprintf(
      (char *)str,
      0x1000u,
      "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v166,
      "cgminer.c",
      "set_curblock",
      5329);
    goto LABEL_12;
  }
  v125 = pthread_mutex_unlock(&ch_lock.mutex);
  if ( v125 )
  {
    v168 = _errno_location();
    snprintf(
      (char *)str,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v168,
      "cgminer.c",
      "set_curblock",
      5329);
LABEL_12:
    applog(3, (const char *)str, 1);
    _quit(1, 1);
  }
  selective_yield();
  v126 = current_hash;
  do
  {
    v127 = (unsigned __int8)*v126++;
    if ( v127 != 48 )
      break;
    ++v125;
  }
  while ( v125 != 57 );
  strncpy(prev_block, &current_hash[v125], 8u);
  prev_block[8] = 0;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf((char *)str, 0x1000u, "New block: %s... diff %s", current_hash, block_diff);
    applog(7, (const char *)str, 0);
  }
  v128 = v177;
  v129 = v178;
  v130 = v179;
  v47 = new_blocks == 1;
  v172[142] = v176;
  v172[143] = v128;
  v172[144] = v129;
  v172[145] = v130;
  v131 = v181;
  v132 = v182;
  v133 = v183;
  v172[146] = v180;
  v172[147] = v131;
  v172[148] = v132;
  v172[149] = v133;
  if ( !v47 )
  {
    v134 = *(unsigned __int8 *)(a1 + 1768);
    *(_DWORD *)(a1 + 1824) = ++work_block;
    if ( v134 )
    {
      if ( *(_BYTE *)(a1 + 1772) )
      {
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf((char *)str, 0x1000u, "Stratum from pool %d detected new block", *v172);
          applog(7, (const char *)str, 0);
        }
      }
      else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        v162 = &byte_59398;
        if ( *(_BYTE *)(a1 + 1812) )
          v162 = "GBT ";
        snprintf((char *)str, 0x1000u, "%sLONGPOLL from pool %d detected new block", v162, **(_DWORD **)(a1 + 1748));
        applog(7, (const char *)str, 0);
      }
    }
    else if ( have_longpoll )
    {
      if ( !*((_BYTE *)v172 + 924) && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        strcpy((char *)str, "New block detected on network before pool notification");
        applog(7, (const char *)str, 0);
      }
    }
    else if ( !*((_BYTE *)v172 + 924) && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      strcpy((char *)str, "New block detected on network");
      applog(7, (const char *)str, 0);
    }
    restart_threads();
    v170 = 1;
  }
out:
  *(_BYTE *)(a1 + 1768) = 0;
  return v170;
}
