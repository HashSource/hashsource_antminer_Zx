int __fastcall sub_3CB3C(int a1, unsigned __int8 a2)
{
  char v3; // r0
  char v4; // r3
  char v5; // r3
  int v6; // r0
  int v8; // [sp+0h] [bp-8h] BYREF
  char v9; // [sp+4h] [bp-4h]

  HIWORD(v8) = a2;
  v9 = 0;
  LOWORD(v8) = 1344;
  v3 = sub_3C92C(&v8, 32);
  v4 = v9;
  *(_BYTE *)a1 = 85;
  *(_BYTE *)(a1 + 1) = -86;
  v5 = v4 & 0xE0 | v3 & 0x1F;
  v6 = v8;
  *(_BYTE *)(a1 + 6) = v5;
  *(_DWORD *)(a1 + 2) = v6;
  return 7;
}
