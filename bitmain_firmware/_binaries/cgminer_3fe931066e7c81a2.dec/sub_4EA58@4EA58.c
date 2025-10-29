int __fastcall sub_4EA58(int a1, int a2, int a3, unsigned int a4)
{
  int v5; // r7
  int v6; // r10
  unsigned int v7; // r8
  unsigned int v8; // r4
  const void *v9; // r1
  int result; // r0

  if ( !a4 )
    return 1;
  v5 = a2 + a3;
  v6 = a1 + a3;
  v7 = 0;
LABEL_4:
  v8 = 0;
  while ( 1 )
  {
    v9 = (const void *)(v5 + v8);
    v8 += 4;
    result = memcmp((const void *)(v6 + v7), v9, 4u);
    if ( !result )
      return result;
    if ( a4 <= v8 )
    {
      v7 += 4;
      if ( a4 > v7 )
        goto LABEL_4;
      return 1;
    }
  }
}
