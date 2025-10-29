int *__fastcall sub_592C4(int *a1, int a2, unsigned int a3, char *a4)
{
  _DWORD v9[3]; // [sp+4h] [bp-50h] BYREF
  _DWORD v10[17]; // [sp+10h] [bp-44h] BYREF

  sub_5B014(a4, "<buffer>");
  if ( a1 )
  {
    v9[0] = a1;
    v9[1] = a2;
    a1 = 0;
    v9[2] = 0;
    if ( !sub_58154((int)v10, (int)sub_57FB4, (int)v9) )
    {
      a1 = sub_59154(v10, a3, (int)a4);
      sub_581A0((int)v10);
    }
  }
  else
  {
    sub_58034((int)a4, 0, "wrong arguments");
  }
  return a1;
}
