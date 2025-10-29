void __fastcall debugstate(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v6; // r4
  int v8; // r2
  _BOOL4 v9; // r3
  char *v10; // r1
  _BOOL4 v11; // r0
  char *v12; // r1
  _BOOL4 v13; // r6
  api_data *v14; // r0
  char *v15; // r1
  api_data *v16; // r0
  char *v17; // r1
  api_data *v18; // r0
  char *v19; // r1
  api_data *v20; // r0
  char *v21; // r1
  api_data *v22; // r0
  char *v23; // r1
  api_data *v24; // r0
  char *v25; // r1
  api_data *v26; // r0
  char *v27; // r1
  char *v28; // r1
  api_data *v29; // r0
  char *v30; // r1
  api_data *v31; // r0
  char *v32; // r1
  api_data *v33; // r0
  char *v34; // r1
  api_data *v35; // r0
  char *v36; // r1
  api_data *v37; // r0
  char *v38; // r1
  api_data *v39; // r0
  char *v40; // r1
  api_data *v41; // r1
  _BOOL4 v42; // r3
  _BOOL4 v43; // r3

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
        v42 = !opt_protocol;
        opt_protocol ^= 1u;
        if ( v42 )
          goto LABEL_4;
        break;
      case 's':
        opt_realquiet = 1;
        break;
      case 'v':
        v43 = !opt_log_output;
        opt_log_output ^= 1u;
        if ( v43 )
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
    LOWORD(v10) = 21756;
    HIWORD(v10) = (unsigned int)"ATUS\":[" >> 16;
    v11 = io_add(io_data, v10);
    LOWORD(v12) = 21768;
    v13 = v11;
    HIWORD(v12) = (unsigned int)"US" >> 16;
    v14 = api_add_data_full(0, v12, api_data_type::API_BOOL, &opt_realquiet, 0);
    LOWORD(v15) = 21776;
    HIWORD(v15) = (unsigned int)"" >> 16;
    v16 = api_add_data_full(v14, v15, api_data_type::API_BOOL, &opt_quiet, 0);
    LOWORD(v17) = 21784;
    HIWORD(v17) = (unsigned int)"" >> 16;
    v18 = api_add_data_full(v16, v17, api_data_type::API_BOOL, &opt_log_output, 0);
    LOWORD(v19) = 21792;
    HIWORD(v19) = (unsigned int)"Description" >> 16;
    v20 = api_add_data_full(v18, v19, api_data_type::API_BOOL, &opt_debug, 0);
    LOWORD(v21) = 21800;
    HIWORD(v21) = (unsigned int)"ion" >> 16;
    v22 = api_add_data_full(v20, v21, api_data_type::API_BOOL, &opt_protocol, 0);
    LOWORD(v23) = 21812;
    HIWORD(v23) = (unsigned int)"BestShare" >> 16;
    v24 = api_add_data_full(v22, v23, api_data_type::API_BOOL, &want_per_device_stats, 0);
    LOWORD(v25) = 21824;
    HIWORD(v25) = (unsigned int)"all" >> 16;
    v26 = api_add_data_full(v24, v25, api_data_type::API_BOOL, &opt_worktime, 0);
    print_data(io_data, v26, 1, 0);
    if ( v13 )
      io_data->close = 1;
  }
  else
  {
    LOWORD(v27) = 21836;
    HIWORD(v27) = (unsigned int)"e" >> 16;
    io_add(io_data, v27);
    LOWORD(v28) = 21768;
    HIWORD(v28) = (unsigned int)"US" >> 16;
    v29 = api_add_data_full(0, v28, api_data_type::API_BOOL, &opt_realquiet, 0);
    LOWORD(v30) = 21776;
    HIWORD(v30) = (unsigned int)"" >> 16;
    v31 = api_add_data_full(v29, v30, api_data_type::API_BOOL, &opt_quiet, 0);
    LOWORD(v32) = 21784;
    HIWORD(v32) = (unsigned int)"" >> 16;
    v33 = api_add_data_full(v31, v32, api_data_type::API_BOOL, &opt_log_output, 0);
    LOWORD(v34) = 21792;
    HIWORD(v34) = (unsigned int)"Description" >> 16;
    v35 = api_add_data_full(v33, v34, api_data_type::API_BOOL, &opt_debug, 0);
    LOWORD(v36) = 21800;
    HIWORD(v36) = (unsigned int)"ion" >> 16;
    v37 = api_add_data_full(v35, v36, api_data_type::API_BOOL, &opt_protocol, 0);
    LOWORD(v38) = 21812;
    HIWORD(v38) = (unsigned int)"BestShare" >> 16;
    v39 = api_add_data_full(v37, v38, api_data_type::API_BOOL, &want_per_device_stats, 0);
    LOWORD(v40) = 21824;
    HIWORD(v40) = (unsigned int)"all" >> 16;
    v41 = api_add_data_full(v39, v40, api_data_type::API_BOOL, &opt_worktime, 0);
    print_data(io_data, v41, 0, 0);
  }
}
