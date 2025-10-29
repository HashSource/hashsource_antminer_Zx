int miner_monitor_stop()
{
  stop_task_timer(dword_17558C);
  return stop_task_timer(dword_175588);
}
