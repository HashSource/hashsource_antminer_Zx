int __fastcall sub_3CBB0(int a1, char a2, char a3, char a4)
{
  char v5; // r0
  int v6; // t1
  __int16 v7; // r3
  int v9; // [sp+0h] [bp-Ch] BYREF
  __int16 v10; // [sp+4h] [bp-8h]
  char v11; // [sp+6h] [bp-6h]

  LOBYTE(v10) = a3;
  HIBYTE(v10) = a4;
  BYTE2(v9) = (16 * (a2 & 1)) | 0x42;
  v11 &= 0x1Fu;
  LOWORD(v9) = -21931;
  HIBYTE(v9) = 5;
  v5 = sub_3C92C((_BYTE *)&v9 + 2, 32);
  v6 = v9;
  *(_BYTE *)(a1 + 6) = v11 & 0xE0 | v5 & 0x1F;
  v7 = v10;
  *(_DWORD *)a1 = v6;
  *(_WORD *)(a1 + 4) = v7;
  return 7;
}
