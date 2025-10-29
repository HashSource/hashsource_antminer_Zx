void __fastcall pgacount(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r5
  char *v7; // r1
  _BOOL4 v8; // r0
  char *v9; // r1
  _BOOL4 v10; // r5
  api_data *v11; // r0
  char *v12; // r1
  char *v13; // r1
  api_data *v14; // r0
  int count; // [sp+Ch] [bp-4h] BYREF

  v5 = isjson;
  count = 0;
  message(io_data, 59, 0, 0, isjson);
  if ( v5 )
  {
    LOWORD(v7) = 21840;
    HIWORD(v7) = (unsigned int)"r_count" >> 16;
    v8 = io_add(io_data, v7);
    LOWORD(v9) = 21896;
    v10 = v8;
    HIWORD(v9) = (unsigned int)"%d" >> 16;
    v11 = api_add_data_full(0, v9, api_data_type::API_INT, &count, 0);
    print_data(io_data, v11, 1, 0);
    if ( v10 )
      io_data->close = 1;
  }
  else
  {
    LOWORD(v12) = 21852;
    HIWORD(v12) = (unsigned int)"num" >> 16;
    io_add(io_data, v12);
    LOWORD(v13) = 21896;
    HIWORD(v13) = (unsigned int)"%d" >> 16;
    v14 = api_add_data_full(0, v13, api_data_type::API_INT, &count, 0);
    print_data(io_data, v14, 0, 0);
  }
}
