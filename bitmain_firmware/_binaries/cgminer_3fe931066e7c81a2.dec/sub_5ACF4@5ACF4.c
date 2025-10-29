int *__fastcall sub_5ACF4(double a1)
{
  _DWORD *v1; // r4
  int v2; // r3
  _DWORD *v4; // r7
  _DWORD *v5; // r0
  char *j; // r5
  int v7; // r3
  int v8; // r0
  int *v9; // r6
  unsigned int v10; // r3
  unsigned int i; // r5
  int v12; // r1

  v1 = (_DWORD *)LODWORD(a1);
  if ( !LODWORD(a1) )
    return 0;
  v2 = *(_DWORD *)LODWORD(a1);
  if ( *(_DWORD *)LODWORD(a1) )
  {
    switch ( v2 )
    {
      case 1:
        v9 = sub_59F80();
        if ( v9 )
        {
          if ( *v1 == 1 )
          {
            v10 = v1[3];
            if ( v10 )
            {
              for ( i = 0; i < v10; ++i )
              {
                v12 = 0;
                if ( v10 > i )
                {
                  v12 = *(_DWORD *)(v1[4] + 4 * i);
                  if ( v12 )
                  {
                    if ( *(_DWORD *)(v12 + 4) != -1 )
                      ++*(_DWORD *)(v12 + 4);
                  }
                }
                sub_5A6E8(v9, (void **)v12);
                if ( *v1 != 1 )
                  break;
                v10 = v1[3];
              }
            }
          }
        }
        return v9;
      case 2:
        return sub_5A0EC(*(const char **)(LODWORD(a1) + 8));
      case 3:
        return (int *)sub_5A21C(*(_QWORD *)(LODWORD(a1) + 8));
      case 4:
        return (int *)sub_5A29C(a1);
      default:
        if ( (unsigned int)(v2 - 5) <= 2 )
          return v1;
        return 0;
    }
  }
  else
  {
    v4 = sub_59DA8();
    if ( v4 )
    {
      v5 = sub_59E9C(v1);
      for ( j = (char *)sub_59F14((int)v5); j; j = (char *)sub_59F14(v8) )
      {
        v7 = sub_59F20((int)(j - 16));
        if ( !v7 )
          break;
        if ( *(_DWORD *)(v7 + 4) != -1 )
          ++*(_DWORD *)(v7 + 4);
        sub_5A820(v4, j, v7);
        v8 = sub_59EE8(v1, (int)(j - 16));
      }
    }
    return v4;
  }
}
