int __fastcall sub_25DB4(int a1, int a2)
{
  int result; // r0
  _DWORD *v5; // r0
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  sub_19DB8(a1, a2);
  if ( sub_29EAC((unsigned int *)(a2 + 192), (unsigned int *)(a2 + 160)) )
  {
    v5 = sub_1A598(a2, 0);
    sub_255FC((int)v5);
    return 1;
  }
  else if ( byte_75C49 )
  {
    if ( byte_77B70 || (result = (unsigned __int8)byte_75C48, byte_75C48) || dword_73504 > 6 )
    {
      snprintf(
        s,
        0x1000u,
        "%s %s %d: Share above target",
        "submit_tested_work",
        *(const char **)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 4) + 8),
        *(_DWORD *)(*(_DWORD *)(a1 + 36) + 8));
      sub_385C8(7, s, 0);
      return 0;
    }
  }
  else
  {
    return 0;
  }
  return result;
}
