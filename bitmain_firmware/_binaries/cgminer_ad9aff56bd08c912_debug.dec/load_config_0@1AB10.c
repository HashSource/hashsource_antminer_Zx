// Alternative name is 'load_config.part.59'
char *__fastcall load_config_0(const char *arg, void *unused)
{
  json_t *v3; // r0
  size_t v4; // r4
  size_t v5; // r4
  char *v6; // r0
  char *v7; // r7
  const char *v8; // r2
  int *v10; // r5
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  json_error_t err; // [sp+Ch] [bp-1100h] BYREF
  char tmp42[4096]; // [sp+108h] [bp-1004h] BYREF

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
      LOWORD(v10) = -1804;
      HIWORD(v10) = (unsigned int)"e %d" >> 16;
      v11 = *v10;
      v12 = v10[1];
      v13 = v10[2];
      v14 = v10[3];
      v10 += 4;
      *(_DWORD *)tmp42 = v11;
      *(_DWORD *)&tmp42[4] = v12;
      *(_DWORD *)&tmp42[8] = v13;
      *(_DWORD *)&tmp42[12] = v14;
      v15 = v10[1];
      v16 = v10[2];
      v17 = v10[3];
      *(_DWORD *)&tmp42[16] = *v10;
      *(_DWORD *)&tmp42[20] = v15;
      *(_DWORD *)&tmp42[24] = v16;
      tmp42[28] = v17;
      applog(3, tmp42, 1);
      _quit(1, 1);
    }
    LOWORD(v8) = -1772;
    HIWORD(v8) = (unsigned int)" thread" >> 16;
    snprintf(v6, v5, v8, arg, err.text);
    return v7;
  }
}
