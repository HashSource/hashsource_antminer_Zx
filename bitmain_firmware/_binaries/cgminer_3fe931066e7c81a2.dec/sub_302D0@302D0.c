_DWORD *__fastcall sub_302D0(_DWORD *result)
{
  _DWORD *v1; // r3
  _DWORD *v2; // r2
  int v3; // t1

  v1 = &unk_760D8;
  v2 = result;
  do
  {
    v3 = v1[1];
    ++v1;
    v2[34] = v3;
    ++v2;
  }
  while ( v1 != (_DWORD *)&unk_760F8 );
  result[1] = 0;
  *result = 0;
  return result;
}
