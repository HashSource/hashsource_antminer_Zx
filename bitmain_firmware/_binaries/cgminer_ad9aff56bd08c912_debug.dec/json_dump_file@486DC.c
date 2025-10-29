int __fastcall json_dump_file(const json_t *json, const char *path, size_t flags)
{
  const char *v4; // r1
  FILE *v7; // r0
  FILE *v8; // r4
  json_dump_callback_t v9; // r1
  int v10; // r5

  LOWORD(v4) = 5820;
  HIWORD(v4) = (unsigned int)"" >> 16;
  v7 = fopen(path, v4);
  if ( !v7 )
    return -1;
  v8 = v7;
  LOWORD(v9) = 32717;
  HIWORD(v9) = (unsigned int)&bench_hidiffs[3473] >> 16;
  v10 = json_dump_callback(json, v9, v7, flags);
  fclose(v8);
  return v10;
}
