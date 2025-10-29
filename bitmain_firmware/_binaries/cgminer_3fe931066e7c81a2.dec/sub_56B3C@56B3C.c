void __fastcall sub_56B3C(unsigned int *a1, int a2, int a3)
{
  int v5; // r10
  int v6; // r0
  unsigned int v7; // r3
  unsigned int v8; // r5
  unsigned int *v9; // r1
  int v10; // r2
  int v11; // r8
  unsigned int v12; // r0
  int v13; // r12
  int v14; // t1
  int *v15; // [sp+0h] [bp-100Ch]
  int v16; // [sp+4h] [bp-1008h]
  char v17[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( a2 <= 1 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
    {
      strcpy(v17, "XXTEA encode failes, N <= 1 found.\n");
      sub_38730(3, v17, 0);
    }
  }
  else
  {
    v5 = a2 - 1;
    v6 = sub_5C710(52, a2);
    v7 = a1[v5];
    v8 = 0;
    v15 = (int *)&a1[v5];
    v16 = -1640531527 * v6 - 1253254570;
    do
    {
      v9 = a1;
      v10 = 0;
      v8 -= 1640531527;
      v11 = (v8 >> 2) & 3;
      do
      {
        v12 = v9[1];
        v13 = v10++ & 3 ^ v11;
        v14 = *v9++;
        v7 = (((v7 ^ *(_DWORD *)(a3 + 4 * v13)) + (v12 ^ v8)) ^ (((16 * v7) ^ (v12 >> 3)) + ((v7 >> 5) ^ (4 * v12))))
           + v14;
        *(v9 - 1) = v7;
      }
      while ( v10 != v5 );
      v7 = (((v7 ^ *(_DWORD *)(a3 + 4 * (v11 ^ v5 & 3))) + (v8 ^ *a1))
          ^ (((*a1 >> 3) ^ (16 * v7)) + ((4 * *a1) ^ (v7 >> 5))))
         + *v15;
      *v15 = v7;
    }
    while ( v8 != v16 );
  }
}
