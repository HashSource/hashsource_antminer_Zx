void *__fastcall mcast_thread(void *userdata)
{
  pthread_t v2; // r0

  v2 = pthread_self();
  pthread_detach(v2);
  pthread_setcanceltype(1, 0);
  RenameThread("APIMcast");
  mcast();
  *((_DWORD *)userdata + 3) = 0;
  return 0;
}
