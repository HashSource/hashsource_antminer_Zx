int __fastcall stratum_sthread(pool *a1)
{
  pthread_t v2; // r0
  thread_q *v3; // r0
  thread_q *v4; // r4
  thread_q *stratum_q; // r0
  void *v6; // r4
  char *v7; // r6
  char *v8; // r8
  char *v9; // r7
  int v10; // r2
  size_t v11; // r0
  time_t v12; // r8
  ssize_t v13; // r0
  stratum_share *v14; // r4
  __int64 v15; // r2
  UT_hash_table *tbl; // r5
  int v17; // r5
  int v18; // r3
  int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r3
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r3
  unsigned int v25; // r1
  unsigned int v26; // r3
  __int64 v27; // kr00_8
  int v28; // r0
  UT_hash_handle *hh_head; // r1
  UT_hash_bucket *buckets; // r2
  UT_hash_handle *v31; // r3
  UT_hash_bucket *v32; // r2
  __int64 v33; // r2
  int v34; // r4
  time_t v35; // r0
  _BOOL4 v36; // r3
  _DWORD *v38; // r7
  unsigned int v39; // r1
  unsigned int v40; // r3
  int v41; // r1
  unsigned int v42; // r4
  unsigned int v43; // r10
  char *v44; // r9
  _DWORD *v45; // r5
  _DWORD *v46; // r6
  int v47; // r4
  char *v48; // r8
  unsigned int v49; // r2
  int v50; // r3
  int v51; // r3
  unsigned int v52; // r2
  unsigned int v53; // r1
  bool v54; // cc
  int v55; // r2
  char *v56; // r5
  char *v57; // r4
  int v58; // r0
  int v59; // r1
  int v60; // r2
  int v61; // r3
  _DWORD *v62; // r5
  char *v63; // r4
  int v64; // r1
  int v65; // r2
  int v66; // r3
  UT_hash_table *v67; // r0
  UT_hash_bucket *v68; // r0
  int v69; // r3
  int v70; // r4
  int v71; // r3
  int v72; // r4
  char *nonce1; // r1
  int v74; // r3
  unsigned int v75; // r3
  int v76; // r3
  int v77; // [sp+18h] [bp-2034h]
  pool *v78; // [sp+30h] [bp-201Ch]
  char s[16]; // [sp+38h] [bp-2014h] BYREF
  char v80[4096]; // [sp+48h] [bp-2004h] BYREF
  char v81[4100]; // [sp+1048h] [bp-1004h] BYREF

  v2 = pthread_self();
  pthread_detach(v2);
  snprintf(s, 0x10u, "%d/SStratum", a1->pool_no);
  RenameThread(s);
  v3 = tq_new();
  a1->stratum_q = v3;
  if ( !v3 )
  {
    v56 = " stratum_q in stratum_sthread";
    qmemcpy(v81, "Failed to create", 16);
    v57 = &v81[16];
    goto LABEL_64;
  }
  v4 = v3;
  memset(v80, 0, sizeof(v80));
  if ( !a1->removed )
  {
    stratum_q = v4;
    while ( 1 )
    {
      v6 = tq_pop(stratum_q, 0);
      if ( !v6 )
        break;
      v7 = (char *)calloc(0x34u, 1u);
      if ( !v7 )
      {
        snprintf(v81, 0x1000u, "%s: calloc() failed on sshare.", &_func___15760.__size[16]);
        goto LABEL_38;
      }
      *((_DWORD *)v7 + 11) = time(0);
      *((_DWORD *)v7 + 9) = v6;
      v8 = bin2hex((const unsigned __int8 *)v6 + 332, 0x20u);
      v9 = bin2hex((const unsigned __int8 *)v6 + 364, 0x543u);
      if ( pthread_mutex_lock(&sshare_lock) )
      {
        v69 = *_errno_location();
        v70 = 7288;
        goto LABEL_70;
      }
      v10 = swork_id;
      *((_DWORD *)v7 + 10) = swork_id;
      swork_id = v10 + 1;
      if ( pthread_mutex_unlock(&sshare_lock) )
      {
        v71 = *_errno_location();
        v72 = 7291;
        goto LABEL_72;
      }
      selective_yield();
      v11 = strlen(*((const char **)v6 + 452));
      snprintf(
        v80,
        0x1000u,
        "{\"id\": %d, \"method\": \"mining.submit\", \"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"]}",
        *((_DWORD *)v7 + 10),
        a1->rpc_user,
        *((const char **)v6 + 444),
        *((const char **)v6 + 449),
        &v8[v11],
        v9);
      free(v8);
      free(v9);
      while ( 1 )
      {
        v12 = *((_DWORD *)v7 + 11) + 119;
        if ( v12 < time(0) )
          goto LABEL_29;
        v13 = strlen(v80);
        if ( stratum_send(a1, v80, v13) )
        {
          if ( !pthread_mutex_lock(&sshare_lock) )
          {
            v14 = stratum_shares;
            LODWORD(v15) = v7 + 40;
            HIDWORD(v15) = 4;
            *((_DWORD *)v7 + 2) = 0;
            *(_QWORD *)(v7 + 20) = v15;
            if ( v14 )
            {
              v14->hh.tbl->tail->next = v7;
              *((_DWORD *)v7 + 1) = (char *)v14->hh.tbl->tail - v14->hh.tbl->hho;
              v14->hh.tbl->tail = (UT_hash_handle *)v7;
              tbl = v14->hh.tbl;
              goto LABEL_14;
            }
            *((_DWORD *)v7 + 1) = 0;
            stratum_shares = (stratum_share *)v7;
            v67 = (UT_hash_table *)malloc(0x2Cu);
            tbl = v67;
            *(_DWORD *)v7 = v67;
            if ( v67 )
            {
              memset(&v67->num_items, 0, 0x20u);
              tbl->num_buckets = 32;
              tbl->tail = (UT_hash_handle *)v7;
              tbl->hho = 0;
              tbl->log2_num_buckets = 5;
              v68 = (UT_hash_bucket *)calloc(0x180u, 1u);
              tbl->buckets = v68;
              if ( v68 )
              {
                v14 = (stratum_share *)v7;
                tbl->signature = -1609490463;
LABEL_14:
                ++tbl->num_items;
                v17 = (unsigned __int8)v7[41];
                v18 = (unsigned __int8)v7[40]
                    + 17973517
                    + ((unsigned __int8)v7[43] << 24)
                    + ((unsigned __int8)v7[42] << 16);
                *(_DWORD *)v7 = v14->hh.tbl;
                v19 = (v18 + (v17 << 8)) ^ 0x7F76D;
                v20 = (-1622558010 - v19) ^ (v19 << 8);
                v21 = (-17973517 - v19 - v20) ^ (v20 >> 13);
                v22 = (v19 - v20 - v21) ^ (v21 >> 12);
                v23 = (v20 - v21 - v22) ^ (v22 << 16);
                v24 = (v21 - v22 - v23) ^ (v23 >> 5);
                v25 = v22 - v23 - v24;
                v26 = (v24 - (v25 ^ (v24 >> 3)) - ((v23 - v24 - (v25 ^ (v24 >> 3))) ^ ((v25 ^ (v24 >> 3)) << 10)))
                    ^ (((v23 - v24 - (v25 ^ (v24 >> 3))) ^ ((v25 ^ (v24 >> 3)) << 10)) >> 15);
                *((_DWORD *)v7 + 7) = v26;
                v27 = *(_QWORD *)&v14->hh.tbl->buckets;
                v28 = v26 & (HIDWORD(v27) - 1);
                ++*(_DWORD *)(v27 + v28 * 12 + 4);
                hh_head = v14->hh.tbl->buckets[v28].hh_head;
                *((_DWORD *)v7 + 3) = 0;
                *((_DWORD *)v7 + 4) = hh_head;
                buckets = v14->hh.tbl->buckets;
                v31 = buckets[v28].hh_head;
                v32 = &buckets[v28];
                if ( v31 )
                {
                  v31->hh_prev = (UT_hash_handle *)v7;
                  v32 = &v14->hh.tbl->buckets[v28];
                }
                v32->hh_head = (UT_hash_handle *)v7;
                v33 = *(_QWORD *)&v14->hh.tbl->buckets[v28].count;
                if ( (unsigned int)v33 < 10 * (HIDWORD(v33) + 1)
                  || (v34 = *(_DWORD *)v7, *(_DWORD *)(*(_DWORD *)v7 + 36) == 1) )
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
                      snprintf(v81, 0x1000u, "Pool %d communication resumed, submitting work", a1->pool_no);
                      applog(4, v81, 0);
LABEL_24:
                      if ( !opt_debug )
                        goto LABEL_29;
                      if ( !use_syslog && !opt_log_output )
                      {
LABEL_27:
                        if ( opt_log_level <= 6 )
                          goto LABEL_29;
                      }
                      strcpy(v81, "Successfully submitted, adding to stratum_shares db");
                      applog(7, v81, 0);
                      goto LABEL_29;
                    }
                    if ( !opt_debug )
                      goto LABEL_29;
                    goto LABEL_27;
                  }
                  v71 = *_errno_location();
                  v72 = 7309;
LABEL_72:
                  snprintf(
                    v81,
                    0x1000u,
                    "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
                    v71,
                    "cgminer.c",
                    &_func___15760.__align + 4,
                    v72);
LABEL_38:
                  applog(3, v81, 1);
                  _quit(1, 1);
                }
                v38 = calloc(24 * *(_DWORD *)(v34 + 4), 1u);
                if ( v38 )
                {
                  v39 = *(_DWORD *)(v34 + 12);
                  v40 = v39 >> (*(_QWORD *)(v34 + 8) + 1);
                  if ( ((2 * *(_DWORD *)(v34 + 4) - 1) & v39) != 0 )
                    ++v40;
                  *(_DWORD *)(v34 + 24) = v40;
                  *(_DWORD *)(*(_DWORD *)v7 + 28) = 0;
                  v41 = *(_DWORD *)v7;
                  v42 = *(_DWORD *)(*(_DWORD *)v7 + 4);
                  if ( v42 )
                  {
                    v78 = a1;
                    v43 = 0;
                    v44 = v7;
                    v77 = 0;
                    do
                    {
                      v45 = *(_DWORD **)(*(_DWORD *)v41 + v77);
                      if ( v45 )
                      {
                        while ( 1 )
                        {
                          v46 = (_DWORD *)v45[4];
                          v47 = 3 * ((2 * v42 - 1) & v45[7]);
                          v48 = (char *)&v38[v47];
                          v49 = *((_DWORD *)v48 + 1) + 1;
                          *((_DWORD *)v48 + 1) = v49;
                          if ( v49 > *(_DWORD *)(v41 + 24) )
                          {
                            ++*(_DWORD *)(v41 + 28);
                            *((_DWORD *)v48 + 2) = *((_DWORD *)v48 + 1) / *(_DWORD *)(*(_DWORD *)v44 + 24);
                          }
                          v45[3] = 0;
                          v45[4] = v38[v47];
                          v50 = v38[v47];
                          if ( v50 )
                            *(_DWORD *)(v50 + 12) = v45;
                          v38[v47] = v45;
                          v41 = *(_DWORD *)v44;
                          if ( !v46 )
                            break;
                          v42 = *(_DWORD *)(v41 + 4);
                          v45 = v46;
                        }
                        v42 = *(_DWORD *)(v41 + 4);
                      }
                      ++v43;
                      v77 += 12;
                    }
                    while ( v43 < v42 );
                    v7 = v44;
                    a1 = v78;
                  }
                  free(*(void **)v41);
                  *(_DWORD *)(*(_DWORD *)v7 + 4) *= 2;
                  ++*(_DWORD *)(*(_DWORD *)v7 + 8);
                  **(_DWORD **)v7 = v38;
                  v51 = *(_DWORD *)v7;
                  v52 = *(_DWORD *)(*(_DWORD *)v7 + 28);
                  v53 = *(_DWORD *)(*(_DWORD *)v7 + 12);
                  v54 = v52 > v53 >> 1;
                  if ( v52 <= v53 >> 1 )
                    v55 = 0;
                  else
                    v55 = *(_DWORD *)(v51 + 32);
                  if ( v54 )
                    ++v55;
                  *(_DWORD *)(v51 + 32) = v55;
                  if ( *(_DWORD *)(*(_DWORD *)v7 + 32) > 1u )
                    *(_DWORD *)(*(_DWORD *)v7 + 36) = 1;
                  goto LABEL_18;
                }
              }
            }
            exit(-1);
          }
          v69 = *_errno_location();
          v70 = 7306;
LABEL_70:
          snprintf(
            v81,
            0x1000u,
            "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
            v69,
            "cgminer.c",
            &_func___15760.__align + 4,
            v70);
          goto LABEL_38;
        }
        if ( !pool_tset((int)a1, &a1->submit_fail) && cnx_needed(a1) )
        {
          if ( use_syslog || opt_log_output || opt_log_level > 3 )
          {
            snprintf(v81, 0x1000u, "Pool %d stratum share submission failure", a1->pool_no);
            applog(4, v81, 0);
          }
          v75 = a1->remotefail_occasions + 1;
          ++total_ro;
          a1->remotefail_occasions = v75;
        }
        if ( opt_lowmem )
          break;
        if ( pthread_mutex_lock(&a1->data_lock.mutex) )
        {
          v69 = *_errno_location();
          v70 = 7330;
          goto LABEL_70;
        }
        if ( pthread_rwlock_rdlock(&a1->data_lock.rwlock) )
        {
          v76 = *_errno_location();
          snprintf(
            v81,
            0x1000u,
            "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
            v76,
            "cgminer.c",
            &_func___15760.__align + 4,
            7330);
          goto LABEL_38;
        }
        if ( pthread_mutex_unlock(&a1->data_lock.mutex) )
        {
          v71 = *_errno_location();
          v72 = 7330;
          goto LABEL_72;
        }
        nonce1 = a1->nonce1;
        if ( !nonce1 || strcmp(*((const char **)v6 + 452), nonce1) )
        {
          if ( !pthread_rwlock_unlock(&a1->data_lock.rwlock) )
          {
            selective_yield();
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              strcpy(v81, "No matching session id for resubmitting stratum share");
              applog(7, v81, 0);
            }
            goto LABEL_29;
          }
LABEL_87:
          v74 = *_errno_location();
          snprintf(
            v81,
            0x1000u,
            "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
            v74,
            "cgminer.c",
            &_func___15760.__align + 4,
            7332);
          goto LABEL_38;
        }
        if ( pthread_rwlock_unlock(&a1->data_lock.rwlock) )
          goto LABEL_87;
        selective_yield();
        sleep(5u);
      }
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        strcpy(v81, "Lowmem option prevents resubmitting stratum share");
        applog(7, v81, 0);
      }
LABEL_29:
      v35 = time(0);
      v36 = opt_debug;
      *((_DWORD *)v7 + 12) = v35;
      if ( v36 && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(
          v81,
          0x1000u,
          "Pool %d stratum share submission lag time %d seconds",
          a1->pool_no,
          v35 - *((_DWORD *)v7 + 11));
        applog(7, v81, 0);
      }
      memset(v80, 0, sizeof(v80));
      stratum_q = a1->stratum_q;
      if ( a1->removed )
      {
        v4 = a1->stratum_q;
        goto LABEL_36;
      }
    }
    v56 = "Stratum q returned empty work";
    v57 = v81;
LABEL_64:
    v58 = *(_DWORD *)v56;
    v59 = *((_DWORD *)v56 + 1);
    v60 = *((_DWORD *)v56 + 2);
    v61 = *((_DWORD *)v56 + 3);
    v62 = v56 + 16;
    *(_DWORD *)v57 = v58;
    *((_DWORD *)v57 + 1) = v59;
    *((_DWORD *)v57 + 2) = v60;
    *((_DWORD *)v57 + 3) = v61;
    v63 = v57 + 16;
    v64 = v62[1];
    v65 = v62[2];
    v66 = v62[3];
    *(_DWORD *)v63 = *v62;
    *((_DWORD *)v63 + 1) = v64;
    *((_DWORD *)v63 + 2) = v65;
    *((_WORD *)v63 + 6) = v66;
    applog(3, v81, 1);
    _quit(1, 1);
  }
LABEL_36:
  tq_freeze(v4);
  return 0;
}
