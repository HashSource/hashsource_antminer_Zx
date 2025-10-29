uint16_t __fastcall ISL_set_voltage(uint8_t i2c_dev_addr, uint16_t voltage)
{
  uint16_t v2; // r3
  const char *v3; // r2
  int v7; // r4
  uint8_t which_page; // [sp+9h] [bp-1007h] BYREF
  uint8_t config; // [sp+Ah] [bp-1006h] BYREF
  uint8_t oper; // [sp+Bh] [bp-1005h] BYREF
  uint8_t cmd[4]; // [sp+Ch] [bp-1004h] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  if ( (unsigned int)(voltage - 700) <= 0x64 )
  {
    which_page = -1;
    write_dc_dc(i2c_dev_addr, 0, &which_page, 1);
    config = 26;
    write_dc_dc(i2c_dev_addr, 2u, &config, 1);
    cgsleep_ms(100);
    oper = 64;
    LOBYTE(v7) = 5;
    write_dc_dc(i2c_dev_addr, 1u, &oper, 1);
    cgsleep_ms(100);
    *(_WORD *)cmd = voltage;
    write_dc_dc(i2c_dev_addr, 0x21u, cmd, 2);
    cgsleep_ms(100);
    oper = 0x80;
    write_dc_dc(i2c_dev_addr, 1u, &oper, 1);
    cgsleep_ms(100);
    *(_WORD *)tmp42 = 0;
    cgsleep_ms(200);
    ISL_get_voltage(i2c_dev_addr, (uint16_t *)tmp42);
    while ( 1 )
    {
      v2 = *(_WORD *)tmp42;
      if ( *(_WORD *)tmp42 )
        break;
      cgsleep_ms(200);
      ISL_get_voltage(i2c_dev_addr, (uint16_t *)tmp42);
      v7 = (unsigned __int8)(v7 - 1);
      if ( !v7 )
        return *(_WORD *)tmp42;
    }
  }
  else if ( use_syslog || (v2 = opt_log_output) != 0 || opt_log_level > 4 )
  {
    LOWORD(v3) = -29184;
    HIWORD(v3) = (unsigned int)"02x\n" >> 16;
    snprintf(tmp42, 0x1000u, v3, 700, 800);
    applog(5, tmp42, 0);
    return 0;
  }
  return v2;
}
