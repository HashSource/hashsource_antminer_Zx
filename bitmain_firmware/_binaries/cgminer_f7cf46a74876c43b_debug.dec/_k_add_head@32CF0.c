void __fastcall k_add_head(K_LIST *list, K_ITEM *item, const char *file, const char *func, const int line)
{
  k_item *head; // r3
  _BOOL4 do_tail; // r3
  __int64 v7; // r2
  char tmp42[4096]; // [sp+20h] [bp-1004h] BYREF

  if ( item->name != list->name )
  {
    snprintf(
      tmp42,
      0x1000u,
      "List %s can't %s() a %s item - from %s %s() line %d in %s %s():%d",
      list->name,
      "_k_add_head",
      item->name,
      file,
      func,
      line,
      "klist.c",
      "_k_add_head",
      205);
    applog(3, tmp42, 1);
    quit(1);
  }
  item->prev = 0;
  item->next = list->head;
  head = list->head;
  if ( head )
    head->prev = item;
  do_tail = list->do_tail;
  list->head = item;
  if ( do_tail && !list->tail )
    list->tail = item;
  v7 = *(_QWORD *)&list->count;
  LODWORD(v7) = v7 + 1;
  ++HIDWORD(v7);
  *(_QWORD *)&list->count = v7;
}
