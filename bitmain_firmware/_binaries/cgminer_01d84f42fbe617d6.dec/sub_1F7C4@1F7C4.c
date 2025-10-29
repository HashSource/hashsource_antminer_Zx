void __fastcall sub_1F7C4(_DWORD *a1)
{
  int v1; // r3
  int v3; // r5
  char s[2052]; // [sp+8h] [bp-804h] BYREF

  v1 = dword_611AC;
  a1[7] = 0;
  if ( v1 || (v3 = a1[1], v3 >= sub_1F70C()) )
  {
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      snprintf(s, 0x800u, "Pool %d %s alive", *a1, (const char *)a1[41]);
      sub_38438(7, s, 0);
    }
  }
  else if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
  {
    snprintf(s, 0x800u, "Pool %d %s alive, testing stability", *a1, (const char *)a1[41]);
    sub_38438(4, s, 0);
  }
}
