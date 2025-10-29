int __fastcall thr_info_create(thr_info *thr, pthread_attr_t *attr, void *(*start)(void *), void *arg)
{
  const char *v5; // r1

  LOWORD(v5) = 15984;
  HIWORD(v5) = (unsigned int)"pecified for socks4 proxy: %s" >> 16;
  cgsem_init(&thr->sem, v5, "thr_info_create", 1312);
  return j_pthread_create(&thr->pth, attr, start, arg);
}
