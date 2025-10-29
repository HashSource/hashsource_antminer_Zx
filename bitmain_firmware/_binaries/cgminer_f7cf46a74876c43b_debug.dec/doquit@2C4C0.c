void __fastcall doquit(io_data *io_data, int c, char *param, bool isjson, char group)
{
  char *ptr; // r4
  char *v6; // r1

  ptr = io_data->ptr;
  if ( isjson )
  {
    LOWORD(v6) = 20132;
    io_data->cur = ptr;
    HIWORD(v6) = (unsigned int)&freq_pll[66].fildiv2 >> 16;
  }
  else
  {
    LOWORD(v6) = 20148;
    io_data->cur = ptr;
    HIWORD(v6) = (unsigned int)&freq_pll[67].fildiv2 >> 16;
  }
  *ptr = 0;
  io_data->close = 0;
  io_add(io_data, v6);
  bye = 1;
  do_a_quit = 1;
}
