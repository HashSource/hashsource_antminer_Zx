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
  const char *v11; // r1
  json_t *v12; // r0
  const char *v13; // r1
  json_t *v14; // r4
  json_t *v15; // r0
  char *v16; // r4
  const char *v17; // r2
  size_t refcount; // r3
  size_t v19; // r3
  char *v20; // r0
  int *v21; // r7
  char *v22; // r12
  int v23; // r0
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r7
  const char *v28; // r2
  int v29; // r3
  const char *v30; // r1
  ssize_t v31; // r0
  const char *v32; // r1
  ssize_t v33; // r0
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
    LOWORD(v11) = 5064;
    HIWORD(v11) = (unsigned int)"terrupted" >> 16;
    v12 = json_object_get(v10, v11);
    LOWORD(v13) = 2324;
    v14 = v12;
    HIWORD(v13) = (unsigned int)"sharelog printf error" >> 16;
    v15 = json_object_get(v10, v13);
    if ( !v14 || v14->type == JSON_FALSE )
    {
      if ( !v15 )
      {
        v20 = (char *)malloc(0x11u);
        v16 = v20;
        if ( v20 )
        {
          LOWORD(v21) = 5076;
          v22 = v20;
          HIWORD(v21) = (unsigned int)"JSON decode failed(%d): %s" >> 16;
          v23 = *v21;
          v24 = v21[1];
          v25 = v21[2];
          v26 = v21[3];
          v27 = v21[4];
          *(_DWORD *)v22 = v23;
          *((_DWORD *)v22 + 1) = v24;
          *((_DWORD *)v22 + 2) = v25;
          *((_DWORD *)v22 + 3) = v26;
          v22[16] = v27;
        }
        goto LABEL_13;
      }
    }
    else if ( !v15 || v15->type == JSON_NULL )
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v28) = 19092;
        HIWORD(v28) = (unsigned int)"g an array value." >> 16;
        snprintf(tmp42, 0x1000u, v28, pool->pool_no);
        applog(7, tmp42, 0);
      }
      v29 = opt_suggest_diff;
      successful_connect = 1;
      pool->probed = 1;
      if ( v29 )
      {
        LOWORD(v32) = 19136;
        HIWORD(v32) = (unsigned int)"ning.authorize\", \"params\": [\"%s\", \"%s\"]}" >> 16;
        ++swork_id;
        sprintf(s, v32);
        v33 = strlen(s);
        stratum_send(pool, s, v33);
      }
      LOBYTE(v6) = v5;
      if ( opt_multi_version )
      {
        LOWORD(v30) = 19204;
        HIWORD(v30) = (unsigned int)"h failed: %s" >> 16;
        ++swork_id;
        sprintf(s, v30);
        v31 = strlen(s);
        stratum_send(pool, s, v31);
      }
      goto out_0;
    }
    v16 = json_dumps(v15, 3u);
LABEL_13:
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v17) = 19052;
      HIWORD(v17) = (unsigned int)"mining.set_target" >> 16;
      snprintf(tmp42, 0x1000u, v17, pool->pool_no, v16);
      applog(7, tmp42, 0);
    }
    free(v16);
    suspend_stratum(pool);
out_0:
    if ( v10 )
    {
      refcount = v10->refcount;
      if ( refcount != -1 )
      {
        v19 = refcount - 1;
        v10->refcount = v19;
        if ( !v19 )
          json_delete(v10);
      }
    }
    return v6;
  }
LABEL_6:
  LOBYTE(v6) = 0;
  return v6;
}
