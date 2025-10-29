void __fastcall lcddisplay(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v6; // r5
  _BOOL4 v7; // r8
  pool *v8; // r6
  char *v9; // r1
  api_data *v10; // r0
  char *v11; // r1
  api_data *v12; // r0
  char *v13; // r1
  api_data *v14; // r0
  const char *v15; // r1
  api_data *v16; // r9
  char *v17; // r1
  api_data *v18; // r0
  const char *v19; // r1
  api_data *v20; // r9
  char *v21; // r1
  api_data *v22; // r0
  char *v23; // r1
  api_data *v24; // r0
  char *v25; // r1
  api_data *v26; // r1
  char *v27; // r1
  int *v28; // r3
  char *v29; // r1
  int v30; // r4
  api_data *v31; // r0
  char *v32; // r1
  double ghs; // [sp+8h] [bp-ACh] BYREF
  char szindex[32]; // [sp+10h] [bp-A4h] BYREF
  char szfan[32]; // [sp+30h] [bp-84h] BYREF
  char sztemp[32]; // [sp+50h] [bp-64h] BYREF
  char szpool[32]; // [sp+70h] [bp-44h] BYREF
  char szuser[32]; // [sp+90h] [bp-24h] BYREF

  v6 = isjson;
  memset(szindex, 0, sizeof(szindex));
  v7 = v6;
  memset(szfan, 0, sizeof(szfan));
  memset(sztemp, 0, sizeof(sztemp));
  memset(szpool, 0, sizeof(szpool));
  memset(szuser, 0, sizeof(szuser));
  v8 = current_pool();
  message(io_data, 7, 0, 0, v6);
  if ( v6 )
  {
    LOWORD(v27) = 22220;
    HIWORD(v27) = (unsigned int)"over-Only" >> 16;
    v7 = io_add(io_data, v27);
  }
  LOWORD(v9) = 22232;
  HIWORD(v9) = (unsigned int)"ScanTime" >> 16;
  strcpy(szindex, "0");
  ghs = total_mhashes_done / 1000.0 / total_secs;
  v10 = api_add_data_full(0, v9, api_data_type::API_STRING, szindex, 0);
  LOWORD(v11) = 22236;
  HIWORD(v11) = (unsigned int)"Time" >> 16;
  v12 = api_add_data_full(v10, v11, api_data_type::API_MHS, &g_displayed_rolling, 0);
  LOWORD(v13) = 22244;
  HIWORD(v13) = (unsigned int)"Queue" >> 16;
  v14 = api_add_data_full(v12, v13, api_data_type::API_MHS, &ghs, 0);
  LOWORD(v15) = -22732;
  v16 = v14;
  HIWORD(v15) = (unsigned int)"dev.timeout = %d us" >> 16;
  sprintf(szfan, v15, g_max_fan);
  LOWORD(v17) = 22252;
  HIWORD(v17) = (unsigned int)"Expiry" >> 16;
  v18 = api_add_data_full(v16, v17, api_data_type::API_STRING, szfan, 0);
  LOWORD(v19) = -22732;
  v20 = v18;
  HIWORD(v19) = (unsigned int)"dev.timeout = %d us" >> 16;
  sprintf(sztemp, v19, g_max_temp);
  LOWORD(v21) = 22256;
  HIWORD(v21) = (unsigned int)"ry" >> 16;
  v22 = api_add_data_full(v20, v21, api_data_type::API_STRING, sztemp, 0);
  if ( v8 )
  {
    LOWORD(v23) = 22264;
    HIWORD(v23) = (unsigned int)"" >> 16;
    v24 = api_add_data_full(v22, v23, api_data_type::API_STRING, v8->rpc_url, 0);
    LOWORD(v25) = 22272;
    HIWORD(v25) = (unsigned int)"lug" >> 16;
    v26 = api_add_data_full(v24, v25, api_data_type::API_STRING, v8->rpc_user, 0);
  }
  else
  {
    LOWORD(v28) = 17908;
    LOWORD(v29) = 22264;
    HIWORD(v28) = (unsigned int)"\"params\": []}" >> 16;
    HIWORD(v29) = (unsigned int)"" >> 16;
    v30 = *v28;
    *(_WORD *)szpool = v30;
    *(_WORD *)szuser = v30;
    szpool[2] = BYTE2(v30);
    szuser[2] = BYTE2(v30);
    v31 = api_add_data_full(v22, v29, api_data_type::API_STRING, szpool, 0);
    LOWORD(v32) = 22272;
    HIWORD(v32) = (unsigned int)"lug" >> 16;
    v26 = api_add_data_full(v31, v32, api_data_type::API_STRING, szuser, 0);
  }
  print_data(io_data, v26, v6, v6);
  if ( v7 )
    io_data->close = 1;
}
