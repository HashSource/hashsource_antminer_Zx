void __fastcall sub_3895C(int a1, const char *a2, int a3)
{
  int v6; // r0

  if ( byte_77B70 )
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
    sub_3888C(a1, "", a2, a3);
  }
}
