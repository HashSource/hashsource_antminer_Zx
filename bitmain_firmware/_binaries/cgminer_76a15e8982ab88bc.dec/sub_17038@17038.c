int __fastcall sub_17038(int a1, char *a2)
{
  char *v3; // r5
  int result; // r0
  char *v5; // r0
  char *v6; // r6
  char v7[4096]; // [sp+0h] [bp-1000h] BYREF

  v3 = sub_2AC38(a2, a1);
  result = sub_154B4(a1, v3);
  if ( !result )
  {
    sub_5858C((int)v3, (_DWORD *)(a1 + 196));
    result = strncmp(v3, "http://", 7u);
    if ( result )
    {
      result = strncmp(v3, "https://", 8u);
      if ( result )
      {
        v5 = (char *)malloc(0x100u);
        v6 = v5;
        if ( !v5 )
        {
          strcpy(v7, "Failed to malloc httpinput");
          sub_385C8(3, v7, 1);
          sub_16BE0(1);
        }
        strcpy(v5, "stratum+tcp://");
        strncat(v5, v3, 0xF2u);
        return sub_154B4(a1, v6);
      }
    }
  }
  return result;
}
