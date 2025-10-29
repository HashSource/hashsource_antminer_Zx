int __fastcall sub_1AA90(int a1)
{
  int v2; // r4

  if ( pthread_rwlock_rdlock(&rwlock) )
    sub_B5E4("get_thread", 614);
  v2 = *(_DWORD *)(dword_78408 + 4 * a1);
  if ( pthread_rwlock_unlock(&rwlock) )
    sub_B578("get_thread", 616);
  off_72D18();
  return v2;
}
