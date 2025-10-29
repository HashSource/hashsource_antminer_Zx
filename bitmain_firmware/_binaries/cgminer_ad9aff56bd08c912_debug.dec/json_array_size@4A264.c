size_t __fastcall json_array_size(const json_t *json)
{
  if ( json )
  {
    if ( json->type == JSON_ARRAY )
      return json[1].refcount;
    else
      return 0;
  }
  return (size_t)json;
}
