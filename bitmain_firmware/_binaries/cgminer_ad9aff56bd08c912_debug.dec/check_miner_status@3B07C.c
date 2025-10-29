void *__fastcall __noreturn check_miner_status(void *arg)
{
  unsigned int **v1; // r11
  char *v2; // r3
  int v3; // r3
  int32_t temp_top1; // r3
  int v5; // r1
  int v6; // r3
  const char *v7; // r2
  int v8; // r2
  int v9; // r3
  _BOOL4 v10; // lr
  int fan_num; // r7
  _BOOL4 v12; // r8
  unsigned int v13; // r6
  int v14; // r2
  int v15; // r0
  unsigned int v16; // r6
  int v17; // r3
  int v18; // r1
  unsigned int v19; // r2
  const char *v20; // r2
  int v21; // r6
  _BOOL4 v22; // r1
  int v23; // r0
  uint32_t v24; // r1
  const char *v25; // r2
  uint32_t fan_exist_map; // r0
  int v27; // r1
  int v28; // r2
  int v29; // r4
  const char *v30; // r2
  const char *v31; // r2
  unsigned int *v32; // r4
  uint8_t *v33; // r5
  int v34; // t1
  char *v35; // r4
  uint32_t *v36; // r6
  uint32_t v37; // r3
  uint32_t *v38; // r5
  uint32_t v39; // r0
  uint32_t v40; // r1
  uint32_t v41; // r2
  uint32_t *v42; // r6
  uint32_t *v43; // r4
  uint32_t v44; // r3
  uint32_t *v45; // r5
  uint32_t v46; // r0
  uint32_t v47; // r1
  uint32_t v48; // r2
  int v49; // r5
  uint8_t *chain_exist; // r7
  unsigned int v51; // r8
  unsigned int v53; // r9
  uint8_t *v54; // r11
  char *v55; // r3
  char *v56; // r2
  unsigned int v58; // r5
  unsigned int v59; // r7
  unsigned int v60; // r5
  uint32_t *v61; // r8
  char *v62; // r3
  unsigned int v63; // r4
  unsigned int v64; // r2
  _BOOL4 v65; // r1
  int v66; // r3
  char *v67; // r3
  unsigned int v68; // lr
  unsigned int v69; // r4
  uint32_t v70; // r12
  int v71; // r3
  const char *v72; // r2
  const char *v73; // r2
  int v74; // r3
  char *v75; // r1
  const char *v76; // r2
  unsigned int v77; // [sp+Ch] [bp-1078h]
  unsigned int asic_num; // [sp+2Ch] [bp-1058h]
  unsigned int asic_numa; // [sp+2Ch] [bp-1058h]
  unsigned int ox_num; // [sp+38h] [bp-104Ch]
  char *v81; // [sp+3Ch] [bp-1048h]
  char *format; // [sp+40h] [bp-1044h]
  unsigned int **v83; // [sp+44h] [bp-1040h]
  int v84; // [sp+50h] [bp-1034h]
  char *v85; // [sp+54h] [bp-1030h]
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
  LOWORD(v2) = -25928;
  HIWORD(v2) = (unsigned int)"d for chain %d ok" >> 16;
  v81 = v2;
  copy_time(&tv_start, &tv_end);
  copy_time(&tv_send_job, &tv_send);
  memset(each_chain_error_asic, 0, sizeof(each_chain_error_asic));
  while ( 1 )
  {
    while ( 1 )
    {
      cgtime(&tv_end);
      cgtime(&tv_send);
      v3 = tv_end.tv_sec - tv_start.tv_sec;
      if ( tv_end.tv_usec - tv_start.tv_usec < 0 )
        --v3;
      if ( v3 <= 11999 )
        break;
      copy_time(&tv_start, &tv_end);
      cgsleep_ms(3000);
    }
    if ( v3 <= 120 )
      goto LABEL_6;
    v35 = (_BYTE *)(&dev + 307);
    v36 = g_scan_freq_info.each_asic_invalid_nonce_each_2min[0];
    memset(each_chain_error_asic, 0, sizeof(each_chain_error_asic));
    do
    {
      v37 = *((_DWORD *)v35 + 3);
      v38 = v36;
      v39 = *(_DWORD *)v35;
      v35 += 16;
      v40 = *((_DWORD *)v35 - 3);
      v36 += 4;
      v41 = *((_DWORD *)v35 - 2);
      *v38 = v39;
      v38[1] = v40;
      v38[2] = v41;
      v38[3] = v37;
    }
    while ( v35 != dev.chain_asic_status_string[0] );
    v42 = g_scan_freq_info.each_asic_valid_nonce_each_2min[0];
    v43 = (_DWORD *)(&dev + 259);
    do
    {
      v44 = v43[3];
      v45 = v42;
      v46 = *v43;
      v43 += 4;
      v47 = *(v43 - 3);
      v42 += 4;
      v48 = *(v43 - 2);
      *v45 = v46;
      v45[1] = v47;
      v45[2] = v48;
      v45[3] = v44;
    }
    while ( v43 != dev.chain_asic_invalid_nonce[0] );
    v49 = 0;
    chain_exist = dev.chain_exist;
    v51 = 0;
    asic_num = 0;
    do
    {
      if ( *chain_exist++ )
      {
        v68 = chain_exist[520];
        asic_num += v68;
        if ( chain_exist[520] )
        {
          v69 = 0;
          do
          {
            v70 = dev.chain_asic_nonce[v49][v69];
            v51 += v70;
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              snprintf(tmp42, 0x1000u, v81, "check_miner_status", v49, v69, v70);
              applog(7, tmp42, 0);
              v68 = chain_exist[520];
            }
            ++v69;
          }
          while ( v68 > v69 );
        }
      }
      ++v49;
    }
    while ( v49 != 4 );
    if ( asic_num )
    {
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        snprintf(tmp42, 0x1000u, "%s: avg_num %d asic_num %d", "check_miner_status", v51, asic_num);
        applog(7, tmp42, 0);
      }
      ox_num = (v51 / asic_num) >> 3;
    }
    else
    {
      ox_num = 1;
    }
    v83 = v1;
    v53 = 0;
    v54 = dev.chain_exist;
    LOWORD(v55) = -25860;
    LOWORD(v56) = -25840;
    HIWORD(v55) = (unsigned int)"!" >> 16;
    HIWORD(v56) = (unsigned int)" %d > /sys/class/gpio/gpio%d/value" >> 16;
    format = v55;
    v85 = v56;
    do
    {
      if ( !*v54++ )
        goto LABEL_120;
      v58 = v54[520];
      if ( !v54[520] )
      {
        v84 = 4 * v53;
        goto LABEL_150;
      }
      v84 = 4 * v53;
      v59 = 0;
      v60 = 0;
      asic_numa = v53;
      v61 = g_scan_freq_info.each_asic_ox_status[v53];
      do
      {
        if ( !v60 )
        {
          if ( v59 > 0x13 && (use_syslog || opt_log_output || opt_log_level > 2) )
          {
            snprintf(tmp42, 0x1000u, format, v59);
            applog(3, tmp42, 0);
          }
          v62 = (char *)&dev + asic_numa * 19 + v59++;
          v62[355] = 32;
        }
        v63 = v59 + v60;
        if ( ox_num < dev.chain_asic_nonce[v53][v60] )
        {
          *v61 = 0;
LABEL_151:
          if ( v63 > 0x13 && (use_syslog || opt_log_output || opt_log_level > 2) )
          {
            snprintf(tmp42, 0x1000u, format, v59 + v60);
            applog(3, tmp42, 0);
          }
          dev.chain_asic_status_string[asic_numa][v63] = 111;
          goto LABEL_144;
        }
        *v61 = 1;
        if ( *((_BYTE *)v83 + 24) )
          goto LABEL_151;
        if ( v63 > 0x13 && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          snprintf(tmp42, 0x1000u, format, v59 + v60);
          applog(3, tmp42, 0);
        }
        v64 = each_chain_error_asic[v53];
        v65 = opt_debug;
        dev.chain_asic_status_string[asic_numa][v63] = 120;
        each_chain_error_asic[v53] = v64 + 1;
        if ( v65 && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(tmp42, 0x1000u, v85, v53, v60, dev.chain_asic_nonce[v53][v60], ox_num);
          applog(7, tmp42, 0);
        }
LABEL_144:
        ++v61;
        v66 = 3 * v53 + v60++;
        v67 = (char *)&dev.chain_hw[v66 + 3] + 1;
        v67[3] = 0;
        v67[4] = 0;
        v67[5] = 0;
        v67[6] = 0;
      }
      while ( v54[520] > v60 );
      v58 = v60 + v59;
      if ( v58 > 0x13 && (use_syslog || opt_log_output || opt_log_level > 2) )
      {
        snprintf(tmp42, 0x1000u, format, v58);
        applog(3, tmp42, 0);
      }
LABEL_150:
      dev.chain_asic_status_string[0][4 * (v84 + v53) - v53 + v58] = 0;
LABEL_120:
      ++v53;
    }
    while ( v53 != 4 );
    v1 = v83;
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
      v18 = *((unsigned __int8 *)v1 + 44);
      v19 = (unsigned __int8)(*((_BYTE *)v1 + 780) + 1);
      *((_BYTE *)v1 + 780) = v19;
      if ( v19 <= 2 )
      {
        if ( !v18 && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          v77 = v19;
          LOWORD(v31) = -25716;
          HIWORD(v31) = (unsigned int)"x chain%d asic%d nonce_num=%d avg_num=%d\n" >> 16;
          snprintf(tmp42, 0x1000u, v31, temp_top1, dev.temp_chip_top, 80, 110, v77, dev.pwm_percent);
          applog(3, tmp42, 0);
        }
      }
      else
      {
        *((_BYTE *)v1 + 781) = 1;
        if ( !v18 && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          LOWORD(v20) = -25796;
          HIWORD(v20) = (unsigned int)"n %d asic %d asic_nonce_num %d" >> 16;
          snprintf(tmp42, 0x1000u, v20, "check_miner_status", temp_top1, dev.temp_chip_top);
          applog(3, tmp42, 0);
        }
      }
    }
    else
    {
      *((_BYTE *)v1 + 780) = 0;
      *((_BYTE *)v1 + 781) = 0;
    }
    v5 = tv_send.tv_sec - (_DWORD)v1[165];
    if ( tv_send.tv_usec - (int)v1[166] < 0 )
      --v5;
    if ( v5 > 120 )
    {
      v6 = *((unsigned __int8 *)v1 + 44);
      *((_BYTE *)v1 + 782) = 1;
      if ( !v6 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        LOWORD(v7) = -25640;
        HIWORD(v7) = (unsigned int)"%d is too high, close PIC and need reboot!!!" >> 16;
        snprintf(tmp42, 0x1000u, v7, "check_miner_status", v5);
        applog(7, tmp42, 0);
      }
    }
    else
    {
      *((_BYTE *)v1 + 782) = 0;
    }
    if ( (dev.fan_exist_map & 1) != 0 )
    {
      v8 = 0;
      v9 = 1;
      if ( (dev.fan_exist_map & 2) == 0 )
      {
LABEL_25:
        v10 = 1;
        goto LABEL_27;
      }
LABEL_171:
      fan_num = dev.fan_num;
      if ( dev.fan_num <= 1u )
      {
        v10 = 1;
        v12 = 1;
        v21 = 1;
        goto LABEL_66;
      }
      v12 = 1;
      goto LABEL_47;
    }
    v8 = 1;
    do
    {
      v9 = v8 + 1;
      if ( ((1 << v8) & dev.fan_exist_map) != 0 )
      {
        if ( v8 != 31 )
        {
          if ( ((1 << v9) & dev.fan_exist_map) == 0 )
            goto LABEL_25;
          goto LABEL_171;
        }
        fan_num = dev.fan_num;
        if ( dev.fan_num <= 1u )
        {
          v10 = 1;
          v9 = -1;
          v21 = 1;
          v12 = 0;
          goto LABEL_66;
        }
        v9 = -1;
        v12 = 0;
LABEL_47:
        v16 = dev.fan_speed_value[v8];
        if ( v16 < 6000 * (unsigned int)dev.fan_pwm / 0x82 )
        {
          v10 = 1;
          v21 = 2;
          goto LABEL_66;
        }
        v10 = dev.pwm_percent == 100;
        if ( v16 >= 0x12C0 )
          v10 = 0;
        if ( v10 )
        {
LABEL_191:
          v21 = 4;
          goto LABEL_66;
        }
        v10 = 1;
LABEL_30:
        if ( v12 )
        {
          v13 = dev.fan_speed_value[v9];
          if ( v13 < 4300 * (unsigned int)dev.fan_pwm / 0x82 )
          {
            v21 = 3;
            goto LABEL_66;
          }
          v12 = dev.pwm_percent == 100;
          if ( v13 >= 0xD70 )
            v12 = 0;
          if ( v12 )
            goto LABEL_191;
        }
        v1[196] = 0;
LABEL_36:
        *((_BYTE *)v1 + 788) = 0;
        goto LABEL_37;
      }
      ++v8;
    }
    while ( v9 != 32 );
    v10 = 0;
    v8 = -1;
    v9 = 0;
    do
    {
LABEL_27:
      if ( ++v9 == 32 )
      {
        fan_num = dev.fan_num;
        v9 = -1;
        v12 = 0;
        if ( dev.fan_num <= 1u )
          goto LABEL_65;
LABEL_29:
        if ( v10 )
          goto LABEL_47;
        goto LABEL_30;
      }
    }
    while ( ((1 << v9) & dev.fan_exist_map) == 0 );
    fan_num = dev.fan_num;
    v12 = 1;
    if ( dev.fan_num > 1u )
      goto LABEL_29;
LABEL_65:
    v21 = 1;
LABEL_66:
    v22 = opt_debug;
    v23 = (int)v1[196] + 1;
    v1[196] = (unsigned int *)v23;
    if ( v22 && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      v24 = dev.fan_speed_value[v8];
      LOWORD(v25) = -25556;
      HIWORD(v25) = (unsigned int)" than %d/%d'C for %d time, PWM is %d" >> 16;
      snprintf(tmp42, 0x1000u, v25, v21, v10, v12, v23, fan_num, dev.fan_pwm, v24, dev.fan_speed_value[v9]);
      applog(7, tmp42, 0);
      v23 = (int)v1[196];
    }
    if ( v23 <= 20 )
      goto LABEL_36;
    fan_exist_map = dev.fan_exist_map;
    v27 = 1;
    *((_BYTE *)v1 + 788) = 1;
    if ( (fan_exist_map & 1) != 0 )
    {
      v28 = 1;
      v29 = fan_exist_map & 2;
      v27 = 0;
      goto LABEL_79;
    }
    while ( 1 )
    {
      v28 = v27 + 1;
      if ( ((1 << v27) & fan_exist_map) != 0 )
        break;
      ++v27;
      if ( v28 == 32 )
      {
        v28 = 0;
        v27 = -1;
        goto LABEL_82;
      }
    }
    if ( v27 == 31 )
    {
LABEL_83:
      v28 = -1;
    }
    else
    {
      v29 = (1 << v28) & fan_exist_map;
LABEL_79:
      if ( !v29 )
      {
LABEL_82:
        while ( ++v28 != 32 )
        {
          if ( ((1 << v28) & fan_exist_map) != 0 )
            goto LABEL_84;
        }
        goto LABEL_83;
      }
    }
LABEL_84:
    switch ( v21 )
    {
      case 3:
        if ( !*((_BYTE *)v1 + 44) && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          v71 = v28 + 122;
          LOWORD(v72) = -25368;
          HIWORD(v72) = (unsigned int)"value %d fan2_speed_value %d" >> 16;
          snprintf(tmp42, 0x1000u, v72, *(uint32_t *)((char *)&dev.pwm_value + 4 * v71 + 1), dev.pwm_percent);
LABEL_180:
          applog(3, tmp42, 0);
        }
        break;
      case 4:
        if ( !*((_BYTE *)v1 + 44) && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          v74 = v27 + 122;
          v75 = (char *)&dev.fan_event_count[v28 + 5] + 3;
          LOWORD(v76) = -25312;
          HIWORD(v76) = (unsigned int)"n num is %d" >> 16;
          snprintf(
            tmp42,
            0x1000u,
            v76,
            *(uint32_t *)((char *)&dev.pwm_value + 4 * v74 + 1),
            *(_DWORD *)(v75 + 1),
            dev.pwm_percent);
          applog(3, tmp42, 0);
        }
        break;
      case 2:
        if ( !*((_BYTE *)v1 + 44) && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          LOWORD(v73) = -25424;
          HIWORD(v73) = (unsigned int)"%d:%d]fan_error_num:%d fan_num %d fan_pwm %d fan1_speed_value %d fan2_speed_value %d" >> 16;
          snprintf(tmp42, 0x1000u, v73, dev.fan_speed_value[v27], dev.pwm_percent);
          goto LABEL_180;
        }
        break;
      default:
        if ( !*((_BYTE *)v1 + 44) && (use_syslog || opt_log_output || opt_log_level > 2) )
        {
          LOWORD(v30) = -25460;
          HIWORD(v30) = (unsigned int)"work to hashboard anymore" >> 16;
          snprintf(tmp42, 0x1000u, v30, dev.fan_num);
          applog(3, tmp42, 0);
        }
        break;
    }
LABEL_37:
    v14 = *((unsigned __int8 *)v1 + 789);
    if ( *((_BYTE *)v1 + 24) )
    {
      *((_BYTE *)v1 + 782) = 0;
      if ( !v14 )
        goto LABEL_39;
LABEL_54:
      v17 = *((unsigned __int8 *)v1 + 790);
      *((_BYTE *)v1 + 656) = 1;
      if ( !v17 )
      {
        if ( !*((_BYTE *)v1 + 781) && !*((_BYTE *)v1 + 788) )
        {
LABEL_57:
          LOBYTE(v15) = *((_BYTE *)v1 + 656);
          goto LABEL_44;
        }
LABEL_98:
        *((_BYTE *)v1 + 44) = 1;
        v32 = 0;
        *((_BYTE *)v1 + 790) = 1;
        v33 = &dev.chain_exist[1];
        if ( dev.chain_exist[0] == 1 )
          goto LABEL_101;
        while ( 1 )
        {
          do
          {
            v32 = (unsigned int *)((char *)v32 + 1);
            if ( v32 == (unsigned int *)4 )
              goto LABEL_57;
            v34 = *v33++;
          }
          while ( v34 != 1 );
LABEL_101:
          pthread_mutex_lock(&iic_mutex);
          v1[168] = v32;
          disable_PIC16F1704_dc_dc_new();
          cgsleep_ms(100);
          pthread_mutex_unlock(&iic_mutex);
        }
      }
LABEL_43:
      LOBYTE(v15) = 1;
      goto LABEL_44;
    }
    if ( *((_BYTE *)v1 + 789) || *((_BYTE *)v1 + 782) )
      goto LABEL_54;
LABEL_39:
    v15 = *((unsigned __int8 *)v1 + 790);
    if ( *((_BYTE *)v1 + 781) || *((_BYTE *)v1 + 788) )
    {
      *((_BYTE *)v1 + 656) = 1;
      if ( !v15 )
        goto LABEL_98;
      goto LABEL_43;
    }
    if ( *((_BYTE *)v1 + 791) )
    {
      *((_BYTE *)v1 + 656) = 1;
      if ( !v15 )
        goto LABEL_57;
      goto LABEL_43;
    }
    *((_BYTE *)v1 + 656) = 0;
    *((_BYTE *)v1 + 44) = 0;
    if ( v15 )
    {
      *((_BYTE *)v1 + 656) = 1;
      *((_BYTE *)v1 + 44) = 1;
    }
LABEL_44:
    set_led(v15);
    cgsleep_ms(1000);
  }
}
