void *__fastcall __noreturn check_fan_thr(void *arg)
{
  int v1; // r6
  int v2; // r10
  int v3; // r3
  uint32_t v4; // r1
  char *v5; // r3
  uint8_t fan_num; // r0
  uint32_t fan_speed_low1; // r3
  uint32_t fan_exist_map; // r2
  uint8_t v9; // r12
  bool v10; // cf
  unsigned int v11; // [sp+4h] [bp-4h]

  while ( 1 )
  {
    v1 = 2;
    dev.fan_speed_top1 = 0;
    dev.fan_speed_low1 = 0;
    while ( 1 )
    {
      v2 = 6;
      do
      {
        v11 = axi_fpga_addr[1];
        if ( v11 == -1 )
          goto LABEL_10;
        v3 = (v11 >> 8) & 7;
        v4 = 120 * (unsigned __int8)v11;
        dev.fan_speed_value[v3] = v4;
        if ( !(_BYTE)v11 )
        {
          v5 = (char *)&dev + v3;
          if ( v5[459] == 1 )
          {
            fan_num = dev.fan_num;
            v5[459] = 0;
            dev.fan_exist_map = 0;
            dev.fan_num = fan_num - 1;
          }
          fan_speed_low1 = dev.fan_speed_low1;
LABEL_8:
          if ( fan_speed_low1 )
            goto LABEL_10;
          goto LABEL_9;
        }
        if ( !dev.fan_exist[v3] )
        {
          fan_exist_map = dev.fan_exist_map;
          v9 = dev.fan_num;
          dev.fan_exist[v3] = 1;
          dev.fan_exist_map = fan_exist_map | (1 << v3);
          dev.fan_num = v9 + 1;
        }
        fan_speed_low1 = dev.fan_speed_low1;
        if ( v4 > dev.fan_speed_top1 )
          dev.fan_speed_top1 = 120 * (unsigned __int8)v11;
        v10 = 1;
        if ( v4 )
          v10 = v4 >= dev.fan_speed_low1;
        if ( v10 )
          goto LABEL_8;
LABEL_9:
        dev.fan_speed_low1 = 120 * (unsigned __int8)v11;
LABEL_10:
        cgsleep_ms(50);
        --v2;
      }
      while ( v2 );
      if ( v1 == 1 )
        break;
      v1 = 1;
    }
    sleep(1u);
  }
}
