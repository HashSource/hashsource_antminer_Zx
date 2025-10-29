int sub_1A1E8()
{
  int v0; // r4

  if ( pthread_mutex_lock(&stru_7BA10) )
    sub_B414("total_work_inc", 2273);
  if ( pthread_rwlock_wrlock(&stru_7BA28) )
    sub_B480("total_work_inc", 2273);
  v0 = dword_770A8++;
  if ( pthread_rwlock_unlock(&stru_7BA28) )
    sub_B630("total_work_inc", 2275);
  if ( pthread_mutex_unlock(&stru_7BA10) )
    sub_B5C4("total_work_inc", 2275);
  off_75ED8();
  return v0;
}
