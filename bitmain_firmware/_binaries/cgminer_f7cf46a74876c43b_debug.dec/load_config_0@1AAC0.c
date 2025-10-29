// Alternative name is 'load_config.part.59'
char *__fastcall load_config_0(const char *arg, void *unused)
{
  json_t *v3; // r0
  size_t v4; // r4
  size_t v5; // r4
  char *v6; // r0
  char *v7; // r7
  json_error_t err; // [sp+Ch] [bp-1100h] BYREF
  char tmp42[4100]; // [sp+108h] [bp-1004h] BYREF

  v3 = json_load_file(arg, 0, &err);
  if ( v3 && v3->type == JSON_OBJECT )
  {
    config_loaded = 1;
    return parse_config(v3, 1);
  }
  else
  {
    v4 = strlen(arg);
    v5 = v4 + strlen(err.text) + 35;
    v6 = (char *)malloc(v5);
    v7 = v6;
    if ( !v6 )
    {
      strcpy(tmp42, "Malloc failure in json error");
      applog(3, tmp42, 1);
      _quit(1, 1);
    }
    snprintf(v6, v5, "JSON decode of file '%s' failed\n %s", arg, err.text);
    return v7;
  }
}
