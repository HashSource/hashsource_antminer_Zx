void __fastcall dosave(io_data *io_data, int c, char *param, bool isjson, char group)
{
  char *v7; // r4
  const char *v8; // r1
  FILE *v9; // r0
  FILE *v10; // r6
  char *v11; // r6
  char *v12; // r8
  char filename[4096]; // [sp+8h] [bp-1000h] BYREF

  if ( !param || (v7 = param, !*param) )
  {
    v7 = filename;
    default_save_file(filename);
  }
  LOWORD(v8) = 5820;
  HIWORD(v8) = (unsigned int)"f" >> 16;
  v9 = fopen(v7, v8);
  v10 = v9;
  if ( v9 )
  {
    write_config(v9);
    fclose(v10);
    v11 = escape_string(v7, isjson);
    message(io_data, 44, 0, v11, isjson);
    if ( v7 != v11 )
      free(v11);
  }
  else
  {
    v12 = escape_string(v7, isjson);
    message(io_data, 43, 0, v12, isjson);
    if ( v7 != v12 )
      free(v12);
  }
}
