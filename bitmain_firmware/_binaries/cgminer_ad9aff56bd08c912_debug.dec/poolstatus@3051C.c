void __fastcall poolstatus(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v6; // r9
  void *v7; // r1
  int v8; // r3
  char *v9; // r1
  api_data *v10; // r0
  char *v11; // r1
  api_data *v12; // r0
  char *v13; // r1
  api_data *v14; // r0
  double diff_rejected; // d5
  double v16; // d7
  double v17; // d6
  char *v18; // r1
  api_data *v19; // r0
  double diff_stale; // d5
  double v21; // d7
  double v22; // d6
  char *v23; // r1
  api_data *v24; // r0
  bool v25; // r3
  pool *v26; // r4
  pool_enable enabled; // r6
  char *v28; // r7
  char *v29; // r2
  void *v30; // r5
  time_t v31; // r0
  unsigned int v32; // lr
  api_data *v33; // r0
  char *v34; // r1
  api_data *v35; // r0
  char *v36; // r1
  api_data *v37; // r0
  char *v38; // r1
  api_data *v39; // r0
  char *v40; // r1
  api_data *v41; // r0
  char *v42; // r1
  api_data *v43; // r0
  char *v44; // r1
  api_data *v45; // r0
  char *v46; // r1
  api_data *v47; // r0
  char *v48; // r1
  api_data *v49; // r0
  char *v50; // r1
  api_data *v51; // r0
  char *v52; // r1
  api_data *v53; // r0
  char *v54; // r1
  api_data *v55; // r0
  char *v56; // r1
  api_data *v57; // r0
  char *v58; // r1
  api_data *v59; // r0
  char *v60; // r1
  api_data *v61; // r0
  char *v62; // r1
  api_data *v63; // r0
  char *v64; // r1
  api_data *v65; // r0
  api_data *v66; // r6
  char *v67; // r0
  char *v68; // r1
  api_data *v69; // r0
  char *v70; // r1
  api_data *v71; // r0
  api_data *v72; // r0
  char *v73; // r1
  api_data *v74; // r0
  char *v75; // r1
  api_data *v76; // r0
  char *v77; // r1
  api_data *v78; // r0
  char *v79; // r1
  api_data *v80; // r0
  char *v81; // r1
  api_data *v82; // r0
  void *v83; // r3
  char *v84; // r1
  char *v85; // r1
  void *v86; // r3
  char *v87; // r1
  api_data *v88; // r0
  void *v89; // r3
  char *v90; // r1
  char *v91; // r6
  char *v92; // r7
  char *v93; // r3
  api_data *root; // [sp+Ch] [bp-130h]
  void *v96; // [sp+14h] [bp-128h]
  _BOOL4 v97; // [sp+1Ch] [bp-120h]
  int i; // [sp+24h] [bp-118h] BYREF
  double rejp; // [sp+28h] [bp-114h] BYREF
  double stalep; // [sp+30h] [bp-10Ch] BYREF
  char lasttime[260]; // [sp+38h] [bp-104h] BYREF

  v6 = isjson;
  memset(lasttime, 0, 0x100u);
  if ( !total_pools )
  {
    message(io_data, 8, 0, 0, v6);
    return;
  }
  message(io_data, 7, 0, 0, v6);
  if ( !v6 )
  {
    i = 0;
    if ( total_pools <= 0 )
      return;
    v97 = 0;
    goto LABEL_6;
  }
  LOWORD(v85) = 22220;
  HIWORD(v85) = (unsigned int)"over-Only" >> 16;
  v97 = io_add(io_data, v85);
  i = 0;
  if ( total_pools > 0 )
  {
LABEL_6:
    LOWORD(v7) = 21848;
    HIWORD(v7) = (unsigned int)"" >> 16;
    root = 0;
    v8 = 0;
    v96 = v7;
    do
    {
      v26 = pools[v8];
      if ( !v26->removed )
      {
        enabled = v26->enabled;
        if ( enabled == pool_enable::POOL_ENABLED )
        {
          LOWORD(v92) = 22848;
          LOWORD(v93) = 22856;
          if ( v26->idle )
          {
            HIWORD(v93) = (unsigned int)" Share" >> 16;
            v91 = v93;
          }
          else
          {
            HIWORD(v92) = (unsigned int)"" >> 16;
            v91 = v92;
          }
        }
        else if ( enabled )
        {
          LOWORD(v28) = 22836;
          LOWORD(v29) = 21616;
          if ( enabled == pool_enable::POOL_REJECTING )
          {
            HIWORD(v28) = (unsigned int)"iculty Stale" >> 16;
            v91 = v28;
          }
          else
          {
            HIWORD(v29) = (unsigned int)"cgminer" >> 16;
            v91 = v29;
          }
        }
        else
        {
          v91 = "Disabled";
        }
        LOWORD(v30) = 21844;
        HIWORD(v30) = (unsigned int)"time" >> 16;
        if ( !v26->hdr_path )
          v30 = v96;
        if ( v26->last_share_time > 0 )
        {
          v31 = time(0);
          v32 = (v31 - v26->last_share_time) & ~((v31 - v26->last_share_time) >> 31);
          sprintf(lasttime, "%d:%02d:%02d", v32 / 0xE10, v32 % 0xE10 / 0x3C, v32 % 0xE10 % 0x3C);
        }
        else
        {
          strcpy(lasttime, "0");
        }
        v33 = api_add_data_full(root, "POOL", api_data_type::API_INT, &i, 0);
        LOWORD(v34) = 23056;
        HIWORD(v34) = (unsigned int)"" >> 16;
        v35 = api_add_data_full(v33, v34, api_data_type::API_ESCAPE, v26->rpc_url, 0);
        LOWORD(v36) = 22888;
        HIWORD(v36) = (unsigned int)"ce Rejected%" >> 16;
        v37 = api_add_data_full(v35, v36, api_data_type::API_STRING, v91, 0);
        LOWORD(v38) = 22896;
        HIWORD(v38) = (unsigned int)"ted%" >> 16;
        v39 = api_add_data_full(v37, v38, api_data_type::API_INT, &v26->prio, 0);
        LOWORD(v40) = 22908;
        HIWORD(v40) = (unsigned int)" Rejected%" >> 16;
        v41 = api_add_data_full(v39, v40, api_data_type::API_INT, &v26->quota, 0);
        LOWORD(v42) = 22916;
        HIWORD(v42) = (unsigned int)"d%" >> 16;
        v43 = api_add_data_full(v41, v42, api_data_type::API_STRING, v30, 0);
        LOWORD(v44) = 22512;
        HIWORD(v44) = (unsigned int)" Method" >> 16;
        v45 = api_add_data_full(v43, v44, api_data_type::API_UINT, &v26->getwork_requested, 0);
        LOWORD(v46) = 20400;
        HIWORD(v46) = (unsigned int)&_func___12699.__data.__nusers >> 16;
        v47 = api_add_data_full(v45, v46, api_data_type::API_INT64, &v26->accepted, 0);
        LOWORD(v48) = 22524;
        HIWORD(v48) = (unsigned int)"ent Block Time" >> 16;
        v49 = api_add_data_full(v47, v48, api_data_type::API_INT64, &v26->rejected, 0);
        LOWORD(v50) = 22560;
        HIWORD(v50) = (unsigned int)"LP" >> 16;
        v51 = api_add_data_full(v49, v50, api_data_type::API_UINT, &v26->discarded_work, 0);
        LOWORD(v52) = 22572;
        HIWORD(v52) = (unsigned int)"Difficulty" >> 16;
        v53 = api_add_data_full(v51, v52, api_data_type::API_UINT, &v26->stale_shares, 0);
        LOWORD(v54) = 22580;
        HIWORD(v54) = (unsigned int)"ty" >> 16;
        v55 = api_add_data_full(v53, v54, api_data_type::API_UINT, &v26->getfail_occasions, 0);
        LOWORD(v56) = 22608;
        HIWORD(v56) = (unsigned int)"" >> 16;
        v57 = api_add_data_full(v55, v56, api_data_type::API_UINT, &v26->remotefail_occasions, 0);
        LOWORD(v58) = 22928;
        HIWORD(v58) = (unsigned int)"le%" >> 16;
        v59 = api_add_data_full(v57, v58, api_data_type::API_ESCAPE, v26->rpc_user, 0);
        LOWORD(v60) = 22936;
        HIWORD(v60) = (unsigned int)" getwork" >> 16;
        v61 = api_add_data_full(v59, v60, api_data_type::API_STRING, lasttime, 0);
        LOWORD(v62) = 22952;
        HIWORD(v62) = (unsigned int)"bled" >> 16;
        v63 = api_add_data_full(v61, v62, api_data_type::API_STRING, v26->diff, 0);
        LOWORD(v64) = 22960;
        HIWORD(v64) = (unsigned int)"Rejecting" >> 16;
        v65 = api_add_data_full(v63, v64, api_data_type::API_INT64, &v26->diff1, 0);
        v66 = v65;
        if ( v26->rpc_proxy )
        {
          v67 = (char *)proxytype(v26->rpc_proxytype);
          LOWORD(v68) = 22976;
          HIWORD(v68) = (unsigned int)"e" >> 16;
          v69 = api_add_data_full(v66, v68, api_data_type::API_CONST, v67, 0);
          LOWORD(v70) = 22988;
          HIWORD(v70) = (unsigned int)"%d:%02d:%02d" >> 16;
          v71 = api_add_data_full(v69, v70, api_data_type::API_ESCAPE, v26->rpc_proxy, 0);
        }
        else
        {
          LOWORD(v86) = -27628;
          LOWORD(v87) = 22976;
          HIWORD(v86) = (unsigned int)"c.txt" >> 16;
          HIWORD(v87) = (unsigned int)"e" >> 16;
          v88 = api_add_data_full(v65, v87, api_data_type::API_CONST, v86, 0);
          LOWORD(v89) = -27628;
          LOWORD(v90) = 22988;
          HIWORD(v89) = (unsigned int)"c.txt" >> 16;
          HIWORD(v90) = (unsigned int)"%d:%02d:%02d" >> 16;
          v71 = api_add_data_full(v88, v90, api_data_type::API_CONST, v89, 0);
        }
        v72 = api_add_data_full(v71, "Difficulty Accepted", api_data_type::API_DIFF, &v26->diff_accepted, 0);
        LOWORD(v73) = 22688;
        HIWORD(v73) = (unsigned int)"arded" >> 16;
        v74 = api_add_data_full(v72, v73, api_data_type::API_DIFF, &v26->diff_rejected, 0);
        LOWORD(v75) = 22708;
        HIWORD(v75) = (unsigned int)"Failures" >> 16;
        v76 = api_add_data_full(v74, v75, api_data_type::API_DIFF, &v26->diff_stale, 0);
        LOWORD(v77) = 22996;
        HIWORD(v77) = (unsigned int)"%02d" >> 16;
        v78 = api_add_data_full(v76, v77, api_data_type::API_DIFF, &v26->last_share_diff, 0);
        LOWORD(v79) = 23020;
        HIWORD(v79) = (unsigned int)"Priority" >> 16;
        v80 = api_add_data_full(v78, v79, api_data_type::API_BOOL, &v26->has_stratum, 0);
        LOWORD(v81) = 23032;
        HIWORD(v81) = (unsigned int)"Quota" >> 16;
        v82 = api_add_data_full(v80, v81, api_data_type::API_BOOL, &v26->stratum_active, 0);
        if ( v26->stratum_active )
        {
          LOWORD(v9) = 23048;
          HIWORD(v9) = (unsigned int)"l" >> 16;
          v10 = api_add_data_full(v82, v9, api_data_type::API_ESCAPE, v26->stratum_url, 0);
        }
        else
        {
          LOWORD(v83) = -27628;
          LOWORD(v84) = 23048;
          HIWORD(v83) = (unsigned int)"c.txt" >> 16;
          HIWORD(v84) = (unsigned int)"l" >> 16;
          v10 = api_add_data_full(v82, v84, api_data_type::API_CONST, v83, v26->stratum_active);
        }
        LOWORD(v11) = 23060;
        HIWORD(v11) = (unsigned int)"Last Share Time" >> 16;
        v12 = api_add_data_full(v10, v11, api_data_type::API_BOOL, &v26->has_gbt, 0);
        LOWORD(v13) = 22728;
        HIWORD(v13) = (unsigned int)"rk" >> 16;
        v14 = api_add_data_full(v12, v13, api_data_type::API_UINT64, &v26->best_diff, 1);
        diff_rejected = v26->diff_rejected;
        v16 = diff_rejected + v26->diff_accepted + v26->diff_stale;
        if ( v16 == 0.0 )
          v17 = 0.0;
        else
          v17 = diff_rejected / v16;
        LOWORD(v18) = 22780;
        HIWORD(v18) = (unsigned int)" Utility" >> 16;
        rejp = v17;
        v19 = api_add_data_full(v14, v18, api_data_type::API_PERCENT, &rejp, 0);
        diff_stale = v26->diff_stale;
        v21 = v26->diff_accepted + v26->diff_rejected + diff_stale;
        if ( v21 == 0.0 )
          v22 = 0.0;
        else
          v22 = diff_stale / v21;
        LOWORD(v23) = 22796;
        HIWORD(v23) = (unsigned int)"iculty Accepted" >> 16;
        stalep = v22;
        v24 = api_add_data_full(v19, v23, api_data_type::API_PERCENT, &stalep, 0);
        v25 = v6 && i > 0;
        root = print_data(io_data, v24, v6, v25);
      }
      v8 = ++i;
    }
    while ( i < total_pools );
  }
  if ( v97 )
    io_data->close = 1;
}
