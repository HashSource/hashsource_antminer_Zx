void __fastcall k_insert_before(
        K_LIST *list,
        K_ITEM *item,
        K_ITEM *before,
        const char *file,
        const char *func,
        const int line)
{
  const char *name; // r1
  k_item *prev; // r3
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
      "_k_insert_before",
      name,
      file,
      func,
      line,
      "klist.c",
      "_k_insert_before",
      262);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( !before )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s() (%s) can't before a null item - from %s %s() line %d in %s %s():%d",
      "_k_insert_before",
      list->name,
      file,
      func,
      line,
      "klist.c",
      "_k_insert_before",
      267);
    applog(3, tmp42, 1);
    quit(1);
  }
  item->next = before;
  item->prev = before->prev;
  prev = before->prev;
  if ( prev )
    prev->next = item;
  else
    list->head = item;
  before->prev = item;
  v9 = *(_QWORD *)&list->count;
  LODWORD(v9) = v9 + 1;
  ++HIDWORD(v9);
  *(_QWORD *)&list->count = v9;
}
