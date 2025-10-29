void __fastcall k_add_tail(K_LIST *list, K_ITEM *item, const char *file, const char *func, const int line)
{
  const char *name; // r1
  k_item *tail; // r3
  k_item *head; // r3
  __int64 v9; // r2
  char tmp42[4096]; // [sp+20h] [bp-1004h] BYREF

  name = item->name;
  if ( name != list->name )
  {
    snprintf(
      tmp42,
      0x1000u,
      "List %s can't %s() a %s item - from %s %s() line %d in %s %s():%d",
      list->name,
      "_k_add_tail",
      name,
      file,
      func,
      line,
      "klist.c",
      "_k_add_tail",
      236);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( !list->do_tail )
  {
    snprintf(
      tmp42,
      0x1000u,
      "List %s can't %s() - do_tail is false - from %s %s() line %d in %s %s():%d",
      list->name,
      "_k_add_tail",
      file,
      func,
      line,
      "klist.c",
      "_k_add_tail",
      241);
    applog(3, tmp42, 1);
    quit(1);
  }
  item->prev = list->tail;
  item->next = 0;
  tail = list->tail;
  if ( tail )
    tail->next = item;
  head = list->head;
  list->tail = item;
  if ( !head )
    list->head = item;
  v9 = *(_QWORD *)&list->count;
  LODWORD(v9) = v9 + 1;
  ++HIDWORD(v9);
  *(_QWORD *)&list->count = v9;
}
