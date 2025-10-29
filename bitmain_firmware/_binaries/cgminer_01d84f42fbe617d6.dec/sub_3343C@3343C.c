int __fastcall sub_3343C(unsigned int *a1, int a2, const char *a3, unsigned __int8 a4)
{
  unsigned int *v5; // r5
  char *v7; // r0
  char *v8; // r7
  int v9; // r8
  int v10; // r10
  int v11; // r9
  int v12; // r2
  bool v13; // zf
  _BOOL4 v14; // r4
  const char *v16; // r3
  int v17; // r1
  unsigned __int8 v18; // [sp+20h] [bp+20h]

  v5 = a1;
  if ( a3 && *a3 )
  {
    v7 = strchr(a3, 44);
    v8 = v7;
    if ( v7 && (*v7 = 0, v7 != (char *)-1) && (v9 = (unsigned __int8)v7[1], v7[1]) )
    {
      if ( !strcasecmp(a3, "all") )
      {
        v11 = 0;
        v10 = 1;
      }
      else
      {
        if ( strcasecmp(a3, "bestshare") )
        {
          v18 = a4;
          a1 = v5;
          v16 = a3;
          v17 = 95;
          return sub_32F3C(a1, v17, 0, (int)v16, v18);
        }
        v10 = 0;
        v11 = 1;
      }
      v12 = LOBYTE((*_ctype_tolower_loc())[v9]);
      v13 = v12 == 102;
      if ( v12 != 102 )
        v13 = v12 == 116;
      v8[1] = v12;
      if ( v13 )
      {
        v14 = v12 == 116;
        if ( v12 == 116 )
          sub_1AECC();
        if ( v10 )
          sub_1ABE0();
        if ( v11 )
          sub_15BEC();
        a1 = v5;
        v16 = "All";
        if ( v14 )
        {
          v17 = 96;
          v18 = a4;
          if ( !v10 )
            v16 = "BestShare";
        }
        else
        {
          v18 = a4;
          v17 = 97;
          if ( !v10 )
            v16 = "BestShare";
        }
      }
      else
      {
        v18 = a4;
        a1 = v5;
        v16 = 0;
        v17 = 76;
      }
    }
    else
    {
      v18 = a4;
      a1 = v5;
      v16 = 0;
      v17 = 75;
    }
  }
  else
  {
    v18 = a4;
    v16 = 0;
    v17 = 94;
  }
  return sub_32F3C(a1, v17, 0, (int)v16, v18);
}
