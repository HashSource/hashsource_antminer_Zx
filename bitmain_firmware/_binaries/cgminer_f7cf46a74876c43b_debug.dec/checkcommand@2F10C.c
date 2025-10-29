void __fastcall checkcommand(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r6
  char *name; // r3
  CMDS *v9; // r4
  char *v10; // t1
  const __int32_t **v11; // r0
  __int32_t v12; // r3
  _BOOL4 v13; // r5
  api_data *v14; // r0
  char *v15; // r3
  api_data *v16; // r0
  _BOOL4 v17; // r0
  char *v18; // r3
  _BOOL4 v19; // r0
  _BOOL4 v20; // r0
  char cmdbuf[100]; // [sp+Ch] [bp-64h] BYREF

  v5 = isjson;
  if ( param && *param )
  {
    name = cmds[0].name;
    if ( cmds[0].name )
    {
      v9 = cmds;
      while ( strcmp(name, param) )
      {
        v10 = v9[1].name;
        ++v9;
        name = v10;
        if ( !v10 )
        {
          message(io_data, 72, 0, 0, v5);
          if ( !v5 )
            goto LABEL_20;
          goto LABEL_17;
        }
      }
      sprintf(cmdbuf, "|%s|", param);
      v11 = _ctype_toupper_loc();
      v12 = (*v11)[(unsigned __int8)group];
      if ( v12 == (*v11)[87] || strstr(apigroups[v12 - (*v11)[65]].commands, cmdbuf) )
      {
        message(io_data, 72, 0, 0, v5);
        if ( v5 )
          v13 = io_add(io_data, ",\"CHECK\":[");
        else
          v13 = io_add(io_data, "CHECK,");
        v14 = api_add_data_full(0, "Exists", api_data_type::API_CONST, "Y", 0);
        v15 = "Y";
        goto LABEL_12;
      }
      message(io_data, 72, 0, 0, v5);
      if ( v5 )
        v20 = io_add(io_data, ",\"CHECK\":[");
      else
        v20 = io_add(io_data, "CHECK,");
      v18 = "Y";
      v13 = v20;
    }
    else
    {
      message(io_data, 72, 0, 0, v5);
      if ( v5 )
      {
LABEL_17:
        v17 = io_add(io_data, ",\"CHECK\":[");
        v18 = "N";
        v13 = v17;
      }
      else
      {
LABEL_20:
        v19 = io_add(io_data, "CHECK,");
        v18 = "N";
        v13 = v19;
      }
    }
    v14 = api_add_data_full(0, "Exists", api_data_type::API_CONST, v18, 0);
    v15 = "N";
LABEL_12:
    v16 = api_add_data_full(v14, "Access", api_data_type::API_CONST, v15, 0);
    print_data(io_data, v16, v5, 0);
    if ( v5 && v13 )
      io_data->close = 1;
  }
  else
  {
    message(io_data, 71, 0, 0, isjson);
  }
}
