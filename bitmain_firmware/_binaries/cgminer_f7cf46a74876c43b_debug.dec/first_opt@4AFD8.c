const char *__fastcall first_opt(unsigned int *i, unsigned int *len)
{
  opt_table *v2; // r2
  opt_table *v3; // r5
  unsigned int v4; // r4
  const char *v5; // r4

  *i = 0;
  if ( !opt_count )
    return 0;
  v2 = opt_table_0;
  if ( opt_table_0->type == opt_type::OPT_SUBTABLE )
  {
    v3 = opt_table_0 + 1;
    v4 = 1;
    do
    {
      *i = v4;
      v2 = v3++;
      if ( opt_count <= v4++ )
        return 0;
    }
    while ( v2->type == opt_type::OPT_SUBTABLE );
  }
  v5 = v2->names + 1;
  *len = strcspn(v5, "|= ");
  return v5;
}
