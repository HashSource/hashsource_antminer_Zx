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
  const char *v13; // r1
  int v14; // r0
  _DWORD *v15; // r3
  char *v16; // r1
  char *v17; // r4
  char *v18; // r7
  const char *sopt; // r12
  int v20; // r8
  const char *v21; // r1
  int v22; // r0
  _WORD *v23; // r3
  char *v24; // r5
  _WORD *v25; // r2
  unsigned int v26; // r3
  int v27; // r3
  const char *v28; // r2
  int v29; // r7
  unsigned int v30; // r8
  const char *v31; // r11
  int v32; // r2
  unsigned int v33; // r4
  unsigned int v34; // r4
  char *v35; // r3
  const char *v36; // r1
  opt_table *v37; // r3
  int v38; // r0
  unsigned int v39; // r4
  char *v40; // r3
  char *v41; // r0
  char *v42; // r0
  int *v43; // r2
  int v44; // r0
  __int16 v45; // r1
  const char *v47; // r1
  _WORD *v48; // r3
  char *(*v49)(void *); // r0
  int v50; // r2
  opt_table *v51; // r3
  _WORD *v53; // [sp+0h] [bp-74h]
  const char *v54; // [sp+4h] [bp-70h]
  int v55; // [sp+4h] [bp-70h]
  const char *v56; // [sp+8h] [bp-6Ch]
  char *s; // [sp+Ch] [bp-68h]
  char *v58; // [sp+10h] [bp-64h]
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
      extra = &byte_59414;
      goto LABEL_13;
    }
    LOWORD(v49) = -20755;
    v50 = 0;
    v4 = opt_table_0;
    v51 = opt_table_0;
    do
    {
      ++v50;
      HIWORD(v49) = ((unsigned int)&loc_4AEBA + 3) >> 16;
      if ( v51->cb == v49 )
      {
        extra = (const char *)v51->u.carg;
        if ( extra )
        {
          v3 += strlen((const char *)v51->u.carg);
          goto LABEL_4;
        }
      }
      ++v51;
    }
    while ( v50 != opt_count );
    extra = &byte_59414;
  }
LABEL_4:
  v5 = 0;
  v54 = extra;
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
  extra = v54;
LABEL_13:
  v11 = (char *)malloc(v3);
  v12 = v11;
  ret = v11;
  if ( v11 )
  {
    LOWORD(v13) = -18744;
    HIWORD(v13) = (unsigned int)"t" >> 16;
    v14 = sprintf(v11, v13, argv0);
    LOWORD(v15) = -18732;
    HIWORD(v15) = (unsigned int)" an argument" >> 16;
    v16 = v12;
    v17 = &v12[v14];
    v18 = v17 + 3;
    *(_DWORD *)&v16[v14] = *v15;
    sopt = first_sopt((unsigned int *)buf);
    if ( sopt )
    {
      v20 = 0;
      do
      {
        if ( opt_table_0[*(_DWORD *)buf].desc != opt_hidden )
          v18[v20++] = *sopt;
        sopt = next_sopt(sopt, (unsigned int *)buf);
      }
      while ( sopt );
      if ( v20 )
      {
        LOWORD(v48) = -25844;
        HIWORD(v48) = (unsigned int)"echo %d > /sys/class/gpio/gpio%d/value" >> 16;
        v17 = &v18[v20 + 1];
        *(_WORD *)&v18[v20] = *v48;
      }
    }
    LOWORD(v21) = -1740;
    HIWORD(v21) = (unsigned int)"rror" >> 16;
    v22 = sprintf(v17, v21, extra);
    LOWORD(v23) = -28576;
    HIWORD(v23) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
    v24 = &v17[v22 + 1];
    v25 = v23;
    v53 = v23;
    v26 = opt_count;
    *(_WORD *)&v17[v22] = *v25;
    if ( v26 )
    {
      LOWORD(v27) = -18712;
      LOWORD(v28) = 16348;
      v29 = 0;
      LOWORD(v31) = 20752;
      HIWORD(v27) = (unsigned int)"cognized option" >> 16;
      HIWORD(v28) = (unsigned int)"get)" >> 16;
      v30 = 0;
      HIWORD(v31) = (unsigned int)"mcast join failed (%s)%s" >> 16;
      v55 = v27;
      v56 = v28;
      do
      {
        v37 = &opt_table_0[v29];
        if ( opt_table_0[v29].desc != opt_hidden )
        {
          if ( v37->type == opt_type::OPT_SUBTABLE )
          {
            LOWORD(v47) = -18728;
            HIWORD(v47) = (unsigned int)"argument" >> 16;
            v24 += sprintf(v24, v47);
          }
          else
          {
            v38 = sprintf(v24, v31, v37->names);
            v39 = v38;
            v40 = &v24[v38];
            if ( opt_table_0[v29].type == opt_type::OPT_HASARG )
            {
              v58 = &v24[v38];
              s = (char *)opt_table_0[v29].names;
              v41 = strchr(s, 32);
              v40 = v58;
              if ( !v41 )
              {
                v42 = strchr(s, 61);
                v40 = v58;
                if ( !v42 )
                {
                  LOWORD(v43) = -18720;
                  v39 += 6;
                  HIWORD(v43) = (unsigned int)"" >> 16;
                  v44 = *v43;
                  v45 = *((_WORD *)v43 + 2);
                  LOBYTE(v43) = *((_BYTE *)v43 + 6);
                  *(_DWORD *)v58 = v44;
                  *((_WORD *)v58 + 2) = v45;
                  v58[6] = (char)v43;
                  v40 = &v24[v39];
                }
              }
            }
            if ( v39 > 0x13 )
              v32 = 1;
            else
              v32 = 20 - v39;
            v33 = v39 + sprintf(v40, v56, v32, v55, v53);
            v34 = v33 + sprintf(&v24[v33], v31, opt_table_0[v29].desc);
            v35 = &v24[v34];
            if ( opt_table_0[v29].show )
            {
              strcpy(&buf[80], "...");
              opt_table_0[v29].show(buf, (const void *)opt_table_0[v29].u.tlen);
              LOWORD(v36) = -18688;
              HIWORD(v36) = (unsigned int)"s" >> 16;
              v35 = &v24[v34 + sprintf(&v24[v34], v36, buf)];
            }
            *(_WORD *)v35 = *v53;
            v24 = v35 + 1;
          }
        }
        ++v30;
        ++v29;
      }
      while ( opt_count > v30 );
    }
    *v24 = 0;
  }
  return ret;
}
