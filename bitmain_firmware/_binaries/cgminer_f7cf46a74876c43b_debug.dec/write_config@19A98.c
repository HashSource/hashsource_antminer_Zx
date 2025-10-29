void __fastcall write_config(FILE *fcfg)
{
  int v2; // r6
  const char *v3; // r10
  char *v4; // r0
  char *v5; // r11
  char *v6; // r0
  char *v7; // r0
  __int16 *v8; // r2
  int quota; // r3
  char *v10; // r0
  char *v11; // r0
  char *v12; // r0
  pool *v13; // r0
  pool *v14; // r4
  const char *v15; // r10
  char *v16; // r0
  char *v17; // r11
  char *rpc_proxy; // r0
  char *v19; // r2
  __int16 *v20; // r3
  char *v21; // r0
  char *v22; // r0
  opt_table *v23; // r4
  char *v24; // r8
  char *v25; // r11
  char *(__fastcall *cb_arg)(const char *, int *); // r2
  bool v27; // zf
  int v28; // r3
  opt_type type; // r1
  char *(__fastcall *cb)(bool *); // r2
  bool v31; // zf
  char **carg; // r3
  char *v33; // r0
  pool_strategy v34; // r1
  JE *next; // r4
  JE v36; // kr00_8
  JE *v37; // r0
  bool v38; // zf
  const char *v39; // [sp+14h] [bp-10h]
  const char *v40; // [sp+14h] [bp-10h]
  int v41; // [sp+18h] [bp-Ch]
  const char *v42; // [sp+18h] [bp-Ch]
  const char *v43; // [sp+1Ch] [bp-8h]

  fwrite("{\n\"pools\" : [", 1u, 0xDu, fcfg);
  if ( total_pools > 0 )
  {
    v2 = 0;
    do
    {
      v13 = priority_pool(v2);
      quota = v13->quota;
      v14 = v13;
      if ( quota == 1 )
      {
        if ( v2 )
          v15 = ",";
        else
          v15 = &byte_59398;
        if ( v13->rpc_proxy )
        {
          v16 = (char *)proxytype(v13->rpc_proxytype);
          v17 = json_escape(v16);
          rpc_proxy = v14->rpc_proxy;
          v19 = &byte_59398;
          v20 = (__int16 *)&byte_59398;
          if ( rpc_proxy )
          {
            v21 = json_escape(rpc_proxy);
            v20 = &word_4F67C;
            v19 = v21;
            if ( !v14->rpc_proxy )
              v20 = (__int16 *)&byte_59398;
          }
        }
        else
        {
          v19 = &byte_59398;
          v17 = &byte_59398;
          v20 = (__int16 *)&byte_59398;
        }
        v40 = (const char *)v20;
        v42 = v19;
        v22 = json_escape(v14->rpc_url);
        fprintf(fcfg, "%s\n\t{\n\t\t\"url\" : \"%s%s%s%s\",", v15, v17, v42, v40, v22);
      }
      else
      {
        if ( v2 )
          v3 = ",";
        else
          v3 = &byte_59398;
        if ( v13->rpc_proxy )
        {
          v4 = (char *)proxytype(v13->rpc_proxytype);
          v5 = json_escape(v4);
          v6 = v14->rpc_proxy;
          if ( v6 )
          {
            v7 = json_escape(v6);
            v8 = &word_4F67C;
            quota = v14->quota;
            v39 = v7;
            if ( !v14->rpc_proxy )
              v8 = (__int16 *)&byte_59398;
          }
          else
          {
            quota = v14->quota;
            v8 = (__int16 *)&byte_59398;
            v39 = &byte_59398;
          }
        }
        else
        {
          v39 = &byte_59398;
          v5 = &byte_59398;
          v8 = (__int16 *)&byte_59398;
        }
        v41 = quota;
        v43 = (const char *)v8;
        v10 = json_escape(v14->rpc_url);
        fprintf(fcfg, "%s\n\t{\n\t\t\"quota\" : \"%s%s%s%d;%s\",", v3, v5, v39, v43, v41, v10);
      }
      ++v2;
      v11 = json_escape(v14->rpc_user);
      fprintf(fcfg, "\n\t\t\"user\" : \"%s\",", v11);
      v12 = json_escape(v14->rpc_pass);
      fprintf(fcfg, "\n\t\t\"pass\" : \"%s\"\n\t}", v12);
    }
    while ( total_pools > v2 );
  }
  fwrite("\n]\n", 1u, 3u, fcfg);
  if ( opt_config_table[0].type != opt_type::OPT_END )
  {
    v23 = &opt_config_table[1];
    while ( 1 )
    {
      v24 = _strdup(v23[-1].names);
      v25 = strtok(v24, (const char *)&word_4F67C);
      if ( v25 )
        break;
LABEL_67:
      ++v23;
      free(v24);
      if ( v23[-1].type == opt_type::OPT_END )
        goto LABEL_68;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        if ( v25[1] != 45 || v23[-1].desc == opt_hidden )
          goto LABEL_53;
        type = v23[-1].type;
        if ( (type & 1) != 0 )
        {
          cb = (char *(__fastcall *)(bool *))v23[-1].cb;
          v31 = cb == opt_set_bool;
          if ( cb != opt_set_bool )
            v31 = cb == opt_set_invbool;
          if ( v31 && *(_BYTE *)v23[-1].u.carg == (cb == opt_set_bool) )
          {
            fprintf(fcfg, ",\n\"%s\" : true", v25 + 2);
            goto LABEL_53;
          }
        }
        if ( (type & 2) == 0 )
          goto LABEL_63;
        cb_arg = (char *(__fastcall *)(const char *, int *))v23[-1].cb_arg;
        v27 = cb_arg == set_int_0_to_9999;
        if ( cb_arg != set_int_0_to_9999 )
          v27 = cb_arg == opt_set_intval;
        v28 = v27;
        if ( cb_arg == set_int_1_to_65535 )
          v28 |= 1u;
        if ( cb_arg == set_int_0_to_10 )
          v28 |= 1u;
        if ( cb_arg == set_int_1_to_10 )
          v28 |= 1u;
        if ( cb_arg == set_int_0_to_100 )
          v28 |= 1u;
        if ( cb_arg == set_int_0_to_255 )
          v28 |= 1u;
        if ( cb_arg == set_int_0_to_200 )
          v28 |= 1u;
        if ( cb_arg == set_int_0_to_4 )
          v28 |= 1u;
        if ( cb_arg == set_int_32_to_63 )
          v28 |= 1u;
        if ( cb_arg == set_int_22_to_55 )
          v28 |= 1u;
        if ( cb_arg == set_int_42_to_65 )
          v28 |= 1u;
        if ( !v28 )
          break;
        fprintf(fcfg, ",\n\"%s\" : \"%d\"", v25 + 2, *(_DWORD *)v23[-1].u.carg);
LABEL_53:
        v25 = strtok(0, (const char *)&word_4F67C);
        if ( !v25 )
          goto LABEL_67;
      }
      v38 = (char *)cb_arg == (char *)set_float_100_to_250;
      if ( (char *)cb_arg != (char *)set_float_100_to_250 )
        v38 = (char *)cb_arg == (char *)set_float_125_to_500;
      if ( v38 )
      {
        fprintf(fcfg, ",\n\"%s\" : \"%.1f\"", v25 + 2, *(float *)v23[-1].u.carg);
        goto LABEL_53;
      }
LABEL_63:
      if ( (type & 6) == 0 )
        goto LABEL_53;
      carg = (char **)v23[-1].u.carg;
      if ( carg == &opt_set_null || !*carg )
        goto LABEL_53;
      v33 = json_escape(*carg);
      fprintf(fcfg, ",\n\"%s\" : \"%s\"", v25 + 2, v33);
      v25 = strtok(0, (const char *)&word_4F67C);
      if ( !v25 )
        goto LABEL_67;
    }
  }
LABEL_68:
  v34 = pool_strategy_0;
  if ( pool_strategy_0 == pool_strategy::POOL_BALANCE )
  {
    fwrite(",\n\"balance\" : true", 1u, 0x12u, fcfg);
    v34 = pool_strategy_0;
  }
  if ( v34 == pool_strategy::POOL_LOADBALANCE )
  {
    fwrite(",\n\"load-balance\" : true", 1u, 0x17u, fcfg);
    v34 = pool_strategy_0;
  }
  if ( v34 == pool_strategy::POOL_ROUNDROBIN )
  {
    fwrite(",\n\"round-robin\" : true", 1u, 0x16u, fcfg);
    v34 = pool_strategy_0;
  }
  if ( v34 == pool_strategy::POOL_ROTATE )
    fprintf(fcfg, ",\n\"rotate\" : \"%d\"", opt_rotate_period);
  fwrite("\n}\n", 1u, 3u, fcfg);
  next = jedata;
  jedata = 0;
  if ( next )
  {
    do
    {
      v36 = *next;
      free(next->buf);
      v37 = next;
      next = v36.next;
      free(v37);
    }
    while ( v36.next );
  }
}
