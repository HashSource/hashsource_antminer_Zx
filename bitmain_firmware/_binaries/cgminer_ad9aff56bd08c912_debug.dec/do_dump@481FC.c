int __fastcall do_dump(int a1, size_t a2, int a3, int (*a4)(const char *, size_t, void *), void *data)
{
  int v6; // r4
  const char *v9; // r0
  const char *v11; // r3
  const char *v12; // r11
  size_t v13; // r8
  void *v14; // r7
  const char *v15; // r0
  const char *v16; // r0
  signed int v17; // r7
  const char *v18; // r0
  const char *v19; // r0
  const char *v20; // r0
  json_int_t v21; // r0
  const char *v22; // r2
  int v23; // r3
  size_t v24; // r0
  double v25; // r2
  signed int v26; // r1
  const char *v27; // r0
  const char *v28; // r0
  const char **v29; // r0
  const char **v30; // r9
  void *v31; // r6
  unsigned int i; // r11
  unsigned int v33; // r2
  const char *v34; // r11
  size_t v35; // r6
  const char **v36; // r7
  int (*v37)(const void *, const void *); // r2
  const char *v38; // r1
  int (*v39)(const void *, const void *); // r3
  unsigned int v40; // r9
  size_t v41; // r8
  const char *v42; // r4
  json_t *v43; // r10
  json_t *v44; // r3
  json_t *v45; // r10
  void *v46; // r4
  const char *v47; // r0
  json_t *v48; // r0
  size_t v49; // r9
  signed int v50; // r8
  const char *v51; // r11
  json_t *v52; // r0
  const char *v53; // r1
  const char *v54; // r0
  const char *v55; // r1
  const char *v56; // r0
  size_t json; // [sp+Ch] [bp-ACh]
  json_t *jsona; // [sp+Ch] [bp-ACh]
  json_t *jsonb; // [sp+Ch] [bp-ACh]
  size_t nmemb; // [sp+10h] [bp-A8h]
  size_t nmemba; // [sp+10h] [bp-A8h]
  const char *v62; // [sp+14h] [bp-A4h]
  size_t v63; // [sp+14h] [bp-A4h]
  size_t depth; // [sp+18h] [bp-A0h]
  int deptha; // [sp+18h] [bp-A0h]
  unsigned int v66; // [sp+1Ch] [bp-9Ch]
  size_t v67; // [sp+20h] [bp-98h]
  const char *v68; // [sp+20h] [bp-98h]
  const char **base; // [sp+24h] [bp-94h]
  char s[140]; // [sp+2Ch] [bp-8Ch] BYREF

  if ( !a1 )
    return -1;
  v6 = a1;
  switch ( *(_DWORD *)a1 )
  {
    case 0:
      LOWORD(v11) = -20284;
      LOWORD(v12) = 16004;
      HIWORD(v12) = (unsigned int)"proxy: %s" >> 16;
      if ( (a2 & 0x20) != 0 )
        v13 = 1;
      else
        v13 = 2;
      if ( (a2 & 0x20) == 0 )
      {
        HIWORD(v11) = (unsigned int)"\\b" >> 16;
        v12 = v11;
      }
      if ( *(_DWORD *)(a1 + 32) )
        goto object_error;
      *(_DWORD *)(a1 + 32) = 1;
      v14 = json_object_iter((json_t *)a1);
      LOWORD(v15) = 20364;
      HIWORD(v15) = (unsigned int)off_54F0C >> 16;
      if ( a4(v15, 1, data) )
        goto object_error;
      if ( !v14 )
        goto LABEL_12;
      deptha = a3 + 1;
      if ( dump_indent(a2, a3 + 1, 0, a4, data) )
        goto object_error;
      if ( (a2 & 0x180) != 0 )
      {
        json = json_object_size((const json_t *)v6);
        v29 = (const char **)jsonp_malloc(8 * json);
        base = v29;
        if ( v29 )
        {
          v62 = v12;
          v67 = a2;
          v30 = v29 + 1;
          v31 = v14;
          for ( i = 0; ; ++i )
          {
            *(v30 - 1) = (const char *)hashtable_iter_serial(v31);
            *v30 = json_object_iter_key(v31);
            v30 += 2;
            v31 = json_object_iter_next((json_t *)v6, v31);
            if ( !v31 )
              break;
          }
          v33 = i + 1;
          nmemb = i + 1;
          v66 = i;
          v34 = v62;
          v35 = v67;
          if ( json != v33 )
          {
            LOWORD(v53) = -20272;
            LOWORD(v54) = -20264;
            HIWORD(v53) = (unsigned int)"\\r" >> 16;
            HIWORD(v54) = (unsigned int)"\\/" >> 16;
            _assert_fail(v54, v53, 0x141u, "do_dump");
          }
          v36 = base;
          LOWORD(v37) = 32741;
          LOWORD(v38) = -2296;
          HIWORD(v38) = (unsigned int)"{\n\t\t\"url\" : \"%s%s%s%s\"," >> 16;
          LOWORD(v39) = 32681;
          v68 = v38;
          HIWORD(v39) = (unsigned int)&loc_47F78 >> 16;
          v40 = 0;
          if ( (v35 & 0x80) != 0 )
          {
            HIWORD(v37) = (unsigned int)&loc_47FB4 >> 16;
            v39 = v37;
          }
          qsort(base, nmemb, 8u, v39);
          v63 = v13;
          jsona = (json_t *)v6;
          v41 = a3 + 1;
          depth = a3;
          while ( 1 )
          {
            v42 = v36[1];
            v43 = json_object_get(jsona, v42);
            if ( !v43 )
            {
              LOWORD(v55) = -20272;
              LOWORD(v56) = -1672;
              HIWORD(v55) = (unsigned int)"\\r" >> 16;
              HIWORD(v56) = (unsigned int)"includes (limit 10) or a loop" >> 16;
              _assert_fail(v56, v55, 0x151u, "do_dump");
            }
            dump_string(v42, a4, data, v35);
            if ( a4(v34, v63, data) || do_dump((int)v43, v35, v41, a4, data) )
              break;
            if ( v40 < v66 )
            {
              if ( a4(v68, 1, data) || dump_indent(v35, v41, 1, a4, data) )
                break;
            }
            else if ( dump_indent(v35, depth, 0, a4, data) )
            {
              break;
            }
            ++v40;
            v36 += 2;
            if ( v40 == nmemb )
            {
              v6 = (int)jsona;
              jsonp_free(base);
LABEL_12:
              LOWORD(v16) = 17792;
              *(_DWORD *)(v6 + 32) = 0;
              HIWORD(v16) = (unsigned int)"confirmed mining.subscribe with extranonce1 %s extran2size %d" >> 16;
              return a4(v16, 1, data);
            }
          }
          v6 = (int)jsona;
          jsonp_free(base);
        }
      }
      else
      {
        LOWORD(v44) = -2296;
        nmemba = a3;
        v45 = (json_t *)v6;
        HIWORD(v44) = (unsigned int)"{\n\t\t\"url\" : \"%s%s%s%s\"," >> 16;
        jsonb = v44;
        while ( 1 )
        {
          v46 = json_object_iter_next(v45, v14);
          v47 = json_object_iter_key(v14);
          dump_string(v47, a4, data, a2);
          if ( a4(v12, v13, data) || (v48 = json_object_iter_value(v14), do_dump((int)v48, a2, deptha, a4, data)) )
          {
LABEL_49:
            v6 = (int)v45;
            goto object_error;
          }
          if ( !v46 )
            break;
          if ( !a4((const char *)jsonb, 1, data) )
          {
            v14 = v46;
            if ( !dump_indent(a2, deptha, 1, a4, data) )
              continue;
          }
          goto LABEL_49;
        }
        v6 = (int)v45;
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
      v17 = json_array_size((const json_t *)a1);
      LOWORD(v18) = -2380;
      HIWORD(v18) = (unsigned int)"d cloned or rolled work" >> 16;
      if ( a4(v18, 1, data) )
        goto array_error;
      if ( !v17 )
        goto LABEL_16;
      v49 = a3 + 1;
      v50 = dump_indent(a2, a3 + 1, 0, a4, data);
      if ( v50 )
        goto array_error;
      if ( v17 <= 0 )
        goto LABEL_16;
      LOWORD(v51) = -2296;
      break;
    case 2:
      v20 = json_string_value((const json_t *)a1);
      return dump_string(v20, a4, data, a2);
    case 3:
      v21 = json_integer_value((const json_t *)a1);
      LOWORD(v22) = 544;
      HIWORD(v22) = (unsigned int)"SOLVED %d BLOCK%s!" >> 16;
      v24 = snprintf(s, 0x64u, v22, v23, v21);
      return a4(s, v24, data);
    case 4:
      json_real_value((const json_t *)a1);
      v26 = jsonp_dtostr(s, 0x64u, v25);
      if ( v26 < 0 )
        return -1;
      return a4(s, v26, data);
    case 5:
      LOWORD(v27) = 21496;
      HIWORD(v27) = (unsigned int)"" >> 16;
      return a4(v27, 4, data);
    case 6:
      LOWORD(v28) = 26060;
      HIWORD(v28) = (unsigned int)"ls" >> 16;
      return a4(v28, 5, data);
    case 7:
      LOWORD(v9) = -20280;
      HIWORD(v9) = (unsigned int)"\\f" >> 16;
      return a4(v9, 4, data);
    default:
      return -1;
  }
  while ( 1 )
  {
    v52 = json_array_get((const json_t *)v6, v50);
    if ( do_dump((int)v52, a2, v49, a4, data) )
      break;
    if ( v17 - 1 <= v50 )
    {
      if ( dump_indent(a2, a3, 0, a4, data) )
        break;
    }
    else
    {
      HIWORD(v51) = (unsigned int)"{\n\t\t\"url\" : \"%s%s%s%s\"," >> 16;
      if ( a4(v51, 1, data) || dump_indent(a2, v49, 1, a4, data) )
        break;
    }
    if ( v17 == ++v50 )
    {
LABEL_16:
      LOWORD(v19) = -25844;
      *(_DWORD *)(v6 + 20) = 0;
      HIWORD(v19) = (unsigned int)"echo %d > /sys/class/gpio/gpio%d/value" >> 16;
      return a4(v19, 1, data);
    }
  }
array_error:
  *(_DWORD *)(v6 + 20) = 0;
  return -1;
}
