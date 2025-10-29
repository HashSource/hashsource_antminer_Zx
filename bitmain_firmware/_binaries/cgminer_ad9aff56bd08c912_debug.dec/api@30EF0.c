void __fastcall api(int api_thr_id)
{
  _BOOL4 v1; // r3
  const char *v2; // r3
  io_data *v3; // r5
  char *v4; // r0
  char *v5; // r7
  io_list *v6; // r0
  io_list *v7; // r2
  char *v8; // r4
  size_t v9; // r0
  unsigned __int8 *v10; // r5
  const char *v11; // r1
  char *v12; // r6
  char *v13; // r4
  char *v14; // r7
  char *v15; // r0
  char *v16; // r0
  const __int32_t **v17; // r9
  const __int32_t *v18; // r2
  __int32_t v19; // r1
  const char *v20; // r2
  unsigned __int8 *v21; // r4
  char *v22; // r2
  int v23; // r8
  char *v24; // r0
  char *v25; // r7
  char *name; // r5
  CMDS *v27; // r10
  int v28; // r6
  char *v29; // t1
  size_t v30; // r0
  int v31; // r5
  char *v32; // r0
  const __int32_t **v33; // r0
  char *v34; // r5
  const __int32_t **v35; // r11
  CMDS *v36; // r4
  char *v37; // r7
  char *v38; // t1
  size_t v39; // r0
  char *v40; // t1
  char *v41; // r0
  size_t v42; // r0
  __int32_t v43; // r3
  int v44; // r4
  char *v45; // r0
  const char *v46; // r5
  size_t v47; // r0
  char *v48; // r0
  char *v49; // r9
  char *v50; // r2
  size_t v51; // r0
  int v52; // r3
  int v53; // t1
  int v54; // r6
  const char *v55; // r5
  int v56; // r3
  int v57; // t1
  bool v58; // zf
  char *v59; // r0
  char *v60; // r8
  const unsigned __int16 **v61; // r0
  int v62; // r2
  const __int32_t *v63; // r3
  char v64; // r1
  IPACCESS *v65; // r4
  int v66; // r10
  char *v67; // r0
  int v68; // r10
  int v69; // r0
  const char *v70; // r1
  const char *v71; // r2
  const char *v72; // r5
  size_t v73; // r0
  CMDS *v74; // r4
  char *v75; // r8
  char *v76; // t1
  const char *v77; // r7
  char *v78; // r0
  const char *v79; // r2
  const char *v80; // r2
  uint8_t *v81; // r1
  IPACCESS *v82; // r3
  IPACCESS *v83; // r3
  int v84; // r2
  bool v85; // cf
  int v86; // r12
  IPACCESS *v87; // r3
  uint8_t *v88; // r0
  uint8_t *v89; // r3
  uint8_t *v90; // r4
  char v91; // r2
  char v92; // t1
  char v93; // t1
  const char *v94; // r1
  int v95; // r3
  const char *v96; // r2
  IPACCESS *v97; // r3
  int *v98; // r5
  int v99; // r0
  int v100; // r1
  int v101; // r2
  int v102; // r3
  int v103; // r0
  int v104; // r1
  int v105; // r2
  int v106; // r3
  int v107; // r5
  __int32_t v108; // r0
  addrinfo *v109; // r4
  addrinfo *i; // r3
  int v111; // r0
  int *v112; // r0
  char *v113; // r0
  const char *v114; // r2
  const char *v115; // r9
  time_t v116; // r8
  int *v117; // r0
  const char *v118; // r2
  const char *file; // r3
  const char *v120; // r0
  int v121; // r7
  _BOOL4 v122; // r4
  _BOOL4 v123; // r0
  int v124; // r9
  int v125; // r2
  int v126; // r1
  const char *v127; // r2
  ssize_t v128; // r0
  size_t v129; // r5
  _BOOL4 v130; // r3
  const char *v131; // r2
  char *v132; // r8
  time_t v133; // r0
  char *ptr; // r3
  int v135; // r3
  char *v136; // r0
  size_t v137; // r0
  char *v138; // r6
  char *v139; // r0
  int v140; // r3
  char *v141; // r1
  CMDS *v142; // r5
  int v143; // r4
  char *v144; // t1
  const char *v145; // r1
  size_t v146; // r0
  _WORD *v147; // r0
  _WORD *v148; // r2
  char **v149; // r3
  int v150; // r5
  __int32_t v151; // r2
  int v152; // r3
  int *v153; // r0
  char *v154; // r0
  int v155; // r1
  const char *v156; // r2
  int *v157; // r5
  int v158; // r0
  int v159; // r1
  int v160; // r2
  int v161; // r3
  int v162; // r1
  int v163; // r2
  int *v164; // r6
  int v165; // r0
  int v166; // r1
  int v167; // r2
  int v168; // r3
  int v169; // r1
  int v170; // r2
  int v171; // r3
  const char *v172; // r2
  int *v173; // r0
  char *v174; // r0
  const char *v175; // r2
  int v176; // r1
  const char *v177; // r2
  int *v178; // r0
  int v179; // r1
  const char *v180; // r2
  int *v181; // r6
  int v182; // r0
  int v183; // r1
  int v184; // r2
  int v185; // r3
  int v186; // r0
  int v187; // r1
  int v188; // r2
  int v189; // r3
  int v190; // r1
  int v191; // r2
  int *v192; // r6
  int v193; // r0
  int v194; // r1
  int v195; // r2
  int v196; // r3
  int v197; // r1
  int v198; // r2
  int v199; // r3
  int *v200; // r0
  char *v201; // r0
  const char *v202; // r2
  const char *v203; // r3
  const char *v204; // r2
  const char *v205; // r2
  int v206; // r3
  const char *v207; // r2
  int v208; // r3
  json_t *v209; // r0
  int v210; // r3
  const char *v211; // r2
  size_t refcount; // r3
  size_t v213; // r3
  int *v214; // r0
  char *v215; // r0
  int v216; // r1
  const char *v217; // r2
  const char *v218; // r2
  const char *v219; // r2
  json_t *v220; // r0
  void *(*v221)(void *); // r2
  const char *v222; // r2
  int v223; // r3
  int *v224; // r5
  int v225; // r0
  int v226; // r1
  int v227; // r2
  int v228; // r3
  int v229; // r0
  int v230; // r1
  int v231; // r2
  int v232; // r3
  int v233; // r1
  int v234; // r2
  int v235; // r3
  void *(*v236)(void *); // r2
  const char *v237; // r2
  int v238; // r3
  int *v239; // r4
  int v240; // r0
  int v241; // r1
  int v242; // r2
  int v243; // r3
  int v244; // r0
  int v245; // r1
  int v246; // r2
  int v247; // r3
  int v248; // r1
  int v249; // r2
  const char *v250; // r0
  const char *v251; // r1
  json_t *v252; // r0
  json_type type; // r3
  const char *v254; // r1
  int v255; // r0
  const char *v256; // r1
  int v257; // [sp+14h] [bp-26468h]
  unsigned __int8 *v258; // [sp+18h] [bp-26464h]
  char *v259; // [sp+1Ch] [bp-26460h]
  int *apisock; // [sp+20h] [bp-2645Ch]
  char *v261; // [sp+24h] [bp-26458h]
  char *v262; // [sp+28h] [bp-26454h]
  json_t *json_config; // [sp+2Ch] [bp-26450h]
  char *format; // [sp+30h] [bp-2644Ch]
  char *v265; // [sp+34h] [bp-26448h]
  __int16 v266; // [sp+38h] [bp-26444h]
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
  char v308[3976]; // [sp+14478h] [bp-12004h] BYREF
  _DWORD v309[7]; // [sp+15478h] [bp-11004h] BYREF
  __int16 v310; // [sp+15494h] [bp-10FE8h]
  char v311[3976]; // [sp+16478h] [bp-10004h] BYREF
  char v312[3976]; // [sp+17478h] [bp-F004h] BYREF
  char v313[3976]; // [sp+18478h] [bp-E004h] BYREF
  char v314[3976]; // [sp+19478h] [bp-D004h] BYREF
  char v315[3976]; // [sp+1A478h] [bp-C004h] BYREF
  char v316[3976]; // [sp+1B478h] [bp-B004h] BYREF
  _DWORD v317[994]; // [sp+1C478h] [bp-A004h] BYREF
  _DWORD v318[10]; // [sp+1D478h] [bp-9004h] BYREF
  __int16 v319; // [sp+1D4A0h] [bp-8FDCh]
  _DWORD v320[7]; // [sp+1E478h] [bp-8004h] BYREF
  __int16 v321; // [sp+1E494h] [bp-7FE8h]
  _DWORD v322[6]; // [sp+1F478h] [bp-7004h] BYREF
  __int16 v323; // [sp+1F490h] [bp-6FECh]
  char buf[8192]; // [sp+20478h] [bp-6004h] BYREF
  char param_buf[8192]; // [sp+22478h] [bp-4004h] BYREF
  _WORD v326[4098]; // [sp+24478h] [bp-2004h] BYREF

  json_config = 0;
  v266 = opt_api_port;
  apisock = (int *)malloc(4u);
  v1 = opt_api_listen;
  *apisock = -1;
  if ( !v1 )
  {
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v2) = 23428;
      HIWORD(v2) = (unsigned int)" Comms Error" >> 16;
      snprintf(tmp42, 0x1000u, "API not running%s", v2);
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
    v178 = _errno_location();
    LOWORD(v179) = 20356;
    HIWORD(v179) = (unsigned int)&_func___11888.__data.__nusers >> 16;
    LOWORD(v180) = -1128;
    HIWORD(v180) = (unsigned int)"NonceTime" >> 16;
    snprintf(v308, 0x1000u, v180, *v178, v179, &_func___12699, 5297);
    applog(3, v308, 1);
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
      LOWORD(v176) = 23428;
      HIWORD(v176) = (unsigned int)" Comms Error" >> 16;
      LOWORD(v177) = 23984;
      HIWORD(v177) = (unsigned int)"on failed (%s)%s" >> 16;
      snprintf(tmp42_5, 0x1000u, v177, v3, v5, v176);
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
    LOWORD(v8) = -27628;
    v9 = 1;
    HIWORD(v8) = (unsigned int)"c.txt" >> 16;
  }
  dest = (char *)malloc(v9);
  if ( !dest )
  {
    LOWORD(v192) = 23480;
    HIWORD(v192) = (unsigned int)"o calloc mcast thr" >> 16;
    v193 = *v192;
    v194 = v192[1];
    v195 = v192[2];
    v196 = v192[3];
    v192 += 4;
    v309[0] = v193;
    v309[1] = v194;
    v309[2] = v195;
    v309[3] = v196;
    v197 = v192[1];
    v198 = v192[2];
    v199 = v192[3];
    v309[4] = *v192;
    v309[5] = v197;
    v309[6] = v198;
    v310 = v199;
    applog(3, (const char *)v309, 1);
    quit(1);
  }
  v10 = (unsigned __int8 *)dest;
  v11 = v8;
  LOWORD(v12) = 23540;
  LOWORD(v13) = 23512;
  LOWORD(v14) = 21852;
  strcpy(dest, v11);
  HIWORD(v12) = (unsigned int)"UNKNOWN!" >> 16;
  HIWORD(v14) = (unsigned int)"expiry" >> 16;
  HIWORD(v13) = (unsigned int)"read create failed" >> 16;
  format = v13;
  v265 = v12;
  v262 = v14;
  if ( *dest )
  {
    do
    {
      v15 = strchr((const char *)v10, 44);
      if ( v15 )
      {
        v258 = (unsigned __int8 *)(v15 + 1);
        *v15 = 0;
      }
      else
      {
        v258 = 0;
      }
      if ( v10[1] != 58 )
      {
        v16 = strchr((const char *)v10, 58);
        if ( v16 )
          *v16 = 0;
        snprintf(v311, 0x1000u, format, v10);
        applog(3, v311, 1);
        quit(1);
      }
      v17 = _ctype_toupper_loc();
      v18 = *v17;
      v257 = LOBYTE((*v17)[*v10]);
      v19 = (*v17)[v257];
      if ( v19 < (*v17)[65] || v19 > v18[90] )
      {
        snprintf(v312, 0x1000u, v265);
        applog(3, v312, 1);
        quit(1);
      }
      if ( v257 == v18[87] )
      {
        LOWORD(v80) = 23568;
        HIWORD(v80) = (unsigned int)"be available" >> 16;
        snprintf(v313, 0x1000u, v80, v257);
        applog(3, v313, 1);
        quit(1);
      }
      if ( v257 == v18[82] )
      {
        LOWORD(v79) = 23568;
        HIWORD(v79) = (unsigned int)"be available" >> 16;
        snprintf(v314, 0x1000u, v79, v257);
        applog(3, v314, 1);
        quit(1);
      }
      if ( apigroups[v18[v257] - v18[65]].commands )
      {
        LOWORD(v20) = 23600;
        HIWORD(v20) = (unsigned int)"s" >> 16;
        snprintf(v315, 0x1000u, v20, *v10);
        applog(3, v315, 1);
        quit(1);
      }
      v21 = v10 + 2;
      v326[0] = 124;
      if ( v10 != (unsigned __int8 *)-2 && v10[2] )
      {
        LOWORD(v22) = 24536;
        v23 = 0;
        HIWORD(v22) = (unsigned int)"and" >> 16;
        v261 = (char *)v326 + 1;
        v259 = v22;
        do
        {
          v24 = strchr((const char *)v21, 58);
          v25 = v24;
          if ( v24 )
          {
            v25 = v24 + 1;
            *v24 = 0;
          }
          if ( *v21 != 42 || v21[1] )
          {
            name = cmds[0].name;
            v27 = cmds;
            v28 = 0;
            if ( !cmds[0].name )
            {
LABEL_92:
              snprintf(v316, 0x1000u, v259, v21, v257);
              applog(3, v316, 1);
              quit(1);
            }
            while ( strcasecmp((const char *)v21, name) )
            {
              v29 = v27[1].name;
              ++v27;
              name = v29;
              ++v28;
              if ( !v29 )
                goto LABEL_92;
            }
            sprintf(s, v262, name);
            if ( !strstr((const char *)v326, s) )
            {
              v72 = (const char *)*((_DWORD *)&codes[67].severity + 3 * v28);
              strcpy(v261, v72);
              v73 = strlen(v72);
              v261[v73 + 1] = 0;
              v261[v73] = 124;
              v261 += v73 + 1;
            }
          }
          else
          {
            v23 = 1;
          }
          if ( !v25 )
            break;
          v21 = (unsigned __int8 *)v25;
        }
        while ( *v25 );
        if ( v23 && cmds[0].name )
        {
          v74 = cmds;
          v75 = v261;
          do
          {
            if ( !v74->iswritemode )
            {
              sprintf(s, v262);
              if ( !strstr((const char *)v326, s) )
              {
                v77 = v74->name;
                strcpy(v75, v74->name);
                v78 = &v75[strlen(v77)];
                v75 = v78 + 1;
                v78[1] = 0;
                *v78 = 124;
              }
            }
            v76 = v74[1].name;
            ++v74;
          }
          while ( v76 );
        }
      }
      v30 = strlen((const char *)v326);
      v31 = (*v17)[v257] - (*v17)[65];
      v32 = (char *)malloc(v30 + 1);
      apigroups[v31].commands = v32;
      if ( !v32 )
      {
        LOWORD(v98) = 23632;
        HIWORD(v98) = (unsigned int)"f" >> 16;
        v99 = *v98;
        v100 = v98[1];
        v101 = v98[2];
        v102 = v98[3];
        v98 += 4;
        v317[0] = v99;
        v317[1] = v100;
        v317[2] = v101;
        v317[3] = v102;
        v103 = *v98;
        v104 = v98[1];
        v105 = v98[2];
        v106 = v98[3];
        v107 = v98[4];
        v317[4] = v103;
        v317[5] = v104;
        v317[6] = v105;
        v317[7] = v106;
        v317[8] = v107;
        applog(3, (const char *)v317, 1);
        quit(1);
      }
      strcpy(v32, (const char *)v326);
      if ( !v258 )
        break;
      v10 = v258;
    }
    while ( *v258 );
  }
  v33 = _ctype_toupper_loc();
  v34 = cmds[0].name;
  v35 = v33;
  v326[0] = 124;
  if ( cmds[0].name )
  {
    v36 = cmds;
    v37 = (char *)v326 + 1;
    do
    {
      while ( v36->iswritemode )
      {
        v38 = v36[1].name;
        ++v36;
        v34 = v38;
        if ( !v38 )
          goto LABEL_51;
      }
      strcpy(v37, v34);
      v39 = strlen(v34);
      v40 = v36[1].name;
      ++v36;
      v34 = v40;
      v41 = &v37[v39];
      v37 = v41 + 1;
      *v41 = 124;
      v41[1] = 0;
    }
    while ( v40 );
  }
LABEL_51:
  v42 = strlen((const char *)v326) + 1;
  v43 = (*v35)[82];
  if ( (unsigned int)(v43 + 128) < 0x180 )
    v43 = (*v35)[v43];
  v44 = v43 - (*v35)[65];
  v45 = (char *)malloc(v42);
  apigroups[v44].commands = v45;
  if ( !v45 )
  {
    LOWORD(v181) = 23668;
    HIWORD(v181) = (unsigned int)"invalid group name '%c'" >> 16;
    v182 = *v181;
    v183 = v181[1];
    v184 = v181[2];
    v185 = v181[3];
    v181 += 4;
    v318[0] = v182;
    v318[1] = v183;
    v318[2] = v184;
    v318[3] = v185;
    v186 = *v181;
    v187 = v181[1];
    v188 = v181[2];
    v189 = v181[3];
    v181 += 4;
    v318[4] = v186;
    v318[5] = v187;
    v318[6] = v188;
    v318[7] = v189;
    v190 = v181[1];
    v191 = v181[2];
    v318[8] = *v181;
    v318[9] = v190;
    v319 = v191;
    applog(3, (const char *)v318, 1);
    quit(1);
  }
  strcpy(v45, (const char *)v326);
  free(dest);
  v46 = opt_api_allow;
  if ( opt_api_allow )
  {
    v47 = strlen(opt_api_allow);
    v48 = (char *)malloc(v47 + 1);
    v49 = v48;
    if ( !v48 )
    {
      LOWORD(v164) = 23712;
      HIWORD(v164) = (unsigned int)" be '%c'" >> 16;
      v165 = *v164;
      v166 = v164[1];
      v167 = v164[2];
      v168 = v164[3];
      v164 += 4;
      v320[0] = v165;
      v320[1] = v166;
      v320[2] = v167;
      v320[3] = v168;
      v169 = v164[1];
      v170 = v164[2];
      v171 = v164[3];
      v320[4] = *v164;
      v320[5] = v169;
      v320[6] = v170;
      v321 = v171;
      applog(3, (const char *)v320, 1);
      quit(1);
    }
    strcpy(v48, v46);
    v50 = v49 - 1;
    v51 = 1;
    while ( 1 )
    {
      v53 = (unsigned __int8)*++v50;
      v52 = v53;
      if ( !v53 )
        break;
      if ( v52 == 44 )
        ++v51;
    }
    ipaccess = (IPACCESS *)calloc(v51, 0x24u);
    if ( !ipaccess )
    {
      LOWORD(v157) = 23744;
      HIWORD(v157) = (unsigned int)"name '%c'" >> 16;
      v158 = *v157;
      v159 = v157[1];
      v160 = v157[2];
      v161 = v157[3];
      v157 += 4;
      v322[0] = v158;
      v322[1] = v159;
      v322[2] = v160;
      v322[3] = v161;
      v162 = v157[1];
      v163 = v157[2];
      v322[4] = *v157;
      v322[5] = v162;
      v323 = v163;
      applog(3, (const char *)v322, 1);
      quit(1);
    }
    v54 = 0;
    v55 = v49;
    ips = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v56 = *(unsigned __int8 *)v55;
        if ( !*v55 )
        {
LABEL_85:
          free(v49);
          if ( v54 )
            goto LABEL_86;
          if ( use_syslog || opt_log_output || opt_log_level > 3 )
          {
            LOWORD(v95) = 23428;
            LOWORD(v96) = 23772;
            HIWORD(v95) = (unsigned int)" Comms Error" >> 16;
            HIWORD(v96) = (unsigned int)" group commands buf" >> 16;
            snprintf(tmp42_0, 0x1000u, v96, v95);
            applog(4, tmp42_0, 0);
          }
LABEL_6:
          free(apisock);
          return;
        }
        while ( 1 )
        {
          v58 = v56 == 9;
          if ( v56 != 9 )
            v58 = v56 == 32;
          if ( !v58 )
            break;
          v57 = *(unsigned __int8 *)++v55;
          v56 = v57;
        }
        if ( v56 != 44 )
          break;
        ++v55;
LABEL_84:
        if ( !v55 )
          goto LABEL_85;
      }
      v59 = strchr(v55, 44);
      v60 = v59;
      if ( v59 )
      {
        v60 = v59 + 1;
        *v59 = 0;
      }
      v61 = _ctype_b_loc();
      v62 = *(unsigned __int8 *)v55;
      v63 = *v35;
      v64 = *((_BYTE *)*v35 + 328);
      if ( ((*v61)[v62] & 0x400) != 0 && v55[1] == 58 )
      {
        v108 = v63[v62];
        if ( v108 == v63[87] || apigroups[v108 - v63[65]].commands )
          v64 = v63[v62];
        v55 += 2;
      }
      v65 = &ipaccess[v54];
      v65->group = v64;
      v66 = *(unsigned __int8 *)v55;
      if ( v66 == 48 )
      {
        if ( v55[1] == 47 && v55[2] == 48 && !v55[3] )
        {
          v81 = &v65->ip.__u6_addr8[15];
          v82 = (IPACCESS *)((char *)v65 - 1);
          do
          {
            v82->ip.__u6_addr8[1] = 0;
            v82 = (IPACCESS *)((char *)v82 + 1);
            *++v81 = 0;
          }
          while ( v82 != (IPACCESS *)((char *)&v65->ip.__u6_addr32[3] + 3) );
          goto LABEL_107;
        }
        v67 = strchr(v55, 47);
        if ( v67 )
          goto LABEL_78;
      }
      else
      {
        v67 = strchr(v55, 47);
        if ( v67 )
          goto LABEL_76;
      }
      v83 = (IPACCESS *)((char *)&v65->ip.__u6_addr32[3] + 3);
      do
      {
        v83->ip.__u6_addr8[1] = -1;
        v83 = (IPACCESS *)((char *)v83 + 1);
      }
      while ( (IPACCESS *)((char *)&v65->mask.__u6_addr32[3] + 3) != v83 );
      v66 = *(unsigned __int8 *)v55;
      v67 = (char *)&v55[strlen(v55)];
LABEL_76:
      if ( v66 == 91 && *(v67 - 1) == 93 )
      {
        v68 = 1;
        *v55++ = 0;
        *(v67 - 1) = 0;
        goto LABEL_79;
      }
LABEL_78:
      v68 = 0;
LABEL_79:
      if ( *v67 )
      {
        *v67 = 0;
        v69 = strtol(v67 + 1, 0, 10);
        if ( v69 <= 0 )
          goto LABEL_83;
        if ( v68 )
        {
          if ( v69 > 128 )
            goto LABEL_83;
        }
        else
        {
          v69 += 96;
          if ( v69 > 128 )
          {
LABEL_83:
            v55 = v60;
            goto LABEL_84;
          }
        }
        v97 = (IPACCESS *)((char *)&v65->ip.__u6_addr32[3] + 3);
        v84 = 0;
        do
        {
          v97->ip.__u6_addr8[1] = 0;
          v97 = (IPACCESS *)((char *)v97 + 1);
        }
        while ( (IPACCESS *)((char *)&v65->mask.__u6_addr32[3] + 3) != v97 );
        while ( 1 )
        {
          v85 = v69-- != 0;
          v86 = 7;
          if ( !v85 )
            break;
          while ( 1 )
          {
            v65->mask.__u6_addr8[v84] |= 1 << v86;
            if ( !v86 )
              break;
            v85 = v69-- != 0;
            --v86;
            if ( !v85 )
              goto LABEL_118;
          }
          ++v84;
        }
      }
LABEL_118:
      v87 = (IPACCESS *)((char *)v65 - 1);
      do
      {
        v87->ip.__u6_addr8[1] = 0;
        v87 = (IPACCESS *)((char *)v87 + 1);
      }
      while ( (IPACCESS *)((char *)&v65->ip.__u6_addr32[3] + 3) != v87 );
      if ( v68 )
      {
        if ( inet_pton(10, v55, v65) != 1 )
          goto LABEL_83;
      }
      else
      {
        LOWORD(v94) = 20376;
        HIWORD(v94) = (unsigned int)off_54F18 >> 16;
        sprintf(cp, v94, v55);
        v54 = ips;
        v65 = &ipaccess[ips];
        if ( inet_pton(10, cp, v65) != 1 )
        {
          v55 = v60;
          goto LABEL_84;
        }
      }
      v88 = &v65->ip.__u6_addr8[15];
      v89 = (uint8_t *)(&v65[-1].group + 3);
      v90 = &v65->ip.__u6_addr8[15];
      do
      {
        v92 = *++v89;
        v91 = v92;
        v93 = *++v88;
        *v89 = v91 & v93;
      }
      while ( v89 != v90 );
LABEL_107:
      v55 = v60;
      ips = ++v54;
      if ( !v60 )
        goto LABEL_85;
    }
  }
LABEL_86:
  v3 = (io_data *)v266;
  cgsleep_ms(1000 * opt_log_interval);
  LOWORD(v70) = -22732;
  HIWORD(v70) = (unsigned int)"dev.timeout = %d us" >> 16;
  sprintf(port_s, v70, v266);
  hints.ai_flags = 1;
  memset(&hints.ai_family, 0, 28);
  protocol = getaddrinfo(opt_api_host, port_s, &hints, &res);
  if ( protocol )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      LOWORD(v71) = 23816;
      HIWORD(v71) = (unsigned int)"roup commands buf" >> 16;
      snprintf(tmp42_1, 0x1000u, v71, opt_api_host);
      applog(3, tmp42_1, 0);
    }
    goto LABEL_6;
  }
  v109 = res;
  if ( res )
  {
    for ( i = res; ; i = res )
    {
      v111 = socket(i->ai_family, 1, protocol);
      *apisock = v111;
      if ( v111 > 0 )
        break;
      v109 = v109->ai_next;
      if ( !v109 )
        goto LABEL_223;
    }
  }
  else
  {
    v111 = *apisock;
LABEL_223:
    if ( v111 == -1 )
    {
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        v153 = _errno_location();
        v154 = strerror(*v153);
        LOWORD(v155) = 23428;
        HIWORD(v155) = (unsigned int)" Comms Error" >> 16;
        LOWORD(v156) = 23844;
        HIWORD(v156) = (unsigned int)"o malloc ipaccess buf" >> 16;
        snprintf(tmp42_2, 0x1000u, v156, v154, v155);
        applog(3, tmp42_2, 0);
      }
      freeaddrinfo(res);
      free(apisock);
      return;
    }
    v109 = 0;
  }
  optval = 1;
  if ( setsockopt(v111, 1, 2, &optval, 4u) < 0 && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
  {
    v112 = _errno_location();
    v113 = strerror(*v112);
    LOWORD(v114) = 23880;
    HIWORD(v114) = (unsigned int)"lloc ipaccess" >> 16;
    snprintf(tmp42_3, 0x1000u, v114, v113);
    applog(7, tmp42_3, 0);
  }
  LOWORD(v115) = 23932;
  v116 = time(0);
  while ( bind(*apisock, v109->ai_addr, v109->ai_addrlen) < 0 )
  {
    v117 = _errno_location();
    v5 = strerror(*v117);
    if ( time(0) - v116 > 61 )
      goto LABEL_253;
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      HIWORD(v115) = (unsigned int)"ied)%s" >> 16;
      snprintf(tmp42_4, 0x1000u, v115, v266);
      applog(4, tmp42_4, 0);
    }
    cgsleep_ms(30000);
  }
  freeaddrinfo(res);
  if ( listen(*apisock, 100) < 0 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      v214 = _errno_location();
      v215 = strerror(*v214);
      LOWORD(v216) = 23428;
      HIWORD(v216) = (unsigned int)" Comms Error" >> 16;
      LOWORD(v217) = 24020;
      HIWORD(v217) = (unsigned int)"O_REUSEADDR failed (ignored): %s" >> 16;
      snprintf(tmp42_6, 0x1000u, v217, v215, v216);
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
      LOWORD(v118) = 24056;
      HIWORD(v118) = (unsigned int)"API bind to port %d failed - trying again in 30sec" >> 16;
      snprintf(tmp42_7, 0x1000u, v118, v266, *apisock);
      applog(4, tmp42_7, 0);
    }
  }
  else if ( opt_api_network )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 3 )
    {
      LOWORD(v218) = 24104;
      HIWORD(v218) = (unsigned int)"ec" >> 16;
      snprintf(tmp42_8, 0x1000u, v218, v266, *apisock);
      applog(4, tmp42_8, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 3 )
  {
    LOWORD(v219) = 24168;
    HIWORD(v219) = (unsigned int)"ed (%s)%s" >> 16;
    snprintf(tmp42_9, 0x1000u, v219, v266, *apisock);
    applog(4, tmp42_9, 0);
  }
  if ( opt_api_mcast )
    mcast_init();
  LOWORD(file) = 20356;
  HIWORD(file) = (unsigned int)&_func___11888.__data.__nusers >> 16;
  LOWORD(v120) = 24224;
  HIWORD(v120) = (unsigned int)")" >> 16;
  v121 = 0;
  strbufs = k_new_list(v120, 0xCu, 2, 0, 0, file, (const char *)&_func___12699, 5409);
  while ( 1 )
  {
    v122 = bye;
    if ( bye )
      goto die;
    clisiz = 128;
    c = accept(*apisock, (struct sockaddr *)&cli, &clisiz);
    if ( c < 0 )
      break;
    v123 = check_connect(&cli, &connectaddr, &group);
    v124 = v123;
    if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
    {
      LOWORD(v125) = 20412;
      LOWORD(v126) = 20400;
      HIWORD(v126) = (unsigned int)&_func___12699.__data.__nusers >> 16;
      if ( !v123 )
      {
        HIWORD(v125) = (unsigned int)"ATUS\":\"RESTART\"" >> 16;
        v126 = v125;
      }
      LOWORD(v127) = 24256;
      HIWORD(v127) = (unsigned int)"read access mode on port %d (%d)" >> 16;
      snprintf(tmp42_11, 0x1000u, v127, connectaddr, v126);
      applog(7, tmp42_11, 0);
    }
    if ( v124 )
    {
      v128 = recv(c, buf, 0x1FFFu, 0);
      v129 = v128;
      v130 = opt_debug;
      if ( v128 >= 0 )
      {
        buf[v128] = 0;
        if ( v130 && (use_syslog || opt_log_output || opt_log_level > 6) )
        {
          LOWORD(v131) = 24312;
          HIWORD(v131) = (unsigned int)" read access mode on port %d (%d)" >> 16;
          snprintf(tmp42_13, 0x1000u, v131, v128, buf);
          applog(7, tmp42_13, 0);
        }
        v132 = buf;
        v133 = time(0);
        ptr = io_data->ptr;
        io_data->cur = ptr;
        when = v133;
        *ptr = 0;
        v135 = (unsigned __int8)buf[0];
        io_data->close = 0;
        if ( v135 == 123 )
        {
          v209 = json_loadb(buf, v129, 0, &json_err);
          json_config = v209;
          if ( v209 && v209->type == JSON_OBJECT )
          {
            v220 = json_object_get(v209, "command");
            if ( v220 )
            {
              if ( v220->type == JSON_STRING )
              {
                v250 = json_string_value(v220);
                LOWORD(v251) = 25248;
                v132 = (char *)v250;
                HIWORD(v251) = (unsigned int)"Missing device id parameter" >> 16;
                v252 = json_object_get(json_config, v251);
                if ( v252 )
                {
                  type = v252->type;
                  if ( v252->type == JSON_STRING )
                  {
                    param = (char *)json_string_value(v252);
                  }
                  else if ( type == JSON_INTEGER )
                  {
                    v255 = json_integer_value(v252);
                    LOWORD(v256) = -22732;
                    HIWORD(v256) = (unsigned int)"dev.timeout = %d us" >> 16;
                    param = param_buf;
                    sprintf(param_buf, v256, v255);
                  }
                  else if ( type == JSON_REAL )
                  {
                    json_real_value(v252);
                    LOWORD(v254) = 21516;
                    HIWORD(v254) = (unsigned int)"remaining %d (sendc=%d)" >> 16;
                    param = param_buf;
                    sprintf(param_buf, v254);
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
          if ( v121 )
            send_result((io_data *)io_data->ptr, io_data->close, c, v124);
LABEL_215:
          if ( json_config )
            v152 = v124 & 1;
          else
            v152 = 0;
          if ( v152 )
          {
            if ( json_config->type == JSON_OBJECT )
            {
              refcount = json_config->refcount;
              if ( refcount != -1 )
              {
                v213 = refcount - 1;
                json_config->refcount = v213;
                if ( !v213 )
                  json_delete(json_config);
              }
            }
          }
          goto LABEL_220;
        }
        v136 = strchr(buf, 124);
        if ( v136 )
        {
          v124 = v122;
          *v136 = 0;
          param = v136 + 1;
        }
        else
        {
          param = 0;
          v124 = v122;
        }
LABEL_191:
        cmdsbuf = strchr(v132, 43);
        if ( cmdsbuf )
        {
          v121 = 1;
          firstjoin = 1;
          v137 = strlen(v132);
          cmdsbuf = (char *)malloc(v137 + 3);
          if ( !cmdsbuf )
          {
            LOWORD(v210) = 20356;
            LOWORD(v211) = 24344;
            HIWORD(v210) = (unsigned int)&_func___11888.__data.__nusers >> 16;
            HIWORD(v211) = (unsigned int)")" >> 16;
            snprintf(tmp42_14, 0x1000u, v211, v210, &_func___12699, 5520);
            applog(3, tmp42_14, 1);
            quit(1);
          }
          param = 0;
          *(_WORD *)cmdsbuf = 124;
        }
        else
        {
          v121 = v122;
          firstjoin = 0;
        }
        v138 = v132;
        if ( !v121 )
        {
          v141 = cmds[0].name;
          if ( cmds[0].name )
            goto LABEL_204;
          goto LABEL_237;
        }
        while ( 2 )
        {
          v139 = strchr(v138, 43);
          v132 = v139;
          if ( v139 )
          {
            v132 = v139 + 1;
            *v139 = 0;
          }
          if ( !*v138 )
          {
LABEL_198:
            if ( v132 )
              v140 = v121 & 1;
            else
              v140 = 0;
            v138 = v132;
            if ( !v140 )
              goto LABEL_283;
            continue;
          }
          break;
        }
        v141 = cmds[0].name;
        if ( cmds[0].name )
        {
LABEL_204:
          v142 = cmds;
          v143 = 0;
          while ( strcmp(v138, v141) )
          {
            v144 = v142[1].name;
            ++v142;
            v141 = v144;
            ++v143;
            if ( !v144 )
            {
              if ( !v121 )
                goto LABEL_237;
              goto LABEL_236;
            }
          }
          LOWORD(v145) = 21852;
          HIWORD(v145) = (unsigned int)"expiry" >> 16;
          sprintf(cmdbuf, v145, v138);
          if ( v121 )
          {
            if ( strstr(cmdsbuf, cmdbuf) )
              goto LABEL_198;
            v146 = strlen(cmdsbuf);
            v147 = (_WORD *)stpcpy(&cmdsbuf[v146], v138);
            LOWORD(v148) = -2396;
            HIWORD(v148) = (unsigned int)"ation" >> 16;
            *v147 = *v148;
            head_join(io_data, v138, v124, &firstjoin);
            v149 = (char **)codes + 3 * v143;
            if ( !*((_BYTE *)v149 + 1081) )
            {
              message(io_data, 45, *((unsigned __int8 *)v149 + 1081), v149[268], v124);
              tail_join(io_data, v124);
              goto inochi;
            }
          }
          v150 = (unsigned __int8)group;
          v151 = (*v35)[(unsigned __int8)group];
          if ( v151 == (*v35)[87] || strstr(apigroups[v151 - (*v35)[65]].commands, cmdbuf) )
          {
            (*((void (__fastcall **)(io_data *, int, char *, int, int))&codes[67].code + 3 * v143))(
              io_data,
              c,
              param,
              v124,
              v150);
          }
          else
          {
            message(io_data, 45, 0, *((char **)&codes[67].severity + 3 * v143), v124);
            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
            {
              LOWORD(v172) = 24372;
              HIWORD(v172) = (unsigned int)"s (%d)" >> 16;
              snprintf(tmp42_15, 0x1000u, v172, connectaddr, *((_DWORD *)&codes[67].severity + 3 * v143));
              applog(7, tmp42_15, 0);
            }
          }
          if ( (unsigned __int8)v121 == 1 )
            goto LABEL_238;
        }
        else
        {
LABEL_236:
          head_join(io_data, v138, v124, &firstjoin);
LABEL_237:
          message(io_data, 14, 0, 0, v124);
          if ( v121 )
          {
LABEL_238:
            tail_join(io_data, v124);
inochi:
            if ( !v121 )
              goto LABEL_215;
            goto LABEL_198;
          }
        }
        send_result((io_data *)io_data->ptr, io_data->close, c, v124);
        goto inochi;
      }
      buf[0] = 0;
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
      {
        v173 = _errno_location();
        v174 = strerror(*v173);
        LOWORD(v175) = 24288;
        HIWORD(v175) = (unsigned int)"" >> 16;
        snprintf(tmp42_12, 0x1000u, v175, v174);
        applog(7, tmp42_12, 0);
      }
    }
LABEL_220:
    close(c);
  }
  if ( use_syslog || opt_log_output || opt_log_level > 2 )
  {
    v200 = _errno_location();
    v201 = strerror(*v200);
    snprintf(tmp42_10, 0x1000u, "API failed (%s)%s (%d)", v201, " - API will not be available", *apisock);
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
      v203 = "QUIT";
    }
    else if ( do_a_restart )
    {
      v203 = "RESTART";
    }
    else
    {
      LOWORD(v202) = 20276;
      LOWORD(v203) = 23416;
      HIWORD(v203) = (unsigned int)" Cutoff" >> 16;
      if ( bye )
      {
        HIWORD(v202) = (unsigned int)&_func___12372.__data.__owner >> 16;
        v203 = v202;
      }
    }
    LOWORD(v204) = 24416;
    HIWORD(v204) = (unsigned int)" recv failed: %s" >> 16;
    snprintf(tmp42_16, 0x1000u, v204, v203);
    applog(7, tmp42_16, 0);
  }
  if ( pthread_mutex_lock(&quit_restart_lock) )
    mutex_lock_1((pthread_mutex_t *)&_func___12699, (const char *)0x15F3, v205, v206);
  if ( do_a_restart )
  {
    LOWORD(v236) = -9939;
    HIWORD(v236) = (unsigned int)&loc_2D81C >> 16;
    if ( thr_info_create(&bye_thr, 0, v236, &bye_thr) )
    {
      if ( !pthread_mutex_unlock(&quit_restart_lock) )
      {
        LOWORD(v239) = 24444;
        HIWORD(v239) = (unsigned int)"v command: (%d) '%s'" >> 16;
        selective_yield();
        v240 = *v239;
        v241 = v239[1];
        v242 = v239[2];
        v243 = v239[3];
        v239 += 4;
        *(_DWORD *)tmp42_17 = v240;
        *(_DWORD *)&tmp42_17[4] = v241;
        *(_DWORD *)&tmp42_17[8] = v242;
        *(_DWORD *)&tmp42_17[12] = v243;
        v244 = *v239;
        v245 = v239[1];
        v246 = v239[2];
        v247 = v239[3];
        v239 += 4;
        *(_DWORD *)&tmp42_17[16] = v244;
        *(_DWORD *)&tmp42_17[20] = v245;
        *(_DWORD *)&tmp42_17[24] = v246;
        *(_DWORD *)&tmp42_17[28] = v247;
        v248 = v239[1];
        v249 = v239[2];
        *(_DWORD *)&tmp42_17[32] = *v239;
        *(_DWORD *)&tmp42_17[36] = v248;
        *(_DWORD *)&tmp42_17[40] = v249;
        applog(3, tmp42_17, 1);
        quit(1);
      }
      mutex_unlock_noyield_1((pthread_mutex_t *)&_func___12699, (const char *)0x15F9, v237, v238);
    }
  }
  else
  {
    if ( !do_a_quit )
      goto LABEL_277;
    LOWORD(v221) = -10219;
    HIWORD(v221) = (unsigned int)&loc_2D704 >> 16;
    if ( thr_info_create(&bye_thr, (pthread_attr_t *)do_a_restart, v221, &bye_thr) )
    {
      if ( pthread_mutex_unlock(&quit_restart_lock) )
        mutex_unlock_noyield_1((pthread_mutex_t *)&_func___12699, (const char *)0x1602, v222, v223);
      LOWORD(v224) = 24488;
      HIWORD(v224) = (unsigned int)"():%d" >> 16;
      selective_yield();
      v225 = *v224;
      v226 = v224[1];
      v227 = v224[2];
      v228 = v224[3];
      v224 += 4;
      *(_DWORD *)tmp42_18 = v225;
      *(_DWORD *)&tmp42_18[4] = v226;
      *(_DWORD *)&tmp42_18[8] = v227;
      *(_DWORD *)&tmp42_18[12] = v228;
      v229 = *v224;
      v230 = v224[1];
      v231 = v224[2];
      v232 = v224[3];
      v224 += 4;
      *(_DWORD *)&tmp42_18[16] = v229;
      *(_DWORD *)&tmp42_18[20] = v230;
      *(_DWORD *)&tmp42_18[24] = v231;
      *(_DWORD *)&tmp42_18[28] = v232;
      v233 = v224[1];
      v234 = v224[2];
      v235 = v224[3];
      *(_DWORD *)&tmp42_18[32] = *v224;
      *(_DWORD *)&tmp42_18[36] = v233;
      *(_DWORD *)&tmp42_18[40] = v234;
      *(_WORD *)&tmp42_18[44] = v235;
      tmp42_18[46] = BYTE2(v235);
      applog(3, tmp42_18, 1);
      quit(1);
    }
  }
  pthread_detach(bye_thr.pth);
LABEL_277:
  if ( pthread_mutex_unlock(&quit_restart_lock) )
    mutex_unlock_noyield_1((pthread_mutex_t *)&_func___12699, (const char *)0x1608, v207, v208);
  selective_yield();
}
