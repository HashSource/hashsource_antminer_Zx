bool erase_PIC16F1704_app_flash_new()
{
  int v0; // r4
  _BOOL4 result; // r0
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  set_PIC16F1704_flash_pointer_new(6u, 0);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "%s: erase_loop = %d\n", "erase_PIC16F1704_app_flash_new", 76);
    applog(5, tmp42, 0);
  }
  v0 = 76;
  do
  {
    result = erase_PIC16F1704_flash_new();
    --v0;
  }
  while ( v0 );
  return result;
}
