void *__fastcall stratum_rthread(void *userdata)
{
  pthread_t v2; // r0
  const char *v3; // r2
  pool *v4; // r0
  fd_set *v5; // r3
  int v6; // r3
  int v7; // r2
  bool v8; // nf
  int v9; // r2
  int v10; // r1
  __fd_mask v11; // r4
  int v12; // r0
  char *v13; // r4
  int v15; // r0
  unsigned int v16; // r2
  int v17; // r4
  json_t *v18; // r0
  json_t *v19; // r0
  const char *v20; // r1
  json_t *v21; // r0
  const char *v22; // r1
  json_t *v23; // r0
  int v24; // r6
  stratum_share *v25; // r5
  UT_hash_table *tbl; // r0
  unsigned int v27; // r1
  unsigned int v28; // r3
  unsigned int v29; // r6
  int v30; // r1
  unsigned int v31; // r2
  unsigned int v32; // r3
  int v33; // r1
  UT_hash_handle *hh_head; // r6
  ptrdiff_t hho; // r12
  char *v36; // r6
  unsigned __int8 *v37; // r2
  int v38; // r7
  unsigned __int8 *v39; // r2
  int v40; // r1
  stratum_share *v41; // r7
  UT_hash_table *v42; // r2
  int v43; // r3
  UT_hash_bucket *buckets; // r2
  __int64 v45; // r2
  int v46; // r7
  time_t v47; // r12
  char *v48; // r3
  unsigned int v50; // r8
  double work_difficulty; // d0
  const char *v52; // r3
  const char *v53; // r1
  pool *pool; // r8
  double v55; // d5
  unsigned int v56; // kr04_4
  int v57; // r1
  unsigned int rejected_high; // r1
  unsigned int rejected; // kr0C_4
  double v60; // d5
  double v61; // d7
  int *v62; // r7
  int v63; // r0
  int v64; // r1
  int v65; // r2
  int v66; // r3
  int v67; // r0
  int v68; // r1
  int v69; // r2
  int v70; // r3
  int v71; // r1
  const char *v72; // r7
  size_t v73; // r3
  const char *v74; // r1
  char *v75; // r7
  int v76; // r3
  const char *v77; // r2
  int seq_rejects; // r5
  const char *v79; // r2
  work *v80; // r5
  size_t v81; // r3
  size_t v82; // r3
  const char *v83; // r2
  work *work; // r5
  const char *v85; // r2
  char *v86; // r6
  size_t refcount; // r3
  size_t v88; // r3
  const char *v89; // r2
  int *v90; // r0
  const pthread_mutex_t *v91; // r5
  int v92; // r3
  int v93; // r1
  int v94; // r4
  const char *v95; // r2
  int *v96; // r0
  int v97; // r1
  const char *v98; // r2
  int *v99; // r0
  const pthread_mutex_t *v100; // r5
  int v101; // r3
  int v102; // r1
  int v103; // r4
  const char *v104; // r2
  int *v105; // r0
  int v106; // r1
  const char *v107; // r2
  int *v108; // r0
  int *v109; // r0
  double v110; // d8
  int64_t v111; // kr20_8
  double v112; // d6
  double v113; // d7
  __int64 v114; // kr28_8
  char *v115; // r0
  int *v116; // r5
  char *v117; // r7
  int v118; // r0
  int v119; // r1
  int v120; // r2
  int v121; // r3
  int v122; // r5
  int64_t v123; // kr30_8
  double v124; // d5
  double v125; // d7
  int pool_no; // r2
  time_t v127; // r0
  _BOOL4 v128; // r3
  int *v129; // r7
  int v130; // r0
  int v131; // r1
  int v132; // r2
  int v133; // r3
  int v134; // r0
  int v135; // r1
  int v136; // r2
  int v137; // r3
  int v138; // r7
  const char *v139; // r2
  const char *v140; // r0
  const char *v141; // r2
  const char *v142; // r2
  int v143; // r3
  double v144; // d6
  unsigned int v145; // r2
  double v146; // d7
  unsigned int v147; // kr18_4
  const char *v148; // r2
  int v149; // r3
  int *v150; // r0
  int *v151; // r0
  const char *v152; // r2
  int *v153; // r0
  int v154; // r1
  int v155; // r3
  const char *v156; // r2
  const char *v157; // r2
  int *v158; // r0
  int v159; // r3
  const char *v160; // r2
  const char *v161; // r1
  const char *v162; // r2
  int *v163; // r0
  const char *v164; // r3
  int v165; // r4
  const char *v166; // r2
  struct timeval *v167; // r3
  struct timeval *v168; // r3
  struct timeval *v169; // r3
  struct timeval *v170; // r3
  json_t *v171; // r0
  const char *v172; // r0
  const char *v173; // r2
  int *v174; // r0
  int v175; // r3
  const char *v176; // r2
  struct timeval *v177; // [sp+0h] [bp-127Ch]
  json_t *json; // [sp+18h] [bp-1264h]
  work *v179; // [sp+20h] [bp-125Ch]
  cgpu_info *cgpu; // [sp+28h] [bp-1254h]
  json_t *n; // [sp+34h] [bp-1248h]
  size_t na; // [sp+34h] [bp-1248h]
  json_t *v183; // [sp+38h] [bp-1244h]
  double *p_work_difficulty; // [sp+44h] [bp-1238h]
  int v185; // [sp+48h] [bp-1234h]
  timeval timeout; // [sp+4Ch] [bp-1230h] BYREF
  char threadname[16]; // [sp+54h] [bp-1228h] BYREF
  char v188[20]; // [sp+64h] [bp-1218h] BYREF
  char v189[2]; // [sp+78h] [bp-1204h] BYREF
  __int16 v190; // [sp+7Ah] [bp-1202h] BYREF
  char buf[7]; // [sp+98h] [bp-11E4h] BYREF
  char dest[29]; // [sp+9Fh] [bp-11DDh] BYREF
  char v193[60]; // [sp+BCh] [bp-11C0h] BYREF
  char v194; // [sp+F8h] [bp-1184h] BYREF
  fd_set rd; // [sp+FCh] [bp-1180h] BYREF
  json_error_t error; // [sp+17Ch] [bp-1100h] BYREF
  char tmp42[4096]; // [sp+278h] [bp-1004h] BYREF

  v2 = pthread_self();
  pthread_detach(v2);
  LOWORD(v3) = 4932;
  HIWORD(v3) = (unsigned int)"ead" >> 16;
  snprintf(threadname, 0x10u, v3, *(_DWORD *)userdata);
  RenameThread(threadname);
  do
  {
LABEL_2:
    v4 = (pool *)userdata;
    if ( *((_BYTE *)userdata + 137) )
    {
LABEL_17:
      suspend_stratum(v4);
      return 0;
    }
    while ( 1 )
    {
      if ( !sock_full(v4) && !cnx_needed((pool *)userdata) )
      {
        suspend_stratum((pool *)userdata);
        clear_stratum_shares((pool *)userdata);
        clear_pool_work((pool *)userdata);
        if ( cnx_needed((pool *)userdata) )
          goto LABEL_33;
        while ( !*((_DWORD *)userdata + 33) || userdata != current_pool() && (unsigned int)(pool_strategy_0 - 3) > 1 )
        {
          if ( pthread_mutex_lock(&lp_lock) )
          {
            v109 = _errno_location();
            LOWORD(v93) = -3136;
            v91 = (const pthread_mutex_t *)"wait_lpcurrent";
            v92 = *v109;
            HIWORD(v93) = (unsigned int)"iner" >> 16;
            v94 = 9248;
            goto LABEL_155;
          }
          pthread_cond_wait(&lp_cond, &lp_lock);
          if ( pthread_mutex_unlock(&lp_lock) )
          {
            v108 = _errno_location();
            LOWORD(v102) = -3136;
            v100 = (const pthread_mutex_t *)"wait_lpcurrent";
            v101 = *v108;
            HIWORD(v102) = (unsigned int)"iner" >> 16;
            v103 = 9250;
            goto LABEL_159;
          }
          selective_yield();
          if ( cnx_needed((pool *)userdata) )
            break;
        }
LABEL_33:
        while ( !restart_stratum((pool *)userdata) )
        {
          if ( *((_BYTE *)userdata + 137) )
            return 0;
          if ( enabled_pools <= 1 )
            v15 = 3000;
          else
            v15 = 30000;
          cgsleep_ms(v15);
        }
      }
      v5 = (fd_set *)&v194;
      do
      {
        v5->fds_bits[1] = 0;
        v5 = (fd_set *)((char *)v5 + 4);
      }
      while ( &rd.fds_bits[31] != (__fd_mask *)v5 );
      v6 = *((_DWORD *)userdata + 153);
      timeout.tv_usec = 0;
      v7 = (v6 + 31) & (v6 >> 31);
      if ( v6 >= 0 )
        v7 = v6;
      v8 = -v6 < 0;
      v9 = v7 >> 5;
      v10 = -v6 & 0x1F;
      LOBYTE(v6) = v6 & 0x1F;
      v11 = rd.fds_bits[v9];
      if ( !v8 )
        v6 = -v10;
      timeout.tv_sec = 90;
      rd.fds_bits[v9] = (1 << v6) | v11;
      if ( !sock_full((pool *)userdata) )
      {
        v12 = select(*((_DWORD *)userdata + 153) + 1, &rd, 0, 0, &timeout);
        if ( v12 <= 0 )
          break;
      }
      v13 = recv_line((pool *)userdata);
      if ( !v13 )
        goto LABEL_35;
      stratum_resumed((pool *)userdata);
      if ( parse_method((pool *)userdata, v13) )
        goto LABEL_14;
      v18 = json_loads(v13, 0, &error);
      json = v18;
      if ( v18 )
      {
        v19 = json_object_get(v18, "result");
        LOWORD(v20) = 2324;
        n = v19;
        HIWORD(v20) = (unsigned int)"sharelog printf error" >> 16;
        v21 = json_object_get(json, v20);
        LOWORD(v22) = 5072;
        v183 = v21;
        HIWORD(v22) = (unsigned int)"d" >> 16;
        v23 = json_object_get(json, v22);
        if ( !v23 || v23->type == JSON_NULL )
        {
          if ( v183 )
          {
            v86 = json_dumps(v183, 3u);
          }
          else
          {
            v115 = (char *)malloc(0x11u);
            v86 = v115;
            if ( v115 )
            {
              LOWORD(v116) = 5076;
              v117 = v115;
              HIWORD(v116) = (unsigned int)"JSON decode failed(%d): %s" >> 16;
              v118 = *v116;
              v119 = v116[1];
              v120 = v116[2];
              v121 = v116[3];
              v122 = v116[4];
              *(_DWORD *)v117 = v118;
              *((_DWORD *)v117 + 1) = v119;
              *((_DWORD *)v117 + 2) = v120;
              *((_DWORD *)v117 + 3) = v121;
              v117[16] = v122;
            }
          }
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            snprintf(tmp42, 0x1000u, "JSON-RPC non method decode failed: %s", v86);
            applog(7, tmp42, 0);
          }
          free(v86);
          refcount = json->refcount;
          if ( refcount != -1 )
            goto LABEL_147;
        }
        else
        {
          v24 = json_integer_value(v23);
          v185 = v24;
          if ( pthread_mutex_lock(&sshare_lock) )
          {
            v150 = _errno_location();
            LOWORD(v93) = -3136;
            v91 = &_func___16149;
            v92 = *v150;
            HIWORD(v93) = (unsigned int)"iner" >> 16;
            v94 = 6921;
LABEL_155:
            LOWORD(v95) = -968;
            HIWORD(v95) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
            snprintf(tmp42, 0x1000u, v95, v92, v93, v91, v94);
            goto LABEL_156;
          }
          v25 = stratum_shares;
          if ( stratum_shares )
          {
            tbl = stratum_shares->hh.tbl;
            v27 = (unsigned int)&nonce_fifo.nonce_buffer[37].Nonce[368]
                ^ ((v24 & 0xFF000000) + (unsigned __int8)v24 + 17973517 + (v24 & 0xFF0000) + (v24 & 0xFF00));
            v28 = (-1622558010 - v27) ^ (v27 << 8);
            v29 = (-17973517 - v27 - v28) ^ (v28 >> 13);
            v30 = (v27 - v28 - v29) ^ (v29 >> 12);
            v31 = (v28 - v29 - v30) ^ (v30 << 16);
            v32 = (v29 - v30 - v31) ^ (v31 >> 5);
            v33 = (v30 - v31 - v32) ^ (v32 >> 3);
            hh_head = stratum_shares->hh.tbl->buckets[((v32 - v33 - ((v31 - v32 - v33) ^ (v33 << 10)))
                                                     ^ (((v31 - v32 - v33) ^ (v33 << 10)) >> 15))
                                                    & (stratum_shares->hh.tbl->num_buckets - 1)].hh_head;
            if ( hh_head )
            {
              hho = tbl->hho;
              while ( 1 )
              {
                v36 = (char *)hh_head - hho;
                if ( !v36 )
                  goto LABEL_163;
                if ( *((_DWORD *)v36 + 6) == 4 )
                {
                  v37 = (unsigned __int8 *)*((_DWORD *)v36 + 5);
                  if ( *v37 == (unsigned __int8)v185 )
                  {
                    v38 = v37[1];
                    v39 = v37 + 1;
                    if ( v38 == BYTE1(v185) && __PAIR64__(v39[2], v39[1]) == __PAIR64__(HIBYTE(v185), BYTE2(v185)) )
                      break;
                  }
                }
                hh_head = (UT_hash_handle *)*((_DWORD *)v36 + 4);
                if ( !hh_head )
                  goto LABEL_163;
              }
              v40 = *((_DWORD *)v36 + 1);
              if ( v40 )
              {
                if ( v36 != (char *)tbl->tail - hho )
                  goto LABEL_67;
LABEL_189:
                tbl->tail = (UT_hash_handle *)(v40 + hho);
                v40 = *((_DWORD *)v36 + 1);
                if ( v40 )
                {
                  hho = v25->hh.tbl->hho;
LABEL_67:
                  *(_DWORD *)(v40 + hho + 8) = *((_DWORD *)v36 + 2);
                  v41 = (stratum_share *)*((_DWORD *)v36 + 2);
LABEL_68:
                  v42 = v25->hh.tbl;
                  if ( v41 )
                  {
                    *(void **)((char *)&v41->hh.prev + v42->hho) = (void *)*((_DWORD *)v36 + 1);
                    v42 = v25->hh.tbl;
                  }
                  v43 = (v42->num_buckets - 1) & *((_DWORD *)v36 + 7);
                  --v42->buckets[v43].count;
                  buckets = v25->hh.tbl->buckets;
                  if ( (char *)buckets[v43].hh_head == v36 )
                    buckets[v43].hh_head = (UT_hash_handle *)*((_DWORD *)v36 + 4);
                  v45 = *(_QWORD *)(v36 + 12);
                  if ( (_DWORD)v45 )
                  {
                    *(_DWORD *)(v45 + 16) = HIDWORD(v45);
                    HIDWORD(v45) = *((_DWORD *)v36 + 4);
                  }
                  if ( HIDWORD(v45) )
                    *(_DWORD *)(HIDWORD(v45) + 12) = *((_DWORD *)v36 + 3);
                  --v25->hh.tbl->num_items;
LABEL_77:
                  --*((_DWORD *)userdata + 189);
                  v46 = pthread_mutex_unlock(&sshare_lock);
                  if ( v46 )
                    goto LABEL_228;
                  selective_yield();
                  v179 = (work *)*((_DWORD *)v36 + 9);
                  v47 = time(0);
                  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                  {
                    snprintf(
                      tmp42,
                      0x1000u,
                      "Pool %d stratum share result lag time %d seconds",
                      v179->pool->pool_no,
                      v47 - *((_DWORD *)v36 + 12));
                    applog(7, tmp42, 0);
                  }
                  v48 = tmp42;
                  *(_DWORD *)tmp42 = bswap32(*(_DWORD *)&v179->hash[28]);
                  *(_DWORD *)&tmp42[4] = bswap32(*(_DWORD *)&v179->hash[24]);
                  *(_DWORD *)&tmp42[8] = bswap32(*(_DWORD *)&v179->hash[20]);
                  *(_DWORD *)&tmp42[12] = bswap32(*(_DWORD *)&v179->hash[16]);
                  *(_DWORD *)&tmp42[16] = bswap32(*(_DWORD *)&v179->hash[12]);
                  *(_DWORD *)&tmp42[20] = bswap32(*(_DWORD *)&v179->hash[8]);
                  *(_DWORD *)&tmp42[24] = bswap32(*(_DWORD *)&v179->hash[4]);
                  *(_DWORD *)&tmp42[28] = bswap32(*(_DWORD *)v179->hash);
                  do
                  {
                    if ( *v48++ )
                      break;
                    ++v46;
                  }
                  while ( v46 != 29 );
                  v50 = bswap32(*(_DWORD *)&tmp42[v46]);
                  work_difficulty = v179->work_difficulty;
                  p_work_difficulty = &v179->work_difficulty;
                  round();
                  suffix_string(v179->share_diff, buf, 0x10u, 0);
                  LOWORD(v52) = -27628;
                  LOWORD(v53) = 4924;
                  HIWORD(v53) = (unsigned int)"work_thread" >> 16;
                  if ( !v179->block )
                  {
                    HIWORD(v52) = (unsigned int)"c.txt" >> 16;
                    v53 = v52;
                  }
                  snprintf(v193, 0x40u, "%08lx Diff %s/%llu%s", v50, buf, (unsigned __int64)work_difficulty, v53);
                  pool = v179->pool;
                  cgpu = get_thread(v179->thr_id)->cgpu;
                  if ( n && (n->type == JSON_TRUE || v179->gbt && n->type == JSON_NULL) )
                  {
                    if ( pthread_mutex_lock(&stats_lock) )
                    {
                      v158 = _errno_location();
                      LOWORD(v159) = -3136;
                      LOWORD(v160) = -968;
                      HIWORD(v159) = (unsigned int)"iner" >> 16;
                      HIWORD(v160) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
                      snprintf(tmp42, 0x1000u, v160, *v158, v159, "share_result", 3481);
                      goto LABEL_156;
                    }
                    v123 = total_accepted + 1;
                    ++cgpu->accepted;
                    total_accepted = v123;
                    ++pool->accepted;
                    v124 = total_diff_accepted;
                    cgpu->diff_accepted = cgpu->diff_accepted + *p_work_difficulty;
                    v125 = pool->diff_accepted + *p_work_difficulty;
                    total_diff_accepted = v124 + *p_work_difficulty;
                    pool->diff_accepted = v125;
                    if ( pthread_mutex_unlock(&stats_lock) )
                    {
                      v153 = _errno_location();
                      LOWORD(v155) = -3136;
                      v154 = 3488;
                      HIWORD(v155) = (unsigned int)"iner" >> 16;
                      goto LABEL_239;
                    }
                    selective_yield();
                    pool_no = pool->pool_no;
                    pool->seq_rejects = 0;
                    cgpu->last_share_pool = pool_no;
                    v127 = time(0);
                    cgpu->last_share_pool_time = v127;
                    v128 = opt_debug;
                    cgpu->last_share_diff = *p_work_difficulty;
                    pool->last_share_time = v127;
                    pool->last_share_diff = *p_work_difficulty;
                    if ( v128 && (use_syslog || opt_log_output || opt_log_level > 6) )
                    {
                      LOWORD(v129) = 5308;
                      HIWORD(v129) = (unsigned int)"e %d seconds" >> 16;
                      v130 = *v129;
                      v131 = v129[1];
                      v132 = v129[2];
                      v133 = v129[3];
                      v129 += 4;
                      *(_DWORD *)tmp42 = v130;
                      *(_DWORD *)&tmp42[4] = v131;
                      *(_DWORD *)&tmp42[8] = v132;
                      *(_DWORD *)&tmp42[12] = v133;
                      v134 = *v129;
                      v135 = v129[1];
                      v136 = v129[2];
                      v137 = v129[3];
                      v138 = v129[4];
                      *(_DWORD *)&tmp42[16] = v134;
                      *(_DWORD *)&tmp42[20] = v135;
                      *(_DWORD *)&tmp42[24] = v136;
                      *(_DWORD *)&tmp42[28] = v137;
                      *(_DWORD *)&tmp42[32] = v138;
                      applog(7, tmp42, 0);
                    }
                    if ( !opt_quiet && !opt_realquiet )
                    {
                      if ( total_pools <= 1 )
                      {
                        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                        {
                          LOWORD(v157) = 5376;
                          HIWORD(v157) = (unsigned int)"yay!!!)" >> 16;
                          snprintf(
                            tmp42,
                            0x1000u,
                            v157,
                            v193,
                            cgpu->drv->name,
                            cgpu->device_id,
                            &byte_59414,
                            &byte_59414);
                          applog(7, tmp42, 0);
                        }
                      }
                      else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                      {
                        LOWORD(v139) = 5344;
                        HIWORD(v139) = (unsigned int)"" >> 16;
                        snprintf(
                          tmp42,
                          0x1000u,
                          v139,
                          v193,
                          cgpu->drv->name,
                          cgpu->device_id,
                          v179->pool->pool_no,
                          &byte_59414,
                          &byte_59414);
                        applog(7, tmp42, 0);
                      }
                    }
                    LOWORD(v140) = 5400;
                    HIWORD(v140) = (unsigned int)"d pool %d %s%s" >> 16;
                    sharelog(v140, v179);
                    if ( opt_shares && (double)opt_shares <= total_diff_accepted )
                    {
                      if ( use_syslog || opt_log_output || opt_log_level > 3 )
                      {
                        LOWORD(v141) = 5408;
                        HIWORD(v141) = (unsigned int)"d %s%s" >> 16;
                        snprintf(tmp42, 0x1000u, v141);
                        applog(4, tmp42, 0);
                      }
                      kill_work();
                    }
                    if ( pool->enabled == pool_enable::POOL_REJECTING )
                    {
                      if ( use_syslog || opt_log_output || opt_log_level > 3 )
                      {
                        LOWORD(v152) = 5472;
                        HIWORD(v152) = (unsigned int)"cepted shares as requested and exiting." >> 16;
                        snprintf(tmp42, 0x1000u, v152, pool->pool_no);
                        applog(4, tmp42, 0);
                      }
                      if ( pool->enabled != pool_enable::POOL_ENABLED )
                        enable_pool((pool *)&pool->enabled);
                      switch_pools(0);
                    }
                    if ( v179->block )
                      restart_threads();
                  }
                  else
                  {
                    if ( pthread_mutex_lock(&stats_lock) )
                    {
                      v174 = _errno_location();
                      LOWORD(v175) = -3136;
                      LOWORD(v176) = -968;
                      HIWORD(v175) = (unsigned int)"iner" >> 16;
                      HIWORD(v176) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
                      snprintf(tmp42, 0x1000u, v176, *v174, v175, "share_result", 3531);
                      goto LABEL_156;
                    }
                    v55 = total_diff_rejected;
                    v56 = total_rejected;
                    v57 = cgpu->rejected + 1;
                    LODWORD(total_rejected) = total_rejected + 1;
                    cgpu->rejected = v57;
                    rejected_high = HIDWORD(pool->rejected);
                    rejected = pool->rejected;
                    HIDWORD(total_rejected) = (__PAIR64__(HIDWORD(total_rejected), v56) + 1) >> 32;
                    pool->rejected = __PAIR64__(rejected_high, rejected) + 1;
                    cgpu->diff_rejected = cgpu->diff_rejected + *p_work_difficulty;
                    v60 = v55 + *p_work_difficulty;
                    v61 = pool->diff_rejected + *p_work_difficulty;
                    ++pool->seq_rejects;
                    total_diff_rejected = v60;
                    pool->diff_rejected = v61;
                    if ( pthread_mutex_unlock(&stats_lock) )
                    {
                      v153 = _errno_location();
                      LOWORD(v155) = -3136;
                      HIWORD(v155) = (unsigned int)"iner" >> 16;
                      v154 = 3539;
LABEL_239:
                      LOWORD(v156) = -920;
                      HIWORD(v156) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
                      snprintf(tmp42, 0x1000u, v156, *v153, v155, "share_result", v154);
                      goto LABEL_156;
                    }
                    selective_yield();
                    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                    {
                      LOWORD(v62) = 5528;
                      HIWORD(v62) = (unsigned int)"d now accepting shares, re-enabling!" >> 16;
                      v63 = *v62;
                      v64 = v62[1];
                      v65 = v62[2];
                      v66 = v62[3];
                      v62 += 4;
                      *(_DWORD *)tmp42 = v63;
                      *(_DWORD *)&tmp42[4] = v64;
                      *(_DWORD *)&tmp42[8] = v65;
                      *(_DWORD *)&tmp42[12] = v66;
                      v67 = *v62;
                      v68 = v62[1];
                      v69 = v62[2];
                      v70 = v62[3];
                      v62 += 4;
                      *(_DWORD *)&tmp42[16] = v67;
                      *(_DWORD *)&tmp42[20] = v68;
                      *(_DWORD *)&tmp42[24] = v69;
                      *(_DWORD *)&tmp42[28] = v70;
                      v71 = v62[1];
                      *(_DWORD *)&tmp42[32] = *v62;
                      tmp42[36] = v71;
                      applog(7, tmp42, 0);
                    }
                    if ( !opt_quiet && !opt_realquiet )
                    {
                      strcpy(buf, "reject");
                      memset(dest, opt_realquiet, sizeof(dest));
                      v189[0] = opt_realquiet;
                      if ( total_pools > 1 )
                      {
                        LOWORD(v162) = 4332;
                        HIWORD(v162) = (unsigned int)"k detected on network" >> 16;
                        snprintf(v188, 0x14u, v162, v179->pool->pool_no);
                      }
                      else
                      {
                        v188[0] = opt_realquiet;
                      }
                      if ( !v179->gbt )
                      {
                        LOWORD(v161) = 5568;
                        HIWORD(v161) = (unsigned int)"PROOF OF WORK RESULT: false (booooo)" >> 16;
                        n = json_object_get(json, v161);
                      }
                      if ( n )
                      {
                        v72 = json_string_value(n);
                        v73 = strlen(v72);
                        if ( v73 >= 0x1C )
                          v73 = 28;
                        *(_WORD *)v189 = 10272;
                        na = v73;
                        memcpy(&v190, v72, v73);
                        v74 = v72;
                        v75 = &v189[na];
                        v75[2] = 41;
                        v75[3] = 0;
                        memcpy(dest, v74, na);
                        buf[6] = 58;
                        buf[na + 7] = 0;
                      }
                      else if ( v183 && v179->stratum )
                      {
                        if ( v183->type == JSON_ARRAY )
                        {
                          v171 = json_array_get(v183, 1u);
                          if ( !v171 || v171->type != JSON_STRING )
                            goto LABEL_105;
                        }
                        else
                        {
                          if ( v183->type != JSON_STRING )
                            goto LABEL_105;
                          v171 = v183;
                        }
                        v172 = json_string_value(v171);
                        LOWORD(v173) = 5776;
                        HIWORD(v173) = (unsigned int)"Failed to allocate device_drv copy of %s (%s)" >> 16;
                        snprintf(v189, 0x1Fu, v173, v172);
                      }
LABEL_105:
                      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                      {
                        LOWORD(v76) = -27628;
                        HIWORD(v76) = (unsigned int)"c.txt" >> 16;
                        LOWORD(v77) = 5584;
                        HIWORD(v77) = (unsigned int)"SULT: false (booooo)" >> 16;
                        snprintf(tmp42, 0x1000u, v77, v193, cgpu->drv->name, cgpu->device_id, v188, v189, v76, v76);
                        applog(7, tmp42, 0);
                      }
                      sharelog(buf, v179);
                    }
                    seq_rejects = pool->seq_rejects;
                    if ( seq_rejects > 10
                      && !v179->stale
                      && opt_disable_pool
                      && enabled_pools > 1
                      && (double)seq_rejects > (double)total_accepted / total_secs * 60.0 * 3.0 )
                    {
                      if ( use_syslog || opt_log_output || opt_log_level > 3 )
                      {
                        LOWORD(v79) = 5612;
                        HIWORD(v79) = (unsigned int)"ct-reason" >> 16;
                        snprintf(tmp42, 0x1000u, v79, pool->pool_no, pool->seq_rejects);
                        applog(4, tmp42, 0);
                      }
                      if ( pool->enabled == pool_enable::POOL_ENABLED )
                        --enabled_pools;
                      pool->enabled = pool_enable::POOL_REJECTING;
                      if ( pool == current_pool() )
                        switch_pools(0);
                      pool->seq_rejects = 0;
                    }
                  }
                  v80 = (work *)*((_DWORD *)v36 + 9);
                  clean_work(v80);
                  free(v80);
                  free(v36);
                  v81 = json->refcount;
                  if ( v81 != -1 )
                  {
                    v82 = v81 - 1;
                    json->refcount = v82;
                    if ( !v82 )
                      json_delete(json);
                  }
LABEL_14:
                  if ( *((_BYTE *)userdata + 696) )
                  {
                    work = make_work();
                    *((_BYTE *)userdata + 696) = 0;
                    gen_stratum_work((pool *)userdata, work);
                    work->longpoll = 1;
                    test_work_current((int)work);
                    clean_work(work);
                    free(work);
                  }
                  goto LABEL_16;
                }
                v41 = (stratum_share *)*((_DWORD *)v36 + 2);
              }
              else
              {
                v41 = (stratum_share *)*((_DWORD *)v36 + 2);
                if ( !v41 )
                {
                  free(stratum_shares->hh.tbl->buckets);
                  free(v25->hh.tbl);
                  stratum_shares = 0;
                  goto LABEL_77;
                }
                if ( v36 == (char *)tbl->tail - hho )
                  goto LABEL_189;
              }
              v25 = v41;
              stratum_shares = v41;
              goto LABEL_68;
            }
          }
LABEL_163:
          if ( pthread_mutex_unlock(&sshare_lock) )
          {
LABEL_228:
            v151 = _errno_location();
            LOWORD(v102) = -3136;
            v100 = &_func___16149;
            v101 = *v151;
            HIWORD(v102) = (unsigned int)"iner" >> 16;
            v103 = 6928;
LABEL_159:
            LOWORD(v104) = -920;
            HIWORD(v104) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
            snprintf(tmp42, 0x1000u, v104, v101, v102, v100, v103);
            goto LABEL_156;
          }
          selective_yield();
          if ( !n )
          {
            refcount = json->refcount;
            if ( refcount == -1 )
              goto LABEL_149;
LABEL_147:
            v88 = refcount - 1;
            json->refcount = v88;
            if ( !v88 )
              json_delete(json);
            goto LABEL_149;
          }
          if ( pthread_mutex_lock((pthread_mutex_t *)((char *)userdata + 244)) )
          {
            v163 = _errno_location();
            LOWORD(v170) = -3136;
            LOWORD(v166) = -968;
            HIWORD(v170) = (unsigned int)"iner" >> 16;
            v165 = 6938;
            v177 = v170;
            HIWORD(v166) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
LABEL_249:
            snprintf(tmp42, 0x1000u, v166, *v163, v177, &_func___16149, v165);
LABEL_156:
            applog(3, tmp42, 1);
            _quit(1, 1);
          }
          if ( pthread_rwlock_rdlock((pthread_rwlock_t *)((char *)userdata + 268)) )
          {
            v163 = _errno_location();
            LOWORD(v169) = -3136;
            LOWORD(v166) = -232;
            HIWORD(v169) = (unsigned int)"iner" >> 16;
            v165 = 6938;
            v177 = v169;
            HIWORD(v166) = (unsigned int)"" >> 16;
            goto LABEL_249;
          }
          if ( pthread_mutex_unlock((pthread_mutex_t *)((char *)userdata + 244)) )
          {
            v163 = _errno_location();
            LOWORD(v164) = -3136;
            HIWORD(v164) = (unsigned int)"iner" >> 16;
            v165 = 6938;
            goto LABEL_248;
          }
          v110 = *((double *)userdata + 230);
          if ( pthread_rwlock_unlock((pthread_rwlock_t *)((char *)userdata + 268)) )
          {
            v163 = _errno_location();
            LOWORD(v168) = -3136;
            LOWORD(v166) = -348;
            HIWORD(v168) = (unsigned int)"iner" >> 16;
            v165 = 6940;
            v177 = v168;
            HIWORD(v166) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
            goto LABEL_249;
          }
          selective_yield();
          if ( n->type == JSON_TRUE )
          {
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              snprintf(tmp42, 0x1000u, "Accepted untracked stratum share from pool %d", *(_DWORD *)userdata);
              applog(7, tmp42, 0);
            }
            if ( pthread_mutex_lock(&stats_lock) )
              mutex_lock((pthread_mutex_t *)&_func___16149, (const char *)0x1B24, v142, v143);
            v144 = *((double *)userdata + 13) + v110;
            ++total_accepted;
            v145 = *((_DWORD *)userdata + 3);
            v146 = total_diff_accepted + v110;
            v147 = *((_DWORD *)userdata + 2);
            *((double *)userdata + 13) = v144;
            *((_QWORD *)userdata + 1) = __PAIR64__(v145, v147) + 1;
            total_diff_accepted = v146;
            if ( pthread_mutex_unlock(&stats_lock) )
              mutex_unlock_noyield((pthread_mutex_t *)&_func___16149, (const char *)0x1B29, v148, v149);
          }
          else
          {
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              snprintf(tmp42, 0x1000u, "Rejected untracked stratum share from pool %d", *(_DWORD *)userdata);
              applog(7, tmp42, 0);
            }
            if ( pthread_mutex_lock(&stats_lock) )
            {
              v163 = _errno_location();
              LOWORD(v167) = -3136;
              LOWORD(v166) = -968;
              HIWORD(v167) = (unsigned int)"iner" >> 16;
              v165 = 6959;
              v177 = v167;
              HIWORD(v166) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
              goto LABEL_249;
            }
            v111 = total_rejected + 1;
            v112 = *((double *)userdata + 14) + v110;
            v113 = total_diff_rejected + v110;
            v114 = *((_QWORD *)userdata + 2) + 1LL;
            LODWORD(total_rejected) = total_rejected + 1;
            *((_QWORD *)userdata + 2) = v114;
            *((double *)userdata + 14) = v112;
            HIDWORD(total_rejected) = HIDWORD(v111);
            total_diff_rejected = v113;
            if ( pthread_mutex_unlock(&stats_lock) )
            {
              v163 = _errno_location();
              v164 = "cgminer.c";
              v165 = 6964;
LABEL_248:
              LOWORD(v166) = -920;
              v177 = (struct timeval *)v164;
              HIWORD(v166) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
              goto LABEL_249;
            }
          }
          selective_yield();
          refcount = json->refcount;
          if ( refcount != -1 )
            goto LABEL_147;
        }
      }
      else
      {
        if ( !opt_debug )
          goto LABEL_16;
        if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
          goto LABEL_151;
        LOWORD(v83) = 5036;
        HIWORD(v83) = (unsigned int)"tum connection to pool %d interrupted" >> 16;
        snprintf(tmp42, 0x1000u, v83, error.line, error.text);
        applog(7, tmp42, 0);
      }
LABEL_149:
      if ( opt_debug )
      {
        if ( !use_syslog )
        {
LABEL_151:
          if ( !opt_log_output && opt_log_level <= 6 )
            goto LABEL_16;
        }
        LOWORD(v89) = 5664;
        HIWORD(v89) = (unsigned int)"cted %d sequential shares, disabling!" >> 16;
        snprintf(tmp42, 0x1000u, v89, v13);
        applog(7, tmp42, 0);
      }
LABEL_16:
      free(v13);
      v4 = (pool *)userdata;
      if ( *((_BYTE *)userdata + 137) )
        goto LABEL_17;
    }
    if ( opt_debug )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 6 )
      {
        LOWORD(v85) = 4944;
        HIWORD(v85) = (unsigned int)"hare above target" >> 16;
        snprintf(tmp42, 0x1000u, v85, *(_DWORD *)userdata, v12);
        applog(7, tmp42, 0);
LABEL_35:
        if ( opt_debug )
        {
          if ( !use_syslog )
            goto LABEL_37;
LABEL_38:
          snprintf(tmp42, 0x1000u, "Stratum connection to pool %d interrupted", *(_DWORD *)userdata);
          applog(7, tmp42, 0);
        }
      }
      else
      {
LABEL_37:
        if ( opt_log_output || opt_log_level > 6 )
          goto LABEL_38;
      }
    }
    v16 = total_go;
    ++*((_DWORD *)userdata + 40);
    total_go = v16 + 1;
    if ( pthread_mutex_lock((pthread_mutex_t *)((char *)userdata + 244)) )
    {
      v90 = _errno_location();
      v91 = (const pthread_mutex_t *)"supports_resume";
      LOWORD(v93) = -3136;
      v92 = *v90;
      HIWORD(v93) = (unsigned int)"iner" >> 16;
      v94 = 7101;
      goto LABEL_155;
    }
    if ( pthread_rwlock_rdlock((pthread_rwlock_t *)((char *)userdata + 268)) )
    {
      v96 = _errno_location();
      LOWORD(v97) = -3136;
      LOWORD(v98) = -232;
      HIWORD(v97) = (unsigned int)"iner" >> 16;
      HIWORD(v98) = (unsigned int)"" >> 16;
      snprintf(tmp42, 0x1000u, v98, *v96, v97, "supports_resume", 7101);
      goto LABEL_156;
    }
    if ( pthread_mutex_unlock((pthread_mutex_t *)((char *)userdata + 244)) )
    {
      v99 = _errno_location();
      v100 = (const pthread_mutex_t *)"supports_resume";
      LOWORD(v102) = -3136;
      v101 = *v99;
      HIWORD(v102) = (unsigned int)"iner" >> 16;
      v103 = 7101;
      goto LABEL_159;
    }
    v17 = *((_DWORD *)userdata + 165);
    if ( pthread_rwlock_unlock((pthread_rwlock_t *)((char *)userdata + 268)) )
    {
      v105 = _errno_location();
      LOWORD(v106) = -3136;
      LOWORD(v107) = -348;
      HIWORD(v106) = (unsigned int)"iner" >> 16;
      HIWORD(v107) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
      snprintf(tmp42, 0x1000u, v107, *v105, v106, "supports_resume", 7103);
      goto LABEL_156;
    }
    selective_yield();
    if ( !v17 || opt_lowmem )
      clear_stratum_shares((pool *)userdata);
    clear_pool_work((pool *)userdata);
    if ( userdata == current_pool() )
      restart_threads();
  }
  while ( restart_stratum((pool *)userdata) );
  while ( !*((_BYTE *)userdata + 137) )
  {
    cgsleep_ms(30000);
    if ( restart_stratum((pool *)userdata) )
      goto LABEL_2;
  }
  return 0;
}
