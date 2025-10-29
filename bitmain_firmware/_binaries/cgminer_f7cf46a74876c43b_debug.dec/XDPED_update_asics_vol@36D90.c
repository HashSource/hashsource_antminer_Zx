int __fastcall XDPED_update_asics_vol(uint32_t vol)
{
  char reg_data[4]; // [sp+Ch] [bp-1008h] BYREF
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  *(_DWORD *)reg_data = 0;
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "xdped set voltage to %d\n", vol);
    applog(5, tmp42, 0);
  }
  reg_data[0] = 32;
  ISL_set_i2c_data(0, (uint8_t *)reg_data, 1);
  sleep(1u);
  reg_data[1] = 64;
  reg_data[0] = (unsigned int)(((double)vol / 1000.0 - 0.25) / 0.005 + 1.0);
  return ISL_set_i2c_data(0x13u, (uint8_t *)reg_data, 2);
}
