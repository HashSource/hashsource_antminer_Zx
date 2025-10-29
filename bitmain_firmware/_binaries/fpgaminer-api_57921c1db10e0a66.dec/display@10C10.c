char *__fastcall display(char *s)
{
  const char *v1; // r4
  const char *v2; // r7
  int v3; // r6
  char *v4; // r0
  const char *v5; // r5
  char *v6; // r0
  char *v7; // r11
  const char *v8; // r10
  const unsigned __int16 **v9; // r0
  const char *v10; // r2
  const char *v11; // r1
  const char *v12; // r2

  if ( s )
  {
    v1 = s;
    while ( 1 )
    {
      s = strchr(v1, 124);
      if ( !s )
        break;
      v2 = s + 1;
      *s = 0;
      if ( *v1 )
      {
LABEL_9:
        v3 = 0;
        while ( 1 )
        {
          v4 = strchr(v1, 44);
          if ( !v4 )
            break;
          v5 = v4 + 1;
          *v4 = 0;
          if ( !*v1 )
          {
            v1 = v4 + 1;
            goto LABEL_11;
          }
          v6 = strchr(v1, 61);
          v7 = v6;
          if ( !v6 )
          {
LABEL_26:
            if ( v3 )
            {
LABEL_28:
              v12 = v1;
              v1 = v5;
              printf("   [%d] => %s\n", v3, v12);
              goto LABEL_11;
            }
LABEL_27:
            v10 = "";
            v8 = 0;
LABEL_19:
            printf("[%s%s] =>\n(\n", v1, v10);
            goto LABEL_20;
          }
LABEL_15:
          v8 = v6 + 1;
          *v6 = 0;
          if ( !v3 )
          {
            if ( v6 == (char *)-1 )
              goto LABEL_27;
            v9 = _ctype_b_loc();
            v10 = "";
            if ( ((*v9)[(unsigned __int8)v7[1]] & 0x800) != 0 )
              v10 = v8;
            goto LABEL_19;
          }
LABEL_20:
          if ( !v8 )
            goto LABEL_28;
          v11 = v1;
          v1 = v5;
          printf("   [%s] => %s\n", v11, v8);
LABEL_11:
          ++v3;
          if ( !v5 )
            goto LABEL_23;
        }
        if ( *v1 )
        {
          v5 = 0;
          v6 = strchr(v1, 61);
          v7 = v6;
          if ( !v6 )
            goto LABEL_26;
          goto LABEL_15;
        }
LABEL_23:
        v1 = v2;
        s = (char *)puts(")");
        if ( !v2 )
          return s;
      }
      else
      {
        v1 = s + 1;
        if ( s == (char *)-1 )
          return s;
      }
    }
    if ( !*v1 )
      return s;
    v2 = 0;
    goto LABEL_9;
  }
  return s;
}
