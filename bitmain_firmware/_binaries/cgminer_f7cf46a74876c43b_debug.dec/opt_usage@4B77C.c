char *__fastcall opt_usage(const char *argv0, const char *extra)
{
  size_t v3; // r7
  opt_table *v4; // r4
  unsigned int v5; // r8
  size_t v6; // r7
  size_t v7; // r0
  size_t v8; // r7
  size_t v9; // r5
  const char *desc; // r11
  char *v11; // r0
  char *v12; // r4
  int v13; // r0
  char *v14; // r1
  char *v15; // r4
  char *v16; // r7
  const char *sopt; // r12
  int v18; // r8
  int v19; // r0
  char *v20; // r5
  unsigned int v21; // r3
  int v22; // r7
  unsigned int v23; // r8
  int v24; // r2
  unsigned int v25; // r4
  unsigned int v26; // r4
  char *v27; // r3
  opt_table *v28; // r3
  const char *v29; // r2
  int v30; // r0
  unsigned int v31; // r4
  char *v32; // r3
  char *v33; // r0
  char *v34; // r0
  int v36; // r2
  opt_table *v37; // r3
  __int16 *v39; // [sp+0h] [bp-74h]
  const char *v40; // [sp+4h] [bp-70h]
  char *s; // [sp+Ch] [bp-68h]
  char *v42; // [sp+10h] [bp-64h]
  char *ret; // [sp+14h] [bp-60h]
  char buf[84]; // [sp+1Ch] [bp-58h] BYREF

  v3 = opt_num_short + 20 + strlen(argv0);
  if ( extra )
  {
    v3 += strlen(extra);
    if ( !opt_count )
      goto LABEL_13;
    v4 = opt_table_0;
  }
  else
  {
    if ( !opt_count )
    {
      extra = &byte_59398;
      goto LABEL_13;
    }
    v36 = 0;
    v4 = opt_table_0;
    v37 = opt_table_0;
    do
    {
      ++v36;
      if ( (char *(__fastcall *)(const char *))v37->cb == opt_usage_and_exit )
      {
        extra = (const char *)v37->u.carg;
        if ( extra )
        {
          v3 += strlen((const char *)v37->u.carg);
          goto LABEL_4;
        }
      }
      ++v37;
    }
    while ( v36 != opt_count );
    extra = &byte_59398;
  }
LABEL_4:
  v5 = 0;
  v40 = extra;
  do
  {
    while ( 1 )
    {
      v9 = v3 + 6;
      desc = v4->desc;
      if ( v4->type != opt_type::OPT_SUBTABLE )
        break;
      ++v5;
      v3 += 3 + strlen(v4->desc);
      ++v4;
      if ( v5 >= opt_count )
        goto LABEL_12;
    }
    if ( desc != opt_hidden )
    {
      v6 = strlen(v4->names);
      v7 = strlen(desc) + v6 + v9;
      v8 = v7 + 118;
      if ( !v4->show )
        v8 = v7 + 21;
      v3 = v8 + 1;
    }
    ++v5;
    ++v4;
  }
  while ( v5 < opt_count );
LABEL_12:
  extra = v40;
LABEL_13:
  v11 = (char *)malloc(v3);
  v12 = v11;
  ret = v11;
  if ( v11 )
  {
    v13 = sprintf(v11, "Usage: %s", argv0);
    v14 = v12;
    v15 = &v12[v13];
    v16 = v15 + 3;
    strcpy(&v14[v13], " [-");
    sopt = first_sopt((unsigned int *)buf);
    if ( sopt )
    {
      v18 = 0;
      do
      {
        if ( opt_table_0[*(_DWORD *)buf].desc != opt_hidden )
          v16[v18++] = *sopt;
        sopt = next_sopt(sopt, (unsigned int *)buf);
      }
      while ( sopt );
      if ( v18 )
      {
        v15 = &v16[v18 + 1];
        *(_WORD *)&v16[v18] = 93;
      }
    }
    v19 = sprintf(v15, " %s", extra);
    v20 = &v15[v19 + 1];
    v39 = &word_58FE4;
    v21 = opt_count;
    *(_WORD *)&v15[v19] = 10;
    if ( v21 )
    {
      v22 = 0;
      v23 = 0;
      do
      {
        v28 = &opt_table_0[v22];
        v29 = opt_table_0[v22].desc;
        if ( v29 != opt_hidden )
        {
          if ( v28->type == opt_type::OPT_SUBTABLE )
          {
            v20 += sprintf(v20, "%s:\n", v29);
          }
          else
          {
            v30 = sprintf(v20, "%s", v28->names);
            v31 = v30;
            v32 = &v20[v30];
            if ( opt_table_0[v22].type == opt_type::OPT_HASARG )
            {
              v42 = &v20[v30];
              s = (char *)opt_table_0[v22].names;
              v33 = strchr(s, 32);
              v32 = v42;
              if ( !v33 )
              {
                v34 = strchr(s, 61);
                v32 = v42;
                if ( !v34 )
                {
                  v31 += 6;
                  strcpy(v42, " <arg>");
                  v32 = &v20[v31];
                }
              }
            }
            if ( v31 > 0x13 )
              v24 = 1;
            else
              v24 = 20 - v31;
            v25 = v31 + sprintf(v32, "%.*s", v24, "                    ", v39);
            v26 = v25 + sprintf(&v20[v25], "%s", opt_table_0[v22].desc);
            v27 = &v20[v26];
            if ( opt_table_0[v22].show )
            {
              strcpy(&buf[80], "...");
              opt_table_0[v22].show(buf, (const void *)opt_table_0[v22].u.tlen);
              v27 = &v20[v26 + sprintf(&v20[v26], " (default: %s)", buf)];
            }
            *(_WORD *)v27 = *v39;
            v20 = v27 + 1;
          }
        }
        ++v23;
        ++v22;
      }
      while ( opt_count > v23 );
    }
    *v20 = 0;
  }
  return ret;
}
