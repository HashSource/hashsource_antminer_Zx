int __fastcall sub_F720(int a1, int a2)
{
  _DWORD *v2; // r3
  int result; // r0
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v2 = *(_DWORD **)(a1 + 36);
  if ( v2[59] == a2 )
  {
    result = (unsigned __int8)byte_75C49;
    if ( byte_75C49 )
    {
      if ( byte_77B70 || (result = (unsigned __int8)byte_75C48, byte_75C48) || dword_73504 > 6 )
      {
        snprintf(s, 0x1000u, "%s %d duplicate share detected as HW error", *(const char **)(v2[1] + 8), v2[2]);
        sub_385C8(7, s, 0);
        return 0;
      }
    }
  }
  else
  {
    v2[59] = a2;
    return 1;
  }
  return result;
}
