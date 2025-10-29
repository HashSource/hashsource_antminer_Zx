char *__fastcall get_proxy(char *url, pool *pool)
{
  const char *v2; // r4
  int v4; // r5
  size_t v5; // r6
  char *v7; // r0
  char *v8; // r8
  char *v9; // r0
  const char *v10; // r1
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  v2 = "http:";
  v4 = 0;
  v5 = 5;
  pool->rpc_proxy = 0;
  while ( strncmp(url, v2, v5) )
  {
    ++v4;
    v2 = (const char *)*(&_func___11739.__data.__nusers + 2 * v4);
    if ( !v2 )
      return url;
    v5 = strlen(v2);
  }
  v7 = strchr(url, 124);
  v8 = v7;
  if ( v7 )
  {
    *v7 = 0;
    v9 = (char *)malloc(v7 - url + 1 - v5);
    pool->rpc_proxy = v9;
    if ( !v9 )
    {
      snprintf(tmp42, 0x1000u, "Failed to malloc rpc_proxy in %s %s():%d", "util.c", &_func___11752.__size[16], 881);
      applog(3, tmp42, 1);
      quit(1);
    }
    v10 = &url[v5];
    url = v8 + 1;
    strcpy(v9, v10);
    extract_sockaddr(pool->rpc_proxy, &pool->sockaddr_proxy_url, &pool->sockaddr_proxy_port);
    pool->rpc_proxytype = *(_DWORD *)&_func___12024[8 * v4 + 32];
  }
  return url;
}
