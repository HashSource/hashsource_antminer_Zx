void *__fastcall sub_30174(int *a1, char *a2, size_t n)
{
  int v4; // r0
  size_t v7; // r6
  int v8; // r0
  void *result; // r0
  unsigned int v10; // r3
  unsigned int v11; // r5
  size_t v12; // r8
  char *v13; // r6
  int v14; // r3

  v4 = a1[1];
  v7 = 64 - v4;
  v8 = v4 + 8;
  if ( n < v7 )
    v7 = n;
  result = memcpy((char *)a1 + v8, a2, v7);
  v10 = n + a1[1];
  if ( v10 > 0x3F )
  {
    v11 = n - v7;
    v12 = v11 & 0x3F;
    v13 = &a2[v7];
    v11 >>= 6;
    sub_2FF20((unsigned int)a1, (int)(a1 + 2), 1);
    sub_2FF20((unsigned int)a1, (int)v13, v11);
    result = memcpy(a1 + 2, &v13[64 * v11], v12);
    v14 = *a1;
    a1[1] = v12;
    *a1 = v14 + ((v11 + 1) << 6);
  }
  else
  {
    a1[1] = v10;
  }
  return result;
}
