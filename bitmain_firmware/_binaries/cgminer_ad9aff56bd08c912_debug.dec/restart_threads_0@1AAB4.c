// Alternative name is 'restart_threads.part.56'
void __noreturn restart_threads_0()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r1
  int v6; // r2
  int v7; // r3
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  LOWORD(v0) = -1836;
  HIWORD(v0) = (unsigned int)"ntf buffer overflow in %s %s line %d" >> 16;
  v1 = *v0;
  v2 = v0[1];
  v3 = v0[2];
  v4 = v0[3];
  v0 += 4;
  *(_DWORD *)tmp42 = v1;
  *(_DWORD *)&tmp42[4] = v2;
  *(_DWORD *)&tmp42[8] = v3;
  *(_DWORD *)&tmp42[12] = v4;
  v5 = v0[1];
  v6 = v0[2];
  v7 = v0[3];
  *(_DWORD *)&tmp42[16] = *v0;
  *(_DWORD *)&tmp42[20] = v5;
  *(_DWORD *)&tmp42[24] = v6;
  *(_DWORD *)&tmp42[28] = v7;
  applog(3, tmp42, 1);
  _quit(1, 1);
}
