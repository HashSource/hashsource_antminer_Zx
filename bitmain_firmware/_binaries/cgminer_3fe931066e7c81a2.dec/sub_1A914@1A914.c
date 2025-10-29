int __fastcall sub_1A914(int a1, int a2, int a3, _DWORD *a4)
{
  bool v4; // zf
  _DWORD *v5; // r5
  int result; // r0
  char v9[4100]; // [sp+0h] [bp-1004h] BYREF

  v5 = a4;
  v4 = a4 == 0;
  if ( a4 )
    a4 = 0;
  if ( !v4 )
    *v5 = a4;
  if ( sub_1654C(a2, a3) )
  {
    sub_1A730(a1, a2);
    if ( sub_29F54((unsigned int *)(a2 + 192), (unsigned int *)(a2 + 160)) )
    {
      return 1;
    }
    else
    {
      if ( v5 )
        *v5 = 1;
      result = (unsigned __int8)byte_78E09;
      if ( byte_78E09 )
      {
        if ( byte_7AD48 || (result = (unsigned __int8)byte_78E08, byte_78E08) || dword_766C4 > 6 )
        {
          strcpy(v9, "Share above target");
          sub_38730(7, v9, 0);
          return 0;
        }
      }
    }
  }
  else
  {
    sub_189A4(a1);
    return 0;
  }
  return result;
}
