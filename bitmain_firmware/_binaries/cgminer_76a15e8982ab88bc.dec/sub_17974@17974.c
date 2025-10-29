char *sub_17974()
{
  char *v0; // r4
  int v1; // r3
  void *v2; // r0
  int v3; // r1
  _DWORD *v4; // r0
  int v5; // r12
  char v7[4096]; // [sp+0h] [bp-1000h] BYREF

  v0 = (char *)calloc(0x750u, 1u);
  if ( !v0 )
  {
    strcpy(v7, "Failed to malloc pool in add_pool");
    sub_385C8(3, v7, 1);
    sub_16BE0(1);
  }
  v1 = dword_77FC0;
  v2 = (void *)dword_78260;
  v3 = dword_77FC0 + 2;
  *((_DWORD *)v0 + 1) = dword_77FC0;
  *(_DWORD *)v0 = v1;
  v4 = realloc(v2, 4 * v3);
  v5 = dword_77FC0 + 1;
  dword_78260 = (int)v4;
  v4[dword_77FC0] = v0;
  dword_77FC0 = v5;
  if ( pthread_mutex_init((pthread_mutex_t *)(v0 + 220), 0) )
    sub_B434("add_pool", 748);
  if ( pthread_cond_init((pthread_cond_t *)(v0 + 328), 0) )
  {
    strcpy(v7, "Failed to pthread_cond_init in add_pool");
    sub_385C8(3, v7, 1);
    sub_16BE0(1);
  }
  if ( pthread_mutex_init((pthread_mutex_t *)(v0 + 244), 0) )
    sub_B434("add_pool", 751);
  if ( pthread_rwlock_init((pthread_rwlock_t *)(v0 + 268), 0) )
    sub_B4A0("add_pool", 751);
  if ( pthread_mutex_init((pthread_mutex_t *)(v0 + 728), 0) )
    sub_B434("add_pool", 752);
  if ( pthread_mutex_init((pthread_mutex_t *)(v0 + 764), 0) )
    sub_B434("add_pool", 753);
  if ( pthread_rwlock_init((pthread_rwlock_t *)(v0 + 788), 0) )
    sub_B4A0("add_pool", 753);
  *((_DWORD *)v0 + 94) = v0 + 376;
  *((_DWORD *)v0 + 95) = v0 + 376;
  *((_DWORD *)v0 + 48) = "{\"method\": \"getwork\", \"params\": [], \"id\":0}\n";
  *((_DWORD *)v0 + 42) = -1;
  *((_DWORD *)v0 + 54) = 0;
  *((_DWORD *)v0 + 14) = 1;
  sub_15218();
  return v0;
}
