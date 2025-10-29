void __fastcall setconfig(io_data *io_data, int c, char *param, bool isjson, char group)
{
  io_data *v6; // r5
  char *v8; // r0
  unsigned int v9; // r0
  int v10; // r7
  char *v11; // r3
  int v12; // r2
  int v13; // r1
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
        v11 = param;
        v12 = v9;
        v13 = 84;
        io_data = v6;
      }
      else
      {
        if ( !strcasecmp(param, "queue") )
        {
          opt_queue = v10;
        }
        else if ( !strcasecmp(param, "scantime") )
        {
          opt_scantime = v10;
        }
        else
        {
          if ( strcasecmp(param, "expiry") )
          {
            groupa = isjson;
            v11 = param;
            v12 = 0;
            io_data = v6;
            v13 = 83;
            goto LABEL_9;
          }
          opt_expiry = v10;
        }
        groupa = isjson;
        v11 = param;
        v12 = v10;
        io_data = v6;
        v13 = 82;
      }
    }
    else
    {
      groupa = isjson;
      v11 = param;
      v12 = 0;
      v13 = 86;
      io_data = v6;
    }
  }
  else
  {
    v11 = 0;
    groupa = isjson;
    v12 = 0;
    v13 = 85;
  }
LABEL_9:
  message(io_data, v13, v12, v11, groupa);
}
