void *__fastcall httpListenThread(void *param)
{
  int v1; // r0
  int v2; // r0
  void *v3; // r4
  int addr_len; // [sp+10h] [bp-102Ch] BYREF
  int v6; // [sp+14h] [bp-1028h] BYREF
  sockaddr_in service; // [sp+18h] [bp-1024h] BYREF
  sockaddr_in client_addr; // [sp+28h] [bp-1014h] BYREF
  char tmp42[4100]; // [sp+38h] [bp-1004h] BYREF

  sleep(0x1Eu);
  do
  {
    v1 = socket(2, 1, 6);
    listen_sockfd = v1;
    if ( v1 < 0 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        strcpy(tmp42, "socket creating failed, try again after 10s...");
        applog(5, tmp42, 0);
      }
      sleep(0xAu);
    }
    else
    {
      v6 = 1;
      if ( setsockopt(v1, 1, 2, &v6, 4u) < 0 && (use_syslog || opt_log_output || opt_log_level > 3) )
      {
        strcpy(tmp42, "*******************setsockopt(SO_REUSEADDR) failed");
        applog(4, tmp42, 0);
      }
      memset(&service.sin_addr, 0, 12);
      *(_DWORD *)&service.sin_family = -1407778814;
      if ( bind(listen_sockfd, (const struct sockaddr *)&service, 0x10u) < 0 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          strcpy(tmp42, "http port bind failed! try again after 10s...");
          applog(5, tmp42, 0);
        }
      }
      else
      {
        if ( listen(listen_sockfd, 100) >= 0 )
          break;
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          strcpy(tmp42, "http listen failed! try again after 10s...");
          applog(5, tmp42, 0);
        }
      }
      close(listen_sockfd);
      listen_sockfd = -1;
      sleep(0xAu);
    }
  }
  while ( !ExitServer );
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(tmp42, "start listen on 6060 ...");
    applog(5, tmp42, 0);
  }
  if ( !ExitServer )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        usleep(0x2710u);
        addr_len = 16;
        v2 = accept(listen_sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len);
        v3 = (void *)v2;
        if ( v2 != -1 )
          break;
        if ( ExitServer )
          goto LABEL_20;
      }
      if ( ExitServer )
        break;
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42, 0x1000u, "one client connected sock=%d", v2);
        applog(7, tmp42, 0);
      }
      statusServiceThread(v3);
      if ( ExitServer )
        goto LABEL_20;
    }
    close(v2);
  }
LABEL_20:
  close(listen_sockfd);
  listen_sockfd = -1;
  return 0;
}
