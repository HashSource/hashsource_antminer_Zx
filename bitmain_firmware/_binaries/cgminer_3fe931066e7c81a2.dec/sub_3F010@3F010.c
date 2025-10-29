int __fastcall sub_3F010(int a1, int a2, int a3)
{
  char v6; // r0
  unsigned __int16 v8; // [sp+6h] [bp-2h] BYREF

  pthread_mutex_lock(&stru_790D0);
  v8 = 0;
  v6 = *((_BYTE *)&unk_76AC8 + a2 + 128);
  dword_7909C = a1;
  sub_3E564(v6, &v8);
  if ( v8 > a3 + 5 || v8 < a3 - 5 )
  {
    sub_3EA50(*((_BYTE *)&unk_76AC8 + a2 + 128), (unsigned __int16)a3);
    sub_2A92C();
  }
  return pthread_mutex_unlock(&stru_790D0);
}
