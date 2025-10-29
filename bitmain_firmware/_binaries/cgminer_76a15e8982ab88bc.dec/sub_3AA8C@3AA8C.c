void __noreturn sub_3AA8C()
{
  double *v0; // r5
  int v1; // r6
  int v2; // r3
  int v3; // r9
  int v4; // r2
  int v5; // r3
  _QWORD *v6; // r7
  int v7; // s28
  int v8; // s29
  int v9; // r4
  double v10; // d8
  int v12; // r10
  double v13; // r0
  double *v14; // r8
  int v15; // r3
  double v16; // d16
  double v17; // d17
  int v18; // r10
  double v19; // d16
  struct timeval v20; // [sp+8h] [bp-10h] BYREF
  struct timeval v21; // [sp+10h] [bp-8h] BYREF
  _DWORD v22[4]; // [sp+18h] [bp+0h] BYREF
  _DWORD s[81]; // [sp+28h] [bp+10h] BYREF

  memset(s, 0, 0x140u);
  memset(v22, 0, sizeof(v22));
  sub_2A7A4(&v20);
  sub_2A7A4(&v21);
  while ( 1 )
  {
    v0 = (double *)&unk_75C80;
    sub_2A7A4(&v21);
    v1 = 0;
    v2 = v21.tv_usec - v20.tv_usec + (v21.tv_usec - v20.tv_usec < 0 ? 0xF4000 : 0);
    v3 = 631471;
    v4 = v21.tv_sec - v20.tv_sec;
    if ( v21.tv_usec - v20.tv_usec < 0 )
      v2 += 576;
    v5 = v2 + 1;
    v6 = qword_75CA0;
    v7 = v21.tv_sec - v20.tv_sec;
    if ( v21.tv_usec - v20.tv_usec < 0 )
      --v4;
    v8 = v5;
    v9 = 0;
    if ( v21.tv_usec - v20.tv_usec < 0 )
      v7 = v4;
    v10 = 0.0;
    do
    {
      if ( *(unsigned __int8 *)++v3 )
      {
        v12 = v22[v1];
        LODWORD(v13) = sub_59F08(0x1FFFLL * *v6);
        *v6 = 0;
        v14 = (double *)&s[20 * v9];
        v15 = 10;
        *v0 = 0.0;
        v16 = 0.0;
        *(double *)&s[20 * v9 + 2 * v12] = v13 / ((double)v7 + (double)v8 / 1000000.0);
        do
        {
          --v15;
          v17 = *v14++;
          v16 = v16 + v17;
        }
        while ( v15 );
        *v0 = v16;
        v18 = v12 + 1;
        sprintf(&byte_78ED0[16 * v9], "%.2f", v16 / 1000.0 / 10.0);
        v19 = *v0 / 1000.0;
        if ( v18 > 9 )
          v18 = 0;
        v22[v1] = v18;
        v10 = v10 + v19 / 10.0;
      }
      ++v9;
      ++v1;
      ++v0;
      ++v6;
    }
    while ( v9 != 4 );
    sprintf(byte_759C0, "%.2f", v10);
    dbl_75CC0 = v10;
    sub_2A488(&v20, &v21);
    sleep(5u);
  }
}
