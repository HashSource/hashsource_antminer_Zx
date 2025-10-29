int __fastcall stream_get_part_3(const lex_t *a1, json_error_t *a2)
{
  size_t buffer_pos; // r3
  const lex_t *v4; // r2
  size_t v5; // r6
  int v7; // r0
  int v8; // r5
  size_t v9; // r1
  int line; // r3
  int column; // r2
  int v13; // r0
  int v14; // r8
  char *v15; // r6
  char *v16; // r9
  size_t v17; // r3
  int v18; // r3

  buffer_pos = a1->stream.buffer_pos;
  v4 = (const lex_t *)((char *)a1 + buffer_pos);
  v5 = (unsigned __int8)a1->stream.buffer[buffer_pos];
  if ( a1->stream.buffer[buffer_pos] )
  {
    v9 = buffer_pos + 1;
  }
  else
  {
    v7 = a1->stream.get(a1->stream.data);
    v8 = v7;
    if ( v7 == -1 )
    {
      a1->stream.state = -1;
      return v8;
    }
    a1->stream.buffer_pos = v5;
    a1->stream.buffer[0] = v7;
    if ( (unsigned int)(v7 - 128) <= 0x7F )
    {
      v13 = utf8_check_first(v7);
      v14 = v13;
      if ( !v13 )
        goto LABEL_20;
      if ( v13 <= 1 )
        _assert_fail("count >= 2", "load.c", 0xAFu, "stream_get");
      v15 = &a1->stream.buffer[1];
      v16 = &a1->stream.buffer[v13];
      do
        *v15++ = a1->stream.get(a1->stream.data);
      while ( v16 != v15 );
      if ( !utf8_check_full(a1->stream.buffer, v14, 0) )
      {
LABEL_20:
        v18 = v8;
        a1->stream.state = -2;
        v8 = -2;
        error_set(a2, a1, "unable to decode byte 0x%x", v18);
        return v8;
      }
      a1->stream.buffer[v14] = 0;
      v17 = a1->stream.buffer_pos;
      v9 = v17 + 1;
      v4 = (const lex_t *)((char *)a1 + v17);
    }
    else
    {
      v9 = 1;
      v4 = a1;
      a1->stream.buffer[1] = v5;
    }
  }
  a1->stream.buffer_pos = v9;
  v8 = (unsigned __int8)v4->stream.buffer[0];
  ++a1->stream.position;
  if ( v8 != 10 )
  {
    if ( utf8_check_first(v8) )
      ++a1->stream.column;
    return v8;
  }
  line = a1->stream.line;
  column = a1->stream.column;
  a1->stream.column = 0;
  a1->stream.line = line + 1;
  a1->stream.last_column = column;
  return 10;
}
