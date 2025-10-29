char *__fastcall set_rr(pool_strategy *strategy)
{
  *strategy = pool_strategy::POOL_ROUNDROBIN;
  return 0;
}
