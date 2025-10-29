bool erase_PIC16F1704_app_flash_new()
{
  const char *v0; // r2
  int v1; // r4
  _BOOL4 result; // r0
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  set_PIC16F1704_flash_pointer_new(6u, 0);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v0) = -27784;
    HIWORD(v0) = (unsigned int)", \t\tread_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n" >> 16;
    snprintf(tmp42, 0x1000u, v0, "erase_PIC16F1704_app_flash_new", 76);
    applog(5, tmp42, 0);
  }
  v1 = 76;
  do
  {
    result = erase_PIC16F1704_flash_new();
    --v1;
  }
  while ( v1 );
  return result;
}
