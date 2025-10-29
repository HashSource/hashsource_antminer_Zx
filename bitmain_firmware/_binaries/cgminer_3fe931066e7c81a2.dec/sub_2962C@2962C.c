int __fastcall sub_2962C(int a1, char a2)
{
  pthread_mutex_t *v2; // r5

  v2 = (pthread_mutex_t *)(a1 + 12);
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 12)) )
    sub_B708("tq_freezethaw", 1236);
  *(_BYTE *)(a1 + 8) = a2;
  pthread_cond_signal((pthread_cond_t *)(a1 + 40));
  sub_29388(v2, "tq_freezethaw", 1239);
  return off_75ED8();
}
