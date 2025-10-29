bool __fastcall cnx_needed(pool *pool)
{
  int prio; // r4

  if ( pool->enabled != pool_enable::POOL_ENABLED )
    return 0;
  if ( (unsigned int)(pool_strategy_0 - 3) <= 1 || pool->has_stratum && pool->idle )
    return 1;
  if ( pool == current_pool() )
    return 1;
  if ( pool->sshares )
    return 1;
  if ( pool_strategy_0 == pool_strategy::POOL_FAILOVER )
  {
    prio = pool->prio;
    if ( prio < cp_prio() )
      return 1;
  }
  return no_work;
}
