void __fastcall k_unlink_item(K_LIST *list, K_ITEM *item, const char *file, const char *func, const int line)
{
  __int64 v5; // r2
  char tmp42[4096]; // [sp+20h] [bp-1004h] BYREF

  if ( item->name != list->name )
  {
    snprintf(
      tmp42,
      0x1000u,
      "List %s can't %s() a %s item - from %s %s() line %d in %s %s():%d",
      list->name,
      "_k_unlink_item",
      item->name,
      file,
      func,
      line,
      "klist.c",
      "_k_unlink_item",
      312);
    applog(3, tmp42, 1);
    quit(1);
  }
  v5 = *(_QWORD *)&item->prev;
  if ( (_DWORD)v5 )
  {
    *(_DWORD *)(v5 + 8) = HIDWORD(v5);
    HIDWORD(v5) = item->next;
  }
  if ( HIDWORD(v5) )
    *(_DWORD *)(HIDWORD(v5) + 4) = item->prev;
  if ( list->head == item )
    list->head = item->next;
  if ( list->do_tail && list->tail == item )
    list->tail = item->prev;
  item->prev = 0;
  item->next = 0;
  --list->count;
}
