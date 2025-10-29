int __fastcall sub_19B04(pthread_rwlock_t *a1, const char *a2, int a3)
{
  if ( pthread_rwlock_unlock(a1) )
    sub_B578(a2, a3);
  return off_72D18();
}
