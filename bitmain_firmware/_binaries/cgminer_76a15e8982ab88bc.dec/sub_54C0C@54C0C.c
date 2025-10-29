void *__fastcall sub_54C0C(_DWORD *a1, __int16 a2)
{
  void *v4; // r4
  const char *v6; // r0
  _DWORD v7[3]; // [sp+4h] [bp-Ch] BYREF

  v4 = (void *)sub_569D4(v7);
  if ( v4 )
    return 0;
  if ( !sub_54B5C(a1, (int (__fastcall *)(char *, int, int))sub_54474, (int)v7, a2) )
  {
    v6 = (const char *)sub_56A4C((int)v7);
    v4 = sub_5696C(v6);
  }
  sub_56A0C((int)v7);
  return v4;
}
