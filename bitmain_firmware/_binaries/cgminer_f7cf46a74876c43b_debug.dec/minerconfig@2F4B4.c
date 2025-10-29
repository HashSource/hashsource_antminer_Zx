void __fastcall minerconfig(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r5
  char *v7; // r1
  _BOOL4 v8; // r7
  api_data *v9; // r0
  api_data *v10; // r0
  api_data *v11; // r0
  api_data *v12; // r0
  api_data *v13; // r0
  api_data *v14; // r0
  api_data *v15; // r0
  api_data *v16; // r0
  api_data *v17; // r0
  api_data *v18; // r0
  api_data *v19; // r0
  api_data *v20; // r0
  int asccount; // [sp+8h] [bp-Ch] BYREF
  int pgacount; // [sp+Ch] [bp-8h] BYREF

  v5 = isjson;
  asccount = 0;
  pgacount = 0;
  message(io_data, 33, 0, 0, isjson);
  v7 = ",\"CONFIG\":[";
  if ( !v5 )
    v7 = "CONFIG,";
  v8 = io_add(io_data, v7);
  v9 = api_add_data_full(0, "ASC Count", api_data_type::API_INT, &asccount, 0);
  v10 = api_add_data_full(v9, "PGA Count", api_data_type::API_INT, &pgacount, 0);
  v11 = api_add_data_full(v10, "Pool Count", api_data_type::API_INT, &total_pools, 0);
  v12 = api_add_data_full(v11, "Strategy", api_data_type::API_CONST, (void *)strategies_0[pool_strategy_0].s, 0);
  v13 = api_add_data_full(v12, "Log Interval", api_data_type::API_INT, &opt_log_interval, 0);
  v14 = api_add_data_full(v13, "Device Code", api_data_type::API_CONST, &byte_59398, 0);
  v15 = api_add_data_full(v14, "OS", api_data_type::API_CONST, "Linux", 0);
  v16 = api_add_data_full(v15, "Failover-Only", api_data_type::API_BOOL, &opt_fail_only, 0);
  v17 = api_add_data_full(v16, "ScanTime", api_data_type::API_INT, &opt_scantime, 0);
  v18 = api_add_data_full(v17, "Queue", api_data_type::API_INT, &opt_queue, 0);
  v19 = api_add_data_full(v18, "Expiry", api_data_type::API_INT, &opt_expiry, 0);
  v20 = api_add_data_full(v19, "Hotplug", api_data_type::API_CONST, "None", 0);
  print_data(io_data, v20, v5, 0);
  if ( v5 && v8 )
    io_data->close = 1;
}
