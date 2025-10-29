int __fastcall strbuffer_append(strbuffer_t *strbuff, const char *string)
{
  size_t v4; // r0

  v4 = strlen(string);
  return strbuffer_append_bytes(strbuff, string, v4);
}
