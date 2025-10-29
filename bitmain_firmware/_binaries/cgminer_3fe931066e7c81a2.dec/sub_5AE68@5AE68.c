int *__fastcall sub_5AE68(double a1)
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
        v10 = sub_59F80();
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
                v13 = sub_5AE68(v9);
                sub_5A6E8(v10, (void **)v13);
                if ( *v1 != 1 )
                  break;
                v11 = v1[3];
              }
            }
          }
        }
        return v10;
      case 2:
        return sub_5A0EC(*(const char **)(LODWORD(a1) + 8));
      case 3:
        return (int *)sub_5A21C(*(_QWORD *)(LODWORD(a1) + 8));
      case 4:
        return (int *)sub_5A29C(a1);
      default:
        if ( (unsigned int)(v2 - 5) > 2 )
          return 0;
        return v1;
    }
  }
  else
  {
    v4 = sub_59DA8();
    if ( v4 )
    {
      for ( j = sub_59E9C(v1); j; j = (_DWORD *)sub_59EE8(v1, (int)j) )
      {
        v6 = (char *)sub_59F14((int)j);
        LODWORD(v7) = sub_59F20((int)j);
        v8 = sub_5AE68(v7);
        sub_5A820(v4, v6, (int)v8);
      }
    }
    return v4;
  }
}
