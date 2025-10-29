void __fastcall setconfig(io_data *io_data, int c, char *param, bool isjson, char group)
{
  io_data *v6; // r5
  char *v8; // r0
  unsigned int v9; // r0
  int v10; // r7
  const char *v11; // r1
  const char *v12; // r1
  char *v13; // r3
  int v14; // r2
  int v15; // r1
  const char *v16; // r1
  bool groupa; // [sp+18h] [bp+18h]

  if ( param && *param )
  {
    v6 = io_data;
    v8 = strchr(param, 44);
    if ( v8 )
    {
      *v8 = 0;
      v9 = strtol(v8 + 1, 0, 10);
      v10 = v9;
      if ( v9 > 0x270F )
      {
        groupa = isjson;
        v13 = param;
        v14 = v9;
        v15 = 84;
        io_data = v6;
      }
      else
      {
        LOWORD(v11) = 4780;
        HIWORD(v11) = (unsigned int)"discard" >> 16;
        if ( !strcasecmp(param, v11) )
        {
          opt_queue = v10;
        }
        else
        {
          LOWORD(v12) = 21716;
          HIWORD(v12) = (unsigned int)"2 data type %d ignored" >> 16;
          if ( !strcasecmp(param, v12) )
          {
            opt_scantime = v10;
          }
          else
          {
            LOWORD(v16) = 21728;
            HIWORD(v16) = (unsigned int)"%d ignored" >> 16;
            if ( strcasecmp(param, v16) )
            {
              groupa = isjson;
              v13 = param;
              v14 = 0;
              io_data = v6;
              v15 = 83;
              goto LABEL_9;
            }
            opt_expiry = v10;
          }
        }
        groupa = isjson;
        v13 = param;
        v14 = v10;
        io_data = v6;
        v15 = 82;
      }
    }
    else
    {
      groupa = isjson;
      v13 = param;
      v14 = 0;
      v15 = 86;
      io_data = v6;
    }
  }
  else
  {
    v13 = 0;
    groupa = isjson;
    v14 = 0;
    v15 = 85;
  }
LABEL_9:
  message(io_data, v15, v14, v13, groupa);
}
