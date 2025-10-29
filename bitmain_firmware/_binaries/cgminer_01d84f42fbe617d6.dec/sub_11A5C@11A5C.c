int __fastcall sub_11A5C(int a1)
{
  _DWORD *v1; // r6
  int v3; // r5
  char v5[16]; // [sp+0h] [bp-810h] BYREF
  char v6[2048]; // [sp+10h] [bp-800h] BYREF

  v1 = *(_DWORD **)(a1 + 36);
  v3 = v1[1];
  snprintf(v5, 0x10u, "%d/Miner", *(_DWORD *)a1);
  sub_2F02C(v5);
  sub_F808(a1);
  if ( (*(int (__fastcall **)(int))(v3 + 52))(a1) )
  {
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      strcpy(v6, "Waiting on sem in miner thread");
      sub_38438(7, v6, 0);
    }
    sub_2F1F8((sem_t *)(a1 + 16), "cgminer.c", "miner_thread", 9151);
    v1[58] = time(0);
    (*(void (__fastcall **)(int))(v3 + 60))(a1);
    (*(void (__fastcall **)(int))(v3 + 88))(a1);
  }
  else
  {
    sub_2ED00(v1, 0);
  }
  return 0;
}
