// Alternative name is '_rwlock_init.constprop.67'
void __fastcall rwlock_init_0(pthread_rwlock_t *lock, pthread_rwlock_t *file, const char *func, const int line)
{
  const char *v6; // r2
  int v7; // r3

  if ( pthread_rwlock_init(lock, 0) )
    rwlock_init(file, func, v6, v7);
}
