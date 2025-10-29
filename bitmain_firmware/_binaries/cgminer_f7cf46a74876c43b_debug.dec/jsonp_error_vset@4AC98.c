void __fastcall jsonp_error_vset(
        json_error_t *error,
        int line,
        int column,
        size_t position,
        const char *msg,
        va_list ap)
{
  if ( error )
  {
    if ( !error->text[0] )
    {
      error->line = line;
      error->column = column;
      error->position = position;
      vsnprintf(error->text, 0xA0u, msg, ap);
      error->text[159] = 0;
    }
  }
}
