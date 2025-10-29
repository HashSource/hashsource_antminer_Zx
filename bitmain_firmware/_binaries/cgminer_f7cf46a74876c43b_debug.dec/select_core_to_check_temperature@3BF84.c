void __fastcall select_core_to_check_temperature(uint32_t analog_mux_reg_value)
{
  unsigned int i; // r4
  unsigned int v3; // r0
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s: analog_mux_reg_value = %08x",
      "select_core_to_check_temperature",
      analog_mux_reg_value);
    applog(5, tmp42, 0);
  }
  for ( i = 0; i != 4; ++i )
  {
    v3 = i;
    select_core_to_check_temperature_chain(v3, analog_mux_reg_value);
  }
}
