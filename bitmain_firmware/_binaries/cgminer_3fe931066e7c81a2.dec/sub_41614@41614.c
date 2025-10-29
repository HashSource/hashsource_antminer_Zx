void sub_41614()
{
  int v0; // r5
  int i; // r4
  int v2; // t1
  char v3[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    strcpy(v3, "every_chain_enable_PIC16F1704_dc_dc_new");
    sub_38730(5, v3, 0);
  }
  v0 = 644283;
  for ( i = 0; i != 4; ++i )
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      pthread_mutex_lock(&stru_790D0);
      dword_7909C = i;
      sub_3FA7C();
      sub_2A92C();
      pthread_mutex_unlock(&stru_790D0);
    }
  }
}
