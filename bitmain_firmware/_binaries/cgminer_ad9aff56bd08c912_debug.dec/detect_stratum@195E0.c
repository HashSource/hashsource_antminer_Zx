bool __fastcall detect_stratum(pool *pool, char *url)
{
  _BOOL4 sockaddr; // r5
  const char *v5; // r1
  char *v7; // r0
  char *sockaddr_url; // r3

  check_extranonce_option(pool, url);
  sockaddr = extract_sockaddr(url, &pool->sockaddr_url, &pool->stratum_port);
  if ( !sockaddr )
    return sockaddr;
  LOWORD(v5) = -2584;
  HIWORD(v5) = (unsigned int)"t common denominator set to %lu" >> 16;
  if ( strncasecmp(url, v5, 0xEu) )
  {
    LOBYTE(sockaddr) = 0;
    return sockaddr;
  }
  v7 = _strdup(url);
  sockaddr_url = pool->sockaddr_url;
  pool->rpc_url = v7;
  pool->has_stratum = 1;
  pool->stratum_url = sockaddr_url;
  return sockaddr;
}
