void *__fastcall stratum_rthread(void *userdata)
{
  pthread_t v2; // r0
  pool *v3; // r0
  fd_set *v4; // r3
  int v5; // r3
  int v6; // r2
  bool v7; // nf
  int v8; // r2
  int v9; // r1
  __fd_mask v10; // r4
  int v11; // r0
  char *v12; // r4
  int v14; // r0
  unsigned int v15; // r2
  int v16; // r4
  json_t *v17; // r0
  json_t *v18; // r0
  int v19; // r6
  stratum_share *v20; // r5
  UT_hash_table *tbl; // r0
  unsigned int v22; // r1
  unsigned int v23; // r3
  unsigned int v24; // r6
  int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r3
  int v28; // r1
  UT_hash_handle *hh_head; // r6
  ptrdiff_t hho; // r12
  char *v31; // r6
  unsigned __int8 *v32; // r2
  int v33; // r7
  unsigned __int8 *v34; // r2
  int v35; // r1
  stratum_share *v36; // r7
  UT_hash_table *v37; // r2
  int v38; // r3
  UT_hash_bucket *buckets; // r2
  __int64 v40; // r2
  int v41; // r7
  time_t v42; // r12
  char *v43; // r3
  unsigned int v45; // r8
  double work_difficulty; // d0
  const char *v47; // r1
  pool *pool; // r8
  double v49; // d5
  unsigned int v50; // kr04_4
  int v51; // r1
  unsigned int rejected_high; // r1
  unsigned int rejected; // kr0C_4
  double v54; // d5
  double v55; // d7
  const char *v56; // r7
  size_t v57; // r3
  const char *v58; // r1
  char *v59; // r7
  int seq_rejects; // r5
  work *v61; // r5
  size_t v62; // r3
  size_t v63; // r3
  work *work; // r5
  char *v65; // r6
  size_t refcount; // r3
  size_t v67; // r3
  const pthread_mutex_t *v68; // r5
  int v69; // r3
  int v70; // r4
  int *v71; // r0
  const pthread_mutex_t *v72; // r5
  int v73; // r3
  int v74; // r4
  int *v75; // r0
  double v76; // d8
  int64_t v77; // kr20_8
  double v78; // d6
  double v79; // d7
  __int64 v80; // kr28_8
  char *v81; // r0
  int64_t v82; // kr30_8
  double v83; // d5
  double v84; // d7
  int pool_no; // r2
  time_t v86; // r0
  _BOOL4 v87; // r3
  const char *v88; // r2
  int v89; // r3
  double v90; // d6
  unsigned int v91; // r2
  double v92; // d7
  unsigned int v93; // kr18_4
  const char *v94; // r2
  int v95; // r3
  int *v96; // r0
  int v97; // r1
  int *v98; // r0
  int *v99; // r0
  int v100; // r4
  const char *v101; // r2
  json_t *v102; // r0
  const char *v103; // r0
  int *v104; // r0
  json_t *json; // [sp+18h] [bp-1264h]
  work *v106; // [sp+20h] [bp-125Ch]
  cgpu_info *cgpu; // [sp+28h] [bp-1254h]
  json_t *n; // [sp+34h] [bp-1248h]
  size_t na; // [sp+34h] [bp-1248h]
  const json_t *v110; // [sp+38h] [bp-1244h]
  double *p_work_difficulty; // [sp+44h] [bp-1238h]
  int v112; // [sp+48h] [bp-1234h]
  timeval timeout; // [sp+4Ch] [bp-1230h] BYREF
  char threadname[16]; // [sp+54h] [bp-1228h] BYREF
  char v115[20]; // [sp+64h] [bp-1218h] BYREF
  char v116[2]; // [sp+78h] [bp-1204h] BYREF
  __int16 v117; // [sp+7Ah] [bp-1202h] BYREF
  char buf[7]; // [sp+98h] [bp-11E4h] BYREF
  char dest[29]; // [sp+9Fh] [bp-11DDh] BYREF
  char v120[60]; // [sp+BCh] [bp-11C0h] BYREF
  char v121; // [sp+F8h] [bp-1184h] BYREF
  fd_set rd; // [sp+FCh] [bp-1180h] BYREF
  json_error_t error; // [sp+17Ch] [bp-1100h] BYREF
  char tmp42[4096]; // [sp+278h] [bp-1004h] BYREF

  v2 = pthread_self();
  pthread_detach(v2);
  snprintf(threadname, 0x10u, "%d/RStratum", *(_DWORD *)userdata);
  RenameThread(threadname);
  do
  {
LABEL_2:
    v3 = (pool *)userdata;
    if ( *((_BYTE *)userdata + 137) )
    {
LABEL_17:
      suspend_stratum(v3);
      return 0;
    }
    while ( 1 )
    {
      if ( !sock_full(v3) && !cnx_needed((pool *)userdata) )
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
            v68 = (const pthread_mutex_t *)"wait_lpcurrent";
            v69 = *_errno_location();
            v70 = 9248;
            goto LABEL_155;
          }
          pthread_cond_wait(&lp_cond, &lp_lock);
          if ( pthread_mutex_unlock(&lp_lock) )
          {
            v72 = (const pthread_mutex_t *)"wait_lpcurrent";
            v73 = *_errno_location();
            v74 = 9250;
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
            v14 = 3000;
          else
            v14 = 30000;
          cgsleep_ms(v14);
        }
      }
      v4 = (fd_set *)&v121;
      do
      {
        v4->fds_bits[1] = 0;
        v4 = (fd_set *)((char *)v4 + 4);
      }
      while ( &rd.fds_bits[31] != (__fd_mask *)v4 );
      v5 = *((_DWORD *)userdata + 153);
      timeout.tv_usec = 0;
      v6 = (v5 + 31) & (v5 >> 31);
      if ( v5 >= 0 )
        v6 = v5;
      v7 = -v5 < 0;
      v8 = v6 >> 5;
      v9 = -v5 & 0x1F;
      LOBYTE(v5) = v5 & 0x1F;
      v10 = rd.fds_bits[v8];
      if ( !v7 )
        v5 = -v9;
      timeout.tv_sec = 90;
      rd.fds_bits[v8] = (1 << v5) | v10;
      if ( !sock_full((pool *)userdata) )
      {
        v11 = select(*((_DWORD *)userdata + 153) + 1, &rd, 0, 0, &timeout);
        if ( v11 <= 0 )
          break;
      }
      v12 = recv_line((pool *)userdata);
      if ( !v12 )
        goto LABEL_35;
      stratum_resumed((pool *)userdata);
      if ( parse_method((pool *)userdata, v12) )
        goto LABEL_14;
      v17 = json_loads(v12, 0, &error);
      json = v17;
      if ( v17 )
      {
        n = json_object_get(v17, "result");
        v110 = json_object_get(json, "error");
        v18 = json_object_get(json, "id");
        if ( !v18 || v18->type == JSON_NULL )
        {
          if ( v110 )
          {
            v65 = json_dumps(v110, 3u);
          }
          else
          {
            v81 = (char *)malloc(0x11u);
            v65 = v81;
            if ( v81 )
              strcpy(v81, "(unknown reason)");
          }
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            snprintf(tmp42, 0x1000u, "JSON-RPC non method decode failed: %s", v65);
            applog(7, tmp42, 0);
          }
          free(v65);
          refcount = json->refcount;
          if ( refcount != -1 )
            goto LABEL_147;
        }
        else
        {
          v19 = json_integer_value(v18);
          v112 = v19;
          if ( pthread_mutex_lock(&sshare_lock) )
          {
            v68 = &_func___16149;
            v69 = *_errno_location();
            v70 = 6921;
LABEL_155:
            snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", v69, "cgminer.c", v68, v70);
            goto LABEL_156;
          }
          v20 = stratum_shares;
          if ( stratum_shares )
          {
            tbl = stratum_shares->hh.tbl;
            v22 = (unsigned int)&nonce_fifo.nonce_buffer[37].Nonce[368]
                ^ ((v19 & 0xFF000000) + (unsigned __int8)v19 + 17973517 + (v19 & 0xFF0000) + (v19 & 0xFF00));
            v23 = (-1622558010 - v22) ^ (v22 << 8);
            v24 = (-17973517 - v22 - v23) ^ (v23 >> 13);
            v25 = (v22 - v23 - v24) ^ (v24 >> 12);
            v26 = (v23 - v24 - v25) ^ (v25 << 16);
            v27 = (v24 - v25 - v26) ^ (v26 >> 5);
            v28 = (v25 - v26 - v27) ^ (v27 >> 3);
            hh_head = stratum_shares->hh.tbl->buckets[((v27 - v28 - ((v26 - v27 - v28) ^ (v28 << 10)))
                                                     ^ (((v26 - v27 - v28) ^ (v28 << 10)) >> 15))
                                                    & (stratum_shares->hh.tbl->num_buckets - 1)].hh_head;
            if ( hh_head )
            {
              hho = tbl->hho;
              while ( 1 )
              {
                v31 = (char *)hh_head - hho;
                if ( !v31 )
                  goto LABEL_163;
                if ( *((_DWORD *)v31 + 6) == 4 )
                {
                  v32 = (unsigned __int8 *)*((_DWORD *)v31 + 5);
                  if ( *v32 == (unsigned __int8)v112 )
                  {
                    v33 = v32[1];
                    v34 = v32 + 1;
                    if ( v33 == BYTE1(v112) && __PAIR64__(v34[2], v34[1]) == __PAIR64__(HIBYTE(v112), BYTE2(v112)) )
                      break;
                  }
                }
                hh_head = (UT_hash_handle *)*((_DWORD *)v31 + 4);
                if ( !hh_head )
                  goto LABEL_163;
              }
              v35 = *((_DWORD *)v31 + 1);
              if ( v35 )
              {
                if ( v31 != (char *)tbl->tail - hho )
                  goto LABEL_67;
LABEL_189:
                tbl->tail = (UT_hash_handle *)(v35 + hho);
                v35 = *((_DWORD *)v31 + 1);
                if ( v35 )
                {
                  hho = v20->hh.tbl->hho;
LABEL_67:
                  *(_DWORD *)(v35 + hho + 8) = *((_DWORD *)v31 + 2);
                  v36 = (stratum_share *)*((_DWORD *)v31 + 2);
LABEL_68:
                  v37 = v20->hh.tbl;
                  if ( v36 )
                  {
                    *(void **)((char *)&v36->hh.prev + v37->hho) = (void *)*((_DWORD *)v31 + 1);
                    v37 = v20->hh.tbl;
                  }
                  v38 = (v37->num_buckets - 1) & *((_DWORD *)v31 + 7);
                  --v37->buckets[v38].count;
                  buckets = v20->hh.tbl->buckets;
                  if ( (char *)buckets[v38].hh_head == v31 )
                    buckets[v38].hh_head = (UT_hash_handle *)*((_DWORD *)v31 + 4);
                  v40 = *(_QWORD *)(v31 + 12);
                  if ( (_DWORD)v40 )
                  {
                    *(_DWORD *)(v40 + 16) = HIDWORD(v40);
                    HIDWORD(v40) = *((_DWORD *)v31 + 4);
                  }
                  if ( HIDWORD(v40) )
                    *(_DWORD *)(HIDWORD(v40) + 12) = *((_DWORD *)v31 + 3);
                  --v20->hh.tbl->num_items;
LABEL_77:
                  --*((_DWORD *)userdata + 189);
                  v41 = pthread_mutex_unlock(&sshare_lock);
                  if ( v41 )
                    goto LABEL_228;
                  selective_yield();
                  v106 = (work *)*((_DWORD *)v31 + 9);
                  v42 = time(0);
                  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                  {
                    snprintf(
                      tmp42,
                      0x1000u,
                      "Pool %d stratum share result lag time %d seconds",
                      v106->pool->pool_no,
                      v42 - *((_DWORD *)v31 + 12));
                    applog(7, tmp42, 0);
                  }
                  v43 = tmp42;
                  *(_DWORD *)tmp42 = bswap32(*(_DWORD *)&v106->hash[28]);
                  *(_DWORD *)&tmp42[4] = bswap32(*(_DWORD *)&v106->hash[24]);
                  *(_DWORD *)&tmp42[8] = bswap32(*(_DWORD *)&v106->hash[20]);
                  *(_DWORD *)&tmp42[12] = bswap32(*(_DWORD *)&v106->hash[16]);
                  *(_DWORD *)&tmp42[16] = bswap32(*(_DWORD *)&v106->hash[12]);
                  *(_DWORD *)&tmp42[20] = bswap32(*(_DWORD *)&v106->hash[8]);
                  *(_DWORD *)&tmp42[24] = bswap32(*(_DWORD *)&v106->hash[4]);
                  *(_DWORD *)&tmp42[28] = bswap32(*(_DWORD *)v106->hash);
                  do
                  {
                    if ( *v43++ )
                      break;
                    ++v41;
                  }
                  while ( v41 != 29 );
                  v45 = bswap32(*(_DWORD *)&tmp42[v41]);
                  work_difficulty = v106->work_difficulty;
                  p_work_difficulty = &v106->work_difficulty;
                  round();
                  suffix_string(v106->share_diff, buf, 0x10u, 0);
                  v47 = " BLOCK!";
                  if ( !v106->block )
                    v47 = &byte_59398;
                  snprintf(v120, 0x40u, "%08lx Diff %s/%llu%s", v45, buf, (unsigned __int64)work_difficulty, v47);
                  pool = v106->pool;
                  cgpu = get_thread(v106->thr_id)->cgpu;
                  if ( n && (n->type == JSON_TRUE || v106->gbt && n->type == JSON_NULL) )
                  {
                    if ( pthread_mutex_lock(&stats_lock) )
                    {
                      v98 = _errno_location();
                      snprintf(
                        tmp42,
                        0x1000u,
                        "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
                        *v98,
                        "cgminer.c",
                        "share_result",
                        3481);
                      goto LABEL_156;
                    }
                    v82 = total_accepted + 1;
                    ++cgpu->accepted;
                    total_accepted = v82;
                    ++pool->accepted;
                    v83 = total_diff_accepted;
                    cgpu->diff_accepted = cgpu->diff_accepted + *p_work_difficulty;
                    v84 = pool->diff_accepted + *p_work_difficulty;
                    total_diff_accepted = v83 + *p_work_difficulty;
                    pool->diff_accepted = v84;
                    if ( pthread_mutex_unlock(&stats_lock) )
                    {
                      v96 = _errno_location();
                      v97 = 3488;
                      goto LABEL_239;
                    }
                    selective_yield();
                    pool_no = pool->pool_no;
                    pool->seq_rejects = 0;
                    cgpu->last_share_pool = pool_no;
                    v86 = time(0);
                    cgpu->last_share_pool_time = v86;
                    v87 = opt_debug;
                    cgpu->last_share_diff = *p_work_difficulty;
                    pool->last_share_time = v86;
                    pool->last_share_diff = *p_work_difficulty;
                    if ( v87 && (use_syslog || opt_log_output || opt_log_level > 6) )
                    {
                      strcpy(tmp42, "PROOF OF WORK RESULT: true (yay!!!)");
                      applog(7, tmp42, 0);
                    }
                    if ( !opt_quiet && !opt_realquiet )
                    {
                      if ( total_pools <= 1 )
                      {
                        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                        {
                          snprintf(
                            tmp42,
                            0x1000u,
                            "Accepted %s %s %d %s%s",
                            v120,
                            cgpu->drv->name,
                            cgpu->device_id,
                            &byte_59398,
                            &byte_59398);
                          applog(7, tmp42, 0);
                        }
                      }
                      else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                      {
                        snprintf(
                          tmp42,
                          0x1000u,
                          "Accepted %s %s %d pool %d %s%s",
                          v120,
                          cgpu->drv->name,
                          cgpu->device_id,
                          v106->pool->pool_no,
                          &byte_59398,
                          &byte_59398);
                        applog(7, tmp42, 0);
                      }
                    }
                    sharelog("accept", v106);
                    if ( opt_shares && (double)opt_shares <= total_diff_accepted )
                    {
                      if ( use_syslog || opt_log_output || opt_log_level > 3 )
                      {
                        snprintf(
                          tmp42,
                          0x1000u,
                          "Successfully mined %d accepted shares as requested and exiting.",
                          opt_shares);
                        applog(4, tmp42, 0);
                      }
                      kill_work();
                    }
                    if ( pool->enabled == pool_enable::POOL_REJECTING )
                    {
                      if ( use_syslog || opt_log_output || opt_log_level > 3 )
                      {
                        snprintf(tmp42, 0x1000u, "Rejecting pool %d now accepting shares, re-enabling!", pool->pool_no);
                        applog(4, tmp42, 0);
                      }
                      if ( pool->enabled != pool_enable::POOL_ENABLED )
                        enable_pool((pool *)&pool->enabled);
                      switch_pools(0);
                    }
                    if ( v106->block )
                      restart_threads();
                  }
                  else
                  {
                    if ( pthread_mutex_lock(&stats_lock) )
                    {
                      v104 = _errno_location();
                      snprintf(
                        tmp42,
                        0x1000u,
                        "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
                        *v104,
                        "cgminer.c",
                        "share_result",
                        3531);
                      goto LABEL_156;
                    }
                    v49 = total_diff_rejected;
                    v50 = total_rejected;
                    v51 = cgpu->rejected + 1;
                    LODWORD(total_rejected) = total_rejected + 1;
                    cgpu->rejected = v51;
                    rejected_high = HIDWORD(pool->rejected);
                    rejected = pool->rejected;
                    HIDWORD(total_rejected) = (__PAIR64__(HIDWORD(total_rejected), v50) + 1) >> 32;
                    pool->rejected = __PAIR64__(rejected_high, rejected) + 1;
                    cgpu->diff_rejected = cgpu->diff_rejected + *p_work_difficulty;
                    v54 = v49 + *p_work_difficulty;
                    v55 = pool->diff_rejected + *p_work_difficulty;
                    ++pool->seq_rejects;
                    total_diff_rejected = v54;
                    pool->diff_rejected = v55;
                    if ( pthread_mutex_unlock(&stats_lock) )
                    {
                      v96 = _errno_location();
                      v97 = 3539;
LABEL_239:
                      snprintf(
                        tmp42,
                        0x1000u,
                        "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
                        *v96,
                        "cgminer.c",
                        "share_result",
                        v97);
                      goto LABEL_156;
                    }
                    selective_yield();
                    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                    {
                      strcpy(tmp42, "PROOF OF WORK RESULT: false (booooo)");
                      applog(7, tmp42, 0);
                    }
                    if ( !opt_quiet && !opt_realquiet )
                    {
                      strcpy(buf, "reject");
                      memset(dest, opt_realquiet, sizeof(dest));
                      v116[0] = opt_realquiet;
                      if ( total_pools > 1 )
                        snprintf(v115, 0x14u, "pool %d", v106->pool->pool_no);
                      else
                        v115[0] = opt_realquiet;
                      if ( !v106->gbt )
                        n = json_object_get(json, "reject-reason");
                      if ( n )
                      {
                        v56 = json_string_value(n);
                        v57 = strlen(v56);
                        if ( v57 >= 0x1C )
                          v57 = 28;
                        *(_WORD *)v116 = 10272;
                        na = v57;
                        memcpy(&v117, v56, v57);
                        v58 = v56;
                        v59 = &v116[na];
                        v59[2] = 41;
                        v59[3] = 0;
                        memcpy(dest, v58, na);
                        buf[6] = 58;
                        buf[na + 7] = 0;
                      }
                      else if ( v110 && v106->stratum )
                      {
                        if ( v110->type == JSON_ARRAY )
                        {
                          v102 = json_array_get(v110, 1u);
                          if ( !v102 || v102->type != JSON_STRING )
                            goto LABEL_105;
                        }
                        else
                        {
                          if ( v110->type != JSON_STRING )
                            goto LABEL_105;
                          v102 = (json_t *)v110;
                        }
                        v103 = json_string_value(v102);
                        snprintf(v116, 0x1Fu, " (%s)", v103);
                      }
LABEL_105:
                      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                      {
                        snprintf(
                          tmp42,
                          0x1000u,
                          "Rejected %s %s %d %s%s %s%s",
                          v120,
                          cgpu->drv->name,
                          cgpu->device_id,
                          v115,
                          v116,
                          &byte_59398,
                          &byte_59398);
                        applog(7, tmp42, 0);
                      }
                      sharelog(buf, v106);
                    }
                    seq_rejects = pool->seq_rejects;
                    if ( seq_rejects > 10
                      && !v106->stale
                      && opt_disable_pool
                      && enabled_pools > 1
                      && (double)seq_rejects > (double)total_accepted / total_secs * 60.0 * 3.0 )
                    {
                      if ( use_syslog || opt_log_output || opt_log_level > 3 )
                      {
                        snprintf(
                          tmp42,
                          0x1000u,
                          "Pool %d rejected %d sequential shares, disabling!",
                          pool->pool_no,
                          pool->seq_rejects);
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
                  v61 = (work *)*((_DWORD *)v31 + 9);
                  clean_work(v61);
                  free(v61);
                  free(v31);
                  v62 = json->refcount;
                  if ( v62 != -1 )
                  {
                    v63 = v62 - 1;
                    json->refcount = v63;
                    if ( !v63 )
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
                v36 = (stratum_share *)*((_DWORD *)v31 + 2);
              }
              else
              {
                v36 = (stratum_share *)*((_DWORD *)v31 + 2);
                if ( !v36 )
                {
                  free(stratum_shares->hh.tbl->buckets);
                  free(v20->hh.tbl);
                  stratum_shares = 0;
                  goto LABEL_77;
                }
                if ( v31 == (char *)tbl->tail - hho )
                  goto LABEL_189;
              }
              v20 = v36;
              stratum_shares = v36;
              goto LABEL_68;
            }
          }
LABEL_163:
          if ( pthread_mutex_unlock(&sshare_lock) )
          {
LABEL_228:
            v72 = &_func___16149;
            v73 = *_errno_location();
            v74 = 6928;
LABEL_159:
            snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", v73, "cgminer.c", v72, v74);
            goto LABEL_156;
          }
          selective_yield();
          if ( !n )
          {
            refcount = json->refcount;
            if ( refcount == -1 )
              goto LABEL_149;
LABEL_147:
            v67 = refcount - 1;
            json->refcount = v67;
            if ( !v67 )
              json_delete(json);
            goto LABEL_149;
          }
          if ( pthread_mutex_lock((pthread_mutex_t *)((char *)userdata + 244)) )
          {
            v99 = _errno_location();
            v101 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
            v100 = 6938;
LABEL_249:
            snprintf(tmp42, 0x1000u, v101, *v99, "cgminer.c", &_func___16149, v100);
LABEL_156:
            applog(3, tmp42, 1);
            _quit(1, 1);
          }
          if ( pthread_rwlock_rdlock((pthread_rwlock_t *)((char *)userdata + 268)) )
          {
            v99 = _errno_location();
            v101 = "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
            v100 = 6938;
            goto LABEL_249;
          }
          if ( pthread_mutex_unlock((pthread_mutex_t *)((char *)userdata + 244)) )
          {
            v99 = _errno_location();
            v100 = 6938;
            goto LABEL_248;
          }
          v76 = *((double *)userdata + 230);
          if ( pthread_rwlock_unlock((pthread_rwlock_t *)((char *)userdata + 268)) )
          {
            v99 = _errno_location();
            v101 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
            v100 = 6940;
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
              mutex_lock((pthread_mutex_t *)&_func___16149, (const char *)0x1B24, v88, v89);
            v90 = *((double *)userdata + 13) + v76;
            ++total_accepted;
            v91 = *((_DWORD *)userdata + 3);
            v92 = total_diff_accepted + v76;
            v93 = *((_DWORD *)userdata + 2);
            *((double *)userdata + 13) = v90;
            *((_QWORD *)userdata + 1) = __PAIR64__(v91, v93) + 1;
            total_diff_accepted = v92;
            if ( pthread_mutex_unlock(&stats_lock) )
              mutex_unlock_noyield((pthread_mutex_t *)&_func___16149, (const char *)0x1B29, v94, v95);
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
              v99 = _errno_location();
              v101 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
              v100 = 6959;
              goto LABEL_249;
            }
            v77 = total_rejected + 1;
            v78 = *((double *)userdata + 14) + v76;
            v79 = total_diff_rejected + v76;
            v80 = *((_QWORD *)userdata + 2) + 1LL;
            LODWORD(total_rejected) = total_rejected + 1;
            *((_QWORD *)userdata + 2) = v80;
            *((double *)userdata + 14) = v78;
            HIDWORD(total_rejected) = HIDWORD(v77);
            total_diff_rejected = v79;
            if ( pthread_mutex_unlock(&stats_lock) )
            {
              v99 = _errno_location();
              v100 = 6964;
LABEL_248:
              v101 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
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
        snprintf(tmp42, 0x1000u, "JSON decode failed(%d): %s", error.line, error.text);
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
        snprintf(tmp42, 0x1000u, "Unknown stratum msg: %s", v12);
        applog(7, tmp42, 0);
      }
LABEL_16:
      free(v12);
      v3 = (pool *)userdata;
      if ( *((_BYTE *)userdata + 137) )
        goto LABEL_17;
    }
    if ( opt_debug )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 6 )
      {
        snprintf(tmp42, 0x1000u, "Stratum select failed on pool %d with value %d", *(_DWORD *)userdata, v11);
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
    v15 = total_go;
    ++*((_DWORD *)userdata + 40);
    total_go = v15 + 1;
    if ( pthread_mutex_lock((pthread_mutex_t *)((char *)userdata + 244)) )
    {
      v68 = (const pthread_mutex_t *)"supports_resume";
      v69 = *_errno_location();
      v70 = 7101;
      goto LABEL_155;
    }
    if ( pthread_rwlock_rdlock((pthread_rwlock_t *)((char *)userdata + 268)) )
    {
      v71 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
        *v71,
        "cgminer.c",
        "supports_resume",
        7101);
      goto LABEL_156;
    }
    if ( pthread_mutex_unlock((pthread_mutex_t *)((char *)userdata + 244)) )
    {
      v72 = (const pthread_mutex_t *)"supports_resume";
      v73 = *_errno_location();
      v74 = 7101;
      goto LABEL_159;
    }
    v16 = *((_DWORD *)userdata + 165);
    if ( pthread_rwlock_unlock((pthread_rwlock_t *)((char *)userdata + 268)) )
    {
      v75 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
        *v75,
        "cgminer.c",
        "supports_resume",
        7103);
      goto LABEL_156;
    }
    selective_yield();
    if ( !v16 || opt_lowmem )
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
