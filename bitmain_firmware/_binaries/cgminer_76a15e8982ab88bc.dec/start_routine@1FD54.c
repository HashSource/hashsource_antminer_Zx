void *__fastcall start_routine(_DWORD *a1)
{
  _BOOL4 v2; // r5
  int v3; // r5
  pthread_t v5; // r0
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( !*((_BYTE *)a1 + 139) )
  {
    v5 = pthread_self();
    pthread_detach(v5);
  }
  while ( !sub_18610(a1, 0) )
  {
    sub_1F95C((int)a1);
    sleep(5u);
  }
  sub_1859C((int)a1, (_BYTE *)a1 + 130);
  sub_18200((int)a1, (_BYTE *)a1 + 129);
  if ( pthread_mutex_lock(&stru_78838) )
    sub_B35C("test_pool_thread", 9995);
  if ( pthread_rwlock_wrlock(&stru_78850) )
    sub_B3C8("test_pool_thread", 9995);
  if ( byte_74148 )
  {
    v2 = 0;
  }
  else
  {
    v3 = *a1;
    dword_73E9C = (int)a1;
    byte_74148 = 1;
    v2 = v3 != 0;
  }
  if ( pthread_rwlock_unlock(&stru_78850) )
    sub_B578("test_pool_thread", 10003);
  if ( pthread_mutex_unlock(&stru_78838) )
    sub_B50C("test_pool_thread", 10003);
  off_72D18();
  if ( v2 && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(s, 0x1000u, "Switching to pool %d %s - first alive pool", *a1, (const char *)a1[49]);
    sub_385C8(7, s, 0);
  }
  sub_1FB7C(a1);
  sub_1A600(0);
  *((_BYTE *)a1 + 316) = 0;
  return 0;
}
