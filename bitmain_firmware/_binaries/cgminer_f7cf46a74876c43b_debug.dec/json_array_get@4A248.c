json_t *__fastcall json_array_get(const json_t *json, size_t index)
{
  if ( json )
  {
    if ( json->type == JSON_ARRAY && json[1].refcount > index )
      return *(json_t **)(json[2].type + 4 * index);
    else
      return 0;
  }
  return (json_t *)json;
}
