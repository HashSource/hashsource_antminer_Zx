K_LIST *__fastcall k_free_store(K_LIST *store, const char *file, const char *func, const int line)
{
  int v5; // r0
  const char *v6; // r2
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( !store->is_store )
  {
    LOWORD(v5) = 27080;
    HIWORD(v5) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v6) = 28036;
    HIWORD(v6) = (unsigned int)"t %s() to a %s list - from %s %s() line %d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v6, store->name, "_k_free_store", file, func, line, v5, "_k_free_store", 424);
    applog(3, tmp42, 1);
    quit(1);
  }
  free(store);
  return 0;
}
