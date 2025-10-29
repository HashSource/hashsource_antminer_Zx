int __fastcall enable_device(cgpu_info *a1)
{
  const char *v2; // r2
  int v3; // r3
  cgpu_info **v4; // r1
  int v5; // r3
  const char *v6; // r2
  int v7; // r3
  int result; // r0
  const char *v9; // r2
  int v10; // r3

  a1->deven = dev_enable::DEV_ENABLED;
  if ( pthread_rwlock_wrlock(&devices_lock) )
    wr_lock((pthread_rwlock_t *)&_func___17121, (const char *)0x2894, v2, v3);
  v4 = devices;
  v5 = cgminer_id_count;
  a1->cgminer_id = cgminer_id_count;
  v4[v5] = a1;
  cgminer_id_count = v5 + 1;
  if ( pthread_rwlock_unlock(&devices_lock) )
    rw_unlock((pthread_rwlock_t *)&_func___17121, (const char *)0x2896, v6, v7);
  selective_yield();
  if ( hotplug_mode )
    new_threads += a1->threads;
  else
    mining_threads += a1->threads;
  result = pthread_rwlock_init(&a1->qlock, 0);
  if ( result )
    rwlock_init((pthread_rwlock_t *)&_func___17121, (const char *)0x289D, v9, v10);
  a1->queued_work = 0;
  return result;
}
