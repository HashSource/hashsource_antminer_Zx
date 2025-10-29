void __fastcall dosave(io_data *io_data, int c, char *param, bool isjson, char group)
{
  char *v7; // r4
  FILE *v8; // r0
  FILE *v9; // r6
  char *v10; // r6
  char *v11; // r8
  char filename[4096]; // [sp+8h] [bp-1000h] BYREF

  if ( !param || (v7 = param, !*param) )
  {
    v7 = filename;
    default_save_file(filename);
  }
  v8 = fopen(v7, "w");
  v9 = v8;
  if ( v8 )
  {
    write_config(v8);
    fclose(v9);
    v10 = escape_string(v7, isjson);
    message(io_data, 44, 0, v10, isjson);
    if ( v7 != v10 )
      free(v10);
  }
  else
  {
    v11 = escape_string(v7, isjson);
    message(io_data, 43, 0, v11, isjson);
    if ( v7 != v11 )
      free(v11);
  }
}
