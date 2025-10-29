void __fastcall k_add_tail(K_LIST *list, K_ITEM *item, const char *file, const char *func, const int line)
{
  const char *name; // r1
  const char *v8; // r2
  int v9; // r0
  const char *v10; // r3
  const char *v11; // r2
  k_item *tail; // r3
  k_item *head; // r3
  __int64 v14; // r2
  int v15; // r1
  const char *v16; // r2
  char tmp42[4096]; // [sp+20h] [bp-1004h] BYREF

  name = item->name;
  v8 = list->name;
  if ( name != list->name )
  {
    LOWORD(v9) = 27080;
    HIWORD(v9) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    v10 = v8;
    LOWORD(v11) = 27688;
    HIWORD(v11) = (unsigned int)"Failed to calloc lock for list %s in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v11, v10, "_k_add_tail", name, file, func, line, v9, "_k_add_tail", 236);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( !list->do_tail )
  {
    LOWORD(v15) = 27080;
    HIWORD(v15) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v16) = 27612;
    HIWORD(v16) = (unsigned int)"it %d must be >= 0 in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v16, list->name, "_k_add_tail", file, func, line, v15, "_k_add_tail", 241);
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
  v14 = *(_QWORD *)&list->count;
  LODWORD(v14) = v14 + 1;
  ++HIDWORD(v14);
  *(_QWORD *)&list->count = v14;
}
