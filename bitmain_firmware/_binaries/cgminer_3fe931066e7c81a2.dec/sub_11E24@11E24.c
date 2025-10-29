int __fastcall sub_11E24(int a1)
{
  _DWORD *v1; // r6
  int v3; // r5
  char v5[16]; // [sp+0h] [bp-1010h] BYREF
  char v6[4096]; // [sp+10h] [bp-1000h] BYREF

  v1 = *(_DWORD **)(a1 + 36);
  v3 = v1[1];
  snprintf(v5, 0x10u, "%d/Miner", *(_DWORD *)a1);
  sub_2F0B4(v5);
  sub_FC58(a1);
  if ( (*(int (__fastcall **)(int))(v3 + 52))(a1) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      strcpy(v6, "Waiting on sem in miner thread");
      sub_38730(7, v6, 0);
    }
    sub_2F280((sem_t *)(a1 + 16), "cgminer.c", "miner_thread", 9147);
    v1[58] = time(0);
    (*(void (__fastcall **)(int))(v3 + 60))(a1);
    (*(void (__fastcall **)(int))(v3 + 88))(a1);
  }
  else
  {
    sub_2ED88(v1, 0);
  }
  return 0;
}
