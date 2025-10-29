int *__fastcall sub_5667C(int *a1, int a2, unsigned int a3, char *a4)
{
  _DWORD v9[3]; // [sp+4h] [bp-50h] BYREF
  _DWORD v10[17]; // [sp+10h] [bp-44h] BYREF

  sub_583CC(a4, "<buffer>");
  if ( a1 )
  {
    v9[0] = a1;
    v9[1] = a2;
    a1 = 0;
    v9[2] = 0;
    if ( !sub_5550C((int)v10, (int)sub_5536C, (int)v9) )
    {
      a1 = sub_5650C(v10, a3, (int)a4);
      sub_55558((int)v10);
    }
  }
  else
  {
    sub_553EC((int)a4, 0, "wrong arguments");
  }
  return a1;
}
