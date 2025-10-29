int sub_1D9A0()
{
  int v0; // r4

  if ( pthread_mutex_lock(&stru_78838) )
    sub_B35C("current_pool", 796);
  if ( pthread_rwlock_rdlock(&stru_78850) )
    sub_B5E4("current_pool", 796);
  if ( pthread_mutex_unlock(&stru_78838) )
    sub_B50C("current_pool", 796);
  v0 = dword_73E9C;
  if ( pthread_rwlock_unlock(&stru_78850) )
    sub_B578("current_pool", 798);
  off_72D18();
  return v0;
}
