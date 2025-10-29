int __fastcall sub_B340(int a1)
{
  char v3[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
  {
    snprintf(v3, 0x1000u, "WTF No pool %d found!", a1);
    sub_38730(3, v3, 0);
  }
  return *(_DWORD *)(dword_7B438 + 4 * a1);
}
