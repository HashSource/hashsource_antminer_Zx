void __fastcall _add_queued(cgpu_info *cgpu, work *work)
{
  work *queued_work; // r5
  UT_hash_handle *p_hh; // r1
  __int64 v6; // kr00_8
  int v7; // r5
  unsigned int v8; // r2
  unsigned int v9; // r3
  int v10; // r5
  unsigned int v11; // r2
  unsigned int v12; // r3
  unsigned int v13; // r5
  unsigned int v14; // r3
  UT_hash_bucket *v15; // r5
  unsigned int v16; // r3
  UT_hash_handle *hh_head; // r2
  UT_hash_bucket *v18; // r2
  UT_hash_handle *v19; // r0
  UT_hash_bucket *v20; // r2
  __int64 v21; // r2
  UT_hash_table *v22; // r4
  UT_hash_bucket *v23; // r6
  int v24; // r7
  unsigned int num_items; // r1
  unsigned int v26; // r3
  UT_hash_table *v27; // r2
  unsigned int num_buckets; // r4
  UT_hash_handle *v29; // r5
  UT_hash_handle *hh_next; // r11
  int v31; // r4
  UT_hash_bucket *v32; // r8
  unsigned int v33; // r0
  UT_hash_handle *v34; // r3
  UT_hash_table *v35; // r3
  unsigned int nonideal_items; // r2
  unsigned int v37; // r1
  bool v38; // cc
  unsigned int ineff_expands; // r2
  UT_hash_table *v40; // r3
  work *v41; // r6
  UT_hash_table *tbl; // r0
  UT_hash_table *v43; // r6
  UT_hash_bucket *buckets; // r0
  unsigned int _he_bkt_i; // [sp+4h] [bp-8h]

  ++cgpu->queued_count;
  work->hh.next = 0;
  work->hh.key = &work->id;
  work->hh.keylen = 4;
  queued_work = cgpu->queued_work;
  if ( queued_work )
  {
    p_hh = &work->hh;
    queued_work->hh.tbl->tail->next = work;
    v6 = *(_QWORD *)&cgpu->queued_work->hh.tbl->tail;
    work->hh.prev = (void *)(v6 - HIDWORD(v6));
    cgpu->queued_work->hh.tbl->tail = &work->hh;
  }
  else
  {
    cgpu->queued_work = work;
    work->hh.prev = 0;
    v41 = cgpu->queued_work;
    v41->hh.tbl = (UT_hash_table *)malloc(0x2Cu);
    tbl = cgpu->queued_work->hh.tbl;
    if ( !tbl )
      goto LABEL_33;
    memset(tbl, 0, sizeof(UT_hash_table));
    cgpu->queued_work->hh.tbl->tail = &cgpu->queued_work->hh;
    cgpu->queued_work->hh.tbl->num_buckets = 32;
    cgpu->queued_work->hh.tbl->log2_num_buckets = 5;
    cgpu->queued_work->hh.tbl->hho = 1832;
    v43 = cgpu->queued_work->hh.tbl;
    v43->buckets = (UT_hash_bucket *)malloc(0x180u);
    buckets = cgpu->queued_work->hh.tbl->buckets;
    if ( !buckets )
      goto LABEL_33;
    memset(buckets, 0, 0x180u);
    p_hh = &work->hh;
    cgpu->queued_work->hh.tbl->signature = -1609490463;
  }
  ++cgpu->queued_work->hh.tbl->num_items;
  v7 = (LOBYTE(work->id) + 17973517 + (HIBYTE(work->id) << 24) + (BYTE2(work->id) << 16) + (BYTE1(work->id) << 8))
     ^ 0x7F76D;
  v8 = (-1622558010 - v7) ^ (v7 << 8);
  v9 = (-17973517 - v7 - v8) ^ (v8 >> 13);
  work->hh.tbl = cgpu->queued_work->hh.tbl;
  v10 = (v7 - v8 - v9) ^ (v9 >> 12);
  v11 = (v8 - v9 - v10) ^ (v10 << 16);
  v12 = (v9 - v10 - v11) ^ (v11 >> 5);
  v13 = v10 - v11 - v12;
  v14 = (v12 - (v13 ^ (v12 >> 3)) - ((v11 - v12 - (v13 ^ (v12 >> 3))) ^ ((v13 ^ (v12 >> 3)) << 10)))
      ^ (((v11 - v12 - (v13 ^ (v12 >> 3))) ^ ((v13 ^ (v12 >> 3)) << 10)) >> 15);
  work->hh.hashv = v14;
  v15 = cgpu->queued_work->hh.tbl->buckets;
  v16 = v14 & (cgpu->queued_work->hh.tbl->num_buckets - 1);
  ++v15[v16].count;
  hh_head = cgpu->queued_work->hh.tbl->buckets[v16].hh_head;
  work->hh.hh_prev = 0;
  work->hh.hh_next = hh_head;
  v18 = cgpu->queued_work->hh.tbl->buckets;
  v19 = v18[v16].hh_head;
  v20 = &v18[v16];
  if ( v19 )
  {
    v19->hh_prev = p_hh;
    v20 = &cgpu->queued_work->hh.tbl->buckets[v16];
  }
  v20->hh_head = p_hh;
  v21 = *(_QWORD *)&cgpu->queued_work->hh.tbl->buckets[v16].count;
  if ( (unsigned int)v21 >= 10 * (HIDWORD(v21) + 1) )
  {
    v22 = work->hh.tbl;
    if ( v22->noexpand != 1 )
    {
      v23 = (UT_hash_bucket *)calloc(24 * v22->num_buckets, 1u);
      if ( v23 )
      {
        v24 = 0;
        num_items = v22->num_items;
        v26 = num_items >> (*(_QWORD *)&v22->log2_num_buckets + 1);
        if ( ((2 * v22->num_buckets - 1) & num_items) != 0 )
          ++v26;
        v22->ideal_chain_maxlen = v26;
        work->hh.tbl->nonideal_items = 0;
        v27 = work->hh.tbl;
        num_buckets = v27->num_buckets;
        if ( num_buckets )
        {
          for ( _he_bkt_i = 0; _he_bkt_i < num_buckets; ++_he_bkt_i )
          {
            v29 = v27->buckets[v24].hh_head;
            if ( v29 )
            {
              while ( 1 )
              {
                hh_next = v29->hh_next;
                v31 = (2 * num_buckets - 1) & v29->hashv;
                v32 = &v23[v31];
                v33 = v32->count + 1;
                v32->count = v33;
                if ( v33 > v27->ideal_chain_maxlen )
                {
                  ++v27->nonideal_items;
                  v32->expand_mult = v32->count / work->hh.tbl->ideal_chain_maxlen;
                }
                v29->hh_prev = 0;
                v29->hh_next = v23[v31].hh_head;
                v34 = v23[v31].hh_head;
                if ( v34 )
                  v34->hh_prev = v29;
                v23[v31].hh_head = v29;
                v27 = work->hh.tbl;
                if ( !hh_next )
                  break;
                num_buckets = v27->num_buckets;
                v29 = hh_next;
              }
              num_buckets = v27->num_buckets;
            }
            ++v24;
          }
        }
        free(v27->buckets);
        work->hh.tbl->num_buckets *= 2;
        ++work->hh.tbl->log2_num_buckets;
        work->hh.tbl->buckets = v23;
        v35 = work->hh.tbl;
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
        return;
      }
LABEL_33:
      exit(-1);
    }
  }
}
