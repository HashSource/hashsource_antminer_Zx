void __fastcall notify(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r6
  _BOOL4 v7; // r9
  int v8; // r4
  cgpu_info *devices; // r0
  int v10; // r1

  if ( !total_devices )
  {
    message(io_data, 10, 0, 0, isjson);
    return;
  }
  v5 = isjson;
  message(io_data, 60, 0, 0, isjson);
  if ( !v5 )
  {
    if ( total_devices <= 0 )
      return;
    v7 = 0;
    goto LABEL_6;
  }
  v7 = io_add(io_data, ",\"NOTIFY\":[");
  if ( total_devices > 0 )
  {
LABEL_6:
    v8 = 0;
    do
    {
      devices = get_devices(v8);
      v10 = v8++;
      notifystatus(io_data, v10, devices, v5, group);
    }
    while ( total_devices > v8 );
  }
  if ( v7 )
    io_data->close = 1;
}
