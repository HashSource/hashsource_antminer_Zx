send_ret __fastcall _stratum_send(pool *pool, char *s, ssize_t len)
{
  int v5; // r4
  size_t v6; // r0
  int sock; // r3
  int v8; // r9
  int v9; // r7
  int v10; // r7
  _BYTE *v11; // r7
  int v12; // r9
  int v13; // r8
  fd_set *p_tv_usec; // r3
  ssize_t v16; // r6
  ssize_t v17; // r0
  __int64 v18; // r2
  int bytes_sent; // r1
  int bytes_sent_high; // r5
  uint64_t v21; // kr08_8
  bool v22; // cf
  uint64_t v23; // r4
  unsigned int net_bytes_sent; // r1
  uint64_t v25; // kr10_8
  ssize_t lena; // [sp+8h] [bp-9Ch]
  ssize_t ssent; // [sp+Ch] [bp-98h]
  timeval timeout; // [sp+18h] [bp-8Ch] BYREF
  fd_set wd; // [sp+20h] [bp-84h] BYREF
  _BYTE v31[4]; // [sp+A0h] [bp-4h] BYREF

  v5 = len + 1;
  v6 = strlen(s);
  sock = pool->sock;
  lena = v5;
  *(_WORD *)&s[v6] = 10;
  if ( v5 <= 0 )
  {
    v18 = 0;
LABEL_17:
    bytes_sent = pool->cgminer_pool_stats.bytes_sent;
    bytes_sent_high = HIDWORD(pool->cgminer_pool_stats.bytes_sent);
    v21 = pool->cgminer_pool_stats.times_sent + 1;
    ++LODWORD(pool->cgminer_pool_stats.times_sent);
    v22 = __CFADD__(bytes_sent, (_DWORD)v18);
    LODWORD(v23) = bytes_sent + v18;
    net_bytes_sent = pool->cgminer_pool_stats.net_bytes_sent;
    HIDWORD(pool->cgminer_pool_stats.times_sent) = HIDWORD(v21);
    HIDWORD(v23) = bytes_sent_high + v22 + HIDWORD(v18);
    v25 = __PAIR64__(HIDWORD(pool->cgminer_pool_stats.net_bytes_sent), net_bytes_sent) + v18;
    pool->cgminer_pool_stats.bytes_sent = v23;
    pool->cgminer_pool_stats.net_bytes_sent = v25;
    return send_ret::SEND_OK;
  }
  else
  {
    LOBYTE(v8) = sock & 0x1F;
    v9 = (sock + 31) & (sock >> 31);
    if ( sock >= 0 )
      v9 = sock;
    v10 = v9 >> 5;
    if ( sock <= 0 )
      v8 = -(-sock & 0x1F);
    v11 = &v31[4 * v10];
    v12 = 1 << v8;
    v13 = sock + 1;
    ssent = 0;
    do
    {
      while ( 1 )
      {
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        while ( 1 )
        {
          p_tv_usec = (fd_set *)&timeout.tv_usec;
          do
          {
            p_tv_usec->fds_bits[1] = 0;
            p_tv_usec = (fd_set *)((char *)p_tv_usec + 4);
          }
          while ( p_tv_usec != (fd_set *)&wd.fds_bits[31] );
          *((_DWORD *)v11 - 32) |= v12;
          if ( select(v13, 0, &wd, 0, &timeout) > 0 )
            break;
          if ( *_errno_location() != 4 )
            return send_ret::SEND_SELECTFAIL;
        }
        v16 = ssent;
        v17 = send(pool->sock, &s[ssent], lena, 0x4000);
        if ( v17 < 0 )
          break;
        ssent += v17;
        lena -= v17;
        if ( lena <= 0 )
        {
          HIDWORD(v18) = ssent >> 31;
          LODWORD(v18) = v16 + v17;
          goto LABEL_17;
        }
      }
    }
    while ( *_errno_location() == 11 );
    return send_ret::SEND_SENDFAIL;
  }
}
