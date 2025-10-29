// Alternative name is '_mutex_init.constprop.65'
void __fastcall mutex_init_0(pthread_mutex_t *lock, pthread_mutex_t *file, const char *func, const int line)
{
  const char *v6; // r2
  int v7; // r3

  if ( pthread_mutex_init(lock, 0) )
    mutex_init(file, func, v6, v7);
}
