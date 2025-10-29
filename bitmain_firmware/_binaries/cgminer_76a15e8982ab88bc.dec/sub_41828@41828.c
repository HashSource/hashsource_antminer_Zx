int __fastcall sub_41828(unsigned int a1)
{
  int v2; // r5
  int i; // r4
  int v4; // t1
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%s %u", "set freq:", a1);
    sub_385C8(5, s, 0);
  }
  v2 = 631471;
  for ( i = 0; i != 4; ++i )
  {
    v4 = *(unsigned __int8 *)++v2;
    if ( v4 == 1 )
    {
      pthread_mutex_lock(&stru_75F10);
      dword_75EDC = i;
      sub_41158(a1);
      sub_2A884();
      pthread_mutex_unlock(&stru_75F10);
    }
  }
  return sub_2A884();
}
