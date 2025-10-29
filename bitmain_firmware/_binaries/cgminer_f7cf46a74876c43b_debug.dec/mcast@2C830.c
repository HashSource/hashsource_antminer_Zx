void mcast()
{
  addrinfo *v0; // r4
  addrinfo *i; // r3
  int v2; // r0
  int *v3; // r0
  char *v4; // r0
  time_t v5; // r6
  int *v6; // r0
  char *v7; // r5
  int ai_family; // r3
  sockaddr *ai_addr; // r3
  in_addr_t v10; // t1
  in_addr_t v11; // r1
  int v12; // r2
  int v13; // r3
  const char *v14; // r11
  size_t v15; // r0
  size_t v16; // r4
  int v17; // r7
  ssize_t v18; // r4
  _BOOL4 v19; // r11
  const char *v20; // r1
  socklen_t v21; // r1
  const char *v22; // r4
  int v23; // r0
  int *v24; // r0
  char *v25; // r0
  addrinfo *v26; // r3
  addrinfo *v27; // r4
  int v28; // r0
  size_t v29; // r0
  ssize_t v30; // r4
  int *v31; // r0
  char *v32; // r0
  int *v33; // r0
  char *v34; // r0
  int mcast_sock; // [sp+10h] [bp-1914h]
  size_t expect_code_len; // [sp+1Ch] [bp-1908h]
  char *expect_code; // [sp+24h] [bp-1900h]
  int fd; // [sp+28h] [bp-18FCh]
  addrinfo *client; // [sp+2Ch] [bp-18F8h]
  char group; // [sp+4Bh] [bp-18D9h] BYREF
  socklen_t came_from_siz; // [sp+4Ch] [bp-18D8h] BYREF
  char *connectaddr; // [sp+50h] [bp-18D4h] BYREF
  addrinfo *res; // [sp+54h] [bp-18D0h] BYREF
  int optval; // [sp+58h] [bp-18CCh] BYREF
  char expect[12]; // [sp+5Ch] [bp-18C8h] BYREF
  char port_s[12]; // [sp+68h] [bp-18BCh] BYREF
  char came_from_port[12]; // [sp+74h] [bp-18B0h] BYREF
  addrinfo hints; // [sp+80h] [bp-18A4h] BYREF
  sockaddr_storage came_from; // [sp+A0h] [bp-1884h] BYREF
  char buf[1024]; // [sp+120h] [bp-1804h] BYREF
  ip_mreq grp; // [sp+520h] [bp-1404h] BYREF
  int v52; // [sp+528h] [bp-13FCh]
  int v53; // [sp+52Ch] [bp-13F8h]
  int v54; // [sp+530h] [bp-13F4h]
  char tmp42[4100]; // [sp+920h] [bp-1004h] BYREF

  strcpy(expect, "cgminer-");
  sprintf(port_s, "%d", opt_api_mcast_port);
  memset(&hints, 0, sizeof(hints));
  if ( getaddrinfo(opt_api_mcast_addr, port_s, &hints, &res) )
  {
    strcpy(tmp42, "Invalid API Multicast Address");
    applog(3, tmp42, 1);
    quit(1);
  }
  v0 = res;
  if ( !res )
  {
LABEL_17:
    freeaddrinfo(res);
    strcpy(tmp42, "API mcast could not open socket");
    applog(3, tmp42, 1);
    quit(1);
  }
  for ( i = res; ; i = res )
  {
    v2 = socket(i->ai_family, 2, 0);
    if ( v2 > 0 )
    {
      mcast_sock = v2;
      goto LABEL_9;
    }
    v0 = v0->ai_next;
    if ( !v0 )
      break;
  }
  mcast_sock = v2;
  if ( v2 == -1 )
    goto LABEL_17;
LABEL_9:
  optval = 1;
  if ( setsockopt(mcast_sock, 1, 2, &optval, 4u) < 0 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      goto die;
    v3 = _errno_location();
    v4 = strerror(*v3);
    snprintf(
      tmp42,
      0x1000u,
      "API mcast setsockopt SO_REUSEADDR failed (%s)%s",
      v4,
      " - API multicast listener will not be available");
    goto LABEL_14;
  }
  v5 = time(0);
  while ( 1 )
  {
    if ( bind(mcast_sock, v0->ai_addr, v0->ai_addrlen) >= 0 )
    {
      ai_family = v0->ai_family;
      if ( ai_family == 2 )
      {
        grp.imr_multiaddr.s_addr = 0;
        grp.imr_interface.s_addr = 0;
        grp.imr_multiaddr.s_addr = *(_DWORD *)&v0->ai_addr->sa_data[2];
        if ( setsockopt(mcast_sock, 0, 35, &grp, 8u) >= 0 )
        {
LABEL_25:
          freeaddrinfo(res);
          v14 = opt_api_mcast_code;
          v15 = strlen(opt_api_mcast_code);
          v16 = v15 + 10;
          expect_code_len = v15 + 9;
          expect_code = (char *)malloc(v15 + 10);
          if ( !expect_code )
          {
            strcpy(tmp42, "Failed to malloc mcast expect_code");
            applog(3, tmp42, 1);
            quit(1);
          }
          fd = -1;
          v17 = 0;
          snprintf(expect_code, v16, "%s%s-", expect, v14);
          while ( 1 )
          {
            do
            {
              while ( 1 )
              {
                cgsleep_ms(1000);
                came_from_siz = 128;
                ++v17;
                v18 = recvfrom(mcast_sock, buf, 0x3FFu, 0, (struct sockaddr *)&came_from, &came_from_siz);
                if ( v18 >= 0 )
                  break;
                if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  v24 = _errno_location();
                  v25 = strerror(*v24);
                  snprintf(tmp42, 0x1000u, "API mcast failed count=%d (%s) (%d)", v17, v25, mcast_sock);
                  applog(7, tmp42, 0);
                }
              }
              v19 = check_connect(&came_from, &connectaddr, &group);
              if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                v20 = "Ignored";
                if ( v19 )
                  v20 = "Accepted";
                snprintf(tmp42, 0x1000u, "API mcast from %s - %s", connectaddr, v20);
                applog(7, tmp42, 0);
              }
            }
            while ( !v19 );
            v21 = came_from_siz;
            buf[v18] = 0;
            if ( v18 )
            {
              if ( buf[v18 - 1] == 10 )
                buf[--v18] = 0;
              getnameinfo((const struct sockaddr *)&came_from, v21, 0, 0, came_from_port, 0xAu, 1u);
              if ( opt_debug )
              {
LABEL_58:
                if ( use_syslog || opt_log_output || opt_log_level > 6 )
                {
                  snprintf(
                    tmp42,
                    0x1000u,
                    "API mcast request rep=%d (%s) from [%s]:%s",
                    v18,
                    buf,
                    connectaddr,
                    came_from_port);
                  applog(7, tmp42, 0);
                }
                if ( expect_code_len < v18 && !memcmp(buf, expect_code, expect_code_len) )
                  goto LABEL_42;
                if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  strcpy(tmp42, "API mcast request was no good");
                  applog(7, tmp42, 0);
                }
              }
              else if ( expect_code_len < v18 && !memcmp(buf, expect_code, expect_code_len) )
              {
LABEL_42:
                v22 = &buf[expect_code_len];
                v23 = strtol(&buf[expect_code_len], 0, 10);
                if ( (unsigned int)(v23 - 1) <= 0xFFFE )
                {
                  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                  {
                    snprintf(tmp42, 0x1000u, "API mcast request OK port %s=%d", v22, v23);
                    applog(7, tmp42, 0);
                  }
                  if ( getaddrinfo(connectaddr, v22, &hints, &res) )
                  {
                    if ( use_syslog || opt_log_output || opt_log_level > 2 )
                    {
                      snprintf(tmp42, 0x1000u, "Invalid client address %s", connectaddr);
                      goto LABEL_79;
                    }
                  }
                  else
                  {
                    v26 = res;
                    client = res;
                    v27 = res;
                    if ( res )
                    {
                      while ( 1 )
                      {
                        v28 = socket(v26->ai_family, 2, 0);
                        if ( mcast_sock > 0 )
                          break;
                        v27 = v27->ai_next;
                        if ( !v27 )
                          break;
                        v26 = res;
                      }
                      fd = v28;
                      client = v27;
                    }
                    if ( fd == -1 )
                    {
                      freeaddrinfo(res);
                      if ( use_syslog || opt_log_output || opt_log_level > 2 )
                      {
                        snprintf(tmp42, 0x1000u, "API mcast could not open socket to client %s", connectaddr);
LABEL_79:
                        applog(3, tmp42, 0);
                      }
                    }
                    else
                    {
                      snprintf((char *)&grp, 0x400u, "cgm-FTW-%d-%s", opt_api_port, opt_api_mcast_des);
                      v29 = strlen((const char *)&grp);
                      v30 = sendto(fd, &grp, v29 + 1, 0, client->ai_addr, client->ai_addrlen);
                      freeaddrinfo(res);
                      if ( v30 < 0 )
                      {
                        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                        {
                          v31 = _errno_location();
                          v32 = strerror(*v31);
                          snprintf(tmp42, 0x1000u, "API mcast send reply failed (%s) (%d)", v32, fd);
                          applog(7, tmp42, 0);
                        }
                      }
                      else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                      {
                        snprintf(tmp42, 0x1000u, "API mcast send reply (%s) succeeded (%d) (%d)", &grp, v30, fd);
                        applog(7, tmp42, 0);
                      }
                      close(fd);
                    }
                  }
                }
                else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  snprintf(tmp42, 0x1000u, "API mcast request ignored - invalid port (%s)", v22);
                  applog(7, tmp42, 0);
                }
              }
            }
            else
            {
              getnameinfo((const struct sockaddr *)&came_from, v21, 0, 0, came_from_port, 0xAu, 1u);
              if ( opt_debug )
                goto LABEL_58;
            }
          }
        }
      }
      else
      {
        if ( ai_family != 10 )
          goto LABEL_25;
        ai_addr = v0->ai_addr;
        v10 = *(_DWORD *)&ai_addr->sa_data[6];
        ai_addr = (sockaddr *)((char *)ai_addr + 8);
        v11 = *(_DWORD *)&ai_addr->sa_data[2];
        v12 = *(_DWORD *)&ai_addr->sa_data[6];
        v13 = *(_DWORD *)&ai_addr->sa_data[10];
        grp.imr_multiaddr.s_addr = v10;
        grp.imr_interface.s_addr = v11;
        v52 = v12;
        v53 = v13;
        v54 = 0;
        if ( setsockopt(mcast_sock, 41, 20, &grp, 0x14u) >= 0 )
          goto LABEL_25;
      }
      if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
        goto die;
      v33 = _errno_location();
      v34 = strerror(*v33);
      snprintf(tmp42, 0x1000u, "API mcast join failed (%s)%s", v34, " - API multicast listener will not be available");
LABEL_14:
      applog(3, tmp42, 0);
      goto die;
    }
    v6 = _errno_location();
    v7 = strerror(*v6);
    if ( time(0) - v5 > 61 )
      break;
    cgsleep_ms(30000);
  }
  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "API mcast bind to port %d failed (%s)%s",
      opt_api_mcast_port,
      v7,
      " - API multicast listener will not be available");
    applog(3, tmp42, 0);
  }
die:
  close(mcast_sock);
}
