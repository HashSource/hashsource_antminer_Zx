void __fastcall sub_1F5DC(int a1)
{
  int v2; // r0
  char s[2048]; // [sp+8h] [bp-800h] BYREF

  if ( !sub_17E64(a1, (_BYTE *)(a1 + 97)) )
  {
    sub_2B13C((struct timeval *)(a1 + 136));
    v2 = sub_1D644();
    if ( v2 == a1 )
    {
      if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
      {
        snprintf(s, 0x800u, "Pool %d %s not responding!", *(_DWORD *)v2, *(const char **)(v2 + 164));
        sub_38438(4, s, 0);
      }
      sub_195D4(0);
    }
    else if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      snprintf(s, 0x800u, "Pool %d %s failed to return work", *(_DWORD *)a1, *(const char **)(a1 + 164));
      sub_38438(7, s, 0);
    }
  }
}
