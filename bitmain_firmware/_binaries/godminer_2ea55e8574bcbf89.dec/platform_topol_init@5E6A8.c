int platform_topol_init()
{
  _DWORD *file; // r0
  _DWORD *v1; // r11
  _DWORD *v2; // r0
  _DWORD *v3; // r9
  _DWORD *v4; // r0
  const char *v5; // r9
  size_t v6; // r0
  char *v7; // r0
  _DWORD *v8; // r0
  _DWORD *v9; // r10
  _DWORD *v10; // r0
  _DWORD *v11; // r0
  _DWORD *v12; // r10
  _DWORD *v13; // r0
  _DWORD *v14; // r0
  _DWORD *v15; // r8
  _DWORD *v16; // r0
  _DWORD *v17; // r8
  _DWORD *v18; // r0
  int v19; // r0
  int v20; // r2
  unsigned int *v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // r2
  int v25; // r0
  int v26; // r2
  _DWORD *v27; // r0
  _DWORD *v28; // r10
  _DWORD *v29; // r0
  int v30; // r9
  int v31; // r0
  size_t v32; // r9
  _DWORD *v33; // r0
  int v34; // r6
  int v35; // r0
  _DWORD *v36; // r0
  int v37; // r6
  int v38; // r0
  _DWORD *v39; // r0
  int v40; // r6
  int v41; // r0
  _DWORD *v42; // r0
  int v43; // r6
  int v44; // r0
  _DWORD *v45; // r0
  int v46; // r8
  int v47; // r0
  _DWORD *v48; // r0
  _DWORD *v49; // r8
  char *v50; // r2
  _DWORD *v51; // r0
  int v52; // r8
  int v53; // r0
  _DWORD *v54; // r0
  int v55; // r8
  int v56; // r0
  size_t v57; // r0
  int v58; // r6
  void *v59; // r0
  _DWORD *v60; // r0
  int v61; // r6
  int v62; // r0
  _DWORD *v63; // r0
  int v64; // r6
  int v65; // r0
  _DWORD *v66; // r0
  int v67; // r6
  int v68; // r0
  _DWORD *v69; // r0
  int v70; // r6
  int v71; // r0
  int v72; // r3
  _DWORD *v73; // r0
  _DWORD *v74; // r0
  _DWORD *v75; // r11
  _DWORD *v76; // r0
  int v77; // r7
  int v78; // r0
  int v79; // r0
  int v80; // r9
  _DWORD *v81; // r9
  _DWORD *v82; // r0
  _DWORD *v83; // r7
  _DWORD *v84; // r0
  const char *v85; // r6
  int v86; // r3
  _DWORD *v87; // r0
  int v88; // r6
  int v89; // r0
  _DWORD *v90; // r0
  _DWORD *v91; // r6
  _DWORD *v92; // r0
  int v93; // r7
  char **v94; // r8
  const char *v95; // r0
  const char *v96; // r1
  const char *v97; // r10
  const char *v98; // t1
  int v99; // r6
  _DWORD *v100; // r0
  _DWORD *v101; // r8
  _DWORD *v102; // r0
  const char **v103; // r7
  const char *v104; // r0
  const char *v105; // r1
  const char *v106; // r8
  const char *v107; // t1
  int v108; // r0
  int v109; // r2
  int v110; // r0
  int v111; // r2
  _DWORD *v112; // r0
  int v113; // r8
  _DWORD *v114; // r0
  _DWORD *v115; // r0
  int v116; // r9
  char **v117; // r6
  int v118; // r4
  const char *v119; // r7
  const char *v120; // r1
  const char *v121; // t1
  int v122; // r2
  _DWORD *v123; // r0
  int v124; // r6
  int v125; // r0
  int v126; // r4
  int v127; // r5
  int v128; // r0
  int v129; // r3
  int v130; // r6
  int v131; // r5
  int v132; // r4
  void *v133; // r0
  unsigned int *v134; // r3
  unsigned int v135; // r2
  unsigned int v136; // r2
  int v137; // r0
  int v138; // r3
  _DWORD *v139; // r0
  _DWORD *v140; // r0
  _DWORD *v141; // r11
  _DWORD *v142; // r0
  int v143; // r7
  int v144; // r0
  int v145; // r0
  int v146; // r10
  _DWORD *v147; // r10
  _DWORD *v148; // r0
  _DWORD *v149; // r7
  _DWORD *v150; // r0
  const char *v151; // r6
  int v152; // r3
  _DWORD *v153; // r0
  int v154; // r6
  int v155; // r0
  _DWORD *v156; // r0
  _DWORD *v157; // r6
  _DWORD *v158; // r0
  int v159; // r7
  char **v160; // r8
  const char *v161; // r0
  const char *v162; // r1
  const char *v163; // r9
  const char *v164; // t1
  int v165; // r6
  _DWORD *v166; // r0
  _DWORD *v167; // r8
  _DWORD *v168; // r0
  const char **v169; // r7
  const char *v170; // r0
  const char *v171; // r1
  const char *v172; // r8
  const char *v173; // t1
  int v174; // r0
  int v175; // r0
  int v176; // r0
  int v177; // [sp+14h] [bp-1120h]
  unsigned int v178; // [sp+18h] [bp-111Ch]
  int v179; // [sp+18h] [bp-111Ch]
  unsigned int v180; // [sp+18h] [bp-111Ch]
  _DWORD *v181; // [sp+1Ch] [bp-1118h]
  _DWORD *v182; // [sp+1Ch] [bp-1118h]
  _DWORD *v183; // [sp+1Ch] [bp-1118h]
  _DWORD *v184; // [sp+20h] [bp-1114h]
  _DWORD *v185; // [sp+20h] [bp-1114h]
  _DWORD *v186; // [sp+20h] [bp-1114h]
  _DWORD *v187; // [sp+2Ch] [bp-1108h]
  _DWORD *v188; // [sp+2Ch] [bp-1108h]
  char v189[252]; // [sp+34h] [bp-1100h] BYREF
  char v190[4100]; // [sp+130h] [bp-1004h] BYREF

  file = json_load_file("/etc/topol.conf", 0, v189);
  v1 = file;
  if ( !file || *file )
  {
    V_LOCK();
    v177 = -1;
    logfmt_raw(v190, 0x1000u, 0, "load topol config file %s failed", "/etc/topol.conf");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "platform_topol_init",
      19,
      1488,
      20,
      v190);
    return v177;
  }
  v2 = (_DWORD *)json_object_get(file, "machine");
  v3 = v2;
  if ( !v2 || *v2 != 2 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get machine failed");
    V_UNLOCK();
    v25 = g_zc;
    v26 = 139;
LABEL_26:
    zlog(
      v25,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_parse_machine",
      14,
      v26,
      100,
      v190);
LABEL_27:
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "parse machine failed");
    V_UNLOCK();
    v19 = g_zc;
    v20 = 1495;
    goto LABEL_16;
  }
  V_LOCK();
  v4 = json_string_value(v3);
  logfmt_raw(v190, 0x1000u, 0, "load machine %s conf", v4);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_machine",
    14,
    142,
    20,
    v190);
  v5 = (const char *)json_string_value(v3);
  v6 = strlen(v5);
  v7 = (char *)calloc(v6 + 1, 1u);
  topol_machine = (int)v7;
  if ( !v7 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get machine failed, Cannot allocate space");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_parse_machine",
      14,
      148,
      100,
      v190);
    goto LABEL_27;
  }
  strcpy(v7, v5);
  V_LOCK();
  logfmt_raw(v190, 0x1000u, 0, "machine : %s ", topol_machine);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_machine",
    14,
    153,
    20,
    v190);
  v8 = (_DWORD *)json_object_get(v1, "hw_version");
  v9 = v8;
  if ( !v8 || *v8 != 2 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get hw_version failed");
    V_UNLOCK();
    v25 = g_zc;
    v26 = 158;
    goto LABEL_26;
  }
  V_LOCK();
  v10 = json_string_value(v9);
  logfmt_raw(v190, 0x1000u, 0, "hw_version: %s", v10);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_machine",
    14,
    161,
    20,
    v190);
  v11 = (_DWORD *)json_object_get(v1, "sw_version");
  v12 = v11;
  if ( !v11 || *v11 != 2 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get sw_version failed");
    V_UNLOCK();
    v25 = g_zc;
    v26 = 166;
    goto LABEL_26;
  }
  V_LOCK();
  v13 = json_string_value(v12);
  logfmt_raw(v190, 0x1000u, 0, "sw_version: %s", v13);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_machine",
    14,
    169,
    20,
    v190);
  v14 = (_DWORD *)json_object_get(v1, "processor");
  v15 = v14;
  if ( !v14 || *v14 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get processor failed");
    V_UNLOCK();
    v108 = g_zc;
    v109 = 181;
LABEL_95:
    zlog(
      v108,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_parse_processor",
      16,
      v109,
      100,
      v190);
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "parse processor failed");
    V_UNLOCK();
    v19 = g_zc;
    v20 = 1502;
    goto LABEL_16;
  }
  V_LOCK();
  logfmt_raw(v190, 0x1000u, 0, "processor:");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_processor",
    16,
    184,
    20,
    v190);
  v16 = (_DWORD *)json_object_get(v15, "type");
  v17 = v16;
  if ( !v16 || *v16 != 2 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get type failed");
    V_UNLOCK();
    v108 = g_zc;
    v109 = 189;
    goto LABEL_95;
  }
  V_LOCK();
  v18 = json_string_value(v17);
  logfmt_raw(v190, 0x1000u, 0, "type: %s", v18);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_processor",
    16,
    192,
    20,
    v190);
  if ( sub_5BCB8(v1) )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "parse power failed");
    V_UNLOCK();
    v19 = g_zc;
    v20 = 1509;
    goto LABEL_16;
  }
  if ( sub_5C3B4(v1) )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "parse fan failed");
    V_UNLOCK();
    v19 = g_zc;
    v20 = 1516;
    goto LABEL_16;
  }
  v27 = (_DWORD *)json_object_get(v1, "chain");
  v28 = v27;
  if ( !v27 || *v27 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get chain failed");
    V_UNLOCK();
    v110 = g_zc;
    v111 = 908;
    goto LABEL_97;
  }
  V_LOCK();
  logfmt_raw(v190, 0x1000u, 0, "chain:");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    911,
    20,
    v190);
  v29 = (_DWORD *)json_object_get(v28, "chain_num");
  v30 = (int)v29;
  if ( !v29 || *v29 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get chain_num failed");
    V_UNLOCK();
    v110 = g_zc;
    v111 = 916;
    goto LABEL_97;
  }
  V_LOCK();
  v31 = json_integer_value(v30);
  logfmt_raw(v190, 0x1000u, 0, "chain_num : %d", v31);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    919,
    20,
    v190);
  v32 = json_integer_value(v30);
  dword_186A78 = v32;
  V_LOCK();
  logfmt_raw(v190, 0x1000u, 0, "chain_num %d", v32);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_alloc_chain",
    12,
    80,
    20,
    v190);
  dword_186A98 = (int)calloc(v32, 0x78u);
  if ( !dword_186A98 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "malloc %d chain_t failed", v32);
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_alloc_chain",
      12,
      85,
      100,
      v190);
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "Sweep error string = %s.", "M:1");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_alloc_chain",
      12,
      86,
      100,
      v190);
    goto LABEL_98;
  }
  v33 = (_DWORD *)json_object_get(v28, "chain_row");
  v34 = (int)v33;
  if ( !v33 || *v33 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get chain_row failed");
    V_UNLOCK();
    v110 = g_zc;
    v111 = 927;
LABEL_97:
    zlog(
      v110,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_parse_chain",
      12,
      v111,
      100,
      v190);
LABEL_98:
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "parse chain failed");
    V_UNLOCK();
    v19 = g_zc;
    v20 = 1524;
LABEL_16:
    zlog(
      v19,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "platform_topol_init",
      19,
      v20,
      20,
      v190);
    if ( v1[1] != -1 )
    {
      v21 = v1 + 1;
      __dmb(0xBu);
      do
      {
        v22 = __ldrex(v21);
        v23 = v22 - 1;
      }
      while ( __strex(v23, v21) );
      if ( !v23 )
        json_delete(v1);
    }
    return 34;
  }
  V_LOCK();
  v35 = json_integer_value(v34);
  logfmt_raw(v190, 0x1000u, 0, "chain_row: %d", v35);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    930,
    20,
    v190);
  dword_186A7C = json_integer_value(v34);
  v36 = (_DWORD *)json_object_get(v28, "chain_column");
  v37 = (int)v36;
  if ( !v36 || *v36 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get chain_column failed");
    V_UNLOCK();
    v110 = g_zc;
    v111 = 936;
    goto LABEL_97;
  }
  V_LOCK();
  v38 = json_integer_value(v37);
  logfmt_raw(v190, 0x1000u, 0, "chain_column: %d", v38);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    939,
    20,
    v190);
  dword_186A80 = json_integer_value(v37);
  v39 = (_DWORD *)json_object_get(v28, "chain_domain_num");
  v40 = (int)v39;
  if ( !v39 || *v39 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get chain_domain_num failed");
    V_UNLOCK();
    v110 = g_zc;
    v111 = 945;
    goto LABEL_97;
  }
  V_LOCK();
  v41 = json_integer_value(v40);
  logfmt_raw(v190, 0x1000u, 0, "chain_domain_num : %d", v41);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    948,
    20,
    v190);
  dword_186A84 = json_integer_value(v40);
  v42 = (_DWORD *)json_object_get(v28, "chain_asic_num");
  v43 = (int)v42;
  if ( !v42 || *v42 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get chain_asic_num failed");
    V_UNLOCK();
    v110 = g_zc;
    v111 = 954;
    goto LABEL_97;
  }
  V_LOCK();
  v44 = json_integer_value(v43);
  logfmt_raw(v190, 0x1000u, 0, "chain_asic_num : %d", v44);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    957,
    20,
    v190);
  dword_186A88 = json_integer_value(v43);
  v45 = (_DWORD *)json_object_get(v28, "domain_asic_num");
  v46 = (int)v45;
  if ( !v45 || *v45 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get domain_asic_num failed");
    V_UNLOCK();
    v110 = g_zc;
    v111 = 963;
    goto LABEL_97;
  }
  V_LOCK();
  v47 = json_integer_value(v46);
  logfmt_raw(v190, 0x1000u, 0, "domain_asic_num : %d", v47);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    966,
    20,
    v190);
  dword_186A8C = json_integer_value(v46);
  v48 = (_DWORD *)json_object_get(v28, "pic_mcu_en");
  v49 = v48;
  if ( !v48 || (unsigned int)(*v48 - 5) > 1 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get pic_mcu_en failed!");
    V_UNLOCK();
    v137 = 972;
    goto LABEL_133;
  }
  V_LOCK();
  v50 = "false";
  if ( *v49 == 5 )
    v50 = "true";
  logfmt_raw(v190, 0x1000u, 0, "pic_mcu_en: %s", v50);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    975,
    20,
    v190);
  byte_186A90 = *v49 == 5;
  v51 = (_DWORD *)json_object_get(v28, "sensor_mode");
  v52 = (int)v51;
  if ( !v51 || *v51 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get sensor_mode failed");
    V_UNLOCK();
    v137 = 981;
    goto LABEL_133;
  }
  V_LOCK();
  v53 = json_integer_value(v52);
  logfmt_raw(v190, 0x1000u, 0, "sensor mode : %d", v53);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    984,
    20,
    v190);
  *(_DWORD *)(dword_186A98 + 88) = json_integer_value(v52);
  v54 = (_DWORD *)json_object_get(v28, "sensor_num");
  v55 = (int)v54;
  if ( !v54 || *v54 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get sensor num failed");
    V_UNLOCK();
    v137 = 990;
LABEL_133:
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_parse_chain",
      12,
      v137,
      100,
      v190);
    goto LABEL_98;
  }
  V_LOCK();
  v56 = json_integer_value(v55);
  logfmt_raw(v190, 0x1000u, 0, "sensor num : %d", v56);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    993,
    20,
    v190);
  v57 = json_integer_value(v55);
  v58 = dword_186A98;
  *(_DWORD *)(dword_186A98 + 92) = v57;
  v59 = calloc(v57, 0x18u);
  *(_DWORD *)(v58 + 84) = v59;
  if ( !v59 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "calloc sensor failed!");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_alloc_sensor",
      13,
      97,
      100,
      v190);
    goto LABEL_98;
  }
  v60 = (_DWORD *)json_object_get(v28, "max_chip_temp");
  v61 = (int)v60;
  if ( !v60 || *v60 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get max_chip_temp failed");
    V_UNLOCK();
    v137 = 1001;
    goto LABEL_133;
  }
  V_LOCK();
  v62 = json_integer_value(v61);
  logfmt_raw(v190, 0x1000u, 0, "max_chip_temp : %d", v62);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    1004,
    20,
    v190);
  *(_DWORD *)(dword_186A98 + 96) = json_integer_value(v61);
  v63 = (_DWORD *)json_object_get(v28, "max_pcb_temp");
  v64 = (int)v63;
  if ( !v63 || *v63 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get max_pcb_temp failed");
    V_UNLOCK();
    v137 = 1010;
    goto LABEL_133;
  }
  V_LOCK();
  v65 = json_integer_value(v64);
  logfmt_raw(v190, 0x1000u, 0, "max_pcb_temp : %d", v65);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    1013,
    20,
    v190);
  *(_DWORD *)(dword_186A98 + 100) = json_integer_value(v64);
  v66 = (_DWORD *)json_object_get(v28, "min_pcb_temp");
  v67 = (int)v66;
  if ( !v66 || *v66 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get min_pcb_temp failed");
    V_UNLOCK();
    v137 = 1019;
    goto LABEL_133;
  }
  V_LOCK();
  v68 = json_integer_value(v67);
  logfmt_raw(v190, 0x1000u, 0, "min_pcb_temp : %d", v68);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    1022,
    20,
    v190);
  *(_DWORD *)(dword_186A98 + 104) = json_integer_value(v67);
  v69 = (_DWORD *)json_object_get(v28, "max_uneffective_count");
  v70 = (int)v69;
  if ( !v69 || *v69 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get max_uneffective_count failed");
    V_UNLOCK();
    v137 = 1028;
    goto LABEL_133;
  }
  V_LOCK();
  v71 = json_integer_value(v70);
  logfmt_raw(v190, 0x1000u, 0, "max_uneffective_count : %d", v71);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain",
    12,
    1031,
    20,
    v190);
  *(_DWORD *)(dword_186A98 + 108) = json_integer_value(v70);
  v177 = sub_5D254(v28);
  if ( v177 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "parse asic failed");
    V_UNLOCK();
    v138 = 1037;
    goto LABEL_138;
  }
  if ( byte_186A90 && sub_5DA24(v28) )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "parse chain pic failed");
    V_UNLOCK();
    v138 = 1045;
LABEL_138:
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_parse_chain",
      12,
      v138,
      100,
      v190);
    goto LABEL_98;
  }
  v72 = *(_DWORD *)(dword_186A98 + 88);
  if ( v72 == 3 )
  {
    v139 = (_DWORD *)json_object_get(v28, "ctrlboard_sensor");
    v186 = v139;
    if ( !v139 || *v139 != 1 )
    {
      V_LOCK();
      logfmt_raw(v190, 0x1000u, 0, "get ctrlboard_sensor sensor failed");
      V_UNLOCK();
      v176 = 640;
LABEL_185:
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/topol/topol.c",
        153,
        "_parse_chain_ctrlboard_sensor",
        29,
        v176,
        100,
        v190);
      V_LOCK();
      logfmt_raw(v190, 0x1000u, 0, "parse chain ctrlboard failed");
      V_UNLOCK();
      v137 = 1054;
      goto LABEL_133;
    }
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "ctrlboard_sensor:");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_parse_chain_ctrlboard_sensor",
      29,
      643,
      20,
      v190);
    v183 = v1;
    v180 = 0;
    v188 = v28;
    while ( v180 < (unsigned int)json_array_size(v186) )
    {
      v140 = json_array_get(v186, v180);
      v141 = v140;
      if ( !v140 || *v140 )
      {
        v1 = v183;
        V_LOCK();
        logfmt_raw(v190, 0x1000u, 0, "get array %d failed", v180);
        V_UNLOCK();
        v176 = 650;
        goto LABEL_185;
      }
      v142 = (_DWORD *)json_object_get(v140, "index");
      v143 = (int)v142;
      if ( !v142 || *v142 != 3 )
      {
        v1 = v183;
        V_LOCK();
        logfmt_raw(v190, 0x1000u, 0, "get array %d index failed", v180);
        V_UNLOCK();
        v176 = 657;
        goto LABEL_185;
      }
      V_LOCK();
      v144 = json_integer_value(v143);
      logfmt_raw(v190, 0x1000u, 0, "index: %d", v144);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/topol/topol.c",
        153,
        "_parse_chain_ctrlboard_sensor",
        29,
        660,
        20,
        v190);
      v145 = json_integer_value(v143);
      v146 = *(_DWORD *)(dword_186A98 + 84);
      *(_DWORD *)(v146 + 24 * v145) = v145;
      v147 = (_DWORD *)(v146 + 24 * v145);
      v147[2] = 2;
      v148 = (_DWORD *)json_object_get(v141, "type");
      v149 = v148;
      if ( !v148 || *v148 != 2 )
      {
        v1 = v183;
        V_LOCK();
        logfmt_raw(v190, 0x1000u, 0, "get array %d type failed", v180);
        V_UNLOCK();
        v176 = 669;
        goto LABEL_185;
      }
      V_LOCK();
      v150 = json_string_value(v149);
      logfmt_raw(v190, 0x1000u, 0, "type: %s", v150);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/topol/topol.c",
        153,
        "_parse_chain_ctrlboard_sensor",
        29,
        672,
        20,
        v190);
      v151 = (const char *)json_string_value(v149);
      v152 = strcmp(v151, "TMP451");
      if ( v152 )
      {
        if ( !strcmp(v151, "LM75A") )
        {
          v152 = 1;
        }
        else if ( !strcmp(v151, "unknow") )
        {
          v152 = 2;
        }
        else
        {
          v152 = 3;
        }
      }
      v147[1] = v152;
      v153 = (_DWORD *)json_object_get(v141, "iic");
      v154 = (int)v153;
      if ( !v153 || *v153 != 3 )
      {
        v1 = v183;
        V_LOCK();
        logfmt_raw(v190, 0x1000u, 0, "get array %d bind_asic failed", v180);
        V_UNLOCK();
        v176 = 678;
        goto LABEL_185;
      }
      V_LOCK();
      v155 = json_integer_value(v154);
      logfmt_raw(v190, 0x1000u, 0, "iic: %d", v155);
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/topol/topol.c",
        153,
        "_parse_chain_ctrlboard_sensor",
        29,
        681,
        20,
        v190);
      v147[5] = json_integer_value(v154);
      v156 = (_DWORD *)json_object_get(v141, "x");
      v157 = v156;
      if ( !v156 || *v156 != 2 )
      {
        v1 = v183;
        V_LOCK();
        logfmt_raw(v190, 0x1000u, 0, "get array %d x failed", v180);
        V_UNLOCK();
        v176 = 687;
        goto LABEL_185;
      }
      V_LOCK();
      v158 = json_string_value(v157);
      logfmt_raw(v190, 0x1000u, 0, "x: %s", v158);
      V_UNLOCK();
      v159 = 0;
      v160 = off_148828;
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/topol/topol.c",
        153,
        "_parse_chain_ctrlboard_sensor",
        29,
        690,
        20,
        v190);
      v161 = (const char *)json_string_value(v157);
      v162 = "air_in";
      v163 = v161;
      while ( strcmp(v163, v162) )
      {
        v164 = *v160++;
        v162 = v164;
        ++v159;
      }
      v165 = 0;
      v147[3] = v159;
      v166 = (_DWORD *)json_object_get(v141, "y");
      v167 = v166;
      if ( !v166 || *v166 != 2 )
      {
        v1 = v183;
        V_LOCK();
        logfmt_raw(v190, 0x1000u, 0, "get array %d y failed", v180);
        V_UNLOCK();
        v176 = 696;
        goto LABEL_185;
      }
      V_LOCK();
      v168 = json_string_value(v167);
      logfmt_raw(v190, 0x1000u, 0, "y: %s", v168);
      V_UNLOCK();
      v169 = (const char **)&unk_148848;
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/topol/topol.c",
        153,
        "_parse_chain_ctrlboard_sensor",
        29,
        699,
        20,
        v190);
      v170 = (const char *)json_string_value(v167);
      v171 = "top";
      v172 = v170;
      while ( strcmp(v172, v171) )
      {
        v173 = *v169++;
        v171 = v173;
        ++v165;
      }
      v147[4] = v165;
      ++v180;
    }
    v1 = v183;
    v28 = v188;
    v72 = *(_DWORD *)(dword_186A98 + 88);
  }
  if ( (v72 & 0xFFFFFFFD) == 0 )
  {
    v73 = (_DWORD *)json_object_get(v28, "asic_sensor");
    v181 = v73;
    if ( v73 && *v73 == 1 )
    {
      V_LOCK();
      v178 = 0;
      logfmt_raw(v190, 0x1000u, 0, "asic_sensor:");
      V_UNLOCK();
      zlog(
        g_zc,
        "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-"
        "origin_godminer-new/backend/topol/topol.c",
        153,
        "_parse_chain_sensor",
        19,
        802,
        20,
        v190);
      v184 = v1;
      v187 = v28;
      while ( 1 )
      {
        if ( v178 >= (unsigned int)json_array_size(v181) )
        {
          v1 = v184;
          v28 = v187;
          goto LABEL_105;
        }
        v74 = json_array_get(v181, v178);
        v75 = v74;
        if ( !v74 || *v74 )
          break;
        v76 = (_DWORD *)json_object_get(v74, "index");
        v77 = (int)v76;
        if ( !v76 || *v76 != 3 )
        {
          v1 = v184;
          V_LOCK();
          logfmt_raw(v190, 0x1000u, 0, "get array %d index failed", v178);
          V_UNLOCK();
          v175 = 817;
          goto LABEL_177;
        }
        V_LOCK();
        v78 = json_integer_value(v77);
        logfmt_raw(v190, 0x1000u, 0, "index: %d", v78);
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/backend/topol/topol.c",
          153,
          "_parse_chain_sensor",
          19,
          820,
          20,
          v190);
        v79 = json_integer_value(v77);
        v80 = *(_DWORD *)(dword_186A98 + 84);
        *(_DWORD *)(v80 + 24 * v79) = v79;
        v81 = (_DWORD *)(v80 + 24 * v79);
        v81[2] = 1;
        v82 = (_DWORD *)json_object_get(v75, "type");
        v83 = v82;
        if ( !v82 || *v82 != 2 )
        {
          v1 = v184;
          V_LOCK();
          logfmt_raw(v190, 0x1000u, 0, "get array %d type failed", v178);
          V_UNLOCK();
          v175 = 829;
          goto LABEL_177;
        }
        V_LOCK();
        v84 = json_string_value(v83);
        logfmt_raw(v190, 0x1000u, 0, "type: %s", v84);
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/backend/topol/topol.c",
          153,
          "_parse_chain_sensor",
          19,
          832,
          20,
          v190);
        v85 = (const char *)json_string_value(v83);
        v86 = strcmp(v85, "TMP451");
        if ( v86 )
        {
          if ( !strcmp(v85, "LM75A") )
          {
            v86 = 1;
          }
          else if ( !strcmp(v85, "unknow") )
          {
            v86 = 2;
          }
          else
          {
            v86 = 3;
          }
        }
        v81[1] = v86;
        v87 = (_DWORD *)json_object_get(v75, "bind_asic");
        v88 = (int)v87;
        if ( !v87 || *v87 != 3 )
        {
          v1 = v184;
          V_LOCK();
          logfmt_raw(v190, 0x1000u, 0, "get array %d bind_asic failed", v178);
          V_UNLOCK();
          v175 = 838;
          goto LABEL_177;
        }
        V_LOCK();
        v89 = json_integer_value(v88);
        logfmt_raw(v190, 0x1000u, 0, "bind_asic: %d", v89);
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/backend/topol/topol.c",
          153,
          "_parse_chain_sensor",
          19,
          841,
          20,
          v190);
        v81[5] = json_integer_value(v88);
        v90 = (_DWORD *)json_object_get(v75, "x");
        v91 = v90;
        if ( !v90 || *v90 != 2 )
        {
          v1 = v184;
          V_LOCK();
          logfmt_raw(v190, 0x1000u, 0, "get array %d x failed", v178);
          V_UNLOCK();
          v175 = 847;
          goto LABEL_177;
        }
        V_LOCK();
        v92 = json_string_value(v91);
        logfmt_raw(v190, 0x1000u, 0, "x: %s", v92);
        V_UNLOCK();
        v93 = 0;
        v94 = off_148828;
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/backend/topol/topol.c",
          153,
          "_parse_chain_sensor",
          19,
          850,
          20,
          v190);
        v95 = (const char *)json_string_value(v91);
        v96 = "air_in";
        v97 = v95;
        while ( strcmp(v97, v96) )
        {
          v98 = *v94++;
          v96 = v98;
          ++v93;
        }
        v99 = 0;
        v81[3] = v93;
        v100 = (_DWORD *)json_object_get(v75, "y");
        v101 = v100;
        if ( !v100 || *v100 != 2 )
        {
          v1 = v184;
          V_LOCK();
          logfmt_raw(v190, 0x1000u, 0, "get array %d y failed", v178);
          V_UNLOCK();
          v175 = 856;
          goto LABEL_177;
        }
        V_LOCK();
        v102 = json_string_value(v101);
        logfmt_raw(v190, 0x1000u, 0, "y: %s", v102);
        V_UNLOCK();
        v103 = (const char **)&unk_148848;
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/backend/topol/topol.c",
          153,
          "_parse_chain_sensor",
          19,
          859,
          20,
          v190);
        v104 = (const char *)json_string_value(v101);
        v105 = "top";
        v106 = v104;
        while ( strcmp(v106, v105) )
        {
          v107 = *v103++;
          v105 = v107;
          ++v99;
        }
        v81[4] = v99;
        ++v178;
      }
      v1 = v184;
      V_LOCK();
      logfmt_raw(v190, 0x1000u, 0, "get array %d failed", v178);
      V_UNLOCK();
      v175 = 810;
    }
    else
    {
      V_LOCK();
      logfmt_raw(v190, 0x1000u, 0, "get sensor failed");
      V_UNLOCK();
      v175 = 799;
    }
LABEL_177:
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_parse_chain_sensor",
      19,
      v175,
      100,
      v190);
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "parse chain sensor failed");
    V_UNLOCK();
    v137 = 1064;
    goto LABEL_133;
  }
LABEL_105:
  v179 = dword_186A78;
  v112 = (_DWORD *)json_object_get(v28, "eeprom");
  v182 = v112;
  if ( !v112 || (v113 = *v112) != 0 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get eeprom failed");
    V_UNLOCK();
    v174 = 760;
    goto LABEL_172;
  }
  V_LOCK();
  logfmt_raw(v190, 0x1000u, 0, "eeprom:");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain_eeprom",
    19,
    763,
    20,
    v190);
  v114 = (_DWORD *)json_object_get(v182, "type");
  v185 = v114;
  if ( !v114 || *v114 != 2 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get type failed");
    V_UNLOCK();
    v174 = 768;
    goto LABEL_172;
  }
  V_LOCK();
  v115 = json_string_value(v185);
  logfmt_raw(v190, 0x1000u, 0, "type: %s", v115);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain_eeprom",
    19,
    771,
    20,
    v190);
  if ( v179 > 0 )
  {
    v116 = 0;
    do
    {
      v117 = off_148914;
      v118 = 0;
      v119 = (const char *)json_string_value(v185);
      v120 = "AT24C02D";
      while ( strcmp(v119, v120) )
      {
        v121 = v117[1];
        ++v117;
        v120 = v121;
        ++v118;
      }
      ++v113;
      v122 = dword_186A98 + v116;
      v116 += 120;
      *(_DWORD *)(v122 + 112) = v118;
    }
    while ( v179 != v113 );
  }
  v123 = (_DWORD *)json_object_get(v182, "i2c_addr");
  v124 = (int)v123;
  if ( !v123 || *v123 != 3 )
  {
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "get i2c_addr failed");
    V_UNLOCK();
    v174 = 780;
LABEL_172:
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/backend/topol/topol.c",
      153,
      "_parse_chain_eeprom",
      19,
      v174,
      100,
      v190);
    V_LOCK();
    logfmt_raw(v190, 0x1000u, 0, "parse chain eeprom failed");
    V_UNLOCK();
    v137 = 1072;
    goto LABEL_133;
  }
  V_LOCK();
  v125 = json_integer_value(v124);
  logfmt_raw(v190, 0x1000u, 0, "i2c_addr: %d", v125);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/topol/topol.c",
    153,
    "_parse_chain_eeprom",
    19,
    783,
    20,
    v190);
  if ( v179 > 0 )
  {
    v126 = 0;
    v127 = 0;
    do
    {
      ++v126;
      v128 = json_integer_value(v124);
      v129 = dword_186A98 + v127;
      v127 += 120;
      *(_DWORD *)(v129 + 116) = v128;
    }
    while ( v179 != v126 );
  }
  v130 = dword_186A78;
  if ( dword_186A78 > 1 )
  {
    v131 = 120;
    v132 = 1;
    do
    {
      ++v132;
      v133 = (void *)(dword_186A98 + v131);
      v131 += 120;
      memcpy(v133, (const void *)dword_186A98, 0x78u);
    }
    while ( v130 != v132 );
  }
  if ( v1[1] != -1 )
  {
    v134 = v1 + 1;
    __dmb(0xBu);
    do
    {
      v135 = __ldrex(v134);
      v136 = v135 - 1;
    }
    while ( __strex(v136, v134) );
    if ( !v136 )
      json_delete(v1);
  }
  return v177;
}
