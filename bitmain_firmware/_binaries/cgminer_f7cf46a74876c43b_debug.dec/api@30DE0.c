void __fastcall api(int api_thr_id)
{
  double v1; // d0
  _BOOL4 v2; // r3
  io_data *v3; // r5
  char *v4; // r0
  char *v5; // r7
  io_list *v6; // r0
  io_list *v7; // r2
  const char *v8; // r4
  size_t v9; // r0
  unsigned __int8 *v10; // r5
  char *v11; // r0
  char *v12; // r0
  const __int32_t **v13; // r9
  const __int32_t *v14; // r2
  __int32_t v15; // r1
  unsigned __int8 *v16; // r4
  int v17; // r8
  char *v18; // r0
  char *v19; // r7
  char *name; // r5
  CMDS *v21; // r10
  int v22; // r6
  char *v23; // t1
  size_t v24; // r0
  int v25; // r5
  char *v26; // r0
  const __int32_t **v27; // r0
  char *v28; // r5
  const __int32_t **v29; // r11
  CMDS *v30; // r4
  char *v31; // r7
  char *v32; // t1
  size_t v33; // r0
  char *v34; // t1
  char *v35; // r0
  size_t v36; // r0
  __int32_t v37; // r3
  int v38; // r4
  char *v39; // r0
  const char *v40; // r5
  size_t v41; // r0
  char *v42; // r0
  char *v43; // r9
  char *v44; // r2
  size_t v45; // r0
  int v46; // r3
  int v47; // t1
  int v48; // r6
  const char *v49; // r5
  int v50; // r3
  int v51; // t1
  bool v52; // zf
  char *v53; // r0
  char *v54; // r8
  const unsigned __int16 **v55; // r0
  int v56; // r2
  const __int32_t *v57; // r3
  char v58; // r1
  IPACCESS *v59; // r4
  int v60; // r10
  char *v61; // r0
  int v62; // r10
  int v63; // r0
  const char *v64; // r5
  size_t v65; // r0
  CMDS *v66; // r4
  char *v67; // r8
  char *v68; // t1
  const char *v69; // r7
  char *v70; // r0
  uint8_t *v71; // r1
  IPACCESS *v72; // r3
  IPACCESS *v73; // r3
  int v74; // r2
  bool v75; // cf
  int v76; // r12
  IPACCESS *v77; // r3
  uint8_t *v78; // r0
  uint8_t *v79; // r3
  uint8_t *v80; // r4
  char v81; // r2
  char v82; // t1
  char v83; // t1
  IPACCESS *v84; // r3
  __int32_t v85; // r0
  addrinfo *v86; // r4
  addrinfo *i; // r3
  int v88; // r0
  int *v89; // r0
  char *v90; // r0
  time_t v91; // r8
  int *v92; // r0
  int v93; // r7
  _BOOL4 v94; // r4
  _BOOL4 v95; // r0
  int v96; // r9
  const char *v97; // r1
  ssize_t v98; // r0
  size_t v99; // r5
  _BOOL4 v100; // r3
  const char *v101; // r8
  time_t v102; // r0
  char *ptr; // r3
  int v104; // r3
  char *v105; // r0
  size_t v106; // r0
  char *v107; // r6
  char *v108; // r0
  int v109; // r3
  char *v110; // r1
  CMDS *v111; // r5
  int v112; // r4
  char *v113; // t1
  size_t v114; // r0
  char **v115; // r3
  int v116; // r5
  __int32_t v117; // r2
  int v118; // r3
  int *v119; // r0
  char *v120; // r0
  int *v121; // r0
  char *v122; // r0
  int *v123; // r0
  int *v124; // r0
  char *v125; // r0
  const char *v126; // r3
  const char *v127; // r2
  int v128; // r3
  const char *v129; // r2
  int v130; // r3
  json_t *v131; // r0
  size_t refcount; // r3
  size_t v133; // r3
  int *v134; // r0
  char *v135; // r0
  json_t *v136; // r0
  const char *v137; // r2
  int v138; // r3
  const char *v139; // r2
  int v140; // r3
  json_t *v141; // r0
  json_type type; // r3
  int v143; // r0
  int v144; // [sp+14h] [bp-26468h]
  unsigned __int8 *v145; // [sp+18h] [bp-26464h]
  int *apisock; // [sp+20h] [bp-2645Ch]
  char *v147; // [sp+24h] [bp-26458h]
  json_t *json_config; // [sp+2Ch] [bp-26450h]
  __int16 v149; // [sp+38h] [bp-26444h]
  int c; // [sp+40h] [bp-2643Ch]
  char *dest; // [sp+44h] [bp-26438h]
  int protocol; // [sp+48h] [bp-26434h]
  char *param; // [sp+54h] [bp-26428h]
  io_data *io_data; // [sp+58h] [bp-26424h]
  char *cmdsbuf; // [sp+60h] [bp-2641Ch]
  char group; // [sp+7Eh] [bp-263FEh] BYREF
  bool firstjoin; // [sp+7Fh] [bp-263FDh] BYREF
  char *connectaddr; // [sp+80h] [bp-263FCh] BYREF
  socklen_t clisiz; // [sp+84h] [bp-263F8h] BYREF
  addrinfo *res; // [sp+88h] [bp-263F4h] BYREF
  int optval; // [sp+8Ch] [bp-263F0h] BYREF
  char port_s[12]; // [sp+90h] [bp-263ECh] BYREF
  char cp[32]; // [sp+9Ch] [bp-263E0h] BYREF
  addrinfo hints; // [sp+BCh] [bp-263C0h] BYREF
  thr_info bye_thr; // [sp+DCh] [bp-263A0h] BYREF
  char cmdbuf[100]; // [sp+11Ch] [bp-26360h] BYREF
  char s[100]; // [sp+180h] [bp-262FCh] BYREF
  sockaddr_storage cli; // [sp+1E4h] [bp-26298h] BYREF
  json_error_t json_err; // [sp+264h] [bp-26218h] BYREF
  __pthread_unwind_buf_t __cancel_buf; // [sp+360h] [bp-2611Ch] BYREF
  char tmp42[4096]; // [sp+478h] [bp-26004h] BYREF
  char tmp42_0[4096]; // [sp+1478h] [bp-25004h] BYREF
  char tmp42_1[4096]; // [sp+2478h] [bp-24004h] BYREF
  char tmp42_2[4096]; // [sp+3478h] [bp-23004h] BYREF
  char tmp42_3[4096]; // [sp+4478h] [bp-22004h] BYREF
  char tmp42_4[4096]; // [sp+5478h] [bp-21004h] BYREF
  char tmp42_5[4096]; // [sp+6478h] [bp-20004h] BYREF
  char tmp42_6[4096]; // [sp+7478h] [bp-1F004h] BYREF
  char tmp42_7[4096]; // [sp+8478h] [bp-1E004h] BYREF
  char tmp42_8[4096]; // [sp+9478h] [bp-1D004h] BYREF
  char tmp42_9[4096]; // [sp+A478h] [bp-1C004h] BYREF
  char tmp42_10[4096]; // [sp+B478h] [bp-1B004h] BYREF
  char tmp42_11[4096]; // [sp+C478h] [bp-1A004h] BYREF
  char tmp42_12[4096]; // [sp+D478h] [bp-19004h] BYREF
  char tmp42_13[4096]; // [sp+E478h] [bp-18004h] BYREF
  char tmp42_14[4096]; // [sp+F478h] [bp-17004h] BYREF
  char tmp42_15[4096]; // [sp+10478h] [bp-16004h] BYREF
  char tmp42_16[4096]; // [sp+11478h] [bp-15004h] BYREF
  char tmp42_17[4096]; // [sp+12478h] [bp-14004h] BYREF
  char tmp42_18[4096]; // [sp+13478h] [bp-13004h] BYREF
  char v191[3976]; // [sp+14478h] [bp-12004h] BYREF
  char v192[3976]; // [sp+15478h] [bp-11004h] BYREF
  char v193[3976]; // [sp+16478h] [bp-10004h] BYREF
  char v194[3976]; // [sp+17478h] [bp-F004h] BYREF
  char v195[3976]; // [sp+18478h] [bp-E004h] BYREF
  char v196[3976]; // [sp+19478h] [bp-D004h] BYREF
  char v197[3976]; // [sp+1A478h] [bp-C004h] BYREF
  char v198[3976]; // [sp+1B478h] [bp-B004h] BYREF
  char v199[3976]; // [sp+1C478h] [bp-A004h] BYREF
  char v200[3976]; // [sp+1D478h] [bp-9004h] BYREF
  char v201[3976]; // [sp+1E478h] [bp-8004h] BYREF
  char v202[3976]; // [sp+1F478h] [bp-7004h] BYREF
  char buf[8192]; // [sp+20478h] [bp-6004h] BYREF
  char param_buf[8192]; // [sp+22478h] [bp-4004h] BYREF
  _WORD v205[4098]; // [sp+24478h] [bp-2004h] BYREF

  json_config = 0;
  v149 = opt_api_port;
  apisock = (int *)malloc(4u);
  v2 = opt_api_listen;
  *apisock = -1;
  if ( !v2 )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      snprintf(tmp42, 0x1000u, "API not running%s", " - API will not be available");
      applog(7, tmp42, 0);
    }
    goto LABEL_6;
  }
  io_data = (io_data *)malloc(0x10u);
  v3 = io_data;
  v4 = (char *)malloc(0x10000u);
  v5 = 0;
  io_data->close = 0;
  *v4 = 0;
  io_data->ptr = v4;
  io_data->cur = v4;
  io_data->sock = 1;
  io_data->siz = 0x10000;
  v6 = (io_list *)malloc(0xCu);
  v6->io_data = io_data;
  v7 = io_head;
  if ( io_head )
  {
    v6->next = io_head;
    v6->prev = v7->prev;
    v7->prev = v6;
    v6->prev->next = v6;
  }
  else
  {
    v6->prev = v6;
    v6->next = v6;
    io_head = v6;
  }
  if ( pthread_mutex_init(&quit_restart_lock, 0) )
  {
    v123 = _errno_location();
    snprintf(
      v191,
      0x1000u,
      "Failed to pthread_mutex_init errno=%d in %s %s():%d",
      *v123,
      "api.c",
      (const char *)&_func___12699,
      5297);
    applog(3, v191, 1);
    quit(1);
  }
  if ( _sigsetjmp((struct __jmp_buf_tag *)&__cancel_buf, 0) )
  {
    tidyup(apisock);
    _pthread_unwind_next(&__cancel_buf);
LABEL_253:
    freeaddrinfo(res);
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      snprintf(tmp42_5, 0x1000u, "API bind to port %d failed (%s)%s", v3, v5, " - API will not be available");
      applog(3, tmp42_5, 0);
    }
    goto LABEL_6;
  }
  _pthread_register_cancel(&__cancel_buf);
  v8 = opt_api_groups;
  if ( opt_api_groups )
  {
    v9 = strlen(opt_api_groups) + 1;
  }
  else
  {
    v8 = &byte_59398;
    v9 = 1;
  }
  dest = (char *)malloc(v9);
  if ( !dest )
  {
    strcpy(v192, "Failed to malloc ipgroups buf");
    applog(3, v192, 1);
    quit(1);
  }
  v10 = (unsigned __int8 *)dest;
  strcpy(dest, v8);
  if ( *dest )
  {
    do
    {
      v11 = strchr((const char *)v10, 44);
      if ( v11 )
      {
        v145 = (unsigned __int8 *)(v11 + 1);
        *v11 = 0;
      }
      else
      {
        v145 = 0;
      }
      if ( v10[1] != 58 )
      {
        v12 = strchr((const char *)v10, 58);
        if ( v12 )
          *v12 = 0;
        snprintf(v193, 0x1000u, "API invalid group name '%s'", v10);
        applog(3, v193, 1);
        quit(1);
      }
      v13 = _ctype_toupper_loc();
      v14 = *v13;
      v144 = LOBYTE((*v13)[*v10]);
      v15 = (*v13)[v144];
      if ( v15 < (*v13)[65] || v15 > v14[90] )
      {
        snprintf(v194, 0x1000u, "API invalid group name '%c'");
        applog(3, v194, 1);
        quit(1);
      }
      if ( v144 == v14[87] )
      {
        snprintf(v195, 0x1000u, "API group name can't be '%c'", v144);
        applog(3, v195, 1);
        quit(1);
      }
      if ( v144 == v14[82] )
      {
        snprintf(v196, 0x1000u, "API group name can't be '%c'", v144);
        applog(3, v196, 1);
        quit(1);
      }
      if ( apigroups[v14[v144] - v14[65]].commands )
      {
        snprintf(v197, 0x1000u, "API duplicate group name '%c'", *v10);
        applog(3, v197, 1);
        quit(1);
      }
      v16 = v10 + 2;
      v205[0] = 124;
      if ( v10 != (unsigned __int8 *)-2 && v10[2] )
      {
        v17 = 0;
        v147 = (char *)v205 + 1;
        do
        {
          v18 = strchr((const char *)v16, 58);
          v19 = v18;
          if ( v18 )
          {
            v19 = v18 + 1;
            *v18 = 0;
          }
          if ( *v16 != 42 || v16[1] )
          {
            name = cmds[0].name;
            v21 = cmds;
            v22 = 0;
            if ( !cmds[0].name )
            {
LABEL_92:
              snprintf(v198, 0x1000u, "API unknown command '%s' in group '%c'", v16, v144);
              applog(3, v198, 1);
              quit(1);
            }
            while ( strcasecmp((const char *)v16, name) )
            {
              v23 = v21[1].name;
              ++v21;
              name = v23;
              ++v22;
              if ( !v23 )
                goto LABEL_92;
            }
            sprintf(s, "|%s|", name);
            if ( !strstr((const char *)v205, s) )
            {
              v64 = (const char *)*((_DWORD *)&codes[67].severity + 3 * v22);
              strcpy(v147, v64);
              v65 = strlen(v64);
              v147[v65 + 1] = 0;
              v147[v65] = 124;
              v147 += v65 + 1;
            }
          }
          else
          {
            v17 = 1;
          }
          if ( !v19 )
            break;
          v16 = (unsigned __int8 *)v19;
        }
        while ( *v19 );
        if ( v17 && cmds[0].name )
        {
          v66 = cmds;
          v67 = v147;
          do
          {
            if ( !v66->iswritemode )
            {
              sprintf(s, "|%s|");
              if ( !strstr((const char *)v205, s) )
              {
                v69 = v66->name;
                strcpy(v67, v66->name);
                v70 = &v67[strlen(v69)];
                v67 = v70 + 1;
                v70[1] = 0;
                *v70 = 124;
              }
            }
            v68 = v66[1].name;
            ++v66;
          }
          while ( v68 );
        }
      }
      v24 = strlen((const char *)v205);
      v25 = (*v13)[v144] - (*v13)[65];
      v26 = (char *)malloc(v24 + 1);
      apigroups[v25].commands = v26;
      if ( !v26 )
      {
        strcpy(v199, "Failed to malloc group commands buf");
        applog(3, v199, 1);
        quit(1);
      }
      strcpy(v26, (const char *)v205);
      if ( !v145 )
        break;
      v10 = v145;
    }
    while ( *v145 );
  }
  v27 = _ctype_toupper_loc();
  v28 = cmds[0].name;
  v29 = v27;
  v205[0] = 124;
  if ( cmds[0].name )
  {
    v30 = cmds;
    v31 = (char *)v205 + 1;
    do
    {
      while ( v30->iswritemode )
      {
        v32 = v30[1].name;
        ++v30;
        v28 = v32;
        if ( !v32 )
          goto LABEL_51;
      }
      strcpy(v31, v28);
      v33 = strlen(v28);
      v34 = v30[1].name;
      ++v30;
      v28 = v34;
      v35 = &v31[v33];
      v31 = v35 + 1;
      *v35 = 124;
      v35[1] = 0;
    }
    while ( v34 );
  }
LABEL_51:
  v36 = strlen((const char *)v205) + 1;
  v37 = (*v29)[82];
  if ( (unsigned int)(v37 + 128) < 0x180 )
    v37 = (*v29)[v37];
  v38 = v37 - (*v29)[65];
  v39 = (char *)malloc(v36);
  apigroups[v38].commands = v39;
  if ( !v39 )
  {
    strcpy(v200, "Failed to malloc noprivgroup commands buf");
    applog(3, v200, 1);
    quit(1);
  }
  strcpy(v39, (const char *)v205);
  free(dest);
  v40 = opt_api_allow;
  if ( opt_api_allow )
  {
    v41 = strlen(opt_api_allow);
    v42 = (char *)malloc(v41 + 1);
    v43 = v42;
    if ( !v42 )
    {
      strcpy(v201, "Failed to malloc ipaccess buf");
      applog(3, v201, 1);
      quit(1);
    }
    strcpy(v42, v40);
    v44 = v43 - 1;
    v45 = 1;
    while ( 1 )
    {
      v47 = (unsigned __int8)*++v44;
      v46 = v47;
      if ( !v47 )
        break;
      if ( v46 == 44 )
        ++v45;
    }
    ipaccess = (IPACCESS *)calloc(v45, 0x24u);
    if ( !ipaccess )
    {
      strcpy(v202, "Failed to calloc ipaccess");
      applog(3, v202, 1);
      quit(1);
    }
    v48 = 0;
    v49 = v43;
    ips = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v50 = *(unsigned __int8 *)v49;
        if ( !*v49 )
        {
LABEL_85:
          free(v43);
          if ( v48 )
            goto LABEL_86;
          if ( use_syslog || opt_log_output || opt_log_level > 3 )
          {
            snprintf(tmp42_0, 0x1000u, "API not running (no valid IPs specified)%s", " - API will not be available");
            applog(4, tmp42_0, 0);
          }
LABEL_6:
          free(apisock);
          return;
        }
        while ( 1 )
        {
          v52 = v50 == 9;
          if ( v50 != 9 )
            v52 = v50 == 32;
          if ( !v52 )
            break;
          v51 = *(unsigned __int8 *)++v49;
          v50 = v51;
        }
        if ( v50 != 44 )
          break;
        ++v49;
LABEL_84:
        if ( !v49 )
          goto LABEL_85;
      }
      v53 = strchr(v49, 44);
      v54 = v53;
      if ( v53 )
      {
        v54 = v53 + 1;
        *v53 = 0;
      }
      v55 = _ctype_b_loc();
      v56 = *(unsigned __int8 *)v49;
      v57 = *v29;
      v58 = *((_BYTE *)*v29 + 328);
      if ( ((*v55)[v56] & 0x400) != 0 && v49[1] == 58 )
      {
        v85 = v57[v56];
        if ( v85 == v57[87] || apigroups[v85 - v57[65]].commands )
          v58 = v57[v56];
        v49 += 2;
      }
      v59 = &ipaccess[v48];
      v59->group = v58;
      v60 = *(unsigned __int8 *)v49;
      if ( v60 == 48 )
      {
        if ( v49[1] == 47 && v49[2] == 48 && !v49[3] )
        {
          v71 = &v59->ip.__u6_addr8[15];
          v72 = (IPACCESS *)((char *)v59 - 1);
          do
          {
            v72->ip.__u6_addr8[1] = 0;
            v72 = (IPACCESS *)((char *)v72 + 1);
            *++v71 = 0;
          }
          while ( v72 != (IPACCESS *)((char *)&v59->ip.__u6_addr32[3] + 3) );
          goto LABEL_107;
        }
        v61 = strchr(v49, 47);
        if ( v61 )
          goto LABEL_78;
      }
      else
      {
        v61 = strchr(v49, 47);
        if ( v61 )
          goto LABEL_76;
      }
      v73 = (IPACCESS *)((char *)&v59->ip.__u6_addr32[3] + 3);
      do
      {
        v73->ip.__u6_addr8[1] = -1;
        v73 = (IPACCESS *)((char *)v73 + 1);
      }
      while ( (IPACCESS *)((char *)&v59->mask.__u6_addr32[3] + 3) != v73 );
      v60 = *(unsigned __int8 *)v49;
      v61 = (char *)&v49[strlen(v49)];
LABEL_76:
      if ( v60 == 91 && *(v61 - 1) == 93 )
      {
        v62 = 1;
        *v49++ = 0;
        *(v61 - 1) = 0;
        goto LABEL_79;
      }
LABEL_78:
      v62 = 0;
LABEL_79:
      if ( *v61 )
      {
        *v61 = 0;
        v63 = strtol(v61 + 1, 0, 10);
        if ( v63 <= 0 )
          goto LABEL_83;
        if ( v62 )
        {
          if ( v63 > 128 )
            goto LABEL_83;
        }
        else
        {
          v63 += 96;
          if ( v63 > 128 )
          {
LABEL_83:
            v49 = v54;
            goto LABEL_84;
          }
        }
        v84 = (IPACCESS *)((char *)&v59->ip.__u6_addr32[3] + 3);
        v74 = 0;
        do
        {
          v84->ip.__u6_addr8[1] = 0;
          v84 = (IPACCESS *)((char *)v84 + 1);
        }
        while ( (IPACCESS *)((char *)&v59->mask.__u6_addr32[3] + 3) != v84 );
        while ( 1 )
        {
          v75 = v63-- != 0;
          v76 = 7;
          if ( !v75 )
            break;
          while ( 1 )
          {
            v59->mask.__u6_addr8[v74] |= 1 << v76;
            if ( !v76 )
              break;
            v75 = v63-- != 0;
            --v76;
            if ( !v75 )
              goto LABEL_118;
          }
          ++v74;
        }
      }
LABEL_118:
      v77 = (IPACCESS *)((char *)v59 - 1);
      do
      {
        v77->ip.__u6_addr8[1] = 0;
        v77 = (IPACCESS *)((char *)v77 + 1);
      }
      while ( (IPACCESS *)((char *)&v59->ip.__u6_addr32[3] + 3) != v77 );
      if ( v62 )
      {
        if ( inet_pton(10, v49, v59) != 1 )
          goto LABEL_83;
      }
      else
      {
        sprintf(cp, "::ffff:%s", v49);
        v48 = ips;
        v59 = &ipaccess[ips];
        if ( inet_pton(10, cp, v59) != 1 )
        {
          v49 = v54;
          goto LABEL_84;
        }
      }
      v78 = &v59->ip.__u6_addr8[15];
      v79 = (uint8_t *)(&v59[-1].group + 3);
      v80 = &v59->ip.__u6_addr8[15];
      do
      {
        v82 = *++v79;
        v81 = v82;
        v83 = *++v78;
        *v79 = v81 & v83;
      }
      while ( v79 != v80 );
LABEL_107:
      v49 = v54;
      ips = ++v48;
      if ( !v54 )
        goto LABEL_85;
    }
  }
LABEL_86:
  v3 = (io_data *)v149;
  cgsleep_ms(1000 * opt_log_interval);
  sprintf(port_s, "%d", v149);
  hints.ai_flags = 1;
  memset(&hints.ai_family, 0, 28);
  protocol = getaddrinfo(opt_api_host, port_s, &hints, &res);
  if ( protocol )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      snprintf(tmp42_1, 0x1000u, "API failed to resolve %s", opt_api_host);
      applog(3, tmp42_1, 0);
    }
    goto LABEL_6;
  }
  v86 = res;
  if ( res )
  {
    for ( i = res; ; i = res )
    {
      v88 = socket(i->ai_family, 1, protocol);
      *apisock = v88;
      if ( v88 > 0 )
        break;
      v86 = v86->ai_next;
      if ( !v86 )
        goto LABEL_223;
    }
  }
  else
  {
    v88 = *apisock;
LABEL_223:
    if ( v88 == -1 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        v119 = _errno_location();
        v120 = strerror(*v119);
        snprintf(tmp42_2, 0x1000u, "API initialisation failed (%s)%s", v120, " - API will not be available");
        applog(3, tmp42_2, 0);
      }
      freeaddrinfo(res);
      free(apisock);
      return;
    }
    v86 = 0;
  }
  optval = 1;
  if ( setsockopt(v88, 1, 2, &optval, 4u) < 0 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    v89 = _errno_location();
    v90 = strerror(*v89);
    snprintf(tmp42_3, 0x1000u, "API setsockopt SO_REUSEADDR failed (ignored): %s", v90);
    applog(7, tmp42_3, 0);
  }
  v91 = time(0);
  while ( bind(*apisock, v86->ai_addr, v86->ai_addrlen) < 0 )
  {
    v92 = _errno_location();
    v5 = strerror(*v92);
    if ( time(0) - v91 > 61 )
      goto LABEL_253;
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      snprintf(tmp42_4, 0x1000u, "API bind to port %d failed - trying again in 30sec", v149);
      applog(4, tmp42_4, 0);
    }
    cgsleep_ms(30000);
  }
  freeaddrinfo(res);
  if ( listen(*apisock, 100) < 0 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      v134 = _errno_location();
      v135 = strerror(*v134);
      snprintf(tmp42_6, 0x1000u, "API3 initialisation failed (%s)%s", v135, " - API will not be available");
      applog(3, tmp42_6, 0);
    }
    close(*apisock);
    free(apisock);
    return;
  }
  if ( opt_api_allow )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      snprintf(tmp42_7, 0x1000u, "API running in IP access mode on port %d (%d)", v149, *apisock);
      applog(4, tmp42_7, 0);
    }
  }
  else if ( opt_api_network )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      snprintf(tmp42_8, 0x1000u, "API running in UNRESTRICTED read access mode on port %d (%d)", v149, *apisock);
      applog(4, tmp42_8, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    snprintf(tmp42_9, 0x1000u, "API running in local read access mode on port %d (%d)", v149, *apisock);
    applog(4, tmp42_9, 0);
  }
  if ( opt_api_mcast )
    mcast_init();
  v93 = 0;
  strbufs = k_new_list("StrBufs", 0xCu, 2, 0, 0, "api.c", (const char *)&_func___12699, 5409);
  while ( 1 )
  {
    v94 = bye;
    if ( bye )
      goto die;
    clisiz = 128;
    c = accept(*apisock, (struct sockaddr *)&cli, &clisiz);
    if ( c < 0 )
      break;
    v95 = check_connect(&cli, &connectaddr, &group);
    v96 = v95;
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      v97 = "Accepted";
      if ( !v95 )
        v97 = "Ignored";
      snprintf(tmp42_11, 0x1000u, "API: connection from %s - %s", connectaddr, v97);
      applog(7, tmp42_11, 0);
    }
    if ( v96 )
    {
      v98 = recv(c, buf, 0x1FFFu, 0);
      v99 = v98;
      v100 = opt_debug;
      if ( v98 >= 0 )
      {
        buf[v98] = 0;
        if ( v100 && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          snprintf(tmp42_13, 0x1000u, "API: recv command: (%d) '%s'", v98, buf);
          applog(7, tmp42_13, 0);
        }
        v101 = buf;
        v102 = time(0);
        ptr = io_data->ptr;
        io_data->cur = ptr;
        when = v102;
        *ptr = 0;
        v104 = (unsigned __int8)buf[0];
        io_data->close = 0;
        if ( v104 == 123 )
        {
          v131 = json_loadb(buf, v99, 0, &json_err);
          json_config = v131;
          if ( v131 && v131->type == JSON_OBJECT )
          {
            v136 = json_object_get(v131, "command");
            if ( v136 )
            {
              if ( v136->type == JSON_STRING )
              {
                v101 = json_string_value(v136);
                v141 = json_object_get(json_config, "parameter");
                if ( v141 )
                {
                  type = v141->type;
                  if ( v141->type == JSON_STRING )
                  {
                    param = (char *)json_string_value(v141);
                  }
                  else if ( type == JSON_INTEGER )
                  {
                    v143 = json_integer_value(v141);
                    param = param_buf;
                    sprintf(param_buf, "%d", v143);
                  }
                  else if ( type == JSON_REAL )
                  {
                    json_real_value(v141);
                    param = param_buf;
                    sprintf(param_buf, "%f", v1);
                  }
                  else
                  {
                    param = 0;
                  }
                }
                else
                {
                  param = 0;
                }
                goto LABEL_191;
              }
              message(io_data, 14, 0, 0, 1);
            }
            else
            {
              message(io_data, 24, 0, 0, 1);
            }
          }
          else
          {
            message(io_data, 23, 0, 0, 1);
          }
          send_result((io_data *)io_data->ptr, io_data->close, c, 1);
LABEL_283:
          if ( v93 )
            send_result((io_data *)io_data->ptr, io_data->close, c, v96);
LABEL_215:
          if ( json_config )
            v118 = v96 & 1;
          else
            v118 = 0;
          if ( v118 )
          {
            if ( json_config->type == JSON_OBJECT )
            {
              refcount = json_config->refcount;
              if ( refcount != -1 )
              {
                v133 = refcount - 1;
                json_config->refcount = v133;
                if ( !v133 )
                  json_delete(json_config);
              }
            }
          }
          goto LABEL_220;
        }
        v105 = strchr(buf, 124);
        if ( v105 )
        {
          v96 = v94;
          *v105 = 0;
          param = v105 + 1;
        }
        else
        {
          param = 0;
          v96 = v94;
        }
LABEL_191:
        cmdsbuf = strchr(v101, 43);
        if ( cmdsbuf )
        {
          v93 = 1;
          firstjoin = 1;
          v106 = strlen(v101);
          cmdsbuf = (char *)malloc(v106 + 3);
          if ( !cmdsbuf )
          {
            snprintf(tmp42_14, 0x1000u, "OOM cmdsbuf in %s %s():%d", "api.c", (const char *)&_func___12699, 5520);
            applog(3, tmp42_14, 1);
            quit(1);
          }
          param = 0;
          *(_WORD *)cmdsbuf = 124;
        }
        else
        {
          v93 = v94;
          firstjoin = 0;
        }
        v107 = (char *)v101;
        if ( !v93 )
        {
          v110 = cmds[0].name;
          if ( cmds[0].name )
            goto LABEL_204;
          goto LABEL_237;
        }
        while ( 2 )
        {
          v108 = strchr(v107, 43);
          v101 = v108;
          if ( v108 )
          {
            v101 = v108 + 1;
            *v108 = 0;
          }
          if ( !*v107 )
          {
LABEL_198:
            if ( v101 )
              v109 = v93 & 1;
            else
              v109 = 0;
            v107 = (char *)v101;
            if ( !v109 )
              goto LABEL_283;
            continue;
          }
          break;
        }
        v110 = cmds[0].name;
        if ( cmds[0].name )
        {
LABEL_204:
          v111 = cmds;
          v112 = 0;
          while ( strcmp(v107, v110) )
          {
            v113 = v111[1].name;
            ++v111;
            v110 = v113;
            ++v112;
            if ( !v113 )
            {
              if ( !v93 )
                goto LABEL_237;
              goto LABEL_236;
            }
          }
          sprintf(cmdbuf, "|%s|", v107);
          if ( v93 )
          {
            if ( strstr(cmdsbuf, cmdbuf) )
              goto LABEL_198;
            v114 = strlen(cmdsbuf);
            *(_WORD *)stpcpy(&cmdsbuf[v114], v107) = 124;
            head_join(io_data, v107, v96, &firstjoin);
            v115 = (char **)codes + 3 * v112;
            if ( !*((_BYTE *)v115 + 1081) )
            {
              message(io_data, 45, *((unsigned __int8 *)v115 + 1081), v115[268], v96);
              tail_join(io_data, v96);
              goto inochi;
            }
          }
          v116 = (unsigned __int8)group;
          v117 = (*v29)[(unsigned __int8)group];
          if ( v117 == (*v29)[87] || strstr(apigroups[v117 - (*v29)[65]].commands, cmdbuf) )
          {
            (*((void (__fastcall **)(io_data *, int, char *, int, int))&codes[67].code + 3 * v112))(
              io_data,
              c,
              param,
              v96,
              v116);
          }
          else
          {
            message(io_data, 45, 0, *((char **)&codes[67].severity + 3 * v112), v96);
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              snprintf(
                tmp42_15,
                0x1000u,
                "API: access denied to '%s' for '%s' command",
                connectaddr,
                *((const char **)&codes[67].severity + 3 * v112));
              applog(7, tmp42_15, 0);
            }
          }
          if ( (unsigned __int8)v93 == 1 )
            goto LABEL_238;
        }
        else
        {
LABEL_236:
          head_join(io_data, v107, v96, &firstjoin);
LABEL_237:
          message(io_data, 14, 0, 0, v96);
          if ( v93 )
          {
LABEL_238:
            tail_join(io_data, v96);
inochi:
            if ( !v93 )
              goto LABEL_215;
            goto LABEL_198;
          }
        }
        send_result((io_data *)io_data->ptr, io_data->close, c, v96);
        goto inochi;
      }
      buf[0] = 0;
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        v121 = _errno_location();
        v122 = strerror(*v121);
        snprintf(tmp42_12, 0x1000u, "API: recv failed: %s", v122);
        applog(7, tmp42_12, 0);
      }
    }
LABEL_220:
    close(c);
  }
  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    v124 = _errno_location();
    v125 = strerror(*v124);
    snprintf(tmp42_10, 0x1000u, "API failed (%s)%s (%d)", v125, " - API will not be available", *apisock);
    applog(3, tmp42_10, 0);
  }
die:
  _pthread_unregister_cancel(&__cancel_buf);
  tidyup(apisock);
  free(apisock);
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    if ( do_a_quit )
    {
      v126 = "QUIT";
    }
    else if ( do_a_restart )
    {
      v126 = "RESTART";
    }
    else
    {
      v126 = "UNKNOWN!";
      if ( bye )
        v126 = &_func___12699.__size[20];
    }
    snprintf(tmp42_16, 0x1000u, "API: terminating due to: %s", v126);
    applog(7, tmp42_16, 0);
  }
  if ( pthread_mutex_lock(&quit_restart_lock) )
    mutex_lock_1((pthread_mutex_t *)&_func___12699, (const char *)0x15F3, v127, v128);
  if ( do_a_restart )
  {
    if ( thr_info_create(&bye_thr, 0, restart_thread_0, &bye_thr) )
    {
      if ( !pthread_mutex_unlock(&quit_restart_lock) )
      {
        selective_yield();
        strcpy(tmp42_17, "API failed to initiate a restart - aborting");
        applog(3, tmp42_17, 1);
        quit(1);
      }
      mutex_unlock_noyield_1((pthread_mutex_t *)&_func___12699, (const char *)0x15F9, v139, v140);
    }
  }
  else
  {
    if ( !do_a_quit )
      goto LABEL_277;
    if ( thr_info_create(&bye_thr, (pthread_attr_t *)do_a_restart, quit_thread, &bye_thr) )
    {
      if ( pthread_mutex_unlock(&quit_restart_lock) )
        mutex_unlock_noyield_1((pthread_mutex_t *)&_func___12699, (const char *)0x1602, v137, v138);
      selective_yield();
      strcpy(tmp42_18, "API failed to initiate a clean quit - aborting");
      applog(3, tmp42_18, 1);
      quit(1);
    }
  }
  pthread_detach(bye_thr.pth);
LABEL_277:
  if ( pthread_mutex_unlock(&quit_restart_lock) )
    mutex_unlock_noyield_1((pthread_mutex_t *)&_func___12699, (const char *)0x1608, v129, v130);
  selective_yield();
}
