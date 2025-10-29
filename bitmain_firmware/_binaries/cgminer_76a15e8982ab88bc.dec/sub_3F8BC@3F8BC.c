void __noreturn sub_3F8BC()
{
  int v0; // r5
  int i; // r4
  char v3[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    strcpy(v3, "pic_heart_beat_func_new");
    sub_385C8(5, v3, 0);
  }
  while ( 1 )
  {
    v0 = 631471;
    sleep(0xAu);
    for ( i = 0; i != 4; ++i )
    {
      if ( *(unsigned __int8 *)++v0 )
      {
        if ( byte_7398B )
        {
          pthread_mutex_lock(&stru_75F10);
          dword_75EDC = i;
          sub_3F64C();
          sub_2A884();
          pthread_mutex_unlock(&stru_75F10);
        }
      }
    }
  }
}
