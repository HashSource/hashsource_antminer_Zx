void __fastcall failoveronly(io_data *io_data, int c, char *param, bool isjson, char group)
{
  int v6; // r6
  io_data *v8; // r5
  int v9; // r2
  bool v10; // zf
  int v11; // r3
  _BOOL4 v12; // r2
  int v13; // r1
  bool groupa; // [sp+18h] [bp+18h]

  if ( param && *param )
  {
    v8 = io_data;
    v6 = (unsigned __int8)*param;
    v9 = LOBYTE((*_ctype_tolower_loc())[v6]);
    v10 = v9 == 116;
    if ( v9 != 116 )
      v10 = v9 == 102;
    *param = v9;
    v11 = !v10;
    if ( v10 )
    {
      groupa = isjson;
      io_data = v8;
      v12 = v9 == 116;
      opt_fail_only = v12;
      v13 = 77;
    }
    else
    {
      v11 = 0;
      groupa = isjson;
      io_data = v8;
      v12 = 0;
      v13 = 76;
    }
  }
  else
  {
    v11 = 0;
    groupa = isjson;
    v12 = 0;
    v13 = 75;
  }
  message(io_data, v13, v12, (char *)v11, groupa);
}
