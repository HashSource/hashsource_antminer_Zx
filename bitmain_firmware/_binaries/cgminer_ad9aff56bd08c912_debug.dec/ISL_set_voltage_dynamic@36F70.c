uint16_t __fastcall ISL_set_voltage_dynamic(uint8_t i2c_dev_addr, uint16_t vol)
{
  int v3; // r5
  const char *v4; // r9
  uint16_t v5; // r6
  const char *v7; // r2
  int v8; // [sp+8h] [bp-101Ch]
  uint8_t v9; // [sp+Ch] [bp-1018h]
  int v10; // [sp+10h] [bp-1014h]
  int v11; // [sp+14h] [bp-1010h]
  uint8_t which_page; // [sp+1Bh] [bp-1009h] BYREF
  uint8_t cmd[2]; // [sp+1Ch] [bp-1008h] BYREF
  uint16_t r_voltage; // [sp+1Eh] [bp-1006h] BYREF
  char tmp42[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( (unsigned int)(vol - 700) > 0x64 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      v3 = 700;
      LOWORD(v7) = -29272;
      HIWORD(v7) = (unsigned int)"chain%d asic%d, slave:%02x, addr:%02x %02x\n" >> 16;
      snprintf(tmp42, 0x1000u, v7, 700, 800, 700);
      applog(5, tmp42, 0);
      LOBYTE(v10) = 2;
      v11 = 704;
      v9 = -68;
    }
    else
    {
      LOBYTE(v10) = 2;
      v11 = 704;
      v9 = -68;
      v3 = 700;
    }
  }
  else
  {
    v3 = vol;
    v9 = vol;
    v10 = HIBYTE(vol);
    v11 = vol + 4;
  }
  LOWORD(v4) = -29220;
  r_voltage = 0;
  LOBYTE(v8) = 4;
  while ( 1 )
  {
    which_page = -1;
    write_dc_dc(i2c_dev_addr, 0, &which_page, 1);
    cgsleep_ms(100);
    cmd[0] = v9;
    cmd[1] = v10;
    write_dc_dc(i2c_dev_addr, 0x21u, cmd, 2);
    cgsleep_ms(200);
    ISL_get_voltage(i2c_dev_addr, &r_voltage);
    v5 = r_voltage;
    if ( r_voltage <= v11 && r_voltage >= v3 - 4 )
      break;
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      HIWORD(v4) = (unsigned int)"asic%d, slave:%02x, addr:%02x %02x %02x\n" >> 16;
      snprintf(tmp42, 0x1000u, v4, v3, r_voltage);
      applog(5, tmp42, 0);
    }
    cgsleep_ms(200);
    v8 = (unsigned __int8)(v8 - 1);
    if ( !v8 )
      return r_voltage;
  }
  return v5;
}
