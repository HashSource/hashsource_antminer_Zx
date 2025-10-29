bool __fastcall subscribe_extranonce(pool *pool)
{
  const char *v2; // r1
  ssize_t v3; // r0
  _BOOL4 v4; // r7
  char *v5; // r0
  char *v6; // r4
  _BOOL4 v7; // r6
  int *v8; // r4
  int v9; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r0
  int v18; // r1
  int v19; // r2
  int v20; // r3
  int v21; // r4
  json_t *v22; // r8
  const char *v23; // r1
  json_t *v24; // r0
  const char *v25; // r1
  json_t *v26; // r7
  json_t *v27; // r0
  const json_t *v28; // r4
  const char *v29; // r7
  const char *v30; // r1
  const char *v31; // r1
  char *v32; // r4
  const char *v33; // r2
  size_t refcount; // r3
  size_t v35; // r3
  char *v36; // r0
  int *v37; // r6
  char *v38; // r7
  int v39; // r0
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r6
  const char *v44; // r2
  const char *v45; // r2
  json_error_t err; // [sp+Ch] [bp-30FCh] BYREF
  char tmp42[4096]; // [sp+108h] [bp-3000h] BYREF
  char s[8192]; // [sp+1108h] [bp-2000h] BYREF

  LOWORD(v2) = 17728;
  HIWORD(v2) = (unsigned int)" decode failed: %s" >> 16;
  ++swork_id;
  sprintf(s, v2);
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
            LOWORD(v8) = 19268;
            HIWORD(v8) = (unsigned int)"\": %d, \"method\": \"mining.suggest_difficulty\", \"params\": [%d]}" >> 16;
            LOBYTE(v4) = opt_debug;
            v9 = *v8;
            v10 = v8[1];
            v11 = v8[2];
            v12 = v8[3];
            v8 += 4;
            *(_DWORD *)tmp42 = v9;
            *(_DWORD *)&tmp42[4] = v10;
            *(_DWORD *)&tmp42[8] = v11;
            *(_DWORD *)&tmp42[12] = v12;
            v13 = *v8;
            v14 = v8[1];
            v15 = v8[2];
            v16 = v8[3];
            v8 += 4;
            *(_DWORD *)&tmp42[16] = v13;
            *(_DWORD *)&tmp42[20] = v14;
            *(_DWORD *)&tmp42[24] = v15;
            *(_DWORD *)&tmp42[28] = v16;
            v17 = *v8;
            v18 = v8[1];
            v19 = v8[2];
            v20 = v8[3];
            v21 = v8[4];
            *(_DWORD *)&tmp42[32] = v17;
            *(_DWORD *)&tmp42[36] = v18;
            *(_DWORD *)&tmp42[40] = v19;
            *(_DWORD *)&tmp42[44] = v20;
            *(_DWORD *)&tmp42[48] = v21;
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
    v22 = json_loads(v6, 0, &err);
    free(v6);
    LOWORD(v23) = 5064;
    HIWORD(v23) = (unsigned int)"terrupted" >> 16;
    v24 = json_object_get(v22, v23);
    LOWORD(v25) = 2324;
    v26 = v24;
    HIWORD(v25) = (unsigned int)"sharelog printf error" >> 16;
    v27 = json_object_get(v22, v25);
    v28 = v27;
    if ( !v26 || v26->type == JSON_FALSE )
    {
      if ( !v27 )
      {
        v36 = (char *)malloc(0x11u);
        v32 = v36;
        if ( v36 )
        {
          LOWORD(v37) = 5076;
          v38 = v36;
          HIWORD(v37) = (unsigned int)"JSON decode failed(%d): %s" >> 16;
          v39 = *v37;
          v40 = v37[1];
          v41 = v37[2];
          v42 = v37[3];
          v43 = v37[4];
          *(_DWORD *)v38 = v39;
          *((_DWORD *)v38 + 1) = v40;
          *((_DWORD *)v38 + 2) = v41;
          *((_DWORD *)v38 + 3) = v42;
          v38[16] = v43;
        }
        goto LABEL_32;
      }
    }
    else if ( !v27 || v27->type == JSON_NULL )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 5 )
      {
        LOWORD(v45) = 19516;
        HIWORD(v45) = (unsigned int)"ot subscribe to mining.extranonce for pool %d" >> 16;
        LOBYTE(v4) = v7;
        snprintf(tmp42, 0x1000u, v45, pool->pool_no);
        applog(6, tmp42, 0);
        goto LABEL_25;
      }
LABEL_44:
      LOBYTE(v4) = v7;
      goto LABEL_25;
    }
    v29 = _json_array_string(v27, 1u);
    if ( !v29 && (v29 = json_string_value(v28)) == 0
      || (LOWORD(v30) = 19320, HIWORD(v30) = (unsigned int)"s\": [%d]}" >> 16, strcmp(v29, v30))
      && (LOWORD(v31) = 19436, HIWORD(v31) = (unsigned int)"e.subscribe" >> 16, strcmp(v29, v31)) )
    {
      v32 = json_dumps(v28, 3u);
LABEL_32:
      if ( use_syslog || opt_log_output || opt_log_level > 5 )
      {
        LOWORD(v44) = 19468;
        HIWORD(v44) = (unsigned int)"ot found for service 'mining.extranonce'" >> 16;
        snprintf(tmp42, 0x1000u, v44, pool->pool_no, v32);
        applog(6, tmp42, 0);
      }
      LOBYTE(v4) = 0;
      free(v32);
      goto LABEL_25;
    }
    if ( use_syslog || opt_log_output || opt_log_level > 5 )
    {
      LOWORD(v33) = 19384;
      HIWORD(v33) = (unsigned int)"\": [%d]}" >> 16;
      LOBYTE(v4) = v7;
      snprintf(tmp42, 0x1000u, v33, pool->pool_no);
      applog(6, tmp42, 0);
LABEL_25:
      if ( v22 )
      {
        refcount = v22->refcount;
        if ( refcount != -1 )
        {
          v35 = refcount - 1;
          v22->refcount = v35;
          if ( !v35 )
            json_delete(v22);
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
