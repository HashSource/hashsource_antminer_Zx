void reg_list_exit()
{
  rs.alive = 0;
  usleep(0x16E360u);
  pthread_cancel(rs.p_reg_list);
  pthread_join(rs.p_reg_list, 0);
  free(rs.reg_list_items);
  pthread_mutex_destroy(&rs.reg_list_mutex);
}
