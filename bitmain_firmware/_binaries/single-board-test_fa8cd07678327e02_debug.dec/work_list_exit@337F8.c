void work_list_exit()
{
  int i; // [sp+4h] [bp+4h]

  for ( i = 0; i <= 9; ++i )
    free(work_list_info.work_list[i].work);
  pthread_mutex_destroy(&work_list_info.work_list_mutex);
}
