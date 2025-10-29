int __fastcall sub_307D8(unsigned int *a1, char *s)
{
  _BYTE *v2; // r12

  v2 = (_BYTE *)a1[1];
  a1[2] = (unsigned int)v2;
  *v2 = 0;
  *((_BYTE *)a1 + 13) = 0;
  return sub_30638(a1, s);
}
