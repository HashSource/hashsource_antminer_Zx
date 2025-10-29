void __fastcall setup_url(pool *pool, char *arg)
{
  char *proxy; // r5
  char *v4; // r0
  char *v5; // r7
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  proxy = get_proxy(arg, pool);
  if ( !detect_stratum(pool, proxy) )
  {
    opt_set_charp(proxy, &pool->rpc_url);
    if ( strncmp(proxy, "http://", 7u) )
    {
      if ( strncmp(proxy, "https://", 8u) )
      {
        v4 = (char *)malloc(0x100u);
        v5 = v4;
        if ( !v4 )
        {
          strcpy(tmp42, "Failed to malloc httpinput");
          applog(3, tmp42, 1);
          _quit(1, 1);
        }
        strcpy(v4, "stratum+tcp://");
        strncat(v4, proxy, 0xF2u);
        detect_stratum(pool, v5);
      }
    }
  }
}
