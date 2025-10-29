void __fastcall init_vol_table(unsigned __int16 vol)
{
  pthread_mutex_t *v1; // r3

  v1 = (pthread_mutex_t *)isl_vol;
  do
  {
    LOWORD(v1->__data.__lock) = vol;
    v1 = (pthread_mutex_t *)((char *)v1 + 6);
    *((_WORD *)&v1[-1].__align + 10) = vol;
    *((_WORD *)&v1[-1].__align + 11) = vol;
  }
  while ( v1 != &iic_mutex );
}
