void __fastcall select_core_to_check_temperature(uint32_t analog_mux_reg_value)
{
  const char *v2; // r2
  unsigned int i; // r4
  unsigned int v4; // r0
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    LOWORD(v2) = -25072;
    HIWORD(v2) = (unsigned int)"o955/value" >> 16;
    snprintf(tmp42, 0x1000u, v2, "select_core_to_check_temperature", analog_mux_reg_value);
    applog(5, tmp42, 0);
  }
  for ( i = 0; i != 4; ++i )
  {
    v4 = i;
    select_core_to_check_temperature_chain(v4, analog_mux_reg_value);
  }
}
