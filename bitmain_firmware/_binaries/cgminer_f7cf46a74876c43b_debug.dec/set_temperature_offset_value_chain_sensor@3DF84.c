void __fastcall set_temperature_offset_value_chain_sensor(unsigned __int8 which_chain, unsigned __int8 which_sensor)
{
  int v2; // r5
  int v3; // r7
  char *v4; // r4
  int v5; // r1
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v2 = which_chain;
  v3 = which_sensor;
  if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    snprintf(tmp42, 0x1000u, "Chain %d %s", which_chain, "set_temperature_offset_value_chain_sensor");
    applog(4, tmp42, 0);
  }
  v4 = (char *)&(&axi_fpga_addr)[v2] + v3;
  write_i2c_reg(v2, v3, 0x4Cu, 0x11u, v4[3540]);
  cgsleep_ms(50);
  read_i2c_reg(v2, v3, 0x4Cu, 0x11u);
  v5 = v4[3540];
  if ( v4[3508] == v5 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf(
        tmp42,
        0x1000u,
        "%s: Chain%d Sensor%d temp offset : %02d, ",
        "set_temperature_offset_value_chain_sensor",
        v2,
        v3,
        v4[3508]);
      applog(5, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s: Chain%d Sensor%d temp offset value set error. It should be %02d, but read back is %02d\n",
      "set_temperature_offset_value_chain_sensor",
      v2,
      v3,
      v5,
      v4[3508]);
    applog(3, tmp42, 0);
  }
}
