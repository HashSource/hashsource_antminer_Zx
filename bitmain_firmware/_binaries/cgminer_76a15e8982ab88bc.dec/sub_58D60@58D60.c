int __fastcall sub_58D60(int *a1)
{
  char *v2; // r0
  int v3; // r10
  int v4; // r8
  int *v5; // r12
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int result; // r0
  int v11; // r1
  int v12; // r2

  v2 = (char *)realloc((void *)dword_9A550, 28 * (dword_9A548 + 1));
  v3 = dword_9A548 + 1;
  v4 = (int)v2;
  v5 = (int *)&v2[28 * dword_9A548];
  v6 = *a1;
  v7 = a1[1];
  v8 = a1[2];
  v9 = a1[3];
  a1 += 4;
  dword_9A550 = v4;
  *v5 = v6;
  v5[1] = v7;
  v5[2] = v8;
  v5[3] = v9;
  v5 += 4;
  result = *a1;
  v11 = a1[1];
  v12 = a1[2];
  dword_9A548 = v3;
  *v5 = result;
  v5[1] = v11;
  v5[2] = v12;
  return result;
}
