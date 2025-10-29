bool __fastcall pool_active(pool *pool, bool pinging)
{
  _BOOL4 v3; // r8
  int v4; // r7
  _BOOL4 v5; // r2
  const char *v6; // r12
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int *v11; // r12
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r1
  int v21; // r2
  int v22; // r3
  char *stratum_url; // r1
  _BOOL4 has_gbt; // r3
  _BOOL4 v26; // r8
  int *v27; // r4
  int v28; // r0
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int *v32; // r4
  int v33; // r0
  int v34; // r1
  int v35; // r2
  int v36; // r3
  int v37; // r4
  timeval tv_getwork; // [sp+8h] [bp-1010h] BYREF
  timeval tv_getwork_reply; // [sp+10h] [bp-1008h] BYREF
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  v3 = pinging;
  if ( pool->has_gbt )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "Retrieving block template from pool %s", pool->rpc_url);
      goto LABEL_62;
    }
  }
  else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "Testing pool %s", pool->rpc_url);
LABEL_62:
    applog(7, tmp42, 0);
  }
  LOBYTE(v4) = pool->has_stratum;
  if ( (_BYTE)v4 )
    goto LABEL_20;
  if ( !curly )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      strcpy(tmp42, "CURL initialisation failed");
      applog(3, tmp42, 0);
    }
    return v4;
  }
  if ( pool->probed )
    goto LABEL_16;
  if ( !opt_debug )
  {
    pool->probed = v4;
    goto LABEL_16;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
  {
    has_gbt = pool->has_gbt;
    pool->probed = v4;
    if ( !has_gbt )
    {
      if ( !pool->gbt_solo )
      {
        if ( use_syslog )
        {
LABEL_57:
          v6 = "No GBT coinbase + append support found, using getwork protocol";
          goto LABEL_14;
        }
        goto LABEL_55;
      }
LABEL_47:
      if ( use_syslog || opt_log_output || opt_log_level > 6 )
      {
        strcpy(tmp42, "GBT coinbase without append found, switching to GBT solo protocol");
        applog(7, tmp42, 0);
      }
      goto LABEL_16;
    }
LABEL_11:
    if ( use_syslog || opt_log_output || opt_log_level > 6 )
    {
      v6 = "GBT coinbase + append support found, switching to GBT protocol";
LABEL_14:
      v7 = *(_DWORD *)v6;
      v8 = *((_DWORD *)v6 + 1);
      v9 = *((_DWORD *)v6 + 2);
      v10 = *((_DWORD *)v6 + 3);
      v11 = (int *)(v6 + 16);
      *(_DWORD *)tmp42 = v7;
      *(_DWORD *)&tmp42[4] = v8;
      *(_DWORD *)&tmp42[8] = v9;
      *(_DWORD *)&tmp42[12] = v10;
      v12 = *v11;
      v13 = v11[1];
      v14 = v11[2];
      v15 = v11[3];
      v11 += 4;
      *(_DWORD *)&tmp42[16] = v12;
      *(_DWORD *)&tmp42[20] = v13;
      *(_DWORD *)&tmp42[24] = v14;
      *(_DWORD *)&tmp42[28] = v15;
      v16 = *v11;
      v17 = v11[1];
      v18 = v11[2];
      v19 = v11[3];
      v11 += 4;
      *(_DWORD *)&tmp42[32] = v16;
      *(_DWORD *)&tmp42[36] = v17;
      *(_DWORD *)&tmp42[40] = v18;
      *(_DWORD *)&tmp42[44] = v19;
      v20 = v11[1];
      v21 = v11[2];
      v22 = v11[3];
      *(_DWORD *)&tmp42[48] = *v11;
      *(_DWORD *)&tmp42[52] = v20;
      *(_DWORD *)&tmp42[56] = v21;
      *(_WORD *)&tmp42[60] = v22;
      tmp42[62] = BYTE2(v22);
      applog(7, tmp42, 0);
      goto LABEL_16;
    }
    goto LABEL_16;
  }
  strcpy(tmp42, "Probing for GBT support");
  applog(7, tmp42, 0);
  v5 = pool->has_gbt;
  pool->probed = 0;
  if ( v5 )
  {
    if ( !opt_debug )
      goto LABEL_16;
    goto LABEL_11;
  }
  if ( pool->gbt_solo )
  {
    if ( !opt_debug )
      goto LABEL_16;
    goto LABEL_47;
  }
  if ( !opt_debug )
    goto LABEL_16;
  if ( use_syslog )
    goto LABEL_57;
LABEL_55:
  if ( opt_log_output || opt_log_level > 6 )
    goto LABEL_57;
LABEL_16:
  cgtime(&tv_getwork);
  cgtime(&tv_getwork_reply);
  stratum_url = pool->stratum_url;
  if ( !stratum_url || opt_fix_protocol )
    goto LABEL_18;
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    snprintf(tmp42, 0x1000u, "Testing pool %d stratum %s", pool->pool_no, pool->stratum_url);
    applog(7, tmp42, 0);
    stratum_url = pool->stratum_url;
  }
  check_extranonce_option(pool, stratum_url);
  if ( extract_sockaddr(pool->stratum_url, &pool->sockaddr_url, &pool->stratum_port) && initiate_stratum(pool) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "Switching pool %d %s to %s", pool->pool_no, pool->rpc_url, pool->stratum_url);
      applog(7, tmp42, 0);
    }
    if ( !pool->rpc_url )
      pool->rpc_url = _strdup(pool->stratum_url);
  }
  else
  {
LABEL_18:
    if ( !initiate_stratum(pool) )
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42, 0x1000u, "FAILED to retrieve work from pool %u %s", pool->pool_no, pool->rpc_url);
        applog(7, tmp42, 0);
      }
      if ( !v3 && !pool->idle && (use_syslog || opt_log_output || opt_log_level > 3) )
      {
        LOBYTE(v4) = 0;
        snprintf(tmp42, 0x1000u, "Pool %u slow/down or URL or credentials invalid", pool->pool_no);
        applog(4, tmp42, 0);
      }
      return v4;
    }
  }
  pool->has_stratum = 1;
LABEL_20:
  v4 = pool_tset((int)pool, &pool->stratum_init);
  if ( v4 )
    return pool->stratum_active;
  if ( initiate_stratum(pool) && (v26 = auth_stratum(pool)) )
  {
    extranonce_subscribe_stratum(pool);
    have_longpoll = 1;
    if ( pthread_create(&pool->stratum_sthread, 0, (void *(*)(void *))stratum_sthread, pool) )
    {
      v27 = (int *)&unk_4FCAC;
LABEL_88:
      v28 = *v27;
      v29 = v27[1];
      v30 = v27[2];
      v31 = v27[3];
      v32 = v27 + 4;
      *(_DWORD *)tmp42 = v28;
      *(_DWORD *)&tmp42[4] = v29;
      *(_DWORD *)&tmp42[8] = v30;
      *(_DWORD *)&tmp42[12] = v31;
      v33 = *v32;
      v34 = v32[1];
      v35 = v32[2];
      v36 = v32[3];
      v37 = v32[4];
      *(_DWORD *)&tmp42[16] = v33;
      *(_DWORD *)&tmp42[20] = v34;
      *(_DWORD *)&tmp42[24] = v35;
      *(_DWORD *)&tmp42[28] = v36;
      tmp42[32] = v37;
      applog(3, tmp42, 1);
      _quit(1, 1);
    }
    LOBYTE(v4) = v26;
    if ( pthread_create(&pool->stratum_rthread, 0, stratum_rthread, pool) )
    {
      v27 = (int *)&unk_4FCD0;
      goto LABEL_88;
    }
  }
  else
  {
    extranonce_subscribe_stratum(pool);
    pool_tclear((int)pool, &pool->stratum_init);
  }
  return v4;
}
