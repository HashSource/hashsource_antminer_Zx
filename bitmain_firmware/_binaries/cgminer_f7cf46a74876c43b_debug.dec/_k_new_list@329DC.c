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
  int *v17; // r0
  int *v18; // r0
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( allocate <= 0 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "Invalid new list %s with allocate %d must be > 0 in %s %s():%d",
      name,
      allocate,
      "klist.c",
      "_k_new_list",
      100);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( limit < 0 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "Invalid new list %s with limit %d must be >= 0 in %s %s():%d",
      name,
      limit,
      "klist.c",
      "_k_new_list",
      103);
    applog(3, tmp42, 1);
    quit(1);
  }
  v12 = (K_LIST *)calloc(1u, 0x40u);
  v13 = v12;
  if ( !v12 )
  {
    snprintf(tmp42, 0x1000u, "Failed to calloc list %s in %s %s():%d", name, "klist.c", "_k_new_list", 107);
    applog(3, tmp42, 1);
    quit(1);
  }
  v12->is_store = 0;
  v14 = (pthread_mutex_t *)calloc(1u, 0x38u);
  v15 = v14;
  v13->lock = (cglock_t *)v14;
  if ( !v14 )
  {
    snprintf(tmp42, 0x1000u, "Failed to calloc lock for list %s in %s %s():%d", name, "klist.c", "_k_new_list", 113);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_mutex_init(v14, 0) )
  {
    v17 = _errno_location();
    snprintf(tmp42, 0x1000u, "Failed to pthread_mutex_init errno=%d in %s %s():%d", *v17, "klist.c", "_k_new_list", 115);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( pthread_rwlock_init((pthread_rwlock_t *)&v15[1], 0) )
  {
    v18 = _errno_location();
    snprintf(
      tmp42,
      0x1000u,
      "Failed to pthread_rwlock_init errno=%d in %s %s():%d",
      *v18,
      "klist.c",
      "_k_new_list",
      115);
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
