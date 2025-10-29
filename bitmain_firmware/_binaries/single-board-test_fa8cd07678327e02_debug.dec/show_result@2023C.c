void show_result()
{
  char tmp42[1024]; // [sp+Ch] [bp+4h] BYREF
  int which_asic; // [sp+40Ch] [bp+404h]
  runtime_base_t *runtime; // [sp+410h] [bp+408h]
  int i; // [sp+414h] [bp+40Ch]

  runtime = cgpu.runtime;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    strcpy(tmp42, "---------------------------------result-----------------------------------------------\n");
    applog(2, tmp42, 0);
  }
  read_temp_test_result = 1;
  for ( i = 0; runtime->sensor_num > i; ++i )
  {
    which_asic = runtime->sensor_pos[i];
    if ( chip_temp[which_asic] < app_conf->pcba_tempture_low || chip_temp[which_asic] > app_conf->pcba_tempture_high )
    {
      if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        snprintf(tmp42, 0x400u, "Sensor %d CHIP temp wrong!\n", runtime->sensor_pos[0] + 1);
        applog(0, tmp42, 0);
      }
      read_temp_test_result = -1;
    }
    if ( pcb_temp[which_asic] < app_conf->pcba_tempture_low || pcb_temp[which_asic] > app_conf->pcba_tempture_high )
    {
      if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        snprintf(tmp42, 0x400u, "Sensor %d PCB temp wrong!\n", runtime->sensor_pos[0] + 1);
        applog(0, tmp42, 0);
      }
      read_temp_test_result = -1;
    }
  }
  if ( read_temp_test_result <= 0 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      strcpy(tmp42, "Sensor NG.\n");
      applog(2, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    strcpy(tmp42, "Sensor OK.\n");
    applog(2, tmp42, 0);
  }
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(
      tmp42,
      0x400u,
      "Expect pass rate: %d, real pattern rate: %.2f\n",
      app_conf->pcba_pattern_pass_rate,
      (float)(g_patten.total_rate * 100.0));
    applog(2, tmp42, 0);
  }
  if ( app_conf->pcba_enable_level != 1 )
  {
    pattern_level = 1;
    if ( (float)(g_patten.total_rate * 100.0) >= (float)app_conf->pcba_pattern_pass_rate )
    {
      pattern_result = 1;
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
        goto LABEL_59;
      goto LABEL_64;
    }
    pattern_result = -1;
    if ( !use_syslog && !opt_log_output && opt_log_level <= 1 )
      goto LABEL_64;
    goto LABEL_63;
  }
  pattern_result = 1;
  if ( (float)(g_patten.total_rate * 100.0) < *app_conf->pcba_level_rate )
  {
    if ( (float)(g_patten.total_rate * 100.0) >= app_conf->pcba_level_rate[1] )
    {
      pattern_level = 2;
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
        goto LABEL_59;
      goto LABEL_64;
    }
    if ( (float)(g_patten.total_rate * 100.0) >= app_conf->pcba_level_rate[2] )
    {
      pattern_level = 3;
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
        goto LABEL_59;
      goto LABEL_64;
    }
    pattern_level = 4;
    pattern_result = -1;
    if ( !use_syslog && !opt_log_output && opt_log_level <= 1 )
      goto LABEL_64;
LABEL_63:
    strcpy(tmp42, "Pattern NG.\n");
    applog(2, tmp42, 0);
    goto LABEL_64;
  }
  pattern_level = 1;
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
LABEL_59:
    strcpy(tmp42, "Pattern OK.\n");
    applog(2, tmp42, 0);
  }
LABEL_64:
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    strcpy(tmp42, "--------------------------------------------------------------------------------------\n");
    applog(2, tmp42, 0);
  }
}
