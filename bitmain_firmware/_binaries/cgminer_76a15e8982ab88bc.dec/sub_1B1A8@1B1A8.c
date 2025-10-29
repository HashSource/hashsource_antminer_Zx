int __fastcall sub_1B1A8(int a1)
{
  int v2; // r4

  if ( pthread_rwlock_rdlock(&stru_78528) )
    sub_B5E4("get_devices", 632);
  v2 = *(_DWORD *)(dword_78450 + 4 * a1);
  if ( pthread_rwlock_unlock(&stru_78528) )
    sub_B578("get_devices", 634);
  off_72D18();
  return v2;
}
