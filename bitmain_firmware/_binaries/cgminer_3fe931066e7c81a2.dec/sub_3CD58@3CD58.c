int __fastcall sub_3CD58(int a1)
{
  char v2; // r0
  char v3; // r3
  char v4; // r3
  int v5; // r0
  int v7; // [sp+0h] [bp-8h] BYREF
  char v8; // [sp+4h] [bp-4h]

  v8 = 0;
  v7 = 1363;
  v2 = sub_3CC6C(&v7, 32);
  v3 = v8;
  *(_BYTE *)a1 = 85;
  *(_BYTE *)(a1 + 1) = -86;
  v4 = v3 & 0xE0 | v2 & 0x1F;
  v5 = v7;
  *(_BYTE *)(a1 + 6) = v4;
  *(_DWORD *)(a1 + 2) = v5;
  return 7;
}
