// Alternative name is 'parse_method.part.6'
bool __fastcall parse_method_0(pool *pool, char *s)
{
  double v2; // d0
  json_t *v4; // r0
  json_t *v5; // r5
  json_t *v6; // r7
  json_t *v7; // r8
  json_t *v8; // r4
  const char *v9; // r0
  const char *v10; // r8
  int v11; // r7
  json_t *v12; // r0
  int v13; // r0
  ssize_t v14; // r0
  json_t *v15; // r0
  size_t refcount; // r3
  size_t v17; // r3
  void *v19; // r0
  json_t *v20; // r0
  const char *v21; // r2
  int v22; // r3
  double sdiff; // d9
  char *v24; // r9
  char *v25; // r8
  char *v26; // r11
  char *v27; // r10
  _BOOL4 v28; // r4
  bool v29; // zf
  bool v30; // zf
  _BOOL4 v31; // r3
  json_t *v32; // r0
  const char *v33; // r8
  char *sockaddr_url; // r10
  char *v35; // r9
  char *v36; // r0
  json_t *v37; // r0
  int v38; // r0
  json_t *v39; // r0
  const char *stratum_port; // r0
  const char *v41; // r2
  int v42; // r3
  char *v43; // r3
  char *v44; // r0
  char *v45; // r0
  char *v46; // r8
  const char *v47; // r2
  int v48; // r3
  __int64 v49; // kr00_8
  __time_t tv_sec; // r1
  struct timeval v51; // kr08_8
  struct timeval v52; // kr10_8
  json_t *v53; // r0
  const char *v54; // r0
  double next_diff; // d7
  size_t v56; // r4
  size_t v57; // r0
  size_t v58; // r4
  size_t v59; // r0
  _BOOL4 v60; // r3
  int header_len; // r4
  int64_t v62; // kr18_8
  struct timezone *v63; // r9
  struct timezone *v64; // r1
  char *v65; // r9
  int *v66; // r0
  int *v67; // r0
  int *v68; // r0
  const char *v69; // r3
  int *v70; // r0
  int *v71; // r0
  int *v72; // r0
  int *v73; // r0
  int *v74; // r0
  int *v75; // r0
  int *v76; // r0
  int *v77; // r0
  int *v78; // r0
  int *v79; // r0
  char *v80; // [sp+18h] [bp-222Ch]
  char *ptr; // [sp+1Ch] [bp-2228h]
  char *v82; // [sp+20h] [bp-2224h]
  char *hexstr; // [sp+24h] [bp-2220h]
  int hexstra; // [sp+24h] [bp-2220h]
  cglock_t *mutex; // [sp+30h] [bp-2214h]
  pthread_rwlock_t *rwlock; // [sp+34h] [bp-2210h]
  char *v87; // [sp+3Ch] [bp-2208h] BYREF
  char *sockaddr_port; // [sp+40h] [bp-2204h] BYREF
  json_error_t err; // [sp+44h] [bp-2200h] BYREF
  struct timeval p[32]; // [sp+140h] [bp-2104h] BYREF
  char tmp42[8196]; // [sp+240h] [bp-2004h] BYREF

  v4 = json_loads(s, 0, &err);
  if ( v4 )
  {
    v5 = v4;
    v6 = json_object_get(v4, "method");
    if ( !v6 )
      goto LABEL_22;
    v7 = json_object_get(v5, "error");
    v8 = json_object_get(v5, "params");
    if ( v7 && v7->type != JSON_NULL )
    {
      v8 = (json_t *)json_dumps(v7, 3u);
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42, 0x1000u, "JSON-RPC method decode failed: %s", (const char *)v8);
        applog(7, tmp42, 0);
      }
      v19 = v8;
      LOBYTE(v8) = 0;
      free(v19);
      goto LABEL_23;
    }
    v9 = json_string_value(v6);
    v10 = v9;
    if ( !v9 )
      goto LABEL_22;
    v11 = strncasecmp(v9, "mining.notify", 0xDu);
    if ( v11 )
    {
      if ( !strncasecmp(v10, "mining.set_extranonce", 0x15u) )
      {
        LOBYTE(v8) = parse_extranonce_equihash(pool, v8, 0);
        goto LABEL_23;
      }
      if ( !strncasecmp(v10, "mining.set_difficulty", 0x15u) )
      {
        v20 = json_array_get(v8, 0);
        json_number_value(v20);
        if ( v2 == 0.0 )
          goto LABEL_22;
        if ( pthread_mutex_lock(&pool->data_lock.mutex) )
          mutex_lock_0((pthread_mutex_t *)&_func___12181, (const char *)0x9B3, v21, v22);
        if ( pthread_rwlock_wrlock(&pool->data_lock.rwlock) )
        {
          v68 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
            *v68,
            "util.c",
            (const char *)&_func___12181,
            2483);
          applog(3, tmp42, 1);
          quit(1);
        }
        sdiff = pool->sdiff;
        pool->sdiff = v2;
        if ( pthread_rwlock_unlock(&pool->data_lock.rwlock) )
        {
          v67 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
            *v67,
            "util.c",
            (const char *)&_func___12181,
            2486);
          applog(3, tmp42, 1);
          quit(1);
        }
        if ( pthread_mutex_unlock(&pool->data_lock.mutex) )
        {
          v66 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
            *v66,
            "util.c",
            (const char *)&_func___12181,
            2486);
          applog(3, tmp42, 1);
          quit(1);
        }
        selective_yield();
        if ( v2 == sdiff )
        {
          LOBYTE(v8) = opt_debug;
          if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            snprintf(tmp42, 0x1000u, "Pool %d difficulty set to %f", pool->pool_no, v2);
            goto LABEL_50;
          }
        }
        else
        {
          LOBYTE(v8) = opt_debug;
          if ( v2 == (double)(int)v2 )
          {
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              snprintf(tmp42, 0x1000u, "Pool %d difficulty changed to %d", pool->pool_no, (int)v2);
LABEL_50:
              applog(7, tmp42, 0);
              goto LABEL_23;
            }
          }
          else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            snprintf(tmp42, 0x1000u, "Pool %d difficulty changed to %.1f", pool->pool_no, v2);
            goto LABEL_50;
          }
        }
LABEL_121:
        LOBYTE(v8) = 1;
        goto LABEL_23;
      }
      if ( strncasecmp(v10, "client.reconnect", 0x10u) )
      {
        if ( !strncasecmp(v10, "client.get_version", 0x12u) )
        {
          v15 = json_object_get(v5, "id");
          if ( !v15 )
            goto LABEL_21;
          v37 = json_object_get(v5, "id");
          v38 = json_integer_value(v37);
          sprintf(tmp42, "{\"id\": %d, \"result\": \"cgminer/4.9.0\", \"error\": null}", v38);
LABEL_20:
          v14 = strlen(tmp42);
          LOBYTE(v15) = stratum_send(pool, tmp42, v14);
LABEL_21:
          LOBYTE(v8) = (_BYTE)v15;
LABEL_23:
          refcount = v5->refcount;
          if ( refcount != -1 )
          {
            v17 = refcount - 1;
            v5->refcount = v17;
            if ( !v17 )
              json_delete(v5);
          }
          return (char)v8;
        }
        if ( strncasecmp(v10, "client.show_message", 0x13u) )
        {
          if ( !strncasecmp(v10, "mining.ping", 0xBu) )
          {
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              snprintf(tmp42, 0x1000u, "Pool %d ping", pool->pool_no);
              applog(7, tmp42, 0);
            }
            if ( json_object_get(v5, "id") )
            {
              v12 = json_object_get(v5, "id");
              v13 = json_integer_value(v12);
              sprintf(tmp42, "{\"id\": %d, \"result\": \"pong\", \"error\": null}", v13);
              goto LABEL_20;
            }
          }
          else if ( !strncasecmp(v10, "mining.set_target", 0x11u) )
          {
            v46 = json_array_string(v8, 0);
            if ( v46 )
            {
              hex2bin((unsigned __int8 *)p, v46, 0x20u);
              if ( pthread_mutex_lock(&pool->data_lock.mutex) )
                mutex_lock_0((pthread_mutex_t *)&_func___12266, (const char *)0xA9A, v47, v48);
              if ( pthread_rwlock_wrlock(&pool->data_lock.rwlock) )
              {
                v77 = _errno_location();
                snprintf(
                  tmp42,
                  0x1000u,
                  "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
                  *v77,
                  "util.c",
                  (const char *)&_func___12266,
                  2714);
                applog(3, tmp42, 1);
                quit(1);
              }
              v49 = *(_QWORD *)&p[2].tv_usec;
              *(_DWORD *)pool->Target = bswap32(p[3].tv_usec);
              tv_sec = p[2].tv_sec;
              *(_DWORD *)&pool->Target[4] = bswap32(HIDWORD(v49));
              *(_DWORD *)&pool->Target[8] = bswap32(v49);
              v51 = p[1];
              *(_DWORD *)&pool->Target[12] = bswap32(tv_sec);
              v52 = p[0];
              *(_DWORD *)&pool->Target[16] = bswap32(v51.tv_usec);
              *(_DWORD *)&pool->Target[20] = bswap32(v51.tv_sec);
              *(_DWORD *)&pool->Target[24] = bswap32(v52.tv_usec);
              *(_DWORD *)&pool->Target[28] = bswap32(v52.tv_sec);
              if ( pthread_rwlock_unlock(&pool->data_lock.rwlock) )
              {
                v76 = _errno_location();
                snprintf(
                  tmp42,
                  0x1000u,
                  "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                  *v76,
                  "util.c",
                  (const char *)&_func___12266,
                  2717);
                applog(3, tmp42, 1);
                quit(1);
              }
              if ( pthread_mutex_unlock(&pool->data_lock.mutex) )
              {
                v75 = _errno_location();
                snprintf(
                  tmp42,
                  0x1000u,
                  "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
                  *v75,
                  "util.c",
                  (const char *)&_func___12266,
                  2717);
                applog(3, tmp42, 1);
                quit(1);
              }
              LOBYTE(v8) = 1;
              selective_yield();
              free(v46);
              goto LABEL_23;
            }
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              LOBYTE(v8) = 0;
              strcpy(tmp42, "parse_target: Missing an array value.");
              applog(7, tmp42, 0);
              goto LABEL_23;
            }
          }
LABEL_22:
          LOBYTE(v8) = 0;
          goto LABEL_23;
        }
        if ( !v8 )
          goto LABEL_22;
        if ( v8->type != JSON_ARRAY )
          goto LABEL_22;
        v53 = json_array_get(v8, 0);
        v54 = json_string_value(v53);
        if ( !v54 )
          goto LABEL_22;
        LOBYTE(v8) = opt_debug;
        if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(tmp42, 0x1000u, "Pool %d message: %s", pool->pool_no, v54);
          goto LABEL_50;
        }
        goto LABEL_121;
      }
      memset(p, 0, 0xFFu);
      v32 = json_array_get(v8, 0);
      v33 = json_string_value(v32);
      if ( v33 )
      {
        sockaddr_url = pool->sockaddr_url;
        v35 = strchr(sockaddr_url, 46);
        if ( !v35 )
        {
          if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
            goto LABEL_22;
          snprintf(tmp42, 0x1000u, "Denied stratum reconnect request for pool without domain '%s'", sockaddr_url);
          goto LABEL_92;
        }
        v36 = strchr(v33, 46);
        if ( !v36 )
        {
          if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
            goto LABEL_22;
          snprintf(tmp42, 0x1000u, "Denied stratum reconnect request to url without domain '%s'", v33);
          goto LABEL_92;
        }
        if ( strcmp(v35, v36) )
        {
          if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
            goto LABEL_22;
          snprintf(tmp42, 0x1000u, "Denied stratum reconnect request to non-matching domain url '%s'", sockaddr_url);
LABEL_92:
          LOBYTE(v8) = 0;
          applog(3, tmp42, 0);
          goto LABEL_23;
        }
      }
      else
      {
        v33 = pool->sockaddr_url;
      }
      v39 = json_array_get(v8, 1u);
      stratum_port = json_string_value(v39);
      if ( !stratum_port )
        stratum_port = pool->stratum_port;
      snprintf((char *)p, 0xFEu, "%s:%s", v33, stratum_port);
      if ( extract_sockaddr((char *)p, &v87, &sockaddr_port) )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 3 )
        {
          snprintf(tmp42, 0x1000u, "Stratum reconnect requested from pool %d to %s", pool->pool_no, (const char *)p);
          applog(4, tmp42, 0);
        }
        clear_pool_work(pool);
        if ( pthread_mutex_lock(&pool->stratum_lock) )
          mutex_lock_0((pthread_mutex_t *)(&_func___12181.__align + 3), (const char *)0xA51, v41, v42);
        _suspend_stratum(pool);
        v43 = v87;
        v44 = pool->sockaddr_url;
        pool->stratum_url = v87;
        pool->sockaddr_url = v43;
        free(v44);
        v45 = pool->stratum_port;
        pool->stratum_port = sockaddr_port;
        free(v45);
        if ( pthread_mutex_unlock(&pool->stratum_lock) )
        {
          v72 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
            *v72,
            "util.c",
            &_func___12181.__size[12],
            2650);
          applog(3, tmp42, 1);
          quit(1);
        }
        selective_yield();
        LOBYTE(v8) = restart_stratum(pool);
        goto LABEL_23;
      }
      goto LABEL_22;
    }
    v24 = json_array_string(v8, 0);
    ptr = json_array_string(v8, 1u);
    v25 = json_array_string(v8, 2u);
    v26 = json_array_string(v8, 3u);
    v27 = json_array_string(v8, 4u);
    v80 = json_array_string(v8, 5u);
    v82 = json_array_string(v8, 6u);
    if ( json_array_get(v8, 7u) )
    {
      v28 = json_array_get(v8, 7u)->type == JSON_TRUE;
      v11 = v28;
    }
    else
    {
      LOBYTE(v28) = 0;
    }
    v29 = v25 == 0;
    if ( v25 )
      v29 = v24 == 0;
    if ( v29 )
    {
      if ( !v24 )
      {
LABEL_58:
        if ( v25 )
          free(v25);
        if ( v27 )
          free(v27);
        if ( v26 )
          free(v26);
        if ( ptr )
          free(ptr);
        if ( v82 )
          free(v82);
        if ( v80 )
          free(v80);
        if ( hexstr )
          free(hexstr);
        LOBYTE(v8) = 0;
        pool->stratum_notify = 0;
        goto LABEL_23;
      }
    }
    else
    {
      v30 = v27 == 0;
      if ( v27 )
        v30 = v26 == 0;
      if ( v30 )
        goto LABEL_82;
      v31 = v82 == 0;
      if ( !ptr )
        v31 = 1;
      if ( !v80 )
        v31 = 1;
      if ( v31 )
        goto LABEL_82;
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        strcpy(tmp42, "Valid Notify\n");
        applog(7, tmp42, 0);
      }
      mutex = &pool->data_lock;
      if ( pthread_mutex_lock(&pool->data_lock.mutex) )
      {
        v74 = _errno_location();
        snprintf(
          tmp42,
          0x1000u,
          "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
          *v74,
          "util.c",
          "parse_notify_equihash",
          2142);
        applog(3, tmp42, 1);
        quit(1);
      }
      rwlock = &pool->data_lock.rwlock;
      if ( pthread_rwlock_wrlock(&pool->data_lock.rwlock) )
      {
        v73 = _errno_location();
        snprintf(
          tmp42,
          0x1000u,
          "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
          *v73,
          "util.c",
          "parse_notify_equihash",
          2142);
        applog(3, tmp42, 1);
        quit(1);
      }
      free(pool->swork.job_id);
      free(pool->swork.prev_hash);
      free(pool->swork.bbversion);
      free(pool->swork.nbit);
      free(pool->swork.ntime);
      pool->swork.job_id = v24;
      pool->swork.prev_hash = v25;
      pool->swork.clean = v28;
      pool->swork.bbversion = ptr;
      pool->swork.nbit = v82;
      pool->swork.ntime = v80;
      next_diff = pool->next_diff;
      if ( next_diff > 0.0 )
        pool->swork.diff = next_diff;
      if ( v11 )
        pool->nonce2 = 0;
      v56 = strlen(ptr);
      v57 = strlen(v25);
      pool->merkle_offset = v56 + v57;
      hexstra = (int)(v56 + v57) / 2;
      v58 = strlen(v80);
      v59 = strlen(v82);
      pool->merkle_offset = hexstra;
      v60 = opt_debug;
      header_len = 2 * ((v59 >> 1) + (v58 >> 1) + 84 + hexstra) + 1;
      pool->swork.header_len = header_len;
      if ( v60 && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42, 0x1000u, "%s: pool->swork.header_len = %d", "parse_notify_equihash", header_len);
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
        snprintf(
          tmp42,
          0x1000u,
          "%s: Failed to malloc header. in %s %s():%d",
          "parse_notify_equihash",
          "util.c",
          "parse_notify_equihash",
          2188);
        applog(3, tmp42, 1);
        quit(1);
      }
      snprintf(
        hexstr,
        header_len,
        "%s%s%s%s%s%s%s",
        pool->swork.bbversion,
        pool->swork.prev_hash,
        v26,
        v27,
        pool->swork.ntime,
        pool->swork.nbit,
        "0000000000000000000000000000000000000000");
      v8 = (json_t *)hex2bin(pool->header_bin, hexstr, 0x80u);
      if ( v8 )
      {
        v62 = total_getworks;
        ++pool->getwork_requested;
        total_getworks = v62 + 1;
        if ( pthread_rwlock_unlock(rwlock) )
        {
          v71 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
            *v71,
            "util.c",
            "parse_notify_equihash",
            2214);
          applog(3, tmp42, 1);
          quit(1);
        }
        if ( pthread_mutex_unlock(&mutex->mutex) )
        {
          v70 = _errno_location();
          snprintf(
            tmp42,
            0x1000u,
            "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
            *v70,
            "util.c",
            "parse_notify_equihash",
            2214);
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
          snprintf(tmp42, 0x1000u, "job_id: %s", v24);
          applog(7, tmp42, 0);
          if ( !opt_debug )
          {
LABEL_220:
            if ( !opt_debug )
              goto LABEL_163;
            if ( use_syslog )
            {
LABEL_211:
              snprintf(tmp42, 0x1000u, "nbit: %s", v82);
              applog(7, tmp42, 0);
LABEL_212:
              if ( !opt_debug )
                goto LABEL_163;
              if ( use_syslog )
              {
LABEL_200:
                snprintf(tmp42, 0x1000u, "ntime: %s", v80);
                applog(7, tmp42, 0);
LABEL_201:
                if ( !opt_debug )
                  goto LABEL_163;
                if ( use_syslog )
                {
LABEL_203:
                  v69 = "yes";
                  if ( !v11 )
                    v69 = (const char *)&dword_54574;
                  snprintf(tmp42, 0x1000u, "clean: %s", v69);
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
          snprintf(tmp42, 0x1000u, "version: %s", ptr);
          applog(7, tmp42, 0);
          if ( !opt_debug )
            goto LABEL_212;
          if ( !use_syslog )
          {
LABEL_156:
            if ( !opt_log_output && opt_log_level <= 6 )
              goto LABEL_160;
          }
          snprintf(tmp42, 0x1000u, "prev_hash: %s", v25);
          applog(7, tmp42, 0);
          if ( !opt_debug )
            goto LABEL_201;
          if ( !use_syslog )
          {
LABEL_160:
            if ( !opt_log_output && opt_log_level <= 6 )
              goto LABEL_207;
          }
          snprintf(tmp42, 0x1000u, "merkle: %s", v26);
          applog(7, tmp42, 0);
        }
        if ( !opt_debug )
        {
LABEL_163:
          v63 = (struct timezone *)(unsigned __int8)set_os_time_12121;
          if ( !set_os_time_12121 )
          {
            hex2bin((unsigned __int8 *)&sockaddr_port, v80, 4u);
            v64 = v63;
            v65 = sockaddr_port;
            gettimeofday(p, v64);
            if ( use_syslog || opt_log_output || opt_log_level > 4 )
            {
              snprintf(tmp42, 0x1000u, "stime.tv_sec %lu, block_ntime %lu\n", p[0].tv_sec, v65);
              applog(5, tmp42, 0);
            }
            if ( (unsigned int)v65 > p[0].tv_sec + 3600 )
            {
              p[0].tv_sec = (__time_t)v65;
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
          snprintf(tmp42, 0x1000u, "reserved: %s", v27);
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
        v79 = _errno_location();
        snprintf(
          tmp42,
          0x1000u,
          "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
          *v79,
          "util.c",
          "parse_notify_equihash",
          2205);
        applog(3, tmp42, 1);
        quit(1);
      }
      if ( pthread_mutex_unlock(&mutex->mutex) )
      {
        v78 = _errno_location();
        snprintf(
          tmp42,
          0x1000u,
          "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
          *v78,
          "util.c",
          "parse_notify_equihash",
          2205);
        applog(3, tmp42, 1);
        quit(1);
      }
      selective_yield();
      pool_failed(pool);
    }
LABEL_82:
    free(v24);
    goto LABEL_58;
  }
  LOBYTE(v8) = opt_debug;
  if ( opt_debug && (use_syslog || (LOBYTE(v8) = opt_log_output) != 0 || opt_log_level > 6) )
  {
    LOBYTE(v8) = 0;
    snprintf(tmp42, 0x1000u, "JSON decode failed(%d): %s", err.line, err.text);
    applog(7, tmp42, 0);
  }
  return (char)v8;
}
