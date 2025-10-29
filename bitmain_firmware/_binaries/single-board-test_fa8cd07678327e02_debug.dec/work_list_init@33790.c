void __cdecl work_list_init(int work_len)
{
  int i; // [sp+Ch] [bp+Ch]

  memset(&work_list_info, 0, sizeof(work_list_info));
  work_list_info.work_len = work_len;
  pthread_mutex_init(&work_list_info.work_list_mutex, 0);
  for ( i = 0; i <= 9; ++i )
    work_list_info.work_list[i].work = (uint8_t *)calloc(work_len, 1u);
}
