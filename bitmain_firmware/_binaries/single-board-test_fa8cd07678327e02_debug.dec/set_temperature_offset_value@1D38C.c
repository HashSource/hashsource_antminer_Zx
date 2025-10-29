void __cdecl set_temperature_offset_value(unsigned int which_i2c, unsigned __int8 which_chain, unsigned __int8 *value)
{
  char tmp42[1024]; // [sp+10h] [bp+10h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "--- %s\n", "set_temperature_offset_value");
    applog(2, tmp42, 0);
  }
  write_temperature_offset_PIC16F1704(which_i2c, which_chain, value);
  usleep(0x186A0u);
}
