int __fastcall sub_1A244(pthread_rwlock_t *a1)
{
  pthread_rwlock_t *v1; // r8
  int lock; // r5
  int i; // r4
  struct timeval v6; // [sp+0h] [bp-8h] BYREF

  v1 = a1 + 10;
  sub_2A7A4(&v6);
  if ( pthread_rwlock_wrlock(v1) )
    sub_B3C8("age_queued_work", 8937);
  lock = a1[11].__lock;
  if ( lock )
  {
    for ( i = *(_DWORD *)(lock + 1840); ; i = *(_DWORD *)(i + 1840) )
    {
      sub_2A97C();
      if ( !i )
        break;
    }
  }
  if ( pthread_rwlock_unlock(v1) )
    sub_B578("age_queued_work", 8947);
  off_72D18();
  return 0;
}
