bool __fastcall isdupnonce(cgpu_info *cgpu, work *work, uint32_t nonce)
{
  double v3; // d0
  void *dup_data; // r4
  _BOOL4 v5; // r6
  int v8; // r1
  int v9; // r5
  int v10; // r5
  _BOOL4 v11; // r7
  _DWORD *v12; // r3
  int i; // r3
  K_ITEM *v14; // r0
  int v15; // r5
  K_ITEM *v17; // r5
  _DWORD *data; // lr
  __time_t tv_sec; // r0
  int *v20; // r0
  int *v21; // r0
  int *v22; // r0
  int *v23; // r0
  timeval now; // [sp+18h] [bp-100Ch] BYREF
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  dup_data = cgpu->dup_data;
  LOBYTE(v5) = (_BYTE)dup_data;
  if ( dup_data )
  {
    cgtime(&now);
    v8 = *((_DWORD *)dup_data + 1);
    ++*((_QWORD *)dup_data + 2);
    v9 = *(_DWORD *)(v8 + 8);
    if ( pthread_mutex_lock((pthread_mutex_t *)v9) )
    {
      v20 = _errno_location();
      snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v20, "noncedup.c", "isdupnonce", 70);
      applog(3, tmp42, 1);
      quit(1);
    }
    if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(v9 + 24)) )
    {
      v21 = _errno_location();
      snprintf(tmp42, 0x1000u, "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d", *v21, "noncedup.c", "isdupnonce", 70);
      applog(3, tmp42, 1);
      quit(1);
    }
    v10 = *(_DWORD *)(*((_DWORD *)dup_data + 2) + 16);
    v11 = 1;
    while ( 1 )
    {
      v5 = v10 && v11;
      if ( !v5 )
        break;
      while ( 1 )
      {
        v12 = *(_DWORD **)(v10 + 12);
        v11 = v5;
        if ( *v12 == work->id && v12[1] == nonce )
          break;
        v10 = *(_DWORD *)(v10 + 4);
        if ( !v10 )
          v5 = 0;
        if ( !v5 )
          goto LABEL_13;
      }
      if ( !use_syslog )
      {
        v11 = opt_log_output;
        if ( !opt_log_output && opt_log_level <= 3 )
          continue;
      }
      v11 = 0;
      snprintf(tmp42, 0x1000u, "%s%d: Duplicate nonce %08x", cgpu->drv->name, cgpu->device_id, nonce);
      applog(4, tmp42, 0);
    }
LABEL_13:
    if ( v11 )
    {
      v17 = k_unlink_head(*((K_LIST **)dup_data + 1), "noncedup.c", "isdupnonce", 81);
      *(_DWORD *)v17->data = work->id;
      *((_DWORD *)v17->data + 1) = nonce;
      data = v17->data;
      tv_sec = now.tv_sec;
      data[3] = now.tv_usec;
      data[2] = tv_sec;
      k_add_head(*((K_LIST **)dup_data + 2), v17, "noncedup.c", "isdupnonce", 85);
    }
    for ( i = *(_DWORD *)(*((_DWORD *)dup_data + 2) + 16); i; i = *(_DWORD *)(*((_DWORD *)dup_data + 2) + 16) )
    {
      tdiff((timeval *)(*(_DWORD *)(i + 12) + 8), &now);
      if ( v3 <= (double)*(int *)dup_data )
        break;
      v14 = k_unlink_tail(*((K_LIST **)dup_data + 2), "noncedup.c", "isdupnonce", 89);
      k_add_head(*((K_LIST **)dup_data + 1), v14, "noncedup.c", "isdupnonce", 90);
    }
    v15 = *(_DWORD *)(*((_DWORD *)dup_data + 1) + 8);
    if ( pthread_rwlock_unlock((pthread_rwlock_t *)(v15 + 24)) )
    {
      v23 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
        *v23,
        "noncedup.c",
        "isdupnonce",
        93);
      applog(3, tmp42, 1);
      quit(1);
    }
    if ( pthread_mutex_unlock((pthread_mutex_t *)v15) )
    {
      v22 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
        *v22,
        "noncedup.c",
        "isdupnonce",
        93);
      applog(3, tmp42, 1);
      quit(1);
    }
    selective_yield();
    if ( !v11 )
    {
      LOBYTE(v5) = 1;
      ++*((_QWORD *)dup_data + 3);
    }
  }
  return v5;
}
