int sub_40B80()
{
  int v0; // r5
  int i; // r4
  int v2; // t1
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v0 = 631471;
  for ( i = 0; i != 4; ++i )
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
      {
        snprintf(s, 0x1000u, "chain%d %s", i, "every_chain_jump_from_loader_to_app_PIC16F1704_new");
        sub_385C8(5, s, 0);
      }
      pthread_mutex_lock(&stru_75F10);
      dword_75EDC = i;
      sub_3DA90();
      sub_2A884();
      pthread_mutex_unlock(&stru_75F10);
    }
  }
  return sub_2A884();
}
