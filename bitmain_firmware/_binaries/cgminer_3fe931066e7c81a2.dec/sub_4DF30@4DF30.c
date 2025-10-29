int __fastcall sub_4DF30(void *src, int a2, void *a3, unsigned __int8 a4)
{
  int srca; // [sp+4h] [bp-170h] BYREF
  _BYTE dest[364]; // [sp+8h] [bp-16Ch] BYREF

  srca = a2;
  memcpy(dest, src, 0x168u);
  sub_54F8C((int)dest, (char *)&srca, 4u);
  return sub_551D4((int)dest, a3, a4);
}
