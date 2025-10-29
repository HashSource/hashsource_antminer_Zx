json_t *__fastcall json_load_file(const char *path, size_t flags, json_error_t *error)
{
  FILE *v6; // r0
  FILE *v7; // r7
  json_t *v8; // r6
  int *v10; // r0
  char *v11; // r0

  jsonp_error_init(error, path);
  if ( path )
  {
    v6 = fopen(path, "rb");
    v7 = v6;
    if ( v6 )
    {
      v8 = json_loadf(v6, flags, error);
      fclose(v7);
    }
    else
    {
      v10 = _errno_location();
      v8 = 0;
      v11 = strerror(*v10);
      error_set(error, 0, "unable to open %s: %s", path, v11);
    }
  }
  else
  {
    error_set(error, 0, "wrong arguments");
    return 0;
  }
  return v8;
}
