int *__fastcall sub_560B8(double a1, int a2)
{
  int v2; // r4
  int v3; // r3
  unsigned int v4; // r8
  int *v6; // r7
  int v8; // r3
  void *v9; // r10
  int *v10; // r0
  int *v11; // r6
  int v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r3
  int *v19; // r0
  int v20; // r3
  int v21; // r3
  void **v22; // r0
  double v23; // r0
  int v24; // r3
  int v25; // r3
  double v26; // [sp+0h] [bp-Ch] BYREF

  v2 = LODWORD(a1);
  v3 = *(_DWORD *)(LODWORD(a1) + 52);
  LODWORD(a1) = 257;
  v4 = HIDWORD(a1);
  if ( v3 != 257 )
  {
    if ( v3 > 257 )
    {
      if ( v3 == 259 )
        return (int *)sub_57778();
      if ( v3 < 259 )
        return (int *)sub_57654(a1);
      if ( v3 == 260 )
        return (int *)sub_57784();
      if ( v3 == 261 )
        return (int *)sub_57790();
LABEL_7:
      v6 = 0;
      sub_553EC(a2, (_DWORD *)v2, "unexpected token");
      return v6;
    }
    if ( v3 == 91 )
    {
      v6 = sub_57338();
      if ( v6 )
      {
        sub_558E4(v2, a2);
        v16 = *(_DWORD *)(v2 + 52);
        if ( v16 == 93 )
          return v6;
        if ( v16 )
        {
          while ( 1 )
          {
            v19 = sub_560B8(COERCE_DOUBLE(__PAIR64__(v4, v2)), a2);
            v11 = v19;
            if ( !v19 )
              break;
            if ( v19[1] != -1 )
              ++v19[1];
            if ( sub_57AA0(v6, v19) )
            {
              v24 = v11[1];
              if ( v24 != -1 )
              {
LABEL_60:
                v25 = v24 - 1;
                v11[1] = v25;
                if ( !v25 )
                  sub_5779C((void **)v11);
              }
              goto LABEL_49;
            }
            v17 = v11[1];
            if ( v17 != -1 )
            {
              v11[1] = v17 - 1;
              if ( v17 == 1 )
                sub_5779C((void **)v11);
            }
            sub_558E4(v2, a2);
            v18 = *(_DWORD *)(v2 + 52);
            if ( v18 != 44 )
            {
              if ( v18 == 93 )
                return v6;
              goto LABEL_63;
            }
            sub_558E4(v2, a2);
            if ( !*(_DWORD *)(v2 + 52) )
              goto LABEL_63;
          }
        }
        else
        {
LABEL_63:
          sub_553EC(a2, (_DWORD *)v2, "']' expected");
        }
        goto LABEL_49;
      }
    }
    else
    {
      if ( v3 <= 91 )
      {
        if ( v3 == -1 )
        {
          v6 = 0;
          sub_553EC(a2, (_DWORD *)v2, "invalid token");
          return v6;
        }
        goto LABEL_7;
      }
      if ( v3 != 123 )
      {
        if ( v3 == 256 )
          return sub_574A4(*(const char **)(v2 + 56));
        goto LABEL_7;
      }
      v6 = sub_57160();
      if ( v6 )
      {
        sub_558E4(v2, a2);
        v8 = *(_DWORD *)(v2 + 52);
        if ( v8 == 125 )
          return v6;
        if ( v8 != 256 )
        {
LABEL_64:
          sub_553EC(a2, (_DWORD *)v2, "string or '}' expected");
          goto LABEL_49;
        }
        v9 = *(void **)(v2 + 56);
        *(_DWORD *)(v2 + 56) = 0;
        if ( v9 )
        {
          while ( 1 )
          {
            if ( (v4 & 1) != 0 && sub_571D8(v6, (char *)v9) )
            {
              sub_5694C(v9);
              sub_553EC(a2, (_DWORD *)v2, "duplicate object key");
              goto LABEL_49;
            }
            sub_558E4(v2, a2);
            if ( *(_DWORD *)(v2 + 52) != 58 )
            {
              sub_5694C(v9);
              sub_553EC(a2, (_DWORD *)v2, "':' expected");
              goto LABEL_49;
            }
            sub_558E4(v2, a2);
            v10 = sub_560B8(COERCE_DOUBLE(__PAIR64__(v4, v2)), a2);
            v11 = v10;
            if ( !v10 )
            {
              sub_5694C(v9);
              goto LABEL_49;
            }
            v12 = v10[1];
            if ( v12 != -1 )
              v10[1] = v12 + 1;
            if ( sub_57BD8(v6, (char *)v9, (int)v10) )
            {
              sub_5694C(v9);
              v24 = v11[1];
              if ( v24 != -1 )
                goto LABEL_60;
              goto LABEL_49;
            }
            v13 = v11[1];
            if ( v13 != -1 )
            {
              v14 = v13 - 1;
              v11[1] = v14;
              if ( !v14 )
                sub_5779C((void **)v11);
            }
            sub_5694C(v9);
            sub_558E4(v2, a2);
            v15 = *(_DWORD *)(v2 + 52);
            if ( v15 != 44 )
              break;
            sub_558E4(v2, a2);
            if ( *(_DWORD *)(v2 + 52) != 256 )
              goto LABEL_64;
            v9 = *(void **)(v2 + 56);
            *(_DWORD *)(v2 + 56) = 0;
            if ( !v9 )
              return 0;
          }
          if ( v15 == 125 )
            return v6;
          sub_553EC(a2, (_DWORD *)v2, "'}' expected");
LABEL_49:
          v20 = v6[1];
          if ( v20 != -1 )
          {
            v21 = v20 - 1;
            v6[1] = v21;
            if ( !v21 )
            {
              v22 = (void **)v6;
              v6 = 0;
              sub_5779C(v22);
              return v6;
            }
          }
        }
      }
    }
    return 0;
  }
  if ( (BYTE4(a1) & 8) == 0 )
    return (int *)sub_575D4(*(_QWORD *)(v2 + 56));
  LODWORD(v23) = sub_56BA0(v2 + 40, &v26);
  if ( !LODWORD(v23) )
    return (int *)sub_57654(v23);
  v6 = 0;
  sub_553EC(a2, (_DWORD *)v2, "real number overflow");
  return v6;
}
