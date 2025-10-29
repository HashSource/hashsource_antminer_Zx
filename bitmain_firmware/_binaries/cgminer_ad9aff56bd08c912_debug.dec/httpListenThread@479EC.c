void *__fastcall httpListenThread(void *param)
{
  int v1; // r0
  int *v2; // r7
  int v3; // r0
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  const char *v9; // r11
  int v10; // r0
  void *v11; // r4
  int *v13; // r7
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int *v25; // r7
  int v26; // r0
  int v27; // r1
  int v28; // r2
  int v29; // r3
  int v30; // r0
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r1
  int v35; // r2
  int v36; // r3
  int *v37; // r7
  int v38; // r0
  int v39; // r1
  int v40; // r2
  int v41; // r3
  int v42; // r0
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r0
  int v47; // r1
  int v48; // r2
  int v49; // r3
  int v50; // r7
  int *v51; // r7
  int v52; // r0
  int v53; // r1
  int v54; // r2
  int v55; // r3
  int v56; // r0
  int v57; // r1
  int v58; // r2
  int v59; // r3
  int v60; // r1
  int v61; // r2
  int addr_len; // [sp+10h] [bp-102Ch] BYREF
  int v63; // [sp+14h] [bp-1028h] BYREF
  sockaddr_in service; // [sp+18h] [bp-1024h] BYREF
  sockaddr_in client_addr; // [sp+28h] [bp-1014h] BYREF
  char tmp42[4096]; // [sp+38h] [bp-1004h] BYREF

  sleep(0x1Eu);
  do
  {
    v1 = socket(2, 1, 6);
    listen_sockfd = v1;
    if ( v1 < 0 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        LOWORD(v13) = -20740;
        HIWORD(v13) = (unsigned int)" http data error" >> 16;
        v14 = *v13;
        v15 = v13[1];
        v16 = v13[2];
        v17 = v13[3];
        v13 += 4;
        *(_DWORD *)tmp42 = v14;
        *(_DWORD *)&tmp42[4] = v15;
        *(_DWORD *)&tmp42[8] = v16;
        *(_DWORD *)&tmp42[12] = v17;
        v18 = *v13;
        v19 = v13[1];
        v20 = v13[2];
        v21 = v13[3];
        v13 += 4;
        *(_DWORD *)&tmp42[16] = v18;
        *(_DWORD *)&tmp42[20] = v19;
        *(_DWORD *)&tmp42[24] = v20;
        *(_DWORD *)&tmp42[28] = v21;
        v22 = v13[1];
        v23 = v13[2];
        v24 = v13[3];
        *(_DWORD *)&tmp42[32] = *v13;
        *(_DWORD *)&tmp42[36] = v22;
        *(_DWORD *)&tmp42[40] = v23;
        *(_WORD *)&tmp42[44] = v24;
        tmp42[46] = BYTE2(v24);
        applog(5, tmp42, 0);
      }
      sleep(0xAu);
    }
    else
    {
      v63 = 1;
      if ( setsockopt(v1, 1, 2, &v63, 4u) < 0 && (use_syslog || opt_log_output || opt_log_level > 3) )
      {
        LOWORD(v37) = -20692;
        HIWORD(v37) = (unsigned int)"socket creating failed, try again after 10s..." >> 16;
        v38 = *v37;
        v39 = v37[1];
        v40 = v37[2];
        v41 = v37[3];
        v37 += 4;
        *(_DWORD *)tmp42 = v38;
        *(_DWORD *)&tmp42[4] = v39;
        *(_DWORD *)&tmp42[8] = v40;
        *(_DWORD *)&tmp42[12] = v41;
        v42 = *v37;
        v43 = v37[1];
        v44 = v37[2];
        v45 = v37[3];
        v37 += 4;
        *(_DWORD *)&tmp42[16] = v42;
        *(_DWORD *)&tmp42[20] = v43;
        *(_DWORD *)&tmp42[24] = v44;
        *(_DWORD *)&tmp42[28] = v45;
        v46 = *v37;
        v47 = v37[1];
        v48 = v37[2];
        v49 = v37[3];
        v50 = v37[4];
        *(_DWORD *)&tmp42[32] = v46;
        *(_DWORD *)&tmp42[36] = v47;
        *(_DWORD *)&tmp42[40] = v48;
        *(_DWORD *)&tmp42[44] = v49;
        *(_WORD *)&tmp42[48] = v50;
        tmp42[50] = BYTE2(v50);
        applog(4, tmp42, 0);
      }
      memset(&service.sin_addr, 0, 12);
      *(_DWORD *)&service.sin_family = -1407778814;
      if ( bind(listen_sockfd, (const struct sockaddr *)&service, 0x10u) < 0 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          LOWORD(v25) = -20640;
          HIWORD(v25) = (unsigned int)"***************setsockopt(SO_REUSEADDR) failed" >> 16;
          v26 = *v25;
          v27 = v25[1];
          v28 = v25[2];
          v29 = v25[3];
          v25 += 4;
          *(_DWORD *)tmp42 = v26;
          *(_DWORD *)&tmp42[4] = v27;
          *(_DWORD *)&tmp42[8] = v28;
          *(_DWORD *)&tmp42[12] = v29;
          v30 = *v25;
          v31 = v25[1];
          v32 = v25[2];
          v33 = v25[3];
          v25 += 4;
          *(_DWORD *)&tmp42[16] = v30;
          *(_DWORD *)&tmp42[20] = v31;
          *(_DWORD *)&tmp42[24] = v32;
          *(_DWORD *)&tmp42[28] = v33;
          v34 = v25[1];
          v35 = v25[2];
          v36 = v25[3];
          *(_DWORD *)&tmp42[32] = *v25;
          *(_DWORD *)&tmp42[36] = v34;
          *(_DWORD *)&tmp42[40] = v35;
          *(_WORD *)&tmp42[44] = v36;
          applog(5, tmp42, 0);
        }
      }
      else
      {
        if ( listen(listen_sockfd, 100) >= 0 )
          break;
        if ( use_syslog || opt_log_output || opt_log_level > 4 )
        {
          LOWORD(v51) = -20592;
          HIWORD(v51) = (unsigned int)"http port bind failed! try again after 10s..." >> 16;
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
          v51 += 4;
          *(_DWORD *)&tmp42[16] = v56;
          *(_DWORD *)&tmp42[20] = v57;
          *(_DWORD *)&tmp42[24] = v58;
          *(_DWORD *)&tmp42[28] = v59;
          v60 = v51[1];
          v61 = v51[2];
          *(_DWORD *)&tmp42[32] = *v51;
          *(_DWORD *)&tmp42[36] = v60;
          *(_WORD *)&tmp42[40] = v61;
          tmp42[42] = BYTE2(v61);
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
    LOWORD(v2) = -20548;
    HIWORD(v2) = (unsigned int)"." >> 16;
    v3 = *v2;
    v4 = v2[1];
    v5 = v2[2];
    v6 = v2[3];
    v2 += 4;
    *(_DWORD *)tmp42 = v3;
    *(_DWORD *)&tmp42[4] = v4;
    *(_DWORD *)&tmp42[8] = v5;
    *(_DWORD *)&tmp42[12] = v6;
    v7 = v2[1];
    v8 = v2[2];
    *(_DWORD *)&tmp42[16] = *v2;
    *(_DWORD *)&tmp42[20] = v7;
    tmp42[24] = v8;
    applog(5, tmp42, 0);
  }
  if ( !ExitServer )
  {
    LOWORD(v9) = -20520;
    while ( 1 )
    {
      while ( 1 )
      {
        usleep(0x2710u);
        addr_len = 16;
        v10 = accept(listen_sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len);
        v11 = (void *)v10;
        if ( v10 != -1 )
          break;
        if ( ExitServer )
          goto LABEL_21;
      }
      if ( ExitServer )
        break;
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        HIWORD(v9) = (unsigned int)"again after 10s..." >> 16;
        snprintf(tmp42, 0x1000u, v9, v10);
        applog(7, tmp42, 0);
      }
      statusServiceThread(v11);
      if ( ExitServer )
        goto LABEL_21;
    }
    close(v10);
  }
LABEL_21:
  close(listen_sockfd);
  listen_sockfd = -1;
  return 0;
}
