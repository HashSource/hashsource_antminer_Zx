_DWORD *__fastcall sub_117A4(int a1)
{
  int i; // r1
  _BYTE v4[32]; // [sp+0h] [bp-70h] BYREF
  _BYTE v5[80]; // [sp+20h] [bp-50h] BYREF

  for ( i = 0; i != 80; i += 4 )
    *(_DWORD *)&v5[i] = bswap32(*(_DWORD *)(a1 + i));
  sub_303DC(v5, 0x50u, (int)v4);
  return sub_303DC(v4, 0x20u, a1 + 192);
}
