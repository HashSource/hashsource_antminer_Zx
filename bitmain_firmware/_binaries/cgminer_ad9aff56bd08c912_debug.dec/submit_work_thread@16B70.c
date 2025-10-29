void *__fastcall submit_work_thread(void *userdata)
{
  pthread_t v1; // r0

  v1 = pthread_self();
  pthread_detach(v1);
  return 0;
}
