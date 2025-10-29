int __fastcall parse_one(int *argc, char **argv, unsigned int *offset, void (*errlog)(const char *, ...))
{
  const char *v5; // r0
  int result; // r0
  char **v10; // r6
  char **v11; // r3
  unsigned int v12; // r4
  int v13; // t1
  const char *v14; // r0
  char *v15; // r11
  unsigned int v16; // r1
  unsigned int v17; // r12
  opt_table *v18; // r3
  unsigned int v19; // r0
  opt_table *v20; // r3
  opt_type type; // r0
  char *v22; // r7
  char *v23; // r11
  int v24; // r7
  const char *v25; // r0
  unsigned int v26; // r11
  const char *v27; // r8
  char *v28; // r7
  unsigned int v29; // r4
  unsigned int v30; // r1
  const char *v31; // r6
  size_t v32; // r2
  const char *v33; // r0
  const char *v34; // r0
  int v35; // r4
  const char *v36; // r0
  char *v37; // r2
  unsigned int v38; // r7
  const char *v39; // r0
  const char *v40; // r3
  const char *v41; // r1
  const char *v42; // r0
  const char *o; // [sp+8h] [bp-14h]
  unsigned int *offseta; // [sp+Ch] [bp-10h]
  unsigned int i; // [sp+10h] [bp-Ch] BYREF
  unsigned int len[2]; // [sp+14h] [bp-8h] BYREF

  LOWORD(v5) = -18876;
  HIWORD(v5) = (unsigned int)"uments '%s'" >> 16;
  if ( getenv(v5) )
  {
    result = (int)argv[1];
    v10 = argv + 1;
    if ( result )
    {
      if ( *(_BYTE *)result != 45 )
        return 0;
      v12 = 1;
      if ( *(_BYTE *)(result + 1) == 45 )
      {
LABEL_32:
        v24 = *(unsigned __int8 *)(result + 2);
        if ( !*(_BYTE *)(result + 2) )
        {
          consume_option(argc, argv, v12);
          return v24;
        }
        if ( *offset )
        {
          LOWORD(v40) = -18888;
          LOWORD(v41) = -18860;
          LOWORD(v42) = -18848;
          HIWORD(v40) = (unsigned int)"not take arguments '%s'" >> 16;
          HIWORD(v41) = (unsigned int)"lid argument '%s'" >> 16;
          HIWORD(v42) = (unsigned int)" '%s'" >> 16;
          _assert_fail(v42, v41, 0x3Bu, v40);
        }
        v25 = first_lopt(&i, len);
        if ( v25 )
        {
          offseta = offset;
          v26 = v12;
          v27 = v25;
          do
          {
            v28 = *v10;
            v29 = len[0];
            if ( !strncmp(*v10 + 2, v27, len[0]) )
            {
              v30 = v29 + 2;
              if ( v28[v29 + 2] == 61 )
              {
                v37 = v28;
                v17 = i;
                v38 = v29;
                v12 = v26;
                v15 = v37;
                o = v27 - 2;
                offset = offseta;
                v22 = &v37[v38 + 3];
                len[0] = v30;
                v20 = &opt_table_0[i];
                type = v20->type;
                if ( type != opt_type::OPT_NOARG )
                {
                  if ( !v22 )
                  {
LABEL_44:
                    v16 = *offset;
                    goto LABEL_18;
                  }
                  goto LABEL_21;
                }
                if ( v22 )
                {
                  LOWORD(v39) = -18832;
                  HIWORD(v39) = (unsigned int)"e" >> 16;
                  errlog(v39, *argv, v30, o, "doesn't allow an argument");
                  return -1;
                }
LABEL_36:
                v22 = 0;
                v23 = v20->cb(v20->u.tlen);
                goto LABEL_24;
              }
              if ( !v28[v29 + 2] )
              {
                v17 = i;
                o = v27 - 2;
                v12 = v26;
                offset = offseta;
                v15 = v28;
                len[0] = v30;
                v20 = &opt_table_0[i];
                type = v20->type;
                if ( type == opt_type::OPT_NOARG )
                  goto LABEL_36;
                goto LABEL_44;
              }
            }
            v27 = next_lopt(v27, &i, len);
          }
          while ( v27 );
        }
LABEL_46:
        v31 = *v10;
        v32 = strlen(v31);
        LOWORD(v33) = -18832;
        HIWORD(v33) = (unsigned int)"e" >> 16;
        errlog(v33, *argv, v32, v31, "unrecognized option");
        return -1;
      }
LABEL_15:
      v14 = first_sopt(&i);
      if ( !v14 )
        goto LABEL_46;
      v15 = *v10;
      v16 = *offset + 1;
      if ( *(unsigned __int8 *)v14 != (unsigned __int8)(*v10)[v16] )
      {
        do
        {
          v14 = next_sopt(v14, &i);
          if ( !v14 )
            goto LABEL_46;
          v16 = *offset + 1;
        }
        while ( (*v10)[v16] != *v14 );
        v15 = *v10;
      }
      v17 = i;
      v18 = opt_table_0;
      o = v14 - 1;
      v19 = i;
      *offset = v16;
      len[0] = 2;
      v20 = &v18[v19];
      type = v20->type;
      if ( type == opt_type::OPT_NOARG )
        goto LABEL_36;
LABEL_18:
      if ( v16 )
      {
        v22 = &v15[v16 + 1];
        if ( *v22 )
        {
          *offset = 0;
          goto LABEL_21;
        }
      }
      v22 = argv[v12 + 1];
      if ( !v22 )
      {
        LOWORD(v35) = -18788;
        LOWORD(v36) = -18832;
        HIWORD(v35) = (unsigned int)"" >> 16;
        HIWORD(v36) = (unsigned int)"e" >> 16;
        errlog(v36, *argv, len[0], o, v35);
        return -1;
      }
LABEL_21:
      if ( type == opt_type::OPT_PROCESSARG )
      {
        opt_set_charp(v22, (char **)v20->u.carg);
        v17 = i;
      }
      v23 = opt_table_0[v17].cb_arg(v22, opt_table_0[v17].u.tlen);
LABEL_24:
      if ( v23 )
      {
        LOWORD(v34) = -18832;
        HIWORD(v34) = (unsigned int)"e" >> 16;
        errlog(v34, *argv, len[0], o, v23);
        free(v23);
        return -1;
      }
      if ( *offset )
      {
        if ( (*v10)[*offset + 1] )
          return 1;
        *offset = 0;
      }
      consume_option(argc, argv, v12);
      if ( v22 )
      {
        if ( *v10 == v22 )
          consume_option(argc, argv, v12);
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
        v10 = argv + 1;
        v12 = 1;
LABEL_14:
        if ( *(_BYTE *)(result + 1) == 45 )
          goto LABEL_32;
        goto LABEL_15;
      }
      v11 = argv + 2;
      v12 = 1;
      while ( 1 )
      {
        v10 = v11;
        v13 = (int)*v11++;
        result = v13;
        ++v12;
        if ( !v13 )
          break;
        if ( *(_BYTE *)result == 45 )
          goto LABEL_14;
      }
    }
  }
  return result;
}
