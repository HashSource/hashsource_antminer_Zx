void __fastcall minerestats(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r9
  int v7; // r4
  int v8; // r8
  cgpu_info *devices; // r0
  cgpu_info *v10; // r5
  device_drv *drv; // r3
  int (*pool_stats)(void); // r6
  int v13; // r0
  cgpu_info *v14; // [sp+8h] [bp-24h]
  _BOOL4 io_open; // [sp+Ch] [bp-20h]
  char id[24]; // [sp+14h] [bp-18h] BYREF

  v5 = isjson;
  message(io_data, 70, 0, 0, isjson);
  if ( !v5 )
  {
    if ( total_devices <= 0 )
      return;
    io_open = 0;
    goto LABEL_5;
  }
  io_open = io_add(io_data, ",\"STATS\":[");
  if ( total_devices > 0 )
  {
LABEL_5:
    v7 = 0;
    v8 = 0;
    do
    {
      devices = get_devices(v7);
      v10 = devices;
      if ( devices )
      {
        drv = devices->drv;
        if ( drv )
        {
          pool_stats = (int (*)(void))drv->get_api_stats;
          if ( pool_stats )
          {
            v13 = pool_stats();
            drv = v10->drv;
            pool_stats = (int (*)(void))v13;
          }
          sprintf(id, "%s%d", drv->name, v10->device_id);
          v8 = itemstats(io_data, v8, id, &v10->cgminer_stats, (api_data *)pool_stats, (api_data *)v5, v14, io_open);
        }
      }
      ++v7;
    }
    while ( total_devices > v7 );
  }
  if ( io_open )
    io_data->close = 1;
}
