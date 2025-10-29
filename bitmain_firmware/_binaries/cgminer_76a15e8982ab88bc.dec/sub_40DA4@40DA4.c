void sub_40DA4()
{
  int v0; // r5
  int i; // r4
  int v2; // t1
  char v3[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    strcpy(v3, "every_chain_enable_PIC16F1704_dc_dc_new");
    sub_385C8(5, v3, 0);
  }
  v0 = 631471;
  for ( i = 0; i != 4; ++i )
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      pthread_mutex_lock(&stru_75F10);
      dword_75EDC = i;
      sub_3F304();
      sub_2A884();
      pthread_mutex_unlock(&stru_75F10);
    }
  }
}
