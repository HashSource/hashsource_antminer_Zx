bool __fastcall stratum_send(pool *pool, char *s, ssize_t len)
{
  pthread_mutex_t *p_stratum_lock; // r6
  int *v7; // r0
  int v8; // r1
  const char *v9; // r2
  const char *v10; // r2
  int *v11; // r0
  int v12; // r1
  const char *v13; // r2
  send_ret v14; // r4
  bool result; // r0
  const char *v16; // r2
  int *v17; // r4
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r0
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r0
  int v27; // r1
  int v28; // r2
  int v29; // r3
  int v30; // r4
  int *v31; // r6
  int v32; // r0
  int v33; // r1
  int v34; // r2
  int v35; // r3
  int v36; // r1
  int v37; // r2
  int v38; // r3
  char tmp42[4096]; // [sp+10h] [bp-1004h] BYREF

  if ( opt_protocol && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v10) = 16472;
    HIWORD(v10) = (unsigned int)"ed." >> 16;
    p_stratum_lock = &pool->stratum_lock;
    snprintf(tmp42, 0x1000u, v10, s);
    applog(7, tmp42, 0);
    if ( pthread_mutex_lock(&pool->stratum_lock) )
    {
LABEL_11:
      v11 = _errno_location();
      LOWORD(v12) = 15984;
      HIWORD(v12) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
      LOWORD(v13) = -968;
      HIWORD(v13) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v13, *v11, v12, "stratum_send", 1893);
      applog(3, tmp42, 1);
      quit(1);
    }
  }
  else
  {
    p_stratum_lock = &pool->stratum_lock;
    if ( pthread_mutex_lock(&pool->stratum_lock) )
      goto LABEL_11;
  }
  if ( !pool->stratum_active )
  {
    if ( pthread_mutex_unlock(p_stratum_lock) )
      goto LABEL_6;
    selective_yield();
    goto LABEL_24;
  }
  v14 = _stratum_send(pool, s, len);
  if ( pthread_mutex_unlock(p_stratum_lock) )
  {
LABEL_6:
    v7 = _errno_location();
    LOWORD(v8) = 15984;
    LOWORD(v9) = -920;
    HIWORD(v8) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
    HIWORD(v9) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v9, *v7, v8, "stratum_send", 1896);
    applog(3, tmp42, 1);
    quit(1);
  }
  selective_yield();
  if ( v14 == send_ret::SEND_SENDFAIL )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v31) = 16520;
      HIWORD(v31) = (unsigned int)" %s():%d" >> 16;
      v32 = *v31;
      v33 = v31[1];
      v34 = v31[2];
      v35 = v31[3];
      v31 += 4;
      *(_DWORD *)tmp42 = v32;
      *(_DWORD *)&tmp42[4] = v33;
      *(_DWORD *)&tmp42[8] = v34;
      *(_DWORD *)&tmp42[12] = v35;
      v36 = v31[1];
      v37 = v31[2];
      v38 = v31[3];
      *(_DWORD *)&tmp42[16] = *v31;
      *(_DWORD *)&tmp42[20] = v36;
      *(_DWORD *)&tmp42[24] = v37;
      *(_WORD *)&tmp42[28] = v38;
      tmp42[30] = BYTE2(v38);
      applog(7, tmp42, 0);
      suspend_stratum(pool);
      return 0;
    }
    goto LABEL_21;
  }
  if ( v14 != send_ret::SEND_INACTIVE )
  {
    if ( v14 != send_ret::SEND_SELECTFAIL )
      return v14 == send_ret::SEND_OK;
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v16) = 16484;
      HIWORD(v16) = (unsigned int)&dword_53FE4 >> 16;
      snprintf(tmp42, 0x1000u, v16, pool->pool_no);
      applog(7, tmp42, 0);
    }
LABEL_21:
    suspend_stratum(pool);
    return 0;
  }
LABEL_24:
  result = opt_debug;
  if ( opt_debug && (use_syslog || (result = opt_log_output) || opt_log_level > 6) )
  {
    LOWORD(v17) = 16552;
    HIWORD(v17) = (unsigned int)" %s %s():%d" >> 16;
    v18 = *v17;
    v19 = v17[1];
    v20 = v17[2];
    v21 = v17[3];
    v17 += 4;
    *(_DWORD *)tmp42 = v18;
    *(_DWORD *)&tmp42[4] = v19;
    *(_DWORD *)&tmp42[8] = v20;
    *(_DWORD *)&tmp42[12] = v21;
    v22 = *v17;
    v23 = v17[1];
    v24 = v17[2];
    v25 = v17[3];
    v17 += 4;
    *(_DWORD *)&tmp42[16] = v22;
    *(_DWORD *)&tmp42[20] = v23;
    *(_DWORD *)&tmp42[24] = v24;
    *(_DWORD *)&tmp42[28] = v25;
    v26 = *v17;
    v27 = v17[1];
    v28 = v17[2];
    v29 = v17[3];
    v30 = v17[4];
    *(_DWORD *)&tmp42[32] = v26;
    *(_DWORD *)&tmp42[36] = v27;
    *(_DWORD *)&tmp42[40] = v28;
    *(_DWORD *)&tmp42[44] = v29;
    *(_WORD *)&tmp42[48] = v30;
    applog(7, tmp42, 0);
    return 0;
  }
  return result;
}
