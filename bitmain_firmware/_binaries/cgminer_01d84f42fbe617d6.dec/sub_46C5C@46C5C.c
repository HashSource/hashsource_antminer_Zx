void __fastcall sub_46C5C(void **a1)
{
  int v2; // r3
  void *v3; // r1
  _DWORD *v4; // r12
  unsigned int i; // r5
  int v6; // r0
  int v7; // r3

  if ( a1 )
  {
    v2 = (int)*a1;
    if ( *a1 )
    {
      switch ( v2 )
      {
        case 1:
          v3 = a1[3];
          v4 = a1[4];
          if ( v3 )
          {
            for ( i = 0; i < (unsigned int)v3; ++i )
            {
              v6 = v4[i];
              if ( v6 )
              {
                v7 = *(_DWORD *)(v6 + 4);
                if ( v7 != -1 )
                {
                  *(_DWORD *)(v6 + 4) = v7 - 1;
                  if ( v7 == 1 )
                  {
                    sub_46C5C((void **)v6);
                    v4 = a1[4];
                    v3 = a1[3];
                  }
                }
              }
            }
          }
          sub_45E0C(v4);
          sub_45E0C(a1);
          break;
        case 2:
          sub_45E0C(a1[2]);
          sub_45E0C(a1);
          break;
        case 3:
        case 4:
          sub_45E0C(a1);
          break;
      }
    }
    else
    {
      sub_442EC((int)(a1 + 2));
      sub_45E0C(a1);
    }
  }
}
