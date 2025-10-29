bool __fastcall initiate_stratum(pool *pool)
{
  pool *v1; // r10
  int sock; // r0
  char *rpc_proxy; // r3
  int v4; // r0
  _BOOL4 v5; // r4
  int *v6; // r5
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  struct addrinfo *v12; // r5
  int v13; // r0
  int *v14; // r10
  int *v15; // r6
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r6
  int v21; // r0
  int v22; // r9
  int *v23; // r3
  char *v24; // r6
  int v25; // r0
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r3
  int v30; // r7
  int v31; // r7
  int v32; // r6
  fd_set *v33; // r3
  int v34; // r0
  int *v35; // r12
  int v36; // r0
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int *v40; // r5
  int v41; // r0
  int v42; // r1
  int v43; // r2
  int v44; // r3
  int v45; // r1
  int v46; // r2
  char *v47; // r0
  char *v48; // r3
  const char *v49; // r2
  int *v50; // r4
  int v51; // r0
  int v52; // r1
  int v53; // r2
  int v54; // r3
  int v55; // r1
  int v56; // r2
  int v57; // r0
  _DWORD *v58; // r4
  const char *v59; // r1
  ssize_t v60; // r0
  bool v61; // r6
  _BOOL4 v63; // r2
  const char *v64; // r2
  bool extranonce_subscribe; // r7
  int v66; // r2
  ssize_t v67; // r0
  char *v68; // r0
  int *v69; // r5
  int v70; // r0
  int v71; // r1
  int v72; // r2
  int v73; // r3
  int v74; // r0
  int v75; // r1
  int v76; // r2
  int v77; // r3
  int v78; // r1
  int v79; // r2
  size_t v80; // r3
  size_t v81; // r3
  int *v82; // r4
  int v83; // r0
  int v84; // r1
  int v85; // r2
  int v86; // r3
  int v87; // r0
  int v88; // r1
  int v89; // r2
  int v90; // r3
  int v91; // r1
  int *v92; // r5
  int v93; // r0
  int v94; // r1
  int v95; // r2
  int v96; // r3
  int v97; // r0
  int v98; // r1
  int v99; // r2
  int v100; // r3
  int v101; // r0
  int v102; // r1
  int v103; // r2
  int v104; // r3
  int v105; // r5
  int v106; // r2
  int *v107; // r0
  int v108; // r1
  const char *v109; // r2
  int *v110; // r0
  int v111; // r1
  const char *v112; // r2
  const char *v113; // r2
  const char *v114; // r6
  size_t v115; // r0
  size_t v116; // r5
  __int16 v117; // r0
  char *v118; // r1
  const char *v119; // r2
  char *v120; // r0
  char *v121; // r6
  json_t *v122; // r0
  const char *v123; // r1
  json_t *v124; // r6
  json_t *v125; // r0
  char *v126; // r4
  const char *v127; // r2
  int *v128; // r4
  int v129; // r0
  int v130; // r1
  int v131; // r2
  int v132; // r3
  int v133; // r0
  int v134; // r1
  int v135; // r2
  int v136; // r3
  int v137; // r1
  size_t refcount; // r3
  size_t v139; // r3
  char *v140; // r0
  const char *v141; // r2
  int v142; // r3
  const char *v143; // r2
  const char *v144; // r2
  int *v145; // r0
  int v146; // r1
  const char *v147; // r2
  int *v148; // r0
  int v149; // r1
  const char *v150; // r2
  int *v151; // r0
  int v152; // r1
  const char *v153; // r2
  int *v154; // r0
  int v155; // r1
  const char *v156; // r2
  int v157; // r5
  int v158; // r6
  int v159; // r5
  _BOOL4 v161; // r0
  const char *v162; // r2
  char *v163; // r0
  int *v164; // r5
  char *v165; // r6
  int v166; // r0
  int v167; // r1
  int v168; // r2
  int v169; // r3
  int v170; // r5
  int v171; // r5
  const char *v172; // r2
  struct addrinfo *v173; // [sp+10h] [bp-3364h]
  const char *stratum_port; // [sp+18h] [bp-335Ch]
  const char *sockaddr_url; // [sp+1Ch] [bp-3358h]
  pthread_mutex_t *mutex; // [sp+20h] [bp-3354h]
  json_t *val; // [sp+28h] [bp-334Ch]
  int noresume; // [sp+2Ch] [bp-3348h]
  pool *v179; // [sp+34h] [bp-3340h]
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
    v110 = _errno_location();
    LOWORD(v111) = 15984;
    HIWORD(v111) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    LOWORD(v112) = -968;
    HIWORD(v112) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v112, *v110, v111, "setup_stratum_socket", 3167);
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
    v107 = _errno_location();
    LOWORD(v108) = 15984;
    HIWORD(v108) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    LOWORD(v109) = -920;
    HIWORD(v109) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v109, *v107, v108, "setup_stratum_socket", 3172);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
  memset(&req, 0, sizeof(req));
  rpc_proxy = v1->rpc_proxy;
  req.ai_socktype = 1;
  if ( rpc_proxy )
    goto LABEL_7;
  v47 = opt_socks_proxy;
  if ( !opt_socks_proxy )
  {
    sockaddr_url = v1->sockaddr_url;
    goto LABEL_73;
  }
  v1->rpc_proxy = opt_socks_proxy;
  extract_sockaddr(v47, &v1->sockaddr_proxy_url, &v1->sockaddr_proxy_port);
  v48 = v1->rpc_proxy;
  v1->rpc_proxytype = 3;
  sockaddr_url = v1->sockaddr_url;
  if ( !v48 )
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
      goto LABEL_94;
    if ( use_syslog || (v5 = opt_log_output) || opt_log_level > 6 )
    {
      LOWORD(v49) = 16872;
      HIWORD(v49) = (unsigned int)"ockbuf in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v49, sockaddr_url, stratum_port);
      applog(7, tmp42, 0);
      goto LABEL_15;
    }
    goto LABEL_17;
  }
  if ( !pai )
    goto LABEL_40;
  v12 = pai;
  v179 = v1;
  do
  {
    while ( 1 )
    {
      v21 = socket(v12->ai_family, v12->ai_socktype, v12->ai_protocol);
      v22 = v21;
      if ( v21 == -1 )
      {
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          LOWORD(v23) = 16904;
          HIWORD(v23) = (unsigned int)"o parse a \\n terminated string in recv_line" >> 16;
          v24 = tmp42;
          v25 = *v23;
          v26 = v23[1];
          v27 = v23[2];
          v28 = v23[3];
          goto LABEL_38;
        }
        goto LABEL_31;
      }
      v13 = fcntl(v21, 3, 0);
      fcntl(v22, 4, v13 | 0x800);
      if ( connect(v22, v12->ai_addr, v12->ai_addrlen) != -1 )
      {
        v1 = v179;
        if ( use_syslog || opt_log_output || opt_log_level > 3 )
        {
          LOWORD(v50) = 17000;
          HIWORD(v50) = (unsigned int)"Failed to getaddrinfo for %s:%s" >> 16;
          v51 = *v50;
          v52 = v50[1];
          v53 = v50[2];
          v54 = v50[3];
          v50 += 4;
          *(_DWORD *)tmp42 = v51;
          *(_DWORD *)&tmp42[4] = v52;
          *(_DWORD *)&tmp42[8] = v53;
          *(_DWORD *)&tmp42[12] = v54;
          v55 = v50[1];
          v56 = v50[2];
          *(_DWORD *)&tmp42[16] = *v50;
          *(_DWORD *)&tmp42[20] = v55;
          *(_DWORD *)&tmp42[24] = v56;
          applog(4, tmp42, 0);
        }
LABEL_69:
        block_socket(v22);
        freeaddrinfo(pai);
        if ( v1->rpc_proxy )
        {
          switch ( v1->rpc_proxytype )
          {
            case 0:
              if ( !http_negotiate(v1, v22, 0) )
                goto LABEL_15;
              break;
            case 1:
              if ( !http_negotiate(v1, v22, 1) )
                goto LABEL_15;
              break;
            case 2:
              if ( !socks4_negotiate(v1, v22, 0) )
                goto LABEL_15;
              break;
            case 3:
            case 5:
              LOWORD(writefds.fds_bits[0]) = 261;
              BYTE2(writefds.fds_bits[0]) = 0;
              if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                LOWORD(v113) = 17068;
                HIWORD(v113) = (unsigned int)"Succeeded delayed connect" >> 16;
                snprintf(tmp42, 0x1000u, v113, v1->sockaddr_proxy_url, v1->sockaddr_proxy_port);
                applog(7, tmp42, 0);
              }
              send(v22, &writefds, 3u, 0);
              if ( recv(v22, tmp42, 1u, 0) == -1
                || tmp42[0] != 5
                || recv(v22, tmp42, 1u, 0) == -1
                || BYTE2(writefds.fds_bits[0]) != (unsigned __int8)tmp42[0] )
              {
                if ( use_syslog || opt_log_output || opt_log_level > 3 )
                  goto LABEL_160;
LABEL_194:
                v5 = 0;
                if ( !opt_debug )
                  goto LABEL_94;
                if ( !opt_log_output )
                {
LABEL_196:
                  if ( opt_log_level > 6 )
                    goto LABEL_19;
LABEL_20:
                  if ( !v5 )
                    goto LABEL_94;
LABEL_93:
                  suspend_stratum(v1);
                  goto LABEL_94;
                }
LABEL_19:
                LOWORD(v6) = 17880;
                HIWORD(v6) = (unsigned int)"ning.extranonce.subscribe\", \"params\": []}" >> 16;
                v7 = *v6;
                v8 = v6[1];
                v9 = v6[2];
                v10 = v6[3];
                v6 += 4;
                *(_DWORD *)tmp42 = v7;
                *(_DWORD *)&tmp42[4] = v8;
                *(_DWORD *)&tmp42[8] = v9;
                *(_DWORD *)&tmp42[12] = v10;
                v11 = v6[1];
                *(_DWORD *)&tmp42[16] = *v6;
                *(_DWORD *)&tmp42[20] = v11;
                applog(7, tmp42, 0);
                goto LABEL_20;
              }
              v114 = v1->sockaddr_url;
              writefds.fds_bits[0] = 50331909;
              v115 = strlen(v114);
              if ( v115 >= 0xFF )
                v115 = 255;
              v116 = v115;
              LOBYTE(writefds.fds_bits[1]) = v115;
              memcpy((char *)&writefds.fds_bits[1] + 1, v114, v115);
              v117 = strtol(v1->stratum_port, 0, 10);
              v118 = (char *)&writefds + v116;
              v118[6] = v117;
              v118[5] = HIBYTE(v117);
              send(v22, &writefds, v116 + 7, 0);
              if ( recv(v22, tmp42, 1u, 0) == -1
                || tmp42[0] != 5
                || recv(v22, tmp42, 1u, 0) == -1
                || (v157 = (unsigned __int8)tmp42[0], tmp42[0])
                || (recv(v22, tmp42, 1u, 0), recv(v22, tmp42, 1u, v157) == -1) )
              {
LABEL_153:
                if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
                  goto LABEL_15;
LABEL_160:
                LOWORD(v119) = 17116;
                HIWORD(v119) = (unsigned int)"d connect" >> 16;
                snprintf(tmp42, 0x1000u, v119, v1->sockaddr_proxy_url, v1->sockaddr_proxy_port);
                applog(4, tmp42, 0);
                goto LABEL_15;
              }
              if ( tmp42[0] == 1 )
              {
                v171 = 4;
                do
                {
                  recv(v22, tmp42, 1u, 0);
                  --v171;
                }
                while ( v171 );
              }
              else
              {
                if ( tmp42[0] != 3 )
                  goto LABEL_153;
                v158 = 0;
                if ( recv(v22, tmp42, 1u, 0) == -1 )
                  v159 = -1;
                else
                  v159 = (unsigned __int8)tmp42[0];
                while ( v158++ < v159 )
                  recv(v22, tmp42, 1u, 0);
              }
              recv(v22, tmp42, 1u, 0);
              recv(v22, tmp42, 1u, 0);
              if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                LOWORD(v172) = 17156;
                HIWORD(v172) = (unsigned int)"Failed to connect to stratum on %s:%s" >> 16;
                snprintf(tmp42, 0x1000u, v172, v1->sockaddr_proxy_url, v1->sockaddr_proxy_port);
                applog(7, tmp42, 0);
              }
              break;
            case 4:
              if ( socks4_negotiate(v1, v22, 1) )
                break;
              goto LABEL_15;
            default:
              if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
                goto LABEL_194;
              LOWORD(v141) = 17200;
              HIWORD(v141) = (unsigned int)"mpting to negotiate with %s:%s SOCKS5 proxy" >> 16;
              snprintf(tmp42, 0x1000u, v141, v1->sockaddr_proxy_url, v1->sockaddr_proxy_port);
              applog(4, tmp42, 0);
              goto LABEL_15;
          }
        }
        if ( !v1->sockbuf )
        {
          v140 = (char *)calloc(0x2000u, 1u);
          v1->sockbuf = v140;
          if ( !v140 )
          {
            LOWORD(v142) = 15984;
            LOWORD(v143) = 17236;
            HIWORD(v142) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
            HIWORD(v143) = (unsigned int)"5 proxy" >> 16;
            snprintf(tmp42, 0x1000u, v143, v142, "setup_stratum_socket", 3311);
            applog(3, tmp42, 1);
            quit(1);
          }
          v1->sockbuf_size = 0x2000;
        }
        v1->sock = v22;
        *(_DWORD *)tmp42 = 30;
        writefds.fds_bits[0] = 45;
        LODWORD(timeout) = 1;
        v57 = fcntl(v22, 3, 0);
        fcntl(v22, 4, v57 | 0x800);
        setsockopt(v22, 1, 9, &timeout, 4u);
        if ( !opt_delaynet )
          fcntl(v22, 2, 1);
        setsockopt(v22, 6, 1, &timeout, 4u);
        setsockopt(v22, 6, 6, &timeout, 4u);
        LOWORD(v58) = (unsigned __int16)&swork_id;
        setsockopt(v22, 6, 4, &writefds, 4u);
        setsockopt(v22, 6, 5, tmp42, 4u);
        if ( noresume )
        {
          HIWORD(v58) = (unsigned int)&swork_id >> 16;
          clear_sock(v1);
          v106 = (*v58)++;
          sprintf(s, "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": []}", v106);
        }
        else
        {
          HIWORD(v58) = (unsigned int)&swork_id >> 16;
          if ( v1->sessionid )
          {
            LOWORD(v59) = 17336;
            HIWORD(v59) = (unsigned int)"ted proxy type for %s:%s" >> 16;
          }
          else
          {
            LOWORD(v59) = 17412;
            HIWORD(v59) = (unsigned int)"\": %d, \"method\": \"mining.subscribe\", \"params\": []}" >> 16;
          }
          ++*v58;
          sprintf(s, v59);
        }
        v60 = strlen(s);
        if ( _stratum_send(v1, s, v60) )
        {
          v5 = opt_debug;
          if ( !opt_debug )
            goto LABEL_93;
          if ( use_syslog || opt_log_output || opt_log_level > 6 )
          {
            LOWORD(v82) = 17500;
            HIWORD(v82) = (unsigned int)"be\", \"params\": [\"cgminer/4.9.0\", \"%s\"]}" >> 16;
            v83 = *v82;
            v84 = v82[1];
            v85 = v82[2];
            v86 = v82[3];
            v82 += 4;
            *(_DWORD *)tmp42 = v83;
            *(_DWORD *)&tmp42[4] = v84;
            *(_DWORD *)&tmp42[8] = v85;
            *(_DWORD *)&tmp42[12] = v86;
            v87 = *v82;
            v88 = v82[1];
            v89 = v82[2];
            v90 = v82[3];
            v82 += 4;
            *(_DWORD *)&tmp42[16] = v87;
            *(_DWORD *)&tmp42[20] = v88;
            *(_DWORD *)&tmp42[24] = v89;
            *(_DWORD *)&tmp42[28] = v90;
            v91 = v82[1];
            *(_DWORD *)&tmp42[32] = *v82;
            tmp42[36] = v91;
            applog(7, tmp42, 0);
            goto LABEL_118;
          }
          goto LABEL_17;
        }
        if ( !socket_full(v1->sock, 60) )
        {
          v5 = opt_debug;
          if ( !opt_debug )
            goto LABEL_93;
          if ( use_syslog || opt_log_output || opt_log_level > 6 )
          {
            LOWORD(v92) = 17540;
            HIWORD(v92) = (unsigned int)"{\"id\":%d, \"method\":\"mining.subscribe\", \"params\":[\"cgminer/4.9.0\", null"
                                        ", \"%s\", \"%s\"]}" >> 16;
            v93 = *v92;
            v94 = v92[1];
            v95 = v92[2];
            v96 = v92[3];
            v92 += 4;
            *(_DWORD *)tmp42 = v93;
            *(_DWORD *)&tmp42[4] = v94;
            *(_DWORD *)&tmp42[8] = v95;
            *(_DWORD *)&tmp42[12] = v96;
            v97 = *v92;
            v98 = v92[1];
            v99 = v92[2];
            v100 = v92[3];
            v92 += 4;
            *(_DWORD *)&tmp42[16] = v97;
            *(_DWORD *)&tmp42[20] = v98;
            *(_DWORD *)&tmp42[24] = v99;
            *(_DWORD *)&tmp42[28] = v100;
            v101 = *v92;
            v102 = v92[1];
            v103 = v92[2];
            v104 = v92[3];
            v105 = v92[4];
            *(_DWORD *)&tmp42[32] = v101;
            *(_DWORD *)&tmp42[36] = v102;
            *(_DWORD *)&tmp42[40] = v103;
            *(_DWORD *)&tmp42[44] = v104;
            *(_WORD *)&tmp42[48] = v105;
            tmp42[50] = BYTE2(v105);
            applog(7, tmp42, 0);
LABEL_118:
            v5 = opt_debug;
            if ( opt_debug )
              goto LABEL_17;
            goto LABEL_93;
          }
LABEL_17:
          if ( !use_syslog && !opt_log_output )
            goto LABEL_196;
          goto LABEL_19;
        }
        v120 = recv_line(v1);
        v121 = v120;
        if ( !v120 )
          goto LABEL_118;
        val = json_loads(v120, 0, &err);
        free(v121);
        if ( !val )
        {
          noresume ^= 1u;
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            LOWORD(v144) = 5036;
            HIWORD(v144) = (unsigned int)"tum connection to pool %d interrupted" >> 16;
            snprintf(tmp42, 0x1000u, v144, err.line, err.text);
            applog(7, tmp42, 0);
          }
          goto LABEL_174;
        }
        v122 = json_object_get(val, "result");
        LOWORD(v123) = 2324;
        v124 = v122;
        HIWORD(v123) = (unsigned int)"sharelog printf error" >> 16;
        v125 = json_object_get(val, v123);
        if ( !v124 || v124->type == JSON_NULL )
        {
          if ( !v125 )
          {
            v163 = (char *)malloc(0x11u);
            v126 = v163;
            if ( v163 )
            {
              LOWORD(v164) = 5076;
              v165 = v163;
              HIWORD(v164) = (unsigned int)"JSON decode failed(%d): %s" >> 16;
              v166 = *v164;
              v167 = v164[1];
              v168 = v164[2];
              v169 = v164[3];
              v170 = v164[4];
              *(_DWORD *)v165 = v166;
              *((_DWORD *)v165 + 1) = v167;
              *((_DWORD *)v165 + 2) = v168;
              *((_DWORD *)v165 + 3) = v169;
              v165[16] = v170;
            }
            goto LABEL_168;
          }
        }
        else if ( !v125 || v125->type == JSON_NULL )
        {
          v161 = parse_extranonce_equihash(v1, v124, 1);
          if ( v161 )
          {
            v61 = v161;
            if ( !v1->stratum_url )
              v1->stratum_url = v1->sockaddr_url;
            v63 = opt_protocol;
            v1->stratum_active = 1;
            v1->sdiff = 1.0;
            if ( v63 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              LOWORD(v64) = 17656;
              HIWORD(v64) = (unsigned int)"_stratum" >> 16;
              snprintf(tmp42, 0x1000u, v64, v1->pool_no, v1->nonce1, v1->n2size);
              applog(7, tmp42, 0);
            }
            extranonce_subscribe = v1->extranonce_subscribe;
            if ( extranonce_subscribe )
            {
              v66 = (*v58)++;
              sprintf(s, "{\"id\": %d, \"method\": \"mining.extranonce.subscribe\", \"params\": []}", v66);
              v67 = strlen(s);
              stratum_send(v1, s, v67);
              v68 = recv_line(v1);
              if ( v68 )
              {
                free(v68);
                v61 = extranonce_subscribe;
              }
              else if ( use_syslog || opt_log_output || opt_log_level > 2 )
              {
                LOWORD(v69) = 17796;
                HIWORD(v69) = (unsigned int)"irmed mining.subscribe with extranonce1 %s extran2size %d" >> 16;
                v61 = extranonce_subscribe;
                v70 = *v69;
                v71 = v69[1];
                v72 = v69[2];
                v73 = v69[3];
                v69 += 4;
                *(_DWORD *)tmp42 = v70;
                *(_DWORD *)&tmp42[4] = v71;
                *(_DWORD *)&tmp42[8] = v72;
                *(_DWORD *)&tmp42[12] = v73;
                v74 = *v69;
                v75 = v69[1];
                v76 = v69[2];
                v77 = v69[3];
                v69 += 4;
                *(_DWORD *)&tmp42[16] = v74;
                *(_DWORD *)&tmp42[20] = v75;
                *(_DWORD *)&tmp42[24] = v76;
                *(_DWORD *)&tmp42[28] = v77;
                v78 = v69[1];
                v79 = v69[2];
                *(_DWORD *)&tmp42[32] = *v69;
                *(_DWORD *)&tmp42[36] = v78;
                tmp42[40] = v79;
                applog(3, tmp42, 0);
              }
              else
              {
                v61 = extranonce_subscribe;
              }
            }
            goto LABEL_112;
          }
          noresume ^= 1u;
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            LOWORD(v162) = 17620;
            HIWORD(v162) = (unsigned int)"s\"]}" >> 16;
            snprintf(tmp42, 0x1000u, v162, "initiate_stratum");
            applog(7, tmp42, 0);
          }
          goto LABEL_174;
        }
        v126 = json_dumps(v125, 3u);
LABEL_168:
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          LOWORD(v127) = 17592;
          HIWORD(v127) = (unsigned int)"miner/4.9.0\", null, \"%s\", \"%s\"]}" >> 16;
          snprintf(tmp42, 0x1000u, v127, v126);
          applog(7, tmp42, 0);
        }
        noresume ^= 1u;
        free(v126);
LABEL_174:
        if ( !noresume )
          goto LABEL_118;
        if ( pthread_mutex_lock(&v1->data_lock.mutex) )
        {
          v154 = _errno_location();
          LOWORD(v155) = 15984;
          HIWORD(v155) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
          LOWORD(v156) = -968;
          HIWORD(v156) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
          snprintf(tmp42, 0x1000u, v156, *v154, v155, "initiate_stratum", 3608);
          applog(3, tmp42, 1);
          quit(1);
        }
        if ( pthread_rwlock_wrlock(&v1->data_lock.rwlock) )
        {
          v151 = _errno_location();
          LOWORD(v152) = 15984;
          HIWORD(v152) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
          LOWORD(v153) = -1020;
          HIWORD(v153) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
          snprintf(tmp42, 0x1000u, v153, *v151, v152, "initiate_stratum", 3608);
          applog(3, tmp42, 1);
          quit(1);
        }
        free(v1->sessionid);
        free(v1->nonce1);
        v1->nonce1 = 0;
        v1->sessionid = 0;
        if ( pthread_rwlock_unlock(&v1->data_lock.rwlock) )
        {
          v148 = _errno_location();
          LOWORD(v149) = 15984;
          HIWORD(v149) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
          LOWORD(v150) = -348;
          HIWORD(v150) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
          snprintf(tmp42, 0x1000u, v150, *v148, v149, "initiate_stratum", 3612);
          applog(3, tmp42, 1);
          quit(1);
        }
        if ( pthread_mutex_unlock(&v1->data_lock.mutex) )
        {
          v145 = _errno_location();
          LOWORD(v146) = 15984;
          HIWORD(v146) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
          LOWORD(v147) = -920;
          HIWORD(v147) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
          snprintf(tmp42, 0x1000u, v147, *v145, v146, "initiate_stratum", 3612);
          applog(3, tmp42, 1);
          quit(1);
        }
        selective_yield();
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          LOWORD(v128) = 17840;
          HIWORD(v128) = (unsigned int)"xtran2size %d" >> 16;
          v129 = *v128;
          v130 = v128[1];
          v131 = v128[2];
          v132 = v128[3];
          v128 += 4;
          *(_DWORD *)tmp42 = v129;
          *(_DWORD *)&tmp42[4] = v130;
          *(_DWORD *)&tmp42[8] = v131;
          *(_DWORD *)&tmp42[12] = v132;
          v133 = *v128;
          v134 = v128[1];
          v135 = v128[2];
          v136 = v128[3];
          v128 += 4;
          *(_DWORD *)&tmp42[16] = v133;
          *(_DWORD *)&tmp42[20] = v134;
          *(_DWORD *)&tmp42[24] = v135;
          *(_DWORD *)&tmp42[28] = v136;
          v137 = v128[1];
          *(_DWORD *)&tmp42[32] = *v128;
          *(_DWORD *)&tmp42[36] = v137;
          applog(7, tmp42, 0);
        }
        if ( val )
        {
          refcount = val->refcount;
          if ( refcount != -1 )
          {
            v139 = refcount - 1;
            val->refcount = v139;
            if ( !v139 )
              json_delete(val);
          }
        }
        goto LABEL_2;
      }
      timeout = 1;
      v14 = _errno_location();
      if ( *v14 != 115 )
      {
        close(v22);
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          LOWORD(v15) = 16920;
          HIWORD(v15) = (unsigned int)"minated string in recv_line" >> 16;
          v16 = *v15;
          v17 = v15[1];
          v18 = v15[2];
          v19 = v15[3];
          v20 = v15[4];
          *(_DWORD *)tmp42 = v16;
          *(_DWORD *)&tmp42[4] = v17;
          *(_DWORD *)&tmp42[8] = v18;
          *(_DWORD *)&tmp42[12] = v19;
          *(_DWORD *)&tmp42[16] = v20;
          applog(7, tmp42, 0);
        }
        goto LABEL_31;
      }
      LOBYTE(v29) = v22 & 0x1F;
      v30 = (v22 + 31) & (v22 >> 31);
      if ( v22 >= 0 )
        v30 = v22;
      v31 = v30 >> 5;
      if ( v22 <= 0 )
        v29 = -(-v22 & 0x1F);
      v173 = v12;
      v32 = 1 << v29;
      while ( 1 )
      {
        v12 = v173;
        v33 = (fd_set *)&err.text[156];
        do
        {
          v33->fds_bits[1] = 0;
          v33 = (fd_set *)((char *)v33 + 4);
        }
        while ( &writefds.fds_bits[31] != (__fd_mask *)v33 );
        writefds.fds_bits[v31] |= v32;
        v34 = select(v22 + 1, 0, &writefds, 0, (struct timeval *)&timeout);
        if ( v34 > 0 )
          break;
        if ( !v34 || *v14 != 4 )
          goto LABEL_54;
      }
      if ( (v32 & writefds.fds_bits[v31]) != 0 )
      {
        optlen = 4;
        if ( !getsockopt(v22, 1, 4, &optval, &optlen) && !optval )
        {
          v1 = v179;
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            LOWORD(v40) = 16940;
            HIWORD(v40) = (unsigned int)"cv_line" >> 16;
            v41 = *v40;
            v42 = v40[1];
            v43 = v40[2];
            v44 = v40[3];
            v40 += 4;
            *(_DWORD *)tmp42 = v41;
            *(_DWORD *)&tmp42[4] = v42;
            *(_DWORD *)&tmp42[8] = v43;
            *(_DWORD *)&tmp42[12] = v44;
            v45 = v40[1];
            v46 = v40[2];
            *(_DWORD *)&tmp42[16] = *v40;
            *(_DWORD *)&tmp42[20] = v45;
            *(_WORD *)&tmp42[24] = v46;
            applog(7, tmp42, 0);
          }
          goto LABEL_69;
        }
      }
LABEL_54:
      close(v22);
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        break;
LABEL_31:
      v12 = v12->ai_next;
      if ( !v12 )
        goto LABEL_39;
    }
    LOWORD(v35) = 16968;
    HIWORD(v35) = (unsigned int)"o resolve (?wrong URL) %s:%s" >> 16;
    v36 = *v35;
    v37 = v35[1];
    v38 = v35[2];
    v39 = v35[3];
    v35 += 4;
    *(_DWORD *)tmp42 = v36;
    *(_DWORD *)&tmp42[4] = v37;
    *(_DWORD *)&tmp42[8] = v38;
    *(_DWORD *)&tmp42[12] = v39;
    v24 = &tmp42[16];
    v25 = *v35;
    v26 = v35[1];
    v27 = v35[2];
    v28 = v35[3];
LABEL_38:
    *(_DWORD *)v24 = v25;
    *((_DWORD *)v24 + 1) = v26;
    *((_DWORD *)v24 + 2) = v27;
    *((_WORD *)v24 + 6) = v28;
    applog(7, tmp42, 0);
    v12 = v12->ai_next;
  }
  while ( v12 );
LABEL_39:
  v1 = v179;
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
LABEL_94:
  v61 = 0;
  if ( !val )
    return 0;
LABEL_112:
  v80 = val->refcount;
  if ( v80 == -1 )
    return v61;
  v81 = v80 - 1;
  val->refcount = v81;
  if ( v81 )
    return v61;
  json_delete(val);
  return v61;
}
