int __cdecl add_reg_item(reg_list_item_t item)
{
  int i; // [sp+14h] [bp+14h]

  pthread_mutex_lock(&rs.reg_list_mutex);
  for ( i = 0; i <= 99; ++i )
  {
    if ( rs.reg_list_items[i].age < 0 )
    {
      rs.reg_list_items[i] = item;
      pthread_mutex_unlock(&rs.reg_list_mutex);
      return 1;
    }
  }
  pthread_mutex_unlock(&rs.reg_list_mutex);
  return -1;
}
