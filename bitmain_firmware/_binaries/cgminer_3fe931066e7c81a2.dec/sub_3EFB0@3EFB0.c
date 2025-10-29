int sub_3EFB0()
{
  int v0; // r4
  int v1; // r5
  int v2; // t1
  int result; // r0

  v0 = 0;
  v1 = 644283;
  do
  {
    v2 = *(unsigned __int8 *)++v1;
    if ( v2 == 1 )
    {
      pthread_mutex_lock(&stru_790D0);
      dword_7909C = v0;
      sub_3EEC8(v0);
      sub_2A92C();
      result = pthread_mutex_unlock(&stru_790D0);
    }
    ++v0;
  }
  while ( v0 != 4 );
  return result;
}
