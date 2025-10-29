int sub_30EEC()
{
  struct addrinfo *v0; // r4
  struct addrinfo *i; // r3
  int v2; // r0
  int v3; // r9
  time_t v4; // r7
  int ai_family; // r3
  const char *v6; // r7
  size_t v7; // r0
  size_t v8; // r4
  int v9; // r5
  ssize_t v10; // r4
  _BOOL4 v11; // r12
  const char *v12; // r2
  int *v13; // r0
  char *v14; // r8
  struct addrinfo *v15; // r0
  int *v16; // r0
  char *v17; // r0
  int *v19; // r0
  char *v20; // r0
  const char *v21; // r4
  int v22; // r0
  struct addrinfo *v23; // r4
  int v24; // r0
  int v25; // r12
  size_t v26; // r0
  ssize_t v27; // r4
  int *v28; // r0
  char *v29; // r0
  int *v30; // r0
  char *v31; // r0
  int v32; // r0
  int v33; // r1
  int v34; // r2
  int v35; // r3
  _BOOL4 v36; // [sp+14h] [bp-18F0h]
  int v37; // [sp+14h] [bp-18F0h]
  size_t n; // [sp+18h] [bp-18ECh]
  char *v39; // [sp+1Ch] [bp-18E8h]
  int fd; // [sp+20h] [bp-18E4h]
  char v41; // [sp+2Bh] [bp-18D9h] BYREF
  socklen_t addr_len; // [sp+2Ch] [bp-18D8h] BYREF
  const char *v43; // [sp+30h] [bp-18D4h] BYREF
  struct addrinfo *pai; // [sp+34h] [bp-18D0h] BYREF
  int optval; // [sp+38h] [bp-18CCh] BYREF
  char v46[12]; // [sp+3Ch] [bp-18C8h] BYREF
  char s[12]; // [sp+48h] [bp-18BCh] BYREF
  char serv[12]; // [sp+54h] [bp-18B0h] BYREF
  struct addrinfo req; // [sp+60h] [bp-18A4h] BYREF
  struct sockaddr v50[8]; // [sp+80h] [bp-1884h] BYREF
  char v51[1024]; // [sp+100h] [bp-1804h] BYREF
  int v52; // [sp+500h] [bp-1404h] BYREF
  int v53; // [sp+504h] [bp-1400h]
  int v54; // [sp+508h] [bp-13FCh]
  int v55; // [sp+50Ch] [bp-13F8h]
  int v56; // [sp+510h] [bp-13F4h]
  char v57[4100]; // [sp+900h] [bp-1004h] BYREF

  strcpy(v46, "cgminer-");
  sprintf(s, "%d", dword_72CFC);
  memset(&req, 0, sizeof(req));
  if ( getaddrinfo(off_72D08[0], s, &req, &pai) )
  {
    strcpy(v57, "Invalid API Multicast Address");
    sub_385C8(3, v57, 1);
    sub_16BE0(1);
  }
  v0 = pai;
  if ( !pai )
  {
    v15 = 0;
LABEL_43:
    freeaddrinfo(v15);
    strcpy(v57, "API mcast could not open socket");
    sub_385C8(3, v57, 1);
    sub_16BE0(1);
  }
  for ( i = pai; ; i = pai )
  {
    v2 = socket(i->ai_family, 2, 0);
    if ( v2 > 0 )
    {
      v3 = v2;
      goto LABEL_8;
    }
    v0 = v0->ai_next;
    if ( !v0 )
      break;
  }
  v3 = v2;
  if ( v2 == -1 )
  {
    v15 = pai;
    goto LABEL_43;
  }
LABEL_8:
  optval = 1;
  if ( setsockopt(v3, 1, 2, &optval, 4u) < 0 )
  {
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
      return close(v3);
    v16 = _errno_location();
    v17 = strerror(*v16);
    snprintf(
      v57,
      0x1000u,
      "API mcast setsockopt SO_REUSEADDR failed (%s)%s",
      v17,
      " - API multicast listener will not be available");
LABEL_48:
    sub_385C8(3, v57, 0);
    return close(v3);
  }
  v4 = time(0);
  while ( 1 )
  {
    if ( bind(v3, v0->ai_addr, v0->ai_addrlen) >= 0 )
    {
      ai_family = v0->ai_family;
      if ( ai_family == 2 )
      {
        v52 = 0;
        v53 = 0;
        v52 = *(_DWORD *)&v0->ai_addr->sa_data[2];
        if ( setsockopt(v3, 0, 35, &v52, 8u) < 0 )
        {
LABEL_97:
          if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 2 )
            return close(v3);
          v30 = _errno_location();
          v31 = strerror(*v30);
          snprintf(v57, 0x1000u, "API mcast join failed (%s)%s", v31, " - API multicast listener will not be available");
          goto LABEL_48;
        }
      }
      else if ( ai_family == 10 )
      {
        v32 = *(_DWORD *)&v0->ai_addr->sa_data[6];
        v33 = *(_DWORD *)&v0->ai_addr->sa_data[10];
        v34 = *(_DWORD *)&v0->ai_addr[1].sa_family;
        v35 = *(_DWORD *)&v0->ai_addr[1].sa_data[2];
        v56 = 0;
        v52 = v32;
        v53 = v33;
        v54 = v34;
        v55 = v35;
        if ( setsockopt(v3, 41, 20, &v52, 0x14u) < 0 )
          goto LABEL_97;
      }
      freeaddrinfo(pai);
      v6 = off_72D04[0];
      v7 = strlen(off_72D04[0]);
      v8 = v7 + 10;
      n = v7 + 9;
      v39 = (char *)malloc(v7 + 10);
      if ( !v39 )
      {
        strcpy(v57, "Failed to malloc mcast expect_code");
        sub_385C8(3, v57, 1);
        sub_16BE0(1);
      }
      v9 = 0;
      snprintf(v39, v8, "%s%s-", v46, v6);
      fd = -1;
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              do
              {
                while ( 1 )
                {
                  ++v9;
                  sub_2A884();
                  addr_len = 128;
                  v10 = recvfrom(v3, v51, 0x3FFu, 0, v50, &addr_len);
                  if ( v10 >= 0 )
                    break;
                  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
                  {
                    v19 = _errno_location();
                    v20 = strerror(*v19);
                    snprintf(v57, 0x1000u, "API mcast failed count=%d (%s) (%d)", v9, v20, v3);
                    sub_385C8(7, v57, 0);
                  }
                }
                v11 = sub_30858(v50, &v43, &v41);
                if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
                {
                  v12 = "Ignored";
                  v36 = v11;
                  if ( v11 )
                    v12 = "Accepted";
                  snprintf(v57, 0x1000u, "API mcast from %s - %s", v43, v12);
                  sub_385C8(7, v57, 0);
                  v11 = v36;
                }
              }
              while ( !v11 );
              v51[v10] = 0;
              if ( v10 && v50[7].sa_data[v10 + 13] == 10 )
                v51[--v10] = 0;
              getnameinfo(v50, addr_len, 0, 0, serv, 0xAu, 1u);
              if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
              {
                snprintf(v57, 0x1000u, "API mcast request rep=%d (%s) from [%s]:%s", v10, v51, v43, serv);
                sub_385C8(7, v57, 0);
              }
              if ( n < v10 && !memcmp(v51, v39, n) )
                break;
              if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
              {
                strcpy(v57, "API mcast request was no good");
                sub_385C8(7, v57, 0);
              }
            }
            v21 = &v51[n];
            v22 = strtol(&v51[n], 0, 10);
            if ( (unsigned int)(v22 - 1) <= 0xFFFE )
              break;
            if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
            {
              snprintf(v57, 0x1000u, "API mcast request ignored - invalid port (%s)", v21);
              sub_385C8(7, v57, 0);
            }
          }
          if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            snprintf(v57, 0x1000u, "API mcast request OK port %s=%d", v21, v22);
            sub_385C8(7, v57, 0);
          }
          if ( !getaddrinfo(v43, v21, &req, &pai) )
            break;
          if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
          {
            snprintf(v57, 0x1000u, "Invalid client address %s", v43);
            goto LABEL_71;
          }
        }
        v23 = pai;
        if ( pai && (v24 = socket(pai->ai_family, 2, 0), v25 = -6348, fd = v24, v3 <= 0) )
        {
          while ( 1 )
          {
            v23 = v23->ai_next;
            if ( !v23 )
              break;
            v37 = v25;
            v24 = socket(*(_DWORD *)(*(_DWORD *)&v57[v25 + 4096] + 4), 2, 0);
            v25 = v37;
          }
          fd = v24;
          if ( v24 == -1 )
            goto LABEL_85;
LABEL_75:
          snprintf((char *)&v52, 0x400u, "cgm-FTW-%d-%s", dword_72D10, (const char *)off_72D00);
          v26 = strlen((const char *)&v52);
          v27 = sendto(fd, &v52, v26 + 1, 0, v23->ai_addr, v23->ai_addrlen);
          freeaddrinfo(pai);
          if ( v27 < 0 )
          {
            if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
            {
              v28 = _errno_location();
              v29 = strerror(*v28);
              snprintf(v57, 0x1000u, "API mcast send reply failed (%s) (%d)", v29, fd);
              sub_385C8(7, v57, 0);
            }
          }
          else if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            snprintf(v57, 0x1000u, "API mcast send reply (%s) succeeded (%d) (%d)", (const char *)&v52, v27, fd);
            sub_385C8(7, v57, 0);
          }
          close(fd);
        }
        else
        {
          if ( fd != -1 )
            goto LABEL_75;
LABEL_85:
          freeaddrinfo(pai);
          if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
          {
            snprintf(v57, 0x1000u, "API mcast could not open socket to client %s", v43);
LABEL_71:
            sub_385C8(3, v57, 0);
          }
        }
      }
    }
    v13 = _errno_location();
    v14 = strerror(*v13);
    if ( time(0) - v4 > 61 )
      break;
    sub_2A884();
  }
  if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
  {
    snprintf(
      v57,
      0x1000u,
      "API mcast bind to port %d failed (%s)%s",
      dword_72CFC,
      v14,
      " - API multicast listener will not be available");
    sub_385C8(3, v57, 0);
  }
  return close(v3);
}
