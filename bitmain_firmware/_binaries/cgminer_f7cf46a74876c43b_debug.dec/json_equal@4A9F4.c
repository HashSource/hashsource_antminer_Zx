int __fastcall json_equal(json_t *json1, json_t *json2)
{
  bool v2; // zf

  v2 = json2 == 0;
  if ( json2 )
    v2 = json1 == 0;
  if ( v2 )
    return 0;
  else
    return json_equal_0(json1, json2);
}
