int __fastcall sub_19FC8(pthread_rwlock_t *a1)
{
  pthread_rwlock_t *v1; // r8
  int lock; // r5
  int i; // r4
  struct timeval v6; // [sp+0h] [bp-8h] BYREF

  v1 = a1 + 10;
  sub_2A84C(&v6);
  if ( pthread_rwlock_wrlock(v1) )
    sub_B480("age_queued_work", 8950);
  lock = a1[11].__lock;
  if ( lock )
  {
    for ( i = *(_DWORD *)(lock + 1840); ; i = *(_DWORD *)(i + 1840) )
    {
      sub_2AA24();
      if ( !i )
        break;
    }
  }
  if ( pthread_rwlock_unlock(v1) )
    sub_B630("age_queued_work", 8960);
  off_75ED8();
  return 0;
}
