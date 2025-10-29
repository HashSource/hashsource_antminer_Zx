unsigned int __fastcall sub_44DA4(int a1, int a2)
{
  const void **v2; // r7
  int v5; // r0
  bool v6; // zf
  unsigned int v7; // r4
  bool v8; // zf
  bool v9; // zf
  bool v10; // zf
  bool v11; // zf
  bool v12; // cc
  unsigned __int8 i; // r1
  int v14; // r2
  int v15; // r3
  int v17; // r0
  const char *v18; // r4
  int v19; // r0
  bool v20; // zf
  const char *v21; // r4
  int *v22; // r7
  __int64 v23; // r2
  int v24; // r0
  int v25; // r1
  _DWORD *v26; // r4
  int v27; // r0
  bool v28; // zf
  bool v29; // zf
  bool v30; // zf
  double v31; // r2
  bool v32; // zf
  int v33; // r8
  bool v34; // cc
  _BYTE *v35; // r0
  _BYTE *v36; // r8
  unsigned __int8 *v37; // r7
  int v38; // r2
  unsigned int v39; // r2
  int v40; // r0
  int v41; // r2
  int v42; // r0
  int v43; // r0
  int v44; // [sp+8h] [bp-24h]
  int v45; // [sp+Ch] [bp-20h]
  _BYTE src[4]; // [sp+14h] [bp-18h] BYREF
  size_t n; // [sp+18h] [bp-14h] BYREF
  char *endptr; // [sp+1Ch] [bp-10h] BYREF
  double v49; // [sp+20h] [bp-Ch] BYREF

  v2 = (const void **)(a1 + 40);
  sub_45EF8(a1 + 40);
  if ( *(_DWORD *)(a1 + 52) == 256 )
  {
    sub_45E0C(*(void **)(a1 + 56));
    *(_DWORD *)(a1 + 56) = 0;
  }
  while ( 1 )
  {
    v5 = sub_44BA4(a1, a2);
    v6 = v5 == 32;
    if ( v5 != 32 )
      v6 = v5 == 9;
    v7 = v5;
    if ( !v6 )
    {
      v8 = v5 == 10;
      if ( v5 != 10 )
        v8 = v5 == 13;
      if ( !v8 )
        break;
    }
  }
  if ( v5 == -1 )
  {
    *(_DWORD *)(a1 + 52) = 0;
    return 0;
  }
  if ( v5 == -2 )
  {
LABEL_33:
    v7 = -1;
LABEL_34:
    *(_DWORD *)(a1 + 52) = v7;
    return v7;
  }
  DataWriter::WriteByte(v2, v5);
  v9 = v7 == 123;
  if ( v7 != 123 )
    v9 = v7 == 125;
  if ( v9 )
    goto LABEL_34;
  v10 = v7 == 91;
  if ( v7 != 91 )
    v10 = v7 == 93;
  if ( v10 )
    goto LABEL_34;
  v11 = v7 == 58;
  if ( v7 != 58 )
    v11 = v7 == 44;
  if ( v11 )
    goto LABEL_34;
  if ( v7 != 34 )
  {
    v12 = v7 > 0x2D;
    if ( v7 != 45 )
      v12 = v7 - 48 > 9;
    if ( !v12 )
    {
      *(_DWORD *)(a1 + 52) = -1;
      if ( v7 == 45 )
        v7 = sub_44D74(a1, a2);
      if ( v7 == 48 )
      {
        v19 = sub_44D74(a1, a2);
        if ( (unsigned int)(v19 - 48) <= 9 )
          goto LABEL_97;
      }
      else
      {
        if ( v7 - 48 > 9 )
        {
          sub_44D28((_DWORD *)a1, (_DWORD *)v7);
          return *(_DWORD *)(a1 + 52);
        }
        do
          v19 = sub_44D74(a1, a2);
        while ( (unsigned int)(v19 - 48) <= 9 );
      }
      v20 = v19 == 69;
      if ( v19 != 69 )
        v20 = v19 == 46;
      if ( v20 )
      {
        if ( v19 == 46 )
        {
          v43 = sub_44BA4(a1, a2);
          if ( (unsigned int)(v43 - 48) > 9 )
          {
            sub_44AEC((_DWORD *)a1, v43);
            return *(_DWORD *)(a1 + 52);
          }
          DataWriter::WriteByte(v2, v43);
          do
            v19 = sub_44D74(a1, a2);
          while ( (unsigned int)(v19 - 48) <= 9 );
        }
        if ( (v19 & 0xFFFFFFDF) != 0x45 )
          goto LABEL_79;
      }
      else if ( v19 != 101 )
      {
        sub_44D28((_DWORD *)a1, (_DWORD *)v19);
        v21 = (const char *)sub_45F0C((int)v2);
        v22 = _errno_location();
        *v22 = 0;
        v23 = strtoll(v21, &endptr, 10);
        if ( *v22 == 34 )
        {
          if ( v23 >= 0 )
            sub_448AC(a2, (_DWORD *)a1, "too big integer");
          else
            sub_448AC(a2, (_DWORD *)a1, "too big negative integer");
          return *(_DWORD *)(a1 + 52);
        }
        else
        {
          if ( endptr != &v21[*(_DWORD *)(a1 + 44)] )
            _assert_fail("end == saved_text + lex->saved_text.length", "load.c", 0x206u, "lex_scan_number");
          *(_QWORD *)(a1 + 56) = v23;
          v7 = 257;
          *(_DWORD *)(a1 + 52) = 257;
        }
        return v7;
      }
      v19 = sub_44D74(a1, a2);
      v32 = v19 == 43;
      if ( v19 != 43 )
        v32 = v19 == 45;
      if ( v32 )
        v19 = sub_44D74(a1, a2);
      if ( (unsigned int)(v19 - 48) <= 9 )
      {
        do
          v19 = sub_44D74(a1, a2);
        while ( (unsigned int)(v19 - 48) <= 9 );
LABEL_79:
        sub_44D28((_DWORD *)a1, (_DWORD *)v19);
        if ( sub_46060((int)v2, &v49) )
        {
          sub_448AC(a2, (_DWORD *)a1, "real number overflow");
          return *(_DWORD *)(a1 + 52);
        }
        else
        {
          v31 = v49;
          v7 = 258;
          *(_DWORD *)(a1 + 52) = 258;
          *(double *)(a1 + 56) = v31;
        }
        return v7;
      }
LABEL_97:
      sub_44D28((_DWORD *)a1, (_DWORD *)v19);
      return *(_DWORD *)(a1 + 52);
    }
    if ( (v7 & 0xFFFFFFDF) - 65 <= 0x19 )
    {
      do
        v17 = sub_44D74(a1, a2);
      while ( (v17 & 0xFFFFFFDF) - 65 <= 0x19 );
      sub_44D28((_DWORD *)a1, (_DWORD *)v17);
      v18 = (const char *)sub_45F0C((int)v2);
      if ( !strcmp(v18, "true") )
      {
        v7 = 259;
        *(_DWORD *)(a1 + 52) = 259;
        return v7;
      }
      if ( !strcmp(v18, "false") )
      {
        v7 = 260;
        *(_DWORD *)(a1 + 52) = 260;
        return v7;
      }
      if ( !strcmp(v18, "null") )
      {
        v7 = 261;
        *(_DWORD *)(a1 + 52) = 261;
        return v7;
      }
    }
    else
    {
      for ( i = *(_BYTE *)(a1 + *(_DWORD *)(a1 + 16) + 8); i; i = *(_BYTE *)(a1 + v15 + 8) )
      {
        DataWriter::WriteByte(v2, i);
        v14 = *(_DWORD *)(a1 + 36);
        v15 = *(_DWORD *)(a1 + 16) + 1;
        *(_DWORD *)(a1 + 16) = v15;
        *(_DWORD *)(a1 + 36) = v14 + 1;
      }
    }
    goto LABEL_33;
  }
  v24 = a1;
  v25 = a2;
  *(_DWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 52) = -1;
LABEL_58:
  v26 = (_DWORD *)sub_44D74(v24, v25);
LABEL_59:
  while ( v26 != (_DWORD *)34 )
  {
    if ( v26 == (_DWORD *)-2 )
      goto LABEL_104;
    if ( v26 == (_DWORD *)-1 )
    {
      sub_448AC(a2, (_DWORD *)a1, "premature end of input");
      v35 = *(_BYTE **)(a1 + 56);
      goto LABEL_102;
    }
    v24 = a1;
    if ( (unsigned int)v26 <= 0x1F )
    {
      sub_44D28((_DWORD *)a1, v26);
      if ( v26 == (_DWORD *)10 )
        sub_448AC(a2, (_DWORD *)a1, "unexpected newline");
      else
        sub_448AC(a2, (_DWORD *)a1, "control character 0x%x", v26);
      v35 = *(_BYTE **)(a1 + 56);
      goto LABEL_102;
    }
    v25 = a2;
    if ( v26 != (_DWORD *)92 )
      goto LABEL_58;
    v27 = sub_44D74(a1, a2);
    if ( v27 == 117 )
    {
      v33 = 4;
      v26 = (_DWORD *)sub_44D74(a1, a2);
      while ( 1 )
      {
        v34 = (unsigned int)v26 - 65 > 5;
        if ( (unsigned int)v26 - 65 > 5 )
          v34 = (unsigned int)(v26 - 12) > 9;
        if ( v34 && (unsigned int)v26 - 97 > 5 )
          break;
        --v33;
        v26 = (_DWORD *)sub_44D74(a1, a2);
        if ( !v33 )
          goto LABEL_59;
      }
LABEL_149:
      sub_448AC(a2, (_DWORD *)a1, "invalid escape");
      v35 = *(_BYTE **)(a1 + 56);
      goto LABEL_102;
    }
    v28 = v27 == 34;
    if ( v27 != 34 )
      v28 = v27 == 92;
    if ( !v28 )
    {
      v29 = v27 == 47;
      if ( v27 != 47 )
        v29 = v27 == 98;
      if ( !v29 && (v27 & 0xFFFFFFF7) != 0x66 )
      {
        v30 = v27 == 114;
        if ( v27 != 114 )
          v30 = v27 == 116;
        if ( !v30 )
          goto LABEL_149;
      }
    }
    v26 = (_DWORD *)sub_44D74(a1, a2);
  }
  v35 = sub_45DE4(*(_DWORD *)(a1 + 44) + 1);
  v36 = v35;
  *(_DWORD *)(a1 + 56) = v35;
  if ( !v35 )
    goto LABEL_102;
  v37 = (unsigned __int8 *)(sub_45F0C((int)v2) + 1);
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v38 = *v37;
        if ( v38 == 34 )
        {
          v7 = 256;
          *v36 = 0;
          *(_DWORD *)(a1 + 52) = 256;
          return v7;
        }
        if ( v38 == 92 )
          break;
        *v36++ = v38;
        ++v37;
      }
      v39 = v37[1];
      if ( v39 == 117 )
        break;
      if ( v39 == 102 )
      {
        *v36 = 12;
        goto LABEL_122;
      }
      if ( v39 > 0x66 )
      {
        switch ( v39 )
        {
          case 'r':
            *v36 = 13;
            break;
          case 't':
            *v36 = 9;
            break;
          case 'n':
            *v36 = 10;
            break;
          default:
            goto LABEL_117;
        }
      }
      else
      {
        if ( v39 == 92 )
          goto LABEL_135;
        if ( v39 <= 0x5C )
        {
          if ( v39 != 34 && v39 != 47 )
LABEL_117:
            _assert_fail(word_50574, "load.c", 0x1BCu, "lex_scan_string");
LABEL_135:
          *v36 = v39;
          goto LABEL_122;
        }
        if ( v39 != 98 )
          goto LABEL_117;
        *v36 = 8;
      }
LABEL_122:
      ++v36;
      v37 += 2;
    }
    v40 = sub_44A44(v37 + 1);
    v41 = v40;
    if ( (unsigned int)(v40 - 55296) > 0x3FF )
      break;
    if ( v37[6] != 92 || v37[7] != 117 )
    {
LABEL_103:
      sub_448AC(a2, (_DWORD *)a1, "invalid Unicode '\\u%04X'", v40);
      goto LABEL_104;
    }
    v44 = v40 - 55296;
    v45 = v40;
    v42 = sub_44A44(v37 + 7);
    v37 += 12;
    if ( (unsigned int)(v42 - 56320) > 0x3FF )
    {
      sub_448AC(a2, (_DWORD *)a1, "invalid Unicode '\\u%04X\\u%04X'", v45, v42);
      goto LABEL_104;
    }
    v41 = v42 - 56320 + (v44 << 10) + 0x10000;
LABEL_131:
    if ( sub_46254(v41, src, &n) )
      _assert_fail(word_50574, "load.c", 0x1AEu, "lex_scan_string");
    memcpy(v36, src, n);
    v36 += n;
  }
  if ( (unsigned int)(v40 - 56320) <= 0x3FF )
    goto LABEL_103;
  if ( v40 )
  {
    v37 += 6;
    goto LABEL_131;
  }
  sub_448AC(a2, (_DWORD *)a1, "\\u0000 is not allowed");
LABEL_104:
  v35 = *(_BYTE **)(a1 + 56);
LABEL_102:
  sub_45E0C(v35);
  return *(_DWORD *)(a1 + 52);
}
