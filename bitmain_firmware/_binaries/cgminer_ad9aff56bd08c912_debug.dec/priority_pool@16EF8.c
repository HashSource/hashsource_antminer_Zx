pool *__fastcall priority_pool(int choice)
{
  pool **v1; // r2
  pool *v2; // r1
  int v3; // r3
  pool *v4; // t1

  if ( total_pools <= 0 )
    return priority_pool_0(choice);
  v1 = pools;
  v2 = *pools;
  if ( (*pools)->prio != choice )
  {
    v3 = 0;
    while ( ++v3 != total_pools )
    {
      v4 = v1[1];
      ++v1;
      v2 = v4;
      if ( v4->prio == choice )
        return v2;
    }
    return priority_pool_0(choice);
  }
  return v2;
}
