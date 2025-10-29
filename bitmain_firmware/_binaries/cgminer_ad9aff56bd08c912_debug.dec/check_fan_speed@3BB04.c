void check_fan_speed()
{
  const char *v0; // r9
  int v1; // r10
  int v2; // r3
  uint32_t v3; // r1
  char *v4; // r3
  uint8_t fan_num; // r0
  uint32_t fan_speed_low1; // r3
  uint32_t fan_exist_map; // r2
  uint8_t v8; // r12
  bool v9; // cf
  unsigned int v10; // [sp+Ch] [bp-1004h]
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  LOWORD(v0) = -25160;
  dev.fan_speed_top1 = 0;
  dev.fan_speed_low1 = 0;
  while ( 2 )
  {
    v1 = 6;
    do
    {
      v10 = axi_fpga_addr[1];
      if ( v10 == -1 )
        goto LABEL_10;
      v2 = (v10 >> 8) & 7;
      v3 = 120 * (unsigned __int8)v10;
      dev.fan_speed_value[v2] = v3;
      if ( !(_BYTE)v10 )
      {
        v4 = (char *)&dev + v2;
        if ( v4[459] == 1 )
        {
          fan_num = dev.fan_num;
          v4[459] = 0;
          dev.fan_exist_map = 0;
          dev.fan_num = fan_num - 1;
        }
        fan_speed_low1 = dev.fan_speed_low1;
LABEL_8:
        if ( fan_speed_low1 )
          goto LABEL_10;
        goto LABEL_9;
      }
      if ( !dev.fan_exist[v2] )
      {
        fan_exist_map = dev.fan_exist_map;
        v8 = dev.fan_num;
        dev.fan_exist[v2] = 1;
        dev.fan_exist_map = fan_exist_map | (1 << v2);
        dev.fan_num = v8 + 1;
      }
      fan_speed_low1 = dev.fan_speed_low1;
      if ( v3 > dev.fan_speed_top1 )
        dev.fan_speed_top1 = 120 * (unsigned __int8)v10;
      v9 = 1;
      if ( v3 )
        v9 = v3 >= dev.fan_speed_low1;
      if ( v9 )
        goto LABEL_8;
LABEL_9:
      dev.fan_speed_low1 = 120 * (unsigned __int8)v10;
LABEL_10:
      cgsleep_ms(50);
      --v1;
    }
    while ( v1 );
    if ( dev.fan_num <= 1u )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        HIWORD(v0) = (unsigned int)"d Fan2:%d pwm %d" >> 16;
        snprintf(tmp42, 0x1000u, v0, 2);
        applog(5, tmp42, 0);
      }
      cgsleep_ms(1000);
      continue;
    }
    break;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "fan-num %d fan-map %d\n", dev.fan_num, dev.fan_exist_map);
    applog(5, tmp42, 0);
  }
}
