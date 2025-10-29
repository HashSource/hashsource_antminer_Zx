int __fastcall main(int argc, const char **argv, const char **envp)
{
  int v3; // r0
  int (*v4)(void); // r2
  int (**v5)(void); // r3
  bool v6; // zf
  int v7; // r0
  char **v8; // r0
  int v9; // r3
  char **v10; // r5
  char **v11; // r6
  int v12; // r4
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
  bool *v38; // r3
  int v39; // r3
  int v40; // r2
  unsigned int v41; // r5
  device_drv *v42; // r9
  int64_t (*scanwork)(thr_info *); // r3
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
  int64_t (*v74)(thr_info *); // r2
  int v75; // r3
  __int64 v76; // kr08_8
  int v77; // r4
  char *v78; // r4
  pool *v79; // r5
  char *v80; // r0
  char **v81; // r3
  char *rpc_url; // r3
  pool_enable enabled; // r3
  unsigned __int8 *v84; // r9
  int v85; // r4
  unsigned __int8 *v86; // r5
  unsigned __int8 *v87; // r0
  const char *v88; // r1
  double v89; // r2
  const char *v90; // r0
  FILE *v91; // r5
  signed int v92; // r0
  char *v93; // r0
  char *v94; // r5
  bool *v95; // r11
  bool *v96; // r3
  bool *v97; // r3
  bool *v98; // r3
  bool *v99; // r3
  char **v100; // r4
  const char *v101; // r1
  const char *v102; // r1
  const char *v103; // r4
  const char *v104; // r0
  int v105; // r0
  FILE *v106; // r0
  _BOOL4 v107; // r3
  int v108; // r3
  int v109; // r4
  bool *v110; // r8
  FILE *v111; // r0
  _BOOL4 v112; // r3
  int v113; // r3
  bool *v114; // r8
  int v115; // r4
  FILE *v116; // r0
  _BOOL4 v117; // r3
  const char *v118; // r3
  char *v119; // r3
  char **v120; // r4
  int v121; // r3
  thr_info *v122; // r4
  char **v123; // r3
  device_drv *v124; // r2
  device_drv *v125; // r3
  int v126; // r0
  int v127; // r2
  device_drv *v128; // r0
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
  pthread_rwlock_t *v142; // r0
  char *v143; // r0
  int v144; // r4
  unsigned int v145; // r5
  char *i; // r0
  const char *v147; // r2
  int v148; // r3
  _DWORD *v149; // r8
  unsigned int v150; // r0
  unsigned int v151; // r3
  int v152; // r0
  char *v153; // r11
  _DWORD *v154; // r5
  _DWORD *v155; // r6
  int v156; // r4
  char *v157; // r9
  unsigned int v158; // r2
  int v159; // r3
  _DWORD *v160; // r3
  unsigned int v161; // r2
  unsigned int v162; // r1
  bool v163; // cc
  int v164; // r2
  int v165; // r3
  bool *v166; // r3
  _DWORD *v167; // r0
  _DWORD *v168; // r4
  void *v169; // r0
  char *v170; // r0
  char **v171; // r5
  char **v172; // r5
  char *v173; // r4
  char *v174; // r5
  int v175; // r0
  int v176; // r1
  int v177; // r2
  int v178; // r3
  _DWORD *v179; // r4
  _DWORD *v180; // r5
  int v181; // r1
  char v182; // r3
  char *v183; // r5
  FILE *v184; // r0
  _BOOL4 v185; // r3
  int v186; // r0
  const char *v187; // r2
  int v188; // r3
  int v189; // r2
  cgpu_info **v190; // r4
  cgpu_info *v191; // r3
  const char *v192; // r2
  int v193; // r3
  int v194; // r0
  drv_driver drv_id; // r4
  int j; // r3
  int v197; // r2
  int v198; // r9
  char *v199; // r3
  int v200; // r4
  int v201; // r3
  size_t v202; // r5
  size_t v203; // r5
  char *v204; // r0
  __int64 v205; // kr10_8
  _BOOL4 v206; // r2
  __sighandler_t v207; // r4
  __sighandler_t v208; // r0
  __pid_t v209; // r0
  __pid_t v210; // r4
  thr_info **v211; // r4
  int *v212; // r6
  signed int k; // r5
  int v214; // r4
  int v215; // r5
  cgpu_info *v216; // r6
  size_t v217; // r4
  thr_info **v218; // r0
  thr_info *thread; // r0
  device_drv *v220; // r3
  thr_info *v221; // r4
  int *v222; // r0
  const char *v223; // r2
  int v224; // r3
  int v225; // r2
  cgpu_info **v226; // r3
  cgpu_info *v227; // r1
  const char *v228; // r2
  int v229; // r3
  int *v230; // r0
  int v231; // r4
  int v232; // r1
  drv_driver v233; // r0
  int v234; // r5
  int v235; // r4
  int v236; // r5
  int m; // r4
  int v238; // r3
  thr_info *v239; // r4
  thr_info *v240; // r10
  thr_info *v241; // r3
  int v242; // r3
  int v243; // r4
  int v244; // r3
  int *v245; // r5
  bool *v246; // r6
  device_drv *v247; // r10
  signed int v248; // r5
  char *v249; // r3
  char **v250; // r0
  pthread_mutex_t *v251; // r1
  signed int v252; // r3
  char **v253; // r4
  char *v254; // r4
  signed int v255; // r3
  unsigned int *v256; // r1
  work *v257; // r0
  device_drv *work; // r10
  pool *v259; // r0
  pool *v260; // r5
  char *v261; // r3
  pool *v262; // r4
  pool *v263; // r0
  pool *v264; // r10
  char *v265; // r3
  pool *v266; // r5
  int v267; // r3
  int v268; // r2
  char *v269; // r1
  __int64 v270; // kr18_8
  int kk; // r3
  int v272; // r5
  int v273; // r3
  pool *v274; // r5
  int mm; // r4
  int v276; // r2
  __int64 v277; // kr20_8
  int v278; // r2
  char **v279; // r3
  void (*v280)(cgpu_info *); // r1
  char *(*v281)(cgpu_info *, char *, char *, char *); // r2
  bool (*v282)(thr_info *); // r3
  uint64_t (*v283)(thr_info *); // r0
  bool (*v284)(thr_info *); // r1
  bool (*v285)(thr_info *, work *); // r2
  device_drv *v286; // r3
  device_drv *v287; // r3
  const char *v288; // r5
  int v289; // r0
  int v290; // r1
  int v291; // r2
  int v292; // r3
  _DWORD *v293; // r5
  int v294; // r1
  int v295; // r2
  work *v296; // r0
  char **v297; // r3
  double v298; // r2
  int nn; // r4
  pool *v300; // r0
  pool *v301; // r0
  int v302; // r3
  int v303; // r2
  char *v304; // r1
  __int64 v305; // kr28_8
  int v306; // r3
  int ii; // r3
  int v308; // r9
  __int64 v309; // kr30_8
  pool *v310; // r0
  int v311; // r3
  int jj; // r9
  pool *v313; // r0
  int *v314; // r0
  const char *v315; // r2
  int v316; // r4
  int v317; // r0
  signed int v318; // r1
  int v319; // r3
  int v320; // r4
  int *v321; // r0
  int *v322; // r0
  int v323; // r4
  int n; // r3
  int v325; // r4
  char v327; // [sp+10h] [bp-2010h] BYREF
  char v328[4088]; // [sp+1018h] [bp-1008h] BYREF
  const char *v329; // [sp+2010h] [bp-10h]
  thr_info **v330; // [sp+2020h] [bp+0h]
  char **v331; // [sp+2024h] [bp+4h]
  unsigned int *v332; // [sp+2028h] [bp+8h]
  size_t *v333; // [sp+202Ch] [bp+Ch]
  device_drv *v334; // [sp+2030h] [bp+10h]
  device_drv *v335; // [sp+2034h] [bp+14h]
  device_drv *v336; // [sp+2038h] [bp+18h]
  device_drv *v337; // [sp+203Ch] [bp+1Ch]
  device_drv *v338; // [sp+2040h] [bp+20h]
  device_drv *v339; // [sp+2044h] [bp+24h]
  device_drv *v340; // [sp+2048h] [bp+28h]
  device_drv *v341; // [sp+204Ch] [bp+2Ch]
  device_drv *v342; // [sp+2050h] [bp+30h]
  device_drv *v343; // [sp+2054h] [bp+34h]
  device_drv *v344; // [sp+2058h] [bp+38h]
  __int64 v345; // [sp+205Ch] [bp+3Ch]
  bool *v346; // [sp+2064h] [bp+44h]
  device_drv *v347; // [sp+2068h] [bp+48h]
  device_drv *drv; // [sp+206Ch] [bp+4Ch]
  char **argva; // [sp+2070h] [bp+50h]
  bool *v350; // [sp+2074h] [bp+54h]
  char **v351; // [sp+2078h] [bp+58h]
  int argca; // [sp+207Ch] [bp+5Ch] BYREF
  struct sigaction act; // [sp+2084h] [bp+64h] BYREF
  char s[256]; // [sp+2110h] [bp+F0h] BYREF
  char str[4100]; // [sp+2210h] [bp+1F0h] BYREF

  argva = (char **)argv;
  argca = argc;
  strcpy(g_logfile_path, "cgminer.log");
  drv = (device_drv *)&g_logfile_enable;
  strcpy(g_logfile_openflag, "a+");
  g_logfile_enable = 0;
  LODWORD(v345) = g_logfile_openflag;
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
  v351 = &opt_logfile_path;
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
    (const char *)0x29C5,
    (unsigned __int16)&bench_lodiff_bins[2][12]);
  mutex_init_0(&update_job_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29C6, v16);
  mutex_init_0(&console_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29C7, v17);
  cglock_init_constprop_65((int)&control_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29C8);
  mutex_init_0(&stats_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29C9, v18);
  v350 = (bool *)&bench_lodiff_bins[2][12];
  mutex_init_0(
    &sharelog_lock,
    (pthread_mutex_t *)(&_func___17121.__align + 7),
    (const char *)0x29CA,
    (const int)&bench_lodiff_bins[2][12]);
  cglock_init_constprop_65((int)&ch_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29CB);
  mutex_init_0(&sshare_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29CC, v19);
  rwlock_init_0(&blk_lock, (pthread_rwlock_t *)(&_func___17121.__align + 7), (const char *)0x29CD, v20);
  rwlock_init_0(&netacc_lock, (pthread_rwlock_t *)(&_func___17121.__align + 7), (const char *)0x29CE, v21);
  rwlock_init_0(&mining_thr_lock, (pthread_rwlock_t *)(&_func___17121.__align + 7), (const char *)0x29CF, v22);
  rwlock_init_0(&devices_lock, (pthread_rwlock_t *)(&_func___17121.__align + 7), (const char *)0x29D0, v23);
  mutex_init_0(&lp_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29D2, v24);
  if ( pthread_cond_init(&lp_cond, 0) )
  {
    strcpy(str, "Failed to pthread_cond_init lp_cond");
    applog(3, str, 1);
    _quit(1, 0);
  }
  mutex_init_0(&restart_lock, (pthread_mutex_t *)(&_func___17121.__align + 7), (const char *)0x29D6, v25);
  if ( pthread_cond_init(&restart_cond, 0) )
  {
    strcpy(str, "Failed to pthread_cond_init restart_cond");
    goto LABEL_169;
  }
  v346 = (bool *)pthread_cond_init(&gws_cond, 0);
  if ( v346 )
  {
    strcpy(str, "Failed to pthread_cond_init gws_cond");
  }
  else
  {
    v26 = tq_new();
    getq = v26;
    if ( v26 )
    {
      v329 = (const char *)&unk_5320C;
      v351[273] = (char *)&v26->mutex;
      snprintf(packagename, 0x100u, "%s %s", "cgminer", v329);
      act.sa_handler = sighandler;
      act.sa_flags = (int)v346;
      sigemptyset(&act.sa_mask);
      sigaction_0(15, &act, &termhandler);
      sigaction_0(2, &act, &inthandler);
      signal(13, (__sighandler_t)1);
      opt_kernel_path = v328;
      v343 = (device_drv *)&opt_kernel_path;
      strcpy(v328, "/usr/local/bin");
      cgminer_path = &v327;
      v27 = *argva;
      HIDWORD(v345) = &word_4F7A8;
      v28 = _strdup(v27);
      v29 = cgminer_path;
      v30 = v28;
      v31 = dirname(v28);
      strcpy(v29, v31);
      free(v30);
      v32 = cgminer_path;
      v33 = strlen(cgminer_path);
      v34 = *(_WORD *)HIDWORD(v345);
      *((_DWORD *)v350 + 660) = 9;
      *(_WORD *)&v32[v33] = v34;
      v35 = (char *)calloc(0x68u, 1u);
      if ( !v35 )
      {
        strcpy(str, "main OOM");
        goto LABEL_174;
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
      v38 = v350;
      *((_DWORD *)v35 + 23) = v37;
      v39 = *((_DWORD *)v38 + 632);
      if ( v39 )
      {
        v40 = *(_DWORD *)(v39 + 68);
        v347 = (device_drv *)(v35 + 68);
        *(_DWORD *)(*(_DWORD *)(v40 + 16) + 8) = v35;
        *((_DWORD *)v35 + 18) = *(_DWORD *)(*(_DWORD *)(v39 + 68) + 16) - *(_DWORD *)(*(_DWORD *)(v39 + 68) + 20);
        *(_DWORD *)(*(_DWORD *)(v39 + 68) + 16) = v35 + 68;
      }
      else
      {
        v166 = v350;
        *((_DWORD *)v35 + 18) = 0;
        *((_DWORD *)v166 + 632) = v35;
        v167 = malloc(0x2Cu);
        v168 = v167;
        *((_DWORD *)v35 + 17) = v167;
        if ( !v167 )
          goto LABEL_164;
        memset(v167 + 3, 0, 0x20u);
        v168[1] = 32;
        v347 = (device_drv *)(v35 + 68);
        v168[2] = 5;
        v168[4] = v35 + 68;
        v168[5] = 68;
        v169 = calloc(0x180u, 1u);
        *v168 = v169;
        if ( !v169 )
          goto LABEL_164;
        v168[10] = -1609490463;
      }
      LOWORD(v41) = 31161;
      v42 = (device_drv *)*((_DWORD *)v350 + 632);
      ++*((_DWORD *)v42->scanwork + 3);
      scanwork = v42->scanwork;
      *((_DWORD *)v35 + 24) = -17973521;
      *((_DWORD *)v35 + 17) = scanwork;
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
        v344 = v42;
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
        v42 = v344;
        v61 = v51;
      }
      v62 = strlen(v35) + *((_DWORD *)v35 + 24);
      *((_DWORD *)v35 + 24) = v62;
      v63 = v62;
      switch ( v44 )
      {
        case 1u:
          goto LABEL_32;
        case 2u:
          goto LABEL_31;
        case 3u:
          goto LABEL_30;
        case 4u:
          goto LABEL_29;
        case 5u:
          goto LABEL_28;
        case 6u:
          goto LABEL_27;
        case 7u:
          goto LABEL_26;
        case 8u:
          goto LABEL_25;
        case 9u:
          goto LABEL_24;
        case 0xAu:
          goto LABEL_23;
        case 0xBu:
          v63 = v62 + (v61[10] << 24);
          *((_DWORD *)v35 + 24) = v63;
LABEL_23:
          v63 += v61[9] << 16;
          *((_DWORD *)v35 + 24) = v63;
LABEL_24:
          v63 += v61[8] << 8;
          *((_DWORD *)v35 + 24) = v63;
LABEL_25:
          v41 += v61[7] << 24;
LABEL_26:
          v41 += v61[6] << 16;
LABEL_27:
          v41 += v61[5] << 8;
LABEL_28:
          v41 += v61[4];
LABEL_29:
          v47 += v61[3] << 24;
LABEL_30:
          v47 += v61[2] << 16;
LABEL_31:
          v47 += v61[1] << 8;
LABEL_32:
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
      v72 = 12 * (v71 & (*((_DWORD *)v42->scanwork + 1) - 1));
      ++*(_DWORD *)(*(_DWORD *)v42->scanwork + v72 + 4);
      v73 = *(_DWORD *)(*(_DWORD *)v42->scanwork + v72);
      *((_DWORD *)v35 + 20) = 0;
      *((_DWORD *)v35 + 21) = v73;
      v74 = v42->scanwork;
      v75 = *(_DWORD *)(*(_DWORD *)v74 + v72);
      if ( v75 )
      {
        *(_DWORD *)(v75 + 12) = v347;
        v74 = v42->scanwork;
      }
      *(_DWORD *)(*(_DWORD *)v74 + v72) = v347;
      v76 = *(_QWORD *)(v72 + *(_DWORD *)v42->scanwork + 4);
      if ( (unsigned int)v76 < 10 * HIDWORD(v76) + 10 || (v77 = *((_DWORD *)v35 + 17), *(_DWORD *)(v77 + 36) == 1) )
      {
LABEL_37:
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
        v78 = (char *)*((unsigned __int8 *)v351 + 856);
        if ( !*((_BYTE *)v351 + 856) )
        {
          v170 = (char *)malloc(0x1000u);
          v171 = v351;
          v351[215] = v170;
          default_save_file(v170);
          if ( access(v171[215], 4) )
          {
            v172 = v351;
            free(v351[215]);
            v172[215] = v78;
          }
          else
          {
            load_config(v171[215], 0);
          }
        }
        if ( *((_BYTE *)v351 + 1377) || v351[269] )
        {
          if ( opt_scrypt )
          {
            strcpy(str, "Cannot use benchmark mode with scrypt");
            applog(3, str, 1);
            _quit(1, 1);
          }
          v79 = add_pool();
          v80 = (char *)malloc(0xFFu);
          v81 = v351;
          v79->rpc_url = v80;
          if ( v81[269] )
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
        v90 = v351[4];
        if ( !v90 )
          goto LABEL_65;
        v91 = fopen(v90, "rb");
        memset(s, 0, sizeof(s));
        if ( v91 )
        {
          v92 = fread(s, 1u, 0x100u, v91);
          if ( v92 <= 0 )
          {
            v95 = &use_syslog;
            if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
              goto LABEL_196;
            snprintf(str, 0x1000u, "Read miner version file %s error %d", v351[4], v92);
            applog(3, str, 0);
          }
          else
          {
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
            LOWORD(v95) = 8008;
            v96 = &v350[strlen(g_miner_compiletime) - 1];
            if ( v96[2676] == 10 )
              v96[2676] = 0;
            v97 = &v350[strlen(g_miner_compiletime) - 1];
            if ( v97[2676] == 13 )
              v97[2676] = 0;
            v98 = &v350[strlen(g_miner_type) - 1];
            if ( v98[2932] == 10 )
              v98[2932] = 0;
            v99 = &v350[strlen(g_miner_type) - 1];
            HIWORD(v95) = 7;
            if ( v99[2932] == 13 )
              v99[2932] = 0;
          }
        }
        else
        {
          v95 = &use_syslog;
          if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
            goto LABEL_196;
          snprintf(str, 0x1000u, "Open miner version file %s error", v351[4]);
          applog(3, str, 0);
        }
        if ( *v95 || opt_log_output )
          goto LABEL_64;
LABEL_196:
        if ( opt_log_level > 2 )
        {
LABEL_64:
          snprintf(str, 0x1000u, "Miner compile time: %s type: %s", g_miner_compiletime, g_miner_type);
          applog(3, str, 0);
        }
LABEL_65:
        v100 = v351;
        v101 = *v351;
        if ( *v351 )
        {
          LOBYTE(drv->drv_id) = 1;
          strcpy(g_logfile_path, v101);
          v102 = v100[3];
          if ( v102 )
            strcpy(g_logfile_openflag, v102);
          if ( !use_syslog && !opt_log_output && opt_log_level <= 2 )
          {
            v103 = v351[2];
            if ( !v103 )
            {
LABEL_178:
              if ( opt_log_level <= 3 )
              {
LABEL_103:
                v118 = v351[215];
                if ( !v118 )
                  goto LABEL_116;
                if ( opt_debug )
                {
                  if ( !use_syslog && !opt_log_output && opt_log_level <= 6 )
                  {
                    v119 = v351[267];
                    if ( v119 != (char *)-1 )
                    {
LABEL_109:
                      if ( !v119 )
                      {
                        if ( (use_syslog || opt_log_output || opt_log_level > 3)
                          && ((strcpy(str, "Fatal JSON error in configuration file."), applog(4, str, 0), use_syslog)
                           || opt_log_output)
                          || opt_log_level > 3 )
                        {
                          strcpy(str, "Configuration file could not be used.");
                          applog(4, str, 0);
                        }
                      }
                      goto LABEL_115;
                    }
LABEL_187:
                    if ( !opt_log_output && opt_log_level <= 3 )
                    {
                      if ( !use_curses )
                        goto LABEL_115;
                      goto LABEL_190;
                    }
LABEL_208:
                    strcpy(str, "Error in configuration file, partially loaded.");
                    applog(4, str, 0);
                    if ( !use_curses )
                      goto LABEL_115;
                    if ( use_syslog || opt_log_output )
                      goto LABEL_191;
LABEL_190:
                    if ( opt_log_level > 3 )
                    {
LABEL_191:
                      strcpy(str, "Start cgminer with -T to see what failed to load.");
                      applog(4, str, 0);
                    }
LABEL_115:
                    v120 = v351;
                    free(v351[215]);
                    v120[215] = 0;
LABEL_116:
                    *(_WORD *)(v343->drv_id + strlen((const char *)v343->drv_id)) = *(_WORD *)HIDWORD(v345);
                    if ( want_per_device_stats )
                      opt_log_output = 1;
                    v332 = &global_quota_gcd;
                    if ( opt_scantime < 0 )
                    {
                      if ( opt_scrypt )
                        v121 = 30;
                      else
                        v121 = 60;
                      v332[504] = v121;
                    }
                    *((_DWORD *)v350 + 930) = 8;
                    v122 = (thr_info *)calloc(8u, 0x40u);
                    v330 = &control_thr;
                    control_thr = v122;
                    if ( v122 )
                    {
                      argva = (char **)&modminer_drv;
                      fill_device_drv(&bitforce_drv);
                      v331 = argva;
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
                      HIDWORD(v345) = (unsigned __int16)&bitfury_drv;
                      HIWORD(v124) = (unsigned int)&avalon4_drv >> 16;
                      v347 = (device_drv *)(unsigned __int16)&bflsc_drv;
                      drv = v124;
                      fill_device_drv((device_drv *)argva);
                      LOWORD(v125) = (_WORD)v347;
                      HIWORD(v125) = (unsigned int)&bflsc_drv >> 16;
                      v347 = v125;
                      fill_device_drv(drv);
                      LOWORD(v126) = WORD2(v345);
                      v344 = (device_drv *)(unsigned __int16)&cointerra_drv;
                      LODWORD(v345) = (unsigned __int16)&blockerupter_drv;
                      HIWORD(v126) = (unsigned int)&bitfury_drv >> 16;
                      HIDWORD(v345) = v126;
                      fill_device_drv(v347);
                      LOWORD(v127) = v345;
                      HIWORD(v127) = (unsigned int)&blockerupter_drv >> 16;
                      LODWORD(v345) = v127;
                      fill_device_drv((device_drv *)HIDWORD(v345));
                      LOWORD(v128) = (_WORD)v344;
                      v343 = (device_drv *)(unsigned __int16)&hashfast_drv;
                      v342 = (device_drv *)(unsigned __int16)&hashratio_drv;
                      HIWORD(v128) = (unsigned int)&cointerra_drv >> 16;
                      v344 = v128;
                      fill_device_drv((device_drv *)v345);
                      LOWORD(v129) = (_WORD)v343;
                      HIWORD(v129) = (unsigned int)&hashfast_drv >> 16;
                      v343 = v129;
                      fill_device_drv(v344);
                      LOWORD(v130) = (_WORD)v342;
                      v341 = (device_drv *)(unsigned __int16)&icarus_drv;
                      HIWORD(v130) = (unsigned int)&hashratio_drv >> 16;
                      v340 = (device_drv *)(unsigned __int16)&klondike_drv;
                      v342 = v130;
                      fill_device_drv(v343);
                      LOWORD(v131) = (_WORD)v341;
                      HIWORD(v131) = (unsigned int)&icarus_drv >> 16;
                      v341 = v131;
                      fill_device_drv(v342);
                      LOWORD(v132) = (_WORD)v340;
                      HIWORD(v132) = (unsigned int)&klondike_drv >> 16;
                      v340 = v132;
                      v339 = (device_drv *)(unsigned __int16)&knc_drv;
                      v338 = (device_drv *)(unsigned __int16)&bitmineA1_drv;
                      fill_device_drv(v341);
                      LOWORD(v133) = (_WORD)v339;
                      HIWORD(v133) = (unsigned int)&knc_drv >> 16;
                      v339 = v133;
                      fill_device_drv(v340);
                      LOWORD(v134) = (_WORD)v338;
                      HIWORD(v134) = (unsigned int)&bitmineA1_drv >> 16;
                      v338 = v134;
                      v337 = (device_drv *)(unsigned __int16)&drillbit_drv;
                      v336 = (device_drv *)(unsigned __int16)&bab_drv;
                      fill_device_drv(v339);
                      LOWORD(v135) = (_WORD)v337;
                      HIWORD(v135) = (unsigned int)&drillbit_drv >> 16;
                      v337 = v135;
                      fill_device_drv(v338);
                      LOWORD(v136) = (_WORD)v336;
                      HIWORD(v136) = (unsigned int)&bab_drv >> 16;
                      v336 = v136;
                      v335 = (device_drv *)(unsigned __int16)&minion_drv;
                      v334 = (device_drv *)(unsigned __int16)&sp10_drv;
                      fill_device_drv(v337);
                      LOWORD(v137) = (_WORD)v335;
                      HIWORD(v137) = (unsigned int)&minion_drv >> 16;
                      v335 = v137;
                      fill_device_drv(v336);
                      LOWORD(v138) = (_WORD)v334;
                      HIWORD(v138) = (unsigned int)&sp10_drv >> 16;
                      v334 = v138;
                      v333 = (size_t *)(unsigned __int16)&mining_threads;
                      fill_device_drv(v335);
                      fill_device_drv(v334);
                      LOWORD(v139) = (_WORD)v333;
                      HIWORD(v139) = (unsigned int)&mining_threads >> 16;
                      v333 = v139;
                      fill_device_drv(&sp30_drv);
                      (*(void (__fastcall **)(_DWORD))(v140 + 12))(0);
                      ((void (__fastcall *)(_DWORD))v331[3])(0);
                      bitmain_drv.drv_detect(0);
                      bitmain_c5_drv.drv_detect(0);
                      ((void (__fastcall *)())bitmainZCASH_drv.drv_detect)();
                      bmsc_drv.drv_detect(0);
                      avalon_drv.drv_detect(0);
                      v141 = 0;
                      CONTAINING_RECORD(argva, device_drv, dname)->reinit_device(0);
                      drv->drv_detect(0);
                      v347->drv_detect(0);
                      (*(void (__fastcall **)(_DWORD))(HIDWORD(v345) + offsetof(device_drv, drv_detect)))(0);
                      (*(void (__fastcall **)(_DWORD))(v345 + offsetof(device_drv, drv_detect)))(0);
                      v344->drv_detect(0);
                      v343->drv_detect(0);
                      v342->drv_detect(0);
                      v341->drv_detect(0);
                      v340->drv_detect(0);
                      v339->drv_detect(0);
                      v338->drv_detect(0);
                      v337->drv_detect(0);
                      v336->drv_detect(0);
                      v335->drv_detect(0);
                      v334->drv_detect(0);
                      sp30_drv.drv_detect(0);
                      *v333 = 0;
                      while ( total_devices > v141 )
                      {
                        v142 = (pthread_rwlock_t *)devices[v141++];
                        enable_device(v142);
                      }
                      if ( total_devices )
                      {
                        v143 = v351[202];
                        *((_DWORD *)v350 + 659) = total_devices;
                        if ( v143 )
                        {
                          v144 = 0;
                          v145 = 0;
                          for ( i = strtok(v143, ","); i; i = strtok((char *)argva, ",") )
                          {
                            if ( total_devices <= v144 )
                            {
                              strcpy(str, "Too many values passed to set temp cutoff");
LABEL_174:
                              applog(3, str, 1);
                              _quit(1, 1);
                            }
                            v145 = strtol(i, 0, 10);
                            if ( v145 > 0xC8 )
                            {
                              v173 = "ssed to set temp cutoff";
                              qmemcpy(str, "Invalid value pa", 16);
                              v174 = &str[16];
                              goto LABEL_206;
                            }
                            if ( pthread_rwlock_rdlock(&devices_lock) )
                              rd_lock((pthread_rwlock_t *)&_func___14711, (const char *)0x479, v147, v148);
                            devices[v144]->cutofftemp = v145;
                            if ( pthread_rwlock_unlock(&devices_lock) )
                            {
                              v222 = _errno_location();
                              snprintf(
                                str,
                                0x1000u,
                                "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                                *v222,
                                "cgminer.c",
                                (const char *)&_func___14711,
                                1147);
                              goto LABEL_207;
                            }
                            ++v144;
                            argva = 0;
                            selective_yield();
                          }
                          if ( v144 > 1 )
                          {
                            drv = (device_drv *)&devices;
                            goto LABEL_232;
                          }
                          if ( pthread_rwlock_rdlock(&devices_lock) )
                            rd_lock((pthread_rwlock_t *)&_func___14711, (const char *)0x48C, v223, v224);
                          v225 = total_devices;
                          drv = (device_drv *)&devices;
                          v226 = devices;
                          while ( v144 < v225 )
                          {
                            v227 = v226[v144++];
                            v227->cutofftemp = v145;
                          }
                          if ( pthread_rwlock_unlock(&devices_lock) )
                            rw_unlock((pthread_rwlock_t *)&_func___14711, (const char *)0x48F, v228, v229);
                        }
                        else
                        {
                          v186 = pthread_rwlock_rdlock(&devices_lock);
                          if ( v186 )
                            rd_lock((pthread_rwlock_t *)&_func___14711, (const char *)0x480, v187, v188);
                          v189 = total_devices;
                          drv = (device_drv *)&devices;
                          v190 = devices;
                          while ( v186 < v189 )
                          {
                            v191 = v190[v186];
                            if ( !v191->cutofftemp )
                              v191->cutofftemp = 95;
                            ++v186;
                          }
                          if ( pthread_rwlock_unlock(&devices_lock) )
                            rw_unlock((pthread_rwlock_t *)&_func___14711, (const char *)0x486, v192, v193);
                        }
                        selective_yield();
LABEL_232:
                        v194 = total_devices;
                        drv_id = drv->drv_id;
                        for ( j = 0; v194 > j; ++j )
                        {
                          v197 = *(_DWORD *)(drv_id + 4 * j);
                          *(_DWORD *)(v197 + 312) = 99999999;
                        }
                        if ( !opt_compact )
                          *((_DWORD *)v350 + 660) += *((_DWORD *)v350 + 659);
                        if ( !total_pools )
                        {
                          if ( use_syslog || opt_log_output || opt_log_level > 3 )
                          {
                            strcpy(str, "Need to specify at least one pool server.");
                            applog(4, str, 0);
                          }
                          strcpy(str, "Pool setup failed");
                          applog(3, str, 1);
                          _quit(1, 0);
                        }
                        v198 = 0;
                        argva = (char **)&pools;
                        v347 = (device_drv *)"%s:%s";
                        while ( 1 )
                        {
                          v199 = *argva;
                          if ( total_pools <= v198 )
                            break;
                          v200 = *(_DWORD *)&v199[4 * v198];
                          v201 = *(_DWORD *)(v200 + 200);
                          *(_DWORD *)(v200 + 428) = 99999999;
                          *(_DWORD *)(v200 + 464) = 99999999;
                          if ( !v201 )
                          {
                            if ( !*(_DWORD *)(v200 + 208) )
                              *(_DWORD *)(v200 + 208) = calloc(1u, 1u);
                            if ( !*(_DWORD *)(v200 + 204) )
                            {
                              snprintf(
                                str,
                                0x1000u,
                                "No login credentials supplied for pool %u %s",
                                v198,
                                *(const char **)(v200 + 196));
                              applog(3, str, 1);
                              _quit(1, 0);
                            }
                            LODWORD(v345) = *(_DWORD *)(v200 + 204);
                            v202 = strlen((const char *)v345);
                            HIDWORD(v345) = *(_DWORD *)(v200 + 208);
                            v203 = v202 + strlen((const char *)HIDWORD(v345)) + 2;
                            v204 = (char *)malloc(v203);
                            v205 = v345;
                            *(_DWORD *)(v200 + 200) = v204;
                            if ( !v204 )
                            {
                              strcpy(str, "Failed to malloc userpass");
                              goto LABEL_169;
                            }
                            snprintf(v204, v203, (const char *)v347, (_DWORD)v205, HIDWORD(v205));
                          }
                          ++v198;
                        }
                        v206 = use_syslog;
                        v351[319] = *(char **)v199;
                        if ( v206 )
                          openlog("cgminer", 1, 8);
                        if ( *((_DWORD *)v350 + 931) )
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
                          v207 = signal(13, (__sighandler_t)1);
                          v208 = signal(13, (__sighandler_t)1);
                          if ( v207 == (__sighandler_t)-1 || v208 == (__sighandler_t)-1 )
                          {
                            perror("signal - failed to edit signal mask for --monitor");
                            exit(1);
                          }
                          v209 = fork();
                          v210 = v209;
                          v351[209] = (char *)v209;
                          if ( v209 < 0 )
                          {
                            perror("fork - failed to fork child process for --monitor");
                            exit(1);
                          }
                          if ( !v209 )
                          {
                            if ( dup2(*(int *)str, v209) >= 0 )
                            {
                              close(*(int *)str);
                              execl("/bin/bash", "/bin/bash", "-c", *((_DWORD *)v350 + 931), v210);
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
                        v211 = (thr_info **)calloc(*v333, 4u);
                        LODWORD(v345) = &mining_thr;
                        mining_thr = v211;
                        if ( !v211 )
                        {
                          strcpy(str, "Failed to calloc mining_thr");
LABEL_277:
                          applog(3, str, 1);
                          _quit(1, 0);
                        }
                        v212 = (int *)v345;
                        for ( k = 0; (int)*v333 > k; ++k )
                        {
                          v214 = *v212;
                          *(_DWORD *)(v214 + 4 * k) = calloc(1u, 0x40u);
                          if ( !*(_DWORD *)(*v212 + 4 * k) )
                          {
                            snprintf(str, 0x1000u, "Failed to calloc mining_thr[%d]", k);
                            goto LABEL_277;
                          }
                        }
                        v347 = 0;
                        HIDWORD(v345) = 0;
                        v344 = (device_drv *)miner_thread;
                        v343 = (device_drv *)&opt_debug;
                        while ( total_devices > (int)v347 )
                        {
                          v215 = 0;
                          v216 = *(cgpu_info **)(drv->drv_id + 4 * (_DWORD)v347);
                          v217 = v216->threads + 1;
                          v218 = (thr_info **)malloc(v217 * 4);
                          v216->thr = v218;
                          v218[v217 - 1] = 0;
                          v216->status = alive::LIFE_INIT;
                          while ( v216->threads > v215 )
                          {
                            v342 = (device_drv *)(HIDWORD(v345) + v215);
                            thread = get_thread(HIDWORD(v345) + v215);
                            v220 = v342;
                            v221 = thread;
                            thread->cgpu = v216;
                            thread->device_thread = v215;
                            thread->id = (int)v220;
                            if ( ((int (*)(void))v216->drv->thread_prepare)() )
                            {
                              if ( thr_info_create(v221, 0, (void *(*)(void *))v344, v221) )
                              {
                                snprintf(str, 0x1000u, "thread %d create failed", v221->id);
                                applog(3, str, 1);
                                _quit(1, 0);
                              }
                              v216->thr[v215] = v221;
                              if ( v216->deven != dev_enable::DEV_DISABLED )
                              {
                                if ( LOBYTE(v343->drv_id) && (use_syslog || opt_log_output || opt_log_level > 6) )
                                {
                                  snprintf(str, 0x1000u, "Pushing sem post to thread %d", v221->id);
                                  applog(7, str, 0);
                                }
                                cgsem_post(&v221->sem, "cgminer.c", &_func___17121.__size[28], 11098);
                              }
                            }
                            ++v215;
                          }
                          HIDWORD(v345) += v215;
                          v347 = (device_drv *)((char *)v347 + 1);
                        }
                        if ( !*((_BYTE *)v351 + 1377) )
                        {
                          v235 = (int)v351[269];
                          if ( !v235 )
                          {
                            while ( total_pools > v235 )
                            {
                              v236 = *(_DWORD *)&(*argva)[4 * v235];
                              if ( *(_DWORD *)(v236 + 132) != 1 )
                                enable_pool((pool *)(v236 + 132));
                              ++v235;
                              *(_BYTE *)(v236 + 129) = 1;
                            }
                            if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                            {
                              strcpy(str, "Probing for an alive pool");
                              applog(7, str, 0);
                            }
                            for ( m = 0; m < total_pools; ++m )
                            {
                              v238 = *(_DWORD *)&(*argva)[4 * m];
                              *(_BYTE *)(v238 + 316) = 1;
                              pthread_create((pthread_t *)(v238 + 312), 0, test_pool_thread, (void *)v238);
                            }
                            v243 = 0;
                            do
                            {
                              ++v243;
                              sleep(1u);
                              if ( v243 == 60 )
                                v244 = 0;
                              else
                                v244 = (*((_BYTE *)v351 + 1376) ^ 1) & 1;
                            }
                            while ( v244 );
                            v245 = &opt_log_level;
                            v344 = (device_drv *)"Pool: %d  URL: %s  User: %s  Password: %s";
                            v347 = (device_drv *)&use_curses;
                            while ( 1 )
                            {
                              if ( *((_BYTE *)v351 + 1376) )
                                goto begin_bench;
                              if ( v244 )
                                goto LABEL_340;
                              if ( ((use_syslog || opt_log_output || *v245 > 2)
                                 && ((strcpy(str, "No servers were found that could be used to get work from."),
                                      applog(3, str, 0),
                                      use_syslog)
                                  || opt_log_output)
                                 || *v245 > 2)
                                && ((strcpy(
                                       str,
                                       "Please check the details from the list below of the servers you have input"),
                                     applog(3, str, 0),
                                     use_syslog)
                                 || opt_log_output)
                                || *v245 > 2 )
                              {
                                strcpy(
                                  str,
                                  "Most likely you have input the wrong URL, forgotten to add a port, or have not set up workers");
                                applog(3, str, 0);
                              }
                              v323 = 0;
                              HIDWORD(v345) = v245;
                              while ( total_pools > v323 )
                              {
                                if ( use_syslog || opt_log_output || (int)*(_DWORD *)HIDWORD(v345) > 3 )
                                {
                                  snprintf(
                                    str,
                                    0x1000u,
                                    (const char *)v344,
                                    v323,
                                    *(_DWORD *)(*(_DWORD *)&(*argva)[4 * v323] + 196),
                                    *(_DWORD *)(*(_DWORD *)&(*argva)[4 * v323] + 204),
                                    *(_DWORD *)(*(_DWORD *)&(*argva)[4 * v323] + 208));
                                  applog(4, str, 0);
                                }
                                ++v323;
                              }
                              v245 = (int *)HIDWORD(v345);
                              if ( !LOBYTE(v347->drv_id) )
                              {
LABEL_489:
                                strcpy(str, "No servers could be used! Exiting.");
                                applog(3, str, 1);
                                _quit(0, 0);
                              }
                              if ( use_syslog || opt_log_output || (int)*(_DWORD *)HIDWORD(v345) > 2 )
                                break;
LABEL_341:
                              v244 = 1;
                            }
                            strcpy(str, "Press any key to exit, or cgminer will wait indefinitely for an alive pool.");
                            applog(3, str, 0);
LABEL_340:
                            if ( !LOBYTE(v347->drv_id) )
                              goto LABEL_489;
                            goto LABEL_341;
                          }
                        }
begin_bench:
                        v230 = (int *)g_local_mhashes_dones;
                        total_mhashes_done = 0.0;
                        do
                        {
                          *(_QWORD *)v230 = 0;
                          v230 += 2;
                        }
                        while ( &g_local_mhashes_index != v230 );
                        v231 = total_devices;
                        v232 = (int)v346;
                        v233 = drv->drv_id;
                        v351[304] = 0;
                        while ( v231 > v232 )
                        {
                          v234 = *(_DWORD *)(v233 + 4 * v232++);
                          *(_QWORD *)(v234 + 80) = 0;
                          *(_QWORD *)(v234 + 48) = 0;
                        }
                        cgtime(&total_tv_start);
                        cgtime(&total_tv_end);
                        cgtime(&tv_hashmeter);
                        get_datestamp(datestamp, 0x28u, &total_tv_start);
                        v239 = *v330;
                        v351[317] = (char *)2;
                        if ( thr_info_create(v239 + 2, 0, (void *(*)(void *))watchpool_thread, 0) )
                        {
                          strcpy(str, "watchpool thread create failed");
                          applog(3, str, 1);
                          _quit(1, 0);
                        }
                        pthread_detach(v239[2].pth);
                        v240 = *v330;
                        v351[318] = (char *)3;
                        if ( thr_info_create(v240 + 3, 0, (void *(*)(void *))watchdog_thread, 0) )
                        {
                          strcpy(str, "watchdog thread create failed");
                          applog(3, str, 1);
                          _quit(1, 0);
                        }
                        pthread_detach(v240[3].pth);
                        v241 = *v330;
                        v351[200] = (char *)5;
                        if ( thr_info_create(v241 + 5, 0, api_thread, &v241[5]) )
                        {
                          strcpy(str, "API thread create failed");
                          applog(3, str, 1);
                          _quit(1, 0);
                        }
                        v242 = *((_DWORD *)v350 + 930);
                        if ( v242 != 8 )
                        {
                          snprintf(str, 0x1000u, "incorrect total_control_threads (%d) should be 8", v242);
LABEL_169:
                          applog(3, str, 1);
                          _quit(1, 0);
                        }
                        if ( !nice(-10) && opt_debug && (use_syslog || opt_log_output || opt_log_level > 6) )
                        {
                          strcpy(str, "Unable to set thread to high priority");
                          applog(7, str, 0);
                        }
                        v246 = v350;
                        v247 = 0;
                        v350 = &use_syslog;
                        HIDWORD(v345) = &opt_work_update;
                        drv = (device_drv *)&opt_debug;
                        v346 = &opt_fail_only;
                        while ( 1 )
                        {
                          while ( 1 )
                          {
                            v248 = v332[502];
                            if ( *(_BYTE *)HIDWORD(v345) )
                            {
                              if ( LOBYTE(drv->drv_id) && (*v350 || opt_log_output || opt_log_level > 6) )
                              {
                                strcpy(str, "Work update message received");
                                applog(7, str, 0);
                              }
                              cgtime(&update_tv_start);
                              v317 = pthread_rwlock_rdlock(&mining_thr_lock);
                              if ( v317 )
                              {
                                v321 = _errno_location();
                                snprintf(
                                  str,
                                  0x1000u,
                                  "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
                                  *v321,
                                  "cgminer.c",
                                  &_func___14711.__align + 5,
                                  5314);
                                goto LABEL_207;
                              }
                              v318 = *v333;
                              v319 = *(_DWORD *)v345;
                              while ( v317 < v318 )
                              {
                                v320 = *(_DWORD *)(v319 + 4 * v317++);
                                *(_BYTE *)(v320 + 63) = 1;
                              }
                              if ( pthread_rwlock_unlock(&mining_thr_lock) )
                              {
                                v322 = _errno_location();
                                snprintf(
                                  str,
                                  0x1000u,
                                  "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                                  *v322,
                                  "cgminer.c",
                                  &_func___14711.__align + 5,
                                  5317);
LABEL_207:
                                applog(3, str, 1);
                                _quit(1, 1);
                              }
                              selective_yield();
                            }
                            *(_BYTE *)HIDWORD(v345) = 0;
                            current_pool();
                            if ( pthread_mutex_lock((pthread_mutex_t *)v351[273]) )
                            {
                              v314 = _errno_location();
                              v315 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
                              v316 = 11235;
LABEL_474:
                              snprintf(str, 0x1000u, v315, *v314, "cgminer.c", &_func___17121.__align + 7, v316);
                              goto LABEL_207;
                            }
                            v249 = v351[324];
                            if ( v249 )
                              v249 = *(char **)(*((_DWORD *)v249 + 458) + 12);
                            v250 = v351;
                            v251 = (pthread_mutex_t *)v351[273];
                            if ( v248 < (int)v249 )
                              break;
                            if ( pthread_mutex_unlock((pthread_mutex_t *)v351[273]) )
                              goto LABEL_513;
                            selective_yield();
LABEL_368:
                            if ( v247 )
                              discard_work((work *)v247);
                            work = (device_drv *)make_work();
                            v259 = current_pool();
                            v260 = v259;
                            v261 = v351[201];
                            if ( v261 == (char *)4 )
                            {
                              v262 = select_balanced(v259);
                            }
                            else if ( v261 == (char *)3 )
                            {
                              v302 = 0;
                              v303 = total_pools;
                              v304 = *argva;
                              while ( v302 < total_pools )
                              {
                                v305 = *(_QWORD *)(*(_DWORD *)&v304[4 * v302] + 60);
                                if ( SHIDWORD(v305) < (int)v305 )
                                  goto LABEL_449;
                                ++v302;
                              }
                              for ( n = 0; v303 > n; ++n )
                              {
                                v325 = *(_DWORD *)&v304[4 * n];
                                *(_DWORD *)(v325 + 64) = 0;
                              }
                              v306 = *((_DWORD *)v246 + 932) + 1;
                              *((_DWORD *)v246 + 932) = v306;
                              if ( v303 <= v306 )
                                *((_DWORD *)v246 + 932) = 0;
LABEL_449:
                              for ( ii = 0; ; ii = v308 )
                              {
                                v308 = ii + 1;
                                if ( ii >= total_pools )
                                  break;
                                v262 = *(pool **)&(*argva)[4 * *((_DWORD *)v246 + 932)];
                                v309 = *(_QWORD *)&v262->quota_gcd;
                                v262->quota_used = HIDWORD(v309) + 1;
                                if ( SHIDWORD(v309) < (int)v309 )
                                {
                                  if ( !v262->idle
                                    && v262->enabled == pool_enable::POOL_ENABLED
                                    && (!v262->has_stratum || v262->stratum_active) )
                                  {
                                    goto LABEL_373;
                                  }
                                  if ( *v346 )
                                  {
                                    v310 = priority_pool(0);
                                    --v310->quota_used;
                                  }
                                }
                                v311 = *((_DWORD *)v246 + 932) + 1;
                                v163 = v311 < total_pools;
                                *((_DWORD *)v246 + 932) = v311;
                                if ( !v163 )
                                  *((_DWORD *)v246 + 932) = 0;
                              }
                              for ( jj = 0; ; ++jj )
                              {
                                if ( jj >= total_pools )
                                  goto LABEL_372;
                                v313 = priority_pool(jj);
                                if ( !v313->idle && v313->enabled == pool_enable::POOL_ENABLED )
                                  break;
                              }
                              v262 = v313;
                            }
                            else
                            {
LABEL_372:
                              v262 = v260;
                            }
LABEL_373:
                            if ( LOBYTE(drv->drv_id) && (*v350 || opt_log_output || opt_log_level > 6) )
                            {
                              snprintf(str, 0x1000u, "Selecting pool %d for work", v262->pool_no);
                              applog(7, str, 0);
                              v347 = work;
                            }
                            else
                            {
                              v347 = work;
                            }
LABEL_378:
                            if ( v262->has_stratum )
                            {
                              while ( !v262->stratum_active || !v262->stratum_notify )
                              {
                                v263 = current_pool();
                                v264 = v263;
                                v265 = v351[201];
                                if ( v265 == (char *)4 )
                                {
                                  v266 = select_balanced(v263);
                                }
                                else if ( v265 == (char *)3 || !*v346 )
                                {
                                  v267 = 0;
                                  v268 = total_pools;
                                  v269 = *argva;
                                  while ( v267 < total_pools )
                                  {
                                    v270 = *(_QWORD *)(*(_DWORD *)&v269[4 * v267] + 60);
                                    if ( SHIDWORD(v270) < (int)v270 )
                                      goto LABEL_401;
                                    ++v267;
                                  }
                                  for ( kk = 0; v268 > kk; ++kk )
                                  {
                                    v272 = *(_DWORD *)&v269[4 * kk];
                                    *(_DWORD *)(v272 + 64) = 0;
                                  }
                                  v273 = *((_DWORD *)v246 + 932) + 1;
                                  *((_DWORD *)v246 + 932) = v273;
                                  if ( v268 <= v273 )
                                    *((_DWORD *)v246 + 932) = 0;
LABEL_401:
                                  v274 = v262;
                                  for ( mm = 0; mm < total_pools; ++mm )
                                  {
                                    v276 = *(_DWORD *)&(*argva)[4 * *((_DWORD *)v246 + 932)];
                                    v277 = *(_QWORD *)(v276 + 60);
                                    *(_DWORD *)(v276 + 64) = HIDWORD(v277) + 1;
                                    if ( SHIDWORD(v277) < (int)v277 )
                                    {
                                      if ( !*(_BYTE *)(v276 + 129)
                                        && *(_DWORD *)(v276 + 132) == 1
                                        && (!*(_BYTE *)(v276 + 664) || *(_BYTE *)(v276 + 665)) )
                                      {
                                        v262 = v274;
                                        v266 = (pool *)v276;
                                        goto LABEL_385;
                                      }
                                      if ( *v346 )
                                      {
                                        v301 = priority_pool(0);
                                        --v301->quota_used;
                                      }
                                    }
                                    v278 = *((_DWORD *)v246 + 932) + 1;
                                    v163 = v278 < total_pools;
                                    *((_DWORD *)v246 + 932) = v278;
                                    if ( !v163 )
                                      *((_DWORD *)v246 + 932) = 0;
                                  }
                                  for ( nn = 0; nn < total_pools; ++nn )
                                  {
                                    v300 = priority_pool(nn);
                                    if ( !v300->idle && v300->enabled == pool_enable::POOL_ENABLED )
                                    {
                                      v262 = v274;
                                      v266 = v300;
                                      goto LABEL_385;
                                    }
                                  }
                                  v262 = v274;
                                  v266 = v264;
                                }
                                else
                                {
                                  v266 = v263;
                                }
LABEL_385:
                                if ( LOBYTE(drv->drv_id) && (*v350 || opt_log_output || opt_log_level > 6) )
                                {
                                  snprintf(str, 0x1000u, "Selecting pool %d for work", v266->pool_no);
                                  applog(7, str, 0);
                                }
                                cgsleep_ms(5000);
                                if ( v262 != v266 )
                                {
                                  v262 = v266;
                                  goto LABEL_378;
                                }
                              }
                              v247 = v347;
                              gen_stratum_work(v262, (work *)v347);
                              if ( LOBYTE(drv->drv_id) && (*v350 || opt_log_output || opt_log_level > 6) )
                              {
                                strcpy(str, "Generated stratum work");
                                applog(7, str, 0);
                              }
                              goto LABEL_420;
                            }
                            v247 = v347;
                            if ( v351[269] )
                            {
                              benchfile_get_work((work *)v347);
                              v297 = argva;
                              BYTE2(v247[13].max_diff) = 1;
                              v247[13].hw_error = *(void (**)(thr_info *))*v297;
                              cgtime((timeval *)&v247[14].zero_stats);
                              copy_time((timeval *)&v247[14].max_diff, (const timeval *)&v247[14].zero_stats);
                              HIDWORD(v298) = 66;
                              LOBYTE(v247[15].name) = 66;
                              calc_diff((work *)v247, v298);
                              if ( LOBYTE(drv->drv_id) && (*v350 || opt_log_output || opt_log_level > 6) )
                              {
                                v288 = "Generated benchfile work";
                                goto LABEL_419;
                              }
LABEL_420:
                              v296 = (work *)v247;
                              v247 = 0;
                              stage_work(v296);
                            }
                            else if ( *((_BYTE *)v351 + 1377) )
                            {
                              *(_QWORD *)&v347[14].queue_full = 0x4040000000000000LL;
                              v279 = argva;
                              v247[13].scanwork = 0;
                              BYTE2(v247[13].max_diff) = 1;
                              v347 = (device_drv *)*v279;
                              v280 = *(void (**)(cgpu_info *))&bench_target[4];
                              v281 = *(char *(**)(cgpu_info *, char *, char *, char *))&bench_target[8];
                              v282 = *(bool (**)(thr_info *))&bench_target[12];
                              v247[1].get_stats = *(bool (**)(cgpu_info *))bench_target;
                              v247[1].identify_device = v280;
                              v247[1].set_device = v281;
                              v247[1].thread_prepare = v282;
                              v283 = *(uint64_t (**)(thr_info *))&bench_target[16];
                              v284 = *(bool (**)(thr_info *))&bench_target[20];
                              v285 = *(bool (**)(thr_info *, work *))&bench_target[24];
                              v247[1].hash_work = *(void (**)(thr_info *))&bench_target[28];
                              v286 = v347;
                              v247[1].prepare_work = v285;
                              v247[1].can_limit_work = v283;
                              v247[1].thread_init = v284;
                              v247[13].hw_error = (void (*)(thr_info *))v286->drv_id;
                              cgtime((timeval *)&v247[14].zero_stats);
                              copy_time((timeval *)&v247[14].max_diff, (const timeval *)&v247[14].zero_stats);
                              v287 = drv;
                              LOBYTE(v247[15].name) = 66;
                              if ( LOBYTE(v287->drv_id) && (*v350 || opt_log_output || opt_log_level > 6) )
                              {
                                v288 = "Generated benchmark work";
LABEL_419:
                                v289 = *(_DWORD *)v288;
                                v290 = *((_DWORD *)v288 + 1);
                                v291 = *((_DWORD *)v288 + 2);
                                v292 = *((_DWORD *)v288 + 3);
                                v293 = v288 + 16;
                                *(_DWORD *)str = v289;
                                *(_DWORD *)&str[4] = v290;
                                *(_DWORD *)&str[8] = v291;
                                *(_DWORD *)&str[12] = v292;
                                v294 = v293[1];
                                v295 = v293[2];
                                *(_DWORD *)&str[16] = *v293;
                                *(_DWORD *)&str[20] = v294;
                                str[24] = v295;
                                applog(7, str, 0);
                                goto LABEL_420;
                              }
                              goto LABEL_420;
                            }
                          }
                          if ( *((_BYTE *)v351 + 1417) )
                          {
                            v252 = v332[502];
                            if ( v252 < (int)v332[503] )
                            {
                              v332[502] = v252 + 1;
                              *((_BYTE *)v250 + 1417) = 0;
                            }
                          }
                          v253 = v351;
                          *((_BYTE *)v351 + 1416) = 1;
                          pthread_cond_wait(&gws_cond, v251);
                          v254 = v253[324];
                          if ( v254 )
                            v254 = *(char **)(*((_DWORD *)v254 + 458) + 12);
                          if ( pthread_mutex_unlock((pthread_mutex_t *)v351[273]) )
                          {
LABEL_513:
                            v314 = _errno_location();
                            v315 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
                            v316 = 11253;
                            goto LABEL_474;
                          }
                          selective_yield();
                          if ( (int)v254 <= v248 )
                            goto LABEL_368;
                          if ( *((_BYTE *)v351 + 1417) )
                          {
                            v255 = v332[502];
                            v256 = v332;
                            if ( v255 < (int)v332[503] )
                            {
                              *((_BYTE *)v351 + 1417) = 0;
                              v256[502] = v255 + 1;
                            }
                          }
                          *((_BYTE *)v351 + 1416) = 1;
                          v257 = hash_pop(0);
                          v247 = (device_drv *)v257;
                          if ( v257 )
                          {
                            discard_work(v257);
                            v247 = 0;
                          }
                        }
                      }
                      qmemcpy(str, "All devices disabled, cannot mine!", 34);
                      v182 = aAllDevicesDisa[34];
                      v183 = &str[34];
                    }
                    else
                    {
                      qmemcpy(str, "Failed to calloc control_thr", 28);
                      v182 = aFailedToCalloc[28];
                      v183 = &str[28];
                    }
                    *v183 = v182;
                    applog(3, str, 1);
                    _quit(1, 0);
                  }
                  snprintf(str, 0x1000u, "Loaded configuration file %s", v118);
                  applog(7, str, 0);
                }
                v119 = v351[267];
                if ( v119 != (char *)-1 )
                  goto LABEL_109;
                if ( use_syslog )
                  goto LABEL_208;
                goto LABEL_187;
              }
LABEL_102:
              snprintf(str, 0x1000u, "Started %s", packagename);
              applog(4, str, 0);
              goto LABEL_103;
            }
LABEL_72:
            memset(s, 0, sizeof(s));
            v104 = v351[1];
            if ( v104 )
            {
              if ( !*v104 )
              {
                v173 = "Log work asic num empty";
                v174 = str;
LABEL_206:
                v175 = *(_DWORD *)v173;
                v176 = *((_DWORD *)v173 + 1);
                v177 = *((_DWORD *)v173 + 2);
                v178 = *((_DWORD *)v173 + 3);
                v179 = v173 + 16;
                *(_DWORD *)v174 = v175;
                *((_DWORD *)v174 + 1) = v176;
                *((_DWORD *)v174 + 2) = v177;
                *((_DWORD *)v174 + 3) = v178;
                v180 = v174 + 16;
                v181 = v179[1];
                *v180 = *v179;
                v180[1] = v181;
                goto LABEL_207;
              }
              v105 = strtol(v104, 0, 10);
              *((_DWORD *)v350 + 797) = v105;
              if ( ((v105 - 32) & 0xFFFFFFDF) != 0 && v105 != 1 )
              {
                strcpy(str, "Log work asic num must be 1, 32, 64");
                applog(3, str, 1);
                _quit(1, 1);
              }
              if ( use_syslog || opt_log_output || opt_log_level > 2 )
              {
                snprintf(str, 0x1000u, "Log work path: %s Asic num: %s", v351[2], v351[1]);
                applog(3, str, 0);
              }
            }
            else if ( use_syslog || opt_log_output || opt_log_level > 2 )
            {
              snprintf(str, 0x1000u, "Log work path: %s", v103);
              applog(3, str, 0);
            }
            sprintf(s, "%s.txt", v351[2]);
            v106 = fopen(s, "a+");
            v107 = use_syslog;
            *((_DWORD *)v350 + 798) = v106;
            if ( v107 || opt_log_output || opt_log_level > 2 )
            {
              snprintf(str, 0x1000u, "Log work open file %s", s);
              applog(3, str, 0);
            }
            v108 = *((_DWORD *)v350 + 797);
            if ( v108 == 1 )
            {
              sprintf(s, "%s%02d.txt", v351[2], 1);
              v184 = fopen(s, "a+");
              v185 = use_syslog;
              *((_DWORD *)v350 + 799) = v184;
              if ( v185 || opt_log_output || opt_log_level > 2 )
              {
                snprintf(str, 0x1000u, "Log work open asic %d file %s", *((_DWORD *)v350 + 797), s);
                applog(3, str, 0);
              }
            }
            else if ( ((v108 - 32) & 0xFFFFFFDF) == 0 )
            {
              argva = (char **)"a+";
              v109 = 0;
              v110 = v350;
              while ( 1 )
              {
                v113 = *((_DWORD *)v110 + 797);
                if ( v113 < v109 )
                  break;
                sprintf(s, "%s%02d_%02d.txt", v351[2], v113, v109);
                v111 = fopen(s, (const char *)argva);
                v112 = use_syslog;
                g_logwork_files[v109] = v111;
                if ( v112 || opt_log_output || opt_log_level > 2 )
                {
                  snprintf(str, 0x1000u, "Log work open asic %d file %s", *((_DWORD *)v110 + 797), s);
                  applog(3, str, 0);
                }
                ++v109;
              }
            }
            if ( v350[3456] )
            {
              v114 = &opt_logwork_diff;
              v115 = 0;
              argva = (char **)"Log work open diff file %s";
              do
              {
                sprintf(s, "%s_diff_%02d.txt", v351[2], v115);
                v116 = fopen(s, "a+");
                v117 = use_syslog;
                *((_DWORD *)v114 + 1) = v116;
                v114 += 4;
                if ( v117 || opt_log_output || opt_log_level > 2 )
                {
                  snprintf(str, 0x1000u, (const char *)argva, s);
                  applog(3, str, 0);
                }
                ++v115;
              }
              while ( v115 != 65 );
            }
LABEL_100:
            if ( use_syslog || opt_log_output )
              goto LABEL_102;
            goto LABEL_178;
          }
          snprintf(str, 0x1000u, "Log file path: %s Open flag: %s", g_logfile_path, (const char *)v345);
          applog(3, str, 0);
        }
        v103 = v351[2];
        if ( !v103 )
          goto LABEL_100;
        goto LABEL_72;
      }
      v149 = calloc(24 * *(_DWORD *)(v77 + 4), 1u);
      if ( v149 )
      {
        v150 = *(_DWORD *)(v77 + 12);
        v151 = v150 >> (*(_QWORD *)(v77 + 8) + 1);
        if ( ((2 * *(_DWORD *)(v77 + 4) - 1) & v150) != 0 )
          ++v151;
        *(_DWORD *)(v77 + 24) = v151;
        *(_DWORD *)(*((_DWORD *)v35 + 17) + 28) = 0;
        v152 = *((_DWORD *)v35 + 17);
        if ( *(_DWORD *)(v152 + 4) )
        {
          v153 = v35;
          v347 = 0;
          do
          {
            v154 = *(_DWORD **)(*(_DWORD *)v152 + 12 * (_DWORD)v347);
            if ( v154 )
            {
              do
              {
                v155 = (_DWORD *)v154[4];
                v156 = 3 * ((2 * *(_DWORD *)(v152 + 4) - 1) & v154[7]);
                v157 = (char *)&v149[3 * ((2 * *(_DWORD *)(v152 + 4) - 1) & v154[7])];
                v158 = *((_DWORD *)v157 + 1) + 1;
                *((_DWORD *)v157 + 1) = v158;
                if ( v158 > *(_DWORD *)(v152 + 24) )
                {
                  ++*(_DWORD *)(v152 + 28);
                  *((_DWORD *)v157 + 2) = *((_DWORD *)v157 + 1) / *(_DWORD *)(*((_DWORD *)v153 + 17) + 24);
                }
                v154[3] = 0;
                v154[4] = v149[v156];
                v159 = v149[v156];
                if ( v159 )
                  *(_DWORD *)(v159 + 12) = v154;
                v149[v156] = v154;
                v154 = v155;
                v152 = *((_DWORD *)v153 + 17);
              }
              while ( v155 );
            }
            v163 = *(_DWORD *)(v152 + 4) > (unsigned int)&v347->drv_id + 1;
            v347 = (device_drv *)((char *)v347 + 1);
          }
          while ( v163 );
          v35 = v153;
        }
        free(*(void **)v152);
        *(_DWORD *)(*((_DWORD *)v35 + 17) + 4) *= 2;
        ++*(_DWORD *)(*((_DWORD *)v35 + 17) + 8);
        **((_DWORD **)v35 + 17) = v149;
        v160 = (_DWORD *)*((_DWORD *)v35 + 17);
        v161 = v160[7];
        v162 = v160[3];
        v163 = v161 > v162 >> 1;
        if ( v161 <= v162 >> 1 )
          v164 = 0;
        else
          v164 = v160[8];
        if ( v163 )
          ++v164;
        v160[8] = v164;
        v165 = *((_DWORD *)v35 + 17);
        if ( *(_DWORD *)(v165 + 32) > 1u )
          *(_DWORD *)(v165 + 36) = 1;
        goto LABEL_37;
      }
LABEL_164:
      exit(-1);
    }
    strcpy(str, "Failed to create getq");
  }
  applog(3, str, 1);
  _quit(1, 0);
}
