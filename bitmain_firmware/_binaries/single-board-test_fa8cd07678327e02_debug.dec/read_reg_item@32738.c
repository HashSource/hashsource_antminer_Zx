int __cdecl read_reg_item(reg_list_item_t *item, int ms)
{
  int v3; // r3
  int i; // [sp+10h] [bp+10h]
  int check_times; // [sp+14h] [bp+14h]

  check_times = ms % 50 + ms / 50;
  do
  {
    usleep(0xC350u);
    pthread_mutex_lock(&rs.reg_list_mutex);
    for ( i = 0; i <= 99; ++i )
    {
      if ( rs.reg_list_items[i].chainid == item->chainid
        && rs.reg_list_items[i].chip_addr == item->chip_addr
        && rs.reg_list_items[i].reg_addr == item->reg_addr
        && rs.reg_list_items[i].age >= 0 )
      {
        item->reg_data = rs.reg_list_items[i].reg_data;
        rs.reg_list_items[i].age = -1;
        pthread_mutex_unlock(&rs.reg_list_mutex);
        return 1;
      }
    }
    pthread_mutex_unlock(&rs.reg_list_mutex);
    v3 = check_times--;
  }
  while ( v3 > 0 );
  return -1;
}
