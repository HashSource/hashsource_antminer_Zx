bool __fastcall http_negotiate(pool *pool, int sockd, bool http0)
{
  char *sockaddr_url; // r0
  size_t v6; // r0
  ssize_t v7; // r0
  _BOOL4 v8; // r3
  int v9; // r7
  int v10; // r3
  bool v11; // r4
  char buf[1024]; // [sp+10h] [bp-1400h] BYREF
  char tmp42[4096]; // [sp+410h] [bp-1000h] BYREF

  sockaddr_url = pool->sockaddr_url;
  if ( http0 )
    snprintf(buf, 0x400u, "CONNECT %s:%s HTTP/1.0\r\n\r\n", sockaddr_url, pool->stratum_port);
  else
    snprintf(
      buf,
      0x400u,
      "CONNECT %s:%s HTTP/1.1\r\nHost: %s:%s\r\n\r\n",
      sockaddr_url,
      pool->stratum_port,
      sockaddr_url,
      pool->stratum_port);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "Sending proxy %s:%s - %s", pool->sockaddr_proxy_url, pool->sockaddr_proxy_port, buf);
    applog(7, tmp42, 0);
  }
  v6 = strlen(buf);
  send(sockd, buf, v6, 0);
  v7 = recv(sockd, buf, 0xCu, 0);
  if ( v7 > 0 )
  {
    v8 = opt_debug;
    buf[v7] = 0;
    if ( v8 && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(
        tmp42,
        0x1000u,
        "Received from proxy %s:%s - %s",
        pool->sockaddr_proxy_url,
        pool->sockaddr_proxy_port,
        buf);
      applog(7, tmp42, 0);
    }
    v9 = strcmp(buf, "HTTP/1.1 200");
    if ( v9 )
    {
      v9 = strcmp(buf, "HTTP/1.0 200");
      if ( v9 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 3 )
        {
          snprintf(
            tmp42,
            0x1000u,
            "HTTP Error from proxy %s:%s - %s",
            pool->sockaddr_proxy_url,
            pool->sockaddr_proxy_port,
            buf);
          applog(4, tmp42, 0);
          return 0;
        }
        return 0;
      }
    }
    do
    {
      if ( recv(sockd, tmp42, 1u, 0) == -1 )
      {
        buf[v9] = -1;
        goto LABEL_31;
      }
      v10 = (unsigned __int8)tmp42[0];
      buf[v9++] = tmp42[0];
      if ( v10 == 255 )
        goto LABEL_31;
    }
    while ( v9 != 4 );
    if ( !strncmp(buf, "\r\n\r\n", 4u) )
    {
LABEL_20:
      v11 = opt_debug;
      if ( !opt_debug )
        return 1;
      if ( use_syslog || opt_log_output || opt_log_level > 6 )
      {
        snprintf(
          tmp42,
          0x1000u,
          "Success negotiating with %s:%s HTTP proxy",
          pool->sockaddr_proxy_url,
          pool->sockaddr_proxy_port);
        applog(7, tmp42, 0);
      }
      return v11;
    }
    while ( 1 )
    {
      buf[0] = buf[1];
      buf[1] = buf[2];
      buf[2] = buf[3];
      if ( recv(sockd, tmp42, 1u, 0) == -1 )
        break;
      buf[3] = tmp42[0];
      if ( (unsigned __int8)tmp42[0] == 255 )
        goto LABEL_31;
      if ( !strncmp(buf, "\r\n\r\n", 4u) )
        goto LABEL_20;
    }
    buf[3] = -1;
LABEL_31:
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      v11 = 0;
      snprintf(
        tmp42,
        0x1000u,
        "Couldn't read HTTP byte from proxy %s:%s",
        pool->sockaddr_proxy_url,
        pool->sockaddr_proxy_port);
      applog(4, tmp42, 0);
      return v11;
    }
    return 0;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
    return 0;
  snprintf(
    tmp42,
    0x1000u,
    "Couldn't read from proxy %s:%s after sending CONNECT",
    pool->sockaddr_proxy_url,
    pool->sockaddr_proxy_port);
  applog(4, tmp42, 0);
  return 0;
}
