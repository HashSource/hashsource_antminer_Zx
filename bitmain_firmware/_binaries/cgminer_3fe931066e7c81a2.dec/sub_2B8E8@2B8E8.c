int *__fastcall sub_2B8E8(_DWORD *a1)
{
  int i; // r0
  int v3; // r4
  int v4; // r3
  int v5; // r3
  int v6; // r0
  bool v7; // zf
  int v8; // r0
  struct addrinfo *v9; // r4
  char *v10; // r12
  int v11; // r0
  int v12; // r1
  int v13; // r2
  __int16 v14; // r3
  int v15; // r0
  int v16; // r7
  int v17; // r0
  int *v18; // r10
  unsigned int v19; // lr
  int *v20; // r5
  int v21; // r0
  char *v22; // r3
  int v23; // r0
  const char *v24; // r3
  int v25; // r2
  size_t v26; // r0
  void *v27; // r0
  char *v28; // r0
  int v29; // r3
  int v30; // r2
  int v31; // r6
  int v32; // r3
  int v33; // r3
  const char *v35; // r3
  int *v36; // r0
  int *v37; // r7
  _DWORD *v38; // r6
  _DWORD *v39; // r0
  char *v40; // r4
  char *v41; // r0
  ssize_t v42; // r0
  const char *v43; // r10
  signed int v44; // r0
  size_t v45; // r5
  __int16 v46; // r0
  char *v47; // r12
  ssize_t v48; // r4
  char v49; // r0
  ssize_t v50; // r5
  int v51; // r0
  int v52; // r0
  int v53; // r2
  size_t v54; // r0
  char *v55; // r0
  int *v56; // r0
  int *v57; // r0
  int *v58; // r0
  int *v59; // r0
  struct timeval *timeout; // [sp+0h] [bp-3374h]
  int *v61; // [sp+18h] [bp-335Ch]
  char *name; // [sp+1Ch] [bp-3358h]
  char *service; // [sp+20h] [bp-3354h]
  int v64; // [sp+24h] [bp-3350h]
  pthread_mutex_t *mutex; // [sp+2Ch] [bp-3348h]
  int v66; // [sp+30h] [bp-3344h]
  struct addrinfo *pai; // [sp+38h] [bp-333Ch] BYREF
  int v68; // [sp+3Ch] [bp-3338h] BYREF
  socklen_t optlen; // [sp+40h] [bp-3334h] BYREF
  int optval; // [sp+44h] [bp-3330h] BYREF
  struct timeval v71; // [sp+48h] [bp-332Ch] BYREF
  addrinfo req; // [sp+50h] [bp-3324h] BYREF
  char v73[92]; // [sp+70h] [bp-3304h] BYREF
  char v74[160]; // [sp+CCh] [bp-32A8h] BYREF
  fd_set writefds; // [sp+16Ch] [bp-3208h] BYREF
  char s[4048]; // [sp+370h] [bp-3004h] BYREF
  char v77[8196]; // [sp+1370h] [bp-2004h] BYREF

  v61 = 0;
  v64 = 0;
  mutex = (pthread_mutex_t *)(a1 + 182);
  v66 = 0;
  for ( i = pthread_mutex_lock((pthread_mutex_t *)(a1 + 182)); ; i = pthread_mutex_lock(mutex) )
  {
    if ( i )
      sub_B708("setup_stratum_socket", 3167);
    v6 = a1[153];
    *((_BYTE *)a1 + 665) = 0;
    if ( v6 )
      close(v6);
    a1[153] = 0;
    if ( pthread_mutex_unlock(mutex) )
    {
      v58 = _errno_location();
      snprintf(
        s,
        0x1000u,
        "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
        *v58,
        "util.c",
        "setup_stratum_socket",
        3172);
      sub_38730(3, s, 1);
      sub_16CA8(1);
    }
    off_75ED8();
    v7 = a1[54] == 0;
    req.ai_family = 0;
    req.ai_flags = 0;
    memset(&req.ai_protocol, 0, 20);
    req.ai_socktype = 1;
    if ( !v7
      || (v28 = (char *)dword_78B78) != 0
      && (a1[54] = dword_78B78, sub_2AB54(v28, (char **)a1 + 157, (char **)a1 + 158), v29 = a1[54], a1[53] = 3, v29) )
    {
      name = (char *)a1[157];
      service = (char *)a1[158];
      v8 = getaddrinfo(name, service, &req, &pai);
    }
    else
    {
      name = (char *)a1[156];
      service = (char *)a1[152];
      v8 = getaddrinfo(name, service, &req, &pai);
    }
    if ( v8 )
    {
      if ( *((_BYTE *)a1 + 131) )
      {
        if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
        {
          snprintf(s, 0x1000u, "Failed to getaddrinfo for %s:%s", name, service);
          sub_38730(7, s, 0);
        }
      }
      else
      {
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
        {
          snprintf(s, 0x1000u, "Failed to resolve (?wrong URL) %s:%s", name, service);
          sub_38730(4, s, 0);
        }
        *((_BYTE *)a1 + 131) = 1;
      }
      goto LABEL_8;
    }
    v9 = pai;
    if ( !pai )
    {
LABEL_60:
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        snprintf(s, 0x1000u, "Failed to connect to stratum on %s:%s", name, service);
        sub_38730(7, s, 0);
      }
      freeaddrinfo(pai);
      goto LABEL_8;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        v15 = socket(v9->ai_family, v9->ai_socktype, v9->ai_protocol);
        v16 = v15;
        if ( v15 != -1 )
          break;
        if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
        {
          v10 = s;
          v11 = *(_DWORD *)"Failed socket";
          v12 = *(_DWORD *)"ed socket";
          v13 = *(_DWORD *)"ocket";
          v14 = *(_WORD *)"t";
          goto LABEL_38;
        }
LABEL_39:
        v9 = v9->ai_next;
        if ( !v9 )
          goto LABEL_60;
      }
      v17 = fcntl(v15, 3, 0);
      fcntl(v16, 4, v17 | 0x800);
      if ( connect(v16, v9->ai_addr, v9->ai_addrlen) != -1 )
        break;
      v71.tv_sec = 1;
      v71.tv_usec = 0;
      v18 = _errno_location();
      if ( *v18 == 115 )
      {
        v19 = 0;
        v20 = &writefds.__fds_bits[v16 / 32];
        while ( 1 )
        {
          if ( v19 > 0x1F )
          {
            *v20 |= 1 << (v16 % 32);
            v21 = select(v16 + 1, 0, &writefds, 0, &v71);
            if ( v21 > 0 )
            {
              if ( ((*v20 >> (v16 % 32)) & 1) != 0 )
              {
                optlen = 4;
                if ( !getsockopt(v16, 1, 4, &optval, &optlen) && !optval )
                {
                  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
                  {
                    strcpy(s, "Succeeded delayed connect");
                    sub_38730(7, s, 0);
                  }
                  goto LABEL_71;
                }
              }
LABEL_47:
              close(v16);
              if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
              {
                qmemcpy(s, "Select timeout/f", 16);
                v10 = &s[16];
                v11 = *(_DWORD *)"ailed connect";
                v12 = *(_DWORD *)"d connect";
                v13 = *(_DWORD *)"nnect";
                v14 = *(_WORD *)"t";
LABEL_38:
                *(_DWORD *)v10 = v11;
                *((_DWORD *)v10 + 1) = v12;
                *((_DWORD *)v10 + 2) = v13;
                *((_WORD *)v10 + 6) = v14;
                sub_38730(7, s, 0);
              }
              goto LABEL_39;
            }
            v19 = 0;
            if ( !v21 || *v18 != 4 )
              goto LABEL_47;
          }
          v22 = &v77[4 * v19++ + 0x2000];
          *((_DWORD *)v22 - 3201) = 0;
        }
      }
      close(v16);
      if ( !byte_78E09 || !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
        goto LABEL_39;
      strcpy(s, "Failed sock connect");
      sub_38730(7, s, 0);
      v9 = v9->ai_next;
      if ( !v9 )
        goto LABEL_60;
    }
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
    {
      strcpy(s, "Succeeded immediate connect");
      sub_38730(4, s, 0);
    }
LABEL_71:
    sub_28B9C(v16);
    freeaddrinfo(pai);
    if ( a1[54] )
    {
      switch ( a1[53] )
      {
        case 0:
          if ( !sub_28BEC((const char **)a1, v16, 0) )
            break;
          if ( !a1[154] )
            goto LABEL_108;
          goto LABEL_84;
        case 1:
          if ( !sub_28BEC((const char **)a1, v16, 1) )
            break;
          goto LABEL_83;
        case 2:
          if ( !sub_28FC8((const char **)a1, v16, 0) )
            break;
          goto LABEL_83;
        case 3:
        case 5:
          LOBYTE(writefds.__fds_bits[0]) = 5;
          *(_WORD *)((char *)writefds.__fds_bits + 1) = 1;
          if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
          {
            snprintf(
              s,
              0x1000u,
              "Attempting to negotiate with %s:%s SOCKS5 proxy",
              (const char *)a1[157],
              (const char *)a1[158]);
            sub_38730(7, s, 0);
          }
          send(v16, &writefds, 3u, 0);
          if ( sub_28BC4(v16) != 5 )
            goto LABEL_100;
          v42 = sub_28BC4(v16);
          if ( v42 != BYTE2(writefds.__fds_bits[0]) )
            goto LABEL_100;
          v43 = (const char *)a1[156];
          writefds.__fds_bits[0] = 50331909;
          v44 = strlen(v43);
          v45 = v44 >= 255 ? 255 : v44;
          LOBYTE(writefds.__fds_bits[1]) = v45;
          memcpy((char *)&writefds.__fds_bits[1] + 1, v43, v45);
          v46 = strtol((const char *)a1[152], 0, 10);
          v47 = (char *)&writefds.__fds_bits[1] + v45;
          v47[2] = v46;
          v47[1] = HIBYTE(v46);
          send(v16, &writefds, v45 + 7, 0);
          if ( sub_28BC4(v16) != 5 )
            goto LABEL_100;
          v48 = sub_28BC4(v16);
          if ( v48 )
            goto LABEL_100;
          sub_28BC4(v16);
          v49 = sub_28BC4(v16);
          if ( v49 == 1 )
          {
            sub_28BC4(v16);
            sub_28BC4(v16);
            sub_28BC4(v16);
            sub_28BC4(v16);
LABEL_177:
            sub_28BC4(v16);
            sub_28BC4(v16);
            if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
            {
              snprintf(
                s,
                0x1000u,
                "Success negotiating with %s:%s SOCKS5 proxy",
                (const char *)a1[157],
                (const char *)a1[158]);
              sub_38730(7, s, 0);
            }
            goto LABEL_83;
          }
          if ( v49 == 3 )
          {
            v50 = sub_28BC4(v16);
            if ( v50 > 0 )
            {
              do
              {
                ++v48;
                sub_28BC4(v16);
              }
              while ( v48 != v50 );
            }
            goto LABEL_177;
          }
LABEL_100:
          if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
          {
            snprintf(s, 0x1000u, "Bad response from %s:%s SOCKS5 server", (const char *)a1[157], (const char *)a1[158]);
            sub_38730(4, s, 0);
          }
          break;
        case 4:
          if ( sub_28FC8((const char **)a1, v16, 1) )
            goto LABEL_83;
          break;
        default:
          if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
          {
            snprintf(s, 0x1000u, "Unsupported proxy type for %s:%s", (const char *)a1[157], (const char *)a1[158]);
            sub_38730(4, s, 0);
          }
          break;
      }
LABEL_8:
      v3 = 0;
      goto LABEL_9;
    }
LABEL_83:
    if ( !a1[154] )
    {
LABEL_108:
      v27 = calloc(0x2000u, 1u);
      a1[154] = v27;
      if ( !v27 )
      {
        snprintf(s, 0x1000u, "Failed to calloc pool sockbuf in %s %s():%d", "util.c", "setup_stratum_socket", 3311);
        sub_38730(3, s, 1);
        sub_16CA8(1);
      }
      a1[155] = 0x2000;
    }
LABEL_84:
    a1[153] = v16;
    v68 = 1;
    optlen = 45;
    optval = 30;
    v23 = fcntl(v16, 3, 0);
    fcntl(v16, 4, v23 | 0x800);
    setsockopt(v16, 1, 9, &v68, 4u);
    if ( !byte_7BD20 )
      fcntl(v16, 2, 1);
    setsockopt(v16, 6, 1, &v68, 4u);
    setsockopt(v16, 6, 6, &v68, 4u);
    setsockopt(v16, 6, 4, &optlen, 4u);
    setsockopt(v16, 6, 5, &optval, 4u);
    if ( v66 )
    {
      sub_295A8((int)a1);
      v30 = dword_7B0F8++;
      sprintf(v77, "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": []}", v30);
    }
    else
    {
      v24 = (const char *)a1[165];
      v25 = dword_7B0F8;
      if ( v24 )
      {
        ++dword_7B0F8;
        sprintf(
          v77,
          "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"cgminer/4.9.0\", \"%s\"]}",
          v25,
          v24);
      }
      else
      {
        v35 = (const char *)a1[156];
        timeout = (struct timeval *)a1[152];
        ++dword_7B0F8;
        sprintf(
          v77,
          "{\"id\":%d, \"method\":\"mining.subscribe\", \"params\":[\"cgminer/4.9.0\", null, \"%s\", \"%s\"]}",
          v25,
          v35,
          (const char *)timeout);
      }
    }
    v26 = strlen(v77);
    if ( sub_29404((int)a1, v77, v26) )
    {
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        v3 = 1;
        strcpy(s, "Failed to send s in initiate_stratum");
        sub_38730(7, s, 0);
        goto LABEL_9;
      }
LABEL_121:
      v3 = 1;
      goto LABEL_9;
    }
    if ( !sub_28AFC((int)a1, 60) )
    {
      if ( !byte_78E09 || !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
        goto LABEL_121;
      v3 = 1;
      strcpy(s, "Timed out waiting for response in initiate_stratum");
      sub_38730(7, s, 0);
      goto LABEL_9;
    }
    v36 = (int *)sub_2B040((int)a1);
    v37 = v36;
    if ( !v36 )
    {
      v3 = 1;
      goto LABEL_9;
    }
    v61 = sub_59230(v36, 0, v73);
    free(v37);
    if ( !v61 )
    {
      if ( !byte_78E09 )
      {
        v66 = 1;
        v3 = 1;
        goto LABEL_9;
      }
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
      {
        v66 = 1;
        v3 = 1;
        goto LABEL_9;
      }
      v3 = 1;
      snprintf(s, 0x1000u, "JSON decode failed(%d): %s", *(_DWORD *)v73, v74);
      goto LABEL_204;
    }
    v38 = (_DWORD *)sub_59E20(v61, "result");
    v39 = (_DWORD *)sub_59E20(v61, "error");
    if ( !v38 || *v38 == 7 )
    {
      if ( v39 )
      {
LABEL_150:
        v40 = (char *)sub_57854(v39, 3);
      }
      else
      {
        v40 = (char *)malloc(0x11u);
        if ( v40 )
          strcpy(v40, "(unknown reason)");
      }
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        snprintf(s, 0x1000u, "JSON-RPC decode failed: %s", v40);
        sub_38730(7, s, 0);
      }
      v41 = v40;
      v3 = 1;
      free(v41);
      v66 = 1;
      goto LABEL_9;
    }
    if ( v39 && *v39 != 7 )
      goto LABEL_150;
    v51 = sub_299AC((int)a1, v38, 1u);
    if ( v51 )
      break;
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      v3 = 1;
      snprintf(s, 0x1000u, "%s: Failed to get parse extranonce.", "initiate_stratum");
LABEL_204:
      sub_38730(7, s, 0);
      v66 = 1;
      goto LABEL_9;
    }
    v3 = 1;
    v66 = 1;
LABEL_9:
    if ( (v66 & (v64 ^ 1)) == 0 )
    {
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        strcpy(s, "Initiate stratum failed");
        sub_38730(7, s, 0);
      }
      if ( v3 )
      {
        sub_2AEE0((int)a1);
        if ( v61 )
          goto LABEL_133;
      }
      else if ( v61 )
      {
LABEL_133:
        v31 = 0;
        goto LABEL_134;
      }
      return v61;
    }
    if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
      sub_B708("initiate_stratum", 3608);
    if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(a1 + 67)) )
    {
      v56 = _errno_location();
      snprintf(s, 0x1000u, "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d", *v56, "util.c", "initiate_stratum", 3608);
      sub_38730(3, s, 1);
      sub_16CA8(1);
    }
    free((void *)a1[165]);
    free((void *)a1[159]);
    a1[159] = 0;
    a1[165] = 0;
    if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 67)) )
    {
      v59 = _errno_location();
      snprintf(
        s,
        0x1000u,
        "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
        *v59,
        "util.c",
        "initiate_stratum",
        3612);
      sub_38730(3, s, 1);
      sub_16CA8(1);
    }
    if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 61)) )
    {
      v57 = _errno_location();
      snprintf(
        s,
        0x1000u,
        "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
        *v57,
        "util.c",
        "initiate_stratum",
        3612);
      sub_38730(3, s, 1);
      sub_16CA8(1);
    }
    off_75ED8();
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      strcpy(s, "Failed to resume stratum, trying afresh");
      sub_38730(7, s, 0);
    }
    if ( v61 )
    {
      v4 = v61[1];
      if ( v4 != -1 )
      {
        v5 = v4 - 1;
        v61[1] = v5;
        if ( !v5 )
          sub_5A3E4((void **)v61);
      }
    }
    v64 = 1;
  }
  v31 = v51;
  if ( !a1[150] )
    a1[150] = a1[156];
  v52 = (unsigned __int8)byte_7B380;
  *((_BYTE *)a1 + 665) = 1;
  *((_QWORD *)a1 + 230) = 0x3FF0000000000000LL;
  if ( v52 && byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(
      s,
      0x1000u,
      "Pool %d confirmed mining.subscribe with extranonce1 %s extran2size %d",
      *a1,
      (const char *)a1[159],
      a1[164]);
    sub_38730(7, s, 0);
  }
  if ( *((_BYTE *)a1 + 604) )
  {
    v53 = dword_7B0F8++;
    sprintf(v77, "{\"id\": %d, \"method\": \"mining.extranonce.subscribe\", \"params\": []}", v53);
    v54 = strlen(v77);
    sub_2B5C8((int)a1, v77, v54);
    v55 = sub_2B040((int)a1);
    if ( v55 )
    {
      free(v55);
    }
    else if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
    {
      strcpy(s, "recv mining.extranonce.subscribe failed\n");
      sub_38730(3, s, 0);
    }
  }
LABEL_134:
  v32 = v61[1];
  if ( v32 != -1 )
  {
    v33 = v32 - 1;
    v61[1] = v33;
    if ( !v33 )
      sub_5A3E4((void **)v61);
  }
  return (int *)v31;
}
