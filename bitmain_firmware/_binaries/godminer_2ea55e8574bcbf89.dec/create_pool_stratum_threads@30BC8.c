int create_pool_stratum_threads()
{
  char *v0; // r5
  int v1; // r4
  int v2; // r7
  char *v3; // r0
  int v4; // r7

  byte_173390 = 1;
  set_current_pool(*(_DWORD *)pools);
  if ( total_pools <= 0 )
    return 0;
  v0 = (char *)&stratum_thr_info;
  v1 = 0;
  while ( 1 )
  {
    v2 = *(_DWORD *)(pools + 4 * v1);
    if ( !*(_BYTE *)(v2 + 28) )
      goto LABEL_3;
    *(_DWORD *)v0 = v1 + 4;
    v3 = tq_new();
    *((_DWORD *)v0 + 11) = v3;
    if ( !v3 )
      return -1;
    tq_push((int)v3, v2);
    pthread_attr_init((pthread_attr_t *)(v0 + 8));
    v4 = pthread_create((pthread_t *)v0 + 1, (const pthread_attr_t *)(v0 + 8), (void *(*)(void *))stratum_thread, v0);
    pthread_attr_destroy((pthread_attr_t *)(v0 + 8));
    if ( v4 )
      return sub_2FC60();
LABEL_3:
    ++v1;
    v0 += 48;
    if ( total_pools <= v1 )
      return 0;
  }
}
