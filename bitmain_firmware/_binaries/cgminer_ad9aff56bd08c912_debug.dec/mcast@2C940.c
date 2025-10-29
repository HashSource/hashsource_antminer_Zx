void mcast()
{
  _DWORD *v0; // r3
  const char *v1; // r1
  int v2; // r2
  int *v3; // r5
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r2
  int v10; // r3
  addrinfo *v11; // r4
  addrinfo *i; // r3
  int v13; // r0
  int *v14; // r0
  char *v15; // r0
  const char *v16; // r2
  int v17; // r1
  int *v18; // r5
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2
  int v25; // r3
  time_t v26; // r6
  int *v27; // r0
  char *v28; // r5
  int ai_family; // r3
  sockaddr *ai_addr; // r3
  in_addr_t v31; // t1
  in_addr_t v32; // r1
  int v33; // r2
  int v34; // r3
  char *v35; // r11
  size_t v36; // r0
  size_t v37; // r4
  const char *v38; // r7
  const char *v39; // r2
  int v40; // r7
  ssize_t v41; // r4
  _BOOL4 v42; // r11
  const char *v43; // r1
  socklen_t v44; // r1
  const char *v45; // r4
  int v46; // r0
  const char *v47; // r2
  int v48; // r1
  const char *v49; // r2
  int *v50; // r0
  char *v51; // r0
  const char *v52; // r2
  const char *v53; // r2
  int *v54; // r12
  int v55; // r0
  int v56; // r1
  int v57; // r2
  int v58; // r3
  int v59; // r1
  int v60; // r2
  int v61; // r3
  const char *v62; // r2
  addrinfo *v63; // r3
  addrinfo *v64; // r4
  int v65; // r0
  size_t v66; // r0
  ssize_t v67; // r4
  int *v68; // r0
  char *v69; // r0
  const char *v70; // r2
  int *v71; // r0
  char *v72; // r0
  int v73; // r1
  const char *v74; // r2
  int *v75; // r7
  int v76; // r0
  int v77; // r1
  int v78; // r2
  int v79; // r3
  int v80; // r0
  int v81; // r1
  int v82; // r2
  int v83; // r3
  int v84; // r7
  int mcast_sock; // [sp+10h] [bp-1914h]
  size_t expect_code_len; // [sp+1Ch] [bp-1908h]
  char *expect_code; // [sp+24h] [bp-1900h]
  int fd; // [sp+28h] [bp-18FCh]
  addrinfo *client; // [sp+2Ch] [bp-18F8h]
  const char *v90; // [sp+3Ch] [bp-18E8h]
  char group; // [sp+4Bh] [bp-18D9h] BYREF
  socklen_t came_from_siz; // [sp+4Ch] [bp-18D8h] BYREF
  char *connectaddr; // [sp+50h] [bp-18D4h] BYREF
  addrinfo *res; // [sp+54h] [bp-18D0h] BYREF
  int optval; // [sp+58h] [bp-18CCh] BYREF
  char expect[9]; // [sp+5Ch] [bp-18C8h] BYREF
  char port_s[12]; // [sp+68h] [bp-18BCh] BYREF
  char came_from_port[12]; // [sp+74h] [bp-18B0h] BYREF
  addrinfo hints; // [sp+80h] [bp-18A4h] BYREF
  sockaddr_storage came_from; // [sp+A0h] [bp-1884h] BYREF
  char buf[1024]; // [sp+120h] [bp-1804h] BYREF
  ip_mreq grp; // [sp+520h] [bp-1404h] BYREF
  int v103; // [sp+528h] [bp-13FCh]
  int v104; // [sp+52Ch] [bp-13F8h]
  int v105; // [sp+530h] [bp-13F4h]
  char tmp42[4096]; // [sp+920h] [bp-1004h] BYREF

  LOWORD(v0) = 21092;
  HIWORD(v0) = (unsigned int)"%d-%s" >> 16;
  v1 = (const char *)v0[1];
  v2 = v0[2];
  *(_DWORD *)expect = *v0;
  *(_DWORD *)&expect[4] = v1;
  LOWORD(v1) = -22732;
  expect[8] = v2;
  HIWORD(v1) = (unsigned int)"dev.timeout = %d us" >> 16;
  sprintf(port_s, v1, opt_api_mcast_port);
  memset(&hints, 0, sizeof(hints));
  if ( getaddrinfo(opt_api_mcast_addr, port_s, &hints, &res) )
  {
    LOWORD(v3) = 20420;
    HIWORD(v3) = (unsigned int)"ESTART\"" >> 16;
    v4 = *v3;
    v5 = v3[1];
    v6 = v3[2];
    v7 = v3[3];
    v3 += 4;
    *(_DWORD *)tmp42 = v4;
    *(_DWORD *)&tmp42[4] = v5;
    *(_DWORD *)&tmp42[8] = v6;
    *(_DWORD *)&tmp42[12] = v7;
    v8 = v3[1];
    v9 = v3[2];
    v10 = v3[3];
    *(_DWORD *)&tmp42[16] = *v3;
    *(_DWORD *)&tmp42[20] = v8;
    *(_DWORD *)&tmp42[24] = v9;
    *(_WORD *)&tmp42[28] = v10;
    applog(3, tmp42, 1);
    quit(1);
  }
  v11 = res;
  if ( !res )
  {
LABEL_17:
    LOWORD(v18) = 20452;
    HIWORD(v18) = (unsigned int)" escape buf %d in %s %s():%d" >> 16;
    freeaddrinfo(res);
    v19 = *v18;
    v20 = v18[1];
    v21 = v18[2];
    v22 = v18[3];
    v18 += 4;
    *(_DWORD *)tmp42 = v19;
    *(_DWORD *)&tmp42[4] = v20;
    *(_DWORD *)&tmp42[8] = v21;
    *(_DWORD *)&tmp42[12] = v22;
    v23 = v18[1];
    v24 = v18[2];
    v25 = v18[3];
    *(_DWORD *)&tmp42[16] = *v18;
    *(_DWORD *)&tmp42[20] = v23;
    *(_DWORD *)&tmp42[24] = v24;
    *(_DWORD *)&tmp42[28] = v25;
    applog(3, tmp42, 1);
    quit(1);
  }
  for ( i = res; ; i = res )
  {
    v13 = socket(i->ai_family, 2, 0);
    if ( v13 > 0 )
    {
      mcast_sock = v13;
      goto LABEL_9;
    }
    v11 = v11->ai_next;
    if ( !v11 )
      break;
  }
  mcast_sock = v13;
  if ( v13 == -1 )
    goto LABEL_17;
LABEL_9:
  optval = 1;
  if ( setsockopt(mcast_sock, 1, 2, &optval, 4u) < 0 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      goto die;
    v14 = _errno_location();
    v15 = strerror(*v14);
    LOWORD(v16) = 20484;
    LOWORD(v17) = 20532;
    HIWORD(v16) = (unsigned int)"api.c" >> 16;
    HIWORD(v17) = (unsigned int)"pted" >> 16;
    snprintf(tmp42, 0x1000u, v16, v15, v17);
    goto LABEL_14;
  }
  v26 = time(0);
  while ( 1 )
  {
    if ( bind(mcast_sock, v11->ai_addr, v11->ai_addrlen) >= 0 )
    {
      ai_family = v11->ai_family;
      if ( ai_family == 2 )
      {
        grp.imr_multiaddr.s_addr = 0;
        grp.imr_interface.s_addr = 0;
        grp.imr_multiaddr.s_addr = *(_DWORD *)&v11->ai_addr->sa_data[2];
        if ( setsockopt(mcast_sock, 0, 35, &grp, 8u) >= 0 )
        {
LABEL_25:
          freeaddrinfo(res);
          v35 = opt_api_mcast_code;
          v36 = strlen(opt_api_mcast_code);
          v37 = v36 + 10;
          expect_code_len = v36 + 9;
          expect_code = (char *)malloc(v36 + 10);
          if ( !expect_code )
          {
            LOWORD(v75) = 20652;
            HIWORD(v75) = (unsigned int)" (%s)%s" >> 16;
            v76 = *v75;
            v77 = v75[1];
            v78 = v75[2];
            v79 = v75[3];
            v75 += 4;
            *(_DWORD *)tmp42 = v76;
            *(_DWORD *)&tmp42[4] = v77;
            *(_DWORD *)&tmp42[8] = v78;
            *(_DWORD *)&tmp42[12] = v79;
            v80 = *v75;
            v81 = v75[1];
            v82 = v75[2];
            v83 = v75[3];
            v84 = v75[4];
            *(_DWORD *)&tmp42[16] = v80;
            *(_DWORD *)&tmp42[20] = v81;
            *(_DWORD *)&tmp42[24] = v82;
            *(_DWORD *)&tmp42[28] = v83;
            *(_WORD *)&tmp42[32] = v84;
            tmp42[34] = BYTE2(v84);
            applog(3, tmp42, 1);
            quit(1);
          }
          LOWORD(v38) = 20956;
          LOWORD(v39) = 20688;
          HIWORD(v38) = (unsigned int)"invalid port (%s)" >> 16;
          HIWORD(v39) = (unsigned int)"ll not be available" >> 16;
          fd = -1;
          v90 = v38;
          v40 = 0;
          snprintf(expect_code, v37, v39, expect, v35);
          while ( 1 )
          {
            do
            {
              while ( 1 )
              {
                cgsleep_ms(1000);
                came_from_siz = 128;
                ++v40;
                v41 = recvfrom(mcast_sock, buf, 0x3FFu, 0, (struct sockaddr *)&came_from, &came_from_siz);
                if ( v41 >= 0 )
                  break;
                if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  v50 = _errno_location();
                  v51 = strerror(*v50);
                  LOWORD(v52) = 20696;
                  HIWORD(v52) = (unsigned int)"e available" >> 16;
                  snprintf(tmp42, 0x1000u, v52, v40, v51, mcast_sock);
                  applog(7, tmp42, 0);
                }
              }
              v42 = check_connect(&came_from, &connectaddr, &group);
              if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                LOWORD(v43) = 20412;
                HIWORD(v43) = (unsigned int)"ATUS\":\"RESTART\"" >> 16;
                if ( v42 )
                  v43 = "Accepted";
                snprintf(tmp42, 0x1000u, "API mcast from %s - %s", connectaddr, v43);
                applog(7, tmp42, 0);
              }
            }
            while ( !v42 );
            v44 = came_from_siz;
            buf[v41] = 0;
            if ( v41 )
            {
              if ( buf[v41 - 1] == 10 )
                buf[--v41] = 0;
              getnameinfo((const struct sockaddr *)&came_from, v44, 0, 0, came_from_port, 0xAu, 1u);
              if ( opt_debug )
              {
LABEL_58:
                if ( use_syslog || opt_log_output || opt_log_level > 6 )
                {
                  LOWORD(v53) = 20756;
                  HIWORD(v53) = (unsigned int)"t join failed (%s)%s" >> 16;
                  snprintf(tmp42, 0x1000u, v53, v41, buf, connectaddr, came_from_port);
                  applog(7, tmp42, 0);
                }
                if ( expect_code_len < v41 && !memcmp(buf, expect_code, expect_code_len) )
                  goto LABEL_42;
                if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  LOWORD(v54) = 21060;
                  HIWORD(v54) = (unsigned int)" socket to client %s" >> 16;
                  v55 = *v54;
                  v56 = v54[1];
                  v57 = v54[2];
                  v58 = v54[3];
                  v54 += 4;
                  *(_DWORD *)tmp42 = v55;
                  *(_DWORD *)&tmp42[4] = v56;
                  *(_DWORD *)&tmp42[8] = v57;
                  *(_DWORD *)&tmp42[12] = v58;
                  v59 = v54[1];
                  v60 = v54[2];
                  v61 = v54[3];
                  *(_DWORD *)&tmp42[16] = *v54;
                  *(_DWORD *)&tmp42[20] = v59;
                  *(_DWORD *)&tmp42[24] = v60;
                  *(_WORD *)&tmp42[28] = v61;
                  applog(7, tmp42, 0);
                }
              }
              else if ( expect_code_len < v41 && !memcmp(buf, expect_code, expect_code_len) )
              {
LABEL_42:
                v45 = &buf[expect_code_len];
                v46 = strtol(&buf[expect_code_len], 0, 10);
                if ( (unsigned int)(v46 - 1) <= 0xFFFE )
                {
                  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                  {
                    LOWORD(v62) = 20848;
                    HIWORD(v62) = (unsigned int)"d (%s) (%d)" >> 16;
                    snprintf(tmp42, 0x1000u, v62, v45, v46);
                    applog(7, tmp42, 0);
                  }
                  if ( getaddrinfo(connectaddr, v45, &hints, &res) )
                  {
                    if ( use_syslog || opt_log_output || opt_log_level > 2 )
                    {
                      snprintf(tmp42, 0x1000u, "Invalid client address %s", connectaddr);
                      goto LABEL_79;
                    }
                  }
                  else
                  {
                    v63 = res;
                    client = res;
                    v64 = res;
                    if ( res )
                    {
                      while ( 1 )
                      {
                        v65 = socket(v63->ai_family, 2, 0);
                        if ( mcast_sock > 0 )
                          break;
                        v64 = v64->ai_next;
                        if ( !v64 )
                          break;
                        v63 = res;
                      }
                      fd = v65;
                      client = v64;
                    }
                    if ( fd == -1 )
                    {
                      freeaddrinfo(res);
                      if ( use_syslog || opt_log_output || opt_log_level > 2 )
                      {
                        LOWORD(v70) = 20908;
                        HIWORD(v70) = (unsigned int)" (%s) from [%s]:%s" >> 16;
                        snprintf(tmp42, 0x1000u, v70, connectaddr);
LABEL_79:
                        applog(3, tmp42, 0);
                      }
                    }
                    else
                    {
                      snprintf((char *)&grp, 0x400u, v90, opt_api_port, opt_api_mcast_des);
                      v66 = strlen((const char *)&grp);
                      v67 = sendto(fd, &grp, v66 + 1, 0, client->ai_addr, client->ai_addrlen);
                      freeaddrinfo(res);
                      if ( v67 < 0 )
                      {
                        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                        {
                          v68 = _errno_location();
                          v69 = strerror(*v68);
                          snprintf(tmp42, 0x1000u, "API mcast send reply failed (%s) (%d)", v69, fd);
                          applog(7, tmp42, 0);
                        }
                      }
                      else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                      {
                        snprintf(tmp42, 0x1000u, "API mcast send reply (%s) succeeded (%d) (%d)", &grp, v67, fd);
                        applog(7, tmp42, 0);
                      }
                      close(fd);
                    }
                  }
                }
                else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                {
                  LOWORD(v47) = 20800;
                  HIWORD(v47) = (unsigned int)"st expect_code" >> 16;
                  snprintf(tmp42, 0x1000u, v47, v45);
                  applog(7, tmp42, 0);
                }
              }
            }
            else
            {
              getnameinfo((const struct sockaddr *)&came_from, v44, 0, 0, came_from_port, 0xAu, 1u);
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
        ai_addr = v11->ai_addr;
        v31 = *(_DWORD *)&ai_addr->sa_data[6];
        ai_addr = (sockaddr *)((char *)ai_addr + 8);
        v32 = *(_DWORD *)&ai_addr->sa_data[2];
        v33 = *(_DWORD *)&ai_addr->sa_data[6];
        v34 = *(_DWORD *)&ai_addr->sa_data[10];
        grp.imr_multiaddr.s_addr = v31;
        grp.imr_interface.s_addr = v32;
        v103 = v33;
        v104 = v34;
        v105 = 0;
        if ( setsockopt(mcast_sock, 41, 20, &grp, 0x14u) >= 0 )
          goto LABEL_25;
      }
      if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
        goto die;
      v71 = _errno_location();
      v72 = strerror(*v71);
      LOWORD(v73) = 20532;
      LOWORD(v74) = 20620;
      HIWORD(v73) = (unsigned int)"pted" >> 16;
      HIWORD(v74) = (unsigned int)"t setsockopt SO_REUSEADDR failed (%s)%s" >> 16;
      snprintf(tmp42, 0x1000u, v74, v72, v73);
LABEL_14:
      applog(3, tmp42, 0);
      goto die;
    }
    v27 = _errno_location();
    v28 = strerror(*v27);
    if ( time(0) - v26 > 61 )
      break;
    cgsleep_ms(30000);
  }
  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    LOWORD(v48) = 20532;
    LOWORD(v49) = 20580;
    HIWORD(v48) = (unsigned int)"pted" >> 16;
    HIWORD(v49) = (unsigned int)"API mcast could not open socket" >> 16;
    snprintf(tmp42, 0x1000u, v49, opt_api_mcast_port, v28, v48);
    applog(3, tmp42, 0);
  }
die:
  close(mcast_sock);
}
