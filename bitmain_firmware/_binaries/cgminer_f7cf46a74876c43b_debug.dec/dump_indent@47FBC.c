int __fastcall dump_indent(size_t flags, int depth, int space, json_dump_callback_t dump, void *data)
{
  size_t v5; // r9
  int v8; // r4

  v5 = flags & 0x1F;
  if ( (flags & 0x1F) != 0 )
  {
    v8 = dump((const char *)&word_58FE4, 1, data);
    if ( !v8 )
    {
      if ( depth <= 0 )
        return 0;
      while ( 1 )
      {
        ++v8;
        if ( dump("                                ", v5, data) )
          break;
        if ( depth == v8 )
          return 0;
      }
    }
    return -1;
  }
  if ( !space || (flags & 0x20) != 0 )
    return 0;
  return dump(" ", 1, data);
}
