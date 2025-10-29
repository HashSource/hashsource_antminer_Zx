int sub_42820()
{
  int v0; // r4
  char v2; // [sp+6h] [bp-2Eh] BYREF
  char v3; // [sp+7h] [bp-2Dh] BYREF
  _DWORD v4[2]; // [sp+8h] [bp-2Ch] BYREF
  _DWORD v5[2]; // [sp+10h] [bp-24h] BYREF
  _DWORD v6[3]; // [sp+18h] [bp-1Ch] BYREF
  _DWORD v7[4]; // [sp+24h] [bp-10h] BYREF

  v2 = 0;
  v0 = 0;
  v3 = 0;
  v6[0] = 218893066;
  v6[1] = 286265102;
  v6[2] = 353637138;
  memset(v7, 0, 12);
  v5[0] = 0;
  v5[1] = 0;
  v4[0] = 387323156;
  v4[1] = 454695192;
  sub_3DF78();
  sub_40E94();
  sub_3DDD0();
  sub_40128(&v2);
  sub_3F4BC((int)v6);
  sub_3F6CC((int)v7);
  sub_40888((int)v4);
  sub_40A84((int)v5);
  sub_3F308(120);
  sub_405AC(&v3);
  sub_3FA7C();
  sub_3FA7C();
  sub_3FDC4();
  usleep(0x1E8480u);
  sub_3FDC4();
  usleep(0x1E8480u);
  sub_3FDC4();
  usleep(0x1E8480u);
  do
  {
    printf("i = %d\n", v0++);
    usleep(0x1E8480u);
  }
  while ( v0 != 35 );
  sub_3FDC4();
  usleep(0x1E8480u);
  sub_3FDC4();
  usleep(0x1E8480u);
  sub_3FDC4();
  return usleep(0x1E8480u);
}
