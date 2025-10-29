void __fastcall minerestats(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r9
  int v7; // r4
  const char *v8; // r10
  int v9; // r8
  cgpu_info *devices; // r0
  cgpu_info *v11; // r5
  device_drv *drv; // r3
  int (*pool_stats)(void); // r6
  int v14; // r0
  char *v15; // r1
  cgpu_info *v16; // [sp+8h] [bp-24h]
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
  LOWORD(v15) = 22336;
  HIWORD(v15) = (unsigned int)"ION," >> 16;
  io_open = io_add(io_data, v15);
  if ( total_devices > 0 )
  {
LABEL_5:
    v7 = 0;
    LOWORD(v8) = 22348;
    v9 = 0;
    do
    {
      devices = get_devices(v7);
      v11 = devices;
      if ( devices )
      {
        drv = devices->drv;
        if ( drv )
        {
          pool_stats = (int (*)(void))drv->get_api_stats;
          if ( pool_stats )
          {
            v14 = pool_stats();
            drv = v11->drv;
            pool_stats = (int (*)(void))v14;
          }
          HIWORD(v8) = (unsigned int)"OLS\":[" >> 16;
          sprintf(id, v8, drv->name, v11->device_id);
          v9 = itemstats(io_data, v9, id, &v11->cgminer_stats, (api_data *)pool_stats, (api_data *)v5, v16, io_open);
        }
      }
      ++v7;
    }
    while ( total_devices > v7 );
  }
  if ( io_open )
    io_data->close = 1;
}
