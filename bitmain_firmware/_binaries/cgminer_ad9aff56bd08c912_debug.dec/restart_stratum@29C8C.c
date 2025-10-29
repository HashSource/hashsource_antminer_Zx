bool __fastcall restart_stratum(pool *pool)
{
  _BOOL4 v3; // r5

  if ( pool->stratum_active )
    suspend_stratum(pool);
  if ( initiate_stratum(pool)
    && (!pool->extranonce_subscribe || subscribe_extranonce(pool))
    && (v3 = auth_stratum(pool)) )
  {
    stratum_resumed(pool);
    return v3;
  }
  else
  {
    pool_died(pool);
    return 0;
  }
}
