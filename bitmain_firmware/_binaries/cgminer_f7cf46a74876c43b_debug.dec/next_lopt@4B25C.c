const char *__fastcall next_lopt(const char *p, unsigned int *i, unsigned int *len)
{
  const char *opt; // r0

  opt = next_opt(p, i, len);
  if ( !opt )
    return 0;
  while ( *opt != 45 )
  {
    opt = next_opt(opt, i, len);
    if ( !opt )
      return 0;
  }
  --*len;
  return opt + 1;
}
