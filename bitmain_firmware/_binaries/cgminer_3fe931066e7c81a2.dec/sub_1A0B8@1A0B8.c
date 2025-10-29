void __fastcall sub_1A0B8(pthread_rwlock_t *a1, void **a2)
{
  pthread_rwlock_t *v2; // r5

  v2 = a1 + 10;
  if ( pthread_rwlock_wrlock(a1 + 10) )
    sub_B480("work_completed", 8969);
  sub_16B40((int)a1, a2);
  if ( pthread_rwlock_unlock(v2) )
    sub_B630("work_completed", 8971);
  off_75ED8();
  sub_15780(a2);
}
