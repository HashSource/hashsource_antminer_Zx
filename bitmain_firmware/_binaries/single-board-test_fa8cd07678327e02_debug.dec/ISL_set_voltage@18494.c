uint16_t __cdecl ISL_set_voltage(uint8_t which_chain, uint8_t which_i2c, uint8_t i2c_dev_addr, uint16_t voltage)
{
  uint16_t r_voltage; // [sp+Ch] [bp+Ch] BYREF
  uint8_t retry_limits; // [sp+Eh] [bp+Eh]
  uint8_t retry; // [sp+Fh] [bp+Fh]

  puts("begin to read voltage");
  ISL_page_enable(which_chain, which_i2c, i2c_dev_addr, 0);
  usleep(0x186A0u);
  usleep(0x186A0u);
  ISL_set_vout_command(which_chain, which_i2c, i2c_dev_addr, voltage);
  usleep(0x186A0u);
  usleep(0x186A0u);
  puts("end to read voltage");
  retry = 0;
  retry_limits = 5;
  r_voltage = 0;
  do
  {
    usleep(0x186A0u);
    ISL_get_voltage(which_chain, which_i2c, i2c_dev_addr, &r_voltage);
    ++retry;
  }
  while ( retry <= (unsigned int)retry_limits && !r_voltage );
  printf("--- ISL_get_voltage, Voltage: 0.%03d V\n\n", r_voltage);
  return r_voltage;
}
