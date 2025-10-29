int sub_188A8()
{
  int v0; // r5
  int v1; // r3

  if ( pthread_mutex_lock((pthread_mutex_t *)dword_7704C) )
    sub_B414("total_staged", 2907);
  if ( dword_77050 )
    v1 = *(_DWORD *)(dword_77050 + 1832);
  else
    v0 = 0;
  if ( dword_77050 )
    v0 = *(_DWORD *)(v1 + 12);
  if ( pthread_mutex_unlock((pthread_mutex_t *)dword_7704C) )
    sub_B5C4("total_staged", 2909);
  off_75ED8();
  return v0;
}
