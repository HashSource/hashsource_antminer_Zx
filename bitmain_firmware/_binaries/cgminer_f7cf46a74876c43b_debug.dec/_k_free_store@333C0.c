K_LIST *__fastcall k_free_store(K_LIST *store, const char *file, const char *func, const int line)
{
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( !store->is_store )
  {
    snprintf(
      tmp42,
      0x1000u,
      "Store %s can't %s() the list - from %s %s() line %d in %s %s():%d",
      store->name,
      "_k_free_store",
      file,
      func,
      line,
      "klist.c",
      "_k_free_store",
      424);
    applog(3, tmp42, 1);
    quit(1);
  }
  free(store);
  return 0;
}
