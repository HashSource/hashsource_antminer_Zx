void start_read_temp()
{
  user_i2c_enable(cgpu.runtime, gChain);
  usleep(0xC350u);
  pthread_create(&cgpu.read_temp, 0, (void *(*)(void *))read_all_sensor, 0);
}
