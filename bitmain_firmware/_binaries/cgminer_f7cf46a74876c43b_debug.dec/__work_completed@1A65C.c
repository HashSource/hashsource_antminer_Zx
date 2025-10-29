void __fastcall _work_completed(cgpu_info *cgpu, work *work)
{
  work *queued_work; // r4
  char *prev; // r2
  UT_hash_table *tbl; // r5
  UT_hash_handle *p_hh; // r4
  ptrdiff_t hho; // r3
  work *next; // r6
  char *v8; // r3
  UT_hash_table *v9; // r2
  unsigned int v10; // r3
  UT_hash_bucket *buckets; // r2
  UT_hash_handle *hh_prev; // r2
  UT_hash_handle *hh_next; // r3

  queued_work = cgpu->queued_work;
  --cgpu->queued_count;
  prev = (char *)work->hh.prev;
  if ( !prev )
  {
    next = (work *)work->hh.next;
    tbl = queued_work->hh.tbl;
    if ( !next )
    {
      free(tbl->buckets);
      free(cgpu->queued_work->hh.tbl);
      cgpu->queued_work = 0;
      return;
    }
    hho = tbl->hho;
    p_hh = &work->hh;
    if ( work != (work *)((char *)tbl->tail - hho) )
      goto LABEL_17;
    goto LABEL_13;
  }
  tbl = queued_work->hh.tbl;
  p_hh = &work->hh;
  hho = tbl->hho;
  if ( work == (work *)((char *)tbl->tail - hho) )
  {
LABEL_13:
    tbl->tail = (UT_hash_handle *)&prev[hho];
    prev = (char *)work->hh.prev;
    if ( prev )
    {
      hho = cgpu->queued_work->hh.tbl->hho;
      goto LABEL_3;
    }
    next = (work *)work->hh.next;
LABEL_17:
    cgpu->queued_work = next;
    goto LABEL_4;
  }
LABEL_3:
  *(_DWORD *)&prev[hho + 8] = work->hh.next;
  next = cgpu->queued_work;
LABEL_4:
  v8 = (char *)work->hh.next;
  v9 = next->hh.tbl;
  if ( v8 )
  {
    *(_DWORD *)&v8[v9->hho + 4] = work->hh.prev;
    v9 = cgpu->queued_work->hh.tbl;
  }
  v10 = (v9->num_buckets - 1) & work->hh.hashv;
  --v9->buckets[v10].count;
  buckets = cgpu->queued_work->hh.tbl->buckets;
  if ( buckets[v10].hh_head == p_hh )
    buckets[v10].hh_head = work->hh.hh_next;
  hh_prev = work->hh.hh_prev;
  hh_next = work->hh.hh_next;
  if ( hh_prev )
  {
    hh_prev->hh_next = hh_next;
    hh_next = work->hh.hh_next;
  }
  if ( hh_next )
    hh_next->hh_prev = work->hh.hh_prev;
  --cgpu->queued_work->hh.tbl->num_items;
}
