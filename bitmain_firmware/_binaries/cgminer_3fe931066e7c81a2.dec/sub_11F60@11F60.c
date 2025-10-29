void __fastcall sub_11F60(int a1)
{
  int i; // r1
  int v2; // r4
  const char *v3; // r0
  char *v4; // r4
  _BYTE v5[32]; // [sp+0h] [bp-1070h] BYREF
  char v6[80]; // [sp+20h] [bp-1050h] BYREF
  char s[4096]; // [sp+70h] [bp-1000h] BYREF

  for ( i = 0; i != 80; i += 4 )
    *(_DWORD *)&v6[i] = bswap32(*(_DWORD *)(a1 + i));
  v2 = a1 + 192;
  sub_3049C(v6, 0x50u, (int)v5);
  sub_3049C(v5, 0x20u, v2);
  v3 = sub_29730(v2, 32);
  v4 = (char *)v3;
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "regen:%s", v3);
    sub_38730(5, s, 0);
  }
  free(v4);
}
