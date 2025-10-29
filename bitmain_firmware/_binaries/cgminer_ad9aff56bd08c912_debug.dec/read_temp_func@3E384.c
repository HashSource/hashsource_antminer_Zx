void __noreturn read_temp_func()
{
  all_parameters *v0; // r11
  char *v1; // r3
  char *v2; // r2
  uint8_t *chain_exist; // r5
  int v4; // r4
  int v5; // t1
  __int16 *v6; // r5
  int v7; // r4
  _BOOL4 v8; // r9
  int v9; // r7
  unsigned int *v10; // r3
  int v11; // r6
  _BOOL4 v12; // r11
  bool *v13; // r8
  bool *v14; // r2
  __int16 *v15; // r9
  int v16; // r12
  int v17; // r12
  int v18; // r2
  int v19; // r3
  int v20; // r1
  uint32_t *v21; // r6
  _BOOL4 v22; // r0
  const char *v23; // r2
  int i; // r7
  unsigned __int8 v25; // r8
  unsigned __int8 v26; // r1
  int *v27; // r3
  int v28; // r0
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int tmpTemp; // [sp+14h] [bp-1028h]
  all_parameters *v33; // [sp+18h] [bp-1024h]
  char *format; // [sp+30h] [bp-100Ch]
  char *v35; // [sp+34h] [bp-1008h]
  char tmp42[4096]; // [sp+38h] [bp-1004h] BYREF

  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    LOWORD(v27) = -23196;
    HIWORD(v27) = (unsigned int)"%s: can't read all sensor's temperature, close PIC and need reboot!!!" >> 16;
    v28 = *v27;
    v29 = v27[1];
    v30 = v27[2];
    v31 = v27[3];
    *(_DWORD *)tmp42 = v28;
    *(_DWORD *)&tmp42[4] = v29;
    *(_DWORD *)&tmp42[8] = v30;
    *(_WORD *)&tmp42[12] = v31;
    tmp42[14] = BYTE2(v31);
    applog(7, tmp42, 0);
  }
  v0 = &dev;
  LOWORD(v1) = -23456;
  LOWORD(v2) = -23392;
  HIWORD(v1) = (unsigned int)"mote:%d" >> 16;
  HIWORD(v2) = (unsigned int)"nsor_ID" >> 16;
  format = v1;
  v35 = v2;
  while ( 1 )
  {
    while ( 1 )
    {
      chain_exist = dev.chain_exist;
      v4 = 0;
      sleep(1u);
      do
      {
        v5 = *chain_exist++;
        if ( v5 == 1 && start_send[v4] )
        {
          for ( i = 0; i != 3; ++i )
          {
            v25 = i;
            v26 = i;
            read_i2c_reg(v4, v26, 0x4Cu, 1u);
            read_i2c_reg(v4, v25, 0x4Cu, 0);
          }
        }
        ++v4;
        cgsleep_ms(200);
      }
      while ( v4 != 4 );
      v6 = (__int16 *)&dev;
      v7 = 0;
      v8 = 0;
      v9 = -256;
      tmpTemp = -256;
      do
      {
        if ( v0->chain_exist[v7] == 1 && start_send[v7] )
        {
          v33 = v0;
          v11 = 0;
          v12 = v8;
          v13 = g_chip_temp_return[v7][0];
          do
          {
            if ( v13[4 * v11] )
            {
              v12 = v13[4 * v11];
            }
            else
            {
              v14 = &v13[4 * v11];
              if ( v14[1] )
                v12 = v14[1];
            }
            v15 = &v6[4 * v11];
            v16 = v15[64];
            if ( v16 > tmpTemp )
            {
              if ( v16 > 80 && !status_error && (use_syslog || opt_log_output || opt_log_level > 2) )
              {
                tmpTemp = v15[64];
                snprintf(tmp42, 0x1000u, format, "read_temp_func", v7, v11, tmpTemp);
                applog(3, tmp42, 0);
              }
              else
              {
                tmpTemp = v15[64];
              }
            }
            v17 = v15[65];
            if ( v17 > v9 )
            {
              if ( v17 > 110 && !status_error && (use_syslog || opt_log_output || opt_log_level > 2) )
              {
                v9 = v15[65];
                snprintf(tmp42, 0x1000u, v35, "read_temp_func", v7, v11, v17);
                applog(3, tmp42, 0);
              }
              else
              {
                v9 = v15[65];
              }
            }
            ++v11;
          }
          while ( v11 != 3 );
          v18 = v6[68];
          v8 = v12;
          v19 = v6[69];
          v0 = v33;
          if ( v18 < v6[64] )
            v18 = v6[64];
          v20 = v6[72];
          if ( v18 < -256 )
            v18 = -256;
          if ( v19 < v6[65] )
            v19 = v6[65];
          v21 = &v33->pwm_value + v7;
          if ( v19 < -256 )
            v19 = -256;
          if ( v20 < v18 )
            v20 = v18;
          v22 = opt_debug;
          if ( v19 < v6[73] )
            v19 = v6[73];
          *(uint32_t *)((char *)v21 + 653) = v20;
          *(uint32_t *)((char *)v21 + 669) = v19;
          if ( v22 && (use_syslog || opt_log_output || opt_log_level > 6) )
          {
            LOWORD(v23) = -23320;
            HIWORD(v23) = (unsigned int)"%s: Chain%d sensor%d remote temp is %d `C, higher than MAX_CHIP_TEMP" >> 16;
            snprintf(tmp42, 0x1000u, v23, v7, v20, v19);
            applog(7, tmp42, 0);
          }
        }
        ++v7;
        v6 += 12;
      }
      while ( v7 != 4 );
      v0->temp_chip_top = v9;
      v0->temp_top1 = tmpTemp;
      if ( !v8 )
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
    v10 = axi_fpga_addr;
    v0->pwm_percent = 100;
    v10[33] = 6553600;
    v10[40] = 6553600;
  }
}
