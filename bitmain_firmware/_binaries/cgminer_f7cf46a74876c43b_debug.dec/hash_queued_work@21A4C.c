void __fastcall hash_queued_work(thr_info *mythr)
{
  cgpu_info *cgpu; // r4
  device_drv *drv; // r5
  uint64_t v4; // r6
  bool shutdown; // r3
  __int64 v6; // r2
  bool v7; // zf
  int v8; // r3
  int v9; // r2
  bool v10; // cc
  uint64_t v11; // r2
  int *v12; // r0
  int *v13; // r0
  int thr_id; // [sp+10h] [bp-101Ch]
  work *work; // [sp+14h] [bp-1018h]
  timeval tv_start; // [sp+18h] [bp-1014h] BYREF
  timeval tv_end; // [sp+20h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+28h] [bp-1004h] BYREF

  cgpu = mythr->cgpu;
  tv_start.tv_sec = 0;
  tv_start.tv_usec = 0;
  drv = cgpu->drv;
  v4 = 0;
  thr_id = mythr->id;
  while ( 2 )
  {
    shutdown = cgpu->shutdown;
    if ( shutdown )
      goto LABEL_23;
LABEL_3:
    mythr->work_update = shutdown;
    do
    {
      while ( cgpu->unqueued_work )
      {
LABEL_4:
        if ( ((int (__fastcall *)(cgpu_info *))drv->queue_full)(cgpu) )
          goto LABEL_10;
      }
      work = get_work(mythr, thr_id);
      if ( pthread_rwlock_wrlock(&cgpu->qlock) )
      {
        v12 = _errno_location();
        snprintf(
          tmp42,
          0x1000u,
          "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
          *v12,
          "cgminer.c",
          "fill_queue",
          8763);
        goto LABEL_28;
      }
      if ( cgpu->unqueued_work )
      {
        if ( !pthread_rwlock_unlock(&cgpu->qlock) )
        {
          selective_yield();
          discard_work(work);
          goto LABEL_4;
        }
LABEL_31:
        v13 = _errno_location();
        snprintf(
          tmp42,
          0x1000u,
          "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
          *v13,
          "cgminer.c",
          "fill_queue",
          8770);
LABEL_28:
        applog(3, tmp42, 1);
        _quit(1, 1);
      }
      cgpu->unqueued_work = work;
      if ( pthread_rwlock_unlock(&cgpu->qlock) )
        goto LABEL_31;
      selective_yield();
    }
    while ( !((int (__fastcall *)(cgpu_info *))drv->queue_full)(cgpu) );
LABEL_10:
    v6 = drv->scanwork(mythr);
    mythr->work_restart = 0;
    v7 = HIDWORD(v6) == -1;
    if ( HIDWORD(v6) == -1 )
      v7 = (_DWORD)v6 == -1;
    if ( !v7 )
    {
      v4 += v6;
      cgtime(&tv_end);
      v8 = tv_end.tv_usec - tv_start.tv_usec;
      v9 = tv_end.tv_sec - tv_start.tv_sec;
      if ( tv_end.tv_usec - tv_start.tv_usec < 0 )
      {
        --v9;
        v8 += 1000000;
      }
      if ( v4 )
      {
        v10 = v8 <= 200000;
        if ( v8 <= 200000 )
          v10 = v9 <= 0;
        if ( !v10 )
          goto LABEL_19;
      }
      if ( opt_log_interval <= v9 )
      {
LABEL_19:
        v11 = v4;
        v4 = 0;
        hashmeter(thr_id, v11);
        copy_time(&tv_start, &tv_end);
        if ( mythr->pause )
          goto LABEL_26;
      }
      else if ( mythr->pause )
      {
LABEL_26:
        mt_disable(mythr, thr_id, (device_drv *)&drv->thread_enable);
        goto LABEL_21;
      }
      if ( cgpu->deven )
        goto LABEL_26;
LABEL_21:
      if ( !mythr->work_update )
        continue;
      drv->update_work(cgpu);
      shutdown = cgpu->shutdown;
      if ( shutdown )
        goto LABEL_23;
      goto LABEL_3;
    }
    break;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    snprintf(tmp42, 0x1000u, "%s %d failure, disabling!", drv->name, cgpu->device_id);
    applog(3, tmp42, 0);
  }
  cgpu->deven = dev_enable::DEV_DISABLED;
  dev_error(cgpu, dev_reason::REASON_THREAD_ZERO_HASH);
LABEL_23:
  cgpu->deven = dev_enable::DEV_DISABLED;
}
