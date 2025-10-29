pool *add_url()
{
  int v0; // r3

  v0 = ++total_urls;
  if ( total_urls > total_pools )
  {
    add_pool();
    v0 = total_urls;
  }
  return *(&pools[v0] + 0x3FFFFFFF);
}
