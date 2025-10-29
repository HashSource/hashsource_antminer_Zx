int __fastcall sub_27E68(pthread_rwlock_t *a1)
{
  int v2; // r2
  int v3; // r3
  unsigned int v4; // r1
  bool v5; // zf
  int *v6; // r3
  unsigned int nr_writers_queued; // r2
  int result; // r0

  a1[1].__lock = 0;
  if ( pthread_rwlock_wrlock(&stru_78528) )
    sub_B3C8("enable_device", 10375);
  v2 = dword_78450;
  v3 = dword_7555C++;
  a1->__lock = v3;
  *(_DWORD *)(v2 + 4 * v3) = a1;
  if ( pthread_rwlock_unlock(&stru_78528) )
    sub_B578("enable_device", 10377);
  off_72D18();
  v5 = byte_785F8 == 0;
  if ( byte_785F8 )
    v6 = (int *)dword_75560;
  else
    v6 = &dword_78994;
  if ( byte_785F8 )
  {
    nr_writers_queued = a1[4].__nr_writers_queued;
  }
  else
  {
    v4 = a1[4].__nr_writers_queued;
    nr_writers_queued = *v6;
  }
  if ( byte_785F8 )
    v6 = (int *)((char *)v6 + nr_writers_queued);
  else
    *v6 = v4 + nr_writers_queued;
  if ( !v5 )
    dword_75560 = (int)v6;
  result = pthread_rwlock_init(a1 + 10, 0);
  if ( result )
    sub_B4A0("enable_device", 10384);
  a1[11].__lock = 0;
  return result;
}
