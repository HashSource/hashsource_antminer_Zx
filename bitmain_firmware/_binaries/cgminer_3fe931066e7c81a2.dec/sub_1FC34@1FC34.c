void __fastcall sub_1FC34(_DWORD *a1)
{
  int v1; // r3
  int v3; // r5
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v1 = dword_76EFC;
  a1[7] = 0;
  if ( v1 || (v3 = a1[1], v3 >= sub_1FB7C()) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "Pool %d %s alive", *a1, (const char *)a1[49]);
      sub_38730(7, s, 0);
    }
  }
  else if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
  {
    snprintf(s, 0x1000u, "Pool %d %s alive, testing stability", *a1, (const char *)a1[49]);
    sub_38730(4, s, 0);
  }
}
