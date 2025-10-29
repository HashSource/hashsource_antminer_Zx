void __fastcall devdetails(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r6
  _BOOL4 v7; // r10
  api_data *v8; // r11
  int v9; // r0
  cgpu_info *devices; // r5
  api_data *v11; // r0
  api_data *v12; // r0
  api_data *v13; // r0
  api_data *v14; // r0
  char *kname; // r3
  api_data *v16; // r0
  char *name; // r3
  api_data *v18; // r0
  char *device_path; // r3
  api_data *v20; // r0
  bool v21; // r3
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
  v7 = io_add(io_data, ",\"DEVDETAILS\":[");
  i = 0;
  if ( total_devices > 0 )
  {
LABEL_6:
    v8 = 0;
    v9 = 0;
    do
    {
      devices = get_devices(v9);
      v11 = api_add_data_full(v8, "DEVDETAILS", api_data_type::API_INT, &i, 0);
      v12 = api_add_data_full(v11, "Name", api_data_type::API_STRING, devices->drv->name, 0);
      v13 = api_add_data_full(v12, "ID", api_data_type::API_INT, &devices->device_id, 0);
      v14 = api_add_data_full(v13, "Driver", api_data_type::API_STRING, devices->drv->dname, 0);
      kname = (char *)devices->kname;
      if ( !kname )
        kname = &byte_59398;
      v16 = api_add_data_full(v14, "Kernel", api_data_type::API_CONST, kname, 0);
      name = devices->name;
      if ( !name )
        name = &byte_59398;
      v18 = api_add_data_full(v16, "Model", api_data_type::API_CONST, name, 0);
      device_path = devices->device_path;
      if ( !device_path )
        device_path = &byte_59398;
      v20 = api_add_data_full(v18, "Device Path", api_data_type::API_CONST, device_path, 0);
      v21 = v5;
      if ( v5 )
        v21 = i > 0;
      v8 = print_data(io_data, v20, v5, v21);
      v9 = ++i;
    }
    while ( i < total_devices );
  }
  if ( v7 )
    io_data->close = 1;
}
