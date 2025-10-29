const char *__fastcall next_opt(const char *p, unsigned int *i, unsigned int *len)
{
  unsigned int j; // r3
  opt_table *v7; // r2
  const char *v9; // r4

  for ( j = *i; j < opt_count; *i = ++j )
  {
    v7 = &opt_table_0[j];
    if ( v7->type != opt_type::OPT_SUBTABLE )
    {
      if ( !p )
      {
        v9 = v7->names + 1;
        *len = strcspn(v9, "|= ");
        return v9;
      }
      p = next_name(p, len);
      if ( p )
        return p;
      j = *i;
    }
  }
  return 0;
}
