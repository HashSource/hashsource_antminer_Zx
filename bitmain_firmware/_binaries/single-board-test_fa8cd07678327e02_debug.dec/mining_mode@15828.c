void *__cdecl __noreturn mining_mode(void *args)
{
  char line[4096]; // [sp+418h] [bp+408h] BYREF
  uint64_t i; // [sp+1418h] [bp+1408h]
  runtime_base_t *runtime; // [sp+1424h] [bp+1414h]

  runtime = (runtime_base_t *)args;
  i = 0;
  puts("SILENTARMY mining mode ready");
  fflush((FILE *)stdout);
  while ( 1 )
  {
    do
      usleep(0x186A0u);
    while ( !read_last_line(line, 0x1000u, i == 0) );
    pthread_mutex_lock(&g_work_info.work_info_mutex);
    mining_parse_job(
      line,
      g_work_info.target,
      32,
      g_work_info.job_id,
      256,
      g_work_info.header,
      140,
      &g_work_info.fixed_nonce_bytes);
    user_send_work(runtime, g_work_info.header, 0, 0);
    pthread_mutex_unlock(&g_work_info.work_info_mutex);
  }
}
