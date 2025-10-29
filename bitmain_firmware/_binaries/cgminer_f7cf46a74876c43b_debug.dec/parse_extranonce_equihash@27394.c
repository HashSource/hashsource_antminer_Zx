bool __fastcall parse_extranonce_equihash(pool *pool, json_t *val, int type)
{
  char *v4; // r0
  char *v5; // r5
  size_t v6; // r3
  unsigned __int8 *nonce1bin; // r0
  size_t n1_len; // r6
  unsigned __int8 *v9; // r0
  size_t v10; // r3
  int *v11; // r0
  int *v12; // r0
  int *v13; // r0
  int *v14; // r0
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v4 = json_array_string(val, type);
  v5 = v4;
  if ( v4 )
  {
    if ( pthread_mutex_lock(&pool->data_lock.mutex) )
    {
      v11 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",
        *v11,
        "util.c",
        "parse_extranonce_equihash",
        2522);
      applog(3, tmp42, 1);
      quit(1);
    }
    if ( pthread_rwlock_wrlock(&pool->data_lock.rwlock) )
    {
      v12 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
        *v12,
        "util.c",
        "parse_extranonce_equihash",
        2522);
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
      snprintf(
        tmp42,
        0x1000u,
        "%s: Failed to calloc pool->nonce1bin in %s %s():%d",
        "parse_extranonce_equihash",
        "util.c",
        "parse_extranonce_equihash",
        2530);
      applog(3, tmp42, 1);
      quit(1);
    }
    hex2bin(v9, pool->nonce1, n1_len);
    v10 = pool->n1_len;
    pool->nonce2 = 0;
    pool->n2size = 64 - v10;
    if ( pthread_rwlock_unlock(&pool->data_lock.rwlock) )
    {
      v13 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
        *v13,
        "util.c",
        "parse_extranonce_equihash",
        2536);
      applog(3, tmp42, 1);
      quit(1);
    }
    if ( pthread_mutex_unlock(&pool->data_lock.mutex) )
    {
      v14 = _errno_location();
      snprintf(
        tmp42,
        0x1000u,
        "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
        *v14,
        "util.c",
        "parse_extranonce_equihash",
        2536);
      applog(3, tmp42, 1);
      quit(1);
    }
    selective_yield();
    if ( use_syslog || opt_log_output || opt_log_level > 5 )
    {
      snprintf(tmp42, 0x1000u, "Pool %d extranonce set to %s", pool->pool_no, v5);
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
