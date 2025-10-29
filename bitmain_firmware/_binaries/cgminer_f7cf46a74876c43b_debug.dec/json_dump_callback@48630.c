int __fastcall json_dump_callback(const json_t *json, json_dump_callback_t callback, void *data, size_t flags)
{
  if ( (flags & 0x200) != 0 || json && json->type <= (unsigned int)JSON_ARRAY )
    return do_dump((int)json, (unsigned __int16)flags, 0, callback, data);
  else
    return -1;
}
