int sub_3E348()
{
  int v0; // r4
  int v1; // r5
  int v2; // t1
  int result; // r0

  v0 = 0;
  v1 = 631471;
  do
  {
    v2 = *(unsigned __int8 *)++v1;
    if ( v2 == 1 )
    {
      pthread_mutex_lock(&stru_75F10);
      dword_75EDC = v0;
      sub_3E264(v0);
      result = pthread_mutex_unlock(&stru_75F10);
    }
    ++v0;
  }
  while ( v0 != 4 );
  return result;
}
