int __cdecl app_config_handle(app_config_t *m_conf, char *config_filename)
{
  char tmp42[1024]; // [sp+8h] [bp+8h] BYREF
  char str[1024]; // [sp+408h] [bp+408h] BYREF
  int num; // [sp+808h] [bp+808h]
  int num_2; // [sp+80Ch] [bp+80Ch]
  int num_1; // [sp+810h] [bp+810h]
  int num_0; // [sp+814h] [bp+814h]
  FILE *fd; // [sp+818h] [bp+818h]
  char *temp; // [sp+81Ch] [bp+81Ch]

  memset(str, 0, sizeof(str));
  temp = 0;
  fd = fopen(config_filename, "r");
  if ( !fd && (use_syslog || opt_log_output || opt_log_level > 1) )
  {
    snprintf(tmp42, 0x400u, "open %s failed\n", config_filename);
    applog(2, tmp42, 0);
  }
  while ( 1 )
  {
    do
    {
      if ( !fgets(str, 1023, fd) )
      {
        fclose(fd);
        return 0;
      }
    }
    while ( str[0] == 35 || str[1] == 35 || !str[0] );
    temp = strstr(str, "Name=");
    if ( temp )
    {
      temp += 5;
      _isoc99_sscanf(temp, "%s", m_conf->name);
    }
    temp = strstr(str, "AsicNum=");
    if ( temp )
    {
      temp += 8;
      _isoc99_sscanf(temp, "%d", &m_conf->asic_num);
    }
    temp = strstr(str, "CoreNum=");
    if ( temp )
    {
      temp += 8;
      _isoc99_sscanf(temp, "%d", &m_conf->core_num);
      goto LABEL_99;
    }
    temp = strstr(str, "WorkMode=");
    if ( temp )
    {
      temp += 9;
      _isoc99_sscanf(temp, "%d", &m_conf->work_mode);
      goto LABEL_99;
    }
    temp = strstr(str, "Comport=");
    if ( temp )
    {
      temp += 8;
      m_conf->comport_num = parse_config_ini_array(temp, (void **)&m_conf->comport);
      goto LABEL_99;
    }
    temp = strstr(str, "SensorPos=");
    if ( temp )
    {
      temp += 10;
      m_conf->sensor_num = parse_config_ini_array(temp, (void **)&m_conf->sensor_pos);
      goto LABEL_99;
    }
    temp = strstr(str, "EnableCp210x=");
    if ( temp )
    {
      temp += 13;
      _isoc99_sscanf(temp, "%d", &m_conf->enable_cp210x);
      goto LABEL_99;
    }
    temp = strstr(str, "Baudrate=");
    if ( temp )
    {
      temp += 9;
      _isoc99_sscanf(temp, "%d", &m_conf->baudrate);
      goto LABEL_99;
    }
    temp = strstr(str, "TicketMask=");
    if ( temp )
    {
      temp += 11;
      _isoc99_sscanf(temp, "%d", &m_conf->ticket_mask);
      goto LABEL_99;
    }
    temp = strstr(str, "CoreTimeout=");
    if ( temp )
    {
      temp += 12;
      _isoc99_sscanf(temp, "%u", &m_conf->core_timeout);
      goto LABEL_99;
    }
    temp = strstr(str, "ChipAlarmTemp=");
    if ( temp )
    {
      temp += 14;
      _isoc99_sscanf(temp, "%d", &m_conf->chip_alarm_temp);
      goto LABEL_99;
    }
    temp = strstr(str, "BringupFreq=");
    if ( temp )
    {
      temp += 12;
      _isoc99_sscanf(temp, "%d", &m_conf->bringup_freq);
      goto LABEL_99;
    }
    temp = strstr(str, "BringupVoltage=");
    if ( temp )
    {
      temp += 15;
      _isoc99_sscanf(temp, "%d", &m_conf->bringup_voltage);
      goto LABEL_99;
    }
    temp = strstr(str, "BringupWorkIntervalS=");
    if ( temp )
    {
      temp += 21;
      _isoc99_sscanf(temp, "%d", &m_conf->bringup_work_interval_s);
      goto LABEL_99;
    }
    temp = strstr(str, "BringupAutoJHVolt=");
    if ( temp )
    {
      temp += 18;
      num = parse_config_ini_array(temp, (void **)&m_conf->bringup_autojh_volt);
      if ( num != 3 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 1 )
        {
          snprintf(tmp42, 0x400u, "BringupAutoJHVolt number error %d\n", num);
          applog(2, tmp42, 0);
        }
        return -1;
      }
      goto LABEL_99;
    }
    temp = strstr(str, "BringupAutoJHFreq=");
    if ( temp )
    {
      temp += 18;
      num_0 = parse_config_ini_array(temp, (void **)&m_conf->bringup_autojh_freq);
      if ( num_0 != 3 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 1 )
        {
          snprintf(tmp42, 0x400u, "BringupAutoJHFreq number error %d\n", num_0);
          applog(2, tmp42, 0);
        }
        return -1;
      }
      goto LABEL_99;
    }
    temp = strstr(str, "PattenNum=");
    if ( temp )
    {
      temp += 10;
      _isoc99_sscanf(temp, "%d", &m_conf->pattern_num);
      goto LABEL_99;
    }
    temp = strstr(str, "SltTestMode=");
    if ( temp )
    {
      temp += 12;
      _isoc99_sscanf(temp, "%d", &m_conf->slt_test_mode);
      goto LABEL_99;
    }
    temp = strstr(str, "SltTunelPath=");
    if ( temp )
    {
      temp += 13;
      _isoc99_sscanf(temp, "%s", m_conf->slt_tunel_path);
      goto LABEL_99;
    }
    temp = strstr(str, "SltCP210xRuntime=");
    if ( temp )
    {
      temp += 17;
      _isoc99_sscanf(temp, "%s", m_conf->slt_cp210x_runtime);
      goto LABEL_99;
    }
    temp = strstr(str, "SltBinRate=");
    if ( temp )
    {
      temp += 11;
      num_1 = parse_config_ini_array(temp, (void **)&m_conf->slt_bin_rate);
      if ( num_1 != 3 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 1 )
        {
          snprintf(tmp42, 0x400u, "SltBinRate number error %d\n", num_1);
          applog(2, tmp42, 0);
        }
        return -1;
      }
      goto LABEL_99;
    }
    temp = strstr(str, "SltDelay=");
    if ( temp )
    {
      temp += 9;
      _isoc99_sscanf(temp, "%d", &m_conf->slt_delay);
      goto LABEL_99;
    }
    temp = strstr(str, "SltFreq=");
    if ( temp )
    {
      temp += 8;
      _isoc99_sscanf(temp, "%d", &m_conf->slt_freq);
      goto LABEL_99;
    }
    temp = strstr(str, "SltWorkIntervalMs=");
    if ( temp )
    {
      temp += 18;
      _isoc99_sscanf(temp, "%d", &m_conf->slt_work_interval_ms);
      goto LABEL_99;
    }
    temp = strstr(str, "SltEnableReadTemp=");
    if ( temp )
    {
      temp += 18;
      _isoc99_sscanf(temp, "%d", &m_conf->slt_enable_read_temp);
      goto LABEL_99;
    }
    temp = strstr(str, "PcbaRepeatCtrl=");
    if ( temp )
    {
      temp += 15;
      _isoc99_sscanf(temp, "%s", m_conf->pcba_repeat_ctrl);
      goto LABEL_99;
    }
    temp = strstr(str, "PcbaFreq=");
    if ( temp )
    {
      temp += 9;
      _isoc99_sscanf(temp, "%d", &m_conf->pcba_freq);
      goto LABEL_99;
    }
    temp = strstr(str, "PcbaVoltage=");
    if ( temp )
    {
      temp += 12;
      _isoc99_sscanf(temp, "%d", &m_conf->pcba_voltage);
      goto LABEL_99;
    }
    temp = strstr(str, "PcbaTemptureHigh=");
    if ( temp )
    {
      temp += 17;
      _isoc99_sscanf(temp, "%d", &m_conf->pcba_tempture_high);
      goto LABEL_99;
    }
    temp = strstr(str, "PcbaTemptureLow=");
    if ( temp )
    {
      temp += 16;
      _isoc99_sscanf(temp, "%d", &m_conf->pcba_tempture_low);
      goto LABEL_99;
    }
    temp = strstr(str, "PcbaOnlyFindASIC=");
    if ( temp )
    {
      temp += 17;
      _isoc99_sscanf(temp, "%d", &m_conf->pcba_only_find_asic);
      goto LABEL_99;
    }
    temp = strstr(str, "PcbaPatternPassRate=");
    if ( temp )
    {
      temp += 20;
      _isoc99_sscanf(temp, "%d", &m_conf->pcba_pattern_pass_rate);
      goto LABEL_99;
    }
    temp = strstr(str, "PcbaSendPtTimeout=");
    if ( temp )
    {
      temp += 18;
      _isoc99_sscanf(temp, "%d", &m_conf->send_pattern_timeout);
      goto LABEL_99;
    }
    temp = strstr(str, "PcbaEnableLevel=");
    if ( temp )
    {
      temp += 16;
      _isoc99_sscanf(temp, "%d", &m_conf->pcba_enable_level);
      goto LABEL_99;
    }
    temp = strstr(str, "PcbaLevelRate=");
    if ( temp )
    {
      temp += 14;
      num_2 = parse_config_ini_array(temp, (void **)&m_conf->pcba_level_rate);
      if ( num_2 != 3 )
        break;
    }
LABEL_99:
    memset(str, 0, sizeof(str));
  }
  if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(tmp42, 0x400u, "PcbaLevelRate number should be 3, but not %d\n", num_2);
    applog(2, tmp42, 0);
  }
  return -1;
}
