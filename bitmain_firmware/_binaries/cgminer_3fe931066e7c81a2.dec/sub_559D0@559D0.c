int __fastcall sub_559D0(int a1)
{
  char *v2; // r5
  int v3; // r4
  ssize_t v4; // r3
  char v5; // r3
  char *v6; // r12
  char *v7; // r1
  const char *v9; // lr
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  _DWORD *v14; // lr
  int v15; // r1
  int v16; // r2
  int v17; // r3
  signed int v18; // r8
  int v19; // r5
  int v20; // r5
  int v21; // r5
  int v22; // r5
  int v23; // r5
  int v24; // r0
  unsigned int v25; // r5
  size_t v26; // r0
  ssize_t v27; // r0
  int v28; // r5
  ssize_t v29; // r12
  ssize_t v30; // [sp+Ch] [bp-7030h]
  char v31; // [sp+10h] [bp-702Ch] BYREF
  char v32[2]; // [sp+11h] [bp-702Bh] BYREF
  socklen_t addr_len; // [sp+14h] [bp-7028h] BYREF
  char needle[3]; // [sp+18h] [bp-7024h] BYREF
  char v35[5]; // [sp+1Bh] [bp-7021h] BYREF
  _DWORD optval[2]; // [sp+20h] [bp-701Ch] BYREF
  struct sockaddr addr; // [sp+28h] [bp-7014h] BYREF
  char s[4096]; // [sp+38h] [bp-7004h] BYREF
  char v39[4040]; // [sp+1038h] [bp-6004h] BYREF
  char v40[10240]; // [sp+2038h] [bp-5004h] BYREF
  _DWORD v41[11]; // [sp+4838h] [bp-2804h] BYREF
  int v42; // [sp+4864h] [bp-27D8h] BYREF

  optval[0] = 3;
  optval[1] = 0;
  memset(s, 0, sizeof(s));
  addr_len = 0;
  v31 = 13;
  needle[0] = 13;
  v2 = v40;
  needle[2] = 13;
  v3 = 0;
  strcpy(v32, "\n");
  needle[1] = 10;
  strcpy(v35, "\n");
  memset(v40, 0, sizeof(v40));
  do
  {
    if ( byte_7ACB8 )
      goto LABEL_10;
    v4 = recvfrom(a1, v2, 10239 - v3, 0, &addr, &addr_len);
    v3 += v4;
    if ( v4 <= 0 )
    {
      close(a1);
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        strcpy((char *)v41, ":statusServiceThread recvfrom<=0");
        sub_38730(7, (const char *)v41, 0);
      }
      return 0;
    }
    v2 = &v40[v3];
    if ( v3 > 10238 )
    {
      close(a1);
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        strcpy((char *)v41, "BUFSIZE is too small!");
        sub_38730(7, (const char *)v41, 0);
        return 0;
      }
      return 0;
    }
  }
  while ( !strstr(v40, needle) );
  if ( byte_78E09 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 6 )
    {
      strcpy((char *)v41, "find http request end flag!");
      sub_38730(7, (const char *)v41, 0);
LABEL_10:
      if ( byte_78E09 )
      {
        if ( !byte_7AD48 && !byte_78E08 )
          goto LABEL_47;
LABEL_13:
        snprintf((char *)v41, 0x1000u, "get http=%s", v40);
        sub_38730(7, (const char *)v41, 0);
      }
    }
    else
    {
LABEL_47:
      if ( dword_766C4 > 6 )
        goto LABEL_13;
    }
  }
  if ( v40[0] != 71 || v40[1] != 69 || v40[2] != 84 || v40[3] != 32 )
  {
    close(a1);
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      qmemcpy(v41, "statusServiceThread not support http command", sizeof(v41));
      v5 = aStatusservicet[44];
      v6 = (char *)&v42;
      v7 = &v40[10184];
      goto LABEL_20;
    }
    return 0;
  }
  if ( strstr(&v40[4], "/rate") )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      strcpy((char *)v41, "cmd : get rate");
      sub_38730(7, (const char *)v41, 0);
    }
    if ( dword_76B98 == 1 )
    {
      snprintf(s, 0x1000u, "%d", "():%d");
    }
    else if ( dword_76B98 == 2 )
    {
      snprintf(s, 0x1000u, "%s:%s", "searchfailed", "search_failed_info");
    }
    else
    {
      strcpy(s, "searching");
    }
    goto LABEL_39;
  }
  if ( !strstr(&v40[4], "/productName") )
  {
    close(a1);
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      strcpy((char *)v41, "statusServiceThread exit for Error cmd!");
      sub_38730(7, (const char *)v41, 0);
      return 0;
    }
    return 0;
  }
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy((char *)v41, "cmd : get miner type");
    sub_38730(7, (const char *)v41, 0);
  }
  snprintf(s, 0x1000u, byte_78850);
LABEL_39:
  if ( setsockopt(a1, 1, 21, optval, 8u) )
  {
    close(a1);
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      v9 = "setsockopt SO_SNDTIMEO failed";
LABEL_45:
      v10 = *(_DWORD *)v9;
      v11 = *((_DWORD *)v9 + 1);
      v12 = *((_DWORD *)v9 + 2);
      v13 = *((_DWORD *)v9 + 3);
      v14 = v9 + 16;
      v41[0] = v10;
      v41[1] = v11;
      v41[2] = v12;
      v41[3] = v13;
      v15 = v14[1];
      v16 = v14[2];
      v17 = v14[3];
      v41[4] = *v14;
      v41[5] = v15;
      v41[6] = v16;
      LOWORD(v41[7]) = v17;
      sub_38730(7, (const char *)v41, 0);
      return 0;
    }
    return 0;
  }
  if ( setsockopt(a1, 1, 20, optval, 8u) )
  {
    close(a1);
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      v9 = "setsockopt SO_RCVTIMEO failed";
      goto LABEL_45;
    }
    return 0;
  }
  v18 = strlen(s);
  v19 = sprintf((char *)v41, "HTTP/1.0  200  OK%s", &v31);
  v20 = v19 + sprintf((char *)v41 + v19, "Server: SearchFreqServer%s", &v31);
  v21 = sprintf((char *)v41 + v20, "Cache-Control: no-cache%s", &v31) + v20;
  v22 = sprintf((char *)v41 + v21, "Pragma: no-cache%s", &v31) + v21;
  v23 = sprintf((char *)v41 + v22, "Content-Type: text/plain%s", &v31) + v22;
  v24 = sprintf((char *)v41 + v23, "Content-Length: %d%s", v18, &v31);
  sprintf((char *)v41 + v24 + v23, "Connection: Keep-Alive%s", needle);
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy(v39, "send http response...\n");
    sub_38730(7, v39, 0);
  }
  v25 = (unsigned __int8)byte_7ACB8;
  if ( byte_7ACB8 )
  {
LABEL_80:
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      strcpy(v39, "send http data...");
      sub_38730(7, v39, 0);
    }
    v28 = 0;
    while ( 1 )
    {
      v29 = send(a1, &s[v28], v18 - v28, 0);
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        v30 = v29;
        snprintf(v39, 0x1000u, "send http data ret=%d", v29);
        sub_38730(7, v39, 0);
        v29 = v30;
      }
      if ( v29 <= 0 )
        break;
      v28 += v29;
      if ( v18 <= v28 || byte_7ACB8 )
        goto LABEL_94;
    }
    if ( byte_78E09 )
    {
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 6 )
      {
        strcpy(v39, "statusServiceThread send http data error");
        sub_38730(7, v39, 0);
LABEL_94:
        if ( !byte_78E09 )
          goto LABEL_99;
        if ( byte_7AD48 )
          goto LABEL_98;
      }
      if ( byte_78E08 || dword_766C4 > 6 )
      {
LABEL_98:
        strcpy(v39, "one client disconnected!");
        sub_38730(7, v39, 0);
      }
    }
LABEL_99:
    close(a1);
    return v28;
  }
  v26 = strlen((const char *)v41);
  while ( 1 )
  {
    v27 = send(a1, (char *)v41 + v25, v26 - v25, 0);
    if ( v27 == -1 )
      break;
    if ( v27 <= 0 )
      goto LABEL_75;
    v25 += v27;
LABEL_71:
    v26 = strlen((const char *)v41);
    if ( v26 <= v25 || byte_7ACB8 )
      goto LABEL_80;
  }
  if ( *_errno_location() == 11 )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      strcpy(v39, "statusServiceThread send http timeout, try again...");
      sub_38730(7, v39, 0);
    }
    usleep(0x186A0u);
    goto LABEL_71;
  }
LABEL_75:
  close(a1);
  if ( !byte_78E09 || !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
    return 0;
  qmemcpy(v39, "statusServiceThread send http response error", 44);
  v5 = aStatusservicet_1[44];
  v6 = &v39[44];
  v7 = &s[4040];
LABEL_20:
  *v6 = v5;
  sub_38730(7, v7 + 56, 0);
  return 0;
}
