void *__fastcall completion_thread(void *arg)
{
  pthread_setcanceltype(1, 0);
  (*((void (__fastcall **)(_DWORD))arg + 4))(*((_DWORD *)arg + 5));
  cgsem_post((cgsem_t *)arg, "util.c", "completion_thread", 3963);
  return 0;
}
