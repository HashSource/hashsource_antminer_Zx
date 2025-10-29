void __fastcall write_config(FILE *fcfg)
{
  const void *v2; // r0
  __int16 *v3; // r7
  __int16 *v4; // r9
  int v5; // r6
  __int16 *v6; // r10
  char *v7; // r0
  char *v8; // r11
  char *v9; // r0
  char *v10; // r0
  int quota; // r3
  __int16 *v12; // r2
  char *v13; // r0
  const char *v14; // r1
  char *v15; // r0
  const char *v16; // r1
  char *v17; // r0
  const char *v18; // r1
  pool *v19; // r0
  pool *v20; // r4
  __int16 *v21; // r10
  char *v22; // r0
  char *v23; // r11
  char *rpc_proxy; // r0
  char *v25; // r2
  __int16 *v26; // r3
  char *v27; // r0
  char *v28; // r0
  const char *v29; // r1
  const void *v30; // r0
  const char *v31; // r10
  opt_table *v32; // r4
  const char *v33; // r6
  char *v34; // r8
  char *v35; // r11
  char *(*cb_arg)(const char *, void *); // r2
  char *(*v37)(const char *, void *); // r3
  char *(*v38)(const char *, void *); // r0
  char *(*v39)(const char *, void *); // r12
  bool v40; // zf
  int v41; // r3
  char *(*v42)(const char *, void *); // r0
  char *(*v43)(const char *, void *); // r12
  char *(*v44)(const char *, void *); // r0
  char *(*v45)(const char *, void *); // r12
  char *(*v46)(const char *, void *); // r0
  char *(*v47)(const char *, void *); // r12
  char *(*v48)(const char *, void *); // r0
  char *(*v49)(const char *, void *); // r12
  char *(*v50)(const char *, void *); // r0
  const char *v51; // r1
  opt_type type; // r1
  char *(*cb)(void *); // r2
  char *(*v54)(void *); // r0
  char *(*v55)(void *); // r3
  bool v56; // zf
  char **carg; // r3
  char *v58; // r0
  pool_strategy v59; // r1
  const void *v60; // r0
  JE *next; // r4
  JE v62; // kr00_8
  JE *v63; // r0
  char *(*v64)(const char *, void *); // r0
  char *(*v65)(const char *, void *); // r3
  bool v66; // zf
  const char *v67; // r1
  const char *v68; // r1
  const char *v69; // r1
  const void *v70; // r0
  const void *v71; // r0
  const void *v72; // r0
  char *v73; // [sp+14h] [bp-10h]
  __int16 *v74; // [sp+14h] [bp-10h]
  int v75; // [sp+18h] [bp-Ch]
  char *v76; // [sp+18h] [bp-Ch]
  __int16 *v77; // [sp+1Ch] [bp-8h]

  LOWORD(v2) = -2392;
  HIWORD(v2) = (unsigned int)"n" >> 16;
  fwrite(v2, 1u, 0xDu, fcfg);
  if ( total_pools > 0 )
  {
    LOWORD(v3) = -27628;
    LOWORD(v4) = -2296;
    HIWORD(v3) = (unsigned int)"c.txt" >> 16;
    HIWORD(v4) = (unsigned int)"{\n\t\t\"url\" : \"%s%s%s%s\"," >> 16;
    v5 = 0;
    do
    {
      v19 = priority_pool(v5);
      quota = v19->quota;
      v20 = v19;
      if ( quota == 1 )
      {
        if ( v5 )
          v21 = v4;
        else
          v21 = v3;
        if ( v19->rpc_proxy )
        {
          v22 = (char *)proxytype(v19->rpc_proxytype);
          v23 = json_escape(v22);
          rpc_proxy = v20->rpc_proxy;
          v25 = (char *)v3;
          v26 = v3;
          if ( rpc_proxy )
          {
            v27 = json_escape(rpc_proxy);
            v26 = &word_4F6A4;
            v25 = v27;
            if ( !v20->rpc_proxy )
              v26 = v3;
          }
        }
        else
        {
          v25 = (char *)v3;
          v23 = (char *)v3;
          v26 = v3;
        }
        v74 = v26;
        v76 = v25;
        v28 = json_escape(v20->rpc_url);
        LOWORD(v29) = -2340;
        HIWORD(v29) = (unsigned int)"[" >> 16;
        fprintf(fcfg, v29, v21, v23, v76, v74, v28);
      }
      else
      {
        if ( v5 )
          v6 = v4;
        else
          v6 = v3;
        if ( v19->rpc_proxy )
        {
          v7 = (char *)proxytype(v19->rpc_proxytype);
          v8 = json_escape(v7);
          v9 = v20->rpc_proxy;
          if ( v9 )
          {
            v10 = json_escape(v9);
            LOWORD(v12) = -2396;
            quota = v20->quota;
            HIWORD(v12) = (unsigned int)"ation" >> 16;
            v73 = v10;
            if ( !v20->rpc_proxy )
              v12 = v3;
          }
          else
          {
            quota = v20->quota;
            v12 = v3;
            v73 = (char *)v3;
          }
        }
        else
        {
          v73 = (char *)v3;
          v8 = (char *)v3;
          v12 = v3;
        }
        v75 = quota;
        v77 = v12;
        v13 = json_escape(v20->rpc_url);
        LOWORD(v14) = -2376;
        HIWORD(v14) = (unsigned int)"oned or rolled work" >> 16;
        fprintf(fcfg, v14, v6, v8, v73, v77, v75, v13);
      }
      ++v5;
      v15 = json_escape(v20->rpc_user);
      LOWORD(v16) = -2312;
      HIWORD(v16) = (unsigned int)"s%d;%s\"," >> 16;
      fprintf(fcfg, v16, v15);
      v17 = json_escape(v20->rpc_pass);
      LOWORD(v18) = -2292;
      HIWORD(v18) = (unsigned int)"\"url\" : \"%s%s%s%s\"," >> 16;
      fprintf(fcfg, v18, v17);
    }
    while ( total_pools > v5 );
  }
  LOWORD(v30) = -2272;
  HIWORD(v30) = (unsigned int)"\n\t\t\"user\" : \"%s\"," >> 16;
  fwrite(v30, 1u, 3u, fcfg);
  if ( opt_config_table[0].type != opt_type::OPT_END )
  {
    LOWORD(v33) = -2396;
    LOWORD(v31) = -2220;
    v32 = &opt_config_table[1];
    HIWORD(v33) = (unsigned int)"ation" >> 16;
    while ( 1 )
    {
      v34 = _strdup(v32[-1].names);
      v35 = strtok(v34, v33);
      if ( v35 )
        break;
LABEL_67:
      ++v32;
      free(v34);
      if ( v32[-1].type == opt_type::OPT_END )
        goto LABEL_68;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        if ( v35[1] != 45 || v32[-1].desc == opt_hidden )
          goto LABEL_53;
        type = v32[-1].type;
        if ( (type & 1) != 0 )
        {
          cb = v32[-1].cb;
          LOWORD(v55) = -21219;
          LOWORD(v54) = -21211;
          HIWORD(v55) = (unsigned int)&loc_4ACEC >> 16;
          v56 = cb == v55;
          if ( cb != v55 )
          {
            HIWORD(v54) = (unsigned int)arg_bad >> 16;
            v56 = cb == v54;
          }
          if ( v56 && *(_BYTE *)v32[-1].u.carg == (cb == v55) )
          {
            LOWORD(v68) = -2268;
            HIWORD(v68) = (unsigned int)"user\" : \"%s\"," >> 16;
            fprintf(fcfg, v68, v35 + 2);
            goto LABEL_53;
          }
        }
        if ( (type & 2) == 0 )
          goto LABEL_63;
        cb_arg = v32[-1].cb_arg;
        LOWORD(v37) = -20915;
        LOWORD(v38) = 29901;
        HIWORD(v38) = ((unsigned int)&loc_17476 + 7) >> 16;
        LOWORD(v39) = 29865;
        v40 = cb_arg == v38;
        if ( cb_arg != v38 )
        {
          HIWORD(v37) = (unsigned int)&loc_4AE1C >> 16;
          v40 = cb_arg == v37;
        }
        v41 = v40;
        LOWORD(v42) = 29833;
        HIWORD(v39) = ((unsigned int)&loc_17456 + 3) >> 16;
        if ( cb_arg == v39 )
          v41 |= 1u;
        HIWORD(v42) = ((unsigned int)&loc_17436 + 3) >> 16;
        LOWORD(v43) = 29801;
        if ( cb_arg == v42 )
          v41 |= 1u;
        HIWORD(v43) = ((unsigned int)&loc_17416 + 3) >> 16;
        LOWORD(v44) = 29769;
        if ( cb_arg == v43 )
          v41 |= 1u;
        HIWORD(v44) = ((unsigned int)&loc_173F6 + 3) >> 16;
        LOWORD(v45) = 29737;
        if ( cb_arg == v44 )
          v41 |= 1u;
        HIWORD(v45) = ((unsigned int)&loc_173D6 + 3) >> 16;
        LOWORD(v46) = 29705;
        if ( cb_arg == v45 )
          v41 |= 1u;
        HIWORD(v46) = ((unsigned int)&loc_173B6 + 3) >> 16;
        LOWORD(v47) = 29673;
        if ( cb_arg == v46 )
          v41 |= 1u;
        HIWORD(v47) = ((unsigned int)&loc_17396 + 3) >> 16;
        LOWORD(v48) = 29641;
        if ( cb_arg == v47 )
          v41 |= 1u;
        HIWORD(v48) = (unsigned int)&loc_17378 >> 16;
        LOWORD(v49) = 29609;
        if ( cb_arg == v48 )
          v41 |= 1u;
        HIWORD(v49) = (unsigned int)&loc_17358 >> 16;
        LOWORD(v50) = 29577;
        if ( cb_arg == v49 )
          v41 |= 1u;
        HIWORD(v50) = ((unsigned int)&loc_17336 + 3) >> 16;
        if ( cb_arg == v50 )
          v41 |= 1u;
        if ( !v41 )
          break;
        LOWORD(v51) = -2252;
        HIWORD(v51) = (unsigned int)"\n\t\t\"pass\" : \"%s\"\n\t}" >> 16;
        fprintf(fcfg, v51, v35 + 2, *(_DWORD *)v32[-1].u.carg);
LABEL_53:
        v35 = strtok(0, v33);
        if ( !v35 )
          goto LABEL_67;
      }
      LOWORD(v64) = 29029;
      LOWORD(v65) = 28953;
      HIWORD(v65) = (unsigned int)&loc_170C8 >> 16;
      v66 = cb_arg == v65;
      if ( cb_arg != v65 )
      {
        HIWORD(v64) = ((unsigned int)&loc_17112 + 3) >> 16;
        v66 = cb_arg == v64;
      }
      if ( v66 )
      {
        LOWORD(v67) = -2236;
        HIWORD(v67) = (unsigned int)"\n\t}" >> 16;
        fprintf(fcfg, v67, v35 + 2, v32[-1].u.tlen, *(float *)v32[-1].u.carg);
        goto LABEL_53;
      }
LABEL_63:
      if ( (type & 6) == 0 )
        goto LABEL_53;
      carg = (char **)v32[-1].u.carg;
      if ( carg == &opt_set_null || !*carg )
        goto LABEL_53;
      v58 = json_escape(*carg);
      HIWORD(v31) = (unsigned int)" true" >> 16;
      fprintf(fcfg, v31, v35 + 2, v58);
      v35 = strtok(0, v33);
      if ( !v35 )
        goto LABEL_67;
    }
  }
LABEL_68:
  v59 = pool_strategy_0;
  if ( pool_strategy_0 == pool_strategy::POOL_BALANCE )
  {
    LOWORD(v72) = -2204;
    HIWORD(v72) = (unsigned int)" \"%d\"" >> 16;
    fwrite(v72, 1u, 0x12u, fcfg);
    v59 = pool_strategy_0;
  }
  if ( v59 == pool_strategy::POOL_LOADBALANCE )
  {
    LOWORD(v71) = -2184;
    HIWORD(v71) = (unsigned int)"1f\"" >> 16;
    fwrite(v71, 1u, 0x17u, fcfg);
    v59 = pool_strategy_0;
  }
  if ( v59 == pool_strategy::POOL_ROUNDROBIN )
  {
    LOWORD(v70) = -2160;
    HIWORD(v70) = (unsigned int)"alance\" : true" >> 16;
    fwrite(v70, 1u, 0x16u, fcfg);
    v59 = pool_strategy_0;
  }
  if ( v59 == pool_strategy::POOL_ROTATE )
  {
    LOWORD(v69) = -2136;
    HIWORD(v69) = (unsigned int)"balance\" : true" >> 16;
    fprintf(fcfg, v69, opt_rotate_period);
  }
  LOWORD(v60) = -2116;
  HIWORD(v60) = (unsigned int)"ound-robin\" : true" >> 16;
  fwrite(v60, 1u, 3u, fcfg);
  next = jedata;
  jedata = 0;
  if ( next )
  {
    do
    {
      v62 = *next;
      free(next->buf);
      v63 = next;
      next = v62.next;
      free(v63);
    }
    while ( v62.next );
  }
}
