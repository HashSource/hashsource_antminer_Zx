_DWORD *__fastcall sub_1D52C(pthread_rwlock_t *a1, int a2)
{
  pthread_rwlock_t *v2; // r5
  int lock; // r2
  _DWORD *v6; // r4
  int v7; // r0

  v2 = a1 + 10;
  if ( pthread_rwlock_rdlock(a1 + 10) )
    sub_B5E4("clone_queued_work_byid", 8911);
  lock = a1[11].__lock;
  if ( lock )
  {
    v7 = *(_DWORD *)(lock + 1840);
    if ( a2 == *(_DWORD *)(lock + 1828) )
    {
      v7 = a1[11].__lock;
LABEL_12:
      v6 = sub_1A598(v7, 0);
    }
    else
    {
      while ( v7 )
      {
        if ( a2 == *(_DWORD *)(v7 + 1828) )
          goto LABEL_12;
        v7 = *(_DWORD *)(v7 + 1840);
      }
      v6 = 0;
    }
  }
  else
  {
    v6 = 0;
  }
  if ( pthread_rwlock_unlock(v2) )
    sub_B578("clone_queued_work_byid", 8915);
  off_72D18();
  return v6;
}
