int sub_41308()
{
  int v0; // r5
  int i; // r4
  int v2; // t1
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v0 = 644283;
  for ( i = 0; i != 4; ++i )
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
      {
        snprintf(s, 0x1000u, "chain%d %s", i, "every_chain_reset_PIC16F1704_pic_new");
        sub_38730(5, s, 0);
      }
      pthread_mutex_lock(&stru_790D0);
      dword_7909C = i;
      sub_3DF78();
      sub_2A92C();
      pthread_mutex_unlock(&stru_790D0);
    }
  }
  return sub_2A92C();
}
