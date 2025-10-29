void __fastcall sub_1FA14(int a1)
{
  int v2; // r0
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  if ( !sub_18834(a1, (_BYTE *)(a1 + 129)) )
  {
    sub_2A84C((struct timeval *)(a1 + 168));
    v2 = sub_1DA58();
    if ( v2 == a1 )
    {
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
      {
        snprintf(s, 0x1000u, "Pool %d %s not responding!", *(_DWORD *)v2, *(const char **)(v2 + 196));
        sub_38730(4, s, 0);
      }
      sub_19BF8(0);
    }
    else if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "Pool %d %s failed to return work", *(_DWORD *)a1, *(const char **)(a1 + 196));
      sub_38730(7, s, 0);
    }
  }
}
