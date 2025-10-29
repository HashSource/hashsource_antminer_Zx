void __fastcall sub_1FB7C(_DWORD *a1)
{
  int v1; // r3
  int v3; // r5
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v1 = dword_73D34;
  a1[7] = 0;
  if ( v1 || (v3 = a1[1], v3 >= sub_1FAC4()) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(s, 0x1000u, "Pool %d %s alive", *a1, (const char *)a1[49]);
      sub_385C8(7, s, 0);
    }
  }
  else if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    snprintf(s, 0x1000u, "Pool %d %s alive, testing stability", *a1, (const char *)a1[49]);
    sub_385C8(4, s, 0);
  }
}
