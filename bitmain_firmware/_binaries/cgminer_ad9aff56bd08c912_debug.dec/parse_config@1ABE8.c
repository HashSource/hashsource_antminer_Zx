char *__fastcall parse_config(const json_t *a1, int a2)
{
  opt_table *v3; // r5
  const char *v4; // r6
  opt_type type; // r3
  const char *names; // r0
  char *v7; // r9
  char *v8; // r4
  json_t *v9; // r0
  const json_t *v10; // r7
  opt_type v11; // r3
  char *v12; // r3
  const char *v13; // r1
  json_t *v14; // r0
  const char *v15; // r0
  const char *v17; // r2
  const char *v18; // r7
  int v19; // r0
  size_t v20; // r4
  json_t *v21; // r0
  int v22; // r0
  const char *v23; // r1
  const char *v24; // r0
  char *v26; // [sp+14h] [bp-1010h]
  char *v27; // [sp+14h] [bp-1010h]
  char *arg; // [sp+18h] [bp-100Ch]
  char *v29; // [sp+1Ch] [bp-1008h]
  char s[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( a2 && !fileconf_load )
    fileconf_load = 1;
  if ( opt_config_table[0].type == opt_type::OPT_END )
    goto LABEL_29;
  if ( (opt_config_table[0].type & 8) != 0 )
  {
LABEL_51:
    LOWORD(v23) = -3136;
    LOWORD(v24) = -1656;
    HIWORD(v23) = (unsigned int)"iner" >> 16;
    HIWORD(v24) = (unsigned int)"10) or a loop" >> 16;
    _assert_fail(v24, v23, 0x7A0u, "parse_config");
  }
  LOWORD(v4) = -2396;
  v3 = &opt_config_table[1];
  HIWORD(v4) = (unsigned int)"ation" >> 16;
  while ( 1 )
  {
    names = v3[-1].names;
    if ( !names )
    {
      type = v3->type;
      if ( type == opt_type::OPT_END )
        break;
      goto LABEL_8;
    }
    v7 = _strdup(names);
    v8 = strtok(v7, v4);
    if ( v8 )
    {
      while ( 1 )
      {
        if ( v8[1] != 45 )
          goto LABEL_12;
        v9 = json_object_get(a1, v8 + 2);
        v10 = v9;
        if ( !v9 )
          goto LABEL_12;
        v11 = v3[-1].type;
        if ( (v11 & 6) != 0 )
        {
          if ( v9->type != JSON_STRING )
          {
            if ( v9->type == JSON_ARRAY )
            {
              v27 = v8;
              v20 = 0;
              if ( json_array_size(v9) )
              {
                while ( 1 )
                {
                  v21 = json_array_get(v10, v20);
                  if ( !v21 )
                    goto LABEL_12;
                  if ( v21->type == JSON_STRING )
                  {
                    arg = (char *)json_string_value(v21);
                    v22 = (int)v3[-1].cb_arg(arg, v3[-1].u.arg);
                    v12 = (char *)v22;
                    if ( v3[-1].type == opt_type::OPT_PROCESSARG )
                    {
                      v29 = (char *)v22;
                      opt_set_charp(arg, (char **)v3[-1].u.carg);
                      v12 = v29;
                      if ( v29 )
                        goto LABEL_46;
                    }
                    else if ( v22 )
                    {
                      goto LABEL_46;
                    }
                  }
                  else if ( v21->type == JSON_OBJECT )
                  {
                    v12 = parse_config(v21, 0);
                    if ( v12 )
                    {
LABEL_46:
                      v8 = v27;
                      goto LABEL_22;
                    }
                  }
                  if ( json_array_size(v10) <= ++v20 )
                    goto LABEL_12;
                }
              }
              goto LABEL_12;
            }
            goto LABEL_18;
          }
          v18 = json_string_value(v9);
          v19 = (int)v3[-1].cb_arg(v18, v3[-1].u.arg);
          v12 = (char *)v19;
          if ( v3[-1].type != opt_type::OPT_PROCESSARG )
            goto LABEL_21;
          v26 = (char *)v19;
          opt_set_charp(v18, (char **)v3[-1].u.carg);
          v12 = v26;
          if ( v26 )
          {
LABEL_22:
            if ( !a2 )
              goto LABEL_33;
            goto LABEL_23;
          }
LABEL_12:
          v8 = strtok(0, v4);
          if ( !v8 )
            break;
        }
        else
        {
LABEL_18:
          if ( (v11 & 1) != 0 && v9->type == JSON_TRUE )
          {
            v12 = v3[-1].cb(v3[-1].u.tlen);
LABEL_21:
            if ( v12 )
              goto LABEL_22;
            goto LABEL_12;
          }
          v12 = "Invalid value";
          if ( !a2 )
          {
LABEL_33:
            LOWORD(v17) = -1596;
            HIWORD(v17) = (unsigned int)"BTABLE)" >> 16;
            snprintf(err_buf_15170, 0xC8u, v17, v8, v12);
            return err_buf_15170;
          }
LABEL_23:
          if ( use_syslog || opt_log_output || opt_log_level > 2 )
          {
            snprintf(s, 0x1000u, "Invalid config option %s: %s", v8, v12);
            applog(3, s, 0);
          }
          fileconf_load = -1;
          v8 = strtok(0, v4);
          if ( !v8 )
            break;
        }
      }
    }
    free(v7);
    type = v3->type;
    if ( type == opt_type::OPT_END )
      break;
LABEL_8:
    ++v3;
    if ( (type & 8) != 0 )
      goto LABEL_51;
  }
LABEL_29:
  LOWORD(v13) = -1664;
  HIWORD(v13) = (unsigned int)" (limit 10) or a loop" >> 16;
  v14 = json_object_get(a1, v13);
  if ( !v14 || v14->type != JSON_STRING )
    return 0;
  v15 = json_string_value(v14);
  return load_config(v15, 0);
}
