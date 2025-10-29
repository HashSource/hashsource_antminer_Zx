uint16_t __fastcall ISL_set_voltage_dynamic(uint8_t i2c_dev_addr, uint16_t vol)
{
  int v3; // r5
  uint16_t v4; // r6
  int v6; // [sp+8h] [bp-101Ch]
  uint8_t v7; // [sp+Ch] [bp-1018h]
  int v8; // [sp+10h] [bp-1014h]
  int v9; // [sp+14h] [bp-1010h]
  uint8_t which_page; // [sp+1Bh] [bp-1009h] BYREF
  uint8_t cmd[2]; // [sp+1Ch] [bp-1008h] BYREF
  uint16_t r_voltage; // [sp+1Eh] [bp-1006h] BYREF
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( (unsigned int)(vol - 700) > 0x64 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      v3 = 700;
      snprintf(tmp42, 0x1000u, "illegal voltage [%d, %d], set default voltage %d\n", 700, 800, 700);
      applog(5, tmp42, 0);
      LOBYTE(v8) = 2;
      v9 = 704;
      v7 = -68;
    }
    else
    {
      LOBYTE(v8) = 2;
      v9 = 704;
      v7 = -68;
      v3 = 700;
    }
  }
  else
  {
    v3 = vol;
    v7 = vol;
    v8 = HIBYTE(vol);
    v9 = vol + 4;
  }
  r_voltage = 0;
  LOBYTE(v6) = 4;
  while ( 1 )
  {
    which_page = -1;
    write_dc_dc(i2c_dev_addr, 0, &which_page, 1);
    cgsleep_ms(100);
    cmd[0] = v7;
    cmd[1] = v8;
    write_dc_dc(i2c_dev_addr, 0x21u, cmd, 2);
    cgsleep_ms(200);
    ISL_get_voltage(i2c_dev_addr, &r_voltage);
    v4 = r_voltage;
    if ( r_voltage <= v9 && r_voltage >= v3 - 4 )
      break;
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf(tmp42, 0x1000u, "set vol %d, get vol %d, set again!\n", v3, r_voltage);
      applog(5, tmp42, 0);
    }
    cgsleep_ms(200);
    v6 = (unsigned __int8)(v6 - 1);
    if ( !v6 )
      return r_voltage;
  }
  return v4;
}
