int *__fastcall sub_565E8(int *a1, unsigned int a2, char *a3)
{
  _DWORD v7[2]; // [sp+0h] [bp-48h] BYREF
  _DWORD v8[16]; // [sp+8h] [bp-40h] BYREF

  sub_583CC(a3, "<string>");
  if ( a1 )
  {
    v7[0] = a1;
    a1 = 0;
    v7[1] = 0;
    if ( !sub_5550C((int)v8, (int)sub_5534C, (int)v7) )
    {
      a1 = sub_5650C(v8, a2, (int)a3);
      sub_55558((int)v8);
    }
  }
  else
  {
    sub_553EC((int)a3, 0, "wrong arguments");
  }
  return a1;
}
