speed_t __fastcall tiospeed_t(int baud)
{
  if ( baud == 115200 )
    return 4098;
  if ( baud <= 115200 )
  {
    if ( baud != 19200 )
    {
      if ( baud <= 19200 )
      {
        if ( baud == 9600 )
          return 13;
      }
      else
      {
        if ( baud == 38400 )
          return 15;
        if ( baud == 57600 )
          return 4097;
      }
      return 0;
    }
    return 14;
  }
  else
  {
    if ( baud != 921600 )
    {
      if ( baud > 921600 )
      {
        if ( baud == 1500000 )
          return 4106;
        if ( baud == 3000000 )
          return 4109;
      }
      else
      {
        if ( baud == 230400 )
          return 4099;
        if ( baud == 460800 )
          return 4100;
      }
      return 0;
    }
    return 4103;
  }
}
