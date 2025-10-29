int sub_1A334()
{
  int v0; // r4

  if ( pthread_mutex_lock(&stru_78838) )
    sub_B35C("total_work_inc", 2273);
  if ( pthread_rwlock_wrlock(&stru_78850) )
    sub_B3C8("total_work_inc", 2273);
  v0 = dword_73E98++;
  if ( pthread_rwlock_unlock(&stru_78850) )
    sub_B578("total_work_inc", 2275);
  if ( pthread_mutex_unlock(&stru_78838) )
    sub_B50C("total_work_inc", 2275);
  off_72D18();
  return v0;
}
