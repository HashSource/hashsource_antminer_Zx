bool __fastcall parse_extranonce_equihash(pool *pool, json_t *val, int type)
{
  char *v4; // r0
  char *v5; // r5
  size_t v6; // r3
  unsigned __int8 *nonce1bin; // r0
  size_t n1_len; // r6
  unsigned __int8 *v9; // r0
  size_t v10; // r3
  const char *v11; // r2
  int *v12; // r0
  const char *v13; // r2
  int *v14; // r0
  const char *v15; // r2
  const char *v16; // r2
  int *v17; // r0
  const char *v18; // r2
  int *v19; // r0
  int v20; // r1
  const char *v21; // r2
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v4 = json_array_string(val, type);
  v5 = v4;
  if ( v4 )
  {
    if ( pthread_mutex_lock(&pool->data_lock.mutex) )
    {
      v12 = _errno_location();
      LOWORD(v13) = -968;
      HIWORD(v13) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v13, *v12, "util.c", "parse_extranonce_equihash", 2522);
      applog(3, tmp42, 1);
      quit(1);
    }
    if ( pthread_rwlock_wrlock(&pool->data_lock.rwlock) )
    {
      v14 = _errno_location();
      LOWORD(v15) = -1020;
      HIWORD(v15) = (unsigned int)"d_rwlock_init errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v15, *v14, "util.c", "parse_extranonce_equihash", 2522);
      applog(3, tmp42, 1);
      quit(1);
    }
    free(pool->nonce1);
    pool->nonce1 = v5;
    v6 = strlen(v5) >> 1;
    nonce1bin = pool->nonce1bin;
    pool->n1_len = v6;
    free(nonce1bin);
    n1_len = pool->n1_len;
    v9 = (unsigned __int8 *)calloc(n1_len, 1u);
    pool->nonce1bin = v9;
    if ( !v9 )
    {
      LOWORD(v16) = 16084;
      HIWORD(v16) = (unsigned int)"cgsem=0x%p in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v16, "parse_extranonce_equihash", "util.c", "parse_extranonce_equihash", 2530);
      applog(3, tmp42, 1);
      quit(1);
    }
    hex2bin(v9, pool->nonce1, n1_len);
    v10 = pool->n1_len;
    pool->nonce2 = 0;
    pool->n2size = 64 - v10;
    if ( pthread_rwlock_unlock(&pool->data_lock.rwlock) )
    {
      v17 = _errno_location();
      LOWORD(v18) = -348;
      HIWORD(v18) = (unsigned int)"slow/down or URL or credentials invalid" >> 16;
      snprintf(tmp42, 0x1000u, v18, *v17, "util.c", "parse_extranonce_equihash", 2536);
      applog(3, tmp42, 1);
      quit(1);
    }
    if ( pthread_mutex_unlock(&pool->data_lock.mutex) )
    {
      v19 = _errno_location();
      LOWORD(v20) = 15984;
      LOWORD(v21) = -920;
      HIWORD(v20) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
      HIWORD(v21) = (unsigned int)"X ERROR ON LOCK! errno=%d in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v21, *v19, v20, "parse_extranonce_equihash", 2536);
      applog(3, tmp42, 1);
      quit(1);
    }
    selective_yield();
    if ( use_syslog || opt_log_output || opt_log_level > 5 )
    {
      LOWORD(v11) = 16136;
      HIWORD(v11) = (unsigned int)"Failed to calloc in %s %s():%d" >> 16;
      snprintf(tmp42, 0x1000u, v11, pool->pool_no, v5);
      applog(6, tmp42, 0);
      LOBYTE(v4) = 1;
    }
    else
    {
      LOBYTE(v4) = 1;
    }
  }
  return (char)v4;
}
