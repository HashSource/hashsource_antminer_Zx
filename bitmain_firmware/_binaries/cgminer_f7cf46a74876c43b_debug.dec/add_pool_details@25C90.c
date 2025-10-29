bool __fastcall add_pool_details(pool *pool, bool live, char *url, char *user, char *pass)
{
  _BOOL4 v6; // r6
  char *proxy; // r0
  size_t v9; // r5
  size_t v10; // r5
  char *v11; // r0
  pool_enable enabled; // r1
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  v6 = live;
  proxy = get_proxy(url, pool);
  pool->rpc_user = user;
  pool->rpc_url = proxy;
  pool->rpc_pass = pass;
  v9 = strlen(user);
  v10 = v9 + strlen(pass) + 2;
  v11 = (char *)malloc(v10);
  pool->rpc_userpass = v11;
  if ( !v11 )
  {
    strcpy(tmp42, "Failed to malloc userpass");
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  snprintf(v11, v10, "%s:%s", user, pass);
  enabled = pool->enabled;
  pool->testing = 1;
  pool->idle = 1;
  pool->blocking = !v6;
  if ( enabled != pool_enable::POOL_ENABLED )
    enable_pool((pool *)&pool->enabled);
  pthread_create(&pool->test_thread, 0, test_pool_thread, pool);
  if ( !v6 )
  {
    pthread_join(pool->test_thread, 0);
    LOBYTE(v6) = pools_active;
  }
  return v6;
}
