int sub_1FAC4()
{
  int v0; // r4

  if ( pthread_mutex_lock(&stru_78838) )
    sub_B35C("cp_prio", 7036);
  if ( pthread_rwlock_rdlock(&stru_78850) )
    sub_B5E4("cp_prio", 7036);
  if ( pthread_mutex_unlock(&stru_78838) )
    sub_B50C("cp_prio", 7036);
  v0 = *(_DWORD *)(dword_73E9C + 4);
  if ( pthread_rwlock_unlock(&stru_78850) )
    sub_B578("cp_prio", 7038);
  off_72D18();
  return v0;
}
