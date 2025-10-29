void sub_44978()
{
  int v0; // r4
  char *v1; // r5
  int v2; // r11
  int v3; // r12
  char s[4088]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    strcpy(s, "check_chain");
    sub_38730(5, s, 0);
  }
  v0 = 0;
  byte_9D6CB = 0;
  v1 = (char *)&unk_9D4B4;
  v2 = *(_DWORD *)(dword_78E10[0] + 8);
  do
  {
    if ( ((v2 >> v0) & 1) != 0 )
    {
      v3 = (unsigned __int8)byte_7AD48;
      v1[8] = 1;
      ++byte_9D6CB;
      if ( v3 || byte_78E08 || dword_766C4 > 4 )
      {
        snprintf(s, 0x1000u, "Chain %d existed!", v0);
        sub_38730(5, s, 0);
      }
    }
    else
    {
      v1[8] = 0;
    }
    ++v0;
    ++v1;
  }
  while ( v0 != 4 );
}
