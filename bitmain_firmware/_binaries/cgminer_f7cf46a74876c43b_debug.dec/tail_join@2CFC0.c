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
    LOWORD(v4) = 20988;
    HIWORD(v4) = (unsigned int)"set_baud" >> 16;
    io_add(io_data, v4);
    j_io_add(io_data, (char *)&word_59A90);
    return;
  }
  io_add(io_data, (char *)&word_59A90);
  io_data->close = 0;
  if ( v3 )
    goto LABEL_5;
}
