void __fastcall k_insert_after(
        K_LIST *list,
        K_ITEM *item,
        K_ITEM *after,
        const char *file,
        const char *func,
        const int line)
{
  const char *name; // r1
  const char *v9; // r2
  int v11; // r0
  const char *v12; // r3
  const char *v13; // r2
  k_item *next; // r3
  __int64 v15; // r2
  int v16; // r3
  const char *v17; // r2
  char tmp42[4096]; // [sp+20h] [bp-1004h] BYREF

  name = item->name;
  v9 = list->name;
  if ( name != list->name )
  {
    LOWORD(v11) = 27080;
    HIWORD(v11) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    v12 = v9;
    LOWORD(v13) = 27688;
    HIWORD(v13) = (unsigned int)"Failed to calloc lock for list %s in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v13, v12, "_k_insert_after", name, file, func, line, v11, "_k_insert_after", 286);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( !after )
  {
    LOWORD(v16) = 27080;
    HIWORD(v16) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v17) = 27828;
    HIWORD(v17) = (unsigned int)"() a %s item - from %s %s() line %d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v17, "_k_insert_after", list->name, file, func, line, v16, "_k_insert_after", 291);
    applog(3, tmp42, 1);
    quit(1);
  }
  item->prev = after;
  item->next = after->next;
  next = after->next;
  if ( next )
  {
    next->prev = item;
  }
  else if ( list->do_tail )
  {
    list->tail = item;
  }
  after->next = item;
  v15 = *(_QWORD *)&list->count;
  LODWORD(v15) = v15 + 1;
  ++HIDWORD(v15);
  *(_QWORD *)&list->count = v15;
}
