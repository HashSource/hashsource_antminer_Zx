int __fastcall sub_246B8(pthread_rwlock_t *a1)
{
  pthread_rwlock_t *v1; // r4
  int v3; // r5

  v1 = a1 + 10;
  if ( pthread_rwlock_wrlock(a1 + 10) )
    sub_B3C8("get_queued", 8803);
  v3 = sub_24660((int)a1);
  if ( pthread_rwlock_unlock(v1) )
    sub_B578("get_queued", 8805);
  off_72D18();
  return v3;
}
