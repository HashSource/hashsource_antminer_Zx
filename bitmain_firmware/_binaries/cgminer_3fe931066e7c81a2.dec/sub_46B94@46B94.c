int __fastcall sub_46B94(unsigned __int8 *a1)
{
  int v2; // r6
  int v3; // r7
  int i; // r4
  int v5; // t1

  v2 = 644283;
  v3 = 1;
  for ( i = 0; i != 4; ++i )
  {
    v5 = *(unsigned __int8 *)++v2;
    if ( v5 == 1 )
    {
      pthread_mutex_lock(&stru_790D0);
      dword_7909C = i;
      v3 = sub_41E7C(a1, 0, 9);
      sub_2A92C();
      pthread_mutex_unlock(&stru_790D0);
    }
    a1 += 9;
  }
  return v3;
}
