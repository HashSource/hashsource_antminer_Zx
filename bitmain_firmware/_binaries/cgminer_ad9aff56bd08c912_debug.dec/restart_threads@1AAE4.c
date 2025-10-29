int restart_threads()
{
  void *(*v0)(void *); // r2
  int result; // r0
  pthread_t newthread[2]; // [sp+4h] [bp-8h] BYREF

  cgtime(&restart_tv_start);
  LOWORD(v0) = 2265;
  HIWORD(v0) = ((unsigned int)&loc_2401E + 3) >> 16;
  result = pthread_create(newthread, 0, v0, 0);
  if ( result )
    restart_threads_0();
  return result;
}
