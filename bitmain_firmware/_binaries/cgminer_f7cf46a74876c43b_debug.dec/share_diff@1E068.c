uint64_t __fastcall share_diff(const work *work)
{
  double v2; // d9
  unsigned __int64 v3; // r0
  double v4; // d0
  uint64_t v5; // r6
  int v6; // r5
  pool *pool; // r1
  int *v9; // r0
  int *v10; // r0
  int *v11; // r0
  int *v12; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v2 = 2.69595353e67;
  v3 = *(_QWORD *)&work->hash[24];
  if ( opt_scrypt )
    v2 = 1.7668201e72;
  v4 = (double)*(unsigned __int64 *)work->hash
     + (double)v3 * 6.27710174e57
     + (double)*(unsigned __int64 *)&work->hash[16] * 3.40282367e38
     + (double)*(unsigned __int64 *)&work->hash[8] * 1.84467441e19;
  if ( v4 == 0.0 )
    v4 = 0.0;
  round();
  v5 = (unsigned __int64)(v2 / v4);
  if ( pthread_mutex_lock(&control_lock.mutex) )
  {
    v9 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v9, "cgminer.c", "share_diff", 4986);
    goto LABEL_17;
  }
  if ( pthread_rwlock_wrlock(&control_lock.rwlock) )
  {
    v10 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d", *v10, "cgminer.c", "share_diff", 4986);
    goto LABEL_17;
  }
  if ( best_diff < v5 )
  {
    best_diff = (unsigned __int64)(v2 / v4);
    v6 = 1;
    suffix_string(v5, best_share, 8u, 0);
  }
  else
  {
    v6 = 0;
  }
  pool = work->pool;
  if ( pool->best_diff < v5 )
    pool->best_diff = v5;
  if ( pthread_rwlock_unlock(&control_lock.rwlock) )
  {
    v11 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v11,
      "cgminer.c",
      "share_diff",
      4995);
    goto LABEL_17;
  }
  if ( pthread_mutex_unlock(&control_lock.mutex) )
  {
    v12 = _errno_location();
    snprintf(tmp42, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v12, "cgminer.c", "share_diff", 4995);
LABEL_17:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  selective_yield();
  if ( v6 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "New best share: %s", best_share);
    applog(7, tmp42, 0);
  }
  return (unsigned __int64)(v2 / v4);
}
