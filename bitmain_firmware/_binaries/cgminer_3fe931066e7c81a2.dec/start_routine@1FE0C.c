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
  while ( !sub_18CA0(a1, 0) )
  {
    sub_1FA14((int)a1);
    sleep(5u);
  }
  sub_18834((int)a1, (_BYTE *)a1 + 130);
  sub_18C2C((int)a1, (_BYTE *)a1 + 129);
  if ( pthread_mutex_lock(&stru_7BA10) )
    sub_B414("test_pool_thread", 10008);
  if ( pthread_rwlock_wrlock(&stru_7BA28) )
    sub_B480("test_pool_thread", 10008);
  if ( byte_7730C )
  {
    v2 = 0;
  }
  else
  {
    v3 = *a1;
    dword_7705C = (int)a1;
    byte_7730C = 1;
    v2 = v3 != 0;
  }
  if ( pthread_rwlock_unlock(&stru_7BA28) )
    sub_B630("test_pool_thread", 10016);
  if ( pthread_mutex_unlock(&stru_7BA10) )
    sub_B5C4("test_pool_thread", 10016);
  off_75ED8();
  if ( v2 && byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "Switching to pool %d %s - first alive pool", *a1, (const char *)a1[49]);
    sub_38730(7, s, 0);
  }
  sub_1FC34(a1);
  sub_19BF8(0);
  *((_BYTE *)a1 + 316) = 0;
  return 0;
}
