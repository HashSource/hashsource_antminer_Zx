void __fastcall sub_34598(unsigned int *a1, int a2, char *a3, int a4)
{
  char *v7; // r7
  int *v8; // r7
  char *v9; // r4
  char *s; // [sp+Ch] [bp-Ch] BYREF
  const char *v11; // [sp+10h] [bp-8h] BYREF
  const char *v12; // [sp+14h] [bp-4h] BYREF

  if ( a3 && *a3 )
  {
    if ( sub_31EBC((unsigned __int8 *)a3, (unsigned __int8 **)&s, &v11, &v12) )
    {
      v8 = (int *)sub_17974();
      sub_154B4((int)v8, s);
      sub_26B24((int)v8, 1, s, v11, v12);
      v9 = sub_30370(s, a4);
      sub_32ECC(a1, 55, *v8, (int)v9, a4);
      if ( v9 != s )
        free(v9);
    }
    else
    {
      v7 = sub_30370(a3, a4);
      sub_32ECC(a1, 53, 0, (int)v7, a4);
      if ( v7 != a3 )
        free(v7);
    }
  }
  else
  {
    sub_32ECC(a1, 52, 0, 0, a4);
  }
}
