int __fastcall sub_1B124(int a1)
{
  int v2; // r4

  if ( pthread_rwlock_rdlock(&rwlock) )
    sub_B69C("get_thread", 614);
  v2 = *(_DWORD *)(dword_7B5E0 + 4 * a1);
  if ( pthread_rwlock_unlock(&rwlock) )
    sub_B630("get_thread", 616);
  off_75ED8();
  return v2;
}
