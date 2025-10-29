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
  const char *v16; // r2
  const char *v17; // r2
  int *v18; // r0
  const char *v19; // r2
  int v20; // r1
  int *v21; // r0
  int v22; // r1
  const char *v23; // r2
  int *v24; // r0
  int v25; // r3
  int v26; // r1
  int v27; // r4
  const char *v28; // r2
  int *v29; // r0
  int v30; // r1
  const char *v31; // r2
  int *v32; // r0
  int v33; // r1
  const char *v34; // r2
  int *v35; // r0
  char *header; // [sp+1Ch] [bp-1008h]
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  p_data_lock = &pool->data_lock;
  if ( pthread_mutex_lock(&pool->data_lock.mutex) )
  {
    v18 = _errno_location();
    LOWORD(v19) = -968;
    LOWORD(v20) = -3136;
    HIWORD(v19) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    HIWORD(v20) = (unsigned int)"iner" >> 16;
    snprintf(tmp42, 0x1000u, v19, *v18, v20, "gen_stratum_work", 7949);
    goto LABEL_19;
  }
  if ( pthread_rwlock_wrlock(&pool->data_lock.rwlock) )
  {
    v21 = _errno_location();
    LOWORD(v22) = -3136;
    LOWORD(v23) = -1020;
    HIWORD(v22) = (unsigned int)"iner" >> 16;
    HIWORD(v23) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v23, *v21, v22, "gen_stratum_work", 7949);
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
    v24 = _errno_location();
    LOWORD(v26) = -3136;
    v25 = *v24;
    HIWORD(v26) = (unsigned int)"iner" >> 16;
    v27 = 7954;
LABEL_22:
    LOWORD(v28) = -348;
    HIWORD(v28) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
    snprintf(tmp42, 0x1000u, v28, v25, v26, "gen_stratum_work", v27);
    goto LABEL_19;
  }
  if ( pthread_rwlock_rdlock(&pool->data_lock.rwlock) )
  {
    v29 = _errno_location();
    LOWORD(v30) = -3136;
    LOWORD(v31) = -232;
    HIWORD(v30) = (unsigned int)"iner" >> 16;
    HIWORD(v31) = (unsigned int)"" >> 16;
    snprintf(tmp42, 0x1000u, v31, *v29, v30, "gen_stratum_work", 7954);
    goto LABEL_19;
  }
  if ( pthread_mutex_unlock(&p_data_lock->mutex) )
  {
    v32 = _errno_location();
    LOWORD(v33) = -3136;
    LOWORD(v34) = -920;
    HIWORD(v33) = (unsigned int)"iner" >> 16;
    HIWORD(v34) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v34, *v32, v33, "gen_stratum_work", 7954);
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
    v35 = _errno_location();
    LOWORD(v26) = -3136;
    v25 = *v35;
    HIWORD(v26) = (unsigned int)"iner" >> 16;
    v27 = 7975;
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
      LOWORD(v16) = 2332;
      HIWORD(v16) = (unsigned int)" printf error" >> 16;
      snprintf(tmp42, 0x1000u, v16, work->thr_id, header);
      applog(7, tmp42, 0);
      if ( opt_debug )
      {
        if ( use_syslog )
        {
LABEL_16:
          LOWORD(v17) = 2368;
          HIWORD(v17) = (unsigned int)"r" >> 16;
          snprintf(
            tmp42,
            0x1000u,
            v17,
            work->thr_id,
            work->job_id,
            work->nonce1,
            LODWORD(work->nonce2),
            HIDWORD(work->nonce2),
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
