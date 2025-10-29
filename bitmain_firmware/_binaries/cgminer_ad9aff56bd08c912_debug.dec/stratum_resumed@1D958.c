void __fastcall stratum_resumed(pool *pool)
{
  if ( pool_tclear((int)pool, &pool->idle) )
    stratum_resumed_0(pool);
}
