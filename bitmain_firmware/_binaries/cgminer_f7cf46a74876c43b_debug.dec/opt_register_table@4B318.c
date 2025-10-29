void __fastcall opt_register_table(const opt_table *entry, const char *desc)
{
  const opt_table *v2; // r4
  unsigned int v4; // r7
  opt_type type; // r3
  opt_table heading; // [sp+4h] [bp-20h] BYREF

  v2 = entry;
  v4 = opt_count;
  if ( desc )
  {
    heading.names = 0;
    memset(&heading.cb, 0, 16);
    heading.desc = desc;
    heading.type = opt_type::OPT_SUBTABLE;
    add_opt(&heading);
    type = v2->type;
    if ( type == opt_type::OPT_END )
    {
LABEL_7:
      opt_table_0[v4].u.tlen = opt_count - v4;
      return;
    }
  }
  else
  {
    type = entry->type;
    if ( type == opt_type::OPT_END )
      return;
  }
  do
  {
    if ( type == opt_type::OPT_SUBTABLE )
    {
      opt_register_table((const opt_table *)v2->names, v2->desc);
    }
    else
    {
      check_opt(v2);
      add_opt(v2);
    }
    ++v2;
    type = v2->type;
  }
  while ( type != opt_type::OPT_END );
  if ( desc )
    goto LABEL_7;
}
