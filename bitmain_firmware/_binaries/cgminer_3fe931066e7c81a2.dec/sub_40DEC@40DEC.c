int sub_40DEC()
{
  int v0; // r4
  int result; // r0
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  sub_3D000(6, 0);
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "%s: erase_loop = %d\n", "erase_PIC16F1704_app_flash_new", 76);
    sub_38730(5, s, 0);
  }
  v0 = 76;
  do
  {
    result = sub_3DA84();
    --v0;
  }
  while ( v0 );
  return result;
}
