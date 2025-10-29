int *__fastcall sub_58220(double a1)
{
  _DWORD *v1; // r4
  int v2; // r3
  _DWORD *v4; // r7
  _DWORD *j; // r5
  char *v6; // r6
  double v7; // r0
  int *v8; // r0
  double v9; // r0
  int *v10; // r6
  unsigned int v11; // r3
  unsigned int i; // r5
  int *v13; // r0

  v1 = (_DWORD *)LODWORD(a1);
  if ( !LODWORD(a1) )
    return v1;
  v2 = *(_DWORD *)LODWORD(a1);
  if ( *(_DWORD *)LODWORD(a1) )
  {
    switch ( v2 )
    {
      case 1:
        v10 = sub_57338();
        if ( v10 )
        {
          if ( *v1 == 1 )
          {
            v11 = v1[3];
            if ( v11 )
            {
              for ( i = 0; i < v11; ++i )
              {
                LODWORD(v9) = 0;
                if ( i < v11 )
                  LODWORD(v9) = *(_DWORD *)(v1[4] + 4 * i);
                v13 = sub_58220(v9);
                sub_57AA0(v10, (void **)v13);
                if ( *v1 != 1 )
                  break;
                v11 = v1[3];
              }
            }
          }
        }
        return v10;
      case 2:
        return sub_574A4(*(const char **)(LODWORD(a1) + 8));
      case 3:
        return (int *)sub_575D4(*(_QWORD *)(LODWORD(a1) + 8));
      case 4:
        return (int *)sub_57654(a1);
      default:
        if ( (unsigned int)(v2 - 5) > 2 )
          return 0;
        return v1;
    }
  }
  else
  {
    v4 = sub_57160();
    if ( v4 )
    {
      for ( j = sub_57254(v1); j; j = (_DWORD *)sub_572A0(v1, (int)j) )
      {
        v6 = (char *)sub_572CC((int)j);
        LODWORD(v7) = sub_572D8((int)j);
        v8 = sub_58220(v7);
        sub_57BD8(v4, v6, (int)v8);
      }
    }
    return v4;
  }
}
