int __fastcall sub_3E564(char a1, _WORD *a2)
{
  __int16 v4; // [sp+4h] [bp-8h] BYREF

  v4 = 0;
  sub_3CA38(a1, 33, (int)&v4, 2);
  *a2 = (unsigned __int8)v4 | (HIBYTE(v4) << 8);
  return 0;
}
