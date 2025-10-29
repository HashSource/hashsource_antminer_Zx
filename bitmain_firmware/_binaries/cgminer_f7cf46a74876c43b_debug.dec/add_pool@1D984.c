pool *add_pool()
{
  pool *v0; // r0
  pool *v1; // r4
  int v2; // r3
  pool **v3; // r0
  int v4; // r1
  pool **v5; // r0
  int v6; // r2
  int v8; // r3
  int v9; // r4
  int v10; // r3
  int v11; // r4
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v0 = (pool *)calloc(0x750u, 1u);
  if ( !v0 )
  {
    strcpy(tmp42, "Failed to malloc pool in add_pool");
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  v1 = v0;
  v2 = total_pools;
  v3 = pools;
  v4 = total_pools + 2;
  v1->pool_no = total_pools;
  v1->prio = v2;
  v5 = (pool **)realloc(v3, 4 * v4);
  v6 = total_pools;
  pools = v5;
  ++total_pools;
  v5[v6] = v1;
  if ( pthread_mutex_init(&v1->pool_lock, 0) )
  {
    v8 = *_errno_location();
    v9 = 748;
    goto LABEL_11;
  }
  if ( pthread_cond_init(&v1->cr_cond, 0) )
  {
    strcpy(tmp42, "Failed to pthread_cond_init in add_pool");
    goto LABEL_12;
  }
  if ( pthread_mutex_init(&v1->data_lock.mutex, 0) )
  {
    v8 = *_errno_location();
    v9 = 751;
    goto LABEL_11;
  }
  if ( pthread_rwlock_init(&v1->data_lock.rwlock, 0) )
  {
    v10 = *_errno_location();
    v11 = 751;
LABEL_18:
    snprintf(
      tmp42,
      0x1000u,
      "Failed to pthread_rwlock_init errno=%d in %s %s():%d",
      v10,
      "cgminer.c",
      &_func___16209.__size[8],
      v11);
LABEL_12:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  if ( pthread_mutex_init(&v1->stratum_lock, 0) )
  {
    v8 = *_errno_location();
    v9 = 752;
LABEL_11:
    snprintf(
      tmp42,
      0x1000u,
      "Failed to pthread_mutex_init errno=%d in %s %s():%d",
      v8,
      "cgminer.c",
      &_func___16209.__size[8],
      v9);
    goto LABEL_12;
  }
  if ( pthread_mutex_init(&v1->gbt_lock.mutex, 0) )
  {
    v8 = *_errno_location();
    v9 = 753;
    goto LABEL_11;
  }
  if ( pthread_rwlock_init(&v1->gbt_lock.rwlock, 0) )
  {
    v10 = *_errno_location();
    v11 = 753;
    goto LABEL_18;
  }
  v1->rpc_proxy = 0;
  v1->rpc_req = "{\"method\": \"getwork\", \"params\": [], \"id\":0}\n";
  v1->curlring.next = &v1->curlring;
  v1->curlring.prev = &v1->curlring;
  v1->tv_idle.tv_sec = -1;
  v1->quota = 1;
  adjust_quota_gcd();
  return v1;
}
