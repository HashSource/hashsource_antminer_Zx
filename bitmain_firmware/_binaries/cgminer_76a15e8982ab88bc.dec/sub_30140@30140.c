_DWORD *__fastcall sub_30140(_DWORD *result)
{
  _DWORD *v1; // r3
  _DWORD *v2; // r2
  int v3; // t1

  v1 = &unk_72F18;
  v2 = result;
  do
  {
    v3 = v1[1];
    ++v1;
    v2[34] = v3;
    ++v2;
  }
  while ( v1 != (_DWORD *)&unk_72F38 );
  result[1] = 0;
  *result = 0;
  return result;
}
