int __fastcall sub_3220C(pthread_mutex_t *a1, const char *a2, int a3)
{
  if ( pthread_mutex_unlock(a1) )
    sub_B84C(a2, a3);
  return off_75ED8();
}
