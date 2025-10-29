void __fastcall check_opt(const opt_table *entry)
{
  __int64 v1; // r2
  bool v2; // cc
  const char *v4; // r4
  const char *v5; // r1
  size_t v6; // r0
  opt_type type; // r5
  unsigned int v8; // r3
  int v9; // r3
  bool v10; // zf
  const char *v11; // r1
  const char *v12; // r1
  const char *v13; // r1
  const char *v14; // r1
  const char *v15; // r1
  const char *v16; // r1
  unsigned int len; // [sp+Ch] [bp-8h] BYREF

  v1 = *(_QWORD *)&entry->names;
  v2 = entry->type > (unsigned int)opt_type::OPT_PROCESSARG;
  if ( entry->type != opt_type::OPT_PROCESSARG )
    v2 = (unsigned int)(entry->type - 1) > 1;
  if ( v2 )
  {
    LOWORD(v16) = -19140;
    HIWORD(v16) = (unsigned int)"ange" >> 16;
    errx(1, v16, (_DWORD)v1);
  }
  if ( !entry->desc )
  {
    LOWORD(v15) = -19104;
    HIWORD(v15) = (unsigned int)"" >> 16;
    errx(1, v15, (_DWORD)v1);
  }
  if ( *(_BYTE *)v1 != 45 )
  {
    LOWORD(v14) = -19064;
    HIWORD(v14) = (unsigned int)"e %u" >> 16;
    errx(1, v14);
  }
  v4 = (const char *)(v1 + 1);
  LOWORD(v5) = -19144;
  HIWORD(v5) = (unsigned int)"of range" >> 16;
  v6 = strcspn((const char *)(v1 + 1), v5);
  for ( len = v6; ; v6 = len )
  {
    if ( *v4 == 45 )
    {
      if ( v6 == 1 )
      {
        LOWORD(v13) = -19028;
        HIWORD(v13) = (unsigned int)"t be NULL" >> 16;
        errx(1, v13, entry->names);
      }
      type = entry->type;
      ++opt_num_long;
    }
    else
    {
      if ( v6 != 1 )
      {
        LOWORD(v11) = -18992;
        HIWORD(v11) = (unsigned int)"n with '-'" >> 16;
        errx(1, v11, entry->names, v6 + 1, v4 - 1);
      }
      type = entry->type;
      v8 = (type - 2) & 0xFFFFFFFD;
      if ( !v8 )
        v8 = opt_num_short_arg;
      ++opt_num_short;
      if ( ((type - 2) & 0xFFFFFFFD) == 0 )
        opt_num_short_arg = v8 + 1;
    }
    if ( type == opt_type::OPT_NOARG )
    {
      v9 = (unsigned __int8)v4[v6];
      v10 = v9 == 61;
      if ( v9 != 61 )
        v10 = v9 == 32;
      if ( v10 )
      {
        LOWORD(v12) = -18952;
        HIWORD(v12) = (unsigned int)"on '--'" >> 16;
        errx(1, v12, entry->names, &v4[v6 + 1]);
      }
    }
    v4 = next_name(v4, &len);
    if ( !v4 )
      break;
  }
}
