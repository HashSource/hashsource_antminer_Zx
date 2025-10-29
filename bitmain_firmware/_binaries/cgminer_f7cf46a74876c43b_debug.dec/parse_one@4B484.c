int __fastcall parse_one(int *argc, char **argv, unsigned int *offset, void (*errlog)(const char *, ...))
{
  int result; // r0
  char **v9; // r6
  char **v10; // r3
  unsigned int v11; // r4
  int v12; // t1
  const char *v13; // r0
  char *v14; // r11
  unsigned int v15; // r1
  unsigned int v16; // r12
  opt_table *v17; // r3
  unsigned int v18; // r0
  opt_table *v19; // r3
  opt_type type; // r0
  char *v21; // r7
  char *v22; // r11
  int v23; // r7
  const char *v24; // r0
  unsigned int v25; // r11
  const char *v26; // r8
  char *v27; // r7
  unsigned int v28; // r4
  unsigned int v29; // r1
  const char *v30; // r6
  size_t v31; // r0
  char *v32; // r2
  unsigned int v33; // r7
  const char *o; // [sp+8h] [bp-14h]
  unsigned int *offseta; // [sp+Ch] [bp-10h]
  unsigned int i; // [sp+10h] [bp-Ch] BYREF
  unsigned int len[2]; // [sp+14h] [bp-8h] BYREF

  if ( getenv("POSIXLY_CORRECT") )
  {
    result = (int)argv[1];
    v9 = argv + 1;
    if ( result )
    {
      if ( *(_BYTE *)result != 45 )
        return 0;
      v11 = 1;
      if ( *(_BYTE *)(result + 1) == 45 )
      {
LABEL_32:
        v23 = *(unsigned __int8 *)(result + 2);
        if ( !*(_BYTE *)(result + 2) )
        {
          consume_option(argc, argv, v11);
          return v23;
        }
        if ( *offset )
          _assert_fail("*offset == 0", "opt/parse.c", 0x3Bu, "parse_one");
        v24 = first_lopt(&i, len);
        if ( v24 )
        {
          offseta = offset;
          v25 = v11;
          v26 = v24;
          do
          {
            v27 = *v9;
            v28 = len[0];
            if ( !strncmp(*v9 + 2, v26, len[0]) )
            {
              v29 = v28 + 2;
              if ( v27[v28 + 2] == 61 )
              {
                v32 = v27;
                v16 = i;
                v33 = v28;
                v11 = v25;
                v14 = v32;
                o = v26 - 2;
                offset = offseta;
                v21 = &v32[v33 + 3];
                len[0] = v29;
                v19 = &opt_table_0[i];
                type = v19->type;
                if ( type != opt_type::OPT_NOARG )
                {
                  if ( !v21 )
                  {
LABEL_44:
                    v15 = *offset;
                    goto LABEL_18;
                  }
                  goto LABEL_21;
                }
                if ( v21 )
                {
                  errlog("%s: %.*s: %s", *argv, v29, o, "doesn't allow an argument");
                  return -1;
                }
LABEL_36:
                v21 = 0;
                v22 = v19->cb(v19->u.tlen);
                goto LABEL_24;
              }
              if ( !v27[v28 + 2] )
              {
                v16 = i;
                o = v26 - 2;
                v11 = v25;
                offset = offseta;
                v14 = v27;
                len[0] = v29;
                v19 = &opt_table_0[i];
                type = v19->type;
                if ( type == opt_type::OPT_NOARG )
                  goto LABEL_36;
                goto LABEL_44;
              }
            }
            v26 = next_lopt(v26, &i, len);
          }
          while ( v26 );
        }
LABEL_46:
        v30 = *v9;
        v31 = strlen(v30);
        errlog("%s: %.*s: %s", *argv, v31, v30, "unrecognized option");
        return -1;
      }
LABEL_15:
      v13 = first_sopt(&i);
      if ( !v13 )
        goto LABEL_46;
      v14 = *v9;
      v15 = *offset + 1;
      if ( *(unsigned __int8 *)v13 != (unsigned __int8)(*v9)[v15] )
      {
        do
        {
          v13 = next_sopt(v13, &i);
          if ( !v13 )
            goto LABEL_46;
          v15 = *offset + 1;
        }
        while ( (*v9)[v15] != *v13 );
        v14 = *v9;
      }
      v16 = i;
      v17 = opt_table_0;
      o = v13 - 1;
      v18 = i;
      *offset = v15;
      len[0] = 2;
      v19 = &v17[v18];
      type = v19->type;
      if ( type == opt_type::OPT_NOARG )
        goto LABEL_36;
LABEL_18:
      if ( v15 )
      {
        v21 = &v14[v15 + 1];
        if ( *v21 )
        {
          *offset = 0;
          goto LABEL_21;
        }
      }
      v21 = argv[v11 + 1];
      if ( !v21 )
      {
        errlog("%s: %.*s: %s", *argv, len[0], o, "requires an argument");
        return -1;
      }
LABEL_21:
      if ( type == opt_type::OPT_PROCESSARG )
      {
        opt_set_charp(v21, (char **)v19->u.carg);
        v16 = i;
      }
      v22 = opt_table_0[v16].cb_arg(v21, opt_table_0[v16].u.tlen);
LABEL_24:
      if ( v22 )
      {
        errlog("%s: %.*s: %s", *argv, len[0], o, v22);
        free(v22);
        return -1;
      }
      if ( *offset )
      {
        if ( (*v9)[*offset + 1] )
          return 1;
        *offset = 0;
      }
      consume_option(argc, argv, v11);
      if ( v21 )
      {
        if ( *v9 == v21 )
          consume_option(argc, argv, v11);
      }
      return 1;
    }
  }
  else
  {
    result = (int)argv[1];
    if ( result )
    {
      if ( *(_BYTE *)result == 45 )
      {
        v9 = argv + 1;
        v11 = 1;
LABEL_14:
        if ( *(_BYTE *)(result + 1) == 45 )
          goto LABEL_32;
        goto LABEL_15;
      }
      v10 = argv + 2;
      v11 = 1;
      while ( 1 )
      {
        v9 = v10;
        v12 = (int)*v10++;
        result = v12;
        ++v11;
        if ( !v12 )
          break;
        if ( *(_BYTE *)result == 45 )
          goto LABEL_14;
      }
    }
  }
  return result;
}
