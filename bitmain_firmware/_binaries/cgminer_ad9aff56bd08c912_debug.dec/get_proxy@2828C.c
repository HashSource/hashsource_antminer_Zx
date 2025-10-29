char *__fastcall get_proxy(char *url, pool *pool)
{
  int v3; // r5
  const char *v4; // r4
  size_t v5; // r6
  char *v7; // r0
  char *v8; // r8
  char *v9; // r0
  const char *v10; // r1
  int v12; // r3
  const char *v13; // r2
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  LOWORD(v4) = 16000;
  v3 = 0;
  HIWORD(v4) = (unsigned int)"ks4 proxy: %s" >> 16;
  v5 = 5;
  pool->rpc_proxy = 0;
  while ( strncmp(url, v4, v5) )
  {
    ++v3;
    v4 = (const char *)*(&_func___11739.__data.__nusers + 2 * v3);
    if ( !v4 )
      return url;
    v5 = strlen(v4);
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
      LOWORD(v12) = 15984;
      LOWORD(v13) = 16360;
      HIWORD(v12) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
      HIWORD(v13) = (unsigned int)"false positive; hash > target)" >> 16;
      snprintf(tmp42, 0x1000u, v13, v12, &_func___11752.__align + 4, 881);
      applog(3, tmp42, 1);
      quit(1);
    }
    v10 = &url[v5];
    url = v8 + 1;
    strcpy(v9, v10);
    extract_sockaddr(pool->rpc_proxy, &pool->sockaddr_proxy_url, &pool->sockaddr_proxy_port);
    pool->rpc_proxytype = *(_DWORD *)&_func___12024[8 * v3 + 32];
  }
  return url;
}
