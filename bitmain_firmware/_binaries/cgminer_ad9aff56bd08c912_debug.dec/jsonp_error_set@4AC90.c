void jsonp_error_set(json_error_t *error, int line, int column, int position, const char *msg, ...)
{
  va_list va; // [sp+24h] [bp+18h] BYREF

  va_start(va, msg);
  if ( error )
  {
    if ( !error->text[0] )
    {
      error->line = line;
      error->column = column;
      error->position = position;
      vsnprintf(error->text, 0xA0u, msg, va);
      error->text[159] = 0;
    }
  }
}
