void __fastcall _suspend_stratum(pool *pool)
{
  char *sockbuf; // r3
  int sock; // r0

  sockbuf = pool->sockbuf;
  if ( sockbuf )
    *sockbuf = 0;
  sock = pool->sock;
  pool->stratum_notify = 0;
  pool->stratum_active = 0;
  if ( sock )
    close(sock);
  pool->sock = 0;
}
