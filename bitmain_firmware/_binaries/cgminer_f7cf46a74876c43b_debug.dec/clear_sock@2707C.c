void __fastcall clear_sock(pool *pool)
{
  pthread_mutex_t *p_stratum_lock; // r5
  const char *v3; // r2
  int v4; // r3
  int v5; // r3
  int sock; // r0
  char *sockbuf; // r3

  p_stratum_lock = &pool->stratum_lock;
  if ( pthread_mutex_lock(&pool->stratum_lock) )
    mutex_lock_0((pthread_mutex_t *)"clear_sock", (const char *)0x7A3, v3, v4);
  do
  {
    v5 = 0;
    sock = pool->sock;
  }
  while ( sock && recv(sock, pool->sockbuf, 0x1FFCu, 0) > 0 );
  mutex_unlock_noyield_0(p_stratum_lock, "clear_sock", (const char *)0x7AC, v5);
  selective_yield();
  sockbuf = pool->sockbuf;
  if ( sockbuf )
    *sockbuf = 0;
}
