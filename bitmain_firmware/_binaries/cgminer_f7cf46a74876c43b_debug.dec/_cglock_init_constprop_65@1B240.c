// Alternative name is '_cglock_init.constprop.64'
int __fastcall cglock_init_constprop_65(int a1, pthread_mutex_t *a2, const char *a3)
{
  const char *v6; // r2
  int v7; // r3
  int result; // r0
  const char *v9; // r2
  int v10; // r3

  if ( pthread_mutex_init((pthread_mutex_t *)a1, 0) )
    mutex_init(a2, a3, v6, v7);
  result = pthread_rwlock_init((pthread_rwlock_t *)(a1 + 24), 0);
  if ( result )
    rwlock_init((pthread_rwlock_t *)a2, a3, v9, v10);
  return result;
}
