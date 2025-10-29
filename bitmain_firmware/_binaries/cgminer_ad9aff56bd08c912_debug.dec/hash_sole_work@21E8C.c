void __fastcall hash_sole_work(thr_info *mythr)
{
  cgpu_info *cgpu; // r10
  int v3; // r3
  int shutdown; // r11
  int v5; // r9
  int v6; // r3
  work *work; // r5
  double *p_work_difficulty; // r6
  double work_difficulty; // d9
  double *p_device_diff; // r4
  double max_diff; // d8
  double v12; // r2
  double working_diff; // d11
  pool *pool; // r6
  __int64 v15; // r6
  bool v16; // zf
  int v17; // r3
  int v18; // r2
  int v19; // r4
  int v20; // r6
  int v21; // r7
  bool v22; // cc
  _BOOL4 v23; // r1
  int device_thread; // r3
  const char *v25; // r2
  int v26; // r1
  double v27; // d8
  const char *v28; // r2
  int64_t hashes_done; // [sp+8h] [bp-106Ch]
  device_drv *drv; // [sp+10h] [bp-1064h]
  timeval *dest; // [sp+14h] [bp-1060h]
  timeval *p_getwork_wait_max; // [sp+18h] [bp-105Ch]
  uint32_t max_nonce; // [sp+20h] [bp-1054h]
  int cycle; // [sp+2Ch] [bp-1048h]
  int thr_id; // [sp+30h] [bp-1044h]
  _BOOL4 primary; // [sp+38h] [bp-103Ch]
  int v37; // [sp+3Ch] [bp-1038h]
  int v38; // [sp+40h] [bp-1034h]
  unsigned int mult; // [sp+4Ch] [bp-1028h]
  timeval getwork_start; // [sp+50h] [bp-1024h] BYREF
  timeval tv_start; // [sp+58h] [bp-101Ch] BYREF
  timeval tv_workstart; // [sp+60h] [bp-1014h] BYREF
  timeval tv_lastupdate; // [sp+68h] [bp-100Ch] BYREF
  timespec rgtp; // [sp+70h] [bp-1004h] BYREF

  cgpu = mythr->cgpu;
  thr_id = mythr->id;
  drv = cgpu->drv;
  v3 = opt_log_interval / 5;
  if ( (int)((unsigned __int64)(1717986919LL * opt_log_interval) >> 32) >> 1 == opt_log_interval >> 31 )
    v3 = 1;
  cycle = v3;
  if ( mythr->device_thread )
    primary = mythr->primary_thread;
  else
    primary = 1;
  max_nonce = drv->can_limit_work(mythr);
  cgtime(&getwork_start);
  cgtime(&tv_lastupdate);
  if ( cgpu->shutdown )
    goto LABEL_60;
  shutdown = cgpu->shutdown;
  v5 = shutdown;
  v37 = 1000000 * cycle;
  v6 = (v37 + 1023) & (v37 >> 31);
  if ( 1000000 * cycle >= 0 )
    v6 = 1000000 * cycle;
  hashes_done = 0;
  v38 = v6 >> 10;
  do
  {
    work = get_work(mythr, thr_id);
    mythr->work_restart = 0;
    cgpu->new_work = 1;
    cgtime(&tv_workstart);
    work->nonce = 0;
    cgpu->max_hashes = 0;
    if ( !((int (__fastcall *)(thr_info *, work *))drv->prepare_work)(mythr, work) )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        LOWORD(v28) = 3444;
        HIWORD(v28) = (unsigned int)"vg):%sh/s" >> 16;
        snprintf((char *)&rgtp, 0x1000u, v28, thr_id);
        applog(3, (const char *)&rgtp, 0);
      }
      break;
    }
    LODWORD(v12) = drv;
    p_work_difficulty = &work->work_difficulty;
    work_difficulty = work->work_difficulty;
    p_device_diff = &work->device_diff;
    max_diff = drv->max_diff;
    HIDWORD(v12) = opt_scrypt;
    if ( max_diff > work_difficulty )
      max_diff = work->work_difficulty;
    *p_device_diff = max_diff;
    if ( drv->min_diff > max_diff )
      max_diff = drv->min_diff;
    *p_device_diff = max_diff;
    if ( HIDWORD(v12) )
    {
      working_diff = drv->working_diff;
      HIDWORD(v12) = &global_quota_gcd;
      if ( (double)total_diff1 / total_secs * 60.0 > 30.0
        && drv->max_diff > working_diff
        && work_difficulty > working_diff )
      {
        v27 = working_diff + 1.0;
        HIDWORD(v12) = opt_debug;
        drv->working_diff = working_diff + 1.0;
        if ( HIDWORD(v12) )
        {
          if ( use_syslog || opt_log_output || (HIDWORD(v12) = opt_log_level, opt_log_level > 6) )
          {
            snprintf((char *)&rgtp, 0x1000u, "Driver %s working diff changed to %.0f", drv->dname, working_diff + 1.0);
            applog(7, (const char *)&rgtp, 0);
            v27 = drv->working_diff;
          }
        }
        if ( *p_work_difficulty < v27 )
          v27 = *p_work_difficulty;
        *p_device_diff = v27;
      }
      else if ( work_difficulty < working_diff )
      {
        HIDWORD(v12) = drv;
        drv->working_diff = work_difficulty;
      }
      set_target(work->device_target, v12);
    }
    p_getwork_wait_max = &cgpu->cgminer_stats.getwork_wait_max;
    dest = &cgpu->cgminer_stats.getwork_wait_min;
    while ( 1 )
    {
      cgtime(&tv_start);
      subtime(&tv_start, &getwork_start);
      addtime(&getwork_start, &cgpu->cgminer_stats.getwork_wait);
      if ( time_more(&getwork_start, p_getwork_wait_max) )
        copy_time(p_getwork_wait_max, &getwork_start);
      if ( time_less(&getwork_start, dest) )
        copy_time(dest, &getwork_start);
      ++cgpu->cgminer_stats.getwork_calls;
      pool = work->pool;
      addtime(&getwork_start, &pool->cgminer_stats.getwork_wait);
      if ( time_more(&getwork_start, &pool->cgminer_stats.getwork_wait_max) )
        copy_time(&pool->cgminer_stats.getwork_wait_max, &getwork_start);
      if ( time_less(&getwork_start, &pool->cgminer_stats.getwork_wait_min) )
        copy_time(&pool->cgminer_stats.getwork_wait_min, &getwork_start);
      ++pool->cgminer_stats.getwork_calls;
      cgtime(&work->tv_work_start);
      pthread_setcancelstate(1, 0);
      thread_reportin(mythr);
      v15 = ((__int64 (__fastcall *)(thr_info *, work *, uint32_t, _DWORD))drv->scanhash)(
              mythr,
              work,
              work->nonce + max_nonce,
              0);
      thread_reportout(mythr);
      pthread_setcancelstate(0, 0);
      pthread_testcancel();
      cgtime(&getwork_start);
      v16 = HIDWORD(v15) == -1;
      if ( HIDWORD(v15) == -1 )
        v16 = (_DWORD)v15 == -1;
      if ( v16 )
        break;
      hashes_done += v15;
      if ( cgpu->max_hashes < v15 )
        cgpu->max_hashes = v15;
      v17 = getwork_start.tv_usec - tv_start.tv_usec + (getwork_start.tv_usec - tv_start.tv_usec < 0 ? 0xF4000 : 0);
      v18 = getwork_start.tv_sec - tv_start.tv_sec;
      if ( getwork_start.tv_usec - tv_start.tv_usec < 0 )
      {
        v17 += 576;
        --v18;
      }
      shutdown += v17;
      v5 += v18;
      if ( shutdown > 1000000 )
      {
        ++v5;
        shutdown -= 1000000;
      }
      v19 = getwork_start.tv_sec - tv_workstart.tv_sec;
      if ( getwork_start.tv_usec - tv_workstart.tv_usec < 0 )
        --v19;
      if ( cycle > v5 )
      {
        if ( max_nonce == -1 )
          goto LABEL_54;
        v26 = shutdown + 2047;
        if ( shutdown + 1024 >= 0 )
          v26 = shutdown + 1024;
        mult = (1000000 / (v26 >> 10) + 16) * cycle;
        if ( 0xFFFFFC00 / mult >= max_nonce )
          max_nonce = (max_nonce * mult) >> 10;
        else
          max_nonce = -1;
      }
      else if ( cycle < v5 )
      {
        max_nonce = max_nonce * cycle / v5;
      }
      else if ( shutdown > 100000 )
      {
        max_nonce = (max_nonce << 10) / ((v37 + shutdown) / v38);
      }
      v20 = getwork_start.tv_usec - tv_lastupdate.tv_usec;
      v21 = getwork_start.tv_sec - tv_lastupdate.tv_sec;
      if ( getwork_start.tv_usec - tv_lastupdate.tv_usec < 0 )
      {
        --v21;
        v20 += 1000000;
      }
      if ( hashes_done )
      {
        v22 = v21 <= 0;
        if ( v21 <= 0 )
          v22 = v20 <= 200000;
        if ( !v22 )
          goto LABEL_51;
      }
      if ( opt_log_interval <= v21 )
      {
LABEL_51:
        hashmeter(thr_id, hashes_done);
        hashes_done = 0;
        copy_time(&tv_lastupdate, &getwork_start);
        if ( mythr->work_restart )
          goto LABEL_63;
      }
      else if ( mythr->work_restart )
      {
LABEL_63:
        if ( !primary )
        {
          device_thread = mythr->device_thread;
          rgtp.tv_sec = 0;
          rgtp.tv_nsec = 250000000 * device_thread;
          nanosleep(&rgtp, 0);
        }
        goto LABEL_59;
      }
      if ( mythr->pause || (shutdown = cgpu->deven, (v5 = shutdown) != 0) )
      {
        shutdown = 0;
        v5 = 0;
        mt_disable(mythr, thr_id, (device_drv *)&drv->thread_enable);
      }
LABEL_54:
      v23 = opt_scantime < v19 || cgpu->max_hashes > 0xFFFFFFFDuLL;
      if ( v23 || stale_work(work, 0) )
        goto LABEL_59;
    }
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      LOWORD(v25) = 3416;
      HIWORD(v25) = (unsigned int)" (1m):%s (5m):%s (15m):%s (avg):%sh/s" >> 16;
      snprintf((char *)&rgtp, 0x1000u, v25, drv->name, cgpu->device_id);
      applog(3, (const char *)&rgtp, 0);
    }
    cgpu->deven = dev_enable::DEV_DISABLED;
    dev_error(cgpu, dev_reason::REASON_THREAD_ZERO_HASH);
    cgpu->shutdown = 1;
LABEL_59:
    clean_work(work);
    free(work);
  }
  while ( !cgpu->shutdown );
LABEL_60:
  cgpu->deven = dev_enable::DEV_DISABLED;
}
