int __fastcall sub_1B83C(int a1)
{
  int v2; // r4

  if ( pthread_rwlock_rdlock(&stru_7B700) )
    sub_B69C("get_devices", 632);
  v2 = *(_DWORD *)(dword_7B628 + 4 * a1);
  if ( pthread_rwlock_unlock(&stru_7B700) )
    sub_B630("get_devices", 634);
  off_75ED8();
  return v2;
}
