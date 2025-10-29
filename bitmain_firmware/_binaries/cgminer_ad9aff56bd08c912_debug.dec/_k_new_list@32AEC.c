K_LIST *__fastcall k_new_list(
        const char *name,
        size_t siz,
        int allocate,
        int limit,
        bool do_tail,
        const char *file,
        const char *func,
        const int line)
{
  K_LIST *v12; // r0
  K_LIST *v13; // r4
  pthread_mutex_t *v14; // r0
  pthread_mutex_t *v15; // r5
  const char *v17; // r2
  const char *v18; // r2
  const char *v19; // r2
  const char *v20; // r2
  int *v21; // r0
  int v22; // r1
  const char *v23; // r2
  int *v24; // r0
  const char *v25; // r2
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( allocate <= 0 )
  {
    LOWORD(v17) = 27396;
    HIWORD(v17) = (unsigned int)"c count=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v17, name, allocate, "klist.c", "_k_new_list", 100);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( limit < 0 )
  {
    LOWORD(v18) = 27460;
    HIWORD(v18) = (unsigned int)"n %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v18, name, limit, "klist.c", "_k_new_list", 103);
    applog(3, tmp42, 1);
    quit(1);
  }
  v12 = (K_LIST *)calloc(1u, 0x40u);
  v13 = v12;
  if ( !v12 )
  {
    LOWORD(v19) = 27524;
    HIWORD(v19) = (unsigned int)"lid new list %s with allocate %d must be > 0 in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v19, name, "klist.c", "_k_new_list", 107);
    applog(3, tmp42, 1);
    quit(1);
  }
  v12->is_store = 0;
  v14 = (pthread_mutex_t *)calloc(1u, 0x38u);
  v15 = v14;
  v13->lock = (cglock_t *)v14;
  if ( !v14 )
  {
    LOWORD(v20) = 27564;
    HIWORD(v20) = (unsigned int)" > 0 in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v20, name, "klist.c", "_k_new_list", 113);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_mutex_init(v14, 0) )
  {
    v21 = _errno_location();
    LOWORD(v22) = 27080;
    HIWORD(v22) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v23) = -1128;
    HIWORD(v23) = (unsigned int)"NonceTime" >> 16;
    snprintf(tmp42, 0x1000u, v23, *v21, v22, "_k_new_list", 115);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_rwlock_init((pthread_rwlock_t *)&v15[1], 0) )
  {
    v24 = _errno_location();
    LOWORD(v25) = -1076;
    HIWORD(v25) = (unsigned int)"hread_mutex_init errno=%d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v25, *v24, "klist.c", "_k_new_list", 115);
    applog(3, tmp42, 1);
    quit(1);
  }
  v13->name = name;
  v13->siz = siz;
  v13->allocate = allocate;
  v13->limit = limit;
  v13->do_tail = do_tail;
  k_alloc_items(v13, file, func, line);
  return v13;
}
