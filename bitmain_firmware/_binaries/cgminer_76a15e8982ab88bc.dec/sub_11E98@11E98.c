void __fastcall sub_11E98(int a1)
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
  sub_3030C(v6, 0x50u, (int)v5);
  sub_3030C(v5, 0x20u, v2);
  v3 = sub_29688(v2, 32);
  v4 = (char *)v3;
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "regen:%s", v3);
    sub_385C8(5, s, 0);
  }
  free(v4);
}
