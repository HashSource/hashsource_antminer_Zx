int __fastcall sub_25E5C(int a1, int a2)
{
  int result; // r0
  _DWORD *v5; // r0
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  sub_1A730(a1, a2);
  if ( sub_29F54((unsigned int *)(a2 + 192), (unsigned int *)(a2 + 160)) )
  {
    v5 = sub_1A44C(a2, 0);
    sub_256A4((int)v5);
    return 1;
  }
  else if ( byte_78E09 )
  {
    if ( byte_7AD48 || (result = (unsigned __int8)byte_78E08, byte_78E08) || dword_766C4 > 6 )
    {
      snprintf(
        s,
        0x1000u,
        "%s %s %d: Share above target",
        "submit_tested_work",
        *(const char **)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 4) + 8),
        *(_DWORD *)(*(_DWORD *)(a1 + 36) + 8));
      sub_38730(7, s, 0);
      return 0;
    }
  }
  else
  {
    return 0;
  }
  return result;
}
