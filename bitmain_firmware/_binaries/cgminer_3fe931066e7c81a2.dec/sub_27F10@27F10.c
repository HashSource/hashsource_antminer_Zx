int __fastcall sub_27F10(pthread_rwlock_t *a1)
{
  int v2; // r2
  int v3; // r3
  unsigned int v4; // r1
  bool v5; // zf
  int *v6; // r3
  unsigned int nr_writers_queued; // r2
  int result; // r0

  a1[1].__lock = 0;
  if ( pthread_rwlock_wrlock(&stru_7B700) )
    sub_B480("enable_device", 10388);
  v2 = dword_7B628;
  v3 = dword_78720++;
  a1->__lock = v3;
  *(_DWORD *)(v2 + 4 * v3) = a1;
  if ( pthread_rwlock_unlock(&stru_7B700) )
    sub_B630("enable_device", 10390);
  off_75ED8();
  v5 = byte_7B7D0 == 0;
  if ( byte_7B7D0 )
    v6 = (int *)dword_78724;
  else
    v6 = &dword_7BB6C;
  if ( byte_7B7D0 )
  {
    nr_writers_queued = a1[4].__nr_writers_queued;
  }
  else
  {
    v4 = a1[4].__nr_writers_queued;
    nr_writers_queued = *v6;
  }
  if ( byte_7B7D0 )
    v6 = (int *)((char *)v6 + nr_writers_queued);
  else
    *v6 = v4 + nr_writers_queued;
  if ( !v5 )
    dword_78724 = (int)v6;
  result = pthread_rwlock_init(a1 + 10, 0);
  if ( result )
    sub_B558("enable_device", 10397);
  a1[11].__lock = 0;
  return result;
}
