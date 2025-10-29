int __cdecl baud2bt8d(unsigned int baud)
{
  if ( baud == 921600 )
    return 2;
  if ( baud <= 0xE1000 )
  {
    if ( baud == 115200 )
    {
      return 26;
    }
    else
    {
      if ( baud != 460800 )
        goto LABEL_13;
      return 6;
    }
  }
  if ( baud == 1500000 )
    return 1;
  if ( baud == 3000000 )
    return 0;
LABEL_13:
  printf("%s: the baud is not recommand value, so use 115200 baud\n", "baud2bt8d");
  return -1;
}
