void __fastcall sub_4791C(int a1)
{
  pthread_t v2; // r0
  int v3; // r4
  char v4[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(v4, 0x1000u, "%s Begin\n", "bitmain_ZCASH_reinit_chain");
    sub_38730(5, v4, 0);
  }
  v2 = pthread_self();
  pthread_detach(v2);
  pthread_mutex_lock(&stru_79134);
  v3 = *(unsigned __int8 *)(a1 + 4);
  sub_46434(*(_DWORD *)a1, v3);
  sub_42F7C(v3);
  sub_2A92C();
  sub_435E0(v3, *(unsigned __int16 *)((char *)&unk_9D4B4 + 2 * v3 + 593));
  sub_2A92C();
  sub_430A0(v3, 0x13880u);
  sub_2A92C();
  sub_44004(v3, dword_76B60);
  sub_2A92C();
  sub_4601C(v3);
  *((_BYTE *)&dword_78E10[183] + v3) = 1;
  sleep(1u);
  pthread_mutex_unlock(&stru_79134);
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(v4, 0x1000u, "%s Done\n", "bitmain_ZCASH_reinit_chain");
    sub_38730(5, v4, 0);
  }
}
