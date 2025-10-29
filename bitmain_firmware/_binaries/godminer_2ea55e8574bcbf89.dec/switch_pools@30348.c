int switch_pools()
{
  char *v0; // r8
  int v1; // r6
  _DWORD *v2; // r7
  int v3; // r12
  int v4; // r4
  int v5; // r3
  int v6; // r2
  pthread_mutex_t *v7; // r11
  pthread_mutex_t *v8; // t1
  int v9; // r9
  _DWORD *v10; // r4
  int result; // r0
  int lock; // [sp+14h] [bp-1010h]
  char v13[4100]; // [sp+20h] [bp-1004h] BYREF

  pthread_mutex_lock(&mutex);
  v1 = dword_17322C;
  v2 = (_DWORD *)(unsigned __int16)&g_zc;
  v3 = total_pools;
  if ( total_pools <= 0 )
  {
    v0 = v13;
    HIWORD(v2) = (unsigned int)&g_zc >> 16;
  }
  lock = *(_DWORD *)dword_17322C;
  if ( total_pools > 0 )
  {
    HIWORD(v2) = 24;
    v4 = 0;
    v0 = v13;
    while ( 1 )
    {
      v5 = 0;
      v6 = pools - 4;
      while ( 1 )
      {
        v8 = *(pthread_mutex_t **)(v6 + 4);
        v6 += 4;
        v7 = v8;
        ++v5;
        if ( v8->__count == v4 )
          break;
        if ( v3 <= v5 )
        {
          V_LOCK();
          logfmt_raw(v13, 0x1000u, 0, "WTF No pool %d found!", v4);
          V_UNLOCK();
          zlog(
            *v2,
            "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmi"
            "ner-origin_godminer-new/pool.c",
            138,
            "priority_pool",
            13,
            252,
            100,
            v13);
          v7 = *(pthread_mutex_t **)(pools + 4 * v4);
          break;
        }
      }
      pthread_mutex_lock(v7 + 76);
      v9 = (unsigned __int8)v7[79].__size[8];
      pthread_mutex_unlock(v7 + 76);
      if ( !v9 )
        break;
      v3 = total_pools;
      if ( total_pools <= ++v4 )
        goto LABEL_11;
    }
    lock = v7->__lock;
  }
LABEL_11:
  v10 = *(_DWORD **)(pools + 4 * lock);
  pthread_mutex_unlock(&mutex);
  set_current_pool((int)v10);
  V_LOCK();
  logfmt_raw(v0, 0x1000u, 0, "Switching pool %d to pool %d", *(_DWORD *)v1, *v10);
  V_UNLOCK();
  result = zlog(
             *v2,
             "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godm"
             "iner-origin_godminer-new/pool.c",
             138,
             "switch_pools",
             12,
             364,
             40,
             v0);
  if ( (_DWORD *)v1 != v10 )
  {
    pthread_mutex_lock((pthread_mutex_t *)(v1 + 1824));
    pthread_cond_broadcast((pthread_cond_t *)(v1 + 1856));
    return pthread_mutex_unlock((pthread_mutex_t *)(v1 + 1824));
  }
  return result;
}
