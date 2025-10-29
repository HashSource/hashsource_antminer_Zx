void adjust_quota_gcd()
{
  unsigned int v0; // r4
  pool **v1; // r7
  pool **v2; // r5
  pool *v3; // t1
  unsigned int quota; // r3
  bool v5; // cf
  pool **v6; // r8
  int v7; // t1
  unsigned int v8; // r6
  unsigned int v9; // r8
  _DWORD *v10; // t1
  const char *v11; // r2
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( total_pools <= 0 )
  {
    v0 = 1;
  }
  else
  {
    v0 = -1;
    v1 = pools;
    v2 = pools;
    do
    {
      v3 = *v2++;
      quota = v3->quota;
      v5 = 1;
      if ( quota )
        v5 = quota >= v0;
      if ( !v5 )
        v0 = quota;
    }
    while ( &pools[total_pools] != v2 );
    if ( v0 == -1 )
    {
      v0 = 1;
    }
    else
    {
      v6 = pools;
      do
      {
        v7 = (int)*v6++;
        v8 = *(_DWORD *)(v7 + 56);
        if ( v8 && v8 % v0 )
        {
          do
            --v0;
          while ( v8 % v0 );
        }
      }
      while ( v2 != v6 );
    }
    v9 = global_quota_gcd;
    do
    {
      v10 = *v1++;
      v10[16] = v10[16] * v9 / v0;
      v10[15] = v10[14] / v0;
    }
    while ( v2 != v1 );
  }
  global_quota_gcd = v0;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v11) = -2644;
    HIWORD(v11) = (unsigned int)"scrypt" >> 16;
    snprintf(tmp42, 0x1000u, v11, v0);
    applog(7, tmp42, 0);
  }
}
