void __fastcall pool_failed(pool *pool)
{
  if ( !pool_tset((int)pool, &pool->idle) )
  {
    cgtime(&pool->tv_idle);
    if ( pool == current_pool() )
      switch_pools(0);
  }
}
