int __fastcall sub_3CA8C(int a1, char a2, char a3, char a4, unsigned int a5)
{
  char v6; // r0
  int v7; // r1
  __int16 v8; // r2
  char v9; // r3
  int v11; // [sp+Ch] [bp-10h] BYREF
  _BYTE v12[6]; // [sp+10h] [bp-Ch]
  char v13; // [sp+16h] [bp-6h]

  v12[0] = a3;
  v12[1] = a4;
  BYTE2(v11) = (16 * (a2 & 1)) | 0x41;
  LOWORD(v11) = -21931;
  HIBYTE(v11) = 9;
  *(_DWORD *)&v12[2] = bswap32(a5);
  v13 &= 0x1Fu;
  v6 = sub_3C92C((_BYTE *)&v11 + 2, 64);
  v13 = v13 & 0xE0 | v6 & 0x1F;
  v7 = *(_DWORD *)v12;
  v8 = *(_WORD *)&v12[4];
  v9 = v13;
  *(_DWORD *)a1 = v11;
  *(_DWORD *)(a1 + 4) = v7;
  *(_WORD *)(a1 + 8) = v8;
  *(_BYTE *)(a1 + 10) = v9;
  return 11;
}
