int sub_1DA58()
{
  int v0; // r4

  if ( pthread_mutex_lock(&stru_7BA10) )
    sub_B414("current_pool", 796);
  if ( pthread_rwlock_rdlock(&stru_7BA28) )
    sub_B69C("current_pool", 796);
  if ( pthread_mutex_unlock(&stru_7BA10) )
    sub_B5C4("current_pool", 796);
  v0 = dword_7705C;
  if ( pthread_rwlock_unlock(&stru_7BA28) )
    sub_B630("current_pool", 798);
  off_75ED8();
  return v0;
}
