void *__fastcall sub_231F0(void *a1)
{
  int v1; // r4
  pthread_t v2; // r0
  int v3; // r6
  int v4; // r4
  int v5; // r3
  pthread_rwlock_t *v6; // r5

  v1 = sub_1DA58();
  v2 = pthread_self();
  pthread_detach(v2);
  sub_18834(v1, (_BYTE *)(v1 + 130));
  sub_22F88();
  if ( pthread_rwlock_rdlock(&rwlock) )
    sub_B69C("restart_thread", 5270);
  v3 = dword_7BB6C;
  if ( pthread_rwlock_unlock(&rwlock) )
    sub_B630("restart_thread", 5272);
  off_75ED8();
  if ( v3 > 0 )
  {
    v4 = 0;
    do
    {
      while ( 1 )
      {
        v5 = *(_DWORD *)(dword_7B5E0 + 4 * v4++);
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
      sub_1AA18(v6);
      (*(void (__fastcall **)(pthread_rwlock_t *))(v6->__nr_readers + 76))(v6);
    }
    while ( v4 != v3 );
  }
LABEL_9:
  if ( pthread_mutex_lock(&stru_7B62C) )
    sub_B414("restart_thread", 5284);
  pthread_cond_broadcast(&cond);
  if ( pthread_mutex_unlock(&stru_7B62C) )
    sub_B5C4("restart_thread", 5286);
  off_75ED8();
  return 0;
}
