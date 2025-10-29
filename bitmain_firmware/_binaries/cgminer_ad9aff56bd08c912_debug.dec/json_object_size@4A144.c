size_t __fastcall json_object_size(const json_t *json)
{
  if ( json )
  {
    if ( json->type )
      return 0;
    else
      return json[1].type;
  }
  return (size_t)json;
}
