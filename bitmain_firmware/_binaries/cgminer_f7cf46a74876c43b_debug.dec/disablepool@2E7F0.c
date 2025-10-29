void __fastcall disablepool(io_data *io_data, int c, char *param, bool isjson, char group)
{
  io_data *v5; // r6
  int v6; // r2
  int v7; // r1
  int v9; // r0
  int v10; // r7
  pool *v11; // r4
  bool groupa; // [sp+18h] [bp+18h]

  if ( total_pools )
  {
    v5 = io_data;
    if ( param && *param )
    {
      v9 = strtol(param, 0, 10);
      v10 = v9;
      if ( v9 < 0 || v9 >= total_pools )
      {
        groupa = isjson;
        v6 = v9;
        io_data = v5;
        v7 = 26;
      }
      else
      {
        v11 = pools[v9];
        if ( v11->enabled )
        {
          if ( enabled_pools <= 1 )
          {
            groupa = isjson;
            v6 = v9;
            io_data = v5;
            v7 = 51;
          }
          else
          {
            v11->enabled = pool_enable::POOL_DISABLED;
            if ( v11 == current_pool() )
              switch_pools(0);
            groupa = isjson;
            v6 = v10;
            io_data = v5;
            v7 = 48;
          }
        }
        else
        {
          groupa = isjson;
          v6 = v9;
          io_data = v5;
          v7 = 50;
        }
      }
    }
    else
    {
      groupa = isjson;
      v6 = 0;
      v7 = 25;
    }
  }
  else
  {
    groupa = isjson;
    v6 = 0;
    v7 = 8;
  }
  message(io_data, v7, v6, 0, groupa);
}
