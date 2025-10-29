void __fastcall minerconfig(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r5
  char *v7; // r1
  _BOOL4 v8; // r0
  char *v9; // r1
  _BOOL4 v10; // r7
  api_data *v11; // r0
  char *v12; // r1
  api_data *v13; // r0
  char *v14; // r1
  api_data *v15; // r0
  char *v16; // r1
  api_data *v17; // r0
  char *v18; // r1
  api_data *v19; // r0
  void *v20; // r3
  char *v21; // r1
  api_data *v22; // r0
  void *v23; // r3
  char *v24; // r1
  api_data *v25; // r0
  char *v26; // r1
  api_data *v27; // r0
  char *v28; // r1
  api_data *v29; // r0
  char *v30; // r1
  api_data *v31; // r0
  char *v32; // r1
  api_data *v33; // r0
  void *v34; // r3
  char *v35; // r1
  api_data *v36; // r0
  int asccount; // [sp+8h] [bp-Ch] BYREF
  int pgacount; // [sp+Ch] [bp-8h] BYREF

  v5 = isjson;
  asccount = 0;
  pgacount = 0;
  message(io_data, 33, 0, 0, isjson);
  LOWORD(v7) = 21984;
  HIWORD(v7) = (unsigned int)",\"CHECK\":[" >> 16;
  if ( !v5 )
    v7 = "CONFIG,";
  v8 = io_add(io_data, v7);
  LOWORD(v9) = 22004;
  v10 = v8;
  HIWORD(v9) = (unsigned int)"Access" >> 16;
  v11 = api_add_data_full(0, v9, api_data_type::API_INT, &asccount, 0);
  LOWORD(v12) = 22016;
  HIWORD(v12) = (unsigned int)"ts" >> 16;
  v13 = api_add_data_full(v11, v12, api_data_type::API_INT, &pgacount, 0);
  LOWORD(v14) = 22028;
  HIWORD(v14) = (unsigned int)"AILS\":[" >> 16;
  v15 = api_add_data_full(v13, v14, api_data_type::API_INT, &total_pools, 0);
  LOWORD(v16) = 22040;
  HIWORD(v16) = (unsigned int)"ETAILS" >> 16;
  v17 = api_add_data_full(v15, v16, api_data_type::API_CONST, (void *)strategies_0[pool_strategy_0].s, 0);
  LOWORD(v18) = 22052;
  HIWORD(v18) = (unsigned int)"Driver" >> 16;
  v19 = api_add_data_full(v17, v18, api_data_type::API_INT, &opt_log_interval, 0);
  LOWORD(v20) = -27628;
  LOWORD(v21) = 22068;
  HIWORD(v20) = (unsigned int)"c.txt" >> 16;
  HIWORD(v21) = (unsigned int)"Model" >> 16;
  v22 = api_add_data_full(v19, v21, api_data_type::API_CONST, v20, 0);
  LOWORD(v23) = 22080;
  LOWORD(v24) = 22088;
  HIWORD(v23) = (unsigned int)"ce Path" >> 16;
  HIWORD(v24) = (unsigned int)",\"PGAS\":[" >> 16;
  v25 = api_add_data_full(v22, v24, api_data_type::API_CONST, v23, 0);
  LOWORD(v26) = 22092;
  HIWORD(v26) = (unsigned int)"AS\":[" >> 16;
  v27 = api_add_data_full(v25, v26, api_data_type::API_BOOL, &opt_fail_only, 0);
  LOWORD(v28) = 22108;
  HIWORD(v28) = (unsigned int)",\"CONFIG\":[" >> 16;
  v29 = api_add_data_full(v27, v28, api_data_type::API_INT, &opt_scantime, 0);
  LOWORD(v30) = 22120;
  HIWORD(v30) = (unsigned int)"CONFIG," >> 16;
  v31 = api_add_data_full(v29, v30, api_data_type::API_INT, &opt_queue, 0);
  LOWORD(v32) = 22128;
  HIWORD(v32) = (unsigned int)"ASC Count" >> 16;
  v33 = api_add_data_full(v31, v32, api_data_type::API_INT, &opt_expiry, 0);
  LOWORD(v34) = 22136;
  LOWORD(v35) = 22144;
  HIWORD(v34) = (unsigned int)"t" >> 16;
  HIWORD(v35) = (unsigned int)"Count" >> 16;
  v36 = api_add_data_full(v33, v35, api_data_type::API_CONST, v34, 0);
  print_data(io_data, v36, v5, 0);
  if ( v5 && v10 )
    io_data->close = 1;
}
