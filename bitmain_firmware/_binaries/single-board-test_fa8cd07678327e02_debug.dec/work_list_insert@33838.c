void __cdecl work_list_insert(uint8_t workid, uint8_t *work)
{
  pthread_mutex_lock(&work_list_info.work_list_mutex);
  work_list_info.work_list[work_list_info.work_list_insert_index].workid = workid;
  memcpy(work_list_info.work_list[work_list_info.work_list_insert_index].work, work, work_list_info.work_len);
  if ( ++work_list_info.work_list_insert_index > 9 )
    work_list_info.work_list_insert_index = 0;
  pthread_mutex_unlock(&work_list_info.work_list_mutex);
}
