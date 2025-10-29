void __fastcall poolstatus(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v6; // r9
  int v7; // r3
  api_data *v8; // r0
  api_data *v9; // r0
  api_data *v10; // r0
  double diff_rejected; // d5
  double v12; // d7
  double v13; // d6
  api_data *v14; // r0
  double diff_stale; // d5
  double v16; // d7
  double v17; // d6
  api_data *v18; // r0
  bool v19; // r3
  pool *v20; // r4
  pool_enable enabled; // r6
  char *v22; // r5
  time_t v23; // r0
  unsigned int v24; // lr
  api_data *v25; // r0
  api_data *v26; // r0
  api_data *v27; // r0
  api_data *v28; // r0
  api_data *v29; // r0
  api_data *v30; // r0
  api_data *v31; // r0
  api_data *v32; // r0
  api_data *v33; // r0
  api_data *v34; // r0
  api_data *v35; // r0
  api_data *v36; // r0
  api_data *v37; // r0
  api_data *v38; // r0
  api_data *v39; // r0
  api_data *v40; // r0
  api_data *v41; // r0
  api_data *v42; // r6
  char *v43; // r0
  api_data *v44; // r0
  api_data *v45; // r0
  api_data *v46; // r0
  api_data *v47; // r0
  api_data *v48; // r0
  api_data *v49; // r0
  api_data *v50; // r0
  api_data *v51; // r0
  api_data *v52; // r0
  char *v53; // r6
  api_data *root; // [sp+Ch] [bp-130h]
  _BOOL4 v56; // [sp+1Ch] [bp-120h]
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
    v56 = 0;
    goto LABEL_6;
  }
  v56 = io_add(io_data, ",\"POOLS\":[");
  i = 0;
  if ( total_pools > 0 )
  {
LABEL_6:
    root = 0;
    v7 = 0;
    do
    {
      v20 = pools[v7];
      if ( !v20->removed )
      {
        enabled = v20->enabled;
        if ( enabled == pool_enable::POOL_ENABLED )
        {
          if ( v20->idle )
            v53 = "Dead";
          else
            v53 = "Alive";
        }
        else if ( enabled )
        {
          if ( enabled == pool_enable::POOL_REJECTING )
            v53 = "Rejecting";
          else
            v53 = "Unknown";
        }
        else
        {
          v53 = "Disabled";
        }
        v22 = "Y";
        if ( !v20->hdr_path )
          v22 = "N";
        if ( v20->last_share_time > 0 )
        {
          v23 = time(0);
          v24 = (v23 - v20->last_share_time) & ~((v23 - v20->last_share_time) >> 31);
          sprintf(lasttime, "%d:%02d:%02d", v24 / 0xE10, v24 % 0xE10 / 0x3C, v24 % 0xE10 % 0x3C);
        }
        else
        {
          strcpy(lasttime, "0");
        }
        v25 = api_add_data_full(root, "POOL", api_data_type::API_INT, &i, 0);
        v26 = api_add_data_full(v25, "URL", api_data_type::API_ESCAPE, v20->rpc_url, 0);
        v27 = api_add_data_full(v26, "Status", api_data_type::API_STRING, v53, 0);
        v28 = api_add_data_full(v27, "Priority", api_data_type::API_INT, &v20->prio, 0);
        v29 = api_add_data_full(v28, "Quota", api_data_type::API_INT, &v20->quota, 0);
        v30 = api_add_data_full(v29, "Long Poll", api_data_type::API_STRING, v22, 0);
        v31 = api_add_data_full(v30, "Getworks", api_data_type::API_UINT, &v20->getwork_requested, 0);
        v32 = api_add_data_full(v31, "Accepted", api_data_type::API_INT64, &v20->accepted, 0);
        v33 = api_add_data_full(v32, "Rejected", api_data_type::API_INT64, &v20->rejected, 0);
        v34 = api_add_data_full(v33, "Discarded", api_data_type::API_UINT, &v20->discarded_work, 0);
        v35 = api_add_data_full(v34, "Stale", api_data_type::API_UINT, &v20->stale_shares, 0);
        v36 = api_add_data_full(v35, "Get Failures", api_data_type::API_UINT, &v20->getfail_occasions, 0);
        v37 = api_add_data_full(v36, "Remote Failures", api_data_type::API_UINT, &v20->remotefail_occasions, 0);
        v38 = api_add_data_full(v37, "User", api_data_type::API_ESCAPE, v20->rpc_user, 0);
        v39 = api_add_data_full(v38, "Last Share Time", api_data_type::API_STRING, lasttime, 0);
        v40 = api_add_data_full(v39, "Diff", api_data_type::API_STRING, v20->diff, 0);
        v41 = api_add_data_full(v40, "Diff1 Shares", api_data_type::API_INT64, &v20->diff1, 0);
        v42 = v41;
        if ( v20->rpc_proxy )
        {
          v43 = (char *)proxytype(v20->rpc_proxytype);
          v44 = api_add_data_full(v42, "Proxy Type", api_data_type::API_CONST, v43, 0);
          v45 = api_add_data_full(v44, "Proxy", api_data_type::API_ESCAPE, v20->rpc_proxy, 0);
        }
        else
        {
          v52 = api_add_data_full(v41, "Proxy Type", api_data_type::API_CONST, &byte_59398, 0);
          v45 = api_add_data_full(v52, "Proxy", api_data_type::API_CONST, &byte_59398, 0);
        }
        v46 = api_add_data_full(v45, "Difficulty Accepted", api_data_type::API_DIFF, &v20->diff_accepted, 0);
        v47 = api_add_data_full(v46, "Difficulty Rejected", api_data_type::API_DIFF, &v20->diff_rejected, 0);
        v48 = api_add_data_full(v47, "Difficulty Stale", api_data_type::API_DIFF, &v20->diff_stale, 0);
        v49 = api_add_data_full(v48, "Last Share Difficulty", api_data_type::API_DIFF, &v20->last_share_diff, 0);
        v50 = api_add_data_full(v49, "Has Stratum", api_data_type::API_BOOL, &v20->has_stratum, 0);
        v51 = api_add_data_full(v50, "Stratum Active", api_data_type::API_BOOL, &v20->stratum_active, 0);
        if ( v20->stratum_active )
          v8 = api_add_data_full(v51, "Stratum URL", api_data_type::API_ESCAPE, v20->stratum_url, 0);
        else
          v8 = api_add_data_full(v51, "Stratum URL", api_data_type::API_CONST, &byte_59398, v20->stratum_active);
        v9 = api_add_data_full(v8, "Has GBT", api_data_type::API_BOOL, &v20->has_gbt, 0);
        v10 = api_add_data_full(v9, "Best Share", api_data_type::API_UINT64, &v20->best_diff, 1);
        diff_rejected = v20->diff_rejected;
        v12 = diff_rejected + v20->diff_accepted + v20->diff_stale;
        if ( v12 == 0.0 )
          v13 = 0.0;
        else
          v13 = diff_rejected / v12;
        rejp = v13;
        v14 = api_add_data_full(v10, "Pool Rejected%", api_data_type::API_PERCENT, &rejp, 0);
        diff_stale = v20->diff_stale;
        v16 = v20->diff_accepted + v20->diff_rejected + diff_stale;
        if ( v16 == 0.0 )
          v17 = 0.0;
        else
          v17 = diff_stale / v16;
        stalep = v17;
        v18 = api_add_data_full(v14, "Pool Stale%", api_data_type::API_PERCENT, &stalep, 0);
        v19 = v6 && i > 0;
        root = print_data(io_data, v18, v6, v19);
      }
      v7 = ++i;
    }
    while ( i < total_pools );
  }
  if ( v56 )
    io_data->close = 1;
}
