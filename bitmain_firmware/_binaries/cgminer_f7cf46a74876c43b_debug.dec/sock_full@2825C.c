bool __fastcall sock_full(pool *pool)
{
  char *sockbuf; // r3

  sockbuf = pool->sockbuf;
  return *sockbuf || socket_full(pool->sock, (unsigned __int8)*sockbuf);
}
