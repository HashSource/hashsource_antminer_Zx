void check_sensor_ID()
{
  uint8_t *chain_exist; // r11
  int i; // r4
  int v2; // t1
  int v3; // r5
  char *v4; // r8
  int v5; // r12
  int v6; // t1
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "check_sensor_ID");
    applog(7, tmp42, 0);
  }
  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
    {
      v3 = 0;
      v4 = &sensor_id[4 * i];
      do
      {
        read_i2c_reg(i, v3, 0x4Cu, 0xFEu);
        v6 = *v4++;
        v5 = v6;
        if ( use_syslog || opt_log_output || opt_log_level > 2 )
        {
          snprintf(tmp42, 0x1000u, "%s: Chain%d Sensor%d Manufacturer ID = 0x%02x", "check_sensor_ID", i, v3, v5);
          applog(3, tmp42, 0);
        }
        ++v3;
      }
      while ( v3 != 3 );
    }
  }
}
