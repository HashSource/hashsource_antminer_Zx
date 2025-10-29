unsigned int __fastcall sub_3C5E8(int a1, _BYTE *a2, unsigned int a3)
{
  pthread_mutex_t *v6; // r5
  unsigned int v7; // r0
  unsigned int v8; // r4

  v6 = (pthread_mutex_t *)((char *)&unk_78FAC + 24 * a1);
  pthread_mutex_lock(v6);
  v7 = sub_3BB78(a1);
  if ( v7 >= a3 )
  {
    v8 = sub_3BD44(a1, a2, a3);
  }
  else if ( v7 )
  {
    v8 = sub_3BD44(a1, a2, v7);
  }
  else
  {
    v8 = 0;
  }
  pthread_mutex_unlock(v6);
  return v8;
}
