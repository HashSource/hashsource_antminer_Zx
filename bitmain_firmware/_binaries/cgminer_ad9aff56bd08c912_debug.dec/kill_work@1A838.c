void __noreturn kill_work()
{
  void *v0; // r0
  int *v1; // r5
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  int v6; // r1
  int v7; // r2
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  LOWORD(v0) = -10839;
  LOWORD(v1) = -2024;
  HIWORD(v0) = (unsigned int)&loc_1D558 >> 16;
  HIWORD(v1) = (unsigned int)"ssed to set_target" >> 16;
  cg_completion_timeout(v0, 0, 5000);
  v2 = *v1;
  v3 = v1[1];
  v4 = v1[2];
  v5 = v1[3];
  v1 += 4;
  *(_DWORD *)tmp42 = v2;
  *(_DWORD *)&tmp42[4] = v3;
  *(_DWORD *)&tmp42[8] = v4;
  *(_DWORD *)&tmp42[12] = v5;
  v6 = v1[1];
  v7 = v1[2];
  *(_DWORD *)&tmp42[16] = *v1;
  *(_DWORD *)&tmp42[20] = v6;
  *(_WORD *)&tmp42[24] = v7;
  applog(3, tmp42, 1);
  _quit(0, 1);
}
