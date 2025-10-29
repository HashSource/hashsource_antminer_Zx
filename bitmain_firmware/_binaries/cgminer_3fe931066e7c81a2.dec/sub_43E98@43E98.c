int __fastcall sub_43E98(int a1, char a2)
{
  _DWORD v4[2]; // [sp+Ch] [bp-10h] BYREF
  __int16 v5; // [sp+14h] [bp-8h]
  char v6; // [sp+16h] [bp-6h]

  dword_76B5C = dword_76B5C & 0xFFFFE0FF | ((a2 & 0x1F) << 8);
  v4[0] = 0;
  v4[1] = 0;
  v5 = 0;
  v6 = 0;
  sub_3CDCC((int)v4, 1, 0, 28, dword_76B5C);
  sub_3C150(a1, v4, 0xBu);
  return sub_2A92C();
}
