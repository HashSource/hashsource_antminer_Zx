void __noreturn read_temp_func()
{
  all_parameters *v0; // r11
  uint8_t *chain_exist; // r5
  int v2; // r4
  int v3; // t1
  __int16 *v4; // r5
  int v5; // r4
  _BOOL4 v6; // r9
  int v7; // r7
  unsigned int *v8; // r3
  int v9; // r6
  _BOOL4 v10; // r11
  bool *v11; // r8
  bool *v12; // r2
  __int16 *v13; // r9
  int v14; // r12
  int v15; // r12
  int v16; // r2
  int v17; // r3
  int v18; // r1
  uint32_t *v19; // r6
  _BOOL4 v20; // r0
  int i; // r7
  unsigned __int8 v22; // r8
  unsigned __int8 v23; // r1
  int tmpTemp; // [sp+14h] [bp-1028h]
  all_parameters *v25; // [sp+18h] [bp-1024h]
  char tmp42[4100]; // [sp+38h] [bp-1004h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    strcpy(tmp42, "read_temp_func");
    applog(7, tmp42, 0);
  }
  v0 = &dev;
  while ( 1 )
  {
    while ( 1 )
    {
      chain_exist = dev.chain_exist;
      v2 = 0;
      sleep(1u);
      do
      {
        v3 = *chain_exist++;
        if ( v3 == 1 && start_send[v2] )
        {
          for ( i = 0; i != 3; ++i )
          {
            v22 = i;
            v23 = i;
            read_i2c_reg(v2, v23, 0x4Cu, 1u);
            read_i2c_reg(v2, v22, 0x4Cu, 0);
          }
        }
        ++v2;
        cgsleep_ms(200);
      }
      while ( v2 != 4 );
      v4 = (__int16 *)&dev;
      v5 = 0;
      v6 = 0;
      v7 = -256;
      tmpTemp = -256;
      do
      {
        if ( v0->chain_exist[v5] == 1 && start_send[v5] )
        {
          v25 = v0;
          v9 = 0;
          v10 = v6;
          v11 = g_chip_temp_return[v5][0];
          do
          {
            if ( v11[4 * v9] )
            {
              v10 = v11[4 * v9];
            }
            else
            {
              v12 = &v11[4 * v9];
              if ( v12[1] )
                v10 = v12[1];
            }
            v13 = &v4[4 * v9];
            v14 = v13[64];
            if ( v14 > tmpTemp )
            {
              if ( v14 > 80 && !status_error && (use_syslog || opt_log_output || opt_log_level > 2) )
              {
                tmpTemp = v13[64];
                snprintf(
                  tmp42,
                  0x1000u,
                  "%s: Chain%d sensor%d local temp is %d `C, higher than MAX_TEMP",
                  "read_temp_func",
                  v5,
                  v9,
                  tmpTemp);
                applog(3, tmp42, 0);
              }
              else
              {
                tmpTemp = v13[64];
              }
            }
            v15 = v13[65];
            if ( v15 > v7 )
            {
              if ( v15 > 110 && !status_error && (use_syslog || opt_log_output || opt_log_level > 2) )
              {
                v7 = v13[65];
                snprintf(
                  tmp42,
                  0x1000u,
                  "%s: Chain%d sensor%d remote temp is %d `C, higher than MAX_CHIP_TEMP",
                  "read_temp_func",
                  v5,
                  v9,
                  v15);
                applog(3, tmp42, 0);
              }
              else
              {
                v7 = v13[65];
              }
            }
            ++v9;
          }
          while ( v9 != 3 );
          v16 = v4[68];
          v6 = v10;
          v17 = v4[69];
          v0 = v25;
          if ( v16 < v4[64] )
            v16 = v4[64];
          v18 = v4[72];
          if ( v16 < -256 )
            v16 = -256;
          if ( v17 < v4[65] )
            v17 = v4[65];
          v19 = &v25->pwm_value + v5;
          if ( v17 < -256 )
            v17 = -256;
          if ( v18 < v16 )
            v18 = v16;
          v20 = opt_debug;
          if ( v17 < v4[73] )
            v17 = v4[73];
          *(uint32_t *)((char *)v19 + 653) = v18;
          *(uint32_t *)((char *)v19 + 669) = v17;
          if ( v20 && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            snprintf(tmp42, 0x1000u, "chain%d, max local temp :%d, max remote temp: %d", v5, v18, v17);
            applog(7, tmp42, 0);
          }
        }
        ++v5;
        v4 += 12;
      }
      while ( v5 != 4 );
      v0->temp_chip_top = v7;
      v0->temp_top1 = tmpTemp;
      if ( !v6 )
        break;
      gMinerStatus_Not_read_all_sensor = 0;
      if ( stop )
        goto LABEL_17;
LABEL_63:
      set_PWM_according_to_temperature();
    }
    gMinerStatus_Not_read_all_sensor = 1;
    if ( !status_error && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(
        tmp42,
        0x1000u,
        "%s: can't read all sensor's temperature, close PIC and need reboot!!!",
        "read_temp_func");
      applog(7, tmp42, 0);
    }
    if ( !stop )
      goto LABEL_63;
LABEL_17:
    v8 = axi_fpga_addr;
    v0->pwm_percent = 100;
    v8[33] = 6553600;
    v8[40] = 6553600;
  }
}
