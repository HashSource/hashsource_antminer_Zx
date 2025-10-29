int __fastcall _aeabi_uldivmod(UDItype a1, UDItype a2)
{
  UDItype v3; // [sp+8h] [bp-8h] BYREF

  if ( a2 )
    return _udivmoddi4(a1, a2, &v3);
  else
    return _aeabi_ldiv0();
}
