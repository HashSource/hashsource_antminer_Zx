void __noreturn sub_40034()
{
  int v0; // r5
  int i; // r4
  char v3[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    strcpy(v3, "pic_heart_beat_func_new");
    sub_38730(5, v3, 0);
  }
  while ( 1 )
  {
    v0 = 644283;
    sleep(0xAu);
    for ( i = 0; i != 4; ++i )
    {
      if ( *(unsigned __int8 *)++v0 )
      {
        if ( byte_76B4B )
        {
          pthread_mutex_lock(&stru_790D0);
          dword_7909C = i;
          sub_3FDC4();
          sub_2A92C();
          pthread_mutex_unlock(&stru_790D0);
        }
      }
    }
  }
}
