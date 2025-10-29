// Alternative name is 'parse_method.part.6'
bool __fastcall parse_method_0(pool *pool, char *s)
{
  double v2; // d0
  json_t *v4; // r0
  const char *v5; // r1
  json_t *v6; // r5
  json_t *v7; // r7
  const char *v8; // r1
  json_t *v9; // r0
  const char *v10; // r1
  const json_t *v11; // r8
  json_t *v12; // r4
  const char *v13; // r0
  const char *v14; // r8
  const char *v15; // r1
  int v16; // r7
  const char *v17; // r1
  const char *v18; // r1
  const char *v19; // r1
  const char *v20; // r1
  const char *v21; // r1
  const char *v22; // r1
  const char *v23; // r2
  const char *v24; // r1
  const char *v25; // r1
  json_t *v26; // r0
  int v27; // r0
  const char *v28; // r1
  ssize_t v29; // r0
  json_t *v30; // r0
  size_t refcount; // r3
  size_t v32; // r3
  const char *v34; // r2
  const char *v35; // r2
  void *v36; // r0
  json_t *v37; // r0
  const char *v38; // r2
  int v39; // r3
  double sdiff; // d9
  const char *v41; // r2
  char *v42; // r9
  char *v43; // r8
  char *v44; // r11
  char *v45; // r10
  _BOOL4 v46; // r4
  bool v47; // zf
  bool v48; // zf
  _BOOL4 v49; // r3
  json_t *v50; // r0
  const char *v51; // r8
  char *sockaddr_url; // r10
  char *v53; // r9
  char *v54; // r0
  const char *v55; // r2
  const char *v56; // r1
  const char *v57; // r1
  json_t *v58; // r0
  int v59; // r0
  const char *v60; // r1
  json_t *v61; // r0
  void *stratum_port; // r0
  const char *v63; // r2
  const char *v64; // r2
  const char *v65; // r2
  int v66; // r3
  char *v67; // r3
  char *v68; // r0
  char *v69; // r0
  const char *v70; // r1
  char *v71; // r8
  const char *v72; // r2
  int v73; // r3
  __int64 v74; // kr00_8
  __time_t tv_sec; // r1
  struct timeval v76; // kr08_8
  struct timeval v77; // kr10_8
  json_t *v78; // r0
  const char *v79; // r0
  const char *v80; // r2
  int *v81; // r3
  int v82; // r0
  int v83; // r1
  int v84; // r2
  int v85; // r3
  double next_diff; // d7
  size_t v87; // r4
  size_t v88; // r0
  size_t v89; // r4
  size_t v90; // r0
  _BOOL4 v91; // r3
  int header_len; // r4
  const char *v93; // r2
  const char *v94; // r2
  int64_t v95; // kr18_8
  const char *v96; // r2
  const char *v97; // r2
  struct timezone *v98; // r9
  const char *v99; // r2
  const char *v100; // r2
  const char *v101; // r2
  const char *v102; // r2
  struct timezone *v103; // r1
  char *v104; // r9
  int *v105; // r6
  int v106; // r0
  int v107; // r1
  int v108; // r2
  int v109; // r3
  int v110; // r0
  int v111; // r1
  int v112; // r2
  int v113; // r3
  int v114; // r1
  int *v115; // r0
  const char *v116; // r2
  int *v117; // r0
  const char *v118; // r2
  int *v119; // r0
  int v120; // r3
  const char *v121; // r2
  int v122; // r3
  const char *v123; // r2
  int v124; // r1
  int v125; // r3
  const char *v126; // r2
  const char *v127; // r2
  const char *v128; // r2
  int *v129; // r0
  int v130; // r3
  const char *v131; // r2
  int *v132; // r0
  int v133; // r3
  const char *v134; // r2
  int *v135; // r0
  const char *v136; // r2
  int *v137; // r0
  int v138; // r3
  const char *v139; // r2
  int *v140; // r0
  int v141; // r3
  const char *v142; // r2
  int *v143; // r0
  const char *v144; // r2
  int *v145; // r0
  const char *v146; // r2
  int *v147; // r0
  int v148; // r3
  const char *v149; // r2
  int *v150; // r0
  const char *v151; // r2
  int *v152; // r0
  const char *v153; // r2
  const char *v154; // [sp+14h] [bp-2230h]
  char *v155; // [sp+18h] [bp-222Ch]
  char *ptr; // [sp+1Ch] [bp-2228h]
  char *v157; // [sp+20h] [bp-2224h]
  char *hexstr; // [sp+24h] [bp-2220h]
  int hexstra; // [sp+24h] [bp-2220h]
  cglock_t *mutex; // [sp+30h] [bp-2214h]
  pthread_rwlock_t *rwlock; // [sp+34h] [bp-2210h]
  char *v162; // [sp+3Ch] [bp-2208h] BYREF
  char *sockaddr_port; // [sp+40h] [bp-2204h] BYREF
  json_error_t err; // [sp+44h] [bp-2200h] BYREF
  struct timeval p[32]; // [sp+140h] [bp-2104h] BYREF
  char tmp42[4096]; // [sp+240h] [bp-2004h] BYREF

  v4 = json_loads(s, 0, &err);
  if ( v4 )
  {
    LOWORD(v5) = 17912;
    v6 = v4;
    HIWORD(v5) = (unsigned int)"ams\": []}" >> 16;
    v7 = json_object_get(v4, v5);
    if ( !v7 )
      goto LABEL_22;
    LOWORD(v8) = 2324;
    HIWORD(v8) = (unsigned int)"sharelog printf error" >> 16;
    v9 = json_object_get(v6, v8);
    LOWORD(v10) = 17920;
    v11 = v9;
    HIWORD(v10) = (unsigned int)"}" >> 16;
    v12 = json_object_get(v6, v10);
    if ( v11 && v11->type != JSON_NULL )
    {
      v12 = (json_t *)json_dumps(v11, 3u);
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v35) = 17928;
        HIWORD(v35) = (unsigned int)" mining.extranonce.subscribe failed\n" >> 16;
        snprintf(tmp42, 0x1000u, v35, v12);
        applog(7, tmp42, 0);
      }
      v36 = v12;
      LOBYTE(v12) = 0;
      free(v36);
      goto LABEL_23;
    }
    v13 = json_string_value(v7);
    v14 = v13;
    if ( !v13 )
      goto LABEL_22;
    LOWORD(v15) = 17964;
    HIWORD(v15) = (unsigned int)"" >> 16;
    v16 = strncasecmp(v13, v15, 0xDu);
    if ( v16 )
    {
      LOWORD(v17) = 18324;
      HIWORD(v17) = (unsigned int)"version: %s" >> 16;
      if ( !strncasecmp(v14, v17, 0x15u) )
      {
        LOBYTE(v12) = parse_extranonce_equihash(pool, v12, 0);
        goto LABEL_23;
      }
      LOWORD(v18) = 18348;
      HIWORD(v18) = (unsigned int)"s" >> 16;
      if ( !strncasecmp(v14, v18, 0x15u) )
      {
        v37 = json_array_get(v12, 0);
        json_number_value(v37);
        if ( v2 == 0.0 )
          goto LABEL_22;
        if ( pthread_mutex_lock(&pool->data_lock.mutex) )
          mutex_lock_0((pthread_mutex_t *)&_func___12181, (const char *)0x9B3, v38, v39);
        if ( pthread_rwlock_wrlock(&pool->data_lock.rwlock) )
        {
          v119 = _errno_location();
          LOWORD(v120) = 15984;
          HIWORD(v120) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
          LOWORD(v121) = -1020;
          HIWORD(v121) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
          snprintf(tmp42, 0x1000u, v121, *v119, v120, &_func___12181, 2483);
          applog(3, tmp42, 1);
          quit(1);
        }
        sdiff = pool->sdiff;
        pool->sdiff = v2;
        if ( pthread_rwlock_unlock(&pool->data_lock.rwlock) )
        {
          v117 = _errno_location();
          LOWORD(v118) = -348;
          HIWORD(v118) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
          snprintf(tmp42, 0x1000u, v118, *v117, "util.c", &_func___12181, 2486);
          applog(3, tmp42, 1);
          quit(1);
        }
        if ( pthread_mutex_unlock(&pool->data_lock.mutex) )
        {
          v115 = _errno_location();
          LOWORD(v116) = -920;
          HIWORD(v116) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
          snprintf(tmp42, 0x1000u, v116, *v115, "util.c", &_func___12181, 2486);
          applog(3, tmp42, 1);
          quit(1);
        }
        selective_yield();
        if ( v2 == sdiff )
        {
          LOBYTE(v12) = opt_debug;
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            LOWORD(v99) = 18444;
            HIWORD(v99) = (unsigned int)"e %lu\n" >> 16;
            snprintf(tmp42, 0x1000u, v99, pool->pool_no);
            goto LABEL_50;
          }
        }
        else
        {
          LOBYTE(v12) = opt_debug;
          if ( v2 == (double)(int)v2 )
          {
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              LOWORD(v41) = 18372;
              HIWORD(v41) = (unsigned int)": %s" >> 16;
              snprintf(tmp42, 0x1000u, v41, pool->pool_no, (int)v2);
LABEL_50:
              applog(7, tmp42, 0);
              goto LABEL_23;
            }
          }
          else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            LOWORD(v102) = 18408;
            HIWORD(v102) = (unsigned int)"n: %s" >> 16;
            snprintf(tmp42, 0x1000u, v102, pool->pool_no);
            goto LABEL_50;
          }
        }
LABEL_121:
        LOBYTE(v12) = 1;
        goto LABEL_23;
      }
      LOWORD(v19) = 18476;
      HIWORD(v19) = (unsigned int)"mining.set_difficulty" >> 16;
      if ( strncasecmp(v14, v19, 0x10u) )
      {
        LOWORD(v20) = 18736;
        HIWORD(v20) = (unsigned int)"domain '%s'" >> 16;
        if ( !strncasecmp(v14, v20, 0x12u) )
        {
          LOWORD(v56) = 5072;
          HIWORD(v56) = (unsigned int)"d" >> 16;
          v30 = json_object_get(v6, v56);
          if ( !v30 )
            goto LABEL_21;
          LOWORD(v57) = 5072;
          HIWORD(v57) = (unsigned int)"d" >> 16;
          v58 = json_object_get(v6, v57);
          v59 = json_integer_value(v58);
          LOWORD(v60) = 18756;
          HIWORD(v60) = (unsigned int)"tratum reconnect request to non-matching domain url '%s'" >> 16;
          sprintf(tmp42, v60, v59);
LABEL_20:
          v29 = strlen(tmp42);
          LOBYTE(v30) = stratum_send(pool, tmp42, v29);
LABEL_21:
          LOBYTE(v12) = (_BYTE)v30;
LABEL_23:
          refcount = v6->refcount;
          if ( refcount != -1 )
          {
            v32 = refcount - 1;
            v6->refcount = v32;
            if ( !v32 )
              json_delete(v6);
          }
          return (char)v12;
        }
        LOWORD(v21) = 18812;
        HIWORD(v21) = (unsigned int)"" >> 16;
        if ( strncasecmp(v14, v21, 0x13u) )
        {
          LOWORD(v22) = 18852;
          HIWORD(v22) = (unsigned int)"l %d to %s" >> 16;
          if ( !strncasecmp(v14, v22, 0xBu) )
          {
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              LOWORD(v23) = 18864;
              HIWORD(v23) = (unsigned int)"client.get_version" >> 16;
              snprintf(tmp42, 0x1000u, v23, pool->pool_no);
              applog(7, tmp42, 0);
            }
            LOWORD(v24) = 5072;
            HIWORD(v24) = (unsigned int)"d" >> 16;
            if ( json_object_get(v6, v24) )
            {
              LOWORD(v25) = 5072;
              HIWORD(v25) = (unsigned int)"d" >> 16;
              v26 = json_object_get(v6, v25);
              v27 = json_integer_value(v26);
              LOWORD(v28) = 18880;
              HIWORD(v28) = (unsigned int)"on" >> 16;
              sprintf(tmp42, v28, v27);
              goto LABEL_20;
            }
          }
          else
          {
            LOWORD(v70) = 18924;
            HIWORD(v70) = (unsigned int)"rror\": null}" >> 16;
            if ( !strncasecmp(v14, v70, 0x11u) )
            {
              v71 = json_array_string(v12, 0);
              if ( v71 )
              {
                hex2bin((unsigned __int8 *)p, v71, 0x20u);
                if ( pthread_mutex_lock(&pool->data_lock.mutex) )
                  mutex_lock_0((pthread_mutex_t *)&_func___12266, (const char *)0xA9A, v72, v73);
                if ( pthread_rwlock_wrlock(&pool->data_lock.rwlock) )
                {
                  v147 = _errno_location();
                  LOWORD(v148) = 15984;
                  HIWORD(v148) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
                  LOWORD(v149) = -1020;
                  HIWORD(v149) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
                  snprintf(tmp42, 0x1000u, v149, *v147, v148, &_func___12266, 2714);
                  applog(3, tmp42, 1);
                  quit(1);
                }
                v74 = *(_QWORD *)&p[2].tv_usec;
                *(_DWORD *)pool->Target = bswap32(p[3].tv_usec);
                tv_sec = p[2].tv_sec;
                *(_DWORD *)&pool->Target[4] = bswap32(HIDWORD(v74));
                *(_DWORD *)&pool->Target[8] = bswap32(v74);
                v76 = p[1];
                *(_DWORD *)&pool->Target[12] = bswap32(tv_sec);
                v77 = p[0];
                *(_DWORD *)&pool->Target[16] = bswap32(v76.tv_usec);
                *(_DWORD *)&pool->Target[20] = bswap32(v76.tv_sec);
                *(_DWORD *)&pool->Target[24] = bswap32(v77.tv_usec);
                *(_DWORD *)&pool->Target[28] = bswap32(v77.tv_sec);
                if ( pthread_rwlock_unlock(&pool->data_lock.rwlock) )
                {
                  v145 = _errno_location();
                  LOWORD(v146) = -348;
                  HIWORD(v146) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
                  snprintf(tmp42, 0x1000u, v146, *v145, "util.c", &_func___12266, 2717);
                  applog(3, tmp42, 1);
                  quit(1);
                }
                if ( pthread_mutex_unlock(&pool->data_lock.mutex) )
                {
                  v143 = _errno_location();
                  LOWORD(v144) = -920;
                  HIWORD(v144) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
                  snprintf(tmp42, 0x1000u, v144, *v143, "util.c", &_func___12266, 2717);
                  applog(3, tmp42, 1);
                  quit(1);
                }
                LOBYTE(v12) = 1;
                selective_yield();
                free(v71);
                goto LABEL_23;
              }
              if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
              {
                LOWORD(v105) = 18944;
                HIWORD(v105) = (unsigned int)"nt.show_message" >> 16;
                LOBYTE(v12) = 0;
                v106 = *v105;
                v107 = v105[1];
                v108 = v105[2];
                v109 = v105[3];
                v105 += 4;
                *(_DWORD *)tmp42 = v106;
                *(_DWORD *)&tmp42[4] = v107;
                *(_DWORD *)&tmp42[8] = v108;
                *(_DWORD *)&tmp42[12] = v109;
                v110 = *v105;
                v111 = v105[1];
                v112 = v105[2];
                v113 = v105[3];
                v105 += 4;
                *(_DWORD *)&tmp42[16] = v110;
                *(_DWORD *)&tmp42[20] = v111;
                *(_DWORD *)&tmp42[24] = v112;
                *(_DWORD *)&tmp42[28] = v113;
                v114 = v105[1];
                *(_DWORD *)&tmp42[32] = *v105;
                *(_WORD *)&tmp42[36] = v114;
                applog(7, tmp42, 0);
                goto LABEL_23;
              }
            }
          }
LABEL_22:
          LOBYTE(v12) = 0;
          goto LABEL_23;
        }
        if ( !v12 )
          goto LABEL_22;
        if ( v12->type != JSON_ARRAY )
          goto LABEL_22;
        v78 = json_array_get(v12, 0);
        v79 = json_string_value(v78);
        if ( !v79 )
          goto LABEL_22;
        LOBYTE(v12) = opt_debug;
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          LOWORD(v80) = 18832;
          HIWORD(v80) = (unsigned int)"t requested from pool %d to %s" >> 16;
          snprintf(tmp42, 0x1000u, v80, pool->pool_no, v79);
          goto LABEL_50;
        }
        goto LABEL_121;
      }
      memset(p, 0, 0xFFu);
      v50 = json_array_get(v12, 0);
      v51 = json_string_value(v50);
      if ( v51 )
      {
        sockaddr_url = pool->sockaddr_url;
        v53 = strchr(sockaddr_url, 46);
        if ( !v53 )
        {
          if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
            goto LABEL_22;
          LOWORD(v100) = 18496;
          HIWORD(v100) = (unsigned int)"y" >> 16;
          snprintf(tmp42, 0x1000u, v100, sockaddr_url);
          goto LABEL_92;
        }
        v54 = strchr(v51, 46);
        if ( !v54 )
        {
          if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
            goto LABEL_22;
          LOWORD(v101) = 18560;
          HIWORD(v101) = (unsigned int)"ed to %.1f" >> 16;
          snprintf(tmp42, 0x1000u, v101, v51);
          goto LABEL_92;
        }
        if ( strcmp(v53, v54) )
        {
          if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
            goto LABEL_22;
          LOWORD(v55) = 18620;
          HIWORD(v55) = (unsigned int)"" >> 16;
          snprintf(tmp42, 0x1000u, v55, sockaddr_url);
LABEL_92:
          LOBYTE(v12) = 0;
          applog(3, tmp42, 0);
          goto LABEL_23;
        }
      }
      else
      {
        v51 = pool->sockaddr_url;
      }
      v61 = json_array_get(v12, 1u);
      stratum_port = (void *)json_string_value(v61);
      if ( !stratum_port )
        stratum_port = pool->stratum_port;
      LOWORD(v63) = 17060;
      HIWORD(v63) = (unsigned int)"connect" >> 16;
      snprintf((char *)p, 0xFEu, v63, v51, stratum_port);
      if ( extract_sockaddr((char *)p, &v162, &sockaddr_port) )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 3 )
        {
          LOWORD(v64) = 18688;
          HIWORD(v64) = (unsigned int)"Denied stratum reconnect request to url without domain '%s'" >> 16;
          snprintf(tmp42, 0x1000u, v64, pool->pool_no, p);
          applog(4, tmp42, 0);
        }
        clear_pool_work(pool);
        if ( pthread_mutex_lock(&pool->stratum_lock) )
          mutex_lock_0((pthread_mutex_t *)(&_func___12181.__align + 3), (const char *)0xA51, v65, v66);
        _suspend_stratum(pool);
        v67 = v162;
        v68 = pool->sockaddr_url;
        pool->stratum_url = v162;
        pool->sockaddr_url = v67;
        free(v68);
        v69 = pool->stratum_port;
        pool->stratum_port = sockaddr_port;
        free(v69);
        if ( pthread_mutex_unlock(&pool->stratum_lock) )
        {
          v135 = _errno_location();
          LOWORD(v136) = -920;
          HIWORD(v136) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
          snprintf(tmp42, 0x1000u, v136, *v135, "util.c", &_func___12181.__align + 3, 2650);
          applog(3, tmp42, 1);
          quit(1);
        }
        selective_yield();
        LOBYTE(v12) = restart_stratum(pool);
        goto LABEL_23;
      }
      goto LABEL_22;
    }
    v42 = json_array_string(v12, 0);
    ptr = json_array_string(v12, 1u);
    v43 = json_array_string(v12, 2u);
    v44 = json_array_string(v12, 3u);
    v45 = json_array_string(v12, 4u);
    v155 = json_array_string(v12, 5u);
    v157 = json_array_string(v12, 6u);
    if ( json_array_get(v12, 7u) )
    {
      v46 = json_array_get(v12, 7u)->type == JSON_TRUE;
      v16 = v46;
    }
    else
    {
      LOBYTE(v46) = 0;
    }
    v47 = v43 == 0;
    if ( v43 )
      v47 = v42 == 0;
    if ( v47 )
    {
      if ( !v42 )
      {
LABEL_58:
        if ( v43 )
          free(v43);
        if ( v45 )
          free(v45);
        if ( v44 )
          free(v44);
        if ( ptr )
          free(ptr);
        if ( v157 )
          free(v157);
        if ( v155 )
          free(v155);
        if ( hexstr )
          free(hexstr);
        LOBYTE(v12) = 0;
        pool->stratum_notify = 0;
        goto LABEL_23;
      }
    }
    else
    {
      v48 = v45 == 0;
      if ( v45 )
        v48 = v44 == 0;
      if ( v48 )
        goto LABEL_82;
      v49 = v157 == 0;
      if ( !ptr )
        v49 = 1;
      if ( !v155 )
        v49 = 1;
      if ( v49 )
        goto LABEL_82;
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v81) = 17980;
        HIWORD(v81) = (unsigned int)"sume stratum, trying afresh" >> 16;
        v82 = *v81;
        v83 = v81[1];
        v84 = v81[2];
        v85 = v81[3];
        *(_DWORD *)tmp42 = v82;
        *(_DWORD *)&tmp42[4] = v83;
        *(_DWORD *)&tmp42[8] = v84;
        *(_WORD *)&tmp42[12] = v85;
        applog(7, tmp42, 0);
      }
      mutex = &pool->data_lock;
      if ( pthread_mutex_lock(&pool->data_lock.mutex) )
      {
        v140 = _errno_location();
        LOWORD(v141) = 15984;
        HIWORD(v141) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
        LOWORD(v142) = -968;
        HIWORD(v142) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
        snprintf(tmp42, 0x1000u, v142, *v140, v141, "parse_notify_equihash", 2142);
        applog(3, tmp42, 1);
        quit(1);
      }
      rwlock = &pool->data_lock.rwlock;
      if ( pthread_rwlock_wrlock(&pool->data_lock.rwlock) )
      {
        v137 = _errno_location();
        LOWORD(v138) = 15984;
        HIWORD(v138) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
        LOWORD(v139) = -1020;
        HIWORD(v139) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
        snprintf(tmp42, 0x1000u, v139, *v137, v138, "parse_notify_equihash", 2142);
        applog(3, tmp42, 1);
        quit(1);
      }
      free(pool->swork.job_id);
      free(pool->swork.prev_hash);
      free(pool->swork.bbversion);
      free(pool->swork.nbit);
      free(pool->swork.ntime);
      pool->swork.job_id = v42;
      pool->swork.prev_hash = v43;
      pool->swork.clean = v46;
      pool->swork.bbversion = ptr;
      pool->swork.nbit = v157;
      pool->swork.ntime = v155;
      next_diff = pool->next_diff;
      if ( next_diff > 0.0 )
        pool->swork.diff = next_diff;
      if ( v16 )
        pool->nonce2 = 0;
      v87 = strlen(ptr);
      v88 = strlen(v43);
      pool->merkle_offset = v87 + v88;
      hexstra = (int)(v87 + v88) / 2;
      v89 = strlen(v155);
      v90 = strlen(v157);
      pool->merkle_offset = hexstra;
      v91 = opt_debug;
      header_len = 2 * ((v90 >> 1) + (v89 >> 1) + 84 + hexstra) + 1;
      pool->swork.header_len = header_len;
      if ( v91 && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v93) = 17996;
        HIWORD(v93) = (unsigned int)"ying afresh" >> 16;
        snprintf(tmp42, 0x1000u, v93, "parse_notify_equihash", header_len);
        applog(7, tmp42, 0);
        header_len = pool->swork.header_len;
      }
      if ( header_len << 30 )
      {
        header_len = (header_len & 0xFFFFFFFC) + 4;
        pool->swork.header_len = header_len;
      }
      hexstr = (char *)malloc(header_len);
      if ( !hexstr )
      {
        LOWORD(v122) = 15984;
        HIWORD(v122) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
        LOWORD(v123) = 18028;
        HIWORD(v123) = (unsigned int)"led" >> 16;
        snprintf(tmp42, 0x1000u, v123, "parse_notify_equihash", v122, "parse_notify_equihash", 2188);
        applog(3, tmp42, 1);
        quit(1);
      }
      LOWORD(v94) = 18088;
      HIWORD(v94) = (unsigned int)"s" >> 16;
      v154 = v94;
      LOWORD(v94) = 18072;
      HIWORD(v94) = (unsigned int)"decode failed: %s" >> 16;
      snprintf(
        hexstr,
        header_len,
        v94,
        pool->swork.bbversion,
        pool->swork.prev_hash,
        v44,
        v45,
        pool->swork.ntime,
        pool->swork.nbit,
        v154);
      v12 = (json_t *)hex2bin(pool->header_bin, hexstr, 0x80u);
      if ( v12 )
      {
        v95 = total_getworks;
        ++pool->getwork_requested;
        total_getworks = v95 + 1;
        if ( pthread_rwlock_unlock(rwlock) )
        {
          v132 = _errno_location();
          LOWORD(v133) = 15984;
          HIWORD(v133) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
          LOWORD(v134) = -348;
          HIWORD(v134) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
          snprintf(tmp42, 0x1000u, v134, *v132, v133, "parse_notify_equihash", 2214);
          applog(3, tmp42, 1);
          quit(1);
        }
        if ( pthread_mutex_unlock(&mutex->mutex) )
        {
          v129 = _errno_location();
          LOWORD(v130) = 15984;
          HIWORD(v130) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
          LOWORD(v131) = -920;
          HIWORD(v131) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
          snprintf(tmp42, 0x1000u, v131, *v129, v130, "parse_notify_equihash", 2214);
          applog(3, tmp42, 1);
          quit(1);
        }
        selective_yield();
        if ( pool == current_pool() )
          opt_work_update = 1;
        if ( !opt_protocol )
          goto LABEL_163;
        if ( opt_debug )
        {
          if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
            goto LABEL_152;
          LOWORD(v128) = 18184;
          HIWORD(v128) = (unsigned int)" in %s %s():%d" >> 16;
          snprintf(tmp42, 0x1000u, v128, v42);
          applog(7, tmp42, 0);
          if ( !opt_debug )
          {
LABEL_220:
            if ( !opt_debug )
              goto LABEL_163;
            if ( use_syslog )
            {
LABEL_211:
              snprintf(tmp42, 0x1000u, "nbit: %s", v157);
              applog(7, tmp42, 0);
LABEL_212:
              if ( !opt_debug )
                goto LABEL_163;
              if ( use_syslog )
              {
LABEL_200:
                snprintf(tmp42, 0x1000u, "ntime: %s", v155);
                applog(7, tmp42, 0);
LABEL_201:
                if ( !opt_debug )
                  goto LABEL_163;
                if ( use_syslog )
                {
LABEL_203:
                  LOWORD(v124) = 17908;
                  LOWORD(v125) = 17904;
                  HIWORD(v125) = (unsigned int)"e\", \"params\": []}" >> 16;
                  if ( !v16 )
                  {
                    HIWORD(v124) = (unsigned int)"\"params\": []}" >> 16;
                    v125 = v124;
                  }
                  LOWORD(v126) = 18276;
                  HIWORD(v126) = (unsigned int)"nvert header to header_bin, got %s" >> 16;
                  snprintf(tmp42, 0x1000u, v126, v125);
                  applog(7, tmp42, 0);
                  goto LABEL_163;
                }
LABEL_216:
                if ( !opt_log_output && opt_log_level <= 6 )
                  goto LABEL_163;
                goto LABEL_203;
              }
LABEL_214:
              if ( !opt_log_output && opt_log_level <= 6 )
                goto LABEL_216;
              goto LABEL_200;
            }
LABEL_209:
            if ( !opt_log_output && opt_log_level <= 6 )
              goto LABEL_214;
            goto LABEL_211;
          }
          if ( !use_syslog )
          {
LABEL_152:
            if ( !opt_log_output && opt_log_level <= 6 )
              goto LABEL_156;
          }
          LOWORD(v96) = 18196;
          HIWORD(v96) = (unsigned int)"%d" >> 16;
          snprintf(tmp42, 0x1000u, v96, ptr);
          applog(7, tmp42, 0);
          if ( !opt_debug )
            goto LABEL_212;
          if ( !use_syslog )
          {
LABEL_156:
            if ( !opt_log_output && opt_log_level <= 6 )
              goto LABEL_160;
          }
          LOWORD(v97) = 18208;
          HIWORD(v97) = (unsigned int)"%s%s%s" >> 16;
          snprintf(tmp42, 0x1000u, v97, v43);
          applog(7, tmp42, 0);
          if ( !opt_debug )
            goto LABEL_201;
          if ( !use_syslog )
          {
LABEL_160:
            if ( !opt_log_output && opt_log_level <= 6 )
              goto LABEL_207;
          }
          snprintf(tmp42, 0x1000u, "merkle: %s", v44);
          applog(7, tmp42, 0);
        }
        if ( !opt_debug )
        {
LABEL_163:
          v98 = (struct timezone *)(unsigned __int8)set_os_time_12121;
          if ( !set_os_time_12121 )
          {
            hex2bin((unsigned __int8 *)&sockaddr_port, v155, 4u);
            v103 = v98;
            v104 = sockaddr_port;
            gettimeofday(p, v103);
            if ( use_syslog || opt_log_output || opt_log_level > 4 )
            {
              snprintf(tmp42, 0x1000u, "stime.tv_sec %lu, block_ntime %lu\n", p[0].tv_sec, v104);
              applog(5, tmp42, 0);
            }
            if ( (unsigned int)v104 > p[0].tv_sec + 3600 )
            {
              p[0].tv_sec = (__time_t)v104;
              settimeofday(p, 0);
            }
            set_os_time_12121 = 1;
          }
          free(hexstr);
          pool->stratum_notify = 1;
          goto LABEL_23;
        }
        if ( use_syslog )
        {
LABEL_219:
          LOWORD(v127) = 18236;
          HIWORD(v127) = (unsigned int)"00000000000000000000" >> 16;
          snprintf(tmp42, 0x1000u, v127, v45);
          applog(7, tmp42, 0);
          goto LABEL_220;
        }
LABEL_207:
        if ( !opt_log_output && opt_log_level <= 6 )
          goto LABEL_209;
        goto LABEL_219;
      }
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        snprintf(tmp42, 0x1000u, "%s: Failed to convert header to header_bin, got %s", "parse_notify_equihash", hexstr);
        applog(4, tmp42, 0);
      }
      if ( pthread_rwlock_unlock(rwlock) )
      {
        v152 = _errno_location();
        LOWORD(v153) = -348;
        HIWORD(v153) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
        snprintf(tmp42, 0x1000u, v153, *v152, "util.c", "parse_notify_equihash", 2205);
        applog(3, tmp42, 1);
        quit(1);
      }
      if ( pthread_mutex_unlock(&mutex->mutex) )
      {
        v150 = _errno_location();
        LOWORD(v151) = -920;
        HIWORD(v151) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
        snprintf(tmp42, 0x1000u, v151, *v150, "util.c", "parse_notify_equihash", 2205);
        applog(3, tmp42, 1);
        quit(1);
      }
      selective_yield();
      pool_failed(pool);
    }
LABEL_82:
    free(v42);
    goto LABEL_58;
  }
  LOBYTE(v12) = opt_debug;
  if ( opt_debug && (use_syslog || (LOBYTE(v12) = opt_log_output) != 0 || opt_log_level > 6) )
  {
    LOWORD(v34) = 5036;
    HIWORD(v34) = (unsigned int)"tum connection to pool %d interrupted" >> 16;
    LOBYTE(v12) = 0;
    snprintf(tmp42, 0x1000u, v34, err.line, err.text);
    applog(7, tmp42, 0);
  }
  return (char)v12;
}
