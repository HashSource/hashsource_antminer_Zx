void __fastcall jsonp_error_init(json_error_t *error, const char *source)
{
  if ( error )
  {
    error->text[0] = 0;
    error->position = 0;
    error->line = -1;
    error->column = -1;
    if ( source )
      jsonp_error_set_source_0(error, source);
    else
      error->source[0] = 0;
  }
}
