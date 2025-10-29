int sub_191B0()
{
  int v0; // r5
  int v1; // r3

  if ( pthread_mutex_lock((pthread_mutex_t *)dword_73E6C) )
    sub_B35C("total_staged", 2907);
  if ( dword_73E74 )
    v1 = *(_DWORD *)(dword_73E74 + 1832);
  else
    v0 = 0;
  if ( dword_73E74 )
    v0 = *(_DWORD *)(v1 + 12);
  if ( pthread_mutex_unlock((pthread_mutex_t *)dword_73E6C) )
    sub_B50C("total_staged", 2909);
  off_72D18();
  return v0;
}
