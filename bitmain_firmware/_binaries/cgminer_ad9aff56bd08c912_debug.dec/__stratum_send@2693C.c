send_ret __fastcall _stratum_send(pool *pool, char *s, ssize_t len)
{
  int v5; // r4
  size_t v6; // r0
  _WORD *v7; // r1
  int sock; // r3
  int v9; // r9
  int v10; // r7
  int v11; // r7
  _BYTE *v12; // r7
  int v13; // r9
  int v14; // r8
  fd_set *p_tv_usec; // r3
  ssize_t v17; // r6
  ssize_t v18; // r0
  __int64 v19; // r2
  int bytes_sent; // r1
  int bytes_sent_high; // r5
  uint64_t v22; // kr08_8
  bool v23; // cf
  uint64_t v24; // r4
  unsigned int net_bytes_sent; // r1
  uint64_t v26; // kr10_8
  ssize_t lena; // [sp+8h] [bp-9Ch]
  ssize_t ssent; // [sp+Ch] [bp-98h]
  timeval timeout; // [sp+18h] [bp-8Ch] BYREF
  fd_set wd; // [sp+20h] [bp-84h] BYREF
  _BYTE v32[4]; // [sp+A0h] [bp-4h] BYREF

  v5 = len + 1;
  v6 = strlen(s);
  LOWORD(v7) = -28576;
  HIWORD(v7) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
  sock = pool->sock;
  lena = v5;
  *(_WORD *)&s[v6] = *v7;
  if ( v5 <= 0 )
  {
    v19 = 0;
LABEL_17:
    bytes_sent = pool->cgminer_pool_stats.bytes_sent;
    bytes_sent_high = HIDWORD(pool->cgminer_pool_stats.bytes_sent);
    v22 = pool->cgminer_pool_stats.times_sent + 1;
    ++LODWORD(pool->cgminer_pool_stats.times_sent);
    v23 = __CFADD__(bytes_sent, (_DWORD)v19);
    LODWORD(v24) = bytes_sent + v19;
    net_bytes_sent = pool->cgminer_pool_stats.net_bytes_sent;
    HIDWORD(pool->cgminer_pool_stats.times_sent) = HIDWORD(v22);
    HIDWORD(v24) = bytes_sent_high + v23 + HIDWORD(v19);
    v26 = __PAIR64__(HIDWORD(pool->cgminer_pool_stats.net_bytes_sent), net_bytes_sent) + v19;
    pool->cgminer_pool_stats.bytes_sent = v24;
    pool->cgminer_pool_stats.net_bytes_sent = v26;
    return send_ret::SEND_OK;
  }
  else
  {
    LOBYTE(v9) = sock & 0x1F;
    v10 = (sock + 31) & (sock >> 31);
    if ( sock >= 0 )
      v10 = sock;
    v11 = v10 >> 5;
    if ( sock <= 0 )
      v9 = -(-sock & 0x1F);
    v12 = &v32[4 * v11];
    v13 = 1 << v9;
    v14 = sock + 1;
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
          *((_DWORD *)v12 - 32) |= v13;
          if ( select(v14, 0, &wd, 0, &timeout) > 0 )
            break;
          if ( *_errno_location() != 4 )
            return send_ret::SEND_SELECTFAIL;
        }
        v17 = ssent;
        v18 = send(pool->sock, &s[ssent], lena, 0x4000);
        if ( v18 < 0 )
          break;
        ssent += v18;
        lena -= v18;
        if ( lena <= 0 )
        {
          HIDWORD(v19) = ssent >> 31;
          LODWORD(v19) = v17 + v18;
          goto LABEL_17;
        }
      }
    }
    while ( *_errno_location() == 11 );
    return send_ret::SEND_SENDFAIL;
  }
}
