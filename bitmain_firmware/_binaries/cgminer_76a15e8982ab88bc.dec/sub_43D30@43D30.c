void sub_43D30()
{
  int v0; // r4
  char *v1; // r5
  int v2; // r11
  int v3; // r12
  char s[4088]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    strcpy(s, "check_chain");
    sub_385C8(5, s, 0);
  }
  v0 = 0;
  byte_9A49F = 0;
  v1 = (char *)&unk_9A2A8;
  v2 = *(_DWORD *)(dword_75C50[0] + 8);
  do
  {
    if ( ((v2 >> v0) & 1) != 0 )
    {
      v3 = (unsigned __int8)byte_77B70;
      v1[8] = 1;
      ++byte_9A49F;
      if ( v3 || byte_75C48 || dword_73504 > 4 )
      {
        snprintf(s, 0x1000u, "Chain %d existed!", v0);
        sub_385C8(5, s, 0);
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
