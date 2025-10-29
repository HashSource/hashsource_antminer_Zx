char *__fastcall json_escape(char *str)
{
  char *v1; // r4
  size_t v2; // r0
  char *v3; // r5
  JE *v4; // r0
  int v5; // r3
  JE *v6; // r1
  char *v7; // r1
  char *v8; // r2
  bool v9; // zf
  char *v10; // r0
  int v11; // t1

  v1 = str;
  v2 = strlen(str);
  v3 = (char *)malloc(2 * v2 + 1);
  v4 = (JE *)malloc(8u);
  v5 = (unsigned __int8)*v1;
  v4->buf = v3;
  v6 = jedata;
  jedata = v4;
  v4->next = v6;
  v7 = v3;
  if ( v5 )
  {
    do
    {
      v8 = v7 + 1;
      v9 = v5 == 34;
      if ( v5 != 34 )
        v9 = v5 == 92;
      v10 = v7 + 1;
      if ( v9 )
      {
        *v7 = 92;
        v7 += 2;
      }
      else
      {
        v8 = v7;
      }
      if ( !v9 )
        v7 = v10;
      *v8 = v5;
      v11 = (unsigned __int8)*++v1;
      v5 = v11;
    }
    while ( v11 );
  }
  *v7 = 0;
  return v3;
}
