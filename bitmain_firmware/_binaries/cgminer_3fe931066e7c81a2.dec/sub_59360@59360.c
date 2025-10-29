int *__fastcall sub_59360(int *a1, unsigned int a2, char *a3)
{
  int *v5; // r4
  char *v6; // r1
  _DWORD v8[16]; // [sp+0h] [bp-40h] BYREF

  v5 = a1;
  if ( a1 == (int *)stdin )
    v6 = "<stdin>";
  else
    v6 = "<stream>";
  sub_5B014(a3, v6);
  if ( v5 )
  {
    if ( sub_58154((int)v8, (int)fgetc, (int)v5) )
    {
      return 0;
    }
    else
    {
      v5 = sub_59154(v8, a2, (int)a3);
      sub_581A0((int)v8);
    }
  }
  else
  {
    sub_58034((int)a3, 0, "wrong arguments");
  }
  return v5;
}
