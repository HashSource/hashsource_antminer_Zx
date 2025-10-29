void __fastcall tail_join(io_data *io_data, bool isjson)
{
  _BOOL4 v3; // r5
  char *v4; // r1

  v3 = isjson;
  if ( !io_data->close )
  {
    if ( !isjson )
      return;
LABEL_5:
    LOWORD(v4) = 21116;
    HIWORD(v4) = (unsigned int)&freq_pll[112].fildiv1 >> 16;
    io_add(io_data, v4);
    io_add(io_data, (char *)&word_59B0C);
    return;
  }
  io_add(io_data, (char *)&word_59B0C);
  io_data->close = 0;
  if ( v3 )
    goto LABEL_5;
}
