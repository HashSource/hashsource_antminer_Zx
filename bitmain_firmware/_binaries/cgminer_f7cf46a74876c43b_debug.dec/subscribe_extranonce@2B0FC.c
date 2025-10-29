bool __fastcall subscribe_extranonce(pool *pool)
{
  int v2; // r2
  ssize_t v3; // r0
  _BOOL4 v4; // r7
  char *v5; // r0
  char *v6; // r4
  _BOOL4 v7; // r6
  json_t *v8; // r8
  json_t *v9; // r7
  json_t *v10; // r0
  const json_t *v11; // r4
  const char *v12; // r7
  char *v13; // r4
  size_t refcount; // r3
  size_t v15; // r3
  char *v16; // r0
  json_error_t err; // [sp+Ch] [bp-30FCh] BYREF
  char tmp42[4096]; // [sp+108h] [bp-3000h] BYREF
  char s[8192]; // [sp+1108h] [bp-2000h] BYREF

  v2 = swork_id++;
  sprintf(s, "{\"id\": %d, \"method\": \"mining.extranonce.subscribe\", \"params\": []}", v2);
  v3 = strlen(s);
  v4 = stratum_send(pool, s, v3);
  if ( v4 )
  {
    while ( 1 )
    {
      v7 = socket_full(pool->sock, 2);
      if ( !v7 )
      {
        if ( opt_debug )
        {
          if ( use_syslog || opt_log_output || opt_log_level > 6 )
          {
            LOBYTE(v4) = opt_debug;
            strcpy(tmp42, "Timed out waiting for response extranonce.subscribe");
            applog(7, tmp42, 0);
          }
          else
          {
            LOBYTE(v4) = opt_debug;
          }
        }
        goto LABEL_11;
      }
      v5 = recv_line(pool);
      v6 = v5;
      if ( !v5 )
        return (char)v5;
      if ( !parse_method_0(pool, v5) )
        break;
      free(v6);
    }
    v8 = json_loads(v6, 0, &err);
    free(v6);
    v9 = json_object_get(v8, "result");
    v10 = json_object_get(v8, "error");
    v11 = v10;
    if ( !v9 || v9->type == JSON_FALSE )
    {
      if ( !v10 )
      {
        v16 = (char *)malloc(0x11u);
        v13 = v16;
        if ( v16 )
          strcpy(v16, "(unknown reason)");
        goto LABEL_32;
      }
    }
    else if ( !v10 || v10->type == JSON_NULL )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 5 )
      {
        LOBYTE(v4) = v7;
        snprintf(tmp42, 0x1000u, "Stratum extranonce subscribe for pool %d", pool->pool_no);
        applog(6, tmp42, 0);
        goto LABEL_25;
      }
LABEL_44:
      LOBYTE(v4) = v7;
      goto LABEL_25;
    }
    v12 = _json_array_string(v10, 1u);
    if ( !v12 && (v12 = json_string_value(v11)) == 0
      || strcmp(v12, "Method 'subscribe' not found for service 'mining.extranonce'")
      && strcmp(v12, "Unrecognized request provided") )
    {
      v13 = json_dumps(v11, 3u);
LABEL_32:
      if ( use_syslog || opt_log_output || opt_log_level > 5 )
      {
        snprintf(tmp42, 0x1000u, "Pool %d JSON extranonce subscribe failed: %s", pool->pool_no, v13);
        applog(6, tmp42, 0);
      }
      LOBYTE(v4) = 0;
      free(v13);
      goto LABEL_25;
    }
    if ( use_syslog || opt_log_output || opt_log_level > 5 )
    {
      LOBYTE(v4) = v7;
      snprintf(tmp42, 0x1000u, "Cannot subscribe to mining.extranonce for pool %d", pool->pool_no);
      applog(6, tmp42, 0);
LABEL_25:
      if ( v8 )
      {
        refcount = v8->refcount;
        if ( refcount != -1 )
        {
          v15 = refcount - 1;
          v8->refcount = v15;
          if ( !v15 )
            json_delete(v8);
        }
      }
      goto LABEL_11;
    }
    goto LABEL_44;
  }
LABEL_11:
  LOBYTE(v5) = v4;
  return (char)v5;
}
