K_ITEM *__fastcall k_unlink_tail(K_LIST *list, const char *file, const char *func, const int line)
{
  K_ITEM *result; // r0
  k_item *prev; // r3
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( !list->do_tail )
  {
    snprintf(
      tmp42,
      0x1000u,
      "List %s can't %s() - do_tail is false - from %s %s() line %d in %s %s():%d",
      list->name,
      "_k_unlink_tail",
      file,
      func,
      line,
      "klist.c",
      "_k_unlink_tail",
      181);
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
