void __fastcall k_unlink_item(K_LIST *list, K_ITEM *item, const char *file, const char *func, const int line)
{
  int v5; // r6
  const char *v6; // r2
  __int64 v7; // r2
  char tmp42[4096]; // [sp+20h] [bp-1004h] BYREF

  if ( item->name != list->name )
  {
    LOWORD(v5) = 27080;
    HIWORD(v5) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v6) = 27688;
    HIWORD(v6) = (unsigned int)"Failed to calloc lock for list %s in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v6, list->name, "_k_unlink_item", item->name, file, func, line, v5, "_k_unlink_item", 312);
    applog(3, tmp42, 1);
    quit(1);
  }
  v7 = *(_QWORD *)&item->prev;
  if ( (_DWORD)v7 )
  {
    *(_DWORD *)(v7 + 8) = HIDWORD(v7);
    HIDWORD(v7) = item->next;
  }
  if ( HIDWORD(v7) )
    *(_DWORD *)(HIDWORD(v7) + 4) = item->prev;
  if ( list->head == item )
    list->head = item->next;
  if ( list->do_tail && list->tail == item )
    list->tail = item->prev;
  item->prev = 0;
  item->next = 0;
  --list->count;
}
