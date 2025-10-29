void __fastcall notifystatus(io_data *io_data, int device, cgpu_info *cgpu, bool isjson, char group)
{
  time_t device_last_not_well; // r2
  int v7; // r7
  _BOOL4 v9; // r6
  dev_reason device_not_well_reason; // r2
  __int16 v11; // r3^2
  api_data *v12; // r0
  api_data *v13; // r0
  api_data *v14; // r0
  api_data *v15; // r0
  api_data *v16; // r0
  api_data *v17; // r0
  api_data *v18; // r0
  api_data *v19; // r0
  api_data *v20; // r0
  api_data *v21; // r0
  api_data *v22; // r0
  api_data *v23; // r0
  api_data *v24; // r0
  api_data *v25; // r0
  api_data *v26; // r0
  api_data *v27; // r0
  bool v28; // r3
  int devicea; // [sp+Ch] [bp-4h] BYREF

  device_last_not_well = cgpu->device_last_not_well;
  v7 = (int)"None";
  v9 = isjson;
  devicea = device;
  if ( device_last_not_well )
  {
    device_not_well_reason = cgpu->device_not_well_reason;
    if ( (unsigned int)device_not_well_reason > dev_reason::REASON_DEV_COMMS_ERROR )
      v7 = 22944;
    else
      *(_DWORD *)&isjson = 19980;
    if ( (unsigned int)device_not_well_reason > dev_reason::REASON_DEV_COMMS_ERROR )
      HIWORD(v7) = 5;
    else
      v11 = 5;
    if ( (unsigned int)device_not_well_reason <= dev_reason::REASON_DEV_COMMS_ERROR )
      v7 = *(_DWORD *)(isjson + 4 * device_not_well_reason + 112);
  }
  v12 = api_add_data_full(0, "NOTIFY", api_data_type::API_INT, &devicea, 0);
  v13 = api_add_data_full(v12, "Name", api_data_type::API_STRING, cgpu->drv->name, 0);
  v14 = api_add_data_full(v13, "ID", api_data_type::API_INT, &cgpu->device_id, 0);
  v15 = api_add_data_full(v14, "Last Well", api_data_type::API_TIME, &cgpu->device_last_well, 0);
  v16 = api_add_data_full(v15, "Last Not Well", api_data_type::API_TIME, &cgpu->device_last_not_well, 0);
  v17 = api_add_data_full(v16, "Reason Not Well", api_data_type::API_STRING, (void *)v7, 0);
  v18 = api_add_data_full(v17, "*Thread Fail Init", api_data_type::API_INT, &cgpu->thread_fail_init_count, 0);
  v19 = api_add_data_full(v18, "*Thread Zero Hash", api_data_type::API_INT, &cgpu->thread_zero_hash_count, 0);
  v20 = api_add_data_full(v19, "*Thread Fail Queue", api_data_type::API_INT, &cgpu->thread_fail_queue_count, 0);
  v21 = api_add_data_full(v20, "*Dev Sick Idle 60s", api_data_type::API_INT, &cgpu->dev_sick_idle_60_count, 0);
  v22 = api_add_data_full(v21, "*Dev Dead Idle 600s", api_data_type::API_INT, &cgpu->dev_dead_idle_600_count, 0);
  v23 = api_add_data_full(v22, "*Dev Nostart", api_data_type::API_INT, &cgpu->dev_nostart_count, 0);
  v24 = api_add_data_full(v23, "*Dev Over Heat", api_data_type::API_INT, &cgpu->dev_over_heat_count, 0);
  v25 = api_add_data_full(v24, "*Dev Thermal Cutoff", api_data_type::API_INT, &cgpu->dev_thermal_cutoff_count, 0);
  v26 = api_add_data_full(v25, "*Dev Comms Error", api_data_type::API_INT, &cgpu->dev_comms_error_count, 0);
  v27 = api_add_data_full(v26, "*Dev Throttle", api_data_type::API_INT, &cgpu->dev_throttle_count, 0);
  v28 = v9;
  if ( v9 )
    v28 = devicea > 0;
  print_data(io_data, v27, v9, v28);
}
