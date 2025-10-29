bool __fastcall socks4_negotiate(pool *pool, int sockd, bool socks4a)
{
  _BOOL4 v5; // r8
  char *stratum_port; // r0
  __int16 v7; // r0
  int *v8; // r2
  char v9; // r3^1
  int v10; // r0
  int v11; // r1
  unsigned int v12; // r6
  const char *v13; // r2
  char *sockaddr_url; // r0
  char *v16; // r8
  size_t v17; // r0
  size_t v18; // r6
  int v19; // r4
  unsigned int v20; // r6
  const char *v21; // r2
  addrinfo *servinfo; // [sp+8h] [bp-1228h] BYREF
  addrinfo servinfobase; // [sp+Ch] [bp-1224h] BYREF
  char buf[515]; // [sp+2Ch] [bp-1204h] BYREF
  char tmp42[4096]; // [sp+230h] [bp-1000h] BYREF

  v5 = socks4a;
  stratum_port = pool->stratum_port;
  *(_WORD *)buf = 260;
  v7 = strtol(stratum_port, 0, 10);
  LOWORD(v8) = 15828;
  buf[3] = v7;
  HIWORD(v8) = (unsigned int)" Error from proxy %s:%s - %s" >> 16;
  v9 = HIBYTE(v7);
  v10 = *v8;
  v11 = v8[1];
  buf[2] = v9;
  *(_DWORD *)&buf[8] = v10;
  *(_DWORD *)&buf[12] = v11;
  v12 = bswap32(inet_addr(pool->sockaddr_url));
  if ( v12 != -1 )
    goto LABEL_2;
  servinfo = &servinfobase;
  memset(tmp42, 0, 0x20u);
  sockaddr_url = pool->sockaddr_url;
  *(_DWORD *)&tmp42[4] = 2;
  if ( !getaddrinfo(sockaddr_url, 0, (const struct addrinfo *)tmp42, &servinfo) )
  {
    v20 = *(_DWORD *)&servinfo->ai_addr->sa_data[2];
    freeaddrinfo(servinfo);
    v12 = bswap32(v20);
    if ( v12 != -1 )
    {
LABEL_2:
      buf[7] = v12;
      buf[4] = HIBYTE(v12);
      buf[5] = BYTE2(v12);
      buf[6] = BYTE1(v12);
      send(sockd, buf, 0x10u, 0);
      goto LABEL_3;
    }
LABEL_22:
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      LOWORD(v21) = 15836;
      HIWORD(v21) = (unsigned int)"rom proxy %s:%s - %s" >> 16;
      snprintf(tmp42, 0x1000u, v21, pool->sockaddr_url);
      goto LABEL_9;
    }
    return 0;
  }
  if ( !v5 )
    goto LABEL_22;
  v16 = pool->sockaddr_url;
  *(_DWORD *)&buf[4] = 0x1000000;
  v17 = strlen(v16);
  if ( v17 >= 0xFF )
    v17 = 255;
  v18 = v17;
  memcpy(&buf[16], v16, v17);
  buf[v18 + 16] = 0;
  send(sockd, buf, v18 + 17, 0);
LABEL_3:
  if ( recv(sockd, tmp42, 1u, 0) == -1 || tmp42[0] || recv(sockd, tmp42, 1u, 0) == -1 || tmp42[0] != 90 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      LOWORD(v13) = 15888;
      HIWORD(v13) = (unsigned int)" proxy %s:%s" >> 16;
      snprintf(tmp42, 0x1000u, v13, pool->sockaddr_proxy_url, pool->sockaddr_proxy_port);
LABEL_9:
      applog(4, tmp42, 0);
      return 0;
    }
    return 0;
  }
  v19 = 6;
  do
  {
    recv(sockd, tmp42, 1u, 0);
    --v19;
  }
  while ( v19 );
  return 1;
}
