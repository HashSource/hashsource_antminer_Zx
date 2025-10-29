void __fastcall debugstate(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v6; // r4
  int v8; // r2
  _BOOL4 v9; // r3
  _BOOL4 v10; // r6
  api_data *v11; // r0
  api_data *v12; // r0
  api_data *v13; // r0
  api_data *v14; // r0
  api_data *v15; // r0
  api_data *v16; // r0
  api_data *v17; // r0
  api_data *v18; // r0
  api_data *v19; // r0
  api_data *v20; // r0
  api_data *v21; // r0
  api_data *v22; // r0
  api_data *v23; // r0
  api_data *v24; // r1
  _BOOL4 v25; // r3
  _BOOL4 v26; // r3

  v6 = isjson;
  if ( param )
  {
    v8 = LOBYTE((*_ctype_tolower_loc())[(unsigned __int8)*param]);
    *param = v8;
    switch ( v8 )
    {
      case 'd':
        v9 = !opt_debug;
        opt_debug = v9;
        opt_log_output = v9;
        if ( v9 )
          goto LABEL_4;
        break;
      case 'n':
        opt_log_output = 0;
        opt_debug = 0;
        opt_quiet = 0;
        opt_protocol = 0;
        want_per_device_stats = 0;
        opt_worktime = 0;
        break;
      case 'p':
        want_per_device_stats ^= 1u;
        opt_log_output = want_per_device_stats;
        break;
      case 'q':
        opt_quiet ^= 1u;
        break;
      case 'r':
        v25 = !opt_protocol;
        opt_protocol ^= 1u;
        if ( v25 )
          goto LABEL_4;
        break;
      case 's':
        opt_realquiet = 1;
        break;
      case 'v':
        v26 = !opt_log_output;
        opt_log_output ^= 1u;
        if ( v26 )
LABEL_4:
          opt_quiet = 0;
        break;
      case 'w':
        opt_worktime ^= 1u;
        break;
      default:
        break;
    }
  }
  message(io_data, 79, 0, 0, v6);
  if ( v6 )
  {
    v10 = io_add(io_data, ",\"DEBUG\":[");
    v11 = api_add_data_full(0, "Silent", api_data_type::API_BOOL, &opt_realquiet, 0);
    v12 = api_add_data_full(v11, "Quiet", api_data_type::API_BOOL, &opt_quiet, 0);
    v13 = api_add_data_full(v12, "Verbose", api_data_type::API_BOOL, &opt_log_output, 0);
    v14 = api_add_data_full(v13, "Debug", api_data_type::API_BOOL, &opt_debug, 0);
    v15 = api_add_data_full(v14, "RPCProto", api_data_type::API_BOOL, &opt_protocol, 0);
    v16 = api_add_data_full(v15, "PerDevice", api_data_type::API_BOOL, &want_per_device_stats, 0);
    v17 = api_add_data_full(v16, "WorkTime", api_data_type::API_BOOL, &opt_worktime, 0);
    print_data(io_data, v17, 1, 0);
    if ( v10 )
      io_data->close = 1;
  }
  else
  {
    io_add(io_data, "DEBUG,");
    v18 = api_add_data_full(0, "Silent", api_data_type::API_BOOL, &opt_realquiet, 0);
    v19 = api_add_data_full(v18, "Quiet", api_data_type::API_BOOL, &opt_quiet, 0);
    v20 = api_add_data_full(v19, "Verbose", api_data_type::API_BOOL, &opt_log_output, 0);
    v21 = api_add_data_full(v20, "Debug", api_data_type::API_BOOL, &opt_debug, 0);
    v22 = api_add_data_full(v21, "RPCProto", api_data_type::API_BOOL, &opt_protocol, 0);
    v23 = api_add_data_full(v22, "PerDevice", api_data_type::API_BOOL, &want_per_device_stats, 0);
    v24 = api_add_data_full(v23, "WorkTime", api_data_type::API_BOOL, &opt_worktime, 0);
    print_data(io_data, v24, 0, 0);
  }
}
