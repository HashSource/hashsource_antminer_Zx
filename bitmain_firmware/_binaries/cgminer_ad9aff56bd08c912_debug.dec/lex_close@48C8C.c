void __fastcall lex_close(lex_t *lex)
{
  if ( lex->token == 256 )
  {
    jsonp_free(lex->value.string);
    strbuffer_close(&lex->saved_text);
  }
  else
  {
    strbuffer_close(&lex->saved_text);
  }
}
