int __fastcall bitmain_ZCASH_init(bitmain_ZCASH_info *info)
{
  pool **v2; // r3
  int v3; // r12
  pool **v4; // r0
  int v5; // r1
  int v6; // t1
  _BYTE *v7; // r2
  _BYTE *v8; // r2
  int v9; // r3
  int v10; // r3
  uint8_t v11; // r1
  unsigned int *v12; // r2
  int hash_rate_pthread; // r8
  init_config *p_config_parameter; // r0
  unsigned int v16; // r3
  int i; // r2
  int version; // t1
  int v19; // r2
  int v20; // r3
  char *v21; // r3
  int v22; // r8
  uint8_t *chain_exist; // r9
  int v24; // t1
  uint8_t *v25; // r10
  int v26; // r8
  uint32_t v27; // r9
  int v28; // t1
  _BOOL4 v29; // r2
  unsigned int fan_pwm_percent; // r6
  _BOOL4 v31; // r3
  int v32; // r3
  unsigned int *v33; // r2
  bool v34; // zf
  int v35; // r10
  int v36; // r3
  _BOOL4 v37; // r2
  char v38; // [sp+20h] [bp-104Ch]
  init_config config; // [sp+28h] [bp-1044h]
  init_config config_parameter; // [sp+48h] [bp-1024h] BYREF
  unsigned __int8 tmp42[455][9]; // [sp+68h] [bp-1004h] BYREF

  config = info->ZCASH_config;
  start_http_thread();
  while ( 1 )
  {
    if ( total_pools > 0 )
    {
      v2 = pools;
      v3 = 0;
      v4 = &pools[total_pools];
      do
      {
        while ( 1 )
        {
          v6 = (int)*v2++;
          v5 = v6;
          v7 = *(_BYTE **)(v6 + 196);
          if ( !v7 )
            break;
          if ( !*v7 )
            break;
          v8 = *(_BYTE **)(v5 + 204);
          if ( !v8 || !*v8 )
            break;
          ++v3;
          if ( v4 == v2 )
            goto LABEL_9;
        }
      }
      while ( v4 != v2 );
      if ( v3 )
        break;
    }
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      strcpy((char *)tmp42, "No valid pools, please configure them first!!!");
      applog(4, (const char *)tmp42, 0);
    }
    sleep(5u);
  }
LABEL_9:
  bitmain_axi_init();
  init_fpga();
  set_fpga_baud(0x1Au);
  config_parameter = config;
  dev.addrInterval = 1;
  strcpy(g_miner_version, "9.0.0.5");
  system("echo 1 > /sys/class/gpio/gpio954/value");
  system("echo 1 > /sys/class/gpio/gpio955/value");
  v9 = (unsigned __int8)opt_bitmain_fan_pwm;
  if ( (unsigned __int8)opt_bitmain_fan_pwm <= 0x27u )
  {
    v9 = 40;
  }
  else if ( (unsigned __int8)opt_bitmain_fan_pwm > 0x64u )
  {
    v10 = 6553600;
    v11 = 100;
    goto LABEL_15;
  }
  if ( gMinerStatus_Not_read_all_sensor )
  {
    v10 = 6553600;
    v11 = 100;
  }
  else
  {
    v11 = v9;
    v10 = (100 - v9) | (v9 << 16);
  }
LABEL_15:
  v12 = axi_fpga_addr;
  dev.pwm_percent = v11;
  axi_fpga_addr[33] = v10;
  v12[40] = v10;
  check_fan_speed();
  if ( config_parameter.token_type != 81 )
  {
    if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
      return -1;
    snprintf(
      (char *)tmp42,
      0x1000u,
      "%s: config_parameter.token_type != 0x%x, it is 0x%x",
      "bitmain_ZCASH_init",
      81,
      config_parameter.token_type);
    hash_rate_pthread = -1;
    applog(3, (const char *)tmp42, 0);
    return hash_rate_pthread;
  }
  p_config_parameter = &config_parameter;
  v16 = 255;
  for ( i = 81; ; i = version )
  {
    v16 = (unsigned __int16)(*(_WORD *)&_FUNCTION___15596[2 * (i ^ (v16 >> 8)) + 100] ^ ((_WORD)v16 << 8));
    if ( p_config_parameter == (init_config *)&config_parameter.reg_address )
      break;
    version = p_config_parameter->version;
    p_config_parameter = (init_config *)((char *)p_config_parameter + 1);
  }
  if ( config_parameter.crc == v16 )
  {
    v19 = 0;
    do
    {
      v20 = v19 + 28;
      ++v19;
      v21 = &info->update_lock.mutex.__size[4 * v20];
      *((_WORD *)v21 + 3) = 0;
      *((_WORD *)v21 + 4) = 0;
    }
    while ( v19 != 128 );
    check_chain();
    if ( certification_firmware )
    {
      config_parameter.fan_pwm_percent = 50;
      *((_BYTE *)&config_parameter + 8) |= 2u;
      rt_chain_num = dev.chain_num;
    }
    every_chain_reset_PIC16F1704_pic_new();
    every_chain_jump_from_loader_to_app_PIC16F1704_new();
    sleep(1u);
    hash_rate_pthread = send_heart_beat_to_every_chain();
    if ( hash_rate_pthread == -3 )
      return hash_rate_pthread;
    if ( !access("/tmp/delete_freq", 0) )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        strcpy((char *)tmp42, "delete freq data and scan freq again\n");
        applog(5, (const char *)tmp42, 0);
      }
      memset(tmp42, 0, 0x24u);
      every_chain_write_freq_to_pic(tmp42);
      system("rm /tmp/delete_freq");
      sleep(3u);
      exit(1);
    }
    v38 = *((_BYTE *)&config_parameter + 8);
    if ( (*((_BYTE *)&config_parameter + 8) & 8) == 0 )
      goto LABEL_46;
    v34 = config_parameter.frequency == 0;
    if ( config_parameter.frequency )
      v34 = config_parameter.frequency == 800;
    if ( v34 )
LABEL_46:
      dev.frequency = 800;
    else
      dev.frequency = config_parameter.frequency;
    reset_all_hash_board_low();
    cgsleep_ms(100);
    every_chain_disable_PIC16F1704_dc_dc_new();
    cgsleep_ms(200);
    cgsleep_ms(200);
    every_chain_enable_PIC16F1704_dc_dc_new();
    cgsleep_ms(100);
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf((char *)tmp42, 0x1000u, "%s %d", "reset_all_hash_board_high", 4398);
      applog(5, (const char *)tmp42, 0);
    }
    v22 = 0;
    axi_fpga_addr[13] = 0;
    cgsleep_ms(100);
    tty_init(info);
    sleep(3u);
    set_baud(config_parameter.baud);
    cgsleep_ms(100);
    calculate_address_interval();
    dev.corenum = 1;
    clear_register_value_buf();
    cgsleep_ms(100);
    sleep(2u);
    chain_exist = dev.chain_exist;
    check_every_chain_asic_number(1);
    cgsleep_ms(300);
    do
    {
      v24 = *chain_exist++;
      if ( v24 == 1 )
      {
        v35 = 3;
        need_recheck[v22] = 1;
        while ( 1 )
        {
          v36 = chain_exist[520];
          if ( v36 == 3 )
            break;
          v37 = use_syslog;
          need_recheck[v22] = 1;
          if ( !v37 && !opt_log_output && opt_log_level <= 4
            || (snprintf(
                  (char *)tmp42,
                  0x1000u,
                  "recheck: chainid %d exist %d asicnum %d realnum %d",
                  v22,
                  *(chain_exist - 1),
                  v36,
                  3),
                applog(5, (const char *)tmp42, 0),
                need_recheck[v22]) )
          {
            recheck_asic_num(info, v22);
            if ( --v35 )
              continue;
          }
          goto LABEL_53;
        }
        need_recheck[v22] = 0;
      }
LABEL_53:
      ++v22;
    }
    while ( v22 != 4 );
    v25 = dev.chain_exist;
    LOBYTE(v26) = 0;
    scan_freq_init_freq();
    v27 = default_ticket_mask_reg;
    do
    {
      v28 = *v25++;
      if ( v28 == 1 )
        set_ticket_mask_chain(v26, v27);
      v26 = (unsigned __int8)(v26 + 1);
    }
    while ( v26 != 4 );
    cgsleep_ms(100);
    software_set_address();
    cgsleep_ms(100);
    set_core_timeout(opt_bitmain_core_timeout);
    cgsleep_ms(100);
    set_nonce_shift(0);
    cgsleep_ms(100);
    enable_read_temperature_from_asic_chain(0);
    enable_read_temperature_from_asic_chain(1u);
    enable_read_temperature_from_asic_chain(2u);
    enable_read_temperature_from_asic_chain(3u);
    enable_sensor_extend_mode();
    set_analog_mux_control(0);
    v29 = use_syslog;
    if ( (v38 & 4) != 0 )
    {
      dev.timeout = 100000000;
      if ( !use_syslog && !opt_log_output && opt_log_level <= 4 )
      {
        fan_pwm_percent = config_parameter.fan_pwm_percent;
        dev.fan_eft = (*((_BYTE *)&config_parameter + 8) & 2) != 0;
        v31 = (*((_BYTE *)&config_parameter + 8) & 2) != 0;
        dev.fan_pwm = config_parameter.fan_pwm_percent;
        goto LABEL_63;
      }
      snprintf((char *)tmp42, 0x1000u, "dev.timeout = %d us", 100000000);
      applog(5, (const char *)tmp42, 0);
      v29 = use_syslog;
    }
    fan_pwm_percent = config_parameter.fan_pwm_percent;
    dev.fan_eft = (*((_BYTE *)&config_parameter + 8) & 2) != 0;
    v31 = (*((_BYTE *)&config_parameter + 8) & 2) != 0;
    dev.fan_pwm = config_parameter.fan_pwm_percent;
    if ( v29 )
    {
LABEL_65:
      snprintf((char *)tmp42, 0x1000u, "%s: fan_eft : %d  fan_pwm : %d", "bitmain_ZCASH_init", v31, fan_pwm_percent);
      applog(5, (const char *)tmp42, 0);
LABEL_66:
      if ( (v38 & 2) != 0 && fan_pwm_percent <= 0x64 )
      {
        if ( gMinerStatus_Not_read_all_sensor )
        {
          v32 = 6553600;
          LOBYTE(fan_pwm_percent) = 100;
        }
        else
        {
          if ( fan_pwm_percent < 0x28 )
            fan_pwm_percent = 40;
          v32 = (100 - fan_pwm_percent) | (fan_pwm_percent << 16);
        }
        v33 = axi_fpga_addr;
        dev.pwm_percent = fan_pwm_percent;
        axi_fpga_addr[33] = v32;
        v33[40] = v32;
      }
      else
      {
        set_PWM_according_to_temperature();
      }
      hash_rate_pthread = create_bitmain_check_fan_pthread();
      if ( hash_rate_pthread != -8 )
      {
        sleep(1u);
        create_bitmain_read_temp_pthread();
        if ( hash_rate_pthread != -7 )
        {
          hash_rate_pthread = create_bitmain_check_miner_status_pthread(info);
          if ( hash_rate_pthread != -5 )
          {
            hash_rate_pthread = create_bitmain_get_hash_rate_pthread();
            if ( hash_rate_pthread != -6 )
            {
              init_asic_display_status();
              start_send[0] = 1;
              start_send[1] = 1;
              start_send[2] = 1;
              start_send[3] = 1;
              if ( use_syslog || opt_log_output || opt_log_level > 4 )
              {
                snprintf((char *)tmp42, 0x1000u, "%s done", "bitmain_ZCASH_init");
                hash_rate_pthread = 0;
                applog(5, (const char *)tmp42, 0);
              }
              else
              {
                return opt_log_output;
              }
            }
          }
        }
      }
      return hash_rate_pthread;
    }
LABEL_63:
    if ( !opt_log_output && opt_log_level <= 4 )
      goto LABEL_66;
    goto LABEL_65;
  }
  if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
    return -2;
  snprintf(
    (char *)tmp42,
    0x1000u,
    "%s: config_parameter.crc = 0x%x, but we calculate it as 0x%x",
    "bitmain_ZCASH_init",
    config_parameter.crc,
    v16);
  applog(3, (const char *)tmp42, 0);
  return -2;
}
