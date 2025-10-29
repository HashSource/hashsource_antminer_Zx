char *__fastcall recv_line(pool *pool)
{
  char *sockbuf; // r6
  signed int v3; // r7
  char *v4; // r0
  char *v5; // r5
  size_t v6; // r0
  size_t v7; // r8
  unsigned int bytes_received; // r2
  _BOOL4 v9; // r7
  uint64_t v10; // kr08_8
  unsigned int bytes_received_high; // r6
  unsigned int net_bytes_received; // r3
  unsigned int v13; // kr00_4
  unsigned int net_bytes_received_high; // r3
  ssize_t v16; // r6
  int v17; // r5
  char *v18; // r9
  size_t v19; // r6
  size_t v20; // r8
  size_t v21; // r0
  size_t v22; // r6
  char *v23; // r0
  timeval rstart; // [sp+8h] [bp-3014h] BYREF
  timeval now; // [sp+10h] [bp-300Ch] BYREF
  char tmp42[4096]; // [sp+18h] [bp-3004h] BYREF
  char tmp42_0[8196]; // [sp+1018h] [bp-2004h] BYREF

  sockbuf = pool->sockbuf;
  if ( !strchr(sockbuf, 10) )
  {
    gettimeofday(&rstart, 0);
    if ( !socket_full(pool->sock, 60) )
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        strcpy(tmp42_0, "Timed out waiting for data on socket_full");
        applog(7, tmp42_0, 0);
      }
      goto LABEL_30;
    }
    while ( 1 )
    {
      memset(tmp42_0, 0, 0x2000u);
      v16 = recv(pool->sock, tmp42_0, 0x1FFCu, 0);
      if ( !v16 )
        break;
      gettimeofday(&now, 0);
      v17 = (int)((double)(now.tv_usec - rstart.tv_usec) / 1000000.0 + (double)(now.tv_sec - rstart.tv_sec));
      if ( v16 < 0 )
      {
        if ( *_errno_location() != 11 || !socket_full(pool->sock, 60 - v17) )
        {
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            strcpy(tmp42, "Failed to recv sock in recv_line");
            applog(7, tmp42, 0);
          }
          goto LABEL_36;
        }
      }
      else
      {
        v18 = pool->sockbuf;
        v19 = strlen(tmp42_0);
        v20 = strlen(v18);
        v21 = v19 + v20 + 1;
        if ( v21 >= pool->sockbuf_size )
        {
          v22 = (v21 & 0xFFFFE000) + 0x2000;
          v23 = (char *)realloc(v18, v22);
          pool->sockbuf = v23;
          if ( !v23 )
          {
            snprintf(tmp42, 0x1000u, "Failed to realloc pool sockbuf in %s %s():%d", "util.c", "recalloc_sock", 1997);
            applog(3, tmp42, 1);
            quit(1);
          }
          memset(&v23[v20], 0, v22 - v20);
          v18 = pool->sockbuf;
          pool->sockbuf_size = v22;
        }
        strcat(v18, tmp42_0);
      }
      sockbuf = pool->sockbuf;
      if ( v17 > 59 || strchr(pool->sockbuf, 10) )
        goto LABEL_2;
    }
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      strcpy(tmp42, "Socket closed waiting in recv_line");
      applog(7, tmp42, 0);
    }
LABEL_36:
    suspend_stratum(pool);
    sockbuf = pool->sockbuf;
  }
LABEL_2:
  v3 = strlen(sockbuf);
  v4 = strtok(sockbuf, (const char *)&word_58FE4);
  if ( !v4 )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      strcpy(tmp42_0, "Failed to parse a \\n terminated string in recv_line");
      applog(7, tmp42_0, 0);
    }
LABEL_30:
    v5 = 0;
    clear_sock(pool);
    return v5;
  }
  v5 = _strdup(v4);
  v6 = strlen(v5);
  v7 = v6;
  if ( (int)(v6 + 1) < v3 )
    memmove(pool->sockbuf, &pool->sockbuf[v6 + 1], v3 - v6 + 1);
  else
    *pool->sockbuf = 0;
  bytes_received = pool->cgminer_pool_stats.bytes_received;
  v9 = opt_protocol;
  v10 = pool->cgminer_pool_stats.times_received + 1;
  bytes_received_high = HIDWORD(pool->cgminer_pool_stats.bytes_received);
  HIDWORD(pool->cgminer_pool_stats.times_received) = HIDWORD(v10);
  net_bytes_received = pool->cgminer_pool_stats.net_bytes_received;
  LODWORD(pool->cgminer_pool_stats.times_received) = v10;
  v13 = net_bytes_received;
  net_bytes_received_high = HIDWORD(pool->cgminer_pool_stats.net_bytes_received);
  pool->cgminer_pool_stats.bytes_received = __PAIR64__(bytes_received_high, bytes_received) + v7;
  pool->cgminer_pool_stats.net_bytes_received = __PAIR64__(net_bytes_received_high, v13) + v7;
  if ( v9 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42_0, 0x1000u, "RECVD: %s", v5);
    applog(7, tmp42_0, 0);
  }
  return v5;
}
