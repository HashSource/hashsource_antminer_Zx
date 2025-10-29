work *make_work()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r4
  int *v3; // r5
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r5
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  v0 = calloc(1u, 0x7B0u);
  if ( !v0 )
  {
    LOWORD(v3) = -268;
    HIWORD(v3) = (unsigned int)"%s %s():%d" >> 16;
    v4 = *v3;
    v5 = v3[1];
    v6 = v3[2];
    v7 = v3[3];
    v3 += 4;
    *(_DWORD *)tmp42 = v4;
    *(_DWORD *)&tmp42[4] = v5;
    *(_DWORD *)&tmp42[8] = v6;
    *(_DWORD *)&tmp42[12] = v7;
    v8 = *v3;
    v9 = v3[1];
    v10 = v3[2];
    v11 = v3[3];
    v12 = v3[4];
    *(_DWORD *)&tmp42[16] = v8;
    *(_DWORD *)&tmp42[20] = v9;
    *(_DWORD *)&tmp42[24] = v10;
    *(_DWORD *)&tmp42[28] = v11;
    *(_WORD *)&tmp42[32] = v12;
    tmp42[34] = BYTE2(v12);
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  v1 = v0;
  v0[457] = total_work_inc();
  return (work *)v1;
}
