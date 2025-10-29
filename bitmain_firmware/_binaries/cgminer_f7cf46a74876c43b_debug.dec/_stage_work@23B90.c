void __fastcall stage_work(work *work)
{
  pthread_mutex_t *v2; // r0
  thread_q *v3; // r10
  work *v4; // r5
  UT_hash_handle *p_hh; // r4
  UT_hash_table *tbl; // r7
  int v7; // r7
  unsigned int v8; // r1
  unsigned int v9; // r3
  int v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // r3
  unsigned int v13; // r0
  unsigned int v14; // r3
  __int64 v15; // r0
  unsigned int v16; // r3
  UT_hash_bucket *buckets; // r2
  UT_hash_handle *hh_head; // r1
  UT_hash_bucket *v19; // r2
  work *v20; // r5
  __int64 v21; // r2
  UT_hash_table *v22; // r4
  UT_hash_bucket *v23; // r7
  unsigned int num_items; // r0
  unsigned int v25; // r3
  UT_hash_table *v26; // r0
  unsigned int num_buckets; // r4
  int v28; // r11
  UT_hash_handle *v29; // r5
  UT_hash_handle *hh_next; // r8
  int v31; // r4
  UT_hash_bucket *v32; // r10
  unsigned int v33; // r2
  UT_hash_handle *v34; // r3
  UT_hash_table *v35; // r3
  unsigned int nonideal_items; // r2
  unsigned int v37; // r1
  bool v38; // cc
  unsigned int ineff_expands; // r2
  UT_hash_table *v40; // r3
  UT_hash_handle *v41; // r12
  int v42; // r7
  UT_hash_handle *v43; // r3
  UT_hash_handle *v44; // r2
  unsigned int v45; // lr
  UT_hash_handle *next; // r6
  ptrdiff_t hho; // r4
  int v48; // r1
  int v49; // r0
  UT_hash_handle *v50; // r4
  bool v51; // zf
  void *v52; // r9
  int v53; // r9
  char *v54; // r6
  bool v55; // zf
  UT_hash_handle *v56; // r11
  ptrdiff_t v57; // r11
  void *v58; // r6
  char *v59; // r6
  char *v60; // r6
  UT_hash_table *v61; // r0
  UT_hash_bucket *v62; // r0
  int *v63; // r0
  int *v64; // r0
  unsigned int i; // [sp+14h] [bp-1010h]
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "Pushing work from pool %d to hash queue", work->pool->pool_no);
    applog(7, tmp42, 0);
  }
  work->work_block = work_block;
  test_work_current((int)work);
  v2 = stgd_lock;
  ++work->pool->works;
  if ( pthread_mutex_lock(v2) )
  {
    v64 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v64, "cgminer.c", "hash_push", 5533);
LABEL_102:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  if ( !work->clone && work->rolltime )
    ++staged_rollable;
  v3 = getq;
  if ( getq->frozen )
    goto LABEL_90;
  v4 = staged_work;
  work->hh.next = (void *)getq->frozen;
  work->hh.key = &work->id;
  work->hh.keylen = 4;
  if ( v4 )
  {
    p_hh = &work->hh;
    v4->hh.tbl->tail->next = work;
    work->hh.prev = (char *)v4->hh.tbl->tail - v4->hh.tbl->hho;
    v4->hh.tbl->tail = &work->hh;
    tbl = v4->hh.tbl;
  }
  else
  {
    work->hh.prev = 0;
    staged_work = work;
    v61 = (UT_hash_table *)malloc(0x2Cu);
    tbl = v61;
    work->hh.tbl = v61;
    if ( !v61 )
      goto LABEL_104;
    memset(&v61->num_items, 0, 0x20u);
    p_hh = &work->hh;
    tbl->num_buckets = 32;
    tbl->tail = &work->hh;
    tbl->log2_num_buckets = 5;
    tbl->hho = 1832;
    v62 = (UT_hash_bucket *)calloc(0x180u, 1u);
    tbl->buckets = v62;
    if ( !v62 )
      goto LABEL_104;
    v4 = work;
    tbl->signature = -1609490463;
  }
  ++tbl->num_items;
  v7 = LOBYTE(work->id) + 17973517 + (HIBYTE(work->id) << 24) + (BYTE2(work->id) << 16) + (BYTE1(work->id) << 8);
  v8 = (-1622558010 - (v7 ^ 0x7F76D)) ^ ((v7 ^ 0x7F76D) << 8);
  work->hh.tbl = v4->hh.tbl;
  v9 = (-17973517 - (v7 ^ 0x7F76D) - v8) ^ (v8 >> 13);
  v10 = ((v7 ^ 0x7F76D) - v8 - v9) ^ (v9 >> 12);
  v11 = (v8 - v9 - v10) ^ (v10 << 16);
  v12 = (v9 - v10 - v11) ^ (v11 >> 5);
  v13 = v10 - v11 - v12;
  v14 = (v12 - (v13 ^ (v12 >> 3)) - ((v11 - v12 - (v13 ^ (v12 >> 3))) ^ ((v13 ^ (v12 >> 3)) << 10)))
      ^ (((v11 - v12 - (v13 ^ (v12 >> 3))) ^ ((v13 ^ (v12 >> 3)) << 10)) >> 15);
  work->hh.hashv = v14;
  v15 = *(_QWORD *)&v4->hh.tbl->buckets;
  v16 = v14 & (HIDWORD(v15) - 1);
  ++*(_DWORD *)(v15 + v16 * 12 + 4);
  HIDWORD(v15) = v4->hh.tbl->buckets[v16].hh_head;
  work->hh.hh_prev = 0;
  work->hh.hh_next = (UT_hash_handle *)HIDWORD(v15);
  buckets = v4->hh.tbl->buckets;
  hh_head = buckets[v16].hh_head;
  v19 = &buckets[v16];
  if ( hh_head )
  {
    hh_head->hh_prev = p_hh;
    v19 = &v4->hh.tbl->buckets[v16];
  }
  v19->hh_head = p_hh;
  v20 = staged_work;
  v21 = *(_QWORD *)&staged_work->hh.tbl->buckets[v16].count;
  if ( (unsigned int)v21 >= 10 * (HIDWORD(v21) + 1) )
  {
    v22 = work->hh.tbl;
    if ( v22->noexpand != 1 )
    {
      v23 = (UT_hash_bucket *)calloc(24 * v22->num_buckets, 1u);
      if ( v23 )
      {
        num_items = v22->num_items;
        v25 = num_items >> (*(_QWORD *)&v22->log2_num_buckets + 1);
        if ( ((2 * v22->num_buckets - 1) & num_items) != 0 )
          ++v25;
        v22->ideal_chain_maxlen = v25;
        work->hh.tbl->nonideal_items = 0;
        v26 = work->hh.tbl;
        num_buckets = v26->num_buckets;
        if ( num_buckets )
        {
          v28 = 0;
          for ( i = 0; i < num_buckets; ++i )
          {
            v29 = v26->buckets[v28].hh_head;
            if ( v29 )
            {
              while ( 1 )
              {
                hh_next = v29->hh_next;
                v31 = (2 * num_buckets - 1) & v29->hashv;
                v32 = &v23[v31];
                v33 = v32->count + 1;
                v32->count = v33;
                if ( v33 > v26->ideal_chain_maxlen )
                {
                  ++v26->nonideal_items;
                  v32->expand_mult = v32->count / work->hh.tbl->ideal_chain_maxlen;
                }
                v29->hh_prev = 0;
                v29->hh_next = v23[v31].hh_head;
                v34 = v23[v31].hh_head;
                if ( v34 )
                  v34->hh_prev = v29;
                v23[v31].hh_head = v29;
                v26 = work->hh.tbl;
                if ( !hh_next )
                  break;
                num_buckets = v26->num_buckets;
                v29 = hh_next;
              }
              num_buckets = v26->num_buckets;
            }
            ++v28;
          }
        }
        free(v26->buckets);
        work->hh.tbl->num_buckets *= 2;
        ++work->hh.tbl->log2_num_buckets;
        work->hh.tbl->buckets = v23;
        v35 = work->hh.tbl;
        v20 = staged_work;
        nonideal_items = v35->nonideal_items;
        v37 = v35->num_items;
        v38 = nonideal_items > v37 >> 1;
        if ( nonideal_items <= v37 >> 1 )
          ineff_expands = 0;
        else
          ineff_expands = v35->ineff_expands;
        if ( v38 )
          ++ineff_expands;
        v35->ineff_expands = ineff_expands;
        v40 = work->hh.tbl;
        if ( v40->ineff_expands > 1 )
          v40->noexpand = 1;
        v3 = getq;
        if ( !v20 )
          goto LABEL_90;
        goto LABEL_40;
      }
LABEL_104:
      exit(-1);
    }
  }
  v3 = getq;
LABEL_40:
  v41 = &v20->hh;
  v42 = 1;
  while ( 2 )
  {
    v43 = v41;
    v41 = 0;
    v44 = 0;
    v45 = 0;
    do
    {
      ++v45;
      if ( v42 )
      {
        next = (UT_hash_handle *)v43->next;
        if ( next && (hho = v20->hh.tbl->hho, (next = (UT_hash_handle *)((char *)next + hho)) != 0) )
        {
          v48 = 1;
          do
          {
            if ( v48 == v42 )
            {
              v49 = v48;
              goto LABEL_50;
            }
            next = (UT_hash_handle *)next->next;
            ++v48;
            if ( !next )
              break;
            next = (UT_hash_handle *)((char *)next + hho);
          }
          while ( next );
          v49 = v42;
        }
        else
        {
          v49 = v42;
          v48 = 1;
        }
      }
      else
      {
        next = v43;
        v49 = 0;
        v48 = 0;
      }
LABEL_50:
      v50 = v43;
      v43 = next;
      while ( v48 )
      {
        v55 = v43 == 0;
        if ( v43 )
          v55 = v49 == 0;
        if ( v55 )
        {
          if ( v50 )
          {
            v56 = (UT_hash_handle *)v50->next;
            if ( v56 )
              v56 = (UT_hash_handle *)((char *)v56 + v20->hh.tbl->hho);
LABEL_68:
            --v48;
            if ( v44 )
              goto LABEL_69;
            goto LABEL_79;
          }
        }
        else
        {
          v57 = v20->hh.tbl->hho;
          if ( (signed int)(*(unsigned int *)((char *)&v50[54].keylen - v57)
                          - *(unsigned int *)((char *)&v43[54].keylen - v57)) > 0 )
          {
            v58 = v43->next;
            v53 = (int)v58 + v57;
            if ( v58 )
              goto LABEL_57;
            v53 = 0;
            --v49;
            if ( !v44 )
            {
LABEL_74:
              v44 = v43;
              v43 = (UT_hash_handle *)v53;
              goto LABEL_75;
            }
LABEL_58:
            v44->next = (char *)v43 - v20->hh.tbl->hho;
            if ( v43 )
              goto LABEL_59;
            v44 = 0;
            v43 = (UT_hash_handle *)v53;
            continue;
          }
          if ( v50 )
          {
            v59 = (char *)v50->next;
            v56 = (UT_hash_handle *)&v59[v57];
            if ( !v59 )
              v56 = 0;
            goto LABEL_68;
          }
        }
        v56 = v50;
        --v48;
        if ( v44 )
        {
LABEL_69:
          if ( v50 )
          {
            v53 = (int)v43;
            v43 = v50;
            v60 = (char *)v50 - v20->hh.tbl->hho;
            v50 = v56;
            v44->next = v60;
LABEL_59:
            v54 = (char *)v44 - v20->hh.tbl->hho;
            v44 = v43;
            v43 = (UT_hash_handle *)v53;
            goto LABEL_60;
          }
          v44->next = 0;
          v44 = 0;
          v50 = v56;
          continue;
        }
LABEL_79:
        v44 = v50;
        v50 = v56;
LABEL_75:
        v41 = v44;
        v54 = 0;
        if ( !v44 )
          continue;
LABEL_60:
        v44->prev = v54;
      }
      v51 = v49 == 0;
      if ( v49 )
        v51 = v43 == 0;
      if ( !v51 )
      {
        v52 = v43->next;
        if ( v52 )
          v53 = (int)v52 + v20->hh.tbl->hho;
        else
          v53 = v48;
LABEL_57:
        --v49;
        if ( !v44 )
          goto LABEL_74;
        goto LABEL_58;
      }
    }
    while ( v43 );
    if ( v44 )
      v44->next = 0;
    if ( v45 > 1 )
    {
      v42 *= 2;
      if ( !v41 )
      {
        v44 = 0;
        break;
      }
      continue;
    }
    break;
  }
  v20->hh.tbl->tail = v44;
  staged_work = (work *)((char *)v41 - v20->hh.tbl->hho);
LABEL_90:
  pthread_cond_broadcast(&v3->cond);
  if ( pthread_mutex_unlock(stgd_lock) )
  {
    v63 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v63, "cgminer.c", "hash_push", 5544);
    goto LABEL_102;
  }
  selective_yield();
}
