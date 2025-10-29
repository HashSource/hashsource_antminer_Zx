int __fastcall sub_163CC(char *a1, unsigned __int64 a2)
{
  bool v3; // cf
  char v4; // r3
  int v6; // r4
  size_t v7; // r2
  unsigned __int64 v8; // [sp+0h] [bp-Ch] BYREF

  v8 = a2;
  if ( a2 > 0xFC )
  {
    if ( a2 <= 0xFFFF )
    {
      v6 = 3;
      *a1 = -3;
      v7 = 2;
    }
    else
    {
      v3 = HIDWORD(a2) == 0;
      if ( !HIDWORD(a2) )
        v3 = 1;
      if ( v3 )
      {
        v6 = 5;
        v7 = 4;
      }
      else
      {
        v6 = 9;
        v7 = 8;
      }
      if ( v3 )
        v4 = -2;
      else
        v4 = -1;
      *a1 = v4;
    }
  }
  else
  {
    *a1 = a2;
    v6 = 1;
    v7 = 0;
  }
  memcpy(a1 + 1, &v8, v7);
  return v6;
}
