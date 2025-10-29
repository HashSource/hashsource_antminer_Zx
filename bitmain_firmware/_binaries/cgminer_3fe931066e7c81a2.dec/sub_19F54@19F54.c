int __fastcall sub_19F54(pthread_rwlock_t *a1, int a2)
{
  pthread_rwlock_t *v2; // r4

  v2 = a1 + 10;
  if ( pthread_rwlock_wrlock(a1 + 10) )
    sub_B480("add_queued", 8825);
  sub_16624((int)a1, a2);
  if ( pthread_rwlock_unlock(v2) )
    sub_B630("add_queued", 8827);
  return off_75ED8();
}
