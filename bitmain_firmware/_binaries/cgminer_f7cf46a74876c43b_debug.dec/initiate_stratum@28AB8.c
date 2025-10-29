bool __fastcall initiate_stratum(pool *pool)
{
  pool *v1; // r10
  int sock; // r0
  char *rpc_proxy; // r3
  int v4; // r0
  _BOOL4 v5; // r4
  struct addrinfo *v6; // r5
  int v7; // r0
  int *v8; // r10
  int v9; // r0
  int v10; // r9
  char *v11; // r6
  int v12; // r0
  int v13; // r1
  int v14; // r2
  __int16 v15; // r3
  int v16; // r3
  int v17; // r7
  int v18; // r7
  int v19; // r6
  fd_set *v20; // r3
  int v21; // r0
  char *v22; // r0
  char *v23; // r3
  int v24; // r0
  int *v25; // r4
  const char *sessionid; // r3
  int v27; // r2
  int v28; // r6
  ssize_t v29; // r0
  bool v30; // r6
  _BOOL4 v32; // r2
  bool extranonce_subscribe; // r7
  int v34; // r2
  ssize_t v35; // r0
  char *v36; // r0
  size_t v37; // r3
  size_t v38; // r3
  int v39; // r2
  const char *v40; // r0
  const char *v41; // r3
  int *v42; // r0
  int *v43; // r0
  const char *v44; // r6
  size_t v45; // r0
  size_t v46; // r5
  __int16 v47; // r0
  char *v48; // r1
  char *v49; // r0
  char *v50; // r6
  json_t *v51; // r6
  json_t *v52; // r0
  char *v53; // r4
  size_t refcount; // r3
  size_t v55; // r3
  char *v56; // r0
  int *v57; // r0
  int *v58; // r0
  int *v59; // r0
  int *v60; // r0
  int v61; // r5
  int v62; // r6
  int v63; // r5
  _BOOL4 v65; // r0
  char *v66; // r0
  int v67; // r5
  struct addrinfo *v68; // [sp+10h] [bp-3364h]
  const char *stratum_port; // [sp+18h] [bp-335Ch]
  const char *sockaddr_url; // [sp+1Ch] [bp-3358h]
  pthread_mutex_t *mutex; // [sp+20h] [bp-3354h]
  json_t *val; // [sp+28h] [bp-334Ch]
  int noresume; // [sp+2Ch] [bp-3348h]
  pool *v74; // [sp+34h] [bp-3340h]
  struct addrinfo *pai; // [sp+3Ch] [bp-3338h] BYREF
  socklen_t optlen; // [sp+40h] [bp-3334h] BYREF
  int optval; // [sp+44h] [bp-3330h] BYREF
  __int64 timeout; // [sp+48h] [bp-332Ch] BYREF
  struct addrinfo req; // [sp+50h] [bp-3324h] BYREF
  json_error_t err; // [sp+70h] [bp-3304h] BYREF
  fd_set writefds; // [sp+16Ch] [bp-3208h] BYREF
  char tmp42[4096]; // [sp+370h] [bp-3004h] BYREF
  char s[8196]; // [sp+1370h] [bp-2004h] BYREF

  v1 = pool;
  val = 0;
  mutex = &pool->stratum_lock;
  noresume = 0;
LABEL_2:
  if ( pthread_mutex_lock(mutex) )
  {
    v43 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
      *v43,
      "util.c",
      "setup_stratum_socket",
      3167);
    applog(3, tmp42, 1);
    quit(1);
  }
  sock = v1->sock;
  v1->stratum_active = 0;
  if ( sock )
    close(sock);
  v1->sock = 0;
  if ( pthread_mutex_unlock(mutex) )
  {
    v42 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v42,
      "util.c",
      "setup_stratum_socket",
      3172);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
  memset(&req, 0, sizeof(req));
  rpc_proxy = v1->rpc_proxy;
  req.ai_socktype = 1;
  if ( rpc_proxy )
    goto LABEL_7;
  v22 = opt_socks_proxy;
  if ( !opt_socks_proxy )
  {
    sockaddr_url = v1->sockaddr_url;
    goto LABEL_73;
  }
  v1->rpc_proxy = opt_socks_proxy;
  extract_sockaddr(v22, &v1->sockaddr_proxy_url, &v1->sockaddr_proxy_port);
  v23 = v1->rpc_proxy;
  v1->rpc_proxytype = 3;
  sockaddr_url = v1->sockaddr_url;
  if ( !v23 )
  {
LABEL_73:
    stratum_port = v1->stratum_port;
    v4 = getaddrinfo(sockaddr_url, stratum_port, &req, &pai);
    goto LABEL_8;
  }
LABEL_7:
  sockaddr_url = v1->sockaddr_proxy_url;
  stratum_port = v1->sockaddr_proxy_port;
  v4 = getaddrinfo(sockaddr_url, stratum_port, &req, &pai);
LABEL_8:
  if ( v4 )
  {
    if ( !v1->probed )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        snprintf(tmp42, 0x1000u, "Failed to resolve (?wrong URL) %s:%s", sockaddr_url, stratum_port);
        applog(4, tmp42, 0);
      }
      v1->probed = 1;
      goto LABEL_15;
    }
    if ( !opt_debug )
      goto LABEL_93;
    if ( use_syslog || (v5 = opt_log_output) || opt_log_level > 6 )
    {
      snprintf(tmp42, 0x1000u, "Failed to getaddrinfo for %s:%s", sockaddr_url, stratum_port);
      applog(7, tmp42, 0);
      goto LABEL_15;
    }
    goto LABEL_17;
  }
  if ( !pai )
    goto LABEL_40;
  v6 = pai;
  v74 = v1;
  do
  {
    while ( 1 )
    {
      v9 = socket(v6->ai_family, v6->ai_socktype, v6->ai_protocol);
      v10 = v9;
      if ( v9 == -1 )
      {
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          v11 = tmp42;
          v12 = *(_DWORD *)"Failed socket";
          v13 = *(_DWORD *)"ed socket";
          v14 = *(_DWORD *)"ocket";
          v15 = *(_WORD *)"t";
          goto LABEL_38;
        }
        goto LABEL_31;
      }
      v7 = fcntl(v9, 3, 0);
      fcntl(v10, 4, v7 | 0x800);
      if ( connect(v10, v6->ai_addr, v6->ai_addrlen) != -1 )
      {
        v1 = v74;
        if ( use_syslog || opt_log_output || opt_log_level > 3 )
        {
          strcpy(tmp42, "Succeeded immediate connect");
          applog(4, tmp42, 0);
        }
LABEL_69:
        block_socket(v10);
        freeaddrinfo(pai);
        if ( v1->rpc_proxy )
        {
          switch ( v1->rpc_proxytype )
          {
            case 0:
              if ( !http_negotiate(v1, v10, 0) )
                goto LABEL_15;
              break;
            case 1:
              if ( !http_negotiate(v1, v10, 1) )
                goto LABEL_15;
              break;
            case 2:
              if ( !socks4_negotiate(v1, v10, 0) )
                goto LABEL_15;
              break;
            case 3:
            case 5:
              LOWORD(writefds.fds_bits[0]) = 261;
              BYTE2(writefds.fds_bits[0]) = 0;
              if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                snprintf(
                  tmp42,
                  0x1000u,
                  "Attempting to negotiate with %s:%s SOCKS5 proxy",
                  v1->sockaddr_proxy_url,
                  v1->sockaddr_proxy_port);
                applog(7, tmp42, 0);
              }
              send(v10, &writefds, 3u, 0);
              if ( recv(v10, tmp42, 1u, 0) == -1
                || tmp42[0] != 5
                || recv(v10, tmp42, 1u, 0) == -1
                || BYTE2(writefds.fds_bits[0]) != (unsigned __int8)tmp42[0] )
              {
                if ( use_syslog || opt_log_output || opt_log_level > 3 )
                  goto LABEL_159;
LABEL_193:
                v5 = 0;
                if ( !opt_debug )
                  goto LABEL_93;
                if ( !opt_log_output )
                {
LABEL_195:
                  if ( opt_log_level > 6 )
                    goto LABEL_19;
LABEL_20:
                  if ( !v5 )
                    goto LABEL_93;
LABEL_92:
                  suspend_stratum(v1);
                  goto LABEL_93;
                }
LABEL_19:
                strcpy(tmp42, "Initiate stratum failed");
                applog(7, tmp42, 0);
                goto LABEL_20;
              }
              v44 = v1->sockaddr_url;
              writefds.fds_bits[0] = 50331909;
              v45 = strlen(v44);
              if ( v45 >= 0xFF )
                v45 = 255;
              v46 = v45;
              LOBYTE(writefds.fds_bits[1]) = v45;
              memcpy((char *)&writefds.fds_bits[1] + 1, v44, v45);
              v47 = strtol(v1->stratum_port, 0, 10);
              v48 = (char *)&writefds + v46;
              v48[6] = v47;
              v48[5] = HIBYTE(v47);
              send(v10, &writefds, v46 + 7, 0);
              if ( recv(v10, tmp42, 1u, 0) == -1
                || tmp42[0] != 5
                || recv(v10, tmp42, 1u, 0) == -1
                || (v61 = (unsigned __int8)tmp42[0], tmp42[0])
                || (recv(v10, tmp42, 1u, 0), recv(v10, tmp42, 1u, v61) == -1) )
              {
LABEL_152:
                if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
                  goto LABEL_15;
LABEL_159:
                snprintf(
                  tmp42,
                  0x1000u,
                  "Bad response from %s:%s SOCKS5 server",
                  v1->sockaddr_proxy_url,
                  v1->sockaddr_proxy_port);
                applog(4, tmp42, 0);
                goto LABEL_15;
              }
              if ( tmp42[0] == 1 )
              {
                v67 = 4;
                do
                {
                  recv(v10, tmp42, 1u, 0);
                  --v67;
                }
                while ( v67 );
              }
              else
              {
                if ( tmp42[0] != 3 )
                  goto LABEL_152;
                v62 = 0;
                if ( recv(v10, tmp42, 1u, 0) == -1 )
                  v63 = -1;
                else
                  v63 = (unsigned __int8)tmp42[0];
                while ( v62++ < v63 )
                  recv(v10, tmp42, 1u, 0);
              }
              recv(v10, tmp42, 1u, 0);
              recv(v10, tmp42, 1u, 0);
              if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                snprintf(
                  tmp42,
                  0x1000u,
                  "Success negotiating with %s:%s SOCKS5 proxy",
                  v1->sockaddr_proxy_url,
                  v1->sockaddr_proxy_port);
                applog(7, tmp42, 0);
              }
              break;
            case 4:
              if ( socks4_negotiate(v1, v10, 1) )
                break;
              goto LABEL_15;
            default:
              if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
                goto LABEL_193;
              snprintf(
                tmp42,
                0x1000u,
                "Unsupported proxy type for %s:%s",
                v1->sockaddr_proxy_url,
                v1->sockaddr_proxy_port);
              applog(4, tmp42, 0);
              goto LABEL_15;
          }
        }
        if ( !v1->sockbuf )
        {
          v56 = (char *)calloc(0x2000u, 1u);
          v1->sockbuf = v56;
          if ( !v56 )
          {
            snprintf(
              tmp42,
              0x1000u,
              "Failed to calloc pool sockbuf in %s %s():%d",
              "util.c",
              "setup_stratum_socket",
              3311);
            applog(3, tmp42, 1);
            quit(1);
          }
          v1->sockbuf_size = 0x2000;
        }
        v1->sock = v10;
        *(_DWORD *)tmp42 = 30;
        writefds.fds_bits[0] = 45;
        LODWORD(timeout) = 1;
        v24 = fcntl(v10, 3, 0);
        fcntl(v10, 4, v24 | 0x800);
        setsockopt(v10, 1, 9, &timeout, 4u);
        if ( !opt_delaynet )
          fcntl(v10, 2, 1);
        setsockopt(v10, 6, 1, &timeout, 4u);
        setsockopt(v10, 6, 6, &timeout, 4u);
        LOWORD(v25) = (unsigned __int16)&swork_id;
        setsockopt(v10, 6, 4, &writefds, 4u);
        setsockopt(v10, 6, 5, tmp42, 4u);
        if ( noresume )
        {
          HIWORD(v25) = (unsigned int)&swork_id >> 16;
          clear_sock(v1);
          v39 = (*v25)++;
          sprintf(s, "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": []}", v39);
        }
        else
        {
          HIWORD(v25) = (unsigned int)&swork_id >> 16;
          sessionid = v1->sessionid;
          v27 = *v25;
          v28 = *v25 + 1;
          if ( sessionid )
          {
            *v25 = v28;
            sprintf(
              s,
              "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"cgminer/4.9.0\", \"%s\"]}",
              v27,
              sessionid);
          }
          else
          {
            v40 = v1->stratum_port;
            v41 = v1->sockaddr_url;
            *v25 = v28;
            sprintf(
              s,
              "{\"id\":%d, \"method\":\"mining.subscribe\", \"params\":[\"cgminer/4.9.0\", null, \"%s\", \"%s\"]}",
              v27,
              v41,
              v40);
          }
        }
        v29 = strlen(s);
        if ( _stratum_send(v1, s, v29) )
        {
          v5 = opt_debug;
          if ( !opt_debug )
            goto LABEL_92;
          if ( use_syslog || opt_log_output || opt_log_level > 6 )
          {
            strcpy(tmp42, "Failed to send s in initiate_stratum");
            applog(7, tmp42, 0);
            goto LABEL_117;
          }
          goto LABEL_17;
        }
        if ( !socket_full(v1->sock, 60) )
        {
          v5 = opt_debug;
          if ( !opt_debug )
            goto LABEL_92;
          if ( use_syslog || opt_log_output || opt_log_level > 6 )
          {
            strcpy(tmp42, "Timed out waiting for response in initiate_stratum");
            applog(7, tmp42, 0);
LABEL_117:
            v5 = opt_debug;
            if ( opt_debug )
              goto LABEL_17;
            goto LABEL_92;
          }
LABEL_17:
          if ( !use_syslog && !opt_log_output )
            goto LABEL_195;
          goto LABEL_19;
        }
        v49 = recv_line(v1);
        v50 = v49;
        if ( !v49 )
          goto LABEL_117;
        val = json_loads(v49, 0, &err);
        free(v50);
        if ( !val )
        {
          noresume ^= 1u;
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            snprintf(tmp42, 0x1000u, "JSON decode failed(%d): %s", err.line, err.text);
            applog(7, tmp42, 0);
          }
          goto LABEL_173;
        }
        v51 = json_object_get(val, "result");
        v52 = json_object_get(val, "error");
        if ( !v51 || v51->type == JSON_NULL )
        {
          if ( !v52 )
          {
            v66 = (char *)malloc(0x11u);
            v53 = v66;
            if ( v66 )
              strcpy(v66, "(unknown reason)");
            goto LABEL_167;
          }
        }
        else if ( !v52 || v52->type == JSON_NULL )
        {
          v65 = parse_extranonce_equihash(v1, v51, 1);
          if ( v65 )
          {
            v30 = v65;
            if ( !v1->stratum_url )
              v1->stratum_url = v1->sockaddr_url;
            v32 = opt_protocol;
            v1->stratum_active = 1;
            v1->sdiff = 1.0;
            if ( v32 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              snprintf(
                tmp42,
                0x1000u,
                "Pool %d confirmed mining.subscribe with extranonce1 %s extran2size %d",
                v1->pool_no,
                v1->nonce1,
                v1->n2size);
              applog(7, tmp42, 0);
            }
            extranonce_subscribe = v1->extranonce_subscribe;
            if ( extranonce_subscribe )
            {
              v34 = (*v25)++;
              sprintf(s, "{\"id\": %d, \"method\": \"mining.extranonce.subscribe\", \"params\": []}", v34);
              v35 = strlen(s);
              stratum_send(v1, s, v35);
              v36 = recv_line(v1);
              if ( v36 )
              {
                free(v36);
                v30 = extranonce_subscribe;
              }
              else if ( use_syslog || opt_log_output || opt_log_level > 2 )
              {
                v30 = extranonce_subscribe;
                strcpy(tmp42, "recv mining.extranonce.subscribe failed\n");
                applog(3, tmp42, 0);
              }
              else
              {
                v30 = extranonce_subscribe;
              }
            }
            goto LABEL_111;
          }
          noresume ^= 1u;
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            snprintf(tmp42, 0x1000u, "%s: Failed to get parse extranonce.", "initiate_stratum");
            applog(7, tmp42, 0);
          }
          goto LABEL_173;
        }
        v53 = json_dumps(v52, 3u);
LABEL_167:
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(tmp42, 0x1000u, "JSON-RPC decode failed: %s", v53);
          applog(7, tmp42, 0);
        }
        noresume ^= 1u;
        free(v53);
LABEL_173:
        if ( !noresume )
          goto LABEL_117;
        if ( pthread_mutex_lock(&v1->data_lock.mutex) )
        {
          v60 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
            *v60,
            "util.c",
            "initiate_stratum",
            3608);
          applog(3, tmp42, 1);
          quit(1);
        }
        if ( pthread_rwlock_wrlock(&v1->data_lock.rwlock) )
        {
          v59 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
            *v59,
            "util.c",
            "initiate_stratum",
            3608);
          applog(3, tmp42, 1);
          quit(1);
        }
        free(v1->sessionid);
        free(v1->nonce1);
        v1->nonce1 = 0;
        v1->sessionid = 0;
        if ( pthread_rwlock_unlock(&v1->data_lock.rwlock) )
        {
          v58 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
            *v58,
            "util.c",
            "initiate_stratum",
            3612);
          applog(3, tmp42, 1);
          quit(1);
        }
        if ( pthread_mutex_unlock(&v1->data_lock.mutex) )
        {
          v57 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
            *v57,
            "util.c",
            "initiate_stratum",
            3612);
          applog(3, tmp42, 1);
          quit(1);
        }
        selective_yield();
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          strcpy(tmp42, "Failed to resume stratum, trying afresh");
          applog(7, tmp42, 0);
        }
        if ( val )
        {
          refcount = val->refcount;
          if ( refcount != -1 )
          {
            v55 = refcount - 1;
            val->refcount = v55;
            if ( !v55 )
              json_delete(val);
          }
        }
        goto LABEL_2;
      }
      timeout = 1;
      v8 = _errno_location();
      if ( *v8 != 115 )
      {
        close(v10);
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          strcpy(tmp42, "Failed sock connect");
          applog(7, tmp42, 0);
        }
        goto LABEL_31;
      }
      LOBYTE(v16) = v10 & 0x1F;
      v17 = (v10 + 31) & (v10 >> 31);
      if ( v10 >= 0 )
        v17 = v10;
      v18 = v17 >> 5;
      if ( v10 <= 0 )
        v16 = -(-v10 & 0x1F);
      v68 = v6;
      v19 = 1 << v16;
      while ( 1 )
      {
        v6 = v68;
        v20 = (fd_set *)&err.text[156];
        do
        {
          v20->fds_bits[1] = 0;
          v20 = (fd_set *)((char *)v20 + 4);
        }
        while ( &writefds.fds_bits[31] != (__fd_mask *)v20 );
        writefds.fds_bits[v18] |= v19;
        v21 = select(v10 + 1, 0, &writefds, 0, (struct timeval *)&timeout);
        if ( v21 > 0 )
          break;
        if ( !v21 || *v8 != 4 )
          goto LABEL_54;
      }
      if ( (v19 & writefds.fds_bits[v18]) != 0 )
      {
        optlen = 4;
        if ( !getsockopt(v10, 1, 4, &optval, &optlen) && !optval )
        {
          v1 = v74;
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            strcpy(tmp42, "Succeeded delayed connect");
            applog(7, tmp42, 0);
          }
          goto LABEL_69;
        }
      }
LABEL_54:
      close(v10);
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        break;
LABEL_31:
      v6 = v6->ai_next;
      if ( !v6 )
        goto LABEL_39;
    }
    qmemcpy(tmp42, "Select timeout/f", 16);
    v11 = &tmp42[16];
    v12 = *(_DWORD *)"ailed connect";
    v13 = *(_DWORD *)"d connect";
    v14 = *(_DWORD *)"nnect";
    v15 = *(_WORD *)"t";
LABEL_38:
    *(_DWORD *)v11 = v12;
    *((_DWORD *)v11 + 1) = v13;
    *((_DWORD *)v11 + 2) = v14;
    *((_WORD *)v11 + 6) = v15;
    applog(7, tmp42, 0);
    v6 = v6->ai_next;
  }
  while ( v6 );
LABEL_39:
  v1 = v74;
LABEL_40:
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "Failed to connect to stratum on %s:%s", sockaddr_url, stratum_port);
    applog(7, tmp42, 0);
  }
  freeaddrinfo(pai);
LABEL_15:
  if ( opt_debug )
  {
    v5 = 0;
    goto LABEL_17;
  }
LABEL_93:
  v30 = 0;
  if ( !val )
    return 0;
LABEL_111:
  v37 = val->refcount;
  if ( v37 == -1 )
    return v30;
  v38 = v37 - 1;
  val->refcount = v38;
  if ( v38 )
    return v30;
  json_delete(val);
  return v30;
}
