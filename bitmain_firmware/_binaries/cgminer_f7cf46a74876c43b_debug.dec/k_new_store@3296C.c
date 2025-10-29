K_LIST *__fastcall k_new_store(K_LIST *list)
{
  K_LIST *result; // r0
  const char *name; // r3
  cglock_t *lock; // r6
  bool do_tail; // r1
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  result = (K_LIST *)calloc(1u, 0x40u);
  name = list->name;
  if ( !result )
  {
    snprintf(tmp42, 0x1000u, "Failed to calloc store for %s in %s %s():%d", name, "klist.c", "k_new_store", 85);
    applog(3, tmp42, 1);
    quit(1);
  }
  lock = list->lock;
  do_tail = list->do_tail;
  result->name = name;
  result->lock = lock;
  result->do_tail = do_tail;
  result->is_store = 1;
  return result;
}
