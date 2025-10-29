void __fastcall head_join(io_data *io_data, char *cmdptr, bool isjson, bool *firstjoin)
{
  char *v6; // r0
  char *v7; // r1
  char *v8; // r5
  char *v9; // r1

  if ( *firstjoin )
  {
    if ( !isjson )
    {
      *firstjoin = 0;
LABEL_4:
      v6 = escape_string(cmdptr, isjson);
      LOWORD(v7) = 20240;
      v8 = v6;
      HIWORD(v7) = (unsigned int)&freq_pll[73] >> 16;
      io_add(io_data, v7);
      io_add(io_data, v8);
      io_add(io_data, (char *)&word_4F67C);
      goto LABEL_5;
    }
    io_add(io_data, "{");
    *firstjoin = 0;
    v8 = escape_string(cmdptr, 1);
  }
  else
  {
    if ( !isjson )
      goto LABEL_4;
    io_add(io_data, ",");
    v8 = escape_string(cmdptr, 1);
  }
  io_add(io_data, "\"");
  io_add(io_data, v8);
  LOWORD(v9) = 21868;
  HIWORD(v9) = (unsigned int)"n_acn%d" >> 16;
  io_add(io_data, v9);
LABEL_5:
  if ( cmdptr != v8 )
    sub_12000(v8);
}
