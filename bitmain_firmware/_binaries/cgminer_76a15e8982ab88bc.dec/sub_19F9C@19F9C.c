int __fastcall sub_19F9C(int a1, int a2, int a3, _DWORD *a4)
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
  if ( sub_16484(a2, a3) )
  {
    sub_19DB8(a1, a2);
    if ( sub_29EAC((unsigned int *)(a2 + 192), (unsigned int *)(a2 + 160)) )
    {
      return 1;
    }
    else
    {
      if ( v5 )
        *v5 = 1;
      result = (unsigned __int8)byte_75C49;
      if ( byte_75C49 )
      {
        if ( byte_77B70 || (result = (unsigned __int8)byte_75C48, byte_75C48) || dword_73504 > 6 )
        {
          strcpy(v9, "Share above target");
          sub_385C8(7, v9, 0);
          return 0;
        }
      }
    }
  }
  else
  {
    sub_19498(a1);
    return 0;
  }
  return result;
}
