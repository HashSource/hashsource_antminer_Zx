int *__fastcall sub_5BBB8(int *result, int a2)
{
  int *v3; // r5
  int v4; // r6
  int v5; // r3
  int *v6; // r4
  int v7[7]; // [sp+4h] [bp-1Ch] BYREF

  v3 = result;
  v4 = dword_9D774;
  if ( a2 )
  {
    v7[6] = a2;
    v7[0] = 0;
    memset(&v7[2], 0, 16);
    v7[1] = 8;
    result = (int *)sub_5B9A8(v7);
  }
  v5 = v3[1];
  if ( v5 != 16 )
  {
    v6 = v3 + 7;
    do
    {
      if ( v5 == 8 )
      {
        result = (int *)sub_5BBB8(*v3, v3[6]);
      }
      else
      {
        sub_5B7C8((const char **)v3);
        result = (int *)sub_5B9A8(v3);
      }
      v3 = v6;
      v6 += 7;
      v5 = *(v6 - 6);
    }
    while ( v5 != 16 );
  }
  if ( a2 )
    *(_DWORD *)(dword_9D77C + 28 * v4 + 20) = dword_9D774 - v4;
  return result;
}
