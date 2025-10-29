int sub_27A98()
{
  char s1[5]; // [sp+7h] [bp-5h] BYREF

  pthread_setcanceltype(1, 0);
  sub_2F0B4("Input");
  if ( byte_77018 )
  {
    do
    {
      while ( 1 )
      {
        s1[0] = wgetch((WINDOW *)stdscr);
        if ( !strncasecmp(s1, "q", 1u) )
          sub_178F8();
        if ( strncasecmp(s1, "d", 1u) )
          break;
        sub_260FC();
        if ( byte_7BB18 )
          goto LABEL_10;
      }
      if ( !strncasecmp(s1, "p", 1u) )
      {
        sub_26F50();
      }
      else if ( !strncasecmp(s1, "s", 1u) )
      {
        sub_267B0();
      }
    }
    while ( !byte_7BB18 );
LABEL_10:
    sub_19ADC();
  }
  return 0;
}
