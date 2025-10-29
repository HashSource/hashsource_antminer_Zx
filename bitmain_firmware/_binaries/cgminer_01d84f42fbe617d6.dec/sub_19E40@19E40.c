_DWORD *__fastcall sub_19E40(int a1)
{
  _DWORD *v1; // r4
  int v3; // r2

  v1 = sub_19E18(a1, 0);
  *((_BYTE *)v1 + 273) = 1;
  sub_2B13C((struct timeval *)v1 + 52);
  v3 = v1[66] - 1;
  *((_BYTE *)v1 + 280) = 0;
  v1[66] = v3;
  *((_BYTE *)v1 + 282) = 0;
  return v1;
}
