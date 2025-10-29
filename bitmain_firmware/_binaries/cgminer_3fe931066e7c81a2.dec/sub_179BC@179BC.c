int __fastcall sub_179BC(pthread_rwlock_t *a1, const char *a2, int a3)
{
  int result; // r0

  result = pthread_rwlock_init(a1, 0);
  if ( result )
    sub_B558(a2, a3);
  return result;
}
