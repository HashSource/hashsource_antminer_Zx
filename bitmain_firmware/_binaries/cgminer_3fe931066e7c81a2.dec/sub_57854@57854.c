void *__fastcall sub_57854(_DWORD *a1, __int16 a2)
{
  void *v4; // r4
  const char *v6; // r0
  _DWORD v7[3]; // [sp+4h] [bp-Ch] BYREF

  v4 = (void *)sub_5961C(v7);
  if ( v4 )
    return 0;
  if ( !sub_577A4(a1, (int (__fastcall *)(char *, int, int))sub_570BC, (int)v7, a2) )
  {
    v6 = (const char *)sub_59694((int)v7);
    v4 = sub_595B4(v6);
  }
  sub_59654((int)v7);
  return v4;
}
