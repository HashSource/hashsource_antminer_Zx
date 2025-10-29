void __fastcall jsonp_error_set_source(json_error_t *error, const char *source)
{
  bool v2; // zf

  v2 = source == 0;
  if ( source )
    v2 = error == 0;
  if ( !v2 )
    jsonp_error_set_source_0(error, source);
}
