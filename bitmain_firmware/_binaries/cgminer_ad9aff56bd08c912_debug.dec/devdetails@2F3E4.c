void __fastcall devdetails(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r6
  _BOOL4 v7; // r10
  api_data *v8; // r11
  int v9; // r0
  char *v10; // r7
  cgpu_info *devices; // r0
  char *v12; // r1
  cgpu_info *v13; // r5
  api_data *v14; // r0
  api_data *v15; // r0
  char *v16; // r1
  api_data *v17; // r0
  api_data *v18; // r0
  char *kname; // r3
  api_data *v20; // r0
  char *name; // r3
  api_data *v22; // r0
  char *device_path; // r3
  api_data *v24; // r0
  bool v25; // r3
  char *v26; // r1
  int i; // [sp+Ch] [bp-8h] BYREF

  v5 = isjson;
  if ( !total_devices )
  {
    message(io_data, 10, 0, 0, isjson);
    return;
  }
  message(io_data, 69, 0, 0, isjson);
  if ( !v5 )
  {
    i = 0;
    if ( total_devices <= 0 )
      return;
    v7 = 0;
    goto LABEL_6;
  }
  LOWORD(v26) = 21896;
  HIWORD(v26) = (unsigned int)"nt" >> 16;
  v7 = io_add(io_data, v26);
  i = 0;
  if ( total_devices > 0 )
  {
LABEL_6:
    v8 = 0;
    LOWORD(v10) = -27628;
    v9 = 0;
    HIWORD(v10) = (unsigned int)"c.txt" >> 16;
    do
    {
      devices = get_devices(v9);
      LOWORD(v12) = 21912;
      v13 = devices;
      HIWORD(v12) = (unsigned int)"ose" >> 16;
      v14 = api_add_data_full(v8, v12, api_data_type::API_INT, &i, 0);
      v15 = api_add_data_full(v14, "Name", api_data_type::API_STRING, v13->drv->name, 0);
      LOWORD(v16) = 21924;
      HIWORD(v16) = (unsigned int)"RPCProto" >> 16;
      v17 = api_add_data_full(v15, v16, api_data_type::API_INT, &v13->device_id, 0);
      v18 = api_add_data_full(v17, "Driver", api_data_type::API_STRING, v13->drv->dname, 0);
      kname = (char *)v13->kname;
      if ( !kname )
        kname = v10;
      v20 = api_add_data_full(v18, "Kernel", api_data_type::API_CONST, kname, 0);
      name = v13->name;
      if ( !name )
        name = v10;
      v22 = api_add_data_full(v20, "Model", api_data_type::API_CONST, name, 0);
      device_path = v13->device_path;
      if ( !device_path )
        device_path = v10;
      v24 = api_add_data_full(v22, "Device Path", api_data_type::API_CONST, device_path, 0);
      v25 = v5;
      if ( v5 )
        v25 = i > 0;
      v8 = print_data(io_data, v24, v5, v25);
      v9 = ++i;
    }
    while ( i < total_devices );
  }
  if ( v7 )
    io_data->close = 1;
}
