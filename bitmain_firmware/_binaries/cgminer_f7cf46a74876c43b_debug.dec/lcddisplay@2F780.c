void __fastcall lcddisplay(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v6; // r5
  _BOOL4 v7; // r8
  pool *v8; // r6
  api_data *v9; // r0
  api_data *v10; // r0
  api_data *v11; // r9
  api_data *v12; // r9
  api_data *v13; // r0
  api_data *v14; // r0
  api_data *v15; // r1
  api_data *v16; // r0
  double ghs; // [sp+8h] [bp-ACh] BYREF
  char szindex[32]; // [sp+10h] [bp-A4h] BYREF
  char szfan[32]; // [sp+30h] [bp-84h] BYREF
  char sztemp[32]; // [sp+50h] [bp-64h] BYREF
  char szpool[32]; // [sp+70h] [bp-44h] BYREF
  char szuser[36]; // [sp+90h] [bp-24h] BYREF

  v6 = isjson;
  memset(szindex, 0, sizeof(szindex));
  v7 = v6;
  memset(szfan, 0, sizeof(szfan));
  memset(sztemp, 0, sizeof(sztemp));
  memset(szpool, 0, sizeof(szpool));
  memset(szuser, 0, 0x20u);
  v8 = current_pool();
  message(io_data, 7, 0, 0, v6);
  if ( v6 )
    v7 = io_add(io_data, ",\"POOLS\":[");
  strcpy(szindex, "0");
  ghs = total_mhashes_done / 1000.0 / total_secs;
  v9 = api_add_data_full(0, "LCD", api_data_type::API_STRING, szindex, 0);
  v10 = api_add_data_full(v9, "GHS5s", api_data_type::API_MHS, &g_displayed_rolling, 0);
  v11 = api_add_data_full(v10, "GHSavg", api_data_type::API_MHS, &ghs, 0);
  sprintf(szfan, "%d", g_max_fan);
  v12 = api_add_data_full(v11, "fan", api_data_type::API_STRING, szfan, 0);
  sprintf(sztemp, "%d", g_max_temp);
  v13 = api_add_data_full(v12, "temp", api_data_type::API_STRING, sztemp, 0);
  if ( v8 )
  {
    v14 = api_add_data_full(v13, "pool", api_data_type::API_STRING, v8->rpc_url, 0);
    v15 = api_add_data_full(v14, "user", api_data_type::API_STRING, v8->rpc_user, 0);
  }
  else
  {
    strcpy(szpool, "no");
    strcpy(szuser, "no");
    v16 = api_add_data_full(v13, "pool", api_data_type::API_STRING, szpool, 0);
    v15 = api_add_data_full(v16, "user", api_data_type::API_STRING, szuser, 0);
  }
  print_data(io_data, v15, v6, v6);
  if ( v7 )
    io_data->close = 1;
}
