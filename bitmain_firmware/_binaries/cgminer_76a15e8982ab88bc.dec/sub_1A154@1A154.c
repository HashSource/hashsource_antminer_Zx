void __fastcall sub_1A154(pthread_rwlock_t *a1, void **a2)
{
  pthread_rwlock_t *v2; // r5

  v2 = a1 + 10;
  if ( pthread_rwlock_wrlock(a1 + 10) )
    sub_B3C8("work_completed", 8956);
  sub_16A78((int)a1, a2);
  if ( pthread_rwlock_unlock(v2) )
    sub_B578("work_completed", 8958);
  off_72D18();
  sub_156B8(a2);
}
