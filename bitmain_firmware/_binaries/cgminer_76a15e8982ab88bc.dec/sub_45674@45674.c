int __fastcall sub_45674(int a1, int a2, char a3, unsigned __int8 a4, unsigned __int8 a5)
{
  unsigned int v5; // r12
  char v7; // r2
  _DWORD v9[2]; // [sp+Ch] [bp-10h] BYREF
  __int16 v10; // [sp+14h] [bp-8h]
  char v11; // [sp+16h] [bp-6h]

  v5 = dword_739A8 & 0xFE0100FF | 0x1000000 | ((a3 & 0x7F) << 17) | (a4 << 8);
  v7 = *((_BYTE *)&dword_75C50[200] + a2);
  v9[0] = 0;
  v9[1] = 0;
  v10 = 0;
  v11 = 0;
  sub_3CA8C((int)v9, 0, v7, 32, v5 & 0xFFFFFF00 | a5 | 0x10000);
  sub_3BFB4(a1, v9, 0xBu);
  return sub_2A884();
}
