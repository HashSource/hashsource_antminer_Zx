void __fastcall sub_15A9C(FILE *s)
{
  const char *v1; // r11
  int v3; // r5
  const char *v4; // r10
  const char *v5; // r0
  const char *v6; // r9
  const char *v7; // r0
  const char *v8; // r0
  int v9; // r7
  const char *v10; // r0
  const char *v11; // r0
  const char *v12; // r0
  int v13; // r0
  int v14; // r4
  const char *v15; // r7
  const char *v16; // r0
  const char *v17; // r9
  const char *v18; // r0
  const char *v19; // r0
  int v20; // r3
  const char *v21; // r10
  const char *v22; // r0
  const char **v23; // r5
  char *v24; // r8
  char *v25; // r4
  int v26; // r2
  int (__fastcall *v27)(_BYTE *); // r3
  char *(__fastcall *v28)(const char *, float *); // r3
  const char **v29; // r3
  const char *v30; // r0
  int v31; // r1
  int v32; // r4
  int v33; // r5
  const char *v34; // [sp+14h] [bp-8h]

  fwrite("{\n\"pools\" : [", 1u, 0xDu, s);
  if ( dword_77FC0 > 0 )
  {
    v3 = 0;
    while ( 1 )
    {
      v13 = sub_11F70(v3);
      v9 = *(_DWORD *)(v13 + 56);
      v14 = v13;
      if ( v9 == 1 )
      {
        v15 = ",";
        if ( !v3 )
          v15 = "";
        if ( *(_DWORD *)(v13 + 216) )
        {
          v16 = sub_295E8(*(char **)(v13 + 212));
          v17 = sub_F7DC(v16);
          v18 = *(const char **)(v14 + 216);
          if ( v18 )
          {
            v19 = sub_F7DC(v18);
            v20 = *(_DWORD *)(v14 + 216);
            if ( v20 )
              v1 = delim;
            v21 = v19;
            if ( v20 )
              goto LABEL_20;
            goto LABEL_69;
          }
        }
        else
        {
          v17 = "";
        }
        v21 = "";
LABEL_69:
        v1 = "";
LABEL_20:
        v22 = sub_F7DC(*(const char **)(v14 + 196));
        fprintf(s, "%s\n\t{\n\t\t\"url\" : \"%s%s%s%s\",", v15, v17, v21, v1, v22);
        goto LABEL_11;
      }
      v4 = ",";
      if ( !v3 )
        v4 = "";
      if ( !*(_DWORD *)(v13 + 216) )
        break;
      v5 = sub_295E8(*(char **)(v13 + 212));
      v6 = sub_F7DC(v5);
      v7 = *(const char **)(v14 + 216);
      if ( !v7 )
      {
        v9 = *(_DWORD *)(v14 + 56);
        goto LABEL_22;
      }
      v8 = sub_F7DC(v7);
      v9 = *(_DWORD *)(v14 + 56);
      v1 = v8;
      if ( !*(_DWORD *)(v14 + 216) )
        goto LABEL_23;
      v34 = delim;
LABEL_10:
      v10 = sub_F7DC(*(const char **)(v14 + 196));
      fprintf(s, "%s\n\t{\n\t\t\"quota\" : \"%s%s%s%d;%s\",", v4, v6, v1, v34, v9, v10);
LABEL_11:
      ++v3;
      v11 = sub_F7DC(*(const char **)(v14 + 204));
      fprintf(s, "\n\t\t\"user\" : \"%s\",", v11);
      v12 = sub_F7DC(*(const char **)(v14 + 208));
      fprintf(s, "\n\t\t\"pass\" : \"%s\"\n\t}", v12);
      if ( dword_77FC0 <= v3 )
        goto LABEL_24;
    }
    v6 = "";
LABEL_22:
    v1 = "";
LABEL_23:
    v34 = "";
    goto LABEL_10;
  }
LABEL_24:
  fwrite("\n]\n", 1u, 3u, s);
  if ( dword_72444 != 16 )
  {
    v23 = (const char **)&unk_7245C;
    while ( 1 )
    {
      v24 = _strdup(*(v23 - 7));
      v25 = strtok(v24, delim);
      if ( v25 )
        break;
LABEL_53:
      v23 += 7;
      free(v24);
      if ( *(v23 - 6) == (const char *)16 )
        goto LABEL_54;
    }
    while ( 1 )
    {
      if ( v25[1] == 45 && *(v23 - 1) != (const char *)&unk_9A558 )
      {
        v26 = (int)*(v23 - 6);
        if ( (v26 & 1) != 0
          && ((v27 = (int (__fastcall *)(_BYTE *))*(v23 - 5), v27 == sub_584B4) || v27 == sub_584C4)
          && **(v23 - 2) == (v27 == sub_584B4) )
        {
          fprintf(s, ",\n\"%s\" : true", v25 + 2);
        }
        else
        {
          if ( (v26 & 2) == 0 )
            goto LABEL_49;
          v28 = (char *(__fastcall *)(const char *, float *))*(v23 - 4);
          if ( (char *)v28 == (char *)sub_586A0
            || (char *)v28 == (char *)sub_15400
            || (char *)v28 == (char *)sub_15418
            || (char *)v28 == (char *)sub_15478
            || (char *)v28 == (char *)sub_1546C
            || (char *)v28 == (char *)sub_1540C
            || (char *)v28 == (char *)sub_15460
            || (char *)v28 == (char *)sub_15454
            || (char *)v28 == (char *)sub_15448
            || (char *)v28 == (char *)sub_1543C
            || (char *)v28 == (char *)sub_15430
            || (char *)v28 == (char *)sub_15424 )
          {
            fprintf(s, ",\n\"%s\" : \"%d\"", v25 + 2, *(_DWORD *)*(v23 - 2));
          }
          else
          {
            if ( v28 != sub_12138 && v28 != sub_120E8 )
            {
LABEL_49:
              if ( (v26 & 6) != 0 )
              {
                v29 = (const char **)*(v23 - 2);
                if ( v29 != (const char **)&unk_73D4C )
                {
                  if ( *v29 )
                  {
                    v30 = sub_F7DC(*v29);
                    fprintf(s, ",\n\"%s\" : \"%s\"", v25 + 2, v30);
                  }
                }
              }
              goto LABEL_28;
            }
            fprintf(s, ",\n\"%s\" : \"%.1f\"", v25 + 2, *(float *)*(v23 - 2));
          }
        }
      }
LABEL_28:
      v25 = strtok(0, delim);
      if ( !v25 )
        goto LABEL_53;
    }
  }
LABEL_54:
  v31 = dword_73D34;
  if ( dword_73D34 == 4 )
  {
    fwrite(",\n\"balance\" : true", 1u, 0x12u, s);
    v31 = dword_73D34;
    if ( dword_73D34 != 3 )
      goto LABEL_56;
  }
  else if ( dword_73D34 != 3 )
  {
    goto LABEL_56;
  }
  fwrite(",\n\"load-balance\" : true", 1u, 0x17u, s);
  v31 = dword_73D34;
LABEL_56:
  if ( v31 == 1 )
  {
    fwrite(",\n\"round-robin\" : true", 1u, 0x16u, s);
    v31 = dword_73D34;
  }
  if ( v31 == 2 )
    fprintf(s, ",\n\"rotate\" : \"%d\"", dword_78380);
  fwrite("\n}\n", 1u, 3u, s);
  v32 = dword_73A10;
  dword_73A10 = 0;
  if ( v32 )
  {
    do
    {
      v33 = *(_DWORD *)(v32 + 4);
      free(*(void **)v32);
      free((void *)v32);
      v32 = v33;
    }
    while ( v33 );
  }
}
