void __fastcall k_add_head(K_LIST *list, K_ITEM *item, const char *file, const char *func, const int line)
{
  int v5; // r6
  const char *v6; // r2
  k_item *head; // r3
  _BOOL4 do_tail; // r3
  __int64 v9; // r2
  char tmp42[4096]; // [sp+20h] [bp-1004h] BYREF

  if ( item->name != list->name )
  {
    LOWORD(v5) = 27080;
    HIWORD(v5) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v6) = 27688;
    HIWORD(v6) = (unsigned int)"Failed to calloc lock for list %s in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v6, list->name, "_k_add_head", item->name, file, func, line, v5, "_k_add_head", 205);
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
  v9 = *(_QWORD *)&list->count;
  LODWORD(v9) = v9 + 1;
  ++HIDWORD(v9);
  *(_QWORD *)&list->count = v9;
}
