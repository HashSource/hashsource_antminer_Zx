void zero_stats()
{
  int *v0; // r3
  pool **v1; // r6
  pool **v2; // r7
  int v3; // t1
  int v4; // r5
  cgpu_info *devices; // r4
  const char *v6; // r2
  int v7; // r3
  const char *v8; // r2
  int v9; // r3

  cgtime(&total_tv_start);
  copy_time(&tv_hashmeter, &total_tv_start);
  v0 = (int *)g_local_mhashes_dones;
  total_rolling = 0.0;
  rolling1 = 0.0;
  rolling5 = 0.0;
  rolling15 = 0.0;
  total_mhashes_done = 0.0;
  do
  {
    *(_QWORD *)v0 = 0;
    v0 += 2;
  }
  while ( v0 != &g_local_mhashes_index );
  total_secs = 1.0;
  zero_stats_flag = 1;
  g_local_mhashes_index = 0;
  hw_errors = 0;
  local_work = 0;
  found_blocks = 0;
  last_total_secs = 1.0;
  total_getworks = 0;
  total_accepted = 0;
  total_rejected = 0;
  g_max_fan = 0;
  g_max_temp = 0;
  total_stale = 0;
  total_discarded = 0;
  total_diff1 = 0;
  total_go = 0;
  total_ro = 0;
  total_diff_accepted = 0.0;
  total_diff_rejected = 0.0;
  total_diff_stale = 0.0;
  if ( total_pools > 0 )
  {
    v1 = pools;
    v2 = &pools[total_pools];
    do
    {
      v3 = (int)*v1++;
      *(_DWORD *)(v3 + 148) = 0;
      *(_QWORD *)(v3 + 8) = 0;
      *(_QWORD *)(v3 + 16) = 0;
      *(_DWORD *)(v3 + 152) = 0;
      *(_DWORD *)(v3 + 156) = 0;
      *(_DWORD *)(v3 + 160) = 0;
      *(_DWORD *)(v3 + 164) = 0;
      *(_DWORD *)(v3 + 384) = 0;
      *(_QWORD *)(v3 + 40) = 0;
      *(_QWORD *)(v3 + 104) = 0;
      *(_QWORD *)(v3 + 112) = 0;
      *(_QWORD *)(v3 + 120) = 0;
      *(_QWORD *)(v3 + 392) = 0;
    }
    while ( v2 != v1 );
  }
  zero_bestshare();
  if ( total_devices > 0 )
  {
    v4 = 0;
    do
    {
      devices = get_devices(v4);
      copy_time(&devices->dev_start_tv, &total_tv_start);
      v7 = pthread_mutex_lock(&hash_lock);
      if ( v7 )
        mutex_lock((pthread_mutex_t *)(&_func___14460.__align + 3), (const char *)0x16F2, v6, v7);
      devices->accepted = 0;
      devices->total_mhashes = 0.0;
      devices->rejected = 0;
      devices->hw_errors = 0;
      devices->utility = 0.0;
      devices->last_share_pool_time = 0;
      devices->diff_accepted = 0.0;
      devices->diff_rejected = 0.0;
      devices->last_share_diff = 0.0;
      devices->diff1 = 0;
      if ( pthread_mutex_unlock(&hash_lock) )
        mutex_unlock_noyield((pthread_mutex_t *)(&_func___14460.__align + 3), (const char *)0x16FD, v8, v9);
      ++v4;
      selective_yield();
      devices->drv->zero_stats(devices);
    }
    while ( total_devices > v4 );
  }
}
