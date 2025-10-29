// Alternative name is 'socket_full.isra.2'
bool __fastcall socket_full(int pool, int wait)
{
  __time_t v2; // r1
  fd_set *p_tv_usec; // r3
  int v4; // r4
  _BYTE *v5; // r4
  int v6; // r3
  timeval timeout; // [sp+8h] [bp-8Ch] BYREF
  fd_set rd; // [sp+10h] [bp-84h] BYREF
  _BYTE v10[4]; // [sp+90h] [bp-4h] BYREF

  v2 = wait & ~(wait >> 31);
  p_tv_usec = (fd_set *)&timeout.tv_usec;
  do
  {
    p_tv_usec->fds_bits[1] = 0;
    p_tv_usec = (fd_set *)((char *)p_tv_usec + 4);
  }
  while ( &rd.fds_bits[31] != (__fd_mask *)p_tv_usec );
  timeout.tv_sec = v2;
  v4 = (pool + 31) & (pool >> 31);
  if ( pool >= 0 )
    v4 = pool;
  timeout.tv_usec = 0;
  v5 = &v10[4 * (v4 >> 5)];
  LOBYTE(v6) = pool & 0x1F;
  if ( pool <= 0 )
    v6 = -(-pool & 0x1F);
  *((_DWORD *)v5 - 32) |= 1 << v6;
  return select(pool + 1, &rd, 0, 0, &timeout) > 0;
}
