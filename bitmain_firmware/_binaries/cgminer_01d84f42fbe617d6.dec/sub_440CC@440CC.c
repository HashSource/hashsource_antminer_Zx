void *__fastcall sub_440CC(_DWORD *a1, __int16 a2)
{
  void *v4; // r4
  const char *v6; // r0
  _DWORD v7[3]; // [sp+4h] [bp-Ch] BYREF

  v4 = (void *)sub_45E94(v7);
  if ( v4 )
    return 0;
  if ( !sub_4401C(a1, (int (__fastcall *)(char *, int, int))sub_43934, (int)v7, a2) )
  {
    v6 = (const char *)sub_45F0C((int)v7);
    v4 = sub_45E2C(v6);
  }
  sub_45ECC((int)v7);
  return v4;
}
