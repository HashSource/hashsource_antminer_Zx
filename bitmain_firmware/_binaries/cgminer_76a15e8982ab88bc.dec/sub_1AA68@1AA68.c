int __fastcall sub_1AA68(pthread_rwlock_t *a1, const char *a2, int a3)
{
  int result; // r0

  result = pthread_rwlock_rdlock(a1);
  if ( result )
    sub_B5E4(a2, a3);
  return result;
}
