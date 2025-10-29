void *__fastcall get_all_created_runtime(_DWORD *a1)
{
  pthread_mutex_lock(&stru_184FC0);
  *a1 = dword_184FD8;
  pthread_mutex_unlock(&stru_184FC0);
  return &unk_184FDC;
}
