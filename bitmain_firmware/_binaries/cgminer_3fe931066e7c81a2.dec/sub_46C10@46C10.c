int sub_46C10()
{
  int v0; // r5
  int v1; // r4
  int v2; // r6
  int v3; // t1
  _DWORD v5[9]; // [sp+4h] [bp-28h] BYREF

  v0 = 644283;
  v1 = 0;
  v2 = 1;
  memset(v5, 0, sizeof(v5));
  do
  {
    v3 = *(unsigned __int8 *)++v0;
    if ( v3 == 1 )
    {
      pthread_mutex_lock(&stru_790D0);
      dword_7909C = v1;
      v2 = sub_41E7C((unsigned __int8 *)v5 + 9 * v1, 0, 9);
      sub_2A92C();
      pthread_mutex_unlock(&stru_790D0);
    }
    ++v1;
  }
  while ( v1 != 4 );
  return v2;
}
