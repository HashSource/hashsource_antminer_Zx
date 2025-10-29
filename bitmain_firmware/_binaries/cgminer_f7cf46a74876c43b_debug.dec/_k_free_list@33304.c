K_LIST *__fastcall k_free_list(K_LIST *list, const char *file, const char *func, const int line)
{
  int v5; // r5
  void *v6; // r0
  int v7; // r5
  void *v8; // r0
  cglock_t *lock; // r5
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( list->is_store )
  {
    snprintf(
      tmp42,
      0x1000u,
      "List %s can't %s() a store - from %s %s() line %d in %s %s():%d",
      list->name,
      "_k_free_list",
      file,
      func,
      line,
      "klist.c",
      "_k_free_list",
      400);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( list->item_mem_count > 0 )
  {
    v5 = 0;
    do
    {
      v6 = list->item_memory[v5++];
      free(v6);
    }
    while ( list->item_mem_count > v5 );
  }
  free(list->item_memory);
  if ( list->data_mem_count > 0 )
  {
    v7 = 0;
    do
    {
      v8 = list->data_memory[v7++];
      free(v8);
    }
    while ( list->data_mem_count > v7 );
  }
  free(list->data_memory);
  lock = list->lock;
  pthread_rwlock_destroy(&lock->rwlock);
  pthread_mutex_destroy(&lock->mutex);
  free(list->lock);
  free(list);
  return 0;
}
