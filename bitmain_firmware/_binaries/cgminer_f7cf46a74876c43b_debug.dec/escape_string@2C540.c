char *__fastcall escape_string(char *str, bool isjson)
{
  unsigned int v2; // r4
  char *v3; // r5
  _BOOL4 v4; // r7
  char *v5; // r2
  unsigned int v6; // r3
  int v7; // r6
  unsigned int v8; // t1
  unsigned int v9; // t1
  size_t v10; // r6
  char *v11; // r3
  char *v12; // r2
  char *v13; // r1
  unsigned int v14; // t1
  char *v15; // r2
  char *v16; // r1
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v2 = (unsigned __int8)*str;
  v3 = str;
  if ( *str )
  {
    v4 = isjson;
    v5 = str;
    v6 = (unsigned __int8)*str;
    v7 = 0;
    while ( 1 )
    {
      if ( v6 == 61 )
        goto LABEL_11;
      if ( v6 <= 0x3D )
      {
        if ( v6 != 34 )
        {
          if ( v6 != 44 )
            goto LABEL_6;
          if ( isjson )
            goto LABEL_12;
LABEL_5:
          ++v7;
          goto LABEL_6;
        }
        if ( isjson )
          goto LABEL_5;
LABEL_6:
        v8 = (unsigned __int8)*++v5;
        v6 = v8;
        if ( !v8 )
          goto LABEL_13;
      }
      else
      {
        if ( v6 == 92 )
          goto LABEL_5;
        if ( v6 != 124 )
          goto LABEL_6;
LABEL_11:
        if ( !isjson )
          goto LABEL_5;
LABEL_12:
        v9 = (unsigned __int8)*++v5;
        v6 = v9;
        if ( !v9 )
        {
LABEL_13:
          if ( !v7 )
            return str;
          v10 = v7 + 1 + strlen(str);
          str = (char *)malloc(v10);
          if ( !str )
          {
            snprintf(tmp42, 0x1000u, "Failed to malloc escape buf %d in %s %s():%d", v10, "api.c", "escape_string", 840);
            applog(3, tmp42, 1);
            quit(1);
          }
          v11 = str;
          if ( !v2 )
          {
LABEL_27:
            *v11 = v2;
            return str;
          }
          while ( 2 )
          {
            if ( v2 != 61 )
            {
              if ( v2 > 0x3D )
              {
                if ( v2 == 92 )
                {
                  *v11 = 92;
                  v11[1] = 92;
                  v11 += 2;
                  goto LABEL_26;
                }
                if ( v2 != 124 )
                  goto LABEL_35;
              }
              else
              {
                if ( v2 == 34 )
                {
                  v12 = v11 + 1;
                  if ( v4 )
                  {
                    v13 = v11++;
                    *v13 = 92;
                    v12 = v13 + 2;
                  }
                  *v11 = 34;
                  v11 = v12;
                  goto LABEL_26;
                }
                if ( v2 != 44 )
                {
LABEL_35:
                  *v11++ = v2;
                  goto LABEL_26;
                }
              }
            }
            v15 = v11 + 1;
            if ( !v4 )
            {
              v16 = v11++;
              *v16 = 92;
              v15 = v16 + 2;
            }
            *v11 = v2;
            v11 = v15;
LABEL_26:
            v14 = (unsigned __int8)*++v3;
            v2 = v14;
            if ( !v14 )
              goto LABEL_27;
            continue;
          }
        }
      }
    }
  }
  return str;
}
