void zero_bestshare()
{
  pool **v0; // r3
  pool **v1; // r4
  int v2; // t1

  *(_DWORD *)best_share = 0;
  *(_DWORD *)&best_share[4] = 0;
  best_diff = 0;
  suffix_string(0, best_share, 8u, 0);
  if ( total_pools > 0 )
  {
    v0 = pools;
    v1 = &pools[total_pools];
    do
    {
      v2 = (int)*v0++;
      *(_DWORD *)(v2 + 400) = 0;
      *(_DWORD *)(v2 + 404) = 0;
    }
    while ( v0 != v1 );
  }
}
