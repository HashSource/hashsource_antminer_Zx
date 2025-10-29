void __fastcall minerstats(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r7
  api_data *v7; // r0
  api_data *v8; // r0
  api_data *v9; // r0
  api_data *v10; // r0
  int v11; // r4
  int v12; // r9
  cgpu_info *devices; // r0
  cgpu_info *v14; // r5
  device_drv *drv; // r3
  int (*get_api_stats)(void); // r6
  int v17; // r0
  api_data *v18; // r0
  api_data *v19; // r0
  api_data *v20; // r0
  api_data *v21; // r0
  cgpu_info *v22; // [sp+8h] [bp-24h]
  _BOOL4 io_open; // [sp+Ch] [bp-20h]
  char id[24]; // [sp+14h] [bp-18h] BYREF

  v5 = isjson;
  message(io_data, 70, 0, 0, isjson);
  if ( !v5 )
  {
    v7 = api_add_data_full(0, "CGMiner", api_data_type::API_STRING, &unk_5320C, 0);
    v8 = api_add_data_full(v7, "Miner", api_data_type::API_STRING, g_miner_version, 0);
    v9 = api_add_data_full(v8, "CompileTime", api_data_type::API_STRING, g_miner_compiletime, 0);
    v10 = api_add_data_full(v9, "Type", api_data_type::API_STRING, g_miner_type, 0);
    print_data(io_data, v10, 0, 0);
    if ( total_devices <= 0 )
      return;
    io_open = 0;
    goto LABEL_5;
  }
  io_open = io_add(io_data, ",\"STATS\":[");
  v18 = api_add_data_full(0, "CGMiner", api_data_type::API_STRING, &unk_5320C, 0);
  v19 = api_add_data_full(v18, "Miner", api_data_type::API_STRING, g_miner_version, 0);
  v20 = api_add_data_full(v19, "CompileTime", api_data_type::API_STRING, g_miner_compiletime, 0);
  v21 = api_add_data_full(v20, "Type", api_data_type::API_STRING, g_miner_type, 0);
  print_data(io_data, v21, 1, 0);
  if ( total_devices > 0 )
  {
LABEL_5:
    v11 = 0;
    v12 = 0;
    do
    {
      devices = get_devices(v11);
      v14 = devices;
      if ( devices )
      {
        drv = devices->drv;
        if ( drv )
        {
          get_api_stats = (int (*)(void))drv->get_api_stats;
          if ( get_api_stats )
          {
            v17 = get_api_stats();
            drv = v14->drv;
            get_api_stats = (int (*)(void))v17;
          }
          sprintf(id, "%s%d", drv->name, v14->device_id);
          v12 = itemstats(
                  io_data,
                  v12,
                  id,
                  &v14->cgminer_stats,
                  (api_data *)get_api_stats,
                  (api_data *)v5,
                  v22,
                  io_open);
        }
      }
      ++v11;
    }
    while ( total_devices > v11 );
  }
  if ( io_open )
    io_data->close = 1;
}
