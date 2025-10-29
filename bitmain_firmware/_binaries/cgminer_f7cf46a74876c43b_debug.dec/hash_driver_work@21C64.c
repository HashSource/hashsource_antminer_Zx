void __fastcall hash_driver_work(thr_info *mythr)
{
  cgpu_info *cgpu; // r7
  device_drv *drv; // r8
  uint64_t v4; // r4
  bool i; // r9
  __int64 v6; // r2
  bool v7; // zf
  __int64 v8; // r0
  int v9; // r3
  int v10; // r2
  bool v11; // cc
  uint64_t v12; // r2
  int *v13; // r0
  int *v14; // r0
  int thr_id; // [sp+10h] [bp-101Ch]
  timeval tv_start; // [sp+18h] [bp-1014h] BYREF
  timeval tv_end; // [sp+20h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+28h] [bp-1004h] BYREF

  cgpu = mythr->cgpu;
  tv_start.tv_usec = 0;
  drv = cgpu->drv;
  tv_start.tv_sec = 0;
  v4 = 0;
  thr_id = mythr->id;
LABEL_2:
  for ( i = cgpu->shutdown; !i; i = cgpu->shutdown )
  {
    mythr->work_update = i;
    v8 = drv->scanwork(mythr);
    v6 = v8;
    v7 = ++HIDWORD(v8) == 0;
    mythr->work_restart = i;
    if ( !HIDWORD(v8) )
      v7 = (_DWORD)v8 == -1;
    if ( v7 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        snprintf(tmp42, 0x1000u, "%s %d failure, disabling!", drv->name, cgpu->device_id);
        applog(3, tmp42, 0);
      }
      cgpu->deven = dev_enable::DEV_DISABLED;
      dev_error(cgpu, dev_reason::REASON_THREAD_ZERO_HASH);
      break;
    }
    v4 += v6;
    cgtime(&tv_end);
    v9 = tv_end.tv_usec - tv_start.tv_usec;
    v10 = tv_end.tv_sec - tv_start.tv_sec;
    if ( tv_end.tv_usec - tv_start.tv_usec < 0 )
    {
      --v10;
      v9 += 1000000;
    }
    if ( v4 )
    {
      v11 = v10 <= 0;
      if ( v10 <= 0 )
        v11 = v9 <= (int)&loc_30D3E + 2;
      if ( !v11 )
        goto LABEL_12;
    }
    if ( opt_log_interval <= v10 )
    {
LABEL_12:
      v12 = v4;
      v4 = 0;
      hashmeter(thr_id, v12);
      copy_time(&tv_start, &tv_end);
      if ( !mythr->pause )
        goto LABEL_13;
    }
    else if ( !mythr->pause )
    {
LABEL_13:
      if ( cgpu->deven == dev_enable::DEV_ENABLED )
        goto LABEL_14;
    }
    mt_disable(mythr, thr_id, (device_drv *)&drv->thread_enable);
LABEL_14:
    if ( !mythr->work_update )
      goto LABEL_2;
    if ( pthread_mutex_lock(&update_job_lock) )
    {
      v13 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
        *v13,
        "cgminer.c",
        "hash_driver_work",
        9120);
      goto LABEL_29;
    }
    drv->update_work(cgpu);
    if ( pthread_mutex_unlock(&update_job_lock) )
    {
      v14 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
        *v14,
        "cgminer.c",
        "hash_driver_work",
        9122);
LABEL_29:
      applog(3, tmp42, 1);
      _quit(1, 1);
    }
    selective_yield();
  }
  cgpu->deven = dev_enable::DEV_DISABLED;
}
