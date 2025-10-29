void __fastcall k_list_transfer_to_tail(K_LIST *from, K_LIST *to, const char *file, const char *func, const int line)
{
  const char *name; // r0
  const char *v9; // r1
  int v10; // r6
  const char *v11; // r2
  k_item *head; // r3
  k_item *tail; // r2
  int count; // r1
  int v15; // r1
  const char *v16; // r2
  char tmp42[4096]; // [sp+20h] [bp-1000h] BYREF

  name = from->name;
  v9 = to->name;
  if ( name != v9 )
  {
    LOWORD(v10) = 27080;
    HIWORD(v10) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v11) = 27900;
    HIWORD(v11) = (unsigned int)"re a null item - from %s %s() line %d in %s %s():%d" >> 16;
    snprintf(
      tmp42,
      0x1000u,
      v11,
      name,
      "_k_list_transfer_to_tail",
      v9,
      file,
      func,
      line,
      v10,
      "_k_list_transfer_to_tail",
      368);
    applog(3, tmp42, 1);
    quit(1);
  }
  if ( !from->do_tail )
  {
    LOWORD(v15) = 27080;
    HIWORD(v15) = (unsigned int)"_k_list_transfer_to_tail" >> 16;
    LOWORD(v16) = 27612;
    HIWORD(v16) = (unsigned int)"it %d must be >= 0 in %s %s():%d" >> 16;
    snprintf(
      tmp42,
      0x1000u,
      v16,
      from->name,
      "_k_list_transfer_to_tail",
      file,
      func,
      line,
      v15,
      "_k_list_transfer_to_tail",
      373);
    applog(3, tmp42, 1);
    quit(1);
  }
  head = from->head;
  if ( head )
  {
    tail = to->tail;
    if ( tail )
    {
      tail->next = head;
      tail = to->tail;
    }
    else
    {
      to->head = head;
    }
    from->head->prev = tail;
    to->tail = from->tail;
    from->tail = 0;
    count = from->count;
    from->head = 0;
    to->count += count;
    from->count = 0;
    to->count_up += from->count_up;
    from->count_up = 0;
  }
}
