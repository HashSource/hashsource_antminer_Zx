bool __fastcall socks4_negotiate(pool *pool, int sockd, bool socks4a)
{
  _BOOL4 v5; // r8
  char *stratum_port; // r0
  __int16 v7; // kr00_2
  unsigned int v8; // r6
  char *sockaddr_url; // r0
  char *v11; // r8
  size_t v12; // r0
  size_t v13; // r6
  int v14; // r4
  unsigned int v15; // r6
  addrinfo *servinfo; // [sp+8h] [bp-1228h] BYREF
  addrinfo servinfobase; // [sp+Ch] [bp-1224h] BYREF
  char buf[515]; // [sp+2Ch] [bp-1204h] BYREF
  char tmp42[4096]; // [sp+230h] [bp-1000h] BYREF

  v5 = socks4a;
  stratum_port = pool->stratum_port;
  *(_WORD *)buf = 260;
  v7 = strtol(stratum_port, 0, 10);
  buf[2] = HIBYTE(v7);
  buf[3] = v7;
  strcpy(&buf[8], "CGMINER");
  v8 = bswap32(inet_addr(pool->sockaddr_url));
  if ( v8 != -1 )
    goto LABEL_2;
  servinfo = &servinfobase;
  memset(tmp42, 0, 0x20u);
  sockaddr_url = pool->sockaddr_url;
  *(_DWORD *)&tmp42[4] = 2;
  if ( !getaddrinfo(sockaddr_url, 0, (const struct addrinfo *)tmp42, &servinfo) )
  {
    v15 = *(_DWORD *)&servinfo->ai_addr->sa_data[2];
    freeaddrinfo(servinfo);
    v8 = bswap32(v15);
    if ( v8 != -1 )
    {
LABEL_2:
      buf[7] = v8;
      buf[4] = HIBYTE(v8);
      buf[5] = BYTE2(v8);
      buf[6] = BYTE1(v8);
      send(sockd, buf, 0x10u, 0);
      goto LABEL_3;
    }
LABEL_22:
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      snprintf(tmp42, 0x1000u, "Invalid IP address specified for socks4 proxy: %s", pool->sockaddr_url);
      goto LABEL_9;
    }
    return 0;
  }
  if ( !v5 )
    goto LABEL_22;
  v11 = pool->sockaddr_url;
  *(_DWORD *)&buf[4] = 0x1000000;
  v12 = strlen(v11);
  if ( v12 >= 0xFF )
    v12 = 255;
  v13 = v12;
  memcpy(&buf[16], v11, v12);
  buf[v13 + 16] = 0;
  send(sockd, buf, v13 + 17, 0);
LABEL_3:
  if ( recv(sockd, tmp42, 1u, 0) == -1 || tmp42[0] || recv(sockd, tmp42, 1u, 0) == -1 || tmp42[0] != 90 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      snprintf(
        tmp42,
        0x1000u,
        "Bad response from %s:%s SOCKS4 server",
        pool->sockaddr_proxy_url,
        pool->sockaddr_proxy_port);
LABEL_9:
      applog(4, tmp42, 0);
      return 0;
    }
    return 0;
  }
  v14 = 6;
  do
  {
    recv(sockd, tmp42, 1u, 0);
    --v14;
  }
  while ( v14 );
  return 1;
}
