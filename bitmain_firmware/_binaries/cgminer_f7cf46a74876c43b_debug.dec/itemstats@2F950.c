// Alternative name is 'itemstats.isra.17'
int __fastcall itemstats(
        io_data *io_data,
        int i,
        char *id,
        cgminer_stats *stats,
        api_data *pool_stats,
        api_data *extra,
        cgpu_info *cgpu,
        bool isjson)
{
  api_data *v11; // r0
  api_data *v12; // r0
  api_data *v13; // r0
  api_data *v14; // r0
  api_data *v15; // r0
  api_data *v16; // r0
  api_data *v17; // r0
  api_data *v18; // r0
  api_data *v19; // r0
  api_data *v20; // r1
  api_data *prev; // r3
  char v22; // r3
  int ia; // [sp+Ch] [bp-Ch] BYREF
  double ghs; // [sp+10h] [bp-8h] BYREF

  ia = i;
  ghs = total_mhashes_done / total_secs;
  v11 = api_add_data_full(0, "STATS", api_data_type::API_INT, &ia, 0);
  v12 = api_add_data_full(v11, "ID", api_data_type::API_STRING, id, 0);
  v13 = api_add_data_full(v12, "Elapsed", api_data_type::API_ELAPSED, &total_secs, 0);
  v14 = api_add_data_full(v13, "Calls", api_data_type::API_UINT32, stats, 0);
  v15 = api_add_data_full(v14, "Wait", api_data_type::API_TIMEVAL, &stats->getwork_wait, 0);
  v16 = api_add_data_full(v15, "Max", api_data_type::API_TIMEVAL, &stats->getwork_wait_max, 0);
  v17 = api_add_data_full(v16, "Min", api_data_type::API_TIMEVAL, &stats->getwork_wait_min, 0);
  v18 = api_add_data_full(v17, "GHS 5s", api_data_type::API_STRING, displayed_hash_rate, 0);
  v19 = api_add_data_full(v18, "GHS av", api_data_type::API_MHS, &ghs, 0);
  v20 = v19;
  if ( pool_stats )
  {
    if ( v19 )
    {
      prev = pool_stats->prev;
      pool_stats->prev = v19->prev;
      v19->prev->next = pool_stats;
      prev->next = v19;
      v19->prev = prev;
    }
    else
    {
      v20 = pool_stats;
    }
  }
  v22 = (char)extra;
  if ( (_BYTE)extra )
    v22 = ia > 0;
  print_data(io_data, v20, (bool)extra, v22);
  return ia + 1;
}
