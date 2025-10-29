void *__fastcall completion_thread(void *arg)
{
  const char *v2; // r1

  pthread_setcanceltype(1, 0);
  (*((void (__fastcall **)(_DWORD))arg + 4))(*((_DWORD *)arg + 5));
  LOWORD(v2) = 15984;
  HIWORD(v2) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
  cgsem_post((cgsem_t *)arg, v2, "completion_thread", 3963);
  return 0;
}
