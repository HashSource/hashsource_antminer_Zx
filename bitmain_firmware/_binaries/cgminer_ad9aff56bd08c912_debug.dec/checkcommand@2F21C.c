void __fastcall checkcommand(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r6
  char *name; // r3
  CMDS *v9; // r4
  char *v10; // t1
  const char *v11; // r1
  const __int32_t **v12; // r0
  __int32_t v13; // r3
  char *v14; // r1
  _BOOL4 v15; // r5
  void *v16; // r3
  char *v17; // r1
  api_data *v18; // r0
  char *v19; // r3
  char *v20; // r1
  api_data *v21; // r0
  char *v22; // r1
  _BOOL4 v23; // r0
  void *v24; // r3
  char *v25; // r1
  char *v26; // r1
  _BOOL4 v27; // r0
  char *v28; // r1
  _BOOL4 v29; // r0
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
      LOWORD(v11) = 21852;
      HIWORD(v11) = (unsigned int)"expiry" >> 16;
      sprintf(cmdbuf, v11, param);
      v12 = _ctype_toupper_loc();
      v13 = (*v12)[(unsigned __int8)group];
      if ( v13 == (*v12)[87] || strstr(apigroups[v13 - (*v12)[65]].commands, cmdbuf) )
      {
        message(io_data, 72, 0, 0, v5);
        if ( v5 )
        {
          LOWORD(v14) = 21860;
          HIWORD(v14) = (unsigned int)",\"ASCS\":[" >> 16;
        }
        else
        {
          LOWORD(v14) = 21872;
          HIWORD(v14) = (unsigned int)"ASCS," >> 16;
        }
        v15 = io_add(io_data, v14);
        LOWORD(v16) = 21844;
        LOWORD(v17) = 21888;
        HIWORD(v16) = (unsigned int)"time" >> 16;
        HIWORD(v17) = (unsigned int)":[" >> 16;
        v18 = api_add_data_full(0, v17, api_data_type::API_CONST, v16, 0);
        v19 = "Y";
        goto LABEL_12;
      }
      message(io_data, 72, 0, 0, v5);
      if ( v5 )
      {
        LOWORD(v28) = 21860;
        HIWORD(v28) = (unsigned int)",\"ASCS\":[" >> 16;
      }
      else
      {
        LOWORD(v28) = 21872;
        HIWORD(v28) = (unsigned int)"ASCS," >> 16;
      }
      v29 = io_add(io_data, v28);
      LOWORD(v24) = 21844;
      v15 = v29;
      HIWORD(v24) = (unsigned int)"time" >> 16;
    }
    else
    {
      message(io_data, 72, 0, 0, v5);
      if ( v5 )
      {
LABEL_17:
        LOWORD(v22) = 21860;
        HIWORD(v22) = (unsigned int)",\"ASCS\":[" >> 16;
        v23 = io_add(io_data, v22);
        LOWORD(v24) = 21848;
        v15 = v23;
        HIWORD(v24) = (unsigned int)"" >> 16;
      }
      else
      {
LABEL_20:
        LOWORD(v26) = 21872;
        HIWORD(v26) = (unsigned int)"ASCS," >> 16;
        v27 = io_add(io_data, v26);
        LOWORD(v24) = 21848;
        v15 = v27;
        HIWORD(v24) = (unsigned int)"" >> 16;
      }
    }
    LOWORD(v25) = 21888;
    HIWORD(v25) = (unsigned int)":[" >> 16;
    v18 = api_add_data_full(0, v25, api_data_type::API_CONST, v24, 0);
    v19 = "N";
LABEL_12:
    LOWORD(v20) = 21880;
    HIWORD(v20) = (unsigned int)",\"DEBUG\":[" >> 16;
    v21 = api_add_data_full(v18, v20, api_data_type::API_CONST, v19, 0);
    print_data(io_data, v21, v5, 0);
    if ( v5 && v15 )
      io_data->close = 1;
  }
  else
  {
    message(io_data, 71, 0, 0, isjson);
  }
}
