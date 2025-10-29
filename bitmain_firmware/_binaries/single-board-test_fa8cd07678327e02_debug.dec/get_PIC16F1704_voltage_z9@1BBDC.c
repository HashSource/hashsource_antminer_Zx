void __cdecl get_PIC16F1704_voltage_z9(uint32_t i2c, uint8_t chain)
{
  char tmp42[1024]; // [sp+1Ch] [bp+Ch] BYREF
  uint8_t read_vol[12]; // [sp+41Ch] [bp+40Ch] BYREF
  size_t i; // [sp+42Ch] [bp+41Ch]

  for ( i = 0; i <= 3; ++i )
  {
    memset(read_vol, 0, sizeof(read_vol));
    if ( PIC16F1704_i2c_forward_send(i2c, chain, isl68127_i2c_dev_addr[i], 1, 0x21u, 2, read_vol) )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(
          tmp42,
          0x400u,
          "read %02x vol failed, 0x%02x%02x\n",
          isl68127_i2c_dev_addr[i],
          read_vol[0],
          read_vol[1]);
        applog(2, tmp42, 0);
      }
    }
    else if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "read %02x vol success, 0x%02x%02x\n", isl68127_i2c_dev_addr[i], read_vol[0], read_vol[1]);
      applog(2, tmp42, 0);
    }
  }
}
