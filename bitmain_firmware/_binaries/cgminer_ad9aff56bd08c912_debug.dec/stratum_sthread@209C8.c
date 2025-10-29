int __fastcall stratum_sthread(pool *a1)
{
  pthread_t v2; // r0
  const char *v3; // r2
  thread_q *v4; // r0
  thread_q *v5; // r4
  thread_q *stratum_q; // r0
  void *v7; // r4
  char *v8; // r6
  char *v9; // r8
  char *v10; // r7
  int v11; // r2
  size_t v12; // r0
  const char *v13; // r2
  time_t v14; // r8
  ssize_t v15; // r0
  stratum_share *v16; // r4
  __int64 v17; // r2
  UT_hash_table *tbl; // r5
  int v19; // r5
  int v20; // r3
  int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r3
  int v24; // r1
  unsigned int v25; // r0
  unsigned int v26; // r3
  unsigned int v27; // r1
  unsigned int v28; // r3
  __int64 v29; // kr00_8
  int v30; // r0
  UT_hash_handle *hh_head; // r1
  UT_hash_bucket *buckets; // r2
  UT_hash_handle *v33; // r3
  UT_hash_bucket *v34; // r2
  __int64 v35; // r2
  int v36; // r4
  const char *v37; // r2
  int *v38; // r4
  int v39; // r0
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r0
  int v44; // r1
  int v45; // r2
  int v46; // r3
  int v47; // r0
  int v48; // r1
  int v49; // r2
  int v50; // r3
  int v51; // r4
  time_t v52; // r0
  _BOOL4 v53; // r3
  const char *v54; // r2
  const char *v56; // r2
  _DWORD *v57; // r7
  unsigned int v58; // r1
  unsigned int v59; // r3
  int v60; // r1
  unsigned int v61; // r4
  unsigned int v62; // r10
  char *v63; // r9
  _DWORD *v64; // r5
  _DWORD *v65; // r6
  int v66; // r4
  char *v67; // r8
  unsigned int v68; // r2
  int v69; // r3
  int v70; // r3
  unsigned int v71; // r2
  unsigned int v72; // r1
  bool v73; // cc
  int v74; // r2
  int *v75; // r5
  int v76; // r0
  int v77; // r1
  int v78; // r2
  int v79; // r3
  int *v80; // r5
  int *v81; // r4
  int v82; // r0
  int v83; // r1
  int v84; // r2
  int v85; // r3
  _DWORD *v86; // r5
  _DWORD *v87; // r4
  int v88; // r1
  int v89; // r2
  int v90; // r3
  UT_hash_table *v91; // r0
  UT_hash_bucket *v92; // r0
  int *v93; // r0
  int v94; // r3
  int v95; // r1
  int v96; // r4
  const char *v97; // r2
  int *v98; // r0
  int v99; // r3
  int v100; // r1
  int v101; // r4
  const char *v102; // r2
  char *nonce1; // r1
  int *v104; // r0
  int *v105; // r0
  int *v106; // r0
  int v107; // r1
  const char *v108; // r2
  unsigned int v109; // r3
  int *v110; // r0
  int *v111; // r0
  int v112; // r1
  const char *v113; // r2
  int *v114; // r0
  int *v115; // r4
  int v116; // r0
  int v117; // r1
  int v118; // r2
  int v119; // r3
  int v120; // r0
  int v121; // r1
  int v122; // r2
  int v123; // r3
  int v124; // r0
  int v125; // r1
  int v126; // r2
  int v127; // r3
  int v128; // r4
  int *v129; // r4
  int v130; // r0
  int v131; // r1
  int v132; // r2
  int v133; // r3
  int v134; // r0
  int v135; // r1
  int v136; // r2
  int v137; // r3
  int v138; // r0
  int v139; // r1
  int v140; // r2
  int v141; // r3
  int v142; // r1
  int v143; // [sp+18h] [bp-2034h]
  pool *v144; // [sp+30h] [bp-201Ch]
  char s[16]; // [sp+38h] [bp-2014h] BYREF
  char v146[4096]; // [sp+48h] [bp-2004h] BYREF
  int v147; // [sp+1048h] [bp-1004h] BYREF
  int v148; // [sp+104Ch] [bp-1000h]
  int v149; // [sp+1050h] [bp-FFCh]
  int v150; // [sp+1054h] [bp-FF8h]
  int v151; // [sp+1058h] [bp-FF4h] BYREF
  int v152; // [sp+105Ch] [bp-FF0h]
  int v153; // [sp+1060h] [bp-FECh]
  int v154; // [sp+1064h] [bp-FE8h]
  int v155; // [sp+1068h] [bp-FE4h]
  int v156; // [sp+106Ch] [bp-FE0h]
  int v157; // [sp+1070h] [bp-FDCh]
  int v158; // [sp+1074h] [bp-FD8h]
  int v159; // [sp+1078h] [bp-FD4h]
  __int16 v160; // [sp+107Ch] [bp-FD0h]

  v2 = pthread_self();
  pthread_detach(v2);
  LOWORD(v3) = 2784;
  HIWORD(v3) = (unsigned int)" stales that didn't match current hash" >> 16;
  snprintf(s, 0x10u, v3, a1->pool_no);
  RenameThread(s);
  v4 = tq_new();
  a1->stratum_q = v4;
  if ( !v4 )
  {
    LOWORD(v75) = 2796;
    HIWORD(v75) = (unsigned int)" didn't match current hash" >> 16;
    v76 = *v75;
    v77 = v75[1];
    v78 = v75[2];
    v79 = v75[3];
    v80 = v75 + 4;
    v147 = v76;
    v148 = v77;
    v149 = v78;
    v150 = v79;
    v81 = &v151;
    goto LABEL_64;
  }
  v5 = v4;
  memset(v146, 0, sizeof(v146));
  if ( !a1->removed )
  {
    stratum_q = v5;
    while ( 1 )
    {
      v7 = tq_pop(stratum_q, 0);
      if ( !v7 )
        break;
      v8 = (char *)calloc(0x34u, 1u);
      if ( !v8 )
      {
        LOWORD(v56) = 2876;
        HIWORD(v56) = (unsigned int)"hread" >> 16;
        snprintf((char *)&v147, 0x1000u, v56, &_func___15760.__align + 4);
        goto LABEL_38;
      }
      *((_DWORD *)v8 + 11) = time(0);
      *((_DWORD *)v8 + 9) = v7;
      v9 = bin2hex((const unsigned __int8 *)v7 + 332, 0x20u);
      v10 = bin2hex((const unsigned __int8 *)v7 + 364, 0x543u);
      if ( pthread_mutex_lock(&sshare_lock) )
      {
        v93 = _errno_location();
        LOWORD(v95) = -3136;
        v94 = *v93;
        HIWORD(v95) = (unsigned int)"iner" >> 16;
        v96 = 7288;
        goto LABEL_70;
      }
      v11 = swork_id;
      *((_DWORD *)v8 + 10) = swork_id;
      swork_id = v11 + 1;
      if ( pthread_mutex_unlock(&sshare_lock) )
      {
        v98 = _errno_location();
        LOWORD(v100) = -3136;
        v99 = *v98;
        HIWORD(v100) = (unsigned int)"iner" >> 16;
        v101 = 7291;
        goto LABEL_72;
      }
      selective_yield();
      v12 = strlen(*((const char **)v7 + 452));
      LOWORD(v13) = 2908;
      HIWORD(v13) = (unsigned int)" work" >> 16;
      snprintf(
        v146,
        0x1000u,
        v13,
        *((_DWORD *)v8 + 10),
        a1->rpc_user,
        *((_DWORD *)v7 + 444),
        *((_DWORD *)v7 + 449),
        &v9[v12],
        v10);
      free(v9);
      free(v10);
      while ( 1 )
      {
        v14 = *((_DWORD *)v8 + 11) + 119;
        if ( v14 < time(0) )
          goto LABEL_29;
        v15 = strlen(v146);
        if ( stratum_send(a1, v146, v15) )
        {
          if ( !pthread_mutex_lock(&sshare_lock) )
          {
            v16 = stratum_shares;
            LODWORD(v17) = v8 + 40;
            HIDWORD(v17) = 4;
            *((_DWORD *)v8 + 2) = 0;
            *(_QWORD *)(v8 + 20) = v17;
            if ( v16 )
            {
              v16->hh.tbl->tail->next = v8;
              *((_DWORD *)v8 + 1) = (char *)v16->hh.tbl->tail - v16->hh.tbl->hho;
              v16->hh.tbl->tail = (UT_hash_handle *)v8;
              tbl = v16->hh.tbl;
              goto LABEL_14;
            }
            *((_DWORD *)v8 + 1) = 0;
            stratum_shares = (stratum_share *)v8;
            v91 = (UT_hash_table *)malloc(0x2Cu);
            tbl = v91;
            *(_DWORD *)v8 = v91;
            if ( v91 )
            {
              memset(&v91->num_items, 0, 0x20u);
              tbl->num_buckets = 32;
              tbl->tail = (UT_hash_handle *)v8;
              tbl->hho = 0;
              tbl->log2_num_buckets = 5;
              v92 = (UT_hash_bucket *)calloc(0x180u, 1u);
              tbl->buckets = v92;
              if ( v92 )
              {
                v16 = (stratum_share *)v8;
                tbl->signature = -1609490463;
LABEL_14:
                ++tbl->num_items;
                v19 = (unsigned __int8)v8[41];
                v20 = (unsigned __int8)v8[40]
                    + 17973517
                    + ((unsigned __int8)v8[43] << 24)
                    + ((unsigned __int8)v8[42] << 16);
                *(_DWORD *)v8 = v16->hh.tbl;
                v21 = (v20 + (v19 << 8)) ^ 0x7F76D;
                v22 = (-1622558010 - v21) ^ (v21 << 8);
                v23 = (-17973517 - v21 - v22) ^ (v22 >> 13);
                v24 = (v21 - v22 - v23) ^ (v23 >> 12);
                v25 = (v22 - v23 - v24) ^ (v24 << 16);
                v26 = (v23 - v24 - v25) ^ (v25 >> 5);
                v27 = v24 - v25 - v26;
                v28 = (v26 - (v27 ^ (v26 >> 3)) - ((v25 - v26 - (v27 ^ (v26 >> 3))) ^ ((v27 ^ (v26 >> 3)) << 10)))
                    ^ (((v25 - v26 - (v27 ^ (v26 >> 3))) ^ ((v27 ^ (v26 >> 3)) << 10)) >> 15);
                *((_DWORD *)v8 + 7) = v28;
                v29 = *(_QWORD *)&v16->hh.tbl->buckets;
                v30 = v28 & (HIDWORD(v29) - 1);
                ++*(_DWORD *)(v29 + v30 * 12 + 4);
                hh_head = v16->hh.tbl->buckets[v30].hh_head;
                *((_DWORD *)v8 + 3) = 0;
                *((_DWORD *)v8 + 4) = hh_head;
                buckets = v16->hh.tbl->buckets;
                v33 = buckets[v30].hh_head;
                v34 = &buckets[v30];
                if ( v33 )
                {
                  v33->hh_prev = (UT_hash_handle *)v8;
                  v34 = &v16->hh.tbl->buckets[v30];
                }
                v34->hh_head = (UT_hash_handle *)v8;
                v35 = *(_QWORD *)&v16->hh.tbl->buckets[v30].count;
                if ( (unsigned int)v35 < 10 * (HIDWORD(v35) + 1)
                  || (v36 = *(_DWORD *)v8, *(_DWORD *)(*(_DWORD *)v8 + 36) == 1) )
                {
LABEL_18:
                  ++a1->sshares;
                  if ( !pthread_mutex_unlock(&sshare_lock) )
                  {
                    selective_yield();
                    if ( !pool_tclear((int)a1, &a1->submit_fail) )
                      goto LABEL_24;
                    if ( use_syslog || opt_log_output || opt_log_level > 3 )
                    {
                      LOWORD(v37) = 2988;
                      HIWORD(v37) = (unsigned int)"arams\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"]}" >> 16;
                      snprintf((char *)&v147, 0x1000u, v37, a1->pool_no);
                      applog(4, (const char *)&v147, 0);
LABEL_24:
                      if ( !opt_debug )
                        goto LABEL_29;
                      if ( !use_syslog && !opt_log_output )
                      {
LABEL_27:
                        if ( opt_log_level <= 6 )
                          goto LABEL_29;
                      }
                      LOWORD(v38) = 3036;
                      HIWORD(v38) = (unsigned int)"communication resumed, submitting work" >> 16;
                      v39 = *v38;
                      v40 = v38[1];
                      v41 = v38[2];
                      v42 = v38[3];
                      v38 += 4;
                      v147 = v39;
                      v148 = v40;
                      v149 = v41;
                      v150 = v42;
                      v43 = *v38;
                      v44 = v38[1];
                      v45 = v38[2];
                      v46 = v38[3];
                      v38 += 4;
                      v151 = v43;
                      v152 = v44;
                      v153 = v45;
                      v154 = v46;
                      v47 = *v38;
                      v48 = v38[1];
                      v49 = v38[2];
                      v50 = v38[3];
                      v51 = v38[4];
                      v155 = v47;
                      v156 = v48;
                      v157 = v49;
                      v158 = v50;
                      v159 = v51;
                      applog(7, (const char *)&v147, 0);
                      goto LABEL_29;
                    }
                    if ( !opt_debug )
                      goto LABEL_29;
                    goto LABEL_27;
                  }
                  v105 = _errno_location();
                  LOWORD(v100) = -3136;
                  v99 = *v105;
                  HIWORD(v100) = (unsigned int)"iner" >> 16;
                  v101 = 7309;
LABEL_72:
                  LOWORD(v102) = -920;
                  HIWORD(v102) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
                  snprintf((char *)&v147, 0x1000u, v102, v99, v100, &_func___15760.__align + 4, v101);
LABEL_38:
                  applog(3, (const char *)&v147, 1);
                  _quit(1, 1);
                }
                v57 = calloc(24 * *(_DWORD *)(v36 + 4), 1u);
                if ( v57 )
                {
                  v58 = *(_DWORD *)(v36 + 12);
                  v59 = v58 >> (*(_QWORD *)(v36 + 8) + 1);
                  if ( ((2 * *(_DWORD *)(v36 + 4) - 1) & v58) != 0 )
                    ++v59;
                  *(_DWORD *)(v36 + 24) = v59;
                  *(_DWORD *)(*(_DWORD *)v8 + 28) = 0;
                  v60 = *(_DWORD *)v8;
                  v61 = *(_DWORD *)(*(_DWORD *)v8 + 4);
                  if ( v61 )
                  {
                    v144 = a1;
                    v62 = 0;
                    v63 = v8;
                    v143 = 0;
                    do
                    {
                      v64 = *(_DWORD **)(*(_DWORD *)v60 + v143);
                      if ( v64 )
                      {
                        while ( 1 )
                        {
                          v65 = (_DWORD *)v64[4];
                          v66 = 3 * ((2 * v61 - 1) & v64[7]);
                          v67 = (char *)&v57[v66];
                          v68 = *((_DWORD *)v67 + 1) + 1;
                          *((_DWORD *)v67 + 1) = v68;
                          if ( v68 > *(_DWORD *)(v60 + 24) )
                          {
                            ++*(_DWORD *)(v60 + 28);
                            *((_DWORD *)v67 + 2) = *((_DWORD *)v67 + 1) / *(_DWORD *)(*(_DWORD *)v63 + 24);
                          }
                          v64[3] = 0;
                          v64[4] = v57[v66];
                          v69 = v57[v66];
                          if ( v69 )
                            *(_DWORD *)(v69 + 12) = v64;
                          v57[v66] = v64;
                          v60 = *(_DWORD *)v63;
                          if ( !v65 )
                            break;
                          v61 = *(_DWORD *)(v60 + 4);
                          v64 = v65;
                        }
                        v61 = *(_DWORD *)(v60 + 4);
                      }
                      ++v62;
                      v143 += 12;
                    }
                    while ( v62 < v61 );
                    v8 = v63;
                    a1 = v144;
                  }
                  free(*(void **)v60);
                  *(_DWORD *)(*(_DWORD *)v8 + 4) *= 2;
                  ++*(_DWORD *)(*(_DWORD *)v8 + 8);
                  **(_DWORD **)v8 = v57;
                  v70 = *(_DWORD *)v8;
                  v71 = *(_DWORD *)(*(_DWORD *)v8 + 28);
                  v72 = *(_DWORD *)(*(_DWORD *)v8 + 12);
                  v73 = v71 > v72 >> 1;
                  if ( v71 <= v72 >> 1 )
                    v74 = 0;
                  else
                    v74 = *(_DWORD *)(v70 + 32);
                  if ( v73 )
                    ++v74;
                  *(_DWORD *)(v70 + 32) = v74;
                  if ( *(_DWORD *)(*(_DWORD *)v8 + 32) > 1u )
                    *(_DWORD *)(*(_DWORD *)v8 + 36) = 1;
                  goto LABEL_18;
                }
              }
            }
            exit(-1);
          }
          v104 = _errno_location();
          LOWORD(v95) = -3136;
          v94 = *v104;
          HIWORD(v95) = (unsigned int)"iner" >> 16;
          v96 = 7306;
LABEL_70:
          LOWORD(v97) = -968;
          HIWORD(v97) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
          snprintf((char *)&v147, 0x1000u, v97, v94, v95, &_func___15760.__align + 4, v96);
          goto LABEL_38;
        }
        if ( !pool_tset((int)a1, &a1->submit_fail) && cnx_needed(a1) )
        {
          if ( use_syslog || opt_log_output || opt_log_level > 3 )
          {
            snprintf((char *)&v147, 0x1000u, "Pool %d stratum share submission failure", a1->pool_no);
            applog(4, (const char *)&v147, 0);
          }
          v109 = a1->remotefail_occasions + 1;
          ++total_ro;
          a1->remotefail_occasions = v109;
        }
        if ( opt_lowmem )
          break;
        if ( pthread_mutex_lock(&a1->data_lock.mutex) )
        {
          v110 = _errno_location();
          LOWORD(v95) = -3136;
          v94 = *v110;
          HIWORD(v95) = (unsigned int)"iner" >> 16;
          v96 = 7330;
          goto LABEL_70;
        }
        if ( pthread_rwlock_rdlock(&a1->data_lock.rwlock) )
        {
          v111 = _errno_location();
          LOWORD(v112) = -3136;
          HIWORD(v112) = (unsigned int)"iner" >> 16;
          LOWORD(v113) = -232;
          HIWORD(v113) = (unsigned int)"" >> 16;
          snprintf((char *)&v147, 0x1000u, v113, *v111, v112, &_func___15760.__align + 4, 7330);
          goto LABEL_38;
        }
        if ( pthread_mutex_unlock(&a1->data_lock.mutex) )
        {
          v114 = _errno_location();
          LOWORD(v100) = -3136;
          v99 = *v114;
          HIWORD(v100) = (unsigned int)"iner" >> 16;
          v101 = 7330;
          goto LABEL_72;
        }
        nonce1 = a1->nonce1;
        if ( !nonce1 || strcmp(*((const char **)v7 + 452), nonce1) )
        {
          if ( !pthread_rwlock_unlock(&a1->data_lock.rwlock) )
          {
            selective_yield();
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              LOWORD(v129) = 3184;
              HIWORD(v129) = (unsigned int)"n prevents resubmitting stratum share" >> 16;
              v130 = *v129;
              v131 = v129[1];
              v132 = v129[2];
              v133 = v129[3];
              v129 += 4;
              v147 = v130;
              v148 = v131;
              v149 = v132;
              v150 = v133;
              v134 = *v129;
              v135 = v129[1];
              v136 = v129[2];
              v137 = v129[3];
              v129 += 4;
              v151 = v134;
              v152 = v135;
              v153 = v136;
              v154 = v137;
              v138 = *v129;
              v139 = v129[1];
              v140 = v129[2];
              v141 = v129[3];
              v129 += 4;
              v155 = v138;
              v156 = v139;
              v157 = v140;
              v158 = v141;
              v142 = v129[1];
              v159 = *v129;
              v160 = v142;
              applog(7, (const char *)&v147, 0);
            }
            goto LABEL_29;
          }
LABEL_87:
          v106 = _errno_location();
          LOWORD(v107) = -3136;
          HIWORD(v107) = (unsigned int)"iner" >> 16;
          LOWORD(v108) = -348;
          HIWORD(v108) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
          snprintf((char *)&v147, 0x1000u, v108, *v106, v107, &_func___15760.__align + 4, 7332);
          goto LABEL_38;
        }
        if ( pthread_rwlock_unlock(&a1->data_lock.rwlock) )
          goto LABEL_87;
        selective_yield();
        sleep(5u);
      }
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v115) = 3132;
        HIWORD(v115) = (unsigned int)" %d stratum share submission failure" >> 16;
        v116 = *v115;
        v117 = v115[1];
        v118 = v115[2];
        v119 = v115[3];
        v115 += 4;
        v147 = v116;
        v148 = v117;
        v149 = v118;
        v150 = v119;
        v120 = *v115;
        v121 = v115[1];
        v122 = v115[2];
        v123 = v115[3];
        v115 += 4;
        v151 = v120;
        v152 = v121;
        v153 = v122;
        v154 = v123;
        v124 = *v115;
        v125 = v115[1];
        v126 = v115[2];
        v127 = v115[3];
        v128 = v115[4];
        v155 = v124;
        v156 = v125;
        v157 = v126;
        v158 = v127;
        LOWORD(v159) = v128;
        applog(7, (const char *)&v147, 0);
      }
LABEL_29:
      v52 = time(0);
      v53 = opt_debug;
      *((_DWORD *)v8 + 12) = v52;
      if ( v53 && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v54) = 3240;
        HIWORD(v54) = (unsigned int)"ion id for resubmitting stratum share" >> 16;
        snprintf((char *)&v147, 0x1000u, v54, a1->pool_no, v52 - *((_DWORD *)v8 + 11));
        applog(7, (const char *)&v147, 0);
      }
      memset(v146, 0, sizeof(v146));
      stratum_q = a1->stratum_q;
      if ( a1->removed )
      {
        v5 = a1->stratum_q;
        goto LABEL_36;
      }
    }
    LOWORD(v80) = 2844;
    HIWORD(v80) = (unsigned int)"o create stratum_q in stratum_sthread" >> 16;
    v81 = &v147;
LABEL_64:
    v82 = *v80;
    v83 = v80[1];
    v84 = v80[2];
    v85 = v80[3];
    v86 = v80 + 4;
    *v81 = v82;
    v81[1] = v83;
    v81[2] = v84;
    v81[3] = v85;
    v87 = v81 + 4;
    v88 = v86[1];
    v89 = v86[2];
    v90 = v86[3];
    *v87 = *v86;
    v87[1] = v88;
    v87[2] = v89;
    *((_WORD *)v87 + 6) = v90;
    applog(3, (const char *)&v147, 1);
    _quit(1, 1);
  }
LABEL_36:
  tq_freeze(v5);
  return 0;
}
