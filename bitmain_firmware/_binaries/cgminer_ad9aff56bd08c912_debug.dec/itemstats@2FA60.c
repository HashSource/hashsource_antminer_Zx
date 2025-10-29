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
  char *v9; // r1
  api_data *v12; // r0
  char *v13; // r1
  api_data *v14; // r0
  char *v15; // r1
  api_data *v16; // r0
  char *v17; // r1
  api_data *v18; // r0
  char *v19; // r1
  api_data *v20; // r0
  char *v21; // r1
  api_data *v22; // r0
  char *v23; // r1
  api_data *v24; // r0
  char *v25; // r1
  api_data *v26; // r0
  char *v27; // r1
  api_data *v28; // r0
  api_data *v29; // r1
  api_data *prev; // r3
  char v31; // r3
  int ia; // [sp+Ch] [bp-Ch] BYREF
  double ghs; // [sp+10h] [bp-8h] BYREF

  ia = i;
  LOWORD(v9) = 22280;
  HIWORD(v9) = (unsigned int)"RSION\":[" >> 16;
  ghs = total_mhashes_done / total_secs;
  v12 = api_add_data_full(0, v9, api_data_type::API_INT, &ia, 0);
  LOWORD(v13) = 21924;
  HIWORD(v13) = (unsigned int)"RPCProto" >> 16;
  v14 = api_add_data_full(v12, v13, api_data_type::API_STRING, id, 0);
  LOWORD(v15) = 22288;
  HIWORD(v15) = (unsigned int)"" >> 16;
  v16 = api_add_data_full(v14, v15, api_data_type::API_ELAPSED, &total_secs, 0);
  LOWORD(v17) = 22296;
  HIWORD(v17) = (unsigned int)"ner" >> 16;
  v18 = api_add_data_full(v16, v17, api_data_type::API_UINT32, stats, 0);
  LOWORD(v19) = 22304;
  HIWORD(v19) = (unsigned int)"Miner" >> 16;
  v20 = api_add_data_full(v18, v19, api_data_type::API_TIMEVAL, &stats->getwork_wait, 0);
  LOWORD(v21) = 22312;
  HIWORD(v21) = (unsigned int)"CompileTime" >> 16;
  v22 = api_add_data_full(v20, v21, api_data_type::API_TIMEVAL, &stats->getwork_wait_max, 0);
  LOWORD(v23) = 22316;
  HIWORD(v23) = (unsigned int)"ileTime" >> 16;
  v24 = api_add_data_full(v22, v23, api_data_type::API_TIMEVAL, &stats->getwork_wait_min, 0);
  LOWORD(v25) = 22320;
  HIWORD(v25) = (unsigned int)"ime" >> 16;
  v26 = api_add_data_full(v24, v25, api_data_type::API_STRING, displayed_hash_rate, 0);
  LOWORD(v27) = 22328;
  HIWORD(v27) = (unsigned int)"" >> 16;
  v28 = api_add_data_full(v26, v27, api_data_type::API_MHS, &ghs, 0);
  v29 = v28;
  if ( pool_stats )
  {
    if ( v28 )
    {
      prev = pool_stats->prev;
      pool_stats->prev = v28->prev;
      v28->prev->next = pool_stats;
      prev->next = v28;
      v28->prev = prev;
    }
    else
    {
      v29 = pool_stats;
    }
  }
  v31 = (char)extra;
  if ( (_BYTE)extra )
    v31 = ia > 0;
  print_data(io_data, v29, (bool)extra, v31);
  return ia + 1;
}
