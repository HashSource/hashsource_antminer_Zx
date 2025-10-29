int __fastcall sub_19A20(pthread_rwlock_t *a1)
{
  pthread_rwlock_t *v1; // r8
  int lock; // r5
  int i; // r4
  struct timeval v6; // [sp+0h] [bp-8h] BYREF

  v1 = a1 + 10;
  sub_2B13C(&v6);
  if ( pthread_rwlock_wrlock(v1) )
    sub_B550("age_queued_work", 8954);
  lock = a1[11].__lock;
  if ( lock )
  {
    for ( i = *(_DWORD *)(lock + 352); ; i = *(_DWORD *)(i + 352) )
    {
      sub_2B314();
      if ( !i )
        break;
    }
  }
  if ( pthread_rwlock_unlock(v1) )
    sub_B700("age_queued_work", 8964);
  off_60178();
  return 0;
}
