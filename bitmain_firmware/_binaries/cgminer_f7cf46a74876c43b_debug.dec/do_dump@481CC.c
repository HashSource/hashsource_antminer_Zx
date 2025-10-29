int __fastcall do_dump(int a1, size_t a2, int a3, int (*a4)(const char *, size_t, void *), void *data)
{
  int v6; // r4
  const char *v10; // r11
  size_t v11; // r8
  void *v12; // r7
  signed int v13; // r7
  const char *v14; // r0
  json_int_t v15; // r0
  size_t v16; // r0
  double v17; // r2
  signed int v18; // r1
  const char **v19; // r0
  const char **v20; // r9
  void *v21; // r6
  unsigned int i; // r11
  unsigned int v23; // r2
  const char *v24; // r11
  const char **v25; // r7
  int (*v26)(const void *, const void *); // r3
  unsigned int v27; // r9
  size_t v28; // r8
  const char *v29; // r4
  json_t *v30; // r10
  json_t *v31; // r10
  void *v32; // r4
  const char *v33; // r0
  json_t *v34; // r0
  size_t v35; // r9
  signed int v36; // r8
  json_t *v37; // r0
  size_t json; // [sp+Ch] [bp-ACh]
  json_t *jsona; // [sp+Ch] [bp-ACh]
  size_t nmemb; // [sp+10h] [bp-A8h]
  size_t nmemba; // [sp+10h] [bp-A8h]
  const char *v42; // [sp+14h] [bp-A4h]
  size_t v43; // [sp+14h] [bp-A4h]
  size_t depth; // [sp+18h] [bp-A0h]
  int deptha; // [sp+18h] [bp-A0h]
  unsigned int v46; // [sp+1Ch] [bp-9Ch]
  size_t v47; // [sp+20h] [bp-98h]
  const char **base; // [sp+24h] [bp-94h]
  char s[140]; // [sp+2Ch] [bp-8Ch] BYREF

  if ( !a1 )
    return -1;
  v6 = a1;
  switch ( *(_DWORD *)a1 )
  {
    case 0:
      v10 = ":";
      if ( (a2 & 0x20) != 0 )
        v11 = 1;
      else
        v11 = 2;
      if ( (a2 & 0x20) == 0 )
        v10 = ": ";
      if ( *(_DWORD *)(a1 + 32) )
        goto object_error;
      *(_DWORD *)(a1 + 32) = 1;
      v12 = json_object_iter((json_t *)a1);
      if ( a4("{", 1, data) )
        goto object_error;
      if ( !v12 )
        goto LABEL_12;
      deptha = a3 + 1;
      if ( dump_indent(a2, a3 + 1, 0, a4, data) )
        goto object_error;
      if ( (a2 & 0x180) != 0 )
      {
        json = json_object_size((const json_t *)v6);
        v19 = (const char **)jsonp_malloc(8 * json);
        base = v19;
        if ( v19 )
        {
          v42 = v10;
          v47 = a2;
          v20 = v19 + 1;
          v21 = v12;
          for ( i = 0; ; ++i )
          {
            *(v20 - 1) = (const char *)hashtable_iter_serial(v21);
            *v20 = json_object_iter_key(v21);
            v20 += 2;
            v21 = json_object_iter_next((json_t *)v6, v21);
            if ( !v21 )
              break;
          }
          v23 = i + 1;
          nmemb = i + 1;
          v46 = i;
          v24 = v42;
          if ( json != v23 )
            _assert_fail("i == size", "dump.c", 0x141u, "do_dump");
          v25 = base;
          v26 = object_key_compare_serials;
          v27 = 0;
          if ( (v47 & 0x80) != 0 )
            v26 = object_key_compare_keys;
          qsort(base, nmemb, 8u, v26);
          v43 = v11;
          jsona = (json_t *)v6;
          v28 = a3 + 1;
          depth = a3;
          while ( 1 )
          {
            v29 = v25[1];
            v30 = json_object_get(jsona, v29);
            if ( !v30 )
              _assert_fail("value", "dump.c", 0x151u, "do_dump");
            dump_string(v29, a4, data, v47);
            if ( a4(v24, v43, data) || do_dump((int)v30, v47, v28, a4, data) )
              break;
            if ( v27 < v46 )
            {
              if ( a4(",", 1, data) || dump_indent(v47, v28, 1, a4, data) )
                break;
            }
            else if ( dump_indent(v47, depth, 0, a4, data) )
            {
              break;
            }
            ++v27;
            v25 += 2;
            if ( v27 == nmemb )
            {
              v6 = (int)jsona;
              jsonp_free(base);
LABEL_12:
              *(_DWORD *)(v6 + 32) = 0;
              return a4("}", 1, data);
            }
          }
          v6 = (int)jsona;
          jsonp_free(base);
        }
      }
      else
      {
        nmemba = a3;
        v31 = (json_t *)v6;
        while ( 1 )
        {
          v32 = json_object_iter_next(v31, v12);
          v33 = json_object_iter_key(v12);
          dump_string(v33, a4, data, a2);
          if ( a4(v10, v11, data) || (v34 = json_object_iter_value(v12), do_dump((int)v34, a2, deptha, a4, data)) )
          {
LABEL_49:
            v6 = (int)v31;
            goto object_error;
          }
          if ( !v32 )
            break;
          if ( !a4(",", 1, data) )
          {
            v12 = v32;
            if ( !dump_indent(a2, deptha, 1, a4, data) )
              continue;
          }
          goto LABEL_49;
        }
        v6 = (int)v31;
        if ( !dump_indent(a2, nmemba, 0, a4, data) )
          goto LABEL_12;
      }
object_error:
      *(_DWORD *)(v6 + 32) = 0;
      return -1;
    case 1:
      if ( *(_DWORD *)(a1 + 20) )
        goto array_error;
      *(_DWORD *)(a1 + 20) = 1;
      v13 = json_array_size((const json_t *)a1);
      if ( a4("[", 1, data) )
        goto array_error;
      if ( !v13 )
        goto LABEL_16;
      v35 = a3 + 1;
      v36 = dump_indent(a2, a3 + 1, 0, a4, data);
      if ( v36 )
        goto array_error;
      if ( v13 <= 0 )
        goto LABEL_16;
      break;
    case 2:
      v14 = json_string_value((const json_t *)a1);
      return dump_string(v14, a4, data, a2);
    case 3:
      v15 = json_integer_value((const json_t *)a1);
      v16 = snprintf(s, 0x64u, "%lld", v15);
      return a4(s, v16, data);
    case 4:
      json_real_value((const json_t *)a1);
      v18 = jsonp_dtostr(s, 0x64u, v17);
      if ( v18 < 0 )
        return -1;
      return a4(s, v18, data);
    case 5:
      return a4("true", 4, data);
    case 6:
      return a4("false", 5, data);
    case 7:
      return a4("null", 4, data);
    default:
      return -1;
  }
  while ( 1 )
  {
    v37 = json_array_get((const json_t *)v6, v36);
    if ( do_dump((int)v37, a2, v35, a4, data) )
      break;
    if ( v13 - 1 <= v36 )
    {
      if ( dump_indent(a2, a3, 0, a4, data) )
        break;
    }
    else if ( a4(",", 1, data) || dump_indent(a2, v35, 1, a4, data) )
    {
      break;
    }
    if ( v13 == ++v36 )
    {
LABEL_16:
      *(_DWORD *)(v6 + 20) = 0;
      return a4((const char *)&word_59A90, 1, data);
    }
  }
array_error:
  *(_DWORD *)(v6 + 20) = 0;
  return -1;
}
