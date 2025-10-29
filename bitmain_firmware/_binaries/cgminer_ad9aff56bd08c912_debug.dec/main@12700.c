int __fastcall main(int argc, const char **argv, const char **envp)
{
  int v3; // r0
  int (*v4)(void); // r2
  int (**v5)(void); // r3
  bool v6; // zf
  int v7; // r0
  char **v8; // r0
  int v9; // r3
  char **v10; // r4
  char **v11; // r6
  int v12; // r5
  char **v13; // r8
  const char *v14; // t1
  char *v15; // r0
  int v16; // r3
  int v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r3
  int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r3
  thread_q *v26; // r0
  char *v27; // r0
  char *v28; // r0
  char *v29; // r6
  char *v30; // r5
  char *v31; // r0
  char *v32; // r4
  size_t v33; // r0
  __int16 v34; // r3
  char *v35; // r6
  int v36; // r8
  size_t v37; // r0
  int v38; // r3
  int v39; // r3
  int v40; // r2
  unsigned int v41; // r5
  int v42; // r9
  int v43; // r3
  size_t v44; // r8
  int v45; // r3
  unsigned __int8 *v46; // lr
  int v47; // r4
  int v48; // r2
  int v49; // r9
  int v50; // r1
  unsigned __int8 *v51; // r12
  int v52; // r0
  unsigned int v53; // r2
  unsigned int v54; // r5
  int v55; // r4
  unsigned int v56; // r5
  unsigned int v57; // r2
  int v58; // r4
  unsigned int v59; // r5
  unsigned int v60; // r3
  unsigned __int8 *v61; // r10
  size_t v62; // r0
  size_t v63; // r2
  int v64; // r3
  unsigned int v65; // r5
  unsigned int v66; // r2
  int v67; // r3
  unsigned int v68; // r5
  unsigned int v69; // r2
  int v70; // r3
  unsigned int v71; // r3
  int v72; // r0
  int v73; // r3
  _DWORD *v74; // r2
  int v75; // r3
  __int64 v76; // kr08_8
  int v77; // r4
  int v78; // r4
  pool *v79; // r5
  char *v80; // r0
  int v81; // r3
  char *rpc_url; // r3
  pool_enable enabled; // r3
  unsigned __int8 *v84; // r9
  int v85; // r4
  unsigned __int8 *v86; // r5
  unsigned __int8 *v87; // r0
  const char *v88; // r1
  double v89; // r2
  const char *v90; // r0
  FILE *v91; // r4
  signed int v92; // r0
  char *v93; // r0
  char *v94; // r4
  int v95; // r3
  int v96; // r3
  int v97; // r3
  int v98; // r3
  int v99; // r4
  const char *v100; // r1
  const char *v101; // r1
  const char *v102; // r4
  const char *v103; // r0
  int v104; // r0
  FILE *v105; // r0
  _BOOL4 v106; // r3
  int v107; // r3
  int v108; // r4
  int v109; // r11
  FILE *v110; // r0
  bool *v111; // r3
  int v112; // r3
  bool *v113; // r8
  int v114; // r11
  int i1; // r4
  FILE *v116; // r0
  bool *v117; // r3
  const char *v118; // r3
  int v119; // r3
  int v120; // r4
  int v121; // r3
  thr_info *v122; // r4
  char **v123; // r3
  device_drv *v124; // r2
  device_drv *v125; // r3
  device_drv *v126; // r0
  int v127; // r2
  int v128; // r0
  device_drv *v129; // r3
  device_drv *v130; // r2
  device_drv *v131; // r12
  device_drv *v132; // r12
  device_drv *v133; // r3
  device_drv *v134; // r12
  device_drv *v135; // r12
  device_drv *v136; // r12
  device_drv *v137; // r12
  device_drv *v138; // r12
  size_t *v139; // r12
  int v140; // r1
  int v141; // r5
  device_drv *v142; // r10
  pthread_rwlock_t *v143; // r0
  char *v144; // r0
  int v145; // r4
  unsigned int v146; // r5
  char *i; // r0
  const char *v148; // r2
  int v149; // r3
  _DWORD *v150; // r8
  unsigned int v151; // r0
  unsigned int v152; // r3
  int v153; // r0
  char *v154; // r11
  _DWORD *v155; // r5
  _DWORD *v156; // r6
  int v157; // r4
  char *v158; // r9
  unsigned int v159; // r2
  int v160; // r3
  _DWORD *v161; // r3
  unsigned int v162; // r2
  unsigned int v163; // r1
  bool v164; // cc
  int v165; // r2
  int v166; // r3
  int v167; // r3
  _DWORD *v168; // r0
  _DWORD *v169; // r4
  void *v170; // r0
  char *v171; // r0
  int v172; // r5
  int v173; // r5
  char v174; // r3
  char *v175; // r5
  char *v176; // r4
  char *v177; // r5
  int v178; // r0
  int v179; // r1
  int v180; // r2
  int v181; // r3
  _DWORD *v182; // r4
  _DWORD *v183; // r5
  int v184; // r1
  FILE *v185; // r0
  _BOOL4 v186; // r3
  int v187; // r0
  const char *v188; // r2
  int v189; // r3
  int v190; // r2
  cgpu_info **v191; // r4
  cgpu_info *v192; // r3
  const char *v193; // r2
  int v194; // r3
  int v195; // r0
  drv_driver drv_id; // r4
  int j; // r3
  int v198; // r2
  int v199; // r8
  _DWORD *v200; // r3
  int v201; // r9
  int v202; // r3
  size_t v203; // r5
  size_t v204; // r4
  char *v205; // r0
  __int64 v206; // kr10_8
  _BOOL4 v207; // r2
  __sighandler_t v208; // r4
  __sighandler_t v209; // r0
  __pid_t v210; // r0
  __pid_t v211; // r4
  thr_info **v212; // r4
  int *v213; // r8
  int v214; // r5
  int *v215; // r6
  int v216; // r4
  int v217; // r6
  cgpu_info *v218; // r5
  size_t v219; // r4
  thr_info **v220; // r0
  char *v221; // r3
  int v222; // r4
  thr_info *thread; // r0
  device_drv *v224; // r3
  thr_info *v225; // r8
  int *v226; // r0
  const char *v227; // r2
  int v228; // r3
  int v229; // r2
  cgpu_info **v230; // r3
  cgpu_info *v231; // r1
  const char *v232; // r2
  int v233; // r3
  int *v234; // r0
  drv_driver v235; // r4
  int v236; // r1
  drv_driver v237; // r0
  int v238; // r5
  int v239; // r4
  char **v240; // r8
  int v241; // r5
  device_drv *v242; // r8
  int k; // r4
  int v244; // r3
  thr_info *v245; // r5
  thr_info *v246; // r6
  thr_info *v247; // r3
  int v248; // r3
  int v249; // r4
  int v250; // r3
  bool *v251; // r10
  device_drv *v252; // r5
  work *v253; // r10
  __int64 v254; // kr18_8
  void (*thread_shutdown)(thr_info *); // r5
  int v256; // r3
  pthread_mutex_t *v257; // r1
  void (*v258)(thr_info *); // r3
  int v259; // r4
  void (*v260)(thr_info *); // r3
  device_drv *v261; // r1
  work *v262; // r0
  work *v263; // r10
  pool *v264; // r0
  int v265; // r3
  pool *v266; // r5
  pool *v267; // r4
  char **v268; // r10
  pool *v269; // r0
  int v270; // r3
  pool *v271; // r5
  int v272; // r3
  char *v273; // r2
  drv_driver v274; // r1
  __int64 v275; // kr20_8
  int kk; // r3
  int v277; // r5
  int v278; // r3
  pool *v279; // r5
  int mm; // r4
  int v281; // r2
  __int64 v282; // kr28_8
  int v283; // r2
  device_drv *v284; // r3
  int v285; // r1
  int v286; // r2
  int v287; // r3
  int v288; // r0
  int v289; // r1
  int v290; // r2
  pool **v291; // r3
  _BYTE *v292; // r3
  const char *v293; // r5
  int v294; // r0
  int v295; // r1
  int v296; // r2
  int v297; // r3
  _DWORD *v298; // r5
  int v299; // r1
  int v300; // r2
  work *v301; // r0
  device_drv *v302; // r3
  double v303; // r2
  int nn; // r4
  pool *v305; // r0
  pool *v306; // r0
  drv_driver v307; // r1
  char *v308; // r2
  int m; // r3
  __int64 v310; // kr30_8
  int v311; // r3
  char **v312; // r4
  int ii; // r3
  int v314; // r8
  int v315; // r2
  __int64 v316; // kr38_8
  pool *v317; // r0
  int v318; // r3
  char **v319; // r4
  int jj; // r8
  pool *v321; // r0
  int *v322; // r0
  const char *v323; // r2
  int v324; // r4
  int v325; // r0
  signed int v326; // r1
  int v327; // r3
  int v328; // r4
  int *v329; // r0
  int n; // r3
  int v331; // r4
  int v332; // r4
  int *v333; // r0
  int result; // r0
  char v335; // [sp+10h] [bp-2010h] BYREF
  char v336[4088]; // [sp+1018h] [bp-1008h] BYREF
  const char *v337; // [sp+2010h] [bp-10h]
  thr_info **v338; // [sp+2020h] [bp+0h]
  char **v339; // [sp+2024h] [bp+4h]
  size_t *v340; // [sp+2028h] [bp+8h]
  device_drv *v341; // [sp+202Ch] [bp+Ch]
  device_drv *v342; // [sp+2030h] [bp+10h]
  device_drv *v343; // [sp+2034h] [bp+14h]
  device_drv *v344; // [sp+2038h] [bp+18h]
  device_drv *v345; // [sp+203Ch] [bp+1Ch]
  device_drv *v346; // [sp+2040h] [bp+20h]
  device_drv *v347; // [sp+2044h] [bp+24h]
  device_drv *v348; // [sp+2048h] [bp+28h]
  device_drv *v349; // [sp+204Ch] [bp+2Ch]
  device_drv *v350; // [sp+2050h] [bp+30h]
  __int64 v351; // [sp+2054h] [bp+34h]
  int v352; // [sp+205Ch] [bp+3Ch]
  device_drv *v353; // [sp+2060h] [bp+40h]
  device_drv *v354; // [sp+2064h] [bp+44h]
  device_drv *drv; // [sp+2068h] [bp+48h]
  char **argva; // [sp+206Ch] [bp+4Ch]
  __int64 work; // [sp+2070h] [bp+50h]
  bool *v358; // [sp+2078h] [bp+58h]
  int argca; // [sp+207Ch] [bp+5Ch] BYREF
  struct sigaction act; // [sp+2084h] [bp+64h] BYREF
  char s[256]; // [sp+2110h] [bp+F0h] BYREF
  char str[4100]; // [sp+2210h] [bp+1F0h] BYREF

  argca = argc;
  v358 = &use_syslog;
  argva = (char **)argv;
  set_miner_name("Z15e");
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(str, "z15e init...\n");
    applog(5, str, 0);
  }
  v354 = (device_drv *)g_logfile_openflag;
  strcpy(g_logfile_path, "cgminer.log");
  drv = (device_drv *)&g_logfile_enable;
  strcpy(g_logfile_openflag, "a+");
  g_logfile_enable = 0;
  v3 = sysconf(84);
  v6 = v3 == 1;
  if ( v3 == 1 )
  {
    v5 = &selective_yield;
    v4 = sched_yield;
  }
  v7 = argca + 1;
  if ( v6 )
    *v5 = v4;
  HIDWORD(work) = &opt_logfile_path;
  v8 = (char **)malloc(4 * v7);
  v9 = argca;
  v10 = v8;
  initial_args = v8;
  if ( argca > 0 )
  {
    v11 = v8 - 1;
    v12 = 0;
    v13 = argva - 1;
    do
    {
      v14 = v13[1];
      ++v13;
      ++v12;
      v15 = _strdup(v14);
      v9 = argca;
      v11[1] = v15;
      ++v11;
    }
    while ( v9 > v12 );
  }
  v10[v9] = 0;
  mutex_init_0(
    &hash_lock,
    (pthread_mutex_t *)(&_func___17121.__align + 7),
    (const char *)0x29E4,
    (unsigned __int16)&bench_lodiff_bins[2][12]);
  mutex_init_0(&update_job_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29E5, v16);
  mutex_init_0(&console_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29E6, v17);
  cglock_init_constprop_65((int)&control_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29E7);
  mutex_init_0(&stats_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29E8, v18);
  LODWORD(work) = &bench_lodiff_bins[2][12];
  mutex_init_0(
    &sharelog_lock,
    (pthread_mutex_t *)(&_func___17121.__align + 7),
    (const char *)0x29E9,
    (const int)&bench_lodiff_bins[2][12]);
  cglock_init_constprop_65((int)&ch_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29EA);
  mutex_init_0(&sshare_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29EB, v19);
  rwlock_init_0(&blk_lock, (pthread_rwlock_t *)(&_func___17121.__align + 7), (const char *)0x29EC, v20);
  rwlock_init_0(&netacc_lock, (pthread_rwlock_t *)(&_func___17121.__align + 7), (const char *)0x29ED, v21);
  rwlock_init_0(&mining_thr_lock, (pthread_rwlock_t *)(&_func___17121.__align + 7), (const char *)0x29EE, v22);
  rwlock_init_0(&devices_lock, (pthread_rwlock_t *)(&_func___17121.__align + 7), (const char *)0x29EF, v23);
  mutex_init_0(&lp_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29F1, v24);
  if ( pthread_cond_init(&lp_cond, 0) )
  {
    strcpy(str, "Failed to pthread_cond_init lp_cond");
    applog(3, str, 1);
    _quit(1, 0);
  }
  mutex_init_0(&restart_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29F5, v25);
  if ( pthread_cond_init(&restart_cond, 0) )
  {
    strcpy(str, "Failed to pthread_cond_init restart_cond");
    goto LABEL_184;
  }
  v352 = pthread_cond_init(&gws_cond, 0);
  if ( v352 )
  {
    strcpy(str, "Failed to pthread_cond_init gws_cond");
    applog(3, str, 1);
    _quit(1, 0);
  }
  v26 = tq_new();
  getq = v26;
  if ( !v26 )
  {
    strcpy(str, "Failed to create getq");
    applog(3, str, 1);
    _quit(1, 0);
  }
  v337 = (const char *)&unk_5328C;
  *(_DWORD *)(HIDWORD(work) + 0x444) = &v26->mutex;
  snprintf(packagename, 0x100u, "%s %s", "cgminer", v337);
  act.sa_handler = sighandler;
  act.sa_flags = v352;
  sigemptyset(&act.sa_mask);
  sigaction_0(15, &act, &termhandler);
  sigaction_0(2, &act, &inthandler);
  signal(13, (__sighandler_t)1);
  opt_kernel_path = v336;
  v350 = (device_drv *)&opt_kernel_path;
  strcpy(v336, "/usr/local/bin");
  cgminer_path = &v335;
  v27 = *argva;
  HIDWORD(v351) = &word_4F7D0;
  v28 = _strdup(v27);
  v29 = cgminer_path;
  v30 = v28;
  v31 = dirname(v28);
  strcpy(v29, v31);
  free(v30);
  v32 = cgminer_path;
  v33 = strlen(cgminer_path);
  v34 = *(_WORD *)HIDWORD(v351);
  *(_DWORD *)(work + 0xA50) = 9;
  *(_WORD *)&v32[v33] = v34;
  v35 = (char *)calloc(0x68u, 1u);
  if ( !v35 )
  {
    strcpy(str, "main OOM");
    goto LABEL_189;
  }
  v36 = 36;
  do
  {
    --v36;
    *(_WORD *)&v35[strlen(v35)] = 48;
  }
  while ( v36 );
  *((_DWORD *)v35 + 19) = 0;
  *((_DWORD *)v35 + 22) = v35;
  v37 = strlen(v35);
  v38 = work;
  *((_DWORD *)v35 + 23) = v37;
  v39 = *(_DWORD *)(v38 + 0x9E0);
  if ( v39 )
  {
    v40 = *(_DWORD *)(v39 + 68);
    v353 = (device_drv *)(v35 + 68);
    *(_DWORD *)(*(_DWORD *)(v40 + 16) + 8) = v35;
    *((_DWORD *)v35 + 18) = *(_DWORD *)(*(_DWORD *)(v39 + 68) + 16) - *(_DWORD *)(*(_DWORD *)(v39 + 68) + 20);
    *(_DWORD *)(*(_DWORD *)(v39 + 68) + 16) = v35 + 68;
  }
  else
  {
    v167 = work;
    *((_DWORD *)v35 + 18) = 0;
    *(_DWORD *)(v167 + 0x9E0) = v35;
    v168 = malloc(0x2Cu);
    v169 = v168;
    *((_DWORD *)v35 + 17) = v168;
    if ( !v168 )
      goto LABEL_172;
    memset(v168 + 3, 0, 0x20u);
    v169[1] = 32;
    v353 = (device_drv *)(v35 + 68);
    v169[2] = 5;
    v169[4] = v35 + 68;
    v169[5] = 68;
    v170 = calloc(0x180u, 1u);
    *v169 = v170;
    if ( !v170 )
      goto LABEL_172;
    v169[10] = -1609490463;
  }
  LOWORD(v41) = 31161;
  v42 = *(_DWORD *)(work + 0x9E0);
  ++*(_DWORD *)(*(_DWORD *)(v42 + 68) + 12);
  v43 = *(_DWORD *)(v42 + 68);
  *((_DWORD *)v35 + 24) = -17973521;
  *((_DWORD *)v35 + 17) = v43;
  v44 = strlen(v35);
  if ( v44 <= 0xB )
  {
    HIWORD(v41) = -25033;
    v61 = (unsigned __int8 *)v35;
    v47 = v41;
  }
  else
  {
    HIWORD(v41) = -25033;
    v45 = -17973521;
    v46 = (unsigned __int8 *)(v35 + 12);
    v47 = v41;
    LODWORD(v351) = v42;
    do
    {
      v48 = *(v46 - 2);
      v44 -= 12;
      v49 = *(v46 - 3);
      v50 = *(v46 - 6);
      v51 = v46;
      v52 = *(v46 - 10);
      v46 += 12;
      v53 = (v48 << 16) + (v49 << 8) + *(v46 - 16) + (*(v46 - 13) << 24) + v45;
      v54 = v41 + (v50 << 16) + (*(v46 - 19) << 8) + *(v46 - 20) + (*(v46 - 17) << 24);
      v55 = (v47 + (v52 << 16) + (*(v46 - 23) << 8) + *(v46 - 24) + (*(v46 - 21) << 24) - v53 - v54) ^ (v53 >> 13);
      v56 = (v54 - v53 - v55) ^ (v55 << 8);
      v57 = (v53 - v55 - v56) ^ (v56 >> 13);
      v58 = (v55 - v56 - v57) ^ (v57 >> 12);
      v59 = (v56 - v57 - v58) ^ (v58 << 16);
      v60 = (v57 - v58 - v59) ^ (v59 >> 5);
      v47 = (v58 - v59 - v60) ^ (v60 >> 3);
      v41 = (v59 - v60 - v47) ^ (v47 << 10);
      v45 = (v60 - v47 - v41) ^ (v41 >> 15);
      *((_DWORD *)v35 + 24) = v45;
    }
    while ( v44 > 0xB );
    v42 = v351;
    v61 = v51;
  }
  v62 = strlen(v35) + *((_DWORD *)v35 + 24);
  *((_DWORD *)v35 + 24) = v62;
  v63 = v62;
  switch ( v44 )
  {
    case 1u:
      goto LABEL_37;
    case 2u:
      goto LABEL_36;
    case 3u:
      goto LABEL_35;
    case 4u:
      goto LABEL_34;
    case 5u:
      goto LABEL_33;
    case 6u:
      goto LABEL_32;
    case 7u:
      goto LABEL_31;
    case 8u:
      goto LABEL_30;
    case 9u:
      goto LABEL_29;
    case 0xAu:
      goto LABEL_28;
    case 0xBu:
      v63 = v62 + (v61[10] << 24);
      *((_DWORD *)v35 + 24) = v63;
LABEL_28:
      v63 += v61[9] << 16;
      *((_DWORD *)v35 + 24) = v63;
LABEL_29:
      v63 += v61[8] << 8;
      *((_DWORD *)v35 + 24) = v63;
LABEL_30:
      v41 += v61[7] << 24;
LABEL_31:
      v41 += v61[6] << 16;
LABEL_32:
      v41 += v61[5] << 8;
LABEL_33:
      v41 += v61[4];
LABEL_34:
      v47 += v61[3] << 24;
LABEL_35:
      v47 += v61[2] << 16;
LABEL_36:
      v47 += v61[1] << 8;
LABEL_37:
      v47 += *v61;
      break;
    default:
      break;
  }
  v64 = (v47 - v41 - v63) ^ (v63 >> 13);
  v65 = (v41 - v63 - v64) ^ (v64 << 8);
  v66 = (v63 - v64 - v65) ^ (v65 >> 13);
  v67 = (v64 - v65 - v66) ^ (v66 >> 12);
  v68 = (v65 - v66 - v67) ^ (v67 << 16);
  v69 = (v66 - v67 - v68) ^ (v68 >> 5);
  v70 = (v67 - v68 - v69) ^ (v69 >> 3);
  v71 = (v69 - v70 - ((v68 - v69 - v70) ^ (v70 << 10))) ^ (((v68 - v69 - v70) ^ (v70 << 10)) >> 15);
  *((_DWORD *)v35 + 24) = v71;
  v72 = 12 * (v71 & (*(_DWORD *)(*(_DWORD *)(v42 + 68) + 4) - 1));
  ++*(_DWORD *)(**(_DWORD **)(v42 + 68) + v72 + 4);
  v73 = *(_DWORD *)(**(_DWORD **)(v42 + 68) + v72);
  *((_DWORD *)v35 + 20) = 0;
  *((_DWORD *)v35 + 21) = v73;
  v74 = *(_DWORD **)(v42 + 68);
  v75 = *(_DWORD *)(*v74 + v72);
  if ( v75 )
  {
    *(_DWORD *)(v75 + 12) = v353;
    v74 = *(_DWORD **)(v42 + 68);
  }
  *(_DWORD *)(*v74 + v72) = v353;
  v76 = *(_QWORD *)(v72 + **(_DWORD **)(v42 + 68) + 4);
  if ( (unsigned int)v76 < 10 * HIDWORD(v76) + 10 || (v77 = *((_DWORD *)v35 + 17), *(_DWORD *)(v77 + 36) == 1) )
  {
LABEL_42:
    strcpy(current_hash, v35);
    scan_devices.next = &scan_devices;
    scan_devices.prev = &scan_devices;
    opt_register_table(opt_config_table, "Options for both config file and command line");
    opt_register_table(opt_cmdline_table, "Options for command line only");
    opt_parse(&argca, argva, (void (*)(const char *, ...))applog_and_exit);
    if ( argca != 1 )
    {
      strcpy(str, "Unexpected extra commandline arguments");
      applog(3, str, 1);
      _quit(1, 0);
    }
    v78 = *(unsigned __int8 *)(HIDWORD(work) + 0x358);
    if ( !*(_BYTE *)(HIDWORD(work) + 0x358) )
    {
      v171 = (char *)malloc(0x1000u);
      v172 = HIDWORD(work);
      *(_DWORD *)(HIDWORD(work) + 0x35C) = v171;
      default_save_file(v171);
      if ( access(*(const char **)(v172 + 0x35C), 4) )
      {
        v173 = HIDWORD(work);
        free(*(void **)(HIDWORD(work) + 0x35C));
        *(_DWORD *)(v173 + 0x35C) = v78;
      }
      else
      {
        load_config(*(const char **)(v172 + 0x35C), 0);
      }
    }
    if ( *(_BYTE *)(HIDWORD(work) + 0x561) || *(_DWORD *)(HIDWORD(work) + 0x434) )
    {
      if ( opt_scrypt )
      {
        strcpy(str, "Cannot use benchmark mode with scrypt");
        applog(3, str, 1);
        _quit(1, 1);
      }
      v79 = add_pool();
      v80 = (char *)malloc(0xFFu);
      v81 = HIDWORD(work);
      v79->rpc_url = v80;
      if ( *(_DWORD *)(v81 + 0x434) )
        strcpy(v80, "Benchfile");
      else
        strcpy(v80, "Benchmark");
      rpc_url = v79->rpc_url;
      v79->rpc_user = rpc_url;
      v79->rpc_pass = rpc_url;
      v79->rpc_userpass = rpc_url;
      v79->sockaddr_url = rpc_url;
      strncpy(v79->diff, "?", 7u);
      enabled = v79->enabled;
      v79->diff[7] = 0;
      if ( enabled != pool_enable::POOL_ENABLED )
        enable_pool((pool *)&v79->enabled);
      v84 = bench_hidiff_bins[0];
      v85 = 0;
      v79->idle = 0;
      v86 = bench_lodiff_bins[0];
      successful_connect = 1;
      do
      {
        v87 = v84;
        v84 += 160;
        hex2bin(v87, &bench_hidiffs[v85], 0xA0u);
        v88 = &bench_lodiffs[v85];
        v85 += 324;
        hex2bin(v86, v88, 0xA0u);
        v86 += 160;
      }
      while ( v85 != 5184 );
      set_target(bench_target, v89);
    }
    v90 = *(const char **)(HIDWORD(work) + 0x10);
    if ( !v90 )
      goto LABEL_74;
    v91 = fopen(v90, "rb");
    memset(s, 0, sizeof(s));
    if ( v91 )
    {
      v92 = fread(s, 1u, 0x100u, v91);
      if ( v92 <= 0 )
      {
        if ( !*v358 && !opt_log_output && opt_log_level <= 2 )
          goto LABEL_207;
        snprintf(str, 0x1000u, "Read miner version file %s error %d", *(const char **)(HIDWORD(work) + 0x10), v92);
        applog(3, str, 0);
      }
      else
      {
        if ( *v358 || opt_log_output || opt_log_level > 4 )
        {
          snprintf(str, 0x1000u, "%s:%s\n", *(const char **)(HIDWORD(work) + 0x10), s);
          applog(5, str, 0);
        }
        v93 = strchr(s, 10);
        v94 = v93;
        if ( v93 )
        {
          memcpy(g_miner_compiletime, s, v93 - s);
          strcpy(g_miner_type, v94 + 1);
        }
        else
        {
          strcpy(g_miner_compiletime, s);
        }
        v95 = strlen(g_miner_compiletime) - 1 + work;
        if ( *(_BYTE *)(v95 + 2676) == 10 )
          *(_BYTE *)(v95 + 2676) = 0;
        v96 = strlen(g_miner_compiletime) - 1 + work;
        if ( *(_BYTE *)(v96 + 2676) == 13 )
          *(_BYTE *)(v96 + 2676) = 0;
        v97 = strlen(g_miner_type) - 1 + work;
        if ( *(_BYTE *)(v97 + 2932) == 10 )
          *(_BYTE *)(v97 + 2932) = 0;
        v98 = strlen(g_miner_type) - 1 + work;
        if ( *(_BYTE *)(v98 + 2932) == 13 )
          *(_BYTE *)(v98 + 2932) = 0;
      }
    }
    else
    {
      if ( !*v358 && !opt_log_output && opt_log_level <= 2 )
        goto LABEL_207;
      snprintf(str, 0x1000u, "Open miner version file %s error", *(const char **)(HIDWORD(work) + 0x10));
      applog(3, str, 0);
    }
    if ( *v358 || opt_log_output )
      goto LABEL_73;
LABEL_207:
    if ( opt_log_level > 2 )
    {
LABEL_73:
      snprintf(str, 0x1000u, "Miner compile time: %s type: %s", g_miner_compiletime, g_miner_type);
      applog(3, str, 0);
    }
LABEL_74:
    v99 = HIDWORD(work);
    v100 = (const char *)*(_DWORD *)HIDWORD(work);
    if ( *(_DWORD *)HIDWORD(work) )
    {
      LOBYTE(drv->drv_id) = 1;
      strcpy(g_logfile_path, v100);
      v101 = *(const char **)(v99 + 0xC);
      if ( v101 )
        strcpy(g_logfile_openflag, v101);
      if ( !*v358 && !opt_log_output && opt_log_level <= 2 )
      {
        v102 = *(const char **)(HIDWORD(work) + 8);
        if ( !v102 )
        {
LABEL_190:
          if ( opt_log_level <= 3 )
          {
LABEL_112:
            v118 = *(const char **)(HIDWORD(work) + 0x35C);
            if ( !v118 )
              goto LABEL_124;
            if ( opt_debug )
            {
              if ( !*v358 && !opt_log_output && opt_log_level <= 6 )
              {
                v119 = *(_DWORD *)(HIDWORD(work) + 0x42C);
                if ( v119 == -1 )
                {
LABEL_118:
                  if ( !opt_log_output && opt_log_level <= 3 )
                  {
                    if ( !use_curses )
                      goto LABEL_123;
                    goto LABEL_121;
                  }
LABEL_215:
                  strcpy(str, "Error in configuration file, partially loaded.");
                  applog(4, str, 0);
                  if ( !use_curses )
                    goto LABEL_123;
                  if ( *v358 || opt_log_output )
                    goto LABEL_122;
LABEL_121:
                  if ( opt_log_level > 3 )
                  {
LABEL_122:
                    strcpy(str, "Start cgminer with -T to see what failed to load.");
                    applog(4, str, 0);
                  }
LABEL_123:
                  v120 = HIDWORD(work);
                  free(*(void **)(HIDWORD(work) + 0x35C));
                  *(_DWORD *)(v120 + 0x35C) = 0;
LABEL_124:
                  *(_WORD *)(v350->drv_id + strlen((const char *)v350->drv_id)) = *(_WORD *)HIDWORD(v351);
                  if ( want_per_device_stats )
                    opt_log_output = 1;
                  if ( opt_scantime < 0 )
                  {
                    if ( opt_scrypt )
                      v121 = 30;
                    else
                      v121 = 60;
                    opt_scantime = v121;
                  }
                  *(_DWORD *)(work + 0xE88) = 8;
                  v122 = (thr_info *)calloc(8u, 0x40u);
                  v338 = &control_thr;
                  control_thr = v122;
                  if ( v122 )
                  {
                    argva = (char **)&modminer_drv;
                    fill_device_drv(&bitforce_drv);
                    v339 = argva;
                    fill_device_drv((device_drv *)argva);
                    fill_device_drv(&bitmain_drv);
                    fill_device_drv(&bitmain_c5_drv);
                    fill_device_drv(&bitmainZCASH_drv);
                    drv = (device_drv *)(unsigned __int16)&avalon4_drv;
                    argva = (char **)(unsigned __int16)&avalon2_drv;
                    fill_device_drv(&bmsc_drv);
                    LOWORD(v123) = (_WORD)argva;
                    HIWORD(v123) = (unsigned int)&avalon2_drv >> 16;
                    argva = v123;
                    fill_device_drv(&avalon_drv);
                    LOWORD(v124) = (_WORD)drv;
                    v353 = (device_drv *)(unsigned __int16)&bitfury_drv;
                    HIWORD(v124) = (unsigned int)&avalon4_drv >> 16;
                    v354 = (device_drv *)(unsigned __int16)&bflsc_drv;
                    drv = v124;
                    fill_device_drv((device_drv *)argva);
                    LOWORD(v125) = (_WORD)v354;
                    HIWORD(v125) = (unsigned int)&bflsc_drv >> 16;
                    v354 = v125;
                    fill_device_drv(drv);
                    LOWORD(v126) = (_WORD)v353;
                    LODWORD(v351) = (unsigned __int16)&cointerra_drv;
                    HIDWORD(v351) = (unsigned __int16)&blockerupter_drv;
                    HIWORD(v126) = (unsigned int)&bitfury_drv >> 16;
                    v353 = v126;
                    fill_device_drv(v354);
                    LOWORD(v127) = WORD2(v351);
                    HIWORD(v127) = (unsigned int)&blockerupter_drv >> 16;
                    HIDWORD(v351) = v127;
                    fill_device_drv(v353);
                    LOWORD(v128) = v351;
                    v350 = (device_drv *)(unsigned __int16)&hashfast_drv;
                    v349 = (device_drv *)(unsigned __int16)&hashratio_drv;
                    HIWORD(v128) = (unsigned int)&cointerra_drv >> 16;
                    LODWORD(v351) = v128;
                    fill_device_drv((device_drv *)HIDWORD(v351));
                    LOWORD(v129) = (_WORD)v350;
                    HIWORD(v129) = (unsigned int)&hashfast_drv >> 16;
                    v350 = v129;
                    fill_device_drv((device_drv *)v351);
                    LOWORD(v130) = (_WORD)v349;
                    v348 = (device_drv *)(unsigned __int16)&icarus_drv;
                    HIWORD(v130) = (unsigned int)&hashratio_drv >> 16;
                    v347 = (device_drv *)(unsigned __int16)&klondike_drv;
                    v349 = v130;
                    fill_device_drv(v350);
                    LOWORD(v131) = (_WORD)v348;
                    HIWORD(v131) = (unsigned int)&icarus_drv >> 16;
                    v348 = v131;
                    fill_device_drv(v349);
                    LOWORD(v132) = (_WORD)v347;
                    HIWORD(v132) = (unsigned int)&klondike_drv >> 16;
                    v347 = v132;
                    v346 = (device_drv *)(unsigned __int16)&knc_drv;
                    v345 = (device_drv *)(unsigned __int16)&bitmineA1_drv;
                    fill_device_drv(v348);
                    LOWORD(v133) = (_WORD)v346;
                    HIWORD(v133) = (unsigned int)&knc_drv >> 16;
                    v346 = v133;
                    fill_device_drv(v347);
                    LOWORD(v134) = (_WORD)v345;
                    HIWORD(v134) = (unsigned int)&bitmineA1_drv >> 16;
                    v345 = v134;
                    v344 = (device_drv *)(unsigned __int16)&drillbit_drv;
                    v343 = (device_drv *)(unsigned __int16)&bab_drv;
                    fill_device_drv(v346);
                    LOWORD(v135) = (_WORD)v344;
                    HIWORD(v135) = (unsigned int)&drillbit_drv >> 16;
                    v344 = v135;
                    fill_device_drv(v345);
                    LOWORD(v136) = (_WORD)v343;
                    HIWORD(v136) = (unsigned int)&bab_drv >> 16;
                    v343 = v136;
                    v342 = (device_drv *)(unsigned __int16)&minion_drv;
                    v341 = (device_drv *)(unsigned __int16)&sp10_drv;
                    fill_device_drv(v344);
                    LOWORD(v137) = (_WORD)v342;
                    HIWORD(v137) = (unsigned int)&minion_drv >> 16;
                    v342 = v137;
                    fill_device_drv(v343);
                    LOWORD(v138) = (_WORD)v341;
                    HIWORD(v138) = (unsigned int)&sp10_drv >> 16;
                    v341 = v138;
                    v340 = (size_t *)(unsigned __int16)&mining_threads;
                    fill_device_drv(v342);
                    fill_device_drv(v341);
                    LOWORD(v139) = (_WORD)v340;
                    HIWORD(v139) = (unsigned int)&mining_threads >> 16;
                    v340 = v139;
                    fill_device_drv(&sp30_drv);
                    (*(void (__fastcall **)(_DWORD))(v140 + 12))(0);
                    ((void (__fastcall *)(_DWORD))v339[3])(0);
                    bitmain_drv.drv_detect(0);
                    bitmain_c5_drv.drv_detect(0);
                    ((void (__fastcall *)())bitmainZCASH_drv.drv_detect)();
                    bmsc_drv.drv_detect(0);
                    avalon_drv.drv_detect(0);
                    v141 = 0;
                    CONTAINING_RECORD(argva, device_drv, dname)->reinit_device(0);
                    drv->drv_detect(0);
                    v354->drv_detect(0);
                    v353->drv_detect(0);
                    (*(void (__fastcall **)(_DWORD))(HIDWORD(v351) + offsetof(device_drv, drv_detect)))(0);
                    (*(void (__fastcall **)(_DWORD))(v351 + offsetof(device_drv, drv_detect)))(0);
                    v350->drv_detect(0);
                    v349->drv_detect(0);
                    v348->drv_detect(0);
                    v347->drv_detect(0);
                    v346->drv_detect(0);
                    v345->drv_detect(0);
                    v344->drv_detect(0);
                    v343->drv_detect(0);
                    v342->drv_detect(0);
                    v341->drv_detect(0);
                    sp30_drv.drv_detect(0);
                    v142 = (device_drv *)&total_devices;
                    *v340 = 0;
                    while ( total_devices > v141 )
                    {
                      v143 = (pthread_rwlock_t *)devices[v141++];
                      enable_device(v143);
                    }
                    if ( total_devices )
                    {
                      v144 = *(char **)(HIDWORD(work) + 0x328);
                      *(_DWORD *)(work + 0xA4C) = total_devices;
                      if ( v144 )
                      {
                        v145 = 0;
                        v146 = 0;
                        for ( i = strtok(v144, ","); i; i = strtok((char *)argva, ",") )
                        {
                          if ( total_devices <= v145 )
                          {
                            strcpy(str, "Too many values passed to set temp cutoff");
LABEL_189:
                            applog(3, str, 1);
                            _quit(1, 1);
                          }
                          v146 = strtol(i, 0, 10);
                          if ( v146 > 0xC8 )
                          {
                            v176 = "ssed to set temp cutoff";
                            qmemcpy(str, "Invalid value pa", 16);
                            v177 = &str[16];
                            goto LABEL_220;
                          }
                          if ( pthread_rwlock_rdlock(&devices_lock) )
                            rd_lock((pthread_rwlock_t *)&_func___14711, (const char *)0x479, v148, v149);
                          devices[v145]->cutofftemp = v146;
                          if ( pthread_rwlock_unlock(&devices_lock) )
                          {
                            v226 = _errno_location();
                            snprintf(
                              str,
                              0x1000u,
                              "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                              *v226,
                              "cgminer.c",
                              (const char *)&_func___14711,
                              1147);
                            goto LABEL_221;
                          }
                          ++v145;
                          argva = 0;
                          selective_yield();
                        }
                        if ( v145 > 1 )
                        {
                          v354 = (device_drv *)&devices;
                          goto LABEL_240;
                        }
                        if ( pthread_rwlock_rdlock(&devices_lock) )
                          rd_lock((pthread_rwlock_t *)&_func___14711, (const char *)0x48C, v227, v228);
                        v229 = total_devices;
                        v354 = (device_drv *)&devices;
                        v230 = devices;
                        while ( v145 < v229 )
                        {
                          v231 = v230[v145++];
                          v231->cutofftemp = v146;
                        }
                        if ( pthread_rwlock_unlock(&devices_lock) )
                          rw_unlock((pthread_rwlock_t *)&_func___14711, (const char *)0x48F, v232, v233);
                      }
                      else
                      {
                        v187 = pthread_rwlock_rdlock(&devices_lock);
                        if ( v187 )
                          rd_lock((pthread_rwlock_t *)&_func___14711, (const char *)0x480, v188, v189);
                        v190 = total_devices;
                        v354 = (device_drv *)&devices;
                        v191 = devices;
                        while ( v187 < v190 )
                        {
                          v192 = v191[v187];
                          if ( !v192->cutofftemp )
                            v192->cutofftemp = 95;
                          ++v187;
                        }
                        if ( pthread_rwlock_unlock(&devices_lock) )
                          rw_unlock((pthread_rwlock_t *)&_func___14711, (const char *)0x486, v193, v194);
                      }
                      selective_yield();
LABEL_240:
                      v195 = total_devices;
                      drv_id = v354->drv_id;
                      for ( j = 0; v195 > j; ++j )
                      {
                        v198 = *(_DWORD *)(drv_id + 4 * j);
                        *(_DWORD *)(v198 + 312) = 99999999;
                      }
                      if ( !opt_compact )
                        *(_DWORD *)(work + 0xA50) += *(_DWORD *)(work + 0xA4C);
                      argva = (char **)&total_pools;
                      if ( !total_pools )
                      {
                        if ( *v358 || opt_log_output || opt_log_level > 3 )
                        {
                          strcpy(str, "Need to specify at least one pool server.");
                          applog(4, str, 0);
                        }
                        strcpy(str, "Pool setup failed");
                        applog(3, str, 1);
                        _quit(1, 0);
                      }
                      v199 = 0;
                      drv = (device_drv *)&pools;
                      v353 = (device_drv *)"%s:%s";
                      while ( 1 )
                      {
                        v200 = (_DWORD *)drv->drv_id;
                        if ( (int)*argva <= v199 )
                          break;
                        v201 = v200[v199];
                        v202 = *(_DWORD *)(v201 + 200);
                        *(_DWORD *)(v201 + 428) = 99999999;
                        *(_DWORD *)(v201 + 464) = 99999999;
                        if ( !v202 )
                        {
                          if ( !*(_DWORD *)(v201 + 208) )
                            *(_DWORD *)(v201 + 208) = calloc(1u, 1u);
                          if ( !*(_DWORD *)(v201 + 204) )
                          {
                            snprintf(
                              str,
                              0x1000u,
                              "No login credentials supplied for pool %u %s",
                              v199,
                              *(const char **)(v201 + 196));
                            goto LABEL_285;
                          }
                          LODWORD(v351) = *(_DWORD *)(v201 + 204);
                          v203 = strlen((const char *)v351);
                          HIDWORD(v351) = *(_DWORD *)(v201 + 208);
                          v204 = strlen((const char *)HIDWORD(v351)) + v203 + 2;
                          v205 = (char *)malloc(v204);
                          v206 = v351;
                          *(_DWORD *)(v201 + 200) = v205;
                          if ( !v205 )
                          {
                            strcpy(str, "Failed to malloc userpass");
                            goto LABEL_306;
                          }
                          snprintf(v205, v204, (const char *)v353, (_DWORD)v206, HIDWORD(v206));
                        }
                        ++v199;
                      }
                      v207 = *v358;
                      *(_DWORD *)(HIDWORD(work) + 0x4FC) = *v200;
                      if ( v207 )
                        openlog("cgminer", 1, 8);
                      if ( *(_DWORD *)(work + 0xE8C) )
                      {
                        if ( pipe((int *)str) < 0 )
                        {
                          perror("pipe - failed to create pipe for --monitor");
                          exit(1);
                        }
                        fflush((FILE *)stderr);
                        if ( dup2(*(int *)&str[4], 2) < 0 )
                        {
                          perror("dup2 - failed to alias stderr to write end of pipe for --monitor");
                          exit(1);
                        }
                        if ( close(*(int *)&str[4]) < 0 )
                        {
                          perror("close - failed to close write end of pipe for --monitor");
                          exit(1);
                        }
                        v208 = signal(13, (__sighandler_t)1);
                        v209 = signal(13, (__sighandler_t)1);
                        if ( v208 == (__sighandler_t)-1 || v209 == (__sighandler_t)-1 )
                        {
                          perror("signal - failed to edit signal mask for --monitor");
                          exit(1);
                        }
                        v210 = fork();
                        v211 = v210;
                        *(_DWORD *)(HIDWORD(work) + 0x344) = v210;
                        if ( v210 < 0 )
                        {
                          perror("fork - failed to fork child process for --monitor");
                          exit(1);
                        }
                        if ( !v210 )
                        {
                          if ( dup2(*(int *)str, v210) >= 0 )
                          {
                            close(*(int *)str);
                            execl("/bin/bash", "/bin/bash", "-c", *(_DWORD *)(work + 0xE8C), v211);
                            perror("execl - in child failed to exec user specified command for --monitor");
                            exit(1);
                          }
                          perror("dup2 - in child, failed to alias read end of pipe to stdin for --monitor");
                          exit(1);
                        }
                        if ( close(*(int *)str) < 0 )
                        {
                          perror("close - failed to close read end of pipe for --monitor");
                          exit(1);
                        }
                      }
                      v212 = (thr_info **)calloc(*v340, 4u);
                      LODWORD(v351) = &mining_thr;
                      mining_thr = v212;
                      if ( !v212 )
                      {
                        strcpy(str, "Failed to calloc mining_thr");
LABEL_285:
                        applog(3, str, 1);
                        _quit(1, 0);
                      }
                      v213 = (int *)v340;
                      v214 = 0;
                      v215 = (int *)v351;
                      while ( *v213 > v214 )
                      {
                        v216 = *v215;
                        *(_DWORD *)(v216 + 4 * v214) = calloc(1u, 0x40u);
                        if ( !*(_DWORD *)(*v215 + 4 * v214) )
                        {
                          snprintf(str, 0x1000u, "Failed to calloc mining_thr[%d]", v214);
                          goto LABEL_285;
                        }
                        ++v214;
                      }
                      v217 = 0;
                      v353 = 0;
                      HIDWORD(v351) = miner_thread;
                      v350 = (device_drv *)&opt_debug;
                      while ( total_devices > v217 )
                      {
                        v218 = *(cgpu_info **)(v354->drv_id + 4 * v217);
                        v219 = v218->threads + 1;
                        v220 = (thr_info **)malloc(v219 * 4);
                        v221 = (char *)&v220[v219];
                        v222 = 0;
                        v218->thr = v220;
                        *((_DWORD *)v221 - 1) = 0;
                        v218->status = alive::LIFE_INIT;
                        while ( v218->threads > v222 )
                        {
                          v349 = (device_drv *)((char *)v353 + v222);
                          thread = get_thread((int)v353 + v222);
                          v224 = v349;
                          v225 = thread;
                          thread->cgpu = v218;
                          thread->device_thread = v222;
                          thread->id = (int)v224;
                          if ( ((int (*)(void))v218->drv->thread_prepare)() )
                          {
                            if ( thr_info_create(v225, 0, (void *(*)(void *))HIDWORD(v351), v225) )
                            {
                              snprintf(str, 0x1000u, "thread %d create failed", v225->id);
                              applog(3, str, 1);
                              _quit(1, 0);
                            }
                            v218->thr[v222] = v225;
                            if ( v218->deven != dev_enable::DEV_DISABLED )
                            {
                              if ( LOBYTE(v350->drv_id) && (*v358 || opt_log_output || opt_log_level > 6) )
                              {
                                snprintf(str, 0x1000u, "Pushing sem post to thread %d", v225->id);
                                applog(7, str, 0);
                              }
                              cgsem_post(&v225->sem, "cgminer.c", &_func___17121.__size[28], 11130);
                            }
                          }
                          ++v222;
                        }
                        ++v217;
                        v353 = (device_drv *)((char *)v353 + v222);
                      }
                      if ( !*(_BYTE *)(HIDWORD(work) + 0x561) )
                      {
                        v239 = *(_DWORD *)(HIDWORD(work) + 0x434);
                        if ( !v239 )
                        {
                          v240 = argva;
                          while ( (int)*v240 > v239 )
                          {
                            v241 = *(_DWORD *)(drv->drv_id + 4 * v239);
                            if ( *(_DWORD *)(v241 + 132) != 1 )
                              enable_pool((pool *)(v241 + 132));
                            ++v239;
                            *(_BYTE *)(v241 + 129) = 1;
                          }
                          if ( opt_debug && (*v358 || opt_log_output || opt_log_level > 6) )
                          {
                            strcpy(str, "Probing for an alive pool");
                            applog(7, str, 0);
                          }
                          v242 = drv;
                          for ( k = 0; k < (int)*argva; ++k )
                          {
                            v244 = *(_DWORD *)(v242->drv_id + 4 * k);
                            *(_BYTE *)(v244 + 316) = 1;
                            pthread_create((pthread_t *)(v244 + 312), 0, test_pool_thread, (void *)v244);
                          }
                          v249 = 0;
                          do
                          {
                            ++v249;
                            sleep(1u);
                            if ( v249 == 60 )
                              v250 = 0;
                            else
                              v250 = (*(_BYTE *)(HIDWORD(work) + 0x560) ^ 1) & 1;
                          }
                          while ( v250 );
                          v350 = (device_drv *)&total_devices;
                          v251 = v358;
                          v252 = (device_drv *)&opt_log_level;
                          HIDWORD(v351) = "Pool: %d  URL: %s  User: %s  Password: %s";
                          while ( 1 )
                          {
                            if ( *(_BYTE *)(HIDWORD(work) + 0x560) )
                            {
                              v142 = v350;
                              goto begin_bench;
                            }
                            if ( v250 )
                              goto LABEL_350;
                            if ( ((*v251 || opt_log_output || v252->drv_id > drv_driver::DRIVER_bitmain)
                               && ((strcpy(str, "No servers were found that could be used to get work from."),
                                    applog(3, str, 0),
                                    *v251)
                                || opt_log_output)
                               || v252->drv_id > drv_driver::DRIVER_bitmain)
                              && ((strcpy(
                                     str,
                                     "Please check the details from the list below of the servers you have input"),
                                   applog(3, str, 0),
                                   *v251)
                               || opt_log_output)
                              || v252->drv_id > drv_driver::DRIVER_bitmain )
                            {
                              strcpy(
                                str,
                                "Most likely you have input the wrong URL, forgotten to add a port, or have not set up workers");
                              applog(3, str, 0);
                            }
                            v332 = 0;
                            v353 = v252;
                            while ( (int)*argva > v332 )
                            {
                              if ( *v251 || opt_log_output || v353->drv_id > drv_driver::DRIVER_bitmain_c5 )
                              {
                                snprintf(
                                  str,
                                  0x1000u,
                                  (const char *)HIDWORD(v351),
                                  v332,
                                  *(_DWORD *)(*(_DWORD *)(drv->drv_id + 4 * v332) + 196),
                                  *(_DWORD *)(*(_DWORD *)(drv->drv_id + 4 * v332) + 204),
                                  *(_DWORD *)(*(_DWORD *)(drv->drv_id + 4 * v332) + 208));
                                applog(4, str, 0);
                              }
                              ++v332;
                            }
                            v252 = v353;
                            if ( !use_curses )
                            {
LABEL_524:
                              strcpy(str, "No servers could be used! Exiting.");
                              applog(3, str, 1);
                              _quit(0, 0);
                            }
                            if ( *v251 || opt_log_output || v353->drv_id > drv_driver::DRIVER_bitmain )
                              break;
LABEL_351:
                            v250 = 1;
                          }
                          strcpy(str, "Press any key to exit, or cgminer will wait indefinitely for an alive pool.");
                          applog(3, str, 0);
LABEL_350:
                          if ( !use_curses )
                            goto LABEL_524;
                          goto LABEL_351;
                        }
                      }
begin_bench:
                      v234 = (int *)g_local_mhashes_dones;
                      total_mhashes_done = 0.0;
                      do
                      {
                        *(_QWORD *)v234 = 0;
                        v234 += 2;
                      }
                      while ( &g_local_mhashes_index != v234 );
                      v235 = v142->drv_id;
                      v236 = v352;
                      v237 = v354->drv_id;
                      *(_DWORD *)(HIDWORD(work) + 0x4C0) = 0;
                      while ( v235 > v236 )
                      {
                        v238 = *(_DWORD *)(v237 + 4 * v236++);
                        *(_QWORD *)(v238 + 80) = 0;
                        *(_QWORD *)(v238 + 48) = 0;
                      }
                      cgtime(&total_tv_start);
                      cgtime(&total_tv_end);
                      cgtime(&tv_hashmeter);
                      get_datestamp(datestamp, 0x28u, &total_tv_start);
                      v245 = *v338;
                      *(_DWORD *)(HIDWORD(work) + 0x4F4) = 2;
                      if ( thr_info_create(v245 + 2, 0, (void *(*)(void *))watchpool_thread, 0) )
                      {
                        strcpy(str, "watchpool thread create failed");
                        applog(3, str, 1);
                        _quit(1, 0);
                      }
                      pthread_detach(v245[2].pth);
                      v246 = *v338;
                      *(_DWORD *)(HIDWORD(work) + 0x4F8) = 3;
                      if ( thr_info_create(v246 + 3, 0, (void *(*)(void *))watchdog_thread, 0) )
                      {
                        strcpy(str, "watchdog thread create failed");
                        applog(3, str, 1);
                        _quit(1, 0);
                      }
                      pthread_detach(v246[3].pth);
                      v247 = *v338;
                      *(_DWORD *)(HIDWORD(work) + 0x320) = 5;
                      if ( thr_info_create(v247 + 5, 0, api_thread, &v247[5]) )
                      {
                        strcpy(str, "API thread create failed");
LABEL_306:
                        applog(3, str, 1);
                        _quit(1, 0);
                      }
                      v248 = *(_DWORD *)(work + 0xE88);
                      if ( v248 != 8 )
                      {
                        snprintf(str, 0x1000u, "incorrect total_control_threads (%d) should be 8", v248);
LABEL_184:
                        applog(3, str, 1);
                        _quit(1, 0);
                      }
                      if ( !nice(-10) && opt_debug && (*v358 || opt_log_output || opt_log_level > 6) )
                      {
                        strcpy(str, "Unable to set thread to high priority");
                        applog(7, str, 0);
                      }
                      v253 = 0;
                      v353 = (device_drv *)&global_quota_gcd;
                      HIDWORD(v351) = &opt_work_update;
                      v254 = work;
                      v354 = (device_drv *)&opt_fail_only;
                      HIDWORD(work) = &opt_debug;
                      while ( 1 )
                      {
                        while ( 1 )
                        {
                          thread_shutdown = v353[15].thread_shutdown;
                          if ( *(_BYTE *)HIDWORD(v351) )
                          {
                            if ( *(_BYTE *)HIDWORD(work) && (*v358 || opt_log_output || opt_log_level > 6) )
                            {
                              strcpy(str, "Work update message received");
                              applog(7, str, 0);
                            }
                            cgtime(&update_tv_start);
                            v325 = pthread_rwlock_rdlock(&mining_thr_lock);
                            if ( v325 )
                            {
                              v329 = _errno_location();
                              snprintf(
                                str,
                                0x1000u,
                                "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
                                *v329,
                                "cgminer.c",
                                &_func___14711.__align + 5,
                                5314);
                              goto LABEL_221;
                            }
                            v326 = *v340;
                            v327 = *(_DWORD *)v351;
                            while ( v325 < v326 )
                            {
                              v328 = *(_DWORD *)(v327 + 4 * v325++);
                              *(_BYTE *)(v328 + 63) = 1;
                            }
                            if ( pthread_rwlock_unlock(&mining_thr_lock) )
                            {
                              v333 = _errno_location();
                              snprintf(
                                str,
                                0x1000u,
                                "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                                *v333,
                                "cgminer.c",
                                &_func___14711.__align + 5,
                                5317);
LABEL_221:
                              applog(3, str, 1);
                              _quit(1, 1);
                            }
                            selective_yield();
                          }
                          *(_BYTE *)HIDWORD(v351) = 0;
                          current_pool();
                          if ( pthread_mutex_lock(*(pthread_mutex_t **)(HIDWORD(v254) + 1092)) )
                          {
                            v322 = _errno_location();
                            v323 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
                            v324 = 11267;
LABEL_484:
                            snprintf(str, 0x1000u, v323, *v322, "cgminer.c", &_func___17121.__align + 7, v324);
                            goto LABEL_221;
                          }
                          v256 = *(_DWORD *)(HIDWORD(v254) + 1296);
                          if ( v256 )
                            v256 = *(_DWORD *)(*(_DWORD *)(v256 + 1832) + 12);
                          v257 = *(pthread_mutex_t **)(HIDWORD(v254) + 1092);
                          if ( (int)thread_shutdown < v256 )
                            break;
                          if ( pthread_mutex_unlock(*(pthread_mutex_t **)(HIDWORD(v254) + 1092)) )
                            goto LABEL_498;
                          selective_yield();
LABEL_378:
                          if ( v253 )
                            discard_work(v253);
                          v263 = make_work();
                          v264 = current_pool();
                          v265 = *(_DWORD *)(HIDWORD(v254) + 804);
                          v266 = v264;
                          if ( v265 == 4 )
                          {
                            v267 = select_balanced(v264);
                          }
                          else if ( v265 == 3 )
                          {
                            v307 = drv->drv_id;
                            v308 = *argva;
                            for ( m = 0; m < (int)v308; ++m )
                            {
                              v310 = *(_QWORD *)(*(_DWORD *)(v307 + 4 * m) + 60);
                              if ( SHIDWORD(v310) < (int)v310 )
                                goto LABEL_459;
                            }
                            for ( n = 0; (int)v308 > n; ++n )
                            {
                              v331 = *(_DWORD *)(v307 + 4 * n);
                              *(_DWORD *)(v331 + 64) = 0;
                            }
                            v311 = *(_DWORD *)(v254 + 3728) + 1;
                            *(_DWORD *)(v254 + 3728) = v311;
                            if ( (int)v308 <= v311 )
                              *(_DWORD *)(v254 + 3728) = 0;
LABEL_459:
                            v312 = argva;
                            for ( ii = 0; ; ii = v314 )
                            {
                              v314 = ii + 1;
                              if ( ii >= (int)*v312 )
                                break;
                              v315 = *(_DWORD *)(drv->drv_id + 4 * *(_DWORD *)(v254 + 3728));
                              v316 = *(_QWORD *)(v315 + 60);
                              *(_DWORD *)(v315 + 64) = HIDWORD(v316) + 1;
                              if ( SHIDWORD(v316) < (int)v316 )
                              {
                                if ( !*(_BYTE *)(v315 + 129)
                                  && *(_DWORD *)(v315 + 132) == 1
                                  && (!*(_BYTE *)(v315 + 664) || *(_BYTE *)(v315 + 665)) )
                                {
                                  v267 = (pool *)v315;
                                  goto LABEL_383;
                                }
                                if ( LOBYTE(v354->drv_id) )
                                {
                                  v317 = priority_pool(0);
                                  --v317->quota_used;
                                }
                              }
                              v318 = *(_DWORD *)(v254 + 3728) + 1;
                              v164 = v318 < (int)*v312;
                              *(_DWORD *)(v254 + 3728) = v318;
                              if ( !v164 )
                                *(_DWORD *)(v254 + 3728) = 0;
                            }
                            v319 = argva;
                            for ( jj = 0; ; ++jj )
                            {
                              if ( jj >= (int)*v319 )
                                goto LABEL_382;
                              v321 = priority_pool(jj);
                              if ( !v321->idle && v321->enabled == pool_enable::POOL_ENABLED )
                                break;
                            }
                            v267 = v321;
                          }
                          else
                          {
LABEL_382:
                            v267 = v266;
                          }
LABEL_383:
                          if ( *(_BYTE *)HIDWORD(work) && (*v358 || opt_log_output || opt_log_level > 6) )
                          {
                            snprintf(str, 0x1000u, "Selecting pool %d for work", v267->pool_no);
                            applog(7, str, 0);
                            LODWORD(work) = v263;
                            v268 = argva;
                          }
                          else
                          {
                            LODWORD(work) = v263;
                            v268 = argva;
                          }
LABEL_388:
                          if ( v267->has_stratum )
                          {
                            while ( !v267->stratum_active || !v267->stratum_notify )
                            {
                              v269 = current_pool();
                              v270 = *(_DWORD *)(HIDWORD(v254) + 804);
                              v352 = (int)v269;
                              if ( v270 == 4 )
                              {
                                v271 = select_balanced(v269);
                              }
                              else if ( v270 == 3 || !LOBYTE(v354->drv_id) )
                              {
                                v272 = 0;
                                v273 = *v268;
                                v274 = drv->drv_id;
                                while ( v272 < (int)v273 )
                                {
                                  v275 = *(_QWORD *)(*(_DWORD *)(v274 + 4 * v272) + 60);
                                  if ( SHIDWORD(v275) < (int)v275 )
                                    goto LABEL_411;
                                  ++v272;
                                }
                                for ( kk = 0; (int)v273 > kk; ++kk )
                                {
                                  v277 = *(_DWORD *)(v274 + 4 * kk);
                                  *(_DWORD *)(v277 + 64) = 0;
                                }
                                v278 = *(_DWORD *)(v254 + 3728) + 1;
                                *(_DWORD *)(v254 + 3728) = v278;
                                if ( (int)v273 <= v278 )
                                  *(_DWORD *)(v254 + 3728) = 0;
LABEL_411:
                                v279 = v267;
                                for ( mm = 0; mm < (int)*v268; ++mm )
                                {
                                  v281 = *(_DWORD *)(drv->drv_id + 4 * *(_DWORD *)(v254 + 3728));
                                  v282 = *(_QWORD *)(v281 + 60);
                                  *(_DWORD *)(v281 + 64) = HIDWORD(v282) + 1;
                                  if ( SHIDWORD(v282) < (int)v282 )
                                  {
                                    if ( !*(_BYTE *)(v281 + 129)
                                      && *(_DWORD *)(v281 + 132) == 1
                                      && (!*(_BYTE *)(v281 + 664) || *(_BYTE *)(v281 + 665)) )
                                    {
                                      v267 = v279;
                                      v271 = (pool *)v281;
                                      goto LABEL_395;
                                    }
                                    if ( LOBYTE(v354->drv_id) )
                                    {
                                      v306 = priority_pool(0);
                                      --v306->quota_used;
                                    }
                                  }
                                  v283 = *(_DWORD *)(v254 + 3728) + 1;
                                  v164 = v283 < (int)*v268;
                                  *(_DWORD *)(v254 + 3728) = v283;
                                  if ( !v164 )
                                    *(_DWORD *)(v254 + 3728) = 0;
                                }
                                for ( nn = 0; nn < (int)*v268; ++nn )
                                {
                                  v305 = priority_pool(nn);
                                  if ( !v305->idle && v305->enabled == pool_enable::POOL_ENABLED )
                                  {
                                    v267 = v279;
                                    v271 = v305;
                                    goto LABEL_395;
                                  }
                                }
                                v267 = v279;
                                v271 = (pool *)v352;
                              }
                              else
                              {
                                v271 = (pool *)v352;
                              }
LABEL_395:
                              if ( *(_BYTE *)HIDWORD(work) && (*v358 || opt_log_output || opt_log_level > 6) )
                              {
                                snprintf(str, 0x1000u, "Selecting pool %d for work", v271->pool_no);
                                applog(7, str, 0);
                              }
                              cgsleep_ms(5000);
                              if ( v267 != v271 )
                              {
                                v267 = v271;
                                goto LABEL_388;
                              }
                            }
                            v253 = (work *)work;
                            gen_stratum_work(v267, (work *)work);
                            if ( *(_BYTE *)HIDWORD(work) && (*v358 || opt_log_output || opt_log_level > 6) )
                            {
                              strcpy(str, "Generated stratum work");
                              applog(7, str, 0);
                            }
                            goto LABEL_430;
                          }
                          v253 = (work *)work;
                          if ( *(_DWORD *)(HIDWORD(v254) + 1076) )
                          {
                            benchfile_get_work((work *)work);
                            v302 = drv;
                            v253->mandatory = 1;
                            v253->pool = *(pool **)v302->drv_id;
                            cgtime(&v253->tv_getwork);
                            copy_time(&v253->tv_getwork_reply, &v253->tv_getwork);
                            HIDWORD(v303) = 66;
                            v253->getwork_mode = 66;
                            calc_diff(v253, v303);
                            if ( *(_BYTE *)HIDWORD(work) && (*v358 || opt_log_output || opt_log_level > 6) )
                            {
                              v293 = "Generated benchfile work";
                              goto LABEL_429;
                            }
LABEL_430:
                            v301 = v253;
                            v253 = 0;
                            stage_work(v301);
                          }
                          else if ( *(_BYTE *)(HIDWORD(v254) + 1377) )
                          {
                            *(_QWORD *)(work + 1864) = 0x4040000000000000LL;
                            v284 = drv;
                            v253->drv_rolllimit = 0;
                            v253->mandatory = 1;
                            LODWORD(work) = v284->drv_id;
                            v285 = *(_DWORD *)&bench_target[4];
                            v286 = *(_DWORD *)&bench_target[8];
                            v287 = *(_DWORD *)&bench_target[12];
                            *(_DWORD *)v253->target = *(_DWORD *)bench_target;
                            *(_DWORD *)&v253->target[4] = v285;
                            *(_DWORD *)&v253->target[8] = v286;
                            *(_DWORD *)&v253->target[12] = v287;
                            v288 = *(_DWORD *)&bench_target[16];
                            v289 = *(_DWORD *)&bench_target[20];
                            v290 = *(_DWORD *)&bench_target[24];
                            *(_DWORD *)&v253->target[28] = *(_DWORD *)&bench_target[28];
                            v291 = (pool **)work;
                            *(_DWORD *)&v253->target[24] = v290;
                            *(_DWORD *)&v253->target[16] = v288;
                            *(_DWORD *)&v253->target[20] = v289;
                            v253->pool = *v291;
                            cgtime(&v253->tv_getwork);
                            copy_time(&v253->tv_getwork_reply, &v253->tv_getwork);
                            v292 = (_BYTE *)HIDWORD(work);
                            v253->getwork_mode = 66;
                            if ( *v292 && (*v358 || opt_log_output || opt_log_level > 6) )
                            {
                              v293 = "Generated benchmark work";
LABEL_429:
                              v294 = *(_DWORD *)v293;
                              v295 = *((_DWORD *)v293 + 1);
                              v296 = *((_DWORD *)v293 + 2);
                              v297 = *((_DWORD *)v293 + 3);
                              v298 = v293 + 16;
                              *(_DWORD *)str = v294;
                              *(_DWORD *)&str[4] = v295;
                              *(_DWORD *)&str[8] = v296;
                              *(_DWORD *)&str[12] = v297;
                              v299 = v298[1];
                              v300 = v298[2];
                              *(_DWORD *)&str[16] = *v298;
                              *(_DWORD *)&str[20] = v299;
                              str[24] = v300;
                              applog(7, str, 0);
                              goto LABEL_430;
                            }
                            goto LABEL_430;
                          }
                        }
                        if ( *(_BYTE *)(HIDWORD(v254) + 1417) )
                        {
                          v258 = v353[15].thread_shutdown;
                          if ( (int)v258 < (int)v353[15].thread_enable )
                          {
                            v353[15].thread_shutdown = (void (*)(thr_info *))((char *)v258 + 1);
                            *(_BYTE *)(HIDWORD(v254) + 1417) = 0;
                          }
                        }
                        *(_BYTE *)(HIDWORD(v254) + 1416) = 1;
                        pthread_cond_wait(&gws_cond, v257);
                        v259 = *(_DWORD *)(HIDWORD(v254) + 1296);
                        if ( v259 )
                          v259 = *(_DWORD *)(*(_DWORD *)(v259 + 1832) + 12);
                        if ( pthread_mutex_unlock(*(pthread_mutex_t **)(HIDWORD(v254) + 1092)) )
                        {
LABEL_498:
                          v322 = _errno_location();
                          v323 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
                          v324 = 11285;
                          goto LABEL_484;
                        }
                        selective_yield();
                        if ( v259 <= (int)thread_shutdown )
                          goto LABEL_378;
                        if ( *(_BYTE *)(HIDWORD(v254) + 1417) )
                        {
                          v260 = v353[15].thread_shutdown;
                          v261 = v353;
                          if ( (int)v260 < (int)v353[15].thread_enable )
                          {
                            *(_BYTE *)(HIDWORD(v254) + 1417) = 0;
                            v261[15].thread_shutdown = (void (*)(thr_info *))((char *)v260 + 1);
                          }
                        }
                        *(_BYTE *)(HIDWORD(v254) + 1416) = 1;
                        v262 = hash_pop(0);
                        v253 = v262;
                        if ( v262 )
                        {
                          discard_work(v262);
                          v253 = 0;
                        }
                      }
                    }
                    qmemcpy(str, "All devices disabled, cannot mine!", 34);
                    v174 = aAllDevicesDisa[34];
                    v175 = &str[34];
                  }
                  else
                  {
                    qmemcpy(str, "Failed to calloc control_thr", 28);
                    v174 = aFailedToCalloc[28];
                    v175 = &str[28];
                  }
                  *v175 = v174;
                  applog(3, str, 1);
                  _quit(1, 0);
                }
                goto LABEL_176;
              }
              snprintf(str, 0x1000u, "Loaded configuration file %s", v118);
              applog(7, str, 0);
            }
            v119 = *(_DWORD *)(HIDWORD(work) + 0x42C);
            if ( v119 == -1 )
            {
              if ( *v358 )
                goto LABEL_215;
              goto LABEL_118;
            }
LABEL_176:
            if ( !v119 )
            {
              if ( (*v358 || opt_log_output || opt_log_level > 3)
                && ((strcpy(str, "Fatal JSON error in configuration file."), applog(4, str, 0), *v358) || opt_log_output)
                || opt_log_level > 3 )
              {
                strcpy(str, "Configuration file could not be used.");
                applog(4, str, 0);
              }
            }
            goto LABEL_123;
          }
LABEL_111:
          snprintf(str, 0x1000u, "Started %s", packagename);
          applog(4, str, 0);
          goto LABEL_112;
        }
LABEL_81:
        memset(s, 0, sizeof(s));
        v103 = *(const char **)(HIDWORD(work) + 4);
        if ( v103 )
        {
          if ( !*v103 )
          {
            v176 = "Log work asic num empty";
            v177 = str;
LABEL_220:
            v178 = *(_DWORD *)v176;
            v179 = *((_DWORD *)v176 + 1);
            v180 = *((_DWORD *)v176 + 2);
            v181 = *((_DWORD *)v176 + 3);
            v182 = v176 + 16;
            *(_DWORD *)v177 = v178;
            *((_DWORD *)v177 + 1) = v179;
            *((_DWORD *)v177 + 2) = v180;
            *((_DWORD *)v177 + 3) = v181;
            v183 = v177 + 16;
            v184 = v182[1];
            *v183 = *v182;
            v183[1] = v184;
            goto LABEL_221;
          }
          v104 = strtol(v103, 0, 10);
          *(_DWORD *)(work + 0xC74) = v104;
          if ( ((v104 - 32) & 0xFFFFFFDF) != 0 && v104 != 1 )
          {
            strcpy(str, "Log work asic num must be 1, 32, 64");
            applog(3, str, 1);
            _quit(1, 1);
          }
          if ( *v358 || opt_log_output || opt_log_level > 2 )
          {
            snprintf(
              str,
              0x1000u,
              "Log work path: %s Asic num: %s",
              *(const char **)(HIDWORD(work) + 8),
              *(const char **)(HIDWORD(work) + 4));
            applog(3, str, 0);
          }
        }
        else if ( *v358 || opt_log_output || opt_log_level > 2 )
        {
          snprintf(str, 0x1000u, "Log work path: %s", v102);
          applog(3, str, 0);
        }
        sprintf(s, "%s.txt", *(const char **)(HIDWORD(work) + 8));
        v105 = fopen(s, "a+");
        v106 = *v358;
        *(_DWORD *)(work + 0xC78) = v105;
        if ( v106 || opt_log_output || opt_log_level > 2 )
        {
          snprintf(str, 0x1000u, "Log work open file %s", s);
          applog(3, str, 0);
        }
        v107 = *(_DWORD *)(work + 0xC74);
        if ( v107 == 1 )
        {
          sprintf(s, "%s%02d.txt", *(const char **)(HIDWORD(work) + 8), 1);
          v185 = fopen(s, "a+");
          v186 = *v358;
          *(_DWORD *)(work + 0xC7C) = v185;
          if ( v186 || opt_log_output || opt_log_level > 2 )
          {
            snprintf(str, 0x1000u, "Log work open asic %d file %s", *(_DWORD *)(work + 0xC74), s);
            applog(3, str, 0);
          }
        }
        else if ( ((v107 - 32) & 0xFFFFFFDF) == 0 )
        {
          v108 = 0;
          v109 = work;
          while ( 1 )
          {
            v112 = *(_DWORD *)(v109 + 0xC74);
            if ( v112 < v108 )
              break;
            sprintf(s, "%s%02d_%02d.txt", *(const char **)(HIDWORD(work) + 8), v112, v108);
            v110 = fopen(s, "a+");
            v111 = v358;
            g_logwork_files[v108] = v110;
            if ( *v111 || opt_log_output || opt_log_level > 2 )
            {
              snprintf(str, 0x1000u, "Log work open asic %d file %s", *(_DWORD *)(v109 + 0xC74), s);
              applog(3, str, 0);
            }
            ++v108;
          }
        }
        if ( *(_BYTE *)(work + 0xD80) )
        {
          v113 = &opt_logwork_diff;
          argva = (char **)"Log work open diff file %s";
          v114 = HIDWORD(work);
          for ( i1 = 0; i1 != 65; ++i1 )
          {
            sprintf(s, "%s_diff_%02d.txt", *(const char **)(v114 + 8), i1);
            v116 = fopen(s, "a+");
            v117 = v358;
            *((_DWORD *)v113 + 1) = v116;
            v113 += 4;
            if ( *v117 || opt_log_output || opt_log_level > 2 )
            {
              snprintf(str, 0x1000u, (const char *)argva, s);
              applog(3, str, 0);
            }
          }
        }
LABEL_109:
        if ( *v358 || opt_log_output )
          goto LABEL_111;
        goto LABEL_190;
      }
      snprintf(str, 0x1000u, "Log file path: %s Open flag: %s", g_logfile_path, (const char *)v354);
      applog(3, str, 0);
    }
    v102 = *(const char **)(HIDWORD(work) + 8);
    if ( !v102 )
      goto LABEL_109;
    goto LABEL_81;
  }
  v150 = calloc(24 * *(_DWORD *)(v77 + 4), 1u);
  if ( v150 )
  {
    v151 = *(_DWORD *)(v77 + 12);
    v152 = v151 >> (*(_QWORD *)(v77 + 8) + 1);
    if ( ((2 * *(_DWORD *)(v77 + 4) - 1) & v151) != 0 )
      ++v152;
    *(_DWORD *)(v77 + 24) = v152;
    *(_DWORD *)(*((_DWORD *)v35 + 17) + 28) = 0;
    v153 = *((_DWORD *)v35 + 17);
    if ( *(_DWORD *)(v153 + 4) )
    {
      v154 = v35;
      v353 = 0;
      do
      {
        v155 = *(_DWORD **)(*(_DWORD *)v153 + 12 * (_DWORD)v353);
        if ( v155 )
        {
          do
          {
            v156 = (_DWORD *)v155[4];
            v157 = 3 * ((2 * *(_DWORD *)(v153 + 4) - 1) & v155[7]);
            v158 = (char *)&v150[3 * ((2 * *(_DWORD *)(v153 + 4) - 1) & v155[7])];
            v159 = *((_DWORD *)v158 + 1) + 1;
            *((_DWORD *)v158 + 1) = v159;
            if ( v159 > *(_DWORD *)(v153 + 24) )
            {
              ++*(_DWORD *)(v153 + 28);
              *((_DWORD *)v158 + 2) = *((_DWORD *)v158 + 1) / *(_DWORD *)(*((_DWORD *)v154 + 17) + 24);
            }
            v155[3] = 0;
            v155[4] = v150[v157];
            v160 = v150[v157];
            if ( v160 )
              *(_DWORD *)(v160 + 12) = v155;
            v150[v157] = v155;
            v155 = v156;
            v153 = *((_DWORD *)v154 + 17);
          }
          while ( v156 );
        }
        v164 = *(_DWORD *)(v153 + 4) > (unsigned int)&v353->drv_id + 1;
        v353 = (device_drv *)((char *)v353 + 1);
      }
      while ( v164 );
      v35 = v154;
    }
    free(*(void **)v153);
    *(_DWORD *)(*((_DWORD *)v35 + 17) + 4) *= 2;
    ++*(_DWORD *)(*((_DWORD *)v35 + 17) + 8);
    **((_DWORD **)v35 + 17) = v150;
    v161 = (_DWORD *)*((_DWORD *)v35 + 17);
    v162 = v161[7];
    v163 = v161[3];
    v164 = v162 > v163 >> 1;
    if ( v162 <= v163 >> 1 )
      v165 = 0;
    else
      v165 = v161[8];
    if ( v164 )
      ++v165;
    v161[8] = v165;
    v166 = *((_DWORD *)v35 + 17);
    if ( *(_DWORD *)(v166 + 32) > 1u )
      *(_DWORD *)(v166 + 36) = 1;
    goto LABEL_42;
  }
LABEL_172:
  exit(-1);
  return result;
}
