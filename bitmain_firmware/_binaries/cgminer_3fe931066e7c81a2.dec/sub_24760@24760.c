int __fastcall sub_24760(pthread_rwlock_t *a1)
{
  pthread_rwlock_t *v1; // r4
  int v3; // r5

  v1 = a1 + 10;
  if ( pthread_rwlock_wrlock(a1 + 10) )
    sub_B480("get_queued", 8816);
  v3 = sub_24708((int)a1);
  if ( pthread_rwlock_unlock(v1) )
    sub_B630("get_queued", 8818);
  off_75ED8();
  return v3;
}
