void __fastcall apiversion(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r4
  char *v7; // r1
  _BOOL4 v8; // r0
  void *v9; // r3
  char *v10; // r1
  _BOOL4 v11; // r6
  api_data *v12; // r0
  void *v13; // r3
  api_data *v14; // r0
  char *v15; // r1
  api_data *v16; // r0
  char *v17; // r1
  api_data *v18; // r0
  char *v19; // r1
  api_data *v20; // r0
  char *v21; // r1
  void *v22; // r3
  char *v23; // r1
  api_data *v24; // r0
  void *v25; // r3
  api_data *v26; // r0
  char *v27; // r1
  api_data *v28; // r0
  char *v29; // r1
  api_data *v30; // r0
  char *v31; // r1
  api_data *v32; // r1

  v5 = isjson;
  message(io_data, 22, 0, 0, isjson);
  if ( v5 )
  {
    LOWORD(v7) = 22028;
    HIWORD(v7) = (unsigned int)"lloc cgpu_info data" >> 16;
    v8 = io_add(io_data, v7);
    LOWORD(v9) = 12812;
    LOWORD(v10) = 22044;
    v11 = v8;
    HIWORD(v9) = (unsigned int)"ata" >> 16;
    HIWORD(v10) = (unsigned int)"cgpu(cgpu)" >> 16;
    v12 = api_add_data_full(0, v10, api_data_type::API_STRING, v9, 0);
    LOWORD(v13) = 22052;
    HIWORD(v13) = (unsigned int)"u)" >> 16;
    v14 = api_add_data_full(v12, "API", api_data_type::API_CONST, v13, 0);
    LOWORD(v15) = 22056;
    HIWORD(v15) = (unsigned int)"etect new device" >> 16;
    v16 = api_add_data_full(v14, v15, api_data_type::API_STRING, g_miner_version, 0);
    LOWORD(v17) = 22064;
    HIWORD(v17) = (unsigned int)"w device" >> 16;
    v18 = api_add_data_full(v16, v17, api_data_type::API_STRING, g_miner_compiletime, 0);
    LOWORD(v19) = 22076;
    HIWORD(v19) = (unsigned int)"%s: i2c always busy, break\n" >> 16;
    v20 = api_add_data_full(v18, v19, api_data_type::API_STRING, g_miner_type, 0);
    print_data(io_data, v20, 1, 0);
    if ( v11 )
      io_data->close = 1;
  }
  else
  {
    LOWORD(v21) = 22084;
    HIWORD(v21) = (unsigned int)"always busy, break\n" >> 16;
    io_add(io_data, v21);
    LOWORD(v22) = 12812;
    LOWORD(v23) = 22044;
    HIWORD(v22) = (unsigned int)"ata" >> 16;
    HIWORD(v23) = (unsigned int)"cgpu(cgpu)" >> 16;
    v24 = api_add_data_full(0, v23, api_data_type::API_STRING, v22, 0);
    LOWORD(v25) = 22052;
    HIWORD(v25) = (unsigned int)"u)" >> 16;
    v26 = api_add_data_full(v24, "API", api_data_type::API_CONST, v25, 0);
    LOWORD(v27) = 22056;
    HIWORD(v27) = (unsigned int)"etect new device" >> 16;
    v28 = api_add_data_full(v26, v27, api_data_type::API_STRING, g_miner_version, 0);
    LOWORD(v29) = 22064;
    HIWORD(v29) = (unsigned int)"w device" >> 16;
    v30 = api_add_data_full(v28, v29, api_data_type::API_STRING, g_miner_compiletime, 0);
    LOWORD(v31) = 22076;
    HIWORD(v31) = (unsigned int)"%s: i2c always busy, break\n" >> 16;
    v32 = api_add_data_full(v30, v31, api_data_type::API_STRING, g_miner_type, 0);
    print_data(io_data, v32, 0, 0);
  }
}
