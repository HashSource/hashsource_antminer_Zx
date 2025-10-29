int __fastcall sub_3E6E0(int result, unsigned __int8 *a2, int a3)
{
  int v3; // r6
  int v4; // r8
  int i; // r4
  int v8; // t1
  int v9; // r5
  char v10; // r0
  char s[4100]; // [sp+18h] [bp-1004h] BYREF

  v3 = 644283;
  v4 = result;
  for ( i = 0; i != 4; ++i )
  {
    v8 = *(unsigned __int8 *)++v3;
    if ( v8 == 1 )
    {
      v9 = 0;
      pthread_mutex_lock(&stru_790D0);
      dword_7909C = i;
      do
      {
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
        {
          snprintf(
            s,
            0x1000u,
            "chain%d asic%d, set data slave:%02x addr:%02x %02x %02x, len=%d\n",
            i,
            v9,
            (unsigned __int8)byte_76B48[v9],
            v4,
            *a2,
            a2[1],
            a3);
          sub_38730(5, s, 0);
        }
        v10 = *((_BYTE *)&unk_76AC8 + v9++ + 128);
        sub_3C7E0(v10, v4, (int)a2, a3);
        sub_2A92C();
      }
      while ( v9 != 3 );
      result = pthread_mutex_unlock(&stru_790D0);
    }
  }
  return result;
}
