int __fastcall sub_14FD0(int a1, int a2, unsigned int a3)
{
  unsigned int v3; // r5
  int i; // r1
  unsigned int v5; // r4
  _BYTE v7[131592]; // [sp+8h] [bp-21284h] BYREF
  int v8[8]; // [sp+20210h] [bp-107Ch] BYREF
  int v9[20]; // [sp+20230h] [bp-105Ch] BYREF
  char v10[12]; // [sp+20280h] [bp-100Ch] BYREF

  v3 = *(_DWORD *)(a2 + 28);
  for ( i = 0; i != 19; ++i )
    v9[i] = bswap32(*(_DWORD *)(a1 + i * 4));
  v9[19] = bswap32(a3);
  sub_122E8(v9, (int)v7, v8);
  v5 = bswap32(v8[7]);
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(v10, 0x1000u, "htarget %08lx diff1 %08lx hash %08lx", v3, 0xFFFF, v5);
    sub_38730(7, v10, 0);
  }
  if ( v5 >= 0x10000 )
    return -1;
  else
    return v3 >= v5;
}
