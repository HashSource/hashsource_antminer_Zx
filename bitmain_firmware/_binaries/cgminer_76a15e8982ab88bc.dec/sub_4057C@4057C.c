int sub_4057C()
{
  int v0; // r4
  int result; // r0
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  sub_3CCC0(6, 0);
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%s: erase_loop = %d\n", "erase_PIC16F1704_app_flash_new", 76);
    sub_385C8(5, s, 0);
  }
  v0 = 76;
  do
  {
    result = sub_3D744();
    --v0;
  }
  while ( v0 );
  return result;
}
