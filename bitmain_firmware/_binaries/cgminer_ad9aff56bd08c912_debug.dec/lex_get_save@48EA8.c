int __fastcall lex_get_save(lex_t *lex, json_error_t *error)
{
  int state; // r4

  state = lex->stream.state;
  if ( !state )
    state = stream_get_part_3(lex, error);
  if ( (unsigned int)(state + 2) > 1 )
    strbuffer_append_byte(&lex->saved_text, state);
  return state;
}
