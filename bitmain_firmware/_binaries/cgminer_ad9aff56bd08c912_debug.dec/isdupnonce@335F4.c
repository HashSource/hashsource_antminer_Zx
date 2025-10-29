bool __fastcall isdupnonce(cgpu_info *cgpu, work *work, uint32_t nonce)
{
  double v3; // d0
  void *dup_data; // r4
  _BOOL4 v5; // r6
  int v8; // r1
  int v9; // r5
  const char *v10; // r10
  int v11; // r5
  _BOOL4 v12; // r7
  _DWORD *v13; // r3
  int v14; // r3
  const char *v15; // r5
  K_ITEM *v16; // r0
  int v17; // r5
  const char *v19; // r1
  K_ITEM *v20; // r5
  _DWORD *data; // lr
  __time_t tv_sec; // r0
  int *v23; // r0
  int v24; // r1
  const char *v25; // r2
  int *v26; // r0
  int v27; // r1
  const char *v28; // r2
  int *v29; // r0
  int v30; // r1
  const char *v31; // r2
  int *v32; // r0
  int v33; // r1
  const char *v34; // r2
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
      v23 = _errno_location();
      LOWORD(v24) = 28128;
      HIWORD(v24) = (unsigned int)"m %s %s() line %d in %s %s():%d" >> 16;
      LOWORD(v25) = -968;
      HIWORD(v25) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v25, *v23, v24, "isdupnonce", 70);
      applog(3, tmp42, 1);
      quit(1);
    }
    if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(v9 + 24)) )
    {
      v26 = _errno_location();
      LOWORD(v27) = 28128;
      HIWORD(v27) = (unsigned int)"m %s %s() line %d in %s %s():%d" >> 16;
      LOWORD(v28) = -1020;
      HIWORD(v28) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v28, *v26, v27, "isdupnonce", 70);
      applog(3, tmp42, 1);
      quit(1);
    }
    LOWORD(v10) = 28188;
    v11 = *(_DWORD *)(*((_DWORD *)dup_data + 2) + 16);
    v12 = 1;
    while ( 1 )
    {
      v5 = v11 && v12;
      if ( !v5 )
        break;
      while ( 1 )
      {
        v13 = *(_DWORD **)(v11 + 12);
        v12 = v5;
        if ( *v13 == work->id && v13[1] == nonce )
          break;
        v11 = *(_DWORD *)(v11 + 4);
        if ( !v11 )
          v5 = 0;
        if ( !v5 )
          goto LABEL_13;
      }
      if ( !use_syslog )
      {
        v12 = opt_log_output;
        if ( !opt_log_output && opt_log_level <= 3 )
          continue;
      }
      v12 = 0;
      HIWORD(v10) = (unsigned int)" - from %s %s() line %d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v10, cgpu->drv->name, cgpu->device_id, nonce);
      applog(4, tmp42, 0);
    }
LABEL_13:
    if ( v12 )
    {
      LOWORD(v19) = 28128;
      HIWORD(v19) = (unsigned int)"m %s %s() line %d in %s %s():%d" >> 16;
      v20 = k_unlink_head(*((K_LIST **)dup_data + 1), v19, "isdupnonce", 81);
      *(_DWORD *)v20->data = work->id;
      *((_DWORD *)v20->data + 1) = nonce;
      data = v20->data;
      tv_sec = now.tv_sec;
      data[3] = now.tv_usec;
      data[2] = tv_sec;
      k_add_head(*((K_LIST **)dup_data + 2), v20, "noncedup.c", "isdupnonce", 85);
    }
    v14 = *(_DWORD *)(*((_DWORD *)dup_data + 2) + 16);
    if ( v14 )
    {
      LOWORD(v15) = 28128;
      HIWORD(v15) = (unsigned int)"m %s %s() line %d in %s %s():%d" >> 16;
      do
      {
        tdiff((timeval *)(*(_DWORD *)(v14 + 12) + 8), &now);
        if ( v3 <= (double)*(int *)dup_data )
          break;
        v16 = k_unlink_tail(*((K_LIST **)dup_data + 2), v15, "isdupnonce", 89);
        k_add_head(*((K_LIST **)dup_data + 1), v16, v15, "isdupnonce", 90);
        v14 = *(_DWORD *)(*((_DWORD *)dup_data + 2) + 16);
      }
      while ( v14 );
    }
    v17 = *(_DWORD *)(*((_DWORD *)dup_data + 1) + 8);
    if ( pthread_rwlock_unlock((pthread_rwlock_t *)(v17 + 24)) )
    {
      v32 = _errno_location();
      LOWORD(v33) = 28128;
      HIWORD(v33) = (unsigned int)"m %s %s() line %d in %s %s():%d" >> 16;
      LOWORD(v34) = -348;
      HIWORD(v34) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
      snprintf(tmp42, 0x1000u, v34, *v32, v33, "isdupnonce", 93);
      applog(3, tmp42, 1);
      quit(1);
    }
    if ( pthread_mutex_unlock((pthread_mutex_t *)v17) )
    {
      v29 = _errno_location();
      LOWORD(v30) = 28128;
      HIWORD(v30) = (unsigned int)"m %s %s() line %d in %s %s():%d" >> 16;
      LOWORD(v31) = -920;
      HIWORD(v31) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v31, *v29, v30, "isdupnonce", 93);
      applog(3, tmp42, 1);
      quit(1);
    }
    selective_yield();
    if ( !v12 )
    {
      LOBYTE(v5) = 1;
      ++*((_QWORD *)dup_data + 3);
    }
  }
  return v5;
}
