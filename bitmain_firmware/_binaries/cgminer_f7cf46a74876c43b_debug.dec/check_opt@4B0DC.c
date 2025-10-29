void __fastcall check_opt(const opt_table *entry)
{
  __int64 v1; // r2
  bool v2; // cc
  const char *v4; // r4
  size_t v5; // r0
  opt_type type; // r5
  unsigned int v7; // r3
  int v8; // r3
  bool v9; // zf
  unsigned int len; // [sp+Ch] [bp-8h] BYREF

  v1 = *(_QWORD *)&entry->names;
  v2 = entry->type > (unsigned int)opt_type::OPT_PROCESSARG;
  if ( entry->type != opt_type::OPT_PROCESSARG )
    v2 = (unsigned int)(entry->type - 1) > 1;
  if ( v2 )
    errx(1, "Option %s: unknown entry type %u", (const char *)v1, HIDWORD(v1));
  if ( !entry->desc )
    errx(1, "Option %s: description cannot be NULL", (const char *)v1);
  if ( *(_BYTE *)v1 != 45 )
    errx(1, "Option %s: does not begin with '-'", (const char *)v1);
  v4 = (const char *)(v1 + 1);
  v5 = strcspn((const char *)(v1 + 1), "|= ");
  for ( len = v5; ; v5 = len )
  {
    if ( *v4 == 45 )
    {
      if ( v5 == 1 )
        errx(1, "Option %s: invalid long option '--'", entry->names);
      type = entry->type;
      ++opt_num_long;
    }
    else
    {
      if ( v5 != 1 )
        errx(1, "Option %s: invalid short option '%.*s'", entry->names, v5 + 1, v4 - 1);
      type = entry->type;
      v7 = (type - 2) & 0xFFFFFFFD;
      if ( !v7 )
        v7 = opt_num_short_arg;
      ++opt_num_short;
      if ( ((type - 2) & 0xFFFFFFFD) == 0 )
        opt_num_short_arg = v7 + 1;
    }
    if ( type == opt_type::OPT_NOARG )
    {
      v8 = (unsigned __int8)v4[v5];
      v9 = v8 == 61;
      if ( v8 != 61 )
        v9 = v8 == 32;
      if ( v9 )
        errx(1, "Option %s: does not take arguments '%s'", entry->names, &v4[v5 + 1]);
    }
    v4 = next_name(v4, &len);
    if ( !v4 )
      break;
  }
}
