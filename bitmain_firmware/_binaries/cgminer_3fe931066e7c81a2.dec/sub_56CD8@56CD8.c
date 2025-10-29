void __fastcall sub_56CD8(unsigned int *a1, int a2, int a3)
{
  int v6; // r0
  unsigned int v7; // r3
  int v8; // r0
  unsigned int v9; // r5
  int v10; // r1
  unsigned int *v11; // r12
  int v12; // r10
  int v13; // r8
  char v14[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( a2 <= 1 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
    {
      strcpy(v14, "XXTEA decode failes, N <= 1 found.\n");
      sub_38730(3, v14, 0);
    }
  }
  else
  {
    v6 = sub_5C710(52, a2);
    v7 = *a1;
    v8 = v6 + 6;
    v9 = -1640531527 * v8;
    do
    {
      v10 = a2 - 1;
      v11 = &a1[a2];
      v12 = (v9 >> 2) & 3;
      do
      {
        v13 = *(_DWORD *)(a3 + 4 * (v10-- & 3 ^ v12));
        v7 = *(v11 - 1)
           - (((*(v11 - 2) ^ v13) + (v7 ^ v9)) ^ (((v7 >> 3) ^ (16 * *(v11 - 2))) + ((4 * v7) ^ (*(v11 - 2) >> 5))));
        *--v11 = v7;
      }
      while ( v10 );
      --v8;
      v7 = *a1
         - ((((16 * a1[a2 - 1]) ^ (v7 >> 3)) + ((a1[a2 - 1] >> 5) ^ (4 * v7)))
          ^ ((v7 ^ v9) + (a1[a2 - 1] ^ *(_DWORD *)(a3 + 4 * v12))));
      v9 += 1640531527;
      *a1 = v7;
    }
    while ( v8 );
  }
}
