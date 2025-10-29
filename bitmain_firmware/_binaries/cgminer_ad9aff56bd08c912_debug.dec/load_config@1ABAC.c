char *__fastcall load_config(const char *arg, void *unused)
{
  bool v3; // nf

  if ( !cnfbuf )
    cnfbuf = _strdup(arg);
  v3 = include_count - 9 < 0;
  ++include_count;
  if ( v3 ^ __OFSUB__(include_count, 10) | (include_count == 10) )
    return load_config_0(arg, unused);
  else
    return "Too many levels of JSON includes (limit 10) or a loop";
}
