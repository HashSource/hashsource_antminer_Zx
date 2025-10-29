void *__fastcall __noreturn check_miner_status(void *arg)
{
  unsigned int **v1; // r11
  int v2; // r3
  int32_t temp_top1; // r3
  int v4; // r1
  int v5; // r3
  int v6; // r2
  int v7; // r3
  _BOOL4 v8; // lr
  int fan_num; // r7
  _BOOL4 v10; // r8
  unsigned int v11; // r6
  int v12; // r2
  int v13; // r0
  unsigned int v14; // r6
  int v15; // r3
  int v16; // r1
  unsigned int v17; // r2
  int v18; // r6
  _BOOL4 v19; // r1
  int v20; // r0
  uint32_t fan_exist_map; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r4
  unsigned int *v25; // r4
  uint8_t *v26; // r5
  int v27; // t1
  char *v28; // r4
  uint32_t *v29; // r6
  uint32_t v30; // r3
  uint32_t *v31; // r5
  uint32_t v32; // r0
  uint32_t v33; // r1
  uint32_t v34; // r2
  uint32_t *v35; // r6
  uint32_t *v36; // r4
  uint32_t v37; // r3
  uint32_t *v38; // r5
  uint32_t v39; // r0
  uint32_t v40; // r1
  uint32_t v41; // r2
  int v42; // r5
  uint8_t *chain_exist; // r7
  unsigned int v44; // r8
  unsigned int v46; // r9
  uint8_t *v47; // r11
  unsigned int v49; // r5
  unsigned int v50; // r7
  unsigned int v51; // r5
  uint32_t *v52; // r8
  char *v53; // r3
  unsigned int v54; // r4
  unsigned int v55; // r2
  _BOOL4 v56; // r1
  int v57; // r3
  char *v58; // r3
  unsigned int v59; // lr
  unsigned int v60; // r4
  uint32_t v61; // r12
  unsigned int asic_num; // [sp+2Ch] [bp-1058h]
  unsigned int asic_numa; // [sp+2Ch] [bp-1058h]
  unsigned int ox_num; // [sp+38h] [bp-104Ch]
  unsigned int **v65; // [sp+44h] [bp-1040h]
  int v66; // [sp+50h] [bp-1034h]
  timeval tv_start; // [sp+58h] [bp-102Ch] BYREF
  timeval tv_end; // [sp+60h] [bp-1024h] BYREF
  timeval tv_send; // [sp+68h] [bp-101Ch] BYREF
  unsigned int each_chain_error_asic[4]; // [sp+70h] [bp-1014h] BYREF
  char tmp42[4100]; // [sp+80h] [bp-1004h] BYREF

  v1 = &axi_fpga_addr;
  tv_start.tv_usec = 0;
  tv_start.tv_sec = 0;
  cgtime(&tv_end);
  cgtime(&tv_send);
  copy_time(&tv_start, &tv_end);
  copy_time(&tv_send_job, &tv_send);
  memset(each_chain_error_asic, 0, sizeof(each_chain_error_asic));
  while ( 1 )
  {
    while ( 1 )
    {
      cgtime(&tv_end);
      cgtime(&tv_send);
      v2 = tv_end.tv_sec - tv_start.tv_sec;
      if ( tv_end.tv_usec - tv_start.tv_usec < 0 )
        --v2;
      if ( v2 <= 11999 )
        break;
      copy_time(&tv_start, &tv_end);
      cgsleep_ms(3000);
    }
    if ( v2 <= 120 )
      goto LABEL_6;
    v28 = (_BYTE *)(&dev + 307);
    v29 = g_scan_freq_info.each_asic_invalid_nonce_each_2min[0];
    memset(each_chain_error_asic, 0, sizeof(each_chain_error_asic));
    do
    {
      v30 = *((_DWORD *)v28 + 3);
      v31 = v29;
      v32 = *(_DWORD *)v28;
      v28 += 16;
      v33 = *((_DWORD *)v28 - 3);
      v29 += 4;
      v34 = *((_DWORD *)v28 - 2);
      *v31 = v32;
      v31[1] = v33;
      v31[2] = v34;
      v31[3] = v30;
    }
    while ( v28 != dev.chain_asic_status_string[0] );
    v35 = g_scan_freq_info.each_asic_valid_nonce_each_2min[0];
    v36 = (_DWORD *)(&dev + 259);
    do
    {
      v37 = v36[3];
      v38 = v35;
      v39 = *v36;
      v36 += 4;
      v40 = *(v36 - 3);
      v35 += 4;
      v41 = *(v36 - 2);
      *v38 = v39;
      v38[1] = v40;
      v38[2] = v41;
      v38[3] = v37;
    }
    while ( v36 != dev.chain_asic_invalid_nonce[0] );
    v42 = 0;
    chain_exist = dev.chain_exist;
    v44 = 0;
    asic_num = 0;
    do
    {
      if ( *chain_exist++ )
      {
        v59 = chain_exist[520];
        asic_num += v59;
        if ( chain_exist[520] )
        {
          v60 = 0;
          do
          {
            v61 = dev.chain_asic_nonce[v42][v60];
            v44 += v61;
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              snprintf(tmp42, 0x1000u, "%s: chain %d asic %d asic_nonce_num %d", "check_miner_status", v42, v60, v61);
              applog(7, tmp42, 0);
              v59 = chain_exist[520];
            }
            ++v60;
          }
          while ( v59 > v60 );
        }
      }
      ++v42;
    }
    while ( v42 != 4 );
    if ( asic_num )
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42, 0x1000u, "%s: avg_num %d asic_num %d", "check_miner_status", v44, asic_num);
        applog(7, tmp42, 0);
      }
      ox_num = (v44 / asic_num) >> 3;
    }
    else
    {
      ox_num = 1;
    }
    v65 = v1;
    v46 = 0;
    v47 = dev.chain_exist;
    do
    {
      if ( !*v47++ )
        goto LABEL_120;
      v49 = v47[520];
      if ( !v47[520] )
      {
        v66 = 4 * v46;
        goto LABEL_150;
      }
      v66 = 4 * v46;
      v50 = 0;
      v51 = 0;
      asic_numa = v46;
      v52 = g_scan_freq_info.each_asic_ox_status[v46];
      do
      {
        if ( !v51 )
        {
          if ( v50 > 0x13 && (use_syslog || opt_log_output || opt_log_level > 2) )
          {
            snprintf(tmp42, 0x1000u, aAsicNumErrD, v50);
            applog(3, tmp42, 0);
          }
          v53 = (char *)&dev + asic_numa * 19 + v50++;
          v53[355] = 32;
        }
        v54 = v50 + v51;
        if ( ox_num < dev.chain_asic_nonce[v46][v51] )
        {
          *v52 = 0;
LABEL_151:
          if ( v54 > 0x13 && (use_syslog || opt_log_output || opt_log_level > 2) )
          {
            snprintf(tmp42, 0x1000u, aAsicNumErrD, v50 + v51);
            applog(3, tmp42, 0);
          }
          dev.chain_asic_status_string[asic_numa][v54] = 111;
          goto LABEL_144;
        }
        *v52 = 1;
        if ( *((_BYTE *)v65 + 24) )
          goto LABEL_151;
        if ( v54 > 0x13 && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          snprintf(tmp42, 0x1000u, aAsicNumErrD, v50 + v51);
          applog(3, tmp42, 0);
        }
        v55 = each_chain_error_asic[v46];
        v56 = opt_debug;
        dev.chain_asic_status_string[asic_numa][v54] = 120;
        each_chain_error_asic[v46] = v55 + 1;
        if ( v56 && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(
            tmp42,
            0x1000u,
            "x chain%d asic%d nonce_num=%d avg_num=%d\n",
            v46,
            v51,
            dev.chain_asic_nonce[v46][v51],
            ox_num);
          applog(7, tmp42, 0);
        }
LABEL_144:
        ++v52;
        v57 = 3 * v46 + v51++;
        v58 = (char *)&dev.chain_hw[v57 + 3] + 1;
        v58[3] = 0;
        v58[4] = 0;
        v58[5] = 0;
        v58[6] = 0;
      }
      while ( v47[520] > v51 );
      v49 = v51 + v50;
      if ( v49 > 0x13 && (use_syslog || opt_log_output || opt_log_level > 2) )
      {
        snprintf(tmp42, 0x1000u, aAsicNumErrD, v49);
        applog(3, tmp42, 0);
      }
LABEL_150:
      dev.chain_asic_status_string[0][4 * (v66 + v46) - v46 + v49] = 0;
LABEL_120:
      ++v46;
    }
    while ( v46 != 4 );
    v1 = v65;
    pthread_mutex_lock(&each_chain_err_asic_mutex);
    pthread_cond_signal(&each_chain_err_asic_cond);
    pthread_mutex_unlock(&each_chain_err_asic_mutex);
    memset(dev.chain_asic_invalid_nonce, 0, sizeof(dev.chain_asic_invalid_nonce));
    memset(dev.chain_asic_nonce, 0, sizeof(dev.chain_asic_nonce));
    copy_time(&tv_start, &tv_end);
LABEL_6:
    temp_top1 = dev.temp_top1;
    if ( dev.temp_top1 > 80 || dev.temp_chip_top > 110 )
    {
      v16 = *((unsigned __int8 *)v1 + 44);
      v17 = (unsigned __int8)(*((_BYTE *)v1 + 780) + 1);
      *((_BYTE *)v1 + 780) = v17;
      if ( v17 <= 2 )
      {
        if ( !v16 && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          snprintf(
            tmp42,
            0x1000u,
            "Temperature pcb:%d/chip:%d is higher than %d/%d'C for %d time, PWM is %d",
            temp_top1,
            dev.temp_chip_top,
            80,
            110,
            v17,
            dev.pwm_percent);
          applog(3, tmp42, 0);
        }
      }
      else
      {
        *((_BYTE *)v1 + 781) = 1;
        if ( !v16 && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          snprintf(
            tmp42,
            0x1000u,
            "%s: the temperature pcb:%d/chip:%d is too high, close PIC and need reboot!!!",
            "check_miner_status",
            temp_top1,
            dev.temp_chip_top);
          applog(3, tmp42, 0);
        }
      }
    }
    else
    {
      *((_BYTE *)v1 + 780) = 0;
      *((_BYTE *)v1 + 781) = 0;
    }
    v4 = tv_send.tv_sec - (_DWORD)v1[165];
    if ( tv_send.tv_usec - (int)v1[166] < 0 )
      --v4;
    if ( v4 > 120 )
    {
      v5 = *((unsigned __int8 *)v1 + 44);
      *((_BYTE *)v1 + 782) = 1;
      if ( !v5 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(
          tmp42,
          0x1000u,
          "%s: We have lost internet for %d seconds, so don't send work to hashboard anymore",
          "check_miner_status",
          v4);
        applog(7, tmp42, 0);
      }
    }
    else
    {
      *((_BYTE *)v1 + 782) = 0;
    }
    if ( (dev.fan_exist_map & 1) != 0 )
    {
      v6 = 0;
      v7 = 1;
      if ( (dev.fan_exist_map & 2) == 0 )
      {
LABEL_25:
        v8 = 1;
        goto LABEL_27;
      }
LABEL_171:
      fan_num = dev.fan_num;
      if ( dev.fan_num <= 1u )
      {
        v8 = 1;
        v10 = 1;
        v18 = 1;
        goto LABEL_66;
      }
      v10 = 1;
      goto LABEL_47;
    }
    v6 = 1;
    do
    {
      v7 = v6 + 1;
      if ( ((1 << v6) & dev.fan_exist_map) != 0 )
      {
        if ( v6 != 31 )
        {
          if ( ((1 << v7) & dev.fan_exist_map) == 0 )
            goto LABEL_25;
          goto LABEL_171;
        }
        fan_num = dev.fan_num;
        if ( dev.fan_num <= 1u )
        {
          v8 = 1;
          v7 = -1;
          v18 = 1;
          v10 = 0;
          goto LABEL_66;
        }
        v7 = -1;
        v10 = 0;
LABEL_47:
        v14 = dev.fan_speed_value[v6];
        if ( v14 < 6000 * (unsigned int)dev.fan_pwm / 0x82 )
        {
          v8 = 1;
          v18 = 2;
          goto LABEL_66;
        }
        v8 = dev.pwm_percent == 100;
        if ( v14 >= 0x12C0 )
          v8 = 0;
        if ( v8 )
        {
LABEL_191:
          v18 = 4;
          goto LABEL_66;
        }
        v8 = 1;
LABEL_30:
        if ( v10 )
        {
          v11 = dev.fan_speed_value[v7];
          if ( v11 < 4300 * (unsigned int)dev.fan_pwm / 0x82 )
          {
            v18 = 3;
            goto LABEL_66;
          }
          v10 = dev.pwm_percent == 100;
          if ( v11 >= 0xD70 )
            v10 = 0;
          if ( v10 )
            goto LABEL_191;
        }
        v1[196] = 0;
LABEL_36:
        *((_BYTE *)v1 + 788) = 0;
        goto LABEL_37;
      }
      ++v6;
    }
    while ( v7 != 32 );
    v8 = 0;
    v6 = -1;
    v7 = 0;
    do
    {
LABEL_27:
      if ( ++v7 == 32 )
      {
        fan_num = dev.fan_num;
        v7 = -1;
        v10 = 0;
        if ( dev.fan_num <= 1u )
          goto LABEL_65;
LABEL_29:
        if ( v8 )
          goto LABEL_47;
        goto LABEL_30;
      }
    }
    while ( ((1 << v7) & dev.fan_exist_map) == 0 );
    fan_num = dev.fan_num;
    v10 = 1;
    if ( dev.fan_num > 1u )
      goto LABEL_29;
LABEL_65:
    v18 = 1;
LABEL_66:
    v19 = opt_debug;
    v20 = (int)v1[196] + 1;
    v1[196] = (unsigned int *)v20;
    if ( v19 && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(
        tmp42,
        0x1000u,
        "ret:%d [%d:%d]fan_error_num:%d fan_num %d fan_pwm %d fan1_speed_value %d fan2_speed_value %d",
        v18,
        v8,
        v10,
        v20,
        fan_num,
        dev.fan_pwm,
        dev.fan_speed_value[v6],
        dev.fan_speed_value[v7]);
      applog(7, tmp42, 0);
      v20 = (int)v1[196];
    }
    if ( v20 <= 20 )
      goto LABEL_36;
    fan_exist_map = dev.fan_exist_map;
    v22 = 1;
    *((_BYTE *)v1 + 788) = 1;
    if ( (fan_exist_map & 1) != 0 )
    {
      v23 = 1;
      v24 = fan_exist_map & 2;
      v22 = 0;
      goto LABEL_79;
    }
    while ( 1 )
    {
      v23 = v22 + 1;
      if ( ((1 << v22) & fan_exist_map) != 0 )
        break;
      ++v22;
      if ( v23 == 32 )
      {
        v23 = 0;
        v22 = -1;
        goto LABEL_82;
      }
    }
    if ( v22 == 31 )
    {
LABEL_83:
      v23 = -1;
    }
    else
    {
      v24 = (1 << v23) & fan_exist_map;
LABEL_79:
      if ( !v24 )
      {
LABEL_82:
        while ( ++v23 != 32 )
        {
          if ( ((1 << v23) & fan_exist_map) != 0 )
            goto LABEL_84;
        }
        goto LABEL_83;
      }
    }
LABEL_84:
    switch ( v18 )
    {
      case 3:
        if ( !*((_BYTE *)v1 + 44) && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          snprintf(
            tmp42,
            0x1000u,
            "Fan Err! Disable PIC! Fan2 speed is too low %d pwm %d ",
            dev.fan_speed_value[v23],
            dev.pwm_percent);
LABEL_180:
          applog(3, tmp42, 0);
        }
        break;
      case 4:
        if ( !*((_BYTE *)v1 + 44) && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          snprintf(
            tmp42,
            0x1000u,
            "Fan Err! Disable PIC! Fan1:%d Fan2:%d pwm %d",
            dev.fan_speed_value[v22],
            dev.fan_speed_value[v23],
            dev.pwm_percent);
          applog(3, tmp42, 0);
        }
        break;
      case 2:
        if ( !*((_BYTE *)v1 + 44) && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          snprintf(
            tmp42,
            0x1000u,
            "Fan Err! Disable PIC! Fan1 speed is too low %d pwm %d ",
            dev.fan_speed_value[v22],
            dev.pwm_percent);
          goto LABEL_180;
        }
        break;
      default:
        if ( !*((_BYTE *)v1 + 44) && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          snprintf(tmp42, 0x1000u, "Fan Err! Disable PIC! Fan num is %d", dev.fan_num);
          applog(3, tmp42, 0);
        }
        break;
    }
LABEL_37:
    v12 = *((unsigned __int8 *)v1 + 789);
    if ( *((_BYTE *)v1 + 24) )
    {
      *((_BYTE *)v1 + 782) = 0;
      if ( !v12 )
        goto LABEL_39;
LABEL_54:
      v15 = *((unsigned __int8 *)v1 + 790);
      *((_BYTE *)v1 + 656) = 1;
      if ( !v15 )
      {
        if ( !*((_BYTE *)v1 + 781) && !*((_BYTE *)v1 + 788) )
        {
LABEL_57:
          LOBYTE(v13) = *((_BYTE *)v1 + 656);
          goto LABEL_44;
        }
LABEL_98:
        *((_BYTE *)v1 + 44) = 1;
        v25 = 0;
        *((_BYTE *)v1 + 790) = 1;
        v26 = &dev.chain_exist[1];
        if ( dev.chain_exist[0] == 1 )
          goto LABEL_101;
        while ( 1 )
        {
          do
          {
            v25 = (unsigned int *)((char *)v25 + 1);
            if ( v25 == (unsigned int *)4 )
              goto LABEL_57;
            v27 = *v26++;
          }
          while ( v27 != 1 );
LABEL_101:
          pthread_mutex_lock(&iic_mutex);
          v1[168] = v25;
          disable_PIC16F1704_dc_dc_new();
          cgsleep_ms(100);
          pthread_mutex_unlock(&iic_mutex);
        }
      }
LABEL_43:
      LOBYTE(v13) = 1;
      goto LABEL_44;
    }
    if ( *((_BYTE *)v1 + 789) || *((_BYTE *)v1 + 782) )
      goto LABEL_54;
LABEL_39:
    v13 = *((unsigned __int8 *)v1 + 790);
    if ( *((_BYTE *)v1 + 781) || *((_BYTE *)v1 + 788) )
    {
      *((_BYTE *)v1 + 656) = 1;
      if ( !v13 )
        goto LABEL_98;
      goto LABEL_43;
    }
    if ( *((_BYTE *)v1 + 791) )
    {
      *((_BYTE *)v1 + 656) = 1;
      if ( !v13 )
        goto LABEL_57;
      goto LABEL_43;
    }
    *((_BYTE *)v1 + 656) = 0;
    *((_BYTE *)v1 + 44) = 0;
    if ( v13 )
    {
      *((_BYTE *)v1 + 656) = 1;
      *((_BYTE *)v1 + 44) = 1;
    }
LABEL_44:
    set_led(v13);
    cgsleep_ms(1000);
  }
}
