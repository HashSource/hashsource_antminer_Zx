// positive sp value has been detected, the output may be wrong!
void __fastcall sub_28870(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        char *format,
        int a10,
        int a11,
        void *a12,
        int a13)
{
  _DWORD *v13; // r4
  int v14; // r5
  int v15; // r8
  int v16; // r6
  int v17; // t1
  char *v18; // r0
  int v19; // r10
  _DWORD *v20; // r6
  int v21; // r8
  unsigned __int64 v22; // kr00_8
  int v23; // t1
  unsigned int v24; // r7
  unsigned int v25; // r11
  _QWORD *v26; // r0
  __int64 v27; // r0
  _QWORD *v28; // r0
  char *v29; // r7
  int v30; // r6
  char *v31; // r9
  char *v32; // r8
  char *v33; // r5
  int v34; // t1
  double *v35; // r0
  int v36; // r6
  int v37; // t1
  char *v38; // r0
  char *v39; // r10
  _DWORD *v40; // r7
  int v41; // r5
  int v42; // t1
  int v43; // r0
  _QWORD *v44; // r0
  char *v45; // r0
  char *v46; // r0
  _QWORD *v47; // r0
  _DWORD *v48; // [sp-1260h] [bp-1260h]
  int v49; // [sp-125Ch] [bp-125Ch]
  char *v50; // [sp-1250h] [bp-1250h]
  _DWORD *v51; // [sp-124Ch] [bp-124Ch]
  int v52; // [sp-1248h] [bp-1248h]
  _DWORD *v53; // [sp-1244h] [bp-1244h]
  _DWORD *v54; // [sp-1240h] [bp-1240h]
  int v55; // [sp-122Ch] [bp-122Ch]
  char v56[160]; // [sp-11F4h] [bp-11F4h] BYREF
  char v57[32]; // [sp-1154h] [bp-1154h] BYREF
  char v58[4404]; // [sp-1134h] [bp-1134h] BYREF

  v16 = 0;
  do
  {
    v17 = *(_DWORD *)(v15 + 4);
    v15 += 4;
    ++v16;
    v14 += 216;
    sprintf(v57, "chain_acs%d", v17);
    memset(v56, 0, 0x20u);
    memset(v58, 0, 0x100u);
    snprintf(v56, 0x20u, "chain_acs%d", v17);
    snprintf(v58, 0x100u, "%s", *(const char **)(v14 - 148));
    v18 = (char *)BUFX_strdup(v58);
    json_object_set_new(v13, v56, v18);
  }
  while ( v55 > v16 );
  if ( v55 <= 0 )
  {
    v22 = 0;
  }
  else
  {
    v19 = v49;
    v20 = v48;
    v21 = 0;
    v22 = 0;
    do
    {
      ++v21;
      memset(v56, 0, 0x20u);
      v23 = *(_DWORD *)(v19 + 4);
      v19 += 4;
      snprintf(v56, 0x20u, "chain_hw%d", v23);
      v24 = v20[20];
      v20 += 54;
      v25 = *(v20 - 33);
      v26 = json_integer(__SPAIR64__(v25, v24));
      json_object_set_new(v13, v56, v26);
      v22 += __PAIR64__(v25, v24);
    }
    while ( v55 > v21 );
  }
  v27 = v22;
  if ( *v54 == 9 )
    LODWORD(v27) = sub_12E4C4(v22, 0x3E8u);
  v28 = json_integer(v27);
  json_object_set_new(v13, "no_matching_work", v28);
  if ( v55 > 0 )
  {
    v29 = (char *)v48;
    v30 = 0;
    v31 = v50 - 4;
    v32 = v50 - 4;
    v33 = (char *)v48;
    do
    {
      ++v30;
      memset(v56, 0, 0x20u);
      v34 = *((_DWORD *)v31 + 1);
      v31 += 4;
      snprintf(v56, 0x20u, "chain_rate%d", v34);
      v29 += 216;
      v35 = json_real();
      json_object_set_new(v13, v56, v35);
    }
    while ( v55 > v30 );
    v36 = 0;
    do
    {
      ++v36;
      v33 += 216;
      format_hashrate_string(*(const char **)(*(_DWORD *)(v52 + 72) + 16), v57);
      v37 = *((_DWORD *)v32 + 1);
      v32 += 4;
      snprintf(v56, 0x20u, "CHAIN AVG HASHRATE%d", v37);
      v38 = (char *)BUFX_strdup(v57);
      json_object_set_new(v13, v56, v38);
    }
    while ( v55 > v36 );
    v39 = v50 - 4;
    v40 = v48;
    v41 = 0;
    do
    {
      ++v41;
      memset(v56, 0, 0x20u);
      v42 = *((_DWORD *)v39 + 1);
      v39 += 4;
      snprintf(v56, 0x20u, "freq%d", v42);
      v43 = v40[18];
      v40 += 54;
      v44 = json_integer(v43);
      json_object_set_new(v13, v56, v44);
    }
    while ( v55 > v41 );
  }
  v45 = (char *)BUFX_strdup(g_miner_version);
  json_object_set_new(v13, "miner_version", v45);
  v46 = (char *)BUFX_strdup(0);
  json_object_set_new(v13, "miner_id", v46);
  json_array_append_new(v53, v13);
  json_object_set_new(v51, "STATS", v53);
  v47 = json_integer(1);
  json_object_set_new(v51, "id", v47);
  if ( v55 > 0 )
  {
    free(v50);
    free(v48);
  }
  __asm { POP             {R4-R11,PC} }
}
