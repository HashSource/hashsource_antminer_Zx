void __fastcall sub_38AC4(int a1, const char *a2, int a3)
{
  int v6; // r0

  if ( byte_7AD48 )
  {
    syslog(a1 | 0x80, "%s", a2);
  }
  else
  {
    v6 = fileno((FILE *)stderr);
    if ( !isatty(v6) )
    {
      fprintf((FILE *)stderr, "%s\n", a2);
      fflush((FILE *)stderr);
    }
    sub_389F4(a1, "", a2, a3);
  }
}
