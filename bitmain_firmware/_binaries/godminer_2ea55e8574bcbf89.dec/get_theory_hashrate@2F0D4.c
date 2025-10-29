int get_theory_hashrate()
{
  double v0; // d0
  int v1; // r4
  char *all_created_runtime; // r5
  double v3; // d8
  double v4; // d9
  int v5; // r6
  char *v6; // r5
  int v7; // t1
  bool v8; // cc
  int v9; // r0
  int v11; // [sp+4h] [bp-2Ch]
  int v12; // [sp+Ch] [bp-24h] BYREF
  double v13[2]; // [sp+10h] [bp-20h] BYREF
  char v14[12]; // [sp+24h] [bp-Ch] BYREF

  v1 = 0;
  v12 = 0;
  all_created_runtime = (char *)get_all_created_runtime(&v12);
  v3 = 0.0;
  get_miner_elapsed_time();
  v4 = v0;
  v13[0] = 0.0;
  if ( v12 > 0 )
  {
    v6 = all_created_runtime - 4;
    v5 = 0;
    do
    {
      v7 = *((_DWORD *)v6 + 1);
      v6 += 4;
      ++v1;
      v5 |= (*(int (**)(void))(v7 + 132))();
      v3 = v3 + v13[1];
    }
    while ( v12 > v1 );
  }
  else
  {
    v5 = 0;
  }
  v8 = (unsigned int)opt_algo > 0xA;
  if ( opt_algo != 10 )
    v8 = (unsigned int)(opt_algo - 6) > 1;
  if ( !v8 )
    v4 = v0 - 2700.0;
  if ( v4 < 1.0 )
  {
    freq_scan_status = 0;
    return (int)v13[0];
  }
  else
  {
    v9 = frontend_runtime_instance();
    format_hashrate_double(*(const char **)(*(_DWORD *)(v9 + 72) + 16), v13, v14);
    if ( v5 )
    {
      freq_scan_status = 2;
      strcpy((char *)search_failed_info, "R:1");
      return v11;
    }
    else
    {
      freq_scan_status = 1;
      return (int)v13[0];
    }
  }
}
