K_LIST *__fastcall k_free_list(K_LIST *list, const char *file, const char *func, const int line)
{
  int v5; // r5
  void *v6; // r0
  int v7; // r5
  void *v8; // r0
  cglock_t *lock; // r5
  int v11; // r0
  const char *v12; // r2
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( list->is_store )
  {
    LOWORD(v11) = 27080;
    HIWORD(v11) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v12) = 27972;
    HIWORD(v12) = (unsigned int)"r a null item - from %s %s() line %d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v12, list->name, "_k_free_list", file, func, line, v11, "_k_free_list", 400);
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
