int __fastcall get_cur_seed_rvn(_DWORD *a1)
{
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r1
  int v6; // r2
  int v7; // r3

  pthread_mutex_lock(&stru_174190);
  v2 = dword_1741A8[1];
  v3 = dword_1741A8[2];
  v4 = dword_1741A8[3];
  *a1 = dword_1741A8[0];
  a1[1] = v2;
  a1[2] = v3;
  a1[3] = v4;
  v5 = unk_1741BC;
  v6 = unk_1741C0;
  v7 = unk_1741C4;
  a1[4] = unk_1741B8;
  a1[5] = v5;
  a1[6] = v6;
  a1[7] = v7;
  return pthread_mutex_unlock(&stru_174190);
}
