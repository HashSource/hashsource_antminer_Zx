void calculate_address_interval()
{
  int v0; // r0
  uint8_t addrInterval; // r2
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  v0 = 256 / calculate_asic_number(3u);
  dev.addrInterval = v0;
  if ( use_syslog || opt_log_output || (addrInterval = v0, opt_log_level > 4) )
  {
    snprintf(tmp42, 0x1000u, "%s:addrInterval = %d", "calculate_address_interval", (unsigned __int8)v0);
    applog(5, tmp42, 0);
    addrInterval = dev.addrInterval;
  }
  TempChipAddr[1] = addrInterval;
  TempChipAddr[2] = 2 * addrInterval;
  TempChipAddr[0] = 0;
}
