K_ITEM *__fastcall k_unlink_head(K_LIST *list, const char *file, const char *func, const int line)
{
  k_item *head; // r4
  k_item *next; // r3

  head = list->head;
  if ( !head )
  {
    if ( list->is_store )
      return 0;
    k_alloc_items(list, file, func, line);
    head = list->head;
    if ( !head )
      return 0;
  }
  next = head->next;
  list->head = next;
  if ( next )
  {
    next->prev = 0;
  }
  else if ( list->do_tail )
  {
    list->tail = 0;
  }
  head->prev = 0;
  head->next = 0;
  --list->count;
  return head;
}
