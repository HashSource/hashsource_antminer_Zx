void *reg_list_aging()
{
  pthread_t v0; // r0
  int i; // [sp+4h] [bp+4h]

  v0 = pthread_self();
  pthread_detach(v0);
  while ( rs.alive == 1 )
  {
    sleep(1u);
    pthread_mutex_lock(&rs.reg_list_mutex);
    for ( i = 0; i <= 99; ++i )
    {
      if ( rs.reg_list_items[i].age >= 0 )
        --rs.reg_list_items[i].age;
    }
    pthread_mutex_unlock(&rs.reg_list_mutex);
  }
  return 0;
}
