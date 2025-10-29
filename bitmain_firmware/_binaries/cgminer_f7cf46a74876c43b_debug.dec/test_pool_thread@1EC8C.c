void *__fastcall test_pool_thread(void *arg)
{
  int v2; // r5
  int v4; // r0
  pthread_t v5; // r0
  int *v6; // r0
  int *v7; // r0
  int *v8; // r0
  int *v9; // r0
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
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v6,
      "cgminer.c",
      "test_pool_thread",
      10008);
    goto LABEL_16;
  }
  if ( pthread_rwlock_wrlock(&control_lock.rwlock) )
  {
    v7 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v7,
      "cgminer.c",
      "test_pool_thread",
      10008);
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
    v8 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v8,
      "cgminer.c",
      "test_pool_thread",
      10016);
    goto LABEL_16;
  }
  if ( pthread_mutex_unlock(&control_lock.mutex) )
  {
    v9 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v9,
      "cgminer.c",
      "test_pool_thread",
      10016);
LABEL_16:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  if ( v2 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "Switching to pool %d %s - first alive pool", *(_DWORD *)arg, *((const char **)arg + 49));
    applog(7, tmp42, 0);
  }
  pool_resus((pool *)arg);
  switch_pools(0);
  *((_BYTE *)arg + 316) = 0;
  return 0;
}
