int __fastcall sub_18C2C(int a1, _BYTE *a2)
{
  pthread_mutex_t *v2; // r5
  pthread_mutex_t *v4; // r0
  int v5; // r5

  v2 = (pthread_mutex_t *)(a1 + 220);
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 220)) )
    sub_B414("pool_tclear", 784);
  v4 = v2;
  v5 = (unsigned __int8)*a2;
  *a2 = 0;
  if ( pthread_mutex_unlock(v4) )
    sub_B5C4("pool_tclear", 787);
  off_75ED8();
  return v5;
}
