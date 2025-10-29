void __fastcall switchpool(io_data *io_data, int c, char *param, bool isjson, char group)
{
  io_data *v5; // r6
  int v6; // r2
  int v7; // r1
  int v9; // r7
  const char *v10; // r2
  int v11; // r3
  const char *v12; // r2
  int v13; // r3
  const char *v14; // r2
  int v15; // r3
  pool *v16; // r4
  const char *v17; // r2
  int v18; // r3
  bool groupa; // [sp+18h] [bp+18h]

  if ( total_pools )
  {
    v5 = io_data;
    if ( param && *param )
    {
      v9 = strtol(param, 0, 10);
      if ( pthread_mutex_lock(&control_lock.mutex) )
        mutex_lock_1((pthread_mutex_t *)&_func___11933, (const char *)0xB5B, v10, v11);
      rd_lock_0(&control_lock.rwlock, (const char *)&_func___11933, (const char *)0xB5B, v11);
      if ( pthread_mutex_unlock(&control_lock.mutex) )
        mutex_unlock_noyield_1((pthread_mutex_t *)&_func___11933, (const char *)0xB5B, v12, v13);
      if ( v9 >= 0 && v9 < total_pools )
      {
        v16 = pools[v9];
        v16->enabled = pool_enable::POOL_ENABLED;
        if ( pthread_rwlock_unlock(&control_lock.rwlock) )
          rw_unlock_0((pthread_rwlock_t *)&_func___11933, (const char *)0xB65, v17, v18);
        selective_yield();
        switch_pools(v16);
        groupa = isjson;
        v6 = v9;
        io_data = v5;
        v7 = 27;
      }
      else
      {
        if ( pthread_rwlock_unlock(&control_lock.rwlock) )
          rw_unlock_0((pthread_rwlock_t *)&_func___11933, (const char *)0xB5E, v14, v15);
        selective_yield();
        groupa = isjson;
        v6 = v9;
        io_data = v5;
        v7 = 26;
      }
    }
    else
    {
      groupa = isjson;
      v6 = 0;
      v7 = 25;
    }
  }
  else
  {
    groupa = isjson;
    v6 = 0;
    v7 = 8;
  }
  message(io_data, v7, v6, 0, groupa);
}
