int __fastcall dump_to_file(const char *buffer, size_t size, void *data)
{
  int result; // r0

  result = fwrite(buffer, size, 1u, (FILE *)data) - 1;
  if ( result )
    return -1;
  return result;
}
