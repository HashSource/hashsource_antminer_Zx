void __fastcall gen_stratum_work(pool *pool, work *work)
{
  cglock_t *p_data_lock; // r6
  int nonce2; // r3
  int nonce2_high; // r2
  size_t v7; // r0
  int v8; // lr
  int v9; // r12
  int v10; // r0
  double v11; // r2
  int v12; // r8
  int v13; // lr
  int v14; // r12
  unsigned int v15; // r0
  int *v16; // r0
  int *v17; // r0
  int v18; // r3
  int v19; // r4
  int *v20; // r0
  int *v21; // r0
  char *header; // [sp+1Ch] [bp-1008h]
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  p_data_lock = &pool->data_lock;
  if ( pthread_mutex_lock(&pool->data_lock.mutex) )
  {
    v16 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v16,
      "cgminer.c",
      "gen_stratum_work",
      7949);
    goto LABEL_19;
  }
  if ( pthread_rwlock_wrlock(&pool->data_lock.rwlock) )
  {
    v17 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v17,
      "cgminer.c",
      "gen_stratum_work",
      7949);
    goto LABEL_19;
  }
  nonce2 = pool->nonce2;
  nonce2_high = HIDWORD(pool->nonce2);
  LODWORD(pool->nonce2) = nonce2 + 1;
  HIDWORD(pool->nonce2) = __CFADD__(nonce2, 1) + nonce2_high;
  LODWORD(work->nonce2) = nonce2;
  HIDWORD(work->nonce2) = nonce2_high;
  work->nonce2_len = 2;
  if ( pthread_rwlock_unlock(&pool->data_lock.rwlock) )
  {
    v18 = *_errno_location();
    v19 = 7954;
LABEL_22:
    snprintf(
      tmp42,
      0x1000u,
      "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
      v18,
      "cgminer.c",
      "gen_stratum_work",
      v19);
    goto LABEL_19;
  }
  if ( pthread_rwlock_rdlock(&pool->data_lock.rwlock) )
  {
    v20 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v20,
      "cgminer.c",
      "gen_stratum_work",
      7954);
    goto LABEL_19;
  }
  if ( pthread_mutex_unlock(&p_data_lock->mutex) )
  {
    v21 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v21,
      "cgminer.c",
      "gen_stratum_work",
      7954);
LABEL_19:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  memset(work->equihash_data, 0, sizeof(work->equihash_data));
  memcpy(work->equihash_data, pool->header_bin, 0x80u);
  v7 = strlen(pool->nonce1);
  hex2bin(&work->equihash_data[108], pool->nonce1, v7 >> 1);
  memcpy(&work->equihash_data[128 - work->nonce2_len], &work->nonce2, work->nonce2_len);
  work->equihash_data[140] = -3;
  *(_WORD *)&work->equihash_data[141] = 1344;
  work->sdiff = pool->swork.diff;
  work->job_id = _strdup(pool->swork.job_id);
  work->nonce1 = _strdup(pool->nonce1);
  work->ntime = _strdup(pool->swork.ntime);
  if ( pthread_rwlock_unlock(&pool->data_lock.rwlock) )
  {
    v18 = *_errno_location();
    v19 = 7975;
    goto LABEL_22;
  }
  selective_yield();
  if ( opt_debug )
  {
    header = bin2hex(work->equihash_data, 0x8Fu);
    if ( opt_debug )
    {
      if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
        goto LABEL_14;
      snprintf(tmp42, 0x1000u, "[THR%d] Generated stratum header %s", work->thr_id, header);
      applog(7, tmp42, 0);
      if ( opt_debug )
      {
        if ( use_syslog )
        {
LABEL_16:
          snprintf(
            tmp42,
            0x1000u,
            "[THR%d] job_id %s, nonce1 %s, nonce2 %llu, ntime %s",
            work->thr_id,
            work->job_id,
            work->nonce1,
            work->nonce2,
            work->ntime);
          applog(7, tmp42, 0);
          goto LABEL_17;
        }
LABEL_14:
        if ( !opt_log_output && opt_log_level <= 6 )
          goto LABEL_17;
        goto LABEL_16;
      }
    }
LABEL_17:
    free(header);
  }
  v8 = *(_DWORD *)&pool->Target[4];
  v9 = *(_DWORD *)&pool->Target[8];
  v10 = *(_DWORD *)&pool->Target[12];
  LODWORD(v11) = local_work + 1;
  *(_DWORD *)work->target = *(_DWORD *)pool->Target;
  *(_DWORD *)&work->target[4] = v8;
  *(_DWORD *)&work->target[8] = v9;
  *(_DWORD *)&work->target[12] = v10;
  v12 = *(_DWORD *)&pool->Target[16];
  v13 = *(_DWORD *)&pool->Target[20];
  v14 = *(_DWORD *)&pool->Target[24];
  HIDWORD(v11) = total_work;
  *(_DWORD *)&work->target[28] = *(_DWORD *)&pool->Target[28];
  v15 = work_block;
  *(_DWORD *)&work->target[16] = v12;
  *(_DWORD *)&work->target[20] = v13;
  *(_DWORD *)&work->target[24] = v14;
  work->id = HIDWORD(v11)++;
  work->work_block = v15;
  work->getwork_mode = 83;
  work->drv_rolllimit = 60;
  work->pool = pool;
  work->stratum = 1;
  work->longpoll = 0;
  total_work = HIDWORD(v11);
  local_work = LODWORD(v11);
  calc_diff(work, v11);
  cgtime(&work->tv_staged);
}
