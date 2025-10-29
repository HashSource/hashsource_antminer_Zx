void __fastcall dozero(io_data *io_data, int c, char *param, bool isjson, char group)
{
  io_data *v6; // r5
  char *v8; // r0
  char *v9; // r7
  int v10; // r8
  const char *v11; // r1
  int v12; // r9
  int v13; // r10
  int v14; // r4
  bool v15; // zf
  char *v16; // r2
  const char *v17; // r1
  char *v18; // r3
  int v19; // r1
  bool groupa; // [sp+20h] [bp+20h]

  if ( !param || !*param )
  {
    v18 = 0;
    groupa = isjson;
    v19 = 94;
    goto LABEL_20;
  }
  v6 = io_data;
  v8 = strchr(param, 44);
  v9 = v8;
  if ( !v8 || (*v8 = 0, v8 == (char *)-1) || (v10 = (unsigned __int8)v8[1], !v8[1]) )
  {
    v18 = 0;
    groupa = isjson;
    io_data = v6;
    v19 = 75;
    goto LABEL_20;
  }
  LOWORD(v11) = 21700;
  HIWORD(v11) = (unsigned int)"d" >> 16;
  if ( !strcasecmp(param, v11) )
  {
    v12 = 0;
    v13 = 1;
  }
  else
  {
    LOWORD(v17) = 21704;
    HIWORD(v17) = (unsigned int)"API: unknown2 data type %d ignored" >> 16;
    if ( strcasecmp(param, v17) )
    {
      groupa = isjson;
      v18 = param;
      io_data = v6;
      v19 = 95;
      goto LABEL_20;
    }
    v13 = 0;
    v12 = 1;
  }
  v14 = LOBYTE((*_ctype_tolower_loc())[v10]);
  v15 = v14 == 116;
  if ( v14 != 116 )
    v15 = v14 == 102;
  v9[1] = v14;
  if ( !v15 )
  {
    v18 = 0;
    groupa = isjson;
    io_data = v6;
    v19 = 76;
    goto LABEL_20;
  }
  if ( v14 == 116 )
  {
    print_summary();
    if ( !v13 )
      goto LABEL_14;
    goto LABEL_26;
  }
  if ( v13 )
LABEL_26:
    zero_stats();
LABEL_14:
  if ( v12 )
    zero_bestshare();
  LOWORD(v16) = 21684;
  LOWORD(v18) = 21688;
  HIWORD(v18) = (unsigned int)"" >> 16;
  if ( v13 )
  {
    HIWORD(v16) = (unsigned int)"%.8f" >> 16;
    v18 = v16;
  }
  groupa = isjson;
  io_data = v6;
  if ( v14 == 116 )
    v19 = 96;
  else
    v19 = 97;
LABEL_20:
  message(io_data, v19, 0, v18, groupa);
}
