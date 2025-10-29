void *read_all_sensor()
{
  char tmp42[1024]; // [sp+Ch] [bp+4h] BYREF
  int chip_addr; // [sp+40Ch] [bp+404h]
  runtime_base_t *runtime; // [sp+410h] [bp+408h]
  int high_temp_alarm_counter; // [sp+414h] [bp+40Ch]
  int pcb_high_temp; // [sp+418h] [bp+410h]
  int chip_high_temp; // [sp+41Ch] [bp+414h]
  int which_asic; // [sp+420h] [bp+418h]
  int i; // [sp+424h] [bp+41Ch]

  runtime = cgpu.runtime;
  high_temp_alarm_counter = 0;
  while ( runtime->start_recv )
  {
    for ( i = 0; runtime->sensor_num > i; ++i )
    {
      which_asic = runtime->sensor_pos[i];
      chip_addr = which_asic * runtime->addr_interval;
      user_read_iic(runtime, chip_addr, 0x4Cu, 1u, &chip_temp[which_asic], 1);
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "ASIC %d chip temp %d\n", which_asic, chip_temp[which_asic]);
        applog(2, tmp42, 0);
      }
      user_read_iic(runtime, chip_addr, 0x4Cu, 0, &pcb_temp[which_asic], 1);
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "ASIC %d pcb temp %d\n", which_asic, pcb_temp[which_asic]);
        applog(2, tmp42, 0);
      }
    }
    pcb_high_temp = 0;
    chip_high_temp = 0;
    for ( which_asic = 0; which_asic <= 2; ++which_asic )
    {
      if ( chip_temp[which_asic] > chip_high_temp )
        chip_high_temp = chip_temp[which_asic];
      if ( pcb_temp[which_asic] > pcb_high_temp )
        pcb_high_temp = pcb_temp[which_asic];
    }
    chip_high = chip_high_temp;
    pcb_high = pcb_high_temp;
    if ( (unsigned __int8)chip_high_temp <= app_conf->pcba_tempture_high )
    {
      high_temp_alarm_counter = 0;
    }
    else
    {
      ++high_temp_alarm_counter;
      if ( use_syslog || opt_log_output || opt_log_level > 1 )
      {
        snprintf(tmp42, 0x400u, "temperature alarm counter %d\n", high_temp_alarm_counter);
        applog(2, tmp42, 0);
      }
      if ( high_temp_alarm_counter > 1 )
        hardware_exception = 1;
    }
    sleep(2u);
  }
  return 0;
}
