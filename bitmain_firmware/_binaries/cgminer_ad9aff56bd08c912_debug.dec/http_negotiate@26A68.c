bool __fastcall http_negotiate(pool *pool, int sockd, bool http0)
{
  char *sockaddr_url; // r0
  const char *v6; // r2
  const char *v7; // r2
  size_t v8; // r0
  ssize_t v9; // r0
  _BOOL4 v10; // r3
  const char *v11; // r2
  const char *v12; // r1
  int v13; // r7
  int v14; // r3
  const char *v15; // r10
  bool v16; // r4
  const char *v17; // r2
  const char *v18; // r2
  const char *v19; // r1
  const char *v20; // r2
  const char *v22; // r2
  const char *v23; // r2
  char buf[1024]; // [sp+10h] [bp-1400h] BYREF
  char tmp42[4096]; // [sp+410h] [bp-1000h] BYREF

  sockaddr_url = pool->sockaddr_url;
  if ( http0 )
  {
    LOWORD(v6) = 15480;
    HIWORD(v6) = (unsigned int)&unk_53BF8 >> 16;
    snprintf(buf, 0x400u, v6, sockaddr_url, pool->stratum_port);
  }
  else
  {
    LOWORD(v18) = 15508;
    HIWORD(v18) = (unsigned int)&unk_53C14 >> 16;
    snprintf(buf, 0x400u, v18, sockaddr_url, pool->stratum_port, sockaddr_url, pool->stratum_port);
  }
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v7) = 15548;
    HIWORD(v7) = (unsigned int)&unk_53C3C >> 16;
    snprintf(tmp42, 0x1000u, v7, pool->sockaddr_proxy_url, pool->sockaddr_proxy_port, buf);
    applog(7, tmp42, 0);
  }
  v8 = strlen(buf);
  send(sockd, buf, v8, 0);
  v9 = recv(sockd, buf, 0xCu, 0);
  if ( v9 > 0 )
  {
    v10 = opt_debug;
    buf[v9] = 0;
    if ( v10 && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v11) = 15632;
      HIWORD(v11) = (unsigned int)"\r\n" >> 16;
      snprintf(tmp42, 0x1000u, v11, pool->sockaddr_proxy_url, pool->sockaddr_proxy_port, buf);
      applog(7, tmp42, 0);
    }
    LOWORD(v12) = 15664;
    HIWORD(v12) = (unsigned int)": %s:%s\r\n\r\n" >> 16;
    v13 = strcmp(buf, v12);
    if ( v13 )
    {
      LOWORD(v19) = 15680;
      HIWORD(v19) = (unsigned int)"ing proxy %s:%s - %s" >> 16;
      v13 = strcmp(buf, v19);
      if ( v13 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 3 )
        {
          LOWORD(v20) = 15696;
          HIWORD(v20) = (unsigned int)"- %s" >> 16;
          snprintf(tmp42, 0x1000u, v20, pool->sockaddr_proxy_url, pool->sockaddr_proxy_port, buf);
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
        buf[v13] = -1;
        goto LABEL_31;
      }
      v14 = (unsigned __int8)tmp42[0];
      buf[v13++] = tmp42[0];
      if ( v14 == 255 )
        goto LABEL_31;
    }
    while ( v13 != 4 );
    LOWORD(v15) = 15776;
    HIWORD(v15) = (unsigned int)"oxy %s:%s - %s" >> 16;
    if ( !strncmp(buf, v15, 4u) )
    {
LABEL_20:
      v16 = opt_debug;
      if ( !opt_debug )
        return 1;
      if ( use_syslog || opt_log_output || opt_log_level > 6 )
      {
        LOWORD(v17) = 15784;
        HIWORD(v17) = (unsigned int)"s - %s" >> 16;
        snprintf(tmp42, 0x1000u, v17, pool->sockaddr_proxy_url, pool->sockaddr_proxy_port);
        applog(7, tmp42, 0);
      }
      return v16;
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
      if ( !strncmp(buf, v15, 4u) )
        goto LABEL_20;
    }
    buf[3] = -1;
LABEL_31:
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      LOWORD(v22) = 15732;
      HIWORD(v22) = (unsigned int)"%s after sending CONNECT" >> 16;
      v16 = 0;
      snprintf(tmp42, 0x1000u, v22, pool->sockaddr_proxy_url, pool->sockaddr_proxy_port);
      applog(4, tmp42, 0);
      return v16;
    }
    return 0;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
    return 0;
  LOWORD(v23) = 15576;
  HIWORD(v23) = (unsigned int)&unk_53C58 >> 16;
  snprintf(tmp42, 0x1000u, v23, pool->sockaddr_proxy_url, pool->sockaddr_proxy_port);
  applog(4, tmp42, 0);
  return 0;
}
