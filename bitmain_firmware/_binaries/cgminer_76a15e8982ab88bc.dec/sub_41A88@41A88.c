int sub_41A88()
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
  sub_3DC38();
  sub_40624();
  sub_3DA90();
  sub_3F9B0(&v2);
  sub_3ED44((int)v6);
  sub_3EF54((int)v7);
  sub_40018((int)v4);
  sub_40214((int)v5);
  sub_3EB90(120);
  sub_3FD3C(&v3);
  sub_3F304();
  sub_3F304();
  sub_3F64C();
  usleep(0x1E8480u);
  sub_3F64C();
  usleep(0x1E8480u);
  sub_3F64C();
  usleep(0x1E8480u);
  do
  {
    printf("i = %d\n", v0++);
    usleep(0x1E8480u);
  }
  while ( v0 != 35 );
  sub_3F64C();
  usleep(0x1E8480u);
  sub_3F64C();
  usleep(0x1E8480u);
  sub_3F64C();
  return usleep(0x1E8480u);
}
