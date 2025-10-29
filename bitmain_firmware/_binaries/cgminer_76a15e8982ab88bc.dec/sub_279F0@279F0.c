int sub_279F0()
{
  char s1[5]; // [sp+7h] [bp-5h] BYREF

  pthread_setcanceltype(1, 0);
  sub_2EF24("Input");
  if ( byte_73E80 )
  {
    do
    {
      while ( 1 )
      {
        s1[0] = wgetch((WINDOW *)stdscr);
        if ( !strncasecmp(s1, "q", 1u) )
          sub_17830();
        if ( strncasecmp(s1, "d", 1u) )
          break;
        sub_26054();
        if ( byte_78940 )
          goto LABEL_10;
      }
      if ( !strncasecmp(s1, "p", 1u) )
      {
        sub_26EA8();
      }
      else if ( !strncasecmp(s1, "s", 1u) )
      {
        sub_26708();
      }
    }
    while ( !byte_78940 );
LABEL_10:
    sub_195CC();
  }
  return 0;
}
