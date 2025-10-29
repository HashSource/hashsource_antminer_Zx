void __fastcall k_list_transfer_to_head(K_LIST *from, K_LIST *to, const char *file, const char *func, const int line)
{
  const char *name; // r0
  const char *v8; // r1
  k_item *head; // r2
  k_item *tail; // r3
  int count; // r1
  char tmp42[4096]; // [sp+20h] [bp-1000h] BYREF

  name = from->name;
  v8 = to->name;
  if ( name != v8 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "List %s can't %s() to a %s list - from %s %s() line %d in %s %s():%d",
      name,
      "_k_list_transfer_to_head",
      v8,
      file,
      func,
      line,
      "klist.c",
      "_k_list_transfer_to_head",
      338);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( !from->do_tail )
  {
    snprintf(
      tmp42,
      0x1000u,
      "List %s can't %s() - do_tail is false - from %s %s() line %d in %s %s():%d",
      from->name,
      "_k_list_transfer_to_head",
      file,
      func,
      line,
      "klist.c",
      "_k_list_transfer_to_head",
      343);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( from->head )
  {
    head = to->head;
    tail = from->tail;
    if ( head )
    {
      head->prev = tail;
      head = to->head;
    }
    else
    {
      to->tail = tail;
    }
    from->tail->next = head;
    to->head = from->head;
    from->tail = 0;
    count = from->count;
    from->head = 0;
    to->count += count;
    from->count = 0;
    to->count_up += from->count_up;
    from->count_up = 0;
  }
}
