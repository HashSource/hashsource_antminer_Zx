void set_PWM_according_to_temperature()
{
  float v0; // s0
  int fan_pwm; // r3
  int v2; // r2
  unsigned int *v3; // r1
  int v4; // r6
  unsigned int *v5; // r2
  unsigned int v6; // r3
  uint8_t v7; // r0
  unsigned int *v8; // r2
  int v9; // r1
  int v10; // r0
  int v11; // r2
  uint8_t v12; // r0
  unsigned int *v13; // r3
  const char *v14; // r2
  char tmp42[4096]; // [sp+8h] [bp-1000h] BYREF

  temp_highest = dev.temp_top1;
  if ( !dev.fan_eft || (fan_pwm = dev.fan_pwm, dev.fan_pwm > 0x64u) )
  {
    v4 = dev.temp_top1 > 62 || dev.temp_top1 == 0;
    if ( v4 )
    {
      v8 = axi_fpga_addr;
      dev.pwm_percent = 100;
      axi_fpga_addr[33] = 6553600;
      v8[40] = 6553600;
      dev.fan_pwm = 100;
      return;
    }
    if ( dev.temp_top1 <= 35 )
    {
      v5 = axi_fpga_addr;
      v6 = 2621500;
      if ( gMinerStatus_Not_read_all_sensor )
      {
        v6 = 6553600;
        v7 = 100;
      }
      else
      {
        v7 = 40;
      }
      dev.pwm_percent = v7;
      axi_fpga_addr[33] = v6;
      v5[40] = v6;
      dev.fan_pwm = 40;
      return;
    }
    if ( (unsigned int)(dev.temp_top1 - last_temperature + 1) <= 2 )
      return;
    adjust_pwm_bm1744_4chips(dev.temp_top1);
    v10 = (int)v0;
    if ( (int)v0 < 0 )
    {
      dev.fan_pwm = 0;
      if ( !opt_debug )
        goto LABEL_33;
      v10 = 0;
    }
    else
    {
      dev.fan_pwm = (int)v0;
      v4 = (unsigned __int8)v10;
      if ( !opt_debug )
        goto LABEL_20;
    }
    if ( use_syslog || opt_log_output || opt_log_level > 6 )
    {
      LOWORD(v14) = -25132;
      HIWORD(v14) = (unsigned int)" /sys/class/gpio/gpio954/value" >> 16;
      snprintf(tmp42, 0x1000u, v14, "set_PWM_according_to_temperature", v10);
      applog(7, tmp42, 0);
      v9 = temp_highest;
    }
LABEL_20:
    if ( v4 > 39 )
    {
      if ( v4 > 100 )
        goto LABEL_22;
      goto LABEL_34;
    }
LABEL_33:
    v4 = 40;
LABEL_34:
    if ( !gMinerStatus_Not_read_all_sensor )
    {
      v12 = v4;
      v11 = (100 - v4) | (v4 << 16);
      goto LABEL_23;
    }
LABEL_22:
    v11 = 6553600;
    v12 = 100;
LABEL_23:
    v13 = axi_fpga_addr;
    dev.pwm_percent = v12;
    last_temperature = v9;
    axi_fpga_addr[33] = v11;
    v13[40] = v11;
    return;
  }
  if ( gMinerStatus_Not_read_all_sensor )
  {
    v2 = 6553600;
    LOBYTE(fan_pwm) = 100;
  }
  else
  {
    if ( dev.fan_pwm < 0x28u )
      fan_pwm = 40;
    v2 = (100 - fan_pwm) | (fan_pwm << 16);
  }
  v3 = axi_fpga_addr;
  dev.pwm_percent = fan_pwm;
  axi_fpga_addr[33] = v2;
  v3[40] = v2;
}
