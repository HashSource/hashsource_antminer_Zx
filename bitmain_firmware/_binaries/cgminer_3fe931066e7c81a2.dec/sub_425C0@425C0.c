int __fastcall sub_425C0(unsigned int a1)
{
  int v2; // r5
  int i; // r4
  int v4; // t1
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "%s %u", "set freq:", a1);
    sub_38730(5, s, 0);
  }
  v2 = 644283;
  for ( i = 0; i != 4; ++i )
  {
    v4 = *(unsigned __int8 *)++v2;
    if ( v4 == 1 )
    {
      pthread_mutex_lock(&stru_790D0);
      dword_7909C = i;
      sub_419C8(a1);
      sub_2A92C();
      pthread_mutex_unlock(&stru_790D0);
    }
  }
  return sub_2A92C();
}
