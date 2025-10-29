// positive sp value has been detected, the output may be wrong!
void __fastcall sub_30D40(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v13; // r4
  char *v14; // r5
  _DWORD *v15; // r6
  pthread_t v16; // r0
  int v17; // r7
  _DWORD *v18; // r8
  char *v19; // r7
  int v20; // r8
  int v21; // r0
  char *v22; // r0
  int v23; // r7
  _DWORD *v24; // r8
  pthread_mutex_t **v25; // r7
  char *v26; // r10
  pthread_t v27; // r0
  pthread_mutex_t *v28; // r6
  char *v29; // r0
  int v30; // r11
  int v31; // r3
  int v32; // lr
  int v33; // r2
  int *v34; // r2
  int *v35; // r12
  int v36; // r1
  int v37; // t1
  signed int v38; // r3
  int lock; // r3
  _DWORD *v40; // r2
  _DWORD *v41; // r1
  int *all_created_runtime; // r0
  int *v43; // r12
  int v44; // t1
  int v45; // r3
  int v46; // r2
  int v47; // r7
  _DWORD *v48; // r8
  int v49; // r9
  int v50; // r7
  int v51; // r3
  int v52; // r7
  int v53; // r7
  void **v54; // r6
  void *v55; // r0
  void *v56; // t1
  _DWORD *v57; // r8
  int v58; // [sp-1094h] [bp-1094h]
  int v59; // [sp-1090h] [bp-1090h]
  _DWORD *v60; // [sp-1088h] [bp-1088h]
  _DWORD v61[1057]; // [sp-1084h] [bp-1084h] BYREF

  HIWORD(a4) = 19;
  logfmt_raw(v14, 0x1000u, 0, a4);
  V_UNLOCK();
  zlog(
    *v15,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/pool.c",
    138,
    "pool_change_function",
    20,
    773,
    20,
    v14);
  v16 = pthread_self();
  pthread_detach(v16);
  if ( dword_18689C )
  {
    v59 = 1;
    pthread_cancel(dword_18689C);
    dword_18689C = 0;
    usleep((__useconds_t)&stru_1869C.st_value);
  }
  else
  {
    v59 = 0;
  }
  if ( v58 > 0 )
  {
    v17 = 0;
    do
    {
      v18 = *(_DWORD **)(*(_DWORD *)(v13 + 84) + 4 * v17++);
      V_LOCK();
      logfmt_raw(v14, 0x1000u, 0, "before add pool, pool->pool_no = %d, pool->rpc_url = %s", *v18, v18[3]);
      V_UNLOCK();
      zlog(
        *v15,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/pool.c",
        138,
        "pool_change_function",
        20,
        789,
        20,
        v14);
    }
    while ( v58 != v17 );
  }
  if ( *(int *)(v13 + 388) > 0 )
  {
    v19 = (char *)&unk_173398;
    v20 = 0;
    do
    {
      v21 = sub_3006C();
      ++v20;
      sub_2F9E0((void **)(v21 + 12), (_BYTE *)(v21 + 28), v19);
      set_user(v19 + 256);
      v22 = v19 + 512;
      v19 += 768;
      set_pass(v22);
    }
    while ( *(_DWORD *)(v13 + 388) > v20 );
  }
  if ( *(_DWORD *)(v13 + 80) == v58 )
  {
    V_LOCK();
    logfmt_raw(v14, 0x1000u, 0, "Input pool error, try again");
    V_UNLOCK();
    zlog(
      *v15,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/pool.c",
      138,
      "pool_change_function",
      20,
      799,
      100,
      v14);
  }
  else
  {
    V_LOCK();
    logfmt_raw(v14, 0x1000u, 0, "total_pools = %d, need to remove %d pools", *(_DWORD *)(v13 + 80));
    V_UNLOCK();
    zlog(
      *v15,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/pool.c",
      138,
      "pool_change_function",
      20,
      803,
      20,
      v14);
    if ( *(int *)(v13 + 80) > 0 )
    {
      v23 = 0;
      do
      {
        v24 = *(_DWORD **)(*(_DWORD *)(v13 + 84) + 4 * v23++);
        V_LOCK();
        logfmt_raw(v14, 0x1000u, 0, "after add pool, pool->pool_no = %d, pool->rpc_url = %s", *v24, v24[3]);
        V_UNLOCK();
        zlog(
          *v15,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/pool.c",
          138,
          "pool_change_function",
          20,
          806,
          20,
          v14);
      }
      while ( *(_DWORD *)(v13 + 80) > v23 );
    }
    if ( v58 > 0 )
    {
      v25 = (pthread_mutex_t **)v61;
      v26 = (char *)&stratum_thr_info;
      v60 = v15;
      do
      {
        v27 = *((_DWORD *)v26 + 1);
        v28 = **(pthread_mutex_t ***)(v13 + 84);
        if ( v27 )
        {
          pthread_cancel(v27);
          *((_DWORD *)v26 + 1) = 0;
        }
        v29 = (char *)*((_DWORD *)v26 + 11);
        if ( v29 )
        {
          tq_free(v29);
          *((_DWORD *)v26 + 11) = 0;
        }
        pthread_mutex_lock(v28 + 76);
        v28[79].__size[20] = 0;
        pthread_mutex_unlock(v28 + 76);
        pthread_mutex_lock(v28 + 76);
        v28[79].__size[8] = 1;
        pthread_mutex_unlock(v28 + 76);
        v30 = *(_DWORD *)(v13 + 80);
        v31 = *(_DWORD *)(v13 + 88);
        v32 = v30 - 1;
        v33 = *(_DWORD *)(v13 + 92) - 1;
        --*(_DWORD *)(v13 + 96);
        *(_DWORD *)(v13 + 92) = v33;
        *(_DWORD *)(v13 + 88) = v31 - 1;
        if ( v30 > 0 )
        {
          v34 = *(int **)(v13 + 84);
          v35 = &v34[v30];
          do
          {
            v37 = *v34++;
            v36 = v37;
            v38 = *(_DWORD *)(v37 + 4);
            if ( v38 > (signed int)v28->__count )
              *(_DWORD *)(v36 + 4) = v38 - 1;
          }
          while ( v35 != v34 );
        }
        lock = v28->__lock;
        if ( v32 > v28->__lock )
        {
          v40 = (_DWORD *)(*(_DWORD *)(v13 + 84) + 4 * lock);
          do
          {
            v41 = (_DWORD *)v40[1];
            *v40++ = v41;
            *v41 = lock++;
          }
          while ( lock != v32 );
        }
        *v25++ = v28;
        v28->__lock = v30;
        v26 += 48;
        *(_DWORD *)(v13 + 80) = v32;
      }
      while ( v25 != &v61[v58] );
      v15 = v60;
    }
    *(_DWORD *)v14 = 0;
    all_created_runtime = (int *)get_all_created_runtime(v14);
    if ( *(int *)v14 > 0 )
    {
      v43 = &all_created_runtime[*(_DWORD *)v14];
      do
      {
        v44 = *all_created_runtime++;
        v45 = v44 + 495;
        v46 = v44 + 527;
        do
          *(_BYTE *)++v45 = 1;
        while ( v46 != v45 );
      }
      while ( v43 != all_created_runtime );
    }
    V_LOCK();
    logfmt_raw(v14, 0x1000u, 0, "total_pools after removed = %d", *(_DWORD *)(v13 + 80));
    V_UNLOCK();
    zlog(
      *v15,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/pool.c",
      138,
      "pool_change_function",
      20,
      831,
      20,
      v14);
    if ( *(int *)(v13 + 80) > 0 )
    {
      v47 = 0;
      do
      {
        v48 = *(_DWORD **)(*(_DWORD *)(v13 + 84) + 4 * v47++);
        V_LOCK();
        logfmt_raw(v14, 0x1000u, 0, "after reload pool, pool->pool_no = %d, pool->rpc_url = %s", *v48, v48[3]);
        V_UNLOCK();
        zlog(
          *v15,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/pool.c",
          138,
          "pool_change_function",
          20,
          834,
          20,
          v14);
      }
      while ( *(_DWORD *)(v13 + 80) > v47 );
    }
    V_LOCK();
    logfmt_raw(v14, 0x1000u, 0, "reload new pool configuration, check pool connect");
    V_UNLOCK();
    zlog(
      *v15,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/pool.c",
      138,
      "pool_change_function",
      20,
      837,
      40,
      v14);
    sleep(5u);
    v49 = *(unsigned __int8 *)(v13 + 384);
    if ( *(_BYTE *)(v13 + 384) )
    {
      create_pool_stratum_threads();
    }
    else if ( check_pools_valid() <= 0 )
    {
      V_LOCK();
      logfmt_raw(v14, 0x1000u, v49, "no new pools could be valid");
      V_UNLOCK();
      zlog(
        *v15,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/pool.c",
        138,
        "pool_change_function",
        20,
        848,
        40,
        v14);
    }
    v50 = 0;
    do
    {
      ++v50;
      sleep(1u);
      if ( v50 == 8 )
        v51 = 0;
      else
        v51 = (*(_BYTE *)(v13 + 385) ^ 1) & 1;
    }
    while ( v51 );
    set_miner_start_time();
    api_flush();
    v52 = *(unsigned __int8 *)(v13 + 385);
    if ( !*(_BYTE *)(v13 + 385) )
    {
      V_LOCK();
      logfmt_raw(v14, 0x1000u, v52, "error pool input");
      V_UNLOCK();
      zlog(
        *v15,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/pool.c",
        138,
        "pool_change_function",
        20,
        862,
        100,
        v14);
      if ( *(int *)(v13 + 80) > 0 )
      {
        do
        {
          v57 = *(_DWORD **)(*(_DWORD *)(v13 + 84) + 4 * v52++);
          V_LOCK();
          logfmt_raw(v14, 0x1000u, 0, "pool%d, url = %s, user = %s, pass = %s", *v57, v57[3], v57[4], v57[5]);
          V_UNLOCK();
          zlog(
            *v15,
            "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmi"
            "ner-origin_godminer-new/pool.c",
            138,
            "pool_change_function",
            20,
            865,
            100,
            v14);
        }
        while ( *(_DWORD *)(v13 + 80) > v52 );
      }
    }
  }
  if ( !v59
    || (dword_186898 = 2,
        pthread_attr_init(&attr),
        v53 = pthread_create((pthread_t *)&dword_18689C, &attr, (void *(*)(void *))watchpool_thread, &dword_186898),
        pthread_attr_destroy(&attr),
        !v53) )
  {
    sleep(0xAu);
    if ( v58 > 0 )
    {
      v54 = (void **)v61;
      do
      {
        v56 = *v54++;
        v55 = v56;
        if ( v56 )
          free(v55);
      }
      while ( &v61[v58] != v54 );
    }
    *(_DWORD *)(v13 + 2696) = 0;
    __asm { POP             {R4-R11,PC} }
  }
  V_LOCK();
  logfmt_raw(v14, 0x1000u, 0, "watchpool thread create failed!");
  V_UNLOCK();
  zlog(
    *v15,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/pool.c",
    138,
    "pool_change_function",
    20,
    875,
    100,
    v14);
  exit(1);
}
