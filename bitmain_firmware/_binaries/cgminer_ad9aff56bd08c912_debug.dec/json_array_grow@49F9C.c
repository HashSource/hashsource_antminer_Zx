json_t **__fastcall json_array_grow(json_array_t *array, size_t amount, int copy)
{
  __int64 v3; // kr00_8
  json_t **table; // r6
  size_t v6; // r5
  json_t **v9; // r0

  v3 = *(_QWORD *)&array->size;
  table = array->table;
  if ( HIDWORD(v3) + amount <= (unsigned int)v3 )
    return table;
  v6 = v3 + amount;
  if ( (unsigned int)v3 + amount < 2 * (int)v3 )
    v6 = 2 * v3;
  v9 = (json_t **)jsonp_malloc(4 * v6);
  if ( !v9 )
    return 0;
  array->size = v6;
  array->table = v9;
  if ( !copy )
    return table;
  memcpy(v9, table, 4 * array->entries);
  jsonp_free(table);
  return array->table;
}
