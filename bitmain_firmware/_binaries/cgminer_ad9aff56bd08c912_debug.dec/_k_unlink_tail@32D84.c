K_ITEM *__fastcall k_unlink_tail(K_LIST *list, const char *file, const char *func, const int line)
{
  K_ITEM *result; // r0
  k_item *prev; // r3
  int v7; // r0
  const char *v8; // r2
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( !list->do_tail )
  {
    LOWORD(v7) = 27080;
    HIWORD(v7) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v8) = 27612;
    HIWORD(v8) = (unsigned int)"it %d must be >= 0 in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v8, list->name, "_k_unlink_tail", file, func, line, v7, "_k_unlink_tail", 181);
    applog(3, tmp42, 1);
    quit(1);
  }
  result = list->tail;
  if ( result )
  {
    prev = result->prev;
    list->tail = prev;
    if ( prev )
      prev->next = 0;
    else
      list->head = 0;
    result->prev = 0;
    result->next = 0;
    --list->count;
  }
  return result;
}
