char *__fastcall set_loadbalance(pool_strategy *strategy)
{
  *strategy = pool_strategy::POOL_LOADBALANCE;
  return 0;
}
