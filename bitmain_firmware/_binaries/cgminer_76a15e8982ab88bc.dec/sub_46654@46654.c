void __fastcall sub_46654(int a1)
{
  pthread_t v2; // r0
  int v3; // r4
  char v4[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(v4, 0x1000u, "%s Begin\n", "bitmain_ZCASH_reinit_chain");
    sub_385C8(5, v4, 0);
  }
  v2 = pthread_self();
  pthread_detach(v2);
  pthread_mutex_lock(&stru_75F74);
  v3 = *(unsigned __int8 *)(a1 + 4);
  sub_45700(*(_DWORD *)a1, v3);
  sub_42200(v3);
  sub_2A884();
  sub_425E8(v3, *(unsigned __int16 *)((char *)&unk_9A2A8 + 2 * v3 + 561));
  sub_2A884();
  sub_42358(v3, 0x13880u);
  sub_2A884();
  sub_433BC(v3, dword_7399C);
  sub_2A884();
  sub_45310(v3);
  *((_BYTE *)&dword_75C50[183] + v3) = 1;
  sleep(1u);
  pthread_mutex_unlock(&stru_75F74);
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(v4, 0x1000u, "%s Done\n", "bitmain_ZCASH_reinit_chain");
    sub_385C8(5, v4, 0);
  }
}
