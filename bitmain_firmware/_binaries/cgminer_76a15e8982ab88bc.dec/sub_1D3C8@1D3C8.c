int __fastcall sub_1D3C8(pthread_rwlock_t *a1, int a2)
{
  pthread_rwlock_t *v2; // r6
  int lock; // r3
  int v6; // r4

  v2 = a1 + 10;
  if ( pthread_rwlock_rdlock(a1 + 10) )
    sub_B5E4("find_queued_work_byid", 8900);
  lock = a1[11].__lock;
  if ( lock && (v6 = *(_DWORD *)(lock + 1840), a2 != *(_DWORD *)(lock + 1828)) )
  {
    while ( v6 && a2 != *(_DWORD *)(v6 + 1828) )
      v6 = *(_DWORD *)(v6 + 1840);
  }
  else
  {
    v6 = lock;
  }
  if ( pthread_rwlock_unlock(v2) )
    sub_B578("find_queued_work_byid", 8902);
  off_72D18();
  return v6;
}
