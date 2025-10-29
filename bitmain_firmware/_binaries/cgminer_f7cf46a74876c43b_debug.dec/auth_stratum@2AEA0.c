bool __fastcall auth_stratum(pool *pool)
{
  char *rpc_user; // r3
  int v3; // r2
  ssize_t v4; // r0
  _BOOL4 v5; // r8
  _BOOL4 v6; // r6
  char *v7; // r0
  char *v8; // r4
  json_t *v10; // r9
  json_t *v11; // r4
  json_t *v12; // r0
  char *v13; // r4
  size_t refcount; // r3
  size_t v15; // r3
  char *v16; // r0
  int v17; // r3
  int v18; // r2
  ssize_t v19; // r0
  int v20; // r2
  ssize_t v21; // r0
  char *rpc_pass; // [sp+0h] [bp-310Ch]
  json_error_t err; // [sp+Ch] [bp-3100h] BYREF
  char tmp42[4096]; // [sp+108h] [bp-3004h] BYREF
  char s[8196]; // [sp+1108h] [bp-2004h] BYREF

  rpc_user = pool->rpc_user;
  v3 = swork_id;
  rpc_pass = pool->rpc_pass;
  ++swork_id;
  sprintf(s, "{\"id\": %d, \"method\": \"mining.authorize\", \"params\": [\"%s\", \"%s\"]}", v3, rpc_user, rpc_pass);
  v4 = strlen(s);
  v5 = stratum_send(pool, s, v4);
  if ( v5 )
  {
    while ( 1 )
    {
      v7 = recv_line(pool);
      v8 = v7;
      if ( !v7 )
        goto LABEL_6;
      v6 = parse_method_0(pool, v7);
      if ( !v6 )
        break;
      free(v8);
    }
    v10 = json_loads(v8, 0, &err);
    free(v8);
    v11 = json_object_get(v10, "result");
    v12 = json_object_get(v10, "error");
    if ( !v11 || v11->type == JSON_FALSE )
    {
      if ( !v12 )
      {
        v16 = (char *)malloc(0x11u);
        v13 = v16;
        if ( v16 )
          strcpy(v16, "(unknown reason)");
        goto LABEL_13;
      }
    }
    else if ( !v12 || v12->type == JSON_NULL )
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42, 0x1000u, "Stratum authorisation success for pool %d", pool->pool_no);
        applog(7, tmp42, 0);
      }
      v17 = opt_suggest_diff;
      successful_connect = 1;
      pool->probed = 1;
      if ( v17 )
      {
        v20 = swork_id++;
        sprintf(s, "{\"id\": %d, \"method\": \"mining.suggest_difficulty\", \"params\": [%d]}", v20, v17);
        v21 = strlen(s);
        stratum_send(pool, s, v21);
      }
      LOBYTE(v6) = v5;
      if ( opt_multi_version )
      {
        v18 = swork_id++;
        sprintf(s, "{\"id\": %d, \"method\": \"mining.multi_version\", \"params\": [%d]}", v18, opt_multi_version);
        v19 = strlen(s);
        stratum_send(pool, s, v19);
      }
      goto out_0;
    }
    v13 = json_dumps(v12, 3u);
LABEL_13:
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "pool %d JSON stratum auth failed: %s", pool->pool_no, v13);
      applog(7, tmp42, 0);
    }
    free(v13);
    suspend_stratum(pool);
out_0:
    if ( v10 )
    {
      refcount = v10->refcount;
      if ( refcount != -1 )
      {
        v15 = refcount - 1;
        v10->refcount = v15;
        if ( !v15 )
          json_delete(v10);
      }
    }
    return v6;
  }
LABEL_6:
  LOBYTE(v6) = 0;
  return v6;
}
