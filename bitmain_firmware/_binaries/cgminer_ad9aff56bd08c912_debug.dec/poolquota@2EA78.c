void __fastcall poolquota(io_data *io_data, int c, char *param, bool isjson, char group)
{
  char *rpc_url; // r3
  io_data *v7; // r7
  char *v9; // r8
  int v10; // r0
  int v11; // r2
  int v12; // r1
  pool *v13; // r5
  int v14; // r0
  int v15; // r4
  bool groupa; // [sp+20h] [bp+20h]

  rpc_url = (char *)total_pools;
  if ( total_pools )
  {
    v7 = io_data;
    if ( param && *param )
    {
      v9 = strchr(param, 44);
      if ( v9 )
      {
        *v9 = 0;
        v10 = strtol(param, 0, 10);
        if ( v10 >= 0 && v10 < total_pools )
        {
          v13 = pools[v10];
          v14 = strtol(v9 + 1, 0, 10);
          v15 = v14;
          if ( v14 < 0 )
          {
            rpc_url = v13->rpc_url;
            v11 = v14;
            groupa = isjson;
            io_data = v7;
            v12 = 121;
          }
          else
          {
            v13->quota = v14;
            adjust_quota_gcd();
            rpc_url = v13->rpc_url;
            v11 = v15;
            groupa = isjson;
            io_data = v7;
            v12 = 122;
          }
        }
        else
        {
          groupa = isjson;
          v11 = v10;
          io_data = v7;
          rpc_url = 0;
          v12 = 26;
        }
      }
      else
      {
        groupa = isjson;
        rpc_url = param;
        v11 = 0;
        v12 = 86;
        io_data = v7;
      }
    }
    else
    {
      rpc_url = 0;
      groupa = isjson;
      v11 = 0;
      v12 = 25;
    }
  }
  else
  {
    groupa = isjson;
    v11 = 0;
    v12 = 8;
  }
  message(io_data, v12, v11, rpc_url, groupa);
}
