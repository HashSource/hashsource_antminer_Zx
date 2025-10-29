int __fastcall sub_1A1D0(pthread_rwlock_t *a1, int a2)
{
  pthread_rwlock_t *v2; // r4

  v2 = a1 + 10;
  if ( pthread_rwlock_wrlock(a1 + 10) )
    sub_B3C8("add_queued", 8812);
  sub_1655C((int)a1, a2);
  if ( pthread_rwlock_unlock(v2) )
    sub_B578("add_queued", 8814);
  return off_72D18();
}
