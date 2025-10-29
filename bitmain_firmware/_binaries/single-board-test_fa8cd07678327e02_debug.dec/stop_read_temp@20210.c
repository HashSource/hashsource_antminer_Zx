void stop_read_temp()
{
  pthread_cancel(cgpu.read_temp);
  pthread_join(cgpu.read_temp, 0);
}
