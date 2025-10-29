void *__fastcall test_pool_thread(void *arg)
{
  int v2; // r5
  int v4; // r0
  pthread_t v5; // r0
  int *v6; // r0
  const char *v7; // r2
  int v8; // r1
  int *v9; // r0
  int v10; // r1
  const char *v11; // r2
  int *v12; // r0
  int v13; // r1
  const char *v14; // r2
  int *v15; // r0
  int v16; // r1
  const char *v17; // r2
  const char *v18; // r2
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( !*((_BYTE *)arg + 139) )
  {
    v5 = pthread_self();
    pthread_detach(v5);
  }
  while ( !pool_active((pool *)arg, 0) )
  {
    pool_died((pool *)arg);
    sleep(5u);
  }
  pool_tset((int)arg, (_BYTE *)arg + 130);
  pool_tclear((int)arg, (_BYTE *)arg + 129);
  if ( pthread_mutex_lock(&control_lock.mutex) )
  {
    v6 = _errno_location();
    LOWORD(v7) = -968;
    LOWORD(v8) = -3136;
    HIWORD(v7) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    HIWORD(v8) = (unsigned int)"iner" >> 16;
    snprintf(tmp42, 0x1000u, v7, *v6, v8, "test_pool_thread", 10008);
    goto LABEL_16;
  }
  if ( pthread_rwlock_wrlock(&control_lock.rwlock) )
  {
    v9 = _errno_location();
    LOWORD(v10) = -3136;
    LOWORD(v11) = -1020;
    HIWORD(v10) = (unsigned int)"iner" >> 16;
    HIWORD(v11) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v11, *v9, v10, "test_pool_thread", 10008);
    goto LABEL_16;
  }
  v2 = 0;
  if ( !pools_active )
  {
    v4 = *(_DWORD *)arg;
    currentpool = (pool *)arg;
    pools_active = 1;
    v2 = v4;
    if ( v4 )
      v2 = 1;
  }
  if ( pthread_rwlock_unlock(&control_lock.rwlock) )
  {
    v12 = _errno_location();
    LOWORD(v13) = -3136;
    LOWORD(v14) = -348;
    HIWORD(v13) = (unsigned int)"iner" >> 16;
    HIWORD(v14) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
    snprintf(tmp42, 0x1000u, v14, *v12, v13, "test_pool_thread", 10016);
    goto LABEL_16;
  }
  if ( pthread_mutex_unlock(&control_lock.mutex) )
  {
    v15 = _errno_location();
    LOWORD(v16) = -3136;
    LOWORD(v17) = -920;
    HIWORD(v16) = (unsigned int)"iner" >> 16;
    HIWORD(v17) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v17, *v15, v16, "test_pool_thread", 10016);
LABEL_16:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  if ( v2 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v18) = 1932;
    HIWORD(v18) = (unsigned int)"g!" >> 16;
    snprintf(tmp42, 0x1000u, v18, *(_DWORD *)arg, *((_DWORD *)arg + 49));
    applog(7, tmp42, 0);
  }
  pool_resus((pool *)arg);
  switch_pools(0);
  *((_BYTE *)arg + 316) = 0;
  return 0;
}
