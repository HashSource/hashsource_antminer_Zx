// Alternative name is 'jsonp_error_set_source.part.0'
void __fastcall jsonp_error_set_source_0(json_error_t *error, const char *source)
{
  size_t v4; // r0

  v4 = strlen(source);
  if ( v4 <= 0x4F )
  {
    sub_12058(error->source, source, v4 + 1);
  }
  else
  {
    strcpy(error->source, "...");
    j_strcpy(&error->source[3], &source[v4 - 76]);
  }
}
