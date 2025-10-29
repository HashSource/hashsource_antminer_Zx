void *__fastcall api_thread(void *userdata)
{
  pthread_t v2; // r0

  v2 = pthread_self();
  pthread_detach(v2);
  pthread_setcanceltype(1, 0);
  RenameThread("API");
  set_lowprio();
  api(api_thr_id);
  *((_DWORD *)userdata + 3) = 0;
  return 0;
}
