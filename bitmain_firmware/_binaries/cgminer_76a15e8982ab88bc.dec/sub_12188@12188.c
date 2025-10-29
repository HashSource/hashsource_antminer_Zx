int __fastcall sub_12188(int result)
{
  int v1; // r4
  int *v2; // r2
  int v3; // r12
  int v4; // r3
  int v5; // t1

  v1 = *(_DWORD *)(result + 188);
  if ( dword_77FC0 > 0 )
  {
    v2 = (int *)dword_78260;
    v3 = dword_78260 + 4 * dword_77FC0;
    do
    {
      while ( 1 )
      {
        v5 = *v2++;
        v4 = v5;
        if ( !*(_BYTE *)(v5 + 129) && *(_DWORD *)(v4 + 132) == 1 && (!*(_BYTE *)(v4 + 664) || *(_BYTE *)(v4 + 665)) )
          break;
        if ( v2 == (int *)v3 )
          goto LABEL_11;
      }
      if ( *(_DWORD *)(v4 + 188) < v1 )
      {
        result = v4;
        v1 = *(_DWORD *)(v4 + 188);
      }
    }
    while ( v2 != (int *)v3 );
LABEL_11:
    v1 = *(_DWORD *)(result + 188);
  }
  *(_DWORD *)(result + 188) = v1 + 1;
  return result;
}
