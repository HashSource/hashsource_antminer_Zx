void *__fastcall sub_2F0AC(sem_t *a1)
{
  pthread_setcanceltype(1, 0);
  ((void (__fastcall *)(_DWORD))a1[1].__align)(*(&a1[1].__align + 1));
  sub_2F02C(a1, "util.c", "completion_thread", 3944);
  return 0;
}
