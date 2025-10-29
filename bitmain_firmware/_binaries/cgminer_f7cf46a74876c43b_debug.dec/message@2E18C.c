void __fastcall message(io_data *io_data, int messageid, int paramid, char *param2, bool isjson)
{
  code_severity v8; // r1
  CODES *v9; // r3
  int v10; // r0
  api_data *v11; // r0
  api_data *v12; // r0
  api_data *v13; // r7
  char *v14; // r1
  api_data *v15; // r0
  api_data *v16; // r0
  api_data *v17; // r0
  __int64 v18; // kr00_8
  api_data *v19; // r0
  api_data *v20; // r0
  char *v21; // r2
  int messageida; // [sp+Ch] [bp-200Ch] BYREF
  char severity[4]; // [sp+10h] [bp-2008h] BYREF
  int id; // [sp+14h] [bp-2004h] BYREF
  char buf[8192]; // [sp+18h] [bp-2000h] BYREF

  messageida = messageid;
  if ( isjson )
    io_add(io_data, "{\"STATUS\":[");
  v8 = codes[0].severity;
  if ( codes[0].severity == code_severity::SEVERITY_FAIL )
  {
LABEL_9:
    v11 = api_add_data_full(0, "STATUS", api_data_type::API_STRING, "F", 0);
    v12 = api_add_data_full(v11, "When", api_data_type::API_TIME, &when, 0);
    id = -1;
    v13 = api_add_data_full(v12, "Code", api_data_type::API_INT, &id, 0);
    sprintf(buf, "%d", messageida);
    LOWORD(v14) = (unsigned __int16)"Msg";
    v15 = v13;
    goto LABEL_10;
  }
  if ( codes[0].code != messageida )
  {
    v9 = codes;
    v10 = 0;
    while ( 1 )
    {
      v8 = v9[1].severity;
      ++v10;
      ++v9;
      if ( v8 == code_severity::SEVERITY_FAIL )
        goto LABEL_9;
      if ( v9->code == messageida )
        goto LABEL_13;
    }
  }
  v10 = 0;
LABEL_13:
  switch ( v8 )
  {
    case code_severity::SEVERITY_INFO:
      severity[0] = 73;
      break;
    case code_severity::SEVERITY_SUCC:
      severity[0] = 83;
      break;
    case code_severity::SEVERITY_WARN:
      severity[0] = 87;
      break;
    default:
      severity[0] = 69;
      break;
  }
  severity[1] = 0;
  v18 = *(_QWORD *)&codes[v10].params;
  switch ( (int)v18 )
  {
    case 0:
    case 1:
    case 2:
    case 14:
      sprintf(buf, (const char *)HIDWORD(v18), paramid);
      break;
    case 5:
      sprintf(buf, (const char *)HIDWORD(v18), total_pools);
      break;
    case 6:
      sprintf(buf, (const char *)HIDWORD(v18), paramid, total_pools - 1);
      break;
    case 7:
      sprintf(buf, (const char *)HIDWORD(v18));
      break;
    case 8:
      sprintf(buf, (const char *)HIDWORD(v18), "command");
      break;
    case 9:
      sprintf(buf, (const char *)HIDWORD(v18), paramid, pools[paramid]->rpc_url);
      break;
    case 10:
      sprintf(buf, (const char *)HIDWORD(v18), param2);
      break;
    case 11:
      sprintf(buf, (const char *)HIDWORD(v18), paramid, param2);
      break;
    case 12:
      v21 = "false";
      if ( paramid )
        v21 = "true";
      sprintf(buf, (const char *)HIDWORD(v18), v21, "true");
      break;
    case 13:
      sprintf(buf, (const char *)HIDWORD(v18), param2, paramid);
      break;
    default:
      strcpy(buf, (const char *)HIDWORD(v18));
      break;
  }
  v19 = api_add_data_full(0, "STATUS", api_data_type::API_STRING, severity, 0);
  v20 = api_add_data_full(v19, "When", api_data_type::API_TIME, &when, 0);
  v15 = api_add_data_full(v20, "Code", api_data_type::API_INT, &messageida, 0);
  LOWORD(v14) = 21536;
LABEL_10:
  HIWORD(v14) = (unsigned int)"Msg" >> 16;
  v16 = api_add_data_full(v15, v14, api_data_type::API_ESCAPE, buf, 0);
  v17 = api_add_data_full(v16, "Description", api_data_type::API_ESCAPE, opt_api_description, 0);
  print_data(io_data, v17, isjson, 0);
  if ( isjson )
    io_add(io_data, (char *)&word_59A90);
}
