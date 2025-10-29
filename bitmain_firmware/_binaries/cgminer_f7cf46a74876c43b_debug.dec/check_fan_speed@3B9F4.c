void check_fan_speed()
{
  int v0; // r10
  int v1; // r3
  uint32_t v2; // r1
  char *v3; // r3
  uint8_t fan_num; // r0
  uint32_t fan_speed_low1; // r3
  uint32_t fan_exist_map; // r2
  uint8_t v7; // r12
  bool v8; // cf
  unsigned int v9; // [sp+Ch] [bp-1004h]
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  dev.fan_speed_top1 = 0;
  dev.fan_speed_low1 = 0;
  while ( 2 )
  {
    v0 = 6;
    do
    {
      v9 = axi_fpga_addr[1];
      if ( v9 == -1 )
        goto LABEL_10;
      v1 = (v9 >> 8) & 7;
      v2 = 120 * (unsigned __int8)v9;
      dev.fan_speed_value[v1] = v2;
      if ( !(_BYTE)v9 )
      {
        v3 = (char *)&dev + v1;
        if ( v3[459] == 1 )
        {
          fan_num = dev.fan_num;
          v3[459] = 0;
          dev.fan_exist_map = 0;
          dev.fan_num = fan_num - 1;
        }
        fan_speed_low1 = dev.fan_speed_low1;
LABEL_8:
        if ( fan_speed_low1 )
          goto LABEL_10;
        goto LABEL_9;
      }
      if ( !dev.fan_exist[v1] )
      {
        fan_exist_map = dev.fan_exist_map;
        v7 = dev.fan_num;
        dev.fan_exist[v1] = 1;
        dev.fan_exist_map = fan_exist_map | (1 << v1);
        dev.fan_num = v7 + 1;
      }
      fan_speed_low1 = dev.fan_speed_low1;
      if ( v2 > dev.fan_speed_top1 )
        dev.fan_speed_top1 = 120 * (unsigned __int8)v9;
      v8 = 1;
      if ( v2 )
        v8 = v2 >= dev.fan_speed_low1;
      if ( v8 )
        goto LABEL_8;
LABEL_9:
      dev.fan_speed_low1 = 120 * (unsigned __int8)v9;
LABEL_10:
      cgsleep_ms(50);
      --v0;
    }
    while ( v0 );
    if ( dev.fan_num <= 1u )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        snprintf(tmp42, 0x1000u, "No %d Fan find, check again", 2);
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
