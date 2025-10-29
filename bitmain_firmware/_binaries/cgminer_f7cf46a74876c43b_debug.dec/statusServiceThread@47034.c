void *__fastcall statusServiceThread(void *param)
{
  char *v2; // r8
  int v3; // r6
  ssize_t v4; // r0
  char v5; // r3
  char *v6; // r4
  char *v7; // r1
  const char *v9; // r5
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  _DWORD *v14; // r5
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r7
  int v19; // r8
  int v20; // r8
  int v21; // r8
  int v22; // r8
  int v23; // r8
  int v24; // r0
  size_t v25; // r0
  unsigned int v26; // r8
  ssize_t v27; // r0
  ssize_t v28; // r11
  signed int len; // [sp+Ch] [bp-7030h]
  char sendbuf[4]; // [sp+10h] [bp-702Ch] BYREF
  int recvlen; // [sp+14h] [bp-7028h] BYREF
  char endofrequest[8]; // [sp+18h] [bp-7024h] BYREF
  timeval timeout; // [sp+20h] [bp-701Ch] BYREF
  sockaddr_in from; // [sp+28h] [bp-7014h] BYREF
  char buf[4096]; // [sp+38h] [bp-7004h] BYREF
  char tmp42_0[4096]; // [sp+1038h] [bp-6004h] BYREF
  char recvbuf[10240]; // [sp+2038h] [bp-5004h] BYREF
  char tmp42[4096]; // [sp+4838h] [bp-2804h] BYREF

  timeout.tv_sec = 3;
  timeout.tv_usec = 0;
  memset(buf, 0, sizeof(buf));
  strcpy(sendbuf, "\r\n");
  v2 = recvbuf;
  recvlen = 0;
  strcpy(endofrequest, "\r\n\r\n");
  v3 = 0;
  memset(recvbuf, 0, sizeof(recvbuf));
  do
  {
    if ( ExitServer )
      goto LABEL_7;
    v4 = recvfrom((int)param, v2, 10239 - v3, 0, (struct sockaddr *)&from, (socklen_t *)&recvlen);
    v3 += v4;
    if ( v4 <= 0 )
    {
      close((int)param);
      if ( !opt_debug || !use_syslog && !opt_log_output && opt_log_level <= 6 )
        return 0;
      strcpy(tmp42, ":statusServiceThread recvfrom<=0");
      applog(7, tmp42, 0);
      return 0;
    }
    v2 = &recvbuf[v3];
    if ( v3 > 10238 )
    {
      close((int)param);
      if ( !opt_debug || !use_syslog && !opt_log_output && opt_log_level <= 6 )
        return 0;
      strcpy(tmp42, "BUFSIZE is too small!");
      applog(7, tmp42, 0);
      return 0;
    }
  }
  while ( !strstr(recvbuf, endofrequest) );
  if ( opt_debug )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 6 )
    {
      strcpy(tmp42, "find http request end flag!");
      applog(7, tmp42, 0);
LABEL_7:
      if ( opt_debug )
      {
        if ( !use_syslog )
          goto LABEL_9;
LABEL_11:
        snprintf(tmp42, 0x1000u, "get http=%s", recvbuf);
        applog(7, tmp42, 0);
      }
    }
    else
    {
LABEL_9:
      if ( opt_log_output || opt_log_level > 6 )
        goto LABEL_11;
    }
  }
  if ( recvbuf[0] != 71 || recvbuf[1] != 69 || recvbuf[2] != 84 || recvbuf[3] != 32 )
  {
    close((int)param);
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      qmemcpy(tmp42, "statusServiceThread not support http command", 44);
      v5 = aStatusservicet[44];
      v6 = &tmp42[44];
      v7 = tmp42;
      goto LABEL_19;
    }
    return 0;
  }
  if ( strstr(&recvbuf[4], "/rate") )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      strcpy(tmp42, "cmd : get rate");
      applog(7, tmp42, 0);
    }
    if ( freq_scan_status == 1 )
    {
      snprintf(buf, 0x1000u, "%d", &bench_hidiffs[900]);
    }
    else if ( freq_scan_status == 2 )
    {
      snprintf(buf, 0x1000u, "%s:%s", "searchfailed", "search_failed_info");
    }
    else
    {
      strcpy(buf, "searching");
    }
    goto LABEL_46;
  }
  if ( !strstr(&recvbuf[4], "/productName") )
  {
    close((int)param);
    if ( !opt_debug || !use_syslog && !opt_log_output && opt_log_level <= 6 )
      return 0;
    strcpy(tmp42, "statusServiceThread exit for Error cmd!");
    applog(7, tmp42, 0);
    return 0;
  }
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "cmd : get miner type");
    applog(7, tmp42, 0);
  }
  snprintf(buf, 0x1000u, g_miner_type);
LABEL_46:
  if ( setsockopt((int)param, 1, 21, &timeout, 8u) )
  {
    close((int)param);
    if ( !opt_debug || !use_syslog && !opt_log_output && opt_log_level <= 6 )
      return 0;
    v9 = "setsockopt SO_SNDTIMEO failed";
    goto LABEL_52;
  }
  v18 = setsockopt((int)param, 1, 20, &timeout, 8u);
  if ( !v18 )
  {
    len = strlen(buf);
    v19 = sprintf(tmp42, "HTTP/1.0  200  OK%s", sendbuf);
    v20 = v19 + sprintf(&tmp42[v19], "Server: SearchFreqServer%s", sendbuf);
    v21 = v20 + sprintf(&tmp42[v20], "Cache-Control: no-cache%s", sendbuf);
    v22 = v21 + sprintf(&tmp42[v21], "Pragma: no-cache%s", sendbuf);
    v23 = v22 + sprintf(&tmp42[v22], "Content-Type: text/plain%s", sendbuf);
    v24 = sprintf(&tmp42[v23], "Content-Length: %d%s", len, sendbuf);
    sprintf(&tmp42[v24 + v23], "Connection: Keep-Alive%s", endofrequest);
    if ( !opt_debug )
    {
      if ( ExitServer )
        goto LABEL_87;
      goto LABEL_74;
    }
    if ( use_syslog || opt_log_output || opt_log_level > 6 )
    {
      strcpy(tmp42_0, "send http response...\n");
      applog(7, tmp42_0, 0);
      if ( !ExitServer )
      {
LABEL_74:
        v25 = strlen(tmp42);
        v26 = 0;
        do
        {
          v27 = send((int)param, &tmp42[v26], v25 - v26, 0);
          if ( v27 == -1 )
          {
            if ( *_errno_location() != 11 )
            {
LABEL_81:
              close((int)param);
              if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                qmemcpy(tmp42_0, "statusServiceThread send http response error", 44);
                v5 = aStatusservicet_1[44];
                v6 = &tmp42_0[44];
                v7 = tmp42_0;
LABEL_19:
                *v6 = v5;
                applog(7, v7, 0);
              }
              return 0;
            }
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              strcpy(tmp42_0, "statusServiceThread send http timeout, try again...");
              applog(7, tmp42_0, 0);
            }
            usleep((__useconds_t)&loc_1869E + 2);
          }
          else
          {
            if ( v27 <= 0 )
              goto LABEL_81;
            v26 += v27;
          }
          v25 = strlen(tmp42);
        }
        while ( v25 > v26 && !ExitServer );
      }
      if ( !opt_debug )
        goto LABEL_87;
    }
    else if ( !ExitServer )
    {
      goto LABEL_74;
    }
    if ( use_syslog || opt_log_output || opt_log_level > 6 )
    {
      strcpy(tmp42_0, "send http data...");
      applog(7, tmp42_0, 0);
    }
    while ( 1 )
    {
LABEL_87:
      v28 = send((int)param, &buf[v18], len - v18, 0);
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42_0, 0x1000u, "send http data ret=%d", v28);
        applog(7, tmp42_0, 0);
      }
      if ( v28 <= 0 )
        break;
      v18 += v28;
      if ( len <= v18 || ExitServer )
        goto LABEL_95;
    }
    if ( opt_debug )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 6 )
      {
        strcpy(tmp42_0, "statusServiceThread send http data error");
        applog(7, tmp42_0, 0);
LABEL_95:
        if ( !opt_debug )
          goto LABEL_100;
        if ( use_syslog )
          goto LABEL_99;
      }
      if ( opt_log_output || opt_log_level > 6 )
      {
LABEL_99:
        strcpy(tmp42_0, "one client disconnected!");
        applog(7, tmp42_0, 0);
      }
    }
LABEL_100:
    close((int)param);
    return (void *)v18;
  }
  close((int)param);
  if ( !opt_debug || !use_syslog && !opt_log_output && opt_log_level <= 6 )
    return 0;
  v9 = "setsockopt SO_RCVTIMEO failed";
LABEL_52:
  v10 = *(_DWORD *)v9;
  v11 = *((_DWORD *)v9 + 1);
  v12 = *((_DWORD *)v9 + 2);
  v13 = *((_DWORD *)v9 + 3);
  v14 = v9 + 16;
  *(_DWORD *)tmp42 = v10;
  *(_DWORD *)&tmp42[4] = v11;
  *(_DWORD *)&tmp42[8] = v12;
  *(_DWORD *)&tmp42[12] = v13;
  v15 = v14[1];
  v16 = v14[2];
  v17 = v14[3];
  *(_DWORD *)&tmp42[16] = *v14;
  *(_DWORD *)&tmp42[20] = v15;
  *(_DWORD *)&tmp42[24] = v16;
  *(_WORD *)&tmp42[28] = v17;
  applog(7, tmp42, 0);
  return 0;
}
