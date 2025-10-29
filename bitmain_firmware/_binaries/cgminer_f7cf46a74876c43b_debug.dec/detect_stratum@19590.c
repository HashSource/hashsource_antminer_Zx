bool __fastcall detect_stratum(pool *pool, char *url)
{
  _BOOL4 sockaddr; // r5
  char *v6; // r0
  char *sockaddr_url; // r3

  check_extranonce_option(pool, url);
  sockaddr = extract_sockaddr(url, &pool->sockaddr_url, &pool->stratum_port);
  if ( !sockaddr )
    return sockaddr;
  if ( strncasecmp(url, "stratum+tcp://", 0xEu) )
  {
    LOBYTE(sockaddr) = 0;
    return sockaddr;
  }
  v6 = _strdup(url);
  sockaddr_url = pool->sockaddr_url;
  pool->rpc_url = v6;
  pool->has_stratum = 1;
  pool->stratum_url = sockaddr_url;
  return sockaddr;
}
