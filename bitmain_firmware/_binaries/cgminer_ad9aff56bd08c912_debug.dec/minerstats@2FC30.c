void __fastcall minerstats(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r7
  void *v7; // r3
  char *v8; // r1
  api_data *v9; // r0
  char *v10; // r1
  api_data *v11; // r0
  char *v12; // r1
  api_data *v13; // r0
  char *v14; // r1
  api_data *v15; // r0
  int v16; // r4
  const char *v17; // r11
  int v18; // r9
  cgpu_info *devices; // r0
  cgpu_info *v20; // r5
  device_drv *drv; // r3
  int (*get_api_stats)(void); // r6
  int v23; // r0
  char *v24; // r1
  _BOOL4 v25; // r0
  void *v26; // r3
  char *v27; // r1
  api_data *v28; // r0
  char *v29; // r1
  api_data *v30; // r0
  char *v31; // r1
  api_data *v32; // r0
  char *v33; // r1
  api_data *v34; // r0
  cgpu_info *v35; // [sp+8h] [bp-24h]
  _BOOL4 io_open; // [sp+Ch] [bp-20h]
  char id[24]; // [sp+14h] [bp-18h] BYREF

  v5 = isjson;
  message(io_data, 70, 0, 0, isjson);
  if ( !v5 )
  {
    LOWORD(v7) = 12940;
    LOWORD(v8) = 22168;
    HIWORD(v7) = (unsigned int)"Use extra wide display without toggling" >> 16;
    HIWORD(v8) = (unsigned int)"tegy" >> 16;
    v9 = api_add_data_full(0, v8, api_data_type::API_STRING, v7, 0);
    LOWORD(v10) = 22180;
    HIWORD(v10) = (unsigned int)"Interval" >> 16;
    v11 = api_add_data_full(v9, v10, api_data_type::API_STRING, g_miner_version, 0);
    LOWORD(v12) = 22188;
    HIWORD(v12) = (unsigned int)"" >> 16;
    v13 = api_add_data_full(v11, v12, api_data_type::API_STRING, g_miner_compiletime, 0);
    LOWORD(v14) = 22200;
    HIWORD(v14) = (unsigned int)"ode" >> 16;
    v15 = api_add_data_full(v13, v14, api_data_type::API_STRING, g_miner_type, 0);
    print_data(io_data, v15, 0, 0);
    if ( total_devices <= 0 )
      return;
    io_open = 0;
    goto LABEL_5;
  }
  LOWORD(v24) = 22336;
  HIWORD(v24) = (unsigned int)"ION," >> 16;
  v25 = io_add(io_data, v24);
  LOWORD(v26) = 12940;
  LOWORD(v27) = 22168;
  io_open = v25;
  HIWORD(v26) = (unsigned int)"Use extra wide display without toggling" >> 16;
  HIWORD(v27) = (unsigned int)"tegy" >> 16;
  v28 = api_add_data_full(0, v27, api_data_type::API_STRING, v26, 0);
  LOWORD(v29) = 22180;
  HIWORD(v29) = (unsigned int)"Interval" >> 16;
  v30 = api_add_data_full(v28, v29, api_data_type::API_STRING, g_miner_version, 0);
  LOWORD(v31) = 22188;
  HIWORD(v31) = (unsigned int)"" >> 16;
  v32 = api_add_data_full(v30, v31, api_data_type::API_STRING, g_miner_compiletime, 0);
  LOWORD(v33) = 22200;
  HIWORD(v33) = (unsigned int)"ode" >> 16;
  v34 = api_add_data_full(v32, v33, api_data_type::API_STRING, g_miner_type, 0);
  print_data(io_data, v34, 1, 0);
  if ( total_devices > 0 )
  {
LABEL_5:
    v16 = 0;
    LOWORD(v17) = 22348;
    v18 = 0;
    do
    {
      devices = get_devices(v16);
      v20 = devices;
      if ( devices )
      {
        drv = devices->drv;
        if ( drv )
        {
          get_api_stats = (int (*)(void))drv->get_api_stats;
          if ( get_api_stats )
          {
            v23 = get_api_stats();
            drv = v20->drv;
            get_api_stats = (int (*)(void))v23;
          }
          HIWORD(v17) = (unsigned int)"OLS\":[" >> 16;
          sprintf(id, v17, drv->name, v20->device_id);
          v18 = itemstats(
                  io_data,
                  v18,
                  id,
                  &v20->cgminer_stats,
                  (api_data *)get_api_stats,
                  (api_data *)v5,
                  v35,
                  io_open);
        }
      }
      ++v16;
    }
    while ( total_devices > v16 );
  }
  if ( io_open )
    io_data->close = 1;
}
