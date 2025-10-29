pool *add_pool()
{
  pool *v0; // r0
  pool *v1; // r4
  int v2; // r3
  pool **v3; // r0
  int v4; // r1
  pool **v5; // r0
  int v6; // r2
  char *v7; // r3
  int *v9; // r0
  int v10; // r3
  int v11; // r1
  int v12; // r4
  const char *v13; // r2
  int *v14; // r4
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r4
  int *v24; // r0
  int *v25; // r4
  int v26; // r0
  int v27; // r1
  int v28; // r2
  int v29; // r3
  int v30; // r0
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r1
  int *v35; // r0
  int *v36; // r0
  int v37; // r3
  int v38; // r1
  int v39; // r4
  const char *v40; // r2
  int *v41; // r0
  int *v42; // r0
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v0 = (pool *)calloc(0x750u, 1u);
  if ( !v0 )
  {
    LOWORD(v14) = 1264;
    HIWORD(v14) = (unsigned int)"Stratum connection to pool %d resumed" >> 16;
    v15 = *v14;
    v16 = v14[1];
    v17 = v14[2];
    v18 = v14[3];
    v14 += 4;
    *(_DWORD *)tmp42 = v15;
    *(_DWORD *)&tmp42[4] = v16;
    *(_DWORD *)&tmp42[8] = v17;
    *(_DWORD *)&tmp42[12] = v18;
    v19 = *v14;
    v20 = v14[1];
    v21 = v14[2];
    v22 = v14[3];
    v23 = v14[4];
    *(_DWORD *)&tmp42[16] = v19;
    *(_DWORD *)&tmp42[20] = v20;
    *(_DWORD *)&tmp42[24] = v21;
    *(_DWORD *)&tmp42[28] = v22;
    *(_WORD *)&tmp42[32] = v23;
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  v1 = v0;
  v2 = total_pools;
  v3 = pools;
  v4 = total_pools + 2;
  v1->pool_no = total_pools;
  v1->prio = v2;
  v5 = (pool **)realloc(v3, 4 * v4);
  v6 = total_pools;
  pools = v5;
  ++total_pools;
  v5[v6] = v1;
  if ( pthread_mutex_init(&v1->pool_lock, 0) )
  {
    v24 = _errno_location();
    LOWORD(v11) = -3136;
    v10 = *v24;
    HIWORD(v11) = (unsigned int)"iner" >> 16;
    v12 = 748;
    goto LABEL_11;
  }
  if ( pthread_cond_init(&v1->cr_cond, 0) )
  {
    LOWORD(v25) = 1300;
    HIWORD(v25) = (unsigned int)"d" >> 16;
    v26 = *v25;
    v27 = v25[1];
    v28 = v25[2];
    v29 = v25[3];
    v25 += 4;
    *(_DWORD *)tmp42 = v26;
    *(_DWORD *)&tmp42[4] = v27;
    *(_DWORD *)&tmp42[8] = v28;
    *(_DWORD *)&tmp42[12] = v29;
    v30 = *v25;
    v31 = v25[1];
    v32 = v25[2];
    v33 = v25[3];
    v25 += 4;
    *(_DWORD *)&tmp42[16] = v30;
    *(_DWORD *)&tmp42[20] = v31;
    *(_DWORD *)&tmp42[24] = v32;
    *(_DWORD *)&tmp42[28] = v33;
    v34 = v25[1];
    *(_DWORD *)&tmp42[32] = *v25;
    *(_DWORD *)&tmp42[36] = v34;
    goto LABEL_12;
  }
  if ( pthread_mutex_init(&v1->data_lock.mutex, 0) )
  {
    v35 = _errno_location();
    LOWORD(v11) = -3136;
    v10 = *v35;
    HIWORD(v11) = (unsigned int)"iner" >> 16;
    v12 = 751;
    goto LABEL_11;
  }
  if ( pthread_rwlock_init(&v1->data_lock.rwlock, 0) )
  {
    v36 = _errno_location();
    LOWORD(v38) = -3136;
    v37 = *v36;
    HIWORD(v38) = (unsigned int)"iner" >> 16;
    v39 = 751;
LABEL_18:
    LOWORD(v40) = -1076;
    HIWORD(v40) = (unsigned int)"hread_mutex_init errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v40, v37, v38, &_func___16209.__align + 2, v39);
LABEL_12:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  if ( pthread_mutex_init(&v1->stratum_lock, 0) )
  {
    v9 = _errno_location();
    LOWORD(v11) = -3136;
    v10 = *v9;
    HIWORD(v11) = (unsigned int)"iner" >> 16;
    v12 = 752;
LABEL_11:
    LOWORD(v13) = -1128;
    HIWORD(v13) = (unsigned int)"NonceTime" >> 16;
    snprintf(tmp42, 0x1000u, v13, v10, v11, &_func___16209.__align + 2, v12);
    goto LABEL_12;
  }
  if ( pthread_mutex_init(&v1->gbt_lock.mutex, 0) )
  {
    v41 = _errno_location();
    LOWORD(v11) = -3136;
    v10 = *v41;
    HIWORD(v11) = (unsigned int)"iner" >> 16;
    v12 = 753;
    goto LABEL_11;
  }
  if ( pthread_rwlock_init(&v1->gbt_lock.rwlock, 0) )
  {
    v42 = _errno_location();
    LOWORD(v38) = -3136;
    v37 = *v42;
    HIWORD(v38) = (unsigned int)"iner" >> 16;
    v39 = 753;
    goto LABEL_18;
  }
  LOWORD(v7) = 1340;
  HIWORD(v7) = (unsigned int)"Failed to pthread_cond_init in add_pool" >> 16;
  v1->rpc_proxy = 0;
  v1->rpc_req = v7;
  v1->curlring.next = &v1->curlring;
  v1->curlring.prev = &v1->curlring;
  v1->tv_idle.tv_sec = -1;
  v1->quota = 1;
  adjust_quota_gcd();
  return v1;
}
