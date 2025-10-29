void __fastcall removepool(io_data *io_data, int c, char *param, bool isjson, char group)
{
  char *v6; // r3
  io_data *v7; // r6
  int v8; // r2
  int v9; // r1
  bool v10; // r5
  int v11; // r0
  int v12; // r7
  pool *v13; // r4
  char *v14; // r8
  bool groupa; // [sp+20h] [bp+18h]

  v6 = (char *)total_pools;
  if ( !total_pools )
  {
    groupa = isjson;
    v8 = 0;
    v9 = 8;
    goto LABEL_5;
  }
  v7 = io_data;
  if ( !param || !*param )
  {
    v6 = 0;
    groupa = isjson;
    v8 = 0;
    v9 = 25;
LABEL_5:
    message(io_data, v9, v8, v6, groupa);
    return;
  }
  v10 = isjson;
  v11 = strtol(param, 0, 10);
  v12 = v11;
  if ( v11 < 0 || v11 >= total_pools )
  {
    groupa = v10;
    v8 = v11;
    io_data = v7;
    v6 = 0;
    v9 = 26;
    goto LABEL_5;
  }
  if ( total_pools <= 1 )
  {
    groupa = v10;
    v8 = v11;
    io_data = v7;
    v6 = 0;
    v9 = 66;
    goto LABEL_5;
  }
  v13 = pools[v11];
  if ( v13 == current_pool() )
    switch_pools(0);
  if ( v13 == current_pool() )
  {
    groupa = v10;
    v8 = v12;
    io_data = v7;
    v6 = 0;
    v9 = 67;
    goto LABEL_5;
  }
  v13->enabled = pool_enable::POOL_DISABLED;
  v14 = escape_string(v13->rpc_url, v10);
  if ( v14 == v13->rpc_url )
  {
    remove_pool(v13);
    groupa = v10;
    v6 = v14;
    v8 = v12;
    io_data = v7;
    v9 = 68;
    goto LABEL_5;
  }
  remove_pool(v13);
  message(v7, 68, v12, v14, v10);
  sub_12000(v14);
}
