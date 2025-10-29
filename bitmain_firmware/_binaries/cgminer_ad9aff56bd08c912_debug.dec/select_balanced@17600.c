pool *__fastcall select_balanced(pool *cp)
{
  int shares; // r5
  pool *v2; // r4
  pool **v3; // r2
  pool *v4; // r3
  pool *v5; // t1

  shares = cp->shares;
  if ( total_pools > 0 )
  {
    v2 = cp;
    v3 = pools;
    do
    {
      v5 = *v3++;
      v4 = v5;
      if ( !v5->idle
        && v4->enabled == pool_enable::POOL_ENABLED
        && (!v4->has_stratum || v4->stratum_active)
        && v4->shares < shares )
      {
        v2 = v4;
        shares = v4->shares;
      }
    }
    while ( v3 != &pools[total_pools] );
    shares = v2->shares;
  }
  else
  {
    v2 = cp;
  }
  v2->shares = shares + 1;
  return v2;
}
