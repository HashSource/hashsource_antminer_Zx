bool __fastcall add_pool_details(pool *pool, bool live, char *url, char *user, char *pass)
{
  _BOOL4 v6; // r6
  char *proxy; // r0
  size_t v9; // r5
  size_t v10; // r5
  char *v11; // r0
  const char *v12; // r2
  pool_enable enabled; // r1
  void *(*v14)(void *); // r2
  int *v16; // r5
  int v17; // r0
  int v18; // r1
  int v19; // r2
  int v20; // r3
  int v21; // r1
  int v22; // r2
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
    LOWORD(v16) = 5688;
    HIWORD(v16) = (unsigned int)"s, disabling!" >> 16;
    v17 = *v16;
    v18 = v16[1];
    v19 = v16[2];
    v20 = v16[3];
    v16 += 4;
    *(_DWORD *)tmp42 = v17;
    *(_DWORD *)&tmp42[4] = v18;
    *(_DWORD *)&tmp42[8] = v19;
    *(_DWORD *)&tmp42[12] = v20;
    v21 = v16[1];
    v22 = v16[2];
    *(_DWORD *)&tmp42[16] = *v16;
    *(_DWORD *)&tmp42[20] = v21;
    *(_WORD *)&tmp42[24] = v22;
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  LOWORD(v12) = 17060;
  HIWORD(v12) = (unsigned int)"connect" >> 16;
  snprintf(v11, v10, v12, user, pass);
  enabled = pool->enabled;
  pool->testing = 1;
  pool->idle = 1;
  pool->blocking = !v6;
  if ( enabled != pool_enable::POOL_ENABLED )
    enable_pool((pool *)&pool->enabled);
  LOWORD(v14) = -4899;
  HIWORD(v14) = ((unsigned int)&loc_1EC8A + 3) >> 16;
  pthread_create(&pool->test_thread, 0, v14, pool);
  if ( !v6 )
  {
    pthread_join(pool->test_thread, 0);
    LOBYTE(v6) = pools_active;
  }
  return v6;
}
