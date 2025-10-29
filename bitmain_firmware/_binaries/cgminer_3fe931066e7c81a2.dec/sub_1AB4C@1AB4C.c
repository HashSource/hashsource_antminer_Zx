_DWORD *__fastcall sub_1AB4C(pthread_rwlock_t *a1, void *a2, size_t a3, const void *a4, int a5, size_t a6)
{
  pthread_rwlock_t *v6; // r4
  int v11; // r0
  _DWORD *v12; // r5

  v6 = a1 + 10;
  if ( pthread_rwlock_rdlock(a1 + 10) )
    sub_B69C("clone_queued_work_bymidstate", 8880);
  v11 = sub_16A80(a1[11].__lock, a2, a3, a4, a5, a6);
  v12 = (_DWORD *)v11;
  if ( v11 )
    v12 = sub_1A44C(v11, 0);
  if ( pthread_rwlock_unlock(v6) )
    sub_B630("clone_queued_work_bymidstate", 8884);
  off_75ED8();
  return v12;
}
