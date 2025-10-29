int __fastcall sub_11D5C(int a1)
{
  _DWORD *v1; // r6
  int v3; // r5
  char v5[16]; // [sp+0h] [bp-1010h] BYREF
  char v6[4096]; // [sp+10h] [bp-1000h] BYREF

  v1 = *(_DWORD **)(a1 + 36);
  v3 = v1[1];
  snprintf(v5, 0x10u, "%d/Miner", *(_DWORD *)a1);
  sub_2EF24(v5);
  sub_FB90(a1);
  if ( (*(int (__fastcall **)(int))(v3 + 52))(a1) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      strcpy(v6, "Waiting on sem in miner thread");
      sub_385C8(7, v6, 0);
    }
    sub_2F0F0((sem_t *)(a1 + 16), "cgminer.c", "miner_thread", 9134);
    v1[58] = time(0);
    (*(void (__fastcall **)(int))(v3 + 60))(a1);
    (*(void (__fastcall **)(int))(v3 + 88))(a1);
  }
  else
  {
    sub_2EBF8(v1, 0);
  }
  return 0;
}
