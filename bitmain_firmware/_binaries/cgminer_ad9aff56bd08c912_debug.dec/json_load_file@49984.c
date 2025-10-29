json_t *__fastcall json_load_file(const char *path, size_t flags, json_error_t *error)
{
  const char *v6; // r1
  FILE *v7; // r0
  FILE *v8; // r7
  json_t *v9; // r6
  const char *v11; // r2
  int *v12; // r0
  char *v13; // r0
  const char *v14; // r2

  jsonp_error_init(error, path);
  if ( path )
  {
    LOWORD(v6) = 6248;
    HIWORD(v6) = (unsigned int)"line only" >> 16;
    v7 = fopen(path, v6);
    v8 = v7;
    if ( v7 )
    {
      v9 = json_loadf(v7, flags, error);
      fclose(v8);
    }
    else
    {
      v12 = _errno_location();
      v9 = 0;
      v13 = strerror(*v12);
      LOWORD(v14) = -19344;
      HIWORD(v14) = (unsigned int)"wrong arguments" >> 16;
      error_set(error, 0, v14, path, v13);
    }
  }
  else
  {
    LOWORD(v11) = -19392;
    HIWORD(v11) = (unsigned int)"{' expected" >> 16;
    error_set(error, 0, v11);
    return 0;
  }
  return v9;
}
