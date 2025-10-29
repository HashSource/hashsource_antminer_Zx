int __fastcall thr_info_create(thr_info *thr, pthread_attr_t *attr, void *(*start)(void *), void *arg)
{
  cgsem_init(&thr->sem, "util.c", "thr_info_create", 1312);
  return j_pthread_create(&thr->pth, attr, start, arg);
}
