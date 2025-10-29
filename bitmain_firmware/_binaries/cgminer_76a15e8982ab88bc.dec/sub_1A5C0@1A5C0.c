_DWORD *__fastcall sub_1A5C0(int a1)
{
  _DWORD *v1; // r4
  int v3; // r2

  v1 = sub_1A598(a1, 0);
  *((_BYTE *)v1 + 1761) = 1;
  sub_2A7A4((struct timeval *)v1 + 238);
  v3 = v1[438] - 1;
  *((_BYTE *)v1 + 1768) = 0;
  v1[438] = v3;
  *((_BYTE *)v1 + 1770) = 0;
  return v1;
}
