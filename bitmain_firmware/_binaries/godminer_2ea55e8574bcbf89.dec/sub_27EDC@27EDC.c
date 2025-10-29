void __fastcall sub_27EDC(
        _DWORD *a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        char *a9,
        int a10,
        int a11,
        void *a12,
        int a13)
{
  _BOOL4 v14; // r5
  _DWORD *v15; // r4
  char *v16; // r0
  char *v17; // r0
  char *v18; // r0
  char *v19; // r0
  int v20; // r8
  float v21; // s18
  float v22; // s16
  double v23; // d10
  _DWORD *v24; // r4
  _QWORD *v25; // r0
  char *v26; // r0
  double v27; // d0
  float v28; // s21
  _QWORD *v29; // r0
  double v30; // d9
  double v31; // d8
  bool v32; // cc
  double *v33; // r0
  double *v34; // r0
  double *v35; // r0
  double *v36; // r0
  _QWORD *v37; // r0
  _QWORD *v38; // r0
  int v39; // r3
  int v40; // r0
  int v41; // r2
  _QWORD *v42; // r0
  _QWORD *v43; // r0
  int v44; // r5
  int v45; // r6
  int v46; // t1
  _QWORD *v47; // r0
  unsigned __int8 v48; // r0
  int v49; // r2
  int v50; // r1
  int v51; // lr
  _QWORD *v52; // r0
  int v53; // r10
  int v54; // r5
  int v55; // r11
  int *v56; // r0
  int v57; // r9
  int v58; // r3
  int v59; // r8
  int v60; // r2
  _QWORD *v61; // r0
  int *v62; // r0
  int v63; // r2
  int v64; // r8
  _QWORD *v65; // r0
  size_t *v66; // r8
  int v67; // r7
  int v68; // r5
  int v69; // t1
  int v70; // r1
  size_t v71; // t1
  char *v72; // r0
  int v73; // r7
  int v74; // r5
  int v75; // r6
  int v76; // t1
  char *v77; // r0
  int v78; // r7
  int v79; // r5
  int v80; // r6
  int v81; // t1
  char *v82; // r0
  int v83; // r10
  int v84; // r5
  int v85; // r6
  int v86; // t1
  char *v87; // r0
  _QWORD *v88; // r0
  int v89; // r7
  int v90; // r6
  int v91; // r9
  int v92; // t1
  int v93; // r0
  _QWORD *v94; // r0
  int v95; // r0
  int v96; // r1
  int v97; // r2
  int v98; // [sp+10h] [bp-123Ch]
  int v99; // [sp+18h] [bp-1234h]
  int v101; // [sp+34h] [bp-1218h]
  _DWORD *v102; // [sp+38h] [bp-1214h]
  __int64 v103; // [sp+40h] [bp-120Ch]
  int v104; // [sp+50h] [bp-11FCh] BYREF
  int v105; // [sp+54h] [bp-11F8h] BYREF
  int v106; // [sp+58h] [bp-11F4h] BYREF
  int v107; // [sp+5Ch] [bp-11F0h] BYREF
  double v108; // [sp+60h] [bp-11ECh] BYREF
  char v109[12]; // [sp+6Ch] [bp-11E0h] BYREF
  char v110[4]; // [sp+78h] [bp-11D4h] BYREF
  int v111; // [sp+7Ch] [bp-11D0h]
  int v112; // [sp+80h] [bp-11CCh]
  int v113; // [sp+84h] [bp-11C8h]
  char s[32]; // [sp+88h] [bp-11C4h] BYREF
  char v115[32]; // [sp+A8h] [bp-11A4h] BYREF
  char v116[32]; // [sp+C8h] [bp-1184h] BYREF
  char v117[32]; // [sp+E8h] [bp-1164h] BYREF
  char v118[32]; // [sp+108h] [bp-1144h] BYREF
  _DWORD v119[8]; // [sp+128h] [bp-1124h] BYREF
  char v120[256]; // [sp+148h] [bp-1104h] BYREF
  char v121[4]; // [sp+248h] [bp-1004h] BYREF
  int v122; // [sp+24Ch] [bp-1000h]
  int v123; // [sp+250h] [bp-FFCh]
  float v124; // [sp+258h] [bp-FF4h]
  float v125; // [sp+25Ch] [bp-FF0h]
  float v126; // [sp+260h] [bp-FECh]
  double v127; // [sp+268h] [bp-FE4h]

  v111 = 0;
  v112 = 0;
  v113 = 0;
  v14 = a1 == 0;
  *(_DWORD *)v110 = 0;
  memset(s, 0, sizeof(s));
  memset(v120, 0, sizeof(v120));
  v104 = 0;
  if ( !a2 )
    v14 = 1;
  if ( v14 )
  {
    V_LOCK();
    logfmt_raw(v121, 0x1000u, 0, "%s: input bad api param", "get_stats_old");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/api_new.c",
      141,
      "get_stats_old",
      13,
      1400,
      100,
      v121);
    JUMPOUT(0x28BF8);
  }
  sub_244FC(a1, 1, 70, *(const char **)(a2 + 8));
  v102 = json_array();
  v15 = json_object();
  v16 = (char *)BUFX_strdup("2.12");
  json_object_set_new(v15, "BMMiner", v16);
  v17 = (char *)BUFX_strdup(g_miner_version);
  json_object_set_new(v15, "Miner", v17);
  v18 = (char *)BUFX_strdup(g_miner_compiletime);
  json_object_set_new(v15, "CompileTime", v18);
  v19 = (char *)BUFX_strdup(g_miner_type);
  json_object_set_new(v15, "Type", v19);
  json_array_append_new(v102, v15);
  read_system_status_from_monitor((int)v121);
  v20 = v122;
  v21 = v125;
  v22 = v126;
  v23 = v127;
  get_all_created_runtime(&v104);
  v101 = frontend_runtime_instance();
  if ( v104 > 0 )
    JUMPOUT(0x28C08);
  v24 = json_object();
  v25 = json_integer(0);
  json_object_set_new(v24, "STATS", v25);
  snprintf(v110, 0x10u, "BTM_SOC%d", 0);
  v26 = (char *)BUFX_strdup(v110);
  json_object_set_new(v24, "ID", v26);
  format_hashrate_string(*(const char **)(*(_DWORD *)(v101 + 72) + 16), v115);
  format_hashrate_string(*(const char **)(*(_DWORD *)(v101 + 72) + 16), v116);
  format_hashrate_string(*(const char **)(*(_DWORD *)(v101 + 72) + 16), v117);
  format_hashrate_string(*(const char **)(*(_DWORD *)(v101 + 72) + 16), v118);
  v27 = v23;
  format_hashrate_double(*(const char **)(*(_DWORD *)(v101 + 72) + 16), &v108, v109);
  v28 = v124;
  get_miner_elapsed_time();
  get_total_nonce_rate();
  get_total_accept_rate();
  v29 = json_integer((__int64)v27);
  json_object_set_new(v24, "Elapsed", v29);
  v30 = v21 * v27;
  v31 = v22 * v27;
  v32 = (unsigned int)opt_algo > 0xA;
  if ( opt_algo != 10 )
    v32 = (unsigned int)(opt_algo - 6) > 1;
  if ( v32 )
    JUMPOUT(0x28C7C);
  sub_12E1AC((__int64)(v28 * v27 * 100.0));
  v33 = json_real();
  json_object_set_new(v24, "GHS 5s", v33);
  sub_12E1AC((__int64)(*(float *)&v27 * v31 * 100.0));
  v34 = json_real();
  json_object_set_new(v24, "GHS av", v34);
  sub_12E1AC((__int64)(*(float *)&v27 * v30 * 100.0));
  v35 = json_real();
  json_object_set_new(v24, "rate_30m", v35);
  sub_12E1AC((__int64)(v108 * 100.0));
  v36 = json_real();
  json_object_set_new(v24, "total_rateideal", v36);
  v37 = json_integer(opt_bitmain_work_mode);
  json_object_set_new(v24, "Mode", v37);
  v38 = json_integer(v104);
  json_object_set_new(v24, "miner_count", v38);
  if ( v104 <= 0 )
    JUMPOUT(0x28CB8);
  v39 = v14;
  v40 = 0x7FFFFFFF;
  do
  {
    v41 = *(_DWORD *)(v39 + 72);
    v39 += 216;
    if ( v40 >= v41 )
      v40 = v41;
  }
  while ( v14 + 216 * v104 != v39 );
  v42 = json_integer(v40);
  json_object_set_new(v24, "frequency", v42);
  v43 = json_integer(v20);
  json_object_set_new(v24, "fan_num", v43);
  if ( v20 > 0 )
  {
    v44 = 0;
    v45 = v123 - 4;
    do
    {
      ++v44;
      memset(s, 0, sizeof(s));
      snprintf(s, 0x20u, "fan%d", v44);
      v46 = *(_DWORD *)(v45 + 4);
      v45 += 4;
      v47 = json_integer(v46);
      json_object_set_new(v24, s, v47);
    }
    while ( v44 != v20 );
  }
  if ( v104 <= 0 )
    JUMPOUT(0x28CC4);
  v48 = 0;
  v49 = 0;
  v50 = -100;
  do
  {
    v51 = *(_DWORD *)(v49 + 16);
    v49 += 216;
    if ( v50 < v51 )
      v50 = v51;
    v48 += *(_DWORD *)(v49 - 192) + *(_DWORD *)(v49 - 188);
  }
  while ( v49 != 216 * v104 );
  v103 = v50;
  v52 = json_integer(v48);
  json_object_set_new(v24, "temp_num", v52);
  if ( v104 > 0 )
  {
    v53 = 0;
    v54 = 0;
    v98 = -4;
    do
    {
      v55 = *(_DWORD *)(v54 + 24);
      v56 = *(int **)v54;
      v105 = 0;
      ++v53;
      v106 = 0;
      v107 = 0;
      v54 += 216;
      v119[0] = 0;
      find_min_and_max_int(v56, v55, &v105, &v106);
      v57 = *(_DWORD *)(v54 - 188);
      find_min_and_max_int(*(int **)(v54 - 208), v57, &v107, v119);
      v58 = v119[0];
      v59 = *(_DWORD *)(v98 + 4);
      if ( v119[0] < v106 )
        v58 = v106;
      v60 = *(_DWORD *)(v98 + 4);
      v98 += 4;
      v99 = v58;
      sprintf(s, "temp%d", v60);
      v61 = json_integer(v99);
      json_object_set_new(v24, s, v61);
      v62 = *(int **)(v54 - 212);
      v119[0] = 0;
      v107 = 0;
      v106 = 0;
      v105 = 0;
      find_min_and_max_int(v62, v55, &v105, &v106);
      find_min_and_max_int(*(int **)(v54 - 204), v57, &v107, v119);
      v63 = v59;
      v64 = v106;
      if ( v119[0] >= v106 )
        v64 = v119[0];
      sprintf(s, "temp2_%d", v63);
      v65 = json_integer(v64);
      json_object_set_new(v24, s, v65);
    }
    while ( v104 > v53 );
    v66 = 0;
    if ( v104 > 0 )
    {
      v67 = -4;
      v68 = 0;
      do
      {
        ++v68;
        memset(s, 0, sizeof(s));
        memset(v120, 0, sizeof(v120));
        v69 = *(_DWORD *)(v67 + 4);
        v67 += 4;
        snprintf(s, 0x20u, "temp_in_pcb_%d", v69);
        v70 = v66[6];
        v71 = *v66;
        v66 += 54;
        sub_249AC(v71, v70, v120);
        v72 = (char *)BUFX_strdup(v120);
        json_object_set_new(v24, s, v72);
      }
      while ( v104 > v68 );
      if ( v104 > 0 )
      {
        v73 = -4;
        v74 = 0;
        v75 = 0;
        do
        {
          ++v75;
          memset(s, 0, sizeof(s));
          v74 += 216;
          memset(v120, 0, sizeof(v120));
          v76 = *(_DWORD *)(v73 + 4);
          v73 += 4;
          snprintf(s, 0x20u, "temp_out_pcb_%d", v76);
          sub_249AC(*(_DWORD *)(v74 - 208), *(_DWORD *)(v74 - 188), v120);
          v77 = (char *)BUFX_strdup(v120);
          json_object_set_new(v24, s, v77);
        }
        while ( v104 > v75 );
        if ( v104 > 0 )
        {
          v78 = -4;
          v79 = 0;
          v80 = 0;
          do
          {
            ++v80;
            memset(s, 0, sizeof(s));
            v79 += 216;
            memset(v120, 0, sizeof(v120));
            v81 = *(_DWORD *)(v78 + 4);
            v78 += 4;
            snprintf(s, 0x20u, "temp_in_chip_%d", v81);
            sub_249AC(*(_DWORD *)(v79 - 212), *(_DWORD *)(v79 - 192), v120);
            v82 = (char *)BUFX_strdup(v120);
            json_object_set_new(v24, s, v82);
          }
          while ( v104 > v80 );
          if ( v104 > 0 )
          {
            v83 = -4;
            v84 = 0;
            v85 = 0;
            do
            {
              ++v85;
              memset(s, 0, sizeof(s));
              v84 += 216;
              memset(v120, 0, sizeof(v120));
              v86 = *(_DWORD *)(v83 + 4);
              v83 += 4;
              snprintf(s, 0x20u, "temp_out_chip_%d", v86);
              sub_249AC(*(_DWORD *)(v84 - 208), *(_DWORD *)(v84 - 188), v120);
              v87 = (char *)BUFX_strdup(v120);
              json_object_set_new(v24, s, v87);
            }
            while ( v104 > v85 );
          }
        }
      }
    }
  }
  v88 = json_integer(v103);
  json_object_set_new(v24, "temp_max", v88);
  if ( v104 <= 0 )
    goto LABEL_50;
  v89 = 0;
  v90 = 0;
  v91 = -4;
  do
  {
    ++v90;
    memset(s, 0, sizeof(s));
    v92 = *(_DWORD *)(v91 + 4);
    v91 += 4;
    snprintf(s, 0x20u, "chain_acn%d", v92);
    v93 = *(_DWORD *)(v89 + 64);
    v89 += 216;
    v94 = json_integer(v93);
    v95 = json_object_set_new(v24, s, v94);
  }
  while ( v104 > v90 );
  if ( v104 <= 0 )
LABEL_50:
    JUMPOUT(0x28CDC);
  sub_28870(v95, v96, v97, v104, a5, a6, a7, a8, a9, a10, a11, a12, a13);
}
