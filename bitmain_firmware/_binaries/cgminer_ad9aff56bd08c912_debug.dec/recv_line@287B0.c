// local variable allocation has failed, the output may be wrong!
char *__fastcall recv_line(pool *pool)
{
  char *sockbuf; // r6
  size_t v3; // r0
  const char *v4; // r1
  signed int v5; // r7
  char *v6; // r0
  char *v7; // r5
  size_t v8; // r0
  size_t v9; // r8
  unsigned int bytes_received; // r2
  _BOOL4 v11; // r7
  uint64_t v12; // kr08_8
  unsigned int bytes_received_high; // r6
  unsigned int net_bytes_received; // r3
  unsigned int v15; // kr00_4
  unsigned int net_bytes_received_high; // r3
  const char *v17; // r2
  ssize_t v19; // r6
  int v20; // r5
  char *v21; // r9
  size_t v22; // r6
  size_t v23; // r8
  size_t v24; // r0
  size_t v25; // r6
  char *v26; // r0
  int *v27; // r5
  int v28; // r0
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int v32; // r0
  int v33; // r1
  int v34; // r2
  int v35; // r3
  int v36; // r0
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int v40; // r5
  int *v41; // r5
  int v42; // r0
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r0
  int v47; // r1
  int v48; // r2
  int v49; // r3
  int v50; // r5
  int *v51; // r6
  int v52; // r0
  int v53; // r1
  int v54; // r2
  int v55; // r3
  int v56; // r0
  int v57; // r1
  int v58; // r2
  int v59; // r3
  int v60; // r6
  int v61; // r3
  const char *v62; // r2
  int *v63; // r6
  int v64; // r0
  int v65; // r1
  int v66; // r2
  int v67; // r3
  int v68; // r0
  int v69; // r1
  int v70; // r2
  int v71; // r3
  int v72; // r1
  int v73; // r2
  timeval rstart; // [sp+8h] [bp-3014h] BYREF
  timeval now; // [sp+10h] [bp-300Ch] BYREF
  char tmp42[4096]; // [sp+18h] [bp-3004h] BYREF
  _BYTE tmp42_0[8192]; // [sp+1018h] [bp-2004h] OVERLAPPED BYREF

  sockbuf = pool->sockbuf;
  if ( !strchr(sockbuf, 10) )
  {
    gettimeofday(&rstart, 0);
    if ( !socket_full(pool->sock, 60) )
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v63) = 16604;
        HIWORD(v63) = (unsigned int)": %s" >> 16;
        v64 = *v63;
        v65 = v63[1];
        v66 = v63[2];
        v67 = v63[3];
        v63 += 4;
        *(_DWORD *)tmp42_0 = v64;
        *(_DWORD *)&tmp42_0[4] = v65;
        *(_DWORD *)&tmp42_0[8] = v66;
        *(_DWORD *)&tmp42_0[12] = v67;
        v68 = *v63;
        v69 = v63[1];
        v70 = v63[2];
        v71 = v63[3];
        v63 += 4;
        *(_DWORD *)&tmp42_0[16] = v68;
        *(_DWORD *)&tmp42_0[20] = v69;
        *(_DWORD *)&tmp42_0[24] = v70;
        *(_DWORD *)&tmp42_0[28] = v71;
        v72 = v63[1];
        v73 = v63[2];
        *(_DWORD *)&tmp42_0[32] = *v63;
        *(_DWORD *)&tmp42_0[36] = v72;
        *(_WORD *)&tmp42_0[40] = v73;
        applog(7, tmp42_0, 0);
      }
      goto LABEL_30;
    }
    while ( 1 )
    {
      memset(tmp42_0, 0, sizeof(tmp42_0));
      v19 = recv(pool->sock, tmp42_0, 0x1FFCu, 0);
      if ( !v19 )
        break;
      gettimeofday(&now, 0);
      v20 = (int)((double)(now.tv_usec - rstart.tv_usec) / 1000000.0 + (double)(now.tv_sec - rstart.tv_sec));
      if ( v19 < 0 )
      {
        if ( *_errno_location() != 11 || !socket_full(pool->sock, 60 - v20) )
        {
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            LOWORD(v41) = 16684;
            HIWORD(v41) = (unsigned int)"tum send failed due to no pool stratum_active" >> 16;
            v42 = *v41;
            v43 = v41[1];
            v44 = v41[2];
            v45 = v41[3];
            v41 += 4;
            *(_DWORD *)tmp42 = v42;
            *(_DWORD *)&tmp42[4] = v43;
            *(_DWORD *)&tmp42[8] = v44;
            *(_DWORD *)&tmp42[12] = v45;
            v46 = *v41;
            v47 = v41[1];
            v48 = v41[2];
            v49 = v41[3];
            v50 = v41[4];
            *(_DWORD *)&tmp42[16] = v46;
            *(_DWORD *)&tmp42[20] = v47;
            *(_DWORD *)&tmp42[24] = v48;
            *(_DWORD *)&tmp42[28] = v49;
            tmp42[32] = v50;
            applog(7, tmp42, 0);
          }
          goto LABEL_36;
        }
      }
      else
      {
        v21 = pool->sockbuf;
        v22 = strlen(tmp42_0);
        v23 = strlen(v21);
        v24 = v22 + v23 + 1;
        if ( v24 >= pool->sockbuf_size )
        {
          v25 = (v24 & 0xFFFFE000) + 0x2000;
          v26 = (char *)realloc(v21, v25);
          pool->sockbuf = v26;
          if ( !v26 )
          {
            LOWORD(v61) = 15984;
            LOWORD(v62) = 16720;
            HIWORD(v61) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
            HIWORD(v62) = (unsigned int)"um_active" >> 16;
            snprintf(tmp42, 0x1000u, v62, v61, "recalloc_sock", 1997);
            applog(3, tmp42, 1);
            quit(1);
          }
          memset(&v26[v23], 0, v25 - v23);
          v21 = pool->sockbuf;
          pool->sockbuf_size = v25;
        }
        strcat(v21, tmp42_0);
      }
      sockbuf = pool->sockbuf;
      if ( v20 > 59 || strchr(pool->sockbuf, 10) )
        goto LABEL_2;
    }
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v51) = 16648;
      HIWORD(v51) = (unsigned int)"Failed to send in stratum_send" >> 16;
      v52 = *v51;
      v53 = v51[1];
      v54 = v51[2];
      v55 = v51[3];
      v51 += 4;
      *(_DWORD *)tmp42 = v52;
      *(_DWORD *)&tmp42[4] = v53;
      *(_DWORD *)&tmp42[8] = v54;
      *(_DWORD *)&tmp42[12] = v55;
      v56 = *v51;
      v57 = v51[1];
      v58 = v51[2];
      v59 = v51[3];
      v60 = v51[4];
      *(_DWORD *)&tmp42[16] = v56;
      *(_DWORD *)&tmp42[20] = v57;
      *(_DWORD *)&tmp42[24] = v58;
      *(_DWORD *)&tmp42[28] = v59;
      *(_WORD *)&tmp42[32] = v60;
      tmp42[34] = BYTE2(v60);
      applog(7, tmp42, 0);
    }
LABEL_36:
    suspend_stratum(pool);
    sockbuf = pool->sockbuf;
  }
LABEL_2:
  v3 = strlen(sockbuf);
  LOWORD(v4) = -28576;
  v5 = v3;
  HIWORD(v4) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
  v6 = strtok(sockbuf, v4);
  if ( !v6 )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v27) = 16768;
      HIWORD(v27) = (unsigned int)"_full" >> 16;
      v28 = *v27;
      v29 = v27[1];
      v30 = v27[2];
      v31 = v27[3];
      v27 += 4;
      *(_DWORD *)tmp42_0 = v28;
      *(_DWORD *)&tmp42_0[4] = v29;
      *(_DWORD *)&tmp42_0[8] = v30;
      *(_DWORD *)&tmp42_0[12] = v31;
      v32 = *v27;
      v33 = v27[1];
      v34 = v27[2];
      v35 = v27[3];
      v27 += 4;
      *(_DWORD *)&tmp42_0[16] = v32;
      *(_DWORD *)&tmp42_0[20] = v33;
      *(_DWORD *)&tmp42_0[24] = v34;
      *(_DWORD *)&tmp42_0[28] = v35;
      v36 = *v27;
      v37 = v27[1];
      v38 = v27[2];
      v39 = v27[3];
      v40 = v27[4];
      *(_DWORD *)&tmp42_0[32] = v36;
      *(_DWORD *)&tmp42_0[36] = v37;
      *(_DWORD *)&tmp42_0[40] = v38;
      *(_DWORD *)&tmp42_0[44] = v39;
      *(_DWORD *)&tmp42_0[48] = v40;
      applog(7, tmp42_0, 0);
    }
LABEL_30:
    v7 = 0;
    clear_sock(pool);
    return v7;
  }
  v7 = _strdup(v6);
  v8 = strlen(v7);
  v9 = v8;
  if ( (int)(v8 + 1) < v5 )
    memmove(pool->sockbuf, &pool->sockbuf[v8 + 1], v5 - v8 + 1);
  else
    *pool->sockbuf = 0;
  bytes_received = pool->cgminer_pool_stats.bytes_received;
  v11 = opt_protocol;
  v12 = pool->cgminer_pool_stats.times_received + 1;
  bytes_received_high = HIDWORD(pool->cgminer_pool_stats.bytes_received);
  HIDWORD(pool->cgminer_pool_stats.times_received) = HIDWORD(v12);
  net_bytes_received = pool->cgminer_pool_stats.net_bytes_received;
  LODWORD(pool->cgminer_pool_stats.times_received) = v12;
  v15 = net_bytes_received;
  net_bytes_received_high = HIDWORD(pool->cgminer_pool_stats.net_bytes_received);
  pool->cgminer_pool_stats.bytes_received = __PAIR64__(bytes_received_high, bytes_received) + v9;
  pool->cgminer_pool_stats.net_bytes_received = __PAIR64__(net_bytes_received_high, v15) + v9;
  if ( v11 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v17) = 16820;
    HIWORD(v17) = (unsigned int)"o recv sock in recv_line" >> 16;
    snprintf(tmp42_0, 0x1000u, v17, v7);
    applog(7, tmp42_0, 0);
  }
  return v7;
}
