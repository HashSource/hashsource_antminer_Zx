bool __fastcall pool_active(pool *pool, bool pinging)
{
  _BOOL4 v3; // r8
  int v4; // r7
  int *v5; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  _BOOL4 v11; // r2
  int *v12; // r12
  int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int *v17; // r12
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r0
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r1
  int v27; // r2
  int v28; // r3
  char *stratum_url; // r1
  const char *v31; // r2
  const char *v32; // r2
  int *v33; // r5
  int v34; // r0
  int v35; // r1
  int v36; // r2
  int v37; // r3
  int v38; // r1
  int v39; // r2
  const char *v40; // r2
  const void *v41; // r1
  _BOOL4 has_gbt; // r3
  const char *v43; // r2
  const char *v44; // r2
  const char *v45; // r2
  _BOOL4 v46; // r8
  void *(*v47)(void *); // r2
  void *(*v48)(void *); // r2
  int *v49; // r4
  int v50; // r0
  int v51; // r1
  int v52; // r2
  int v53; // r3
  int *v54; // r4
  int v55; // r0
  int v56; // r1
  int v57; // r2
  int v58; // r3
  int v59; // r4
  timeval tv_getwork; // [sp+8h] [bp-1010h] BYREF
  timeval tv_getwork_reply; // [sp+10h] [bp-1008h] BYREF
  char tmp42[4096]; // [sp+18h] [bp-1000h] BYREF

  v3 = pinging;
  if ( pool->has_gbt )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v43) = -868;
      HIWORD(v43) = (unsigned int)"ROR ON UNLOCK! errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v43, pool->rpc_url);
      goto LABEL_62;
    }
  }
  else if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v40) = -828;
    HIWORD(v40) = (unsigned int)"Retrieving block template from pool %s" >> 16;
    snprintf(tmp42, 0x1000u, v40, pool->rpc_url);
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
      LOWORD(v33) = -740;
      HIWORD(v33) = (unsigned int)&dword_4FCF4 >> 16;
      v34 = *v33;
      v35 = v33[1];
      v36 = v33[2];
      v37 = v33[3];
      v33 += 4;
      *(_DWORD *)tmp42 = v34;
      *(_DWORD *)&tmp42[4] = v35;
      *(_DWORD *)&tmp42[8] = v36;
      *(_DWORD *)&tmp42[12] = v37;
      v38 = v33[1];
      v39 = v33[2];
      *(_DWORD *)&tmp42[16] = *v33;
      *(_DWORD *)&tmp42[20] = v38;
      *(_WORD *)&tmp42[24] = v39;
      tmp42[26] = BYTE2(v39);
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
          LOWORD(v12) = -556;
          HIWORD(v12) = (unsigned int)"found, switching to GBT solo protocol" >> 16;
          goto LABEL_14;
        }
        goto LABEL_55;
      }
LABEL_47:
      if ( use_syslog || opt_log_output || opt_log_level > 6 )
      {
        LOWORD(v41) = -624;
        HIWORD(v41) = (unsigned int)"pport found, switching to GBT protocol" >> 16;
        memcpy(tmp42, v41, 0x42u);
        applog(7, tmp42, 0);
      }
      goto LABEL_16;
    }
LABEL_11:
    if ( use_syslog || opt_log_output || opt_log_level > 6 )
    {
      LOWORD(v12) = -688;
      HIWORD(v12) = (unsigned int)"isation failed" >> 16;
LABEL_14:
      v13 = *v12;
      v14 = v12[1];
      v15 = v12[2];
      v16 = v12[3];
      v17 = v12 + 4;
      *(_DWORD *)tmp42 = v13;
      *(_DWORD *)&tmp42[4] = v14;
      *(_DWORD *)&tmp42[8] = v15;
      *(_DWORD *)&tmp42[12] = v16;
      v18 = *v17;
      v19 = v17[1];
      v20 = v17[2];
      v21 = v17[3];
      v17 += 4;
      *(_DWORD *)&tmp42[16] = v18;
      *(_DWORD *)&tmp42[20] = v19;
      *(_DWORD *)&tmp42[24] = v20;
      *(_DWORD *)&tmp42[28] = v21;
      v22 = *v17;
      v23 = v17[1];
      v24 = v17[2];
      v25 = v17[3];
      v17 += 4;
      *(_DWORD *)&tmp42[32] = v22;
      *(_DWORD *)&tmp42[36] = v23;
      *(_DWORD *)&tmp42[40] = v24;
      *(_DWORD *)&tmp42[44] = v25;
      v26 = v17[1];
      v27 = v17[2];
      v28 = v17[3];
      *(_DWORD *)&tmp42[48] = *v17;
      *(_DWORD *)&tmp42[52] = v26;
      *(_DWORD *)&tmp42[56] = v27;
      *(_WORD *)&tmp42[60] = v28;
      tmp42[62] = BYTE2(v28);
      applog(7, tmp42, 0);
      goto LABEL_16;
    }
    goto LABEL_16;
  }
  LOWORD(v5) = -712;
  HIWORD(v5) = (unsigned int)&unk_4FD10 >> 16;
  v6 = *v5;
  v7 = v5[1];
  v8 = v5[2];
  v9 = v5[3];
  v5 += 4;
  *(_DWORD *)tmp42 = v6;
  *(_DWORD *)&tmp42[4] = v7;
  *(_DWORD *)&tmp42[8] = v8;
  *(_DWORD *)&tmp42[12] = v9;
  v10 = v5[1];
  *(_DWORD *)&tmp42[16] = *v5;
  *(_DWORD *)&tmp42[20] = v10;
  applog(7, tmp42, 0);
  v11 = pool->has_gbt;
  pool->probed = 0;
  if ( v11 )
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
    LOWORD(v31) = -492;
    HIWORD(v31) = (unsigned int)" support found, using getwork protocol" >> 16;
    snprintf(tmp42, 0x1000u, v31, pool->pool_no, pool->stratum_url);
    applog(7, tmp42, 0);
    stratum_url = pool->stratum_url;
  }
  check_extranonce_option(pool, stratum_url);
  if ( extract_sockaddr(pool->stratum_url, &pool->sockaddr_url, &pool->stratum_port) && initiate_stratum(pool) )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v32) = -464;
      HIWORD(v32) = (unsigned int)"k protocol" >> 16;
      snprintf(tmp42, 0x1000u, v32, pool->pool_no, pool->rpc_url, pool->stratum_url);
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
        LOWORD(v44) = -436;
        HIWORD(v44) = (unsigned int)"stratum %s" >> 16;
        snprintf(tmp42, 0x1000u, v44, pool->pool_no, pool->rpc_url);
        applog(7, tmp42, 0);
      }
      if ( !v3 && !pool->idle && (use_syslog || opt_log_output || opt_log_level > 3) )
      {
        LOWORD(v45) = -396;
        HIWORD(v45) = (unsigned int)"FAILED to retrieve work from pool %u %s" >> 16;
        LOBYTE(v4) = 0;
        snprintf(tmp42, 0x1000u, v45, pool->pool_no);
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
  if ( initiate_stratum(pool) && (v46 = auth_stratum(pool)) )
  {
    extranonce_subscribe_stratum(pool);
    LOWORD(v47) = 2505;
    HIWORD(v47) = ((unsigned int)&loc_20976 + 3) >> 16;
    have_longpoll = 1;
    if ( pthread_create(&pool->stratum_sthread, 0, v47, pool) )
    {
      v49 = (int *)&unk_4FCD4;
LABEL_88:
      v50 = *v49;
      v51 = v49[1];
      v52 = v49[2];
      v53 = v49[3];
      v54 = v49 + 4;
      *(_DWORD *)tmp42 = v50;
      *(_DWORD *)&tmp42[4] = v51;
      *(_DWORD *)&tmp42[8] = v52;
      *(_DWORD *)&tmp42[12] = v53;
      v55 = *v54;
      v56 = v54[1];
      v57 = v54[2];
      v58 = v54[3];
      v59 = v54[4];
      *(_DWORD *)&tmp42[16] = v55;
      *(_DWORD *)&tmp42[20] = v56;
      *(_DWORD *)&tmp42[24] = v57;
      *(_DWORD *)&tmp42[28] = v58;
      tmp42[32] = v59;
      applog(3, tmp42, 1);
      _quit(1, 1);
    }
    LOWORD(v48) = 18669;
    HIWORD(v48) = ((unsigned int)&loc_2489A + 3) >> 16;
    LOBYTE(v4) = v46;
    if ( pthread_create(&pool->stratum_rthread, 0, v48, pool) )
    {
      v49 = (int *)&unk_4FCF8;
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
