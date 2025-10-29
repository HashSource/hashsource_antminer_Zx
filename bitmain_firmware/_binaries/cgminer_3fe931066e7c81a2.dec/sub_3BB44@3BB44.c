int __fastcall sub_3BB44(int a1)
{
  int result; // r0

  result = sub_3BB00(a1) & 0x3F;
  *(_DWORD *)(dword_78E10[0] + 60) = result & 0x3F
                                   | ((result & 0x3F) << 8)
                                   | ((result & 0x3F) << 16) & 0xC0FFFFFF
                                   | ((result & 0x3F) << 24);
  return result;
}
