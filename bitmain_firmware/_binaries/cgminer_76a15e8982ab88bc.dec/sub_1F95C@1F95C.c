void __fastcall sub_1F95C(int a1)
{
  int v2; // r0
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  if ( !sub_1859C(a1, (_BYTE *)(a1 + 129)) )
  {
    sub_2A7A4((struct timeval *)(a1 + 168));
    v2 = sub_1D9A0();
    if ( v2 == a1 )
    {
      if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
      {
        snprintf(s, 0x1000u, "Pool %d %s not responding!", *(_DWORD *)v2, *(const char **)(v2 + 196));
        sub_385C8(4, s, 0);
      }
      sub_1A600(0);
    }
    else if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(s, 0x1000u, "Pool %d %s failed to return work", *(_DWORD *)a1, *(const char **)(a1 + 196));
      sub_385C8(7, s, 0);
    }
  }
}
