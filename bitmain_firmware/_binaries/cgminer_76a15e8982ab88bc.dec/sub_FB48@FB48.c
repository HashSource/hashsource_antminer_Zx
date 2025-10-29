void *__fastcall sub_FB48(void *a1)
{
  pthread_t v1; // r0

  v1 = pthread_self();
  pthread_detach(v1);
  return 0;
}
