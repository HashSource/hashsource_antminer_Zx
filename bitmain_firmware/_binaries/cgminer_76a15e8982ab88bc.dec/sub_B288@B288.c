int __fastcall sub_B288(int a1)
{
  char v3[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
  {
    snprintf(v3, 0x1000u, "WTF No pool %d found!", a1);
    sub_385C8(3, v3, 0);
  }
  return *(_DWORD *)(dword_78260 + 4 * a1);
}
