_WORD *__fastcall get_miner_6060info_status(_WORD *a1)
{
  char *v1; // r4
  _WORD *v3; // lr
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3

  v1 = byte_1742C0;
  v3 = a1;
  do
  {
    v3 += 8;
    v4 = *(_DWORD *)v1;
    v5 = *((_DWORD *)v1 + 1);
    v6 = *((_DWORD *)v1 + 2);
    v7 = *((_DWORD *)v1 + 3);
    v1 += 16;
    *((_DWORD *)v3 - 4) = v4;
    *((_DWORD *)v3 - 3) = v5;
    *((_DWORD *)v3 - 2) = v6;
    *((_DWORD *)v3 - 1) = v7;
  }
  while ( v1 != (char *)&unk_1742F0 );
  *v3 = *(_WORD *)v1;
  return a1;
}
