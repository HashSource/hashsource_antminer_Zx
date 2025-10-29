_DWORD *__fastcall sub_1AC00(pthread_rwlock_t *a1, int a2)
{
  pthread_rwlock_t *v2; // r5
  int lock; // r2
  _DWORD *v6; // r4
  int v7; // r0

  v2 = a1 + 10;
  if ( pthread_rwlock_rdlock(a1 + 10) )
    sub_B69C("clone_queued_work_byid", 8924);
  lock = a1[11].__lock;
  if ( lock )
  {
    v7 = *(_DWORD *)(lock + 1840);
    if ( a2 == *(_DWORD *)(lock + 1828) )
    {
      v7 = a1[11].__lock;
LABEL_12:
      v6 = sub_1A44C(v7, 0);
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
    sub_B630("clone_queued_work_byid", 8928);
  off_75ED8();
  return v6;
}
