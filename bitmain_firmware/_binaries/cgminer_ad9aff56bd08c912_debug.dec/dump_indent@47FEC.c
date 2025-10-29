int __fastcall dump_indent(size_t flags, int depth, int space, json_dump_callback_t dump, void *data)
{
  size_t v5; // r9
  const char *v6; // r0
  int v9; // r4
  const char *v10; // r7
  const char *v12; // r0

  v5 = flags & 0x1F;
  if ( (flags & 0x1F) != 0 )
  {
    LOWORD(v6) = -28576;
    HIWORD(v6) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
    v9 = dump(v6, 1, data);
    if ( v9 )
      return -1;
    if ( depth > 0 )
    {
      LOWORD(v10) = -20384;
      while ( 1 )
      {
        HIWORD(v10) = (unsigned int)"= 1 found.\n" >> 16;
        ++v9;
        if ( dump(v10, v5, data) )
          break;
        if ( depth == v9 )
          return 0;
      }
      return -1;
    }
    return 0;
  }
  if ( !space || (flags & 0x20) != 0 )
    return 0;
  LOWORD(v12) = -23560;
  HIWORD(v12) = (unsigned int)"be %02d, but read back is %02d\n" >> 16;
  return dump(v12, 1, data);
}
