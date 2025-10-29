int __fastcall strbuffer_append_bytes(strbuffer_t *strbuff, const char *data, size_t size)
{
  size_t v4; // r3
  size_t length; // r0
  char *value; // r8
  unsigned int v9; // r3
  size_t v10; // r6
  char *v11; // r0
  char *v12; // r2
  size_t v14; // r5

  v4 = strbuff->size;
  length = strbuff->length;
  if ( v4 - length > size )
  {
    value = strbuff->value;
LABEL_9:
    memcpy(&value[length], data, size);
    v12 = strbuff->value;
    v14 = size + strbuff->length;
    strbuff->length = v14;
    v12[v14] = 0;
    return 0;
  }
  if ( !((size == -1) | (v4 >> 31)) && -2 - size >= length )
  {
    v9 = 2 * v4;
    v10 = size + 1 + length;
    if ( v10 < v9 )
      v10 = v9;
    v11 = (char *)jsonp_malloc(v10);
    value = v11;
    if ( v11 )
    {
      memcpy(v11, strbuff->value, strbuff->length);
      jsonp_free(strbuff->value);
      length = strbuff->length;
      strbuff->value = value;
      strbuff->size = v10;
      goto LABEL_9;
    }
  }
  return -1;
}
