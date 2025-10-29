int sub_1FB7C()
{
  int v0; // r4

  if ( pthread_mutex_lock(&stru_7BA10) )
    sub_B414("cp_prio", 7036);
  if ( pthread_rwlock_rdlock(&stru_7BA28) )
    sub_B69C("cp_prio", 7036);
  if ( pthread_mutex_unlock(&stru_7BA10) )
    sub_B5C4("cp_prio", 7036);
  v0 = *(_DWORD *)(dword_7705C + 4);
  if ( pthread_rwlock_unlock(&stru_7BA28) )
    sub_B630("cp_prio", 7038);
  off_75ED8();
  return v0;
}
