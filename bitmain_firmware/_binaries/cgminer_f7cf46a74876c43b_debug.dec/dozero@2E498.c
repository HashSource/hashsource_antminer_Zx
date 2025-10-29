void __fastcall dozero(io_data *io_data, int c, char *param, bool isjson, char group)
{
  io_data *v6; // r5
  char *v8; // r0
  char *v9; // r7
  int v10; // r8
  int v11; // r9
  int v12; // r10
  int v13; // r4
  bool v14; // zf
  char *v15; // r3
  int v16; // r1
  bool groupa; // [sp+20h] [bp+20h]

  if ( !param || !*param )
  {
    v15 = 0;
    groupa = isjson;
    v16 = 94;
    goto LABEL_20;
  }
  v6 = io_data;
  v8 = strchr(param, 44);
  v9 = v8;
  if ( !v8 || (*v8 = 0, v8 == (char *)-1) || (v10 = (unsigned __int8)v8[1], !v8[1]) )
  {
    v15 = 0;
    groupa = isjson;
    io_data = v6;
    v16 = 75;
    goto LABEL_20;
  }
  if ( !strcasecmp(param, "all") )
  {
    v11 = 0;
    v12 = 1;
  }
  else
  {
    if ( strcasecmp(param, "bestshare") )
    {
      groupa = isjson;
      v15 = param;
      io_data = v6;
      v16 = 95;
      goto LABEL_20;
    }
    v12 = 0;
    v11 = 1;
  }
  v13 = LOBYTE((*_ctype_tolower_loc())[v10]);
  v14 = v13 == 116;
  if ( v13 != 116 )
    v14 = v13 == 102;
  v9[1] = v13;
  if ( !v14 )
  {
    v15 = 0;
    groupa = isjson;
    io_data = v6;
    v16 = 76;
    goto LABEL_20;
  }
  if ( v13 == 116 )
  {
    print_summary();
    if ( !v12 )
      goto LABEL_14;
    goto LABEL_26;
  }
  if ( v12 )
LABEL_26:
    zero_stats();
LABEL_14:
  if ( v11 )
    zero_bestshare();
  v15 = "BestShare";
  if ( v12 )
    v15 = "All";
  groupa = isjson;
  io_data = v6;
  if ( v13 == 116 )
    v16 = 96;
  else
    v16 = 97;
LABEL_20:
  message(io_data, v16, 0, v15, groupa);
}
