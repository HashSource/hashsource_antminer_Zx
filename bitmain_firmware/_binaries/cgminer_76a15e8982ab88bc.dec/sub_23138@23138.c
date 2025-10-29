void *__fastcall sub_23138(void *a1)
{
  int v1; // r4
  pthread_t v2; // r0
  int v3; // r6
  int v4; // r4
  int v5; // r3
  pthread_rwlock_t *v6; // r5

  v1 = sub_1D9A0();
  v2 = pthread_self();
  pthread_detach(v2);
  sub_1859C(v1, (_BYTE *)(v1 + 130));
  sub_22ED0();
  if ( pthread_rwlock_rdlock(&rwlock) )
    sub_B5E4("restart_thread", 5270);
  v3 = dword_78994;
  if ( pthread_rwlock_unlock(&rwlock) )
    sub_B578("restart_thread", 5272);
  off_72D18();
  if ( v3 > 0 )
  {
    v4 = 0;
    do
    {
      while ( 1 )
      {
        v5 = *(_DWORD *)(dword_78408 + 4 * v4++);
        v6 = *(pthread_rwlock_t **)(v5 + 36);
        if ( v6 )
        {
          if ( !v6[1].__lock )
            break;
        }
        if ( v4 == v3 )
          goto LABEL_9;
      }
      *(_BYTE *)(v5 + 62) = 1;
      sub_1A95C(v6);
      (*(void (__fastcall **)(pthread_rwlock_t *))(v6->__nr_readers + 76))(v6);
    }
    while ( v4 != v3 );
  }
LABEL_9:
  if ( pthread_mutex_lock(&stru_78454) )
    sub_B35C("restart_thread", 5284);
  pthread_cond_broadcast(&cond);
  if ( pthread_mutex_unlock(&stru_78454) )
    sub_B50C("restart_thread", 5286);
  off_72D18();
  return 0;
}
