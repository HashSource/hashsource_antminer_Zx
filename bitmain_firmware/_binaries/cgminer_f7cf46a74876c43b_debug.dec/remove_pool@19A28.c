void __fastcall remove_pool(pool *pool)
{
  int v1; // r7
  int v2; // r12
  pool **v3; // r2
  pool **v4; // r6
  int v5; // r1
  int v6; // t1
  int v7; // r3
  bool v8; // cc
  int v9; // r3
  int v10; // r3

  v1 = total_pools;
  v2 = total_pools - 1;
  if ( total_pools > 0 )
  {
    v3 = pools;
    v4 = &pools[total_pools];
    do
    {
      v6 = (int)*v3++;
      v5 = v6;
      v7 = *(_DWORD *)(v6 + 4);
      v8 = v7 <= pool->prio;
      v9 = v7 - 1;
      if ( !v8 )
        *(_DWORD *)(v5 + 4) = v9;
    }
    while ( v3 != v4 );
  }
  if ( pool->pool_no < v2 )
  {
    pools[v2]->pool_no = pool->pool_no;
    pools[pool->pool_no] = pools[v2];
    v1 = total_pools;
  }
  pool->pool_no = v1;
  v10 = total_pools;
  pool->removed = 1;
  total_pools = v10 - 1;
}
