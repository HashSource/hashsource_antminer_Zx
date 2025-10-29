void __fastcall k_insert_after(
        K_LIST *list,
        K_ITEM *item,
        K_ITEM *after,
        const char *file,
        const char *func,
        const int line)
{
  const char *name; // r1
  k_item *next; // r3
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
      "_k_insert_after",
      name,
      file,
      func,
      line,
      "klist.c",
      "_k_insert_after",
      286);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( !after )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s() (%s) can't after a null item - from %s %s() line %d in %s %s():%d",
      "_k_insert_after",
      list->name,
      file,
      func,
      line,
      "klist.c",
      "_k_insert_after",
      291);
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
  v9 = *(_QWORD *)&list->count;
  LODWORD(v9) = v9 + 1;
  ++HIDWORD(v9);
  *(_QWORD *)&list->count = v9;
}
