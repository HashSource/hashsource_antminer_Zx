void reg_list_init()
{
  int id; // [sp+4h] [bp+4h]

  rs.alive = 1;
  pthread_mutex_init(&rs.reg_list_mutex, 0);
  rs.reg_list_items = (reg_list_item_t *)calloc(0xCu, 0x64u);
  for ( id = 0; id <= 99; ++id )
    rs.reg_list_items[id].age = -1;
  pthread_create(&rs.p_reg_list, 0, (void *(*)(void *))reg_list_aging, 0);
}
