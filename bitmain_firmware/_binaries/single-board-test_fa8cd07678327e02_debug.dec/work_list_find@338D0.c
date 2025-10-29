void __cdecl work_list_find(uint8_t workid, uint8_t *work)
{
  int i; // [sp+Ch] [bp+Ch]

  pthread_mutex_lock(&work_list_info.work_list_mutex);
  for ( i = 0; i <= 9; ++i )
  {
    if ( workid == work_list_info.work_list[i].workid )
    {
      memcpy(work, work_list_info.work_list[i].work, work_list_info.work_len);
      break;
    }
  }
  pthread_mutex_unlock(&work_list_info.work_list_mutex);
}
