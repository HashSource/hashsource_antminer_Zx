char *__fastcall parse_config(const json_t *a1, int a2)
{
  opt_table *v3; // r5
  opt_type type; // r3
  const char *names; // r0
  char *v6; // r9
  char *v7; // r4
  json_t *v8; // r0
  const json_t *v9; // r7
  opt_type v10; // r3
  char *v11; // r3
  json_t *v12; // r0
  const char *v13; // r0
  const char *v15; // r7
  int v16; // r0
  size_t v17; // r4
  json_t *v18; // r0
  int v19; // r0
  char *v21; // [sp+14h] [bp-1010h]
  char *v22; // [sp+14h] [bp-1010h]
  char *arg; // [sp+18h] [bp-100Ch]
  char *v24; // [sp+1Ch] [bp-1008h]
  char s[4100]; // [sp+20h] [bp-1004h] BYREF

  if ( a2 && !fileconf_load )
    fileconf_load = 1;
  if ( opt_config_table[0].type == opt_type::OPT_END )
    goto LABEL_29;
  if ( (opt_config_table[0].type & 8) != 0 )
LABEL_51:
    _assert_fail("!(opt->type & OPT_SUBTABLE)", "cgminer.c", 0x7A0u, "parse_config");
  v3 = &opt_config_table[1];
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
    v6 = _strdup(names);
    v7 = strtok(v6, (const char *)&word_4F67C);
    if ( v7 )
    {
      while ( 1 )
      {
        if ( v7[1] != 45 )
          goto LABEL_12;
        v8 = json_object_get(a1, v7 + 2);
        v9 = v8;
        if ( !v8 )
          goto LABEL_12;
        v10 = v3[-1].type;
        if ( (v10 & 6) != 0 )
        {
          if ( v8->type != JSON_STRING )
          {
            if ( v8->type == JSON_ARRAY )
            {
              v22 = v7;
              v17 = 0;
              if ( json_array_size(v8) )
              {
                while ( 1 )
                {
                  v18 = json_array_get(v9, v17);
                  if ( !v18 )
                    goto LABEL_12;
                  if ( v18->type == JSON_STRING )
                  {
                    arg = (char *)json_string_value(v18);
                    v19 = (int)v3[-1].cb_arg(arg, v3[-1].u.arg);
                    v11 = (char *)v19;
                    if ( v3[-1].type == opt_type::OPT_PROCESSARG )
                    {
                      v24 = (char *)v19;
                      opt_set_charp(arg, (char **)v3[-1].u.carg);
                      v11 = v24;
                      if ( v24 )
                        goto LABEL_46;
                    }
                    else if ( v19 )
                    {
                      goto LABEL_46;
                    }
                  }
                  else if ( v18->type == JSON_OBJECT )
                  {
                    v11 = parse_config(v18, 0);
                    if ( v11 )
                    {
LABEL_46:
                      v7 = v22;
                      goto LABEL_22;
                    }
                  }
                  if ( json_array_size(v9) <= ++v17 )
                    goto LABEL_12;
                }
              }
              goto LABEL_12;
            }
            goto LABEL_18;
          }
          v15 = json_string_value(v8);
          v16 = (int)v3[-1].cb_arg(v15, v3[-1].u.arg);
          v11 = (char *)v16;
          if ( v3[-1].type != opt_type::OPT_PROCESSARG )
            goto LABEL_21;
          v21 = (char *)v16;
          opt_set_charp(v15, (char **)v3[-1].u.carg);
          v11 = v21;
          if ( v21 )
          {
LABEL_22:
            if ( !a2 )
              goto LABEL_33;
            goto LABEL_23;
          }
LABEL_12:
          v7 = strtok(0, (const char *)&word_4F67C);
          if ( !v7 )
            break;
        }
        else
        {
LABEL_18:
          if ( (v10 & 1) != 0 && v8->type == JSON_TRUE )
          {
            v11 = v3[-1].cb(v3[-1].u.tlen);
LABEL_21:
            if ( v11 )
              goto LABEL_22;
            goto LABEL_12;
          }
          v11 = "Invalid value";
          if ( !a2 )
          {
LABEL_33:
            snprintf(err_buf_15170, 0xC8u, "Parsing JSON option %s: %s", v7, v11);
            return err_buf_15170;
          }
LABEL_23:
          if ( use_syslog || opt_log_output || opt_log_level > 2 )
          {
            snprintf(s, 0x1000u, "Invalid config option %s: %s", v7, v11);
            applog(3, s, 0);
          }
          fileconf_load = -1;
          v7 = strtok(0, (const char *)&word_4F67C);
          if ( !v7 )
            break;
        }
      }
    }
    free(v6);
    type = v3->type;
    if ( type == opt_type::OPT_END )
      break;
LABEL_8:
    ++v3;
    if ( (type & 8) != 0 )
      goto LABEL_51;
  }
LABEL_29:
  v12 = json_object_get(a1, "include");
  if ( !v12 || v12->type != JSON_STRING )
    return 0;
  v13 = json_string_value(v12);
  return load_config(v13, 0);
}
