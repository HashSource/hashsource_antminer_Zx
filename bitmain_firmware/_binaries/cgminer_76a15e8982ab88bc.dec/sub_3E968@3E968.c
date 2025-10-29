int __fastcall sub_3E968(int a1, int a2, int a3)
{
  char v6; // r0
  unsigned __int16 v8; // [sp+6h] [bp-2h] BYREF

  pthread_mutex_lock(&stru_75F10);
  v8 = 0;
  v6 = *((_BYTE *)&unk_73908 + a2 + 128);
  dword_75EDC = a1;
  sub_3E224(v6, &v8);
  if ( v8 > a3 + 5 || v8 < a3 - 5 )
  {
    sub_3E3A0(*((_BYTE *)&unk_73908 + a2 + 128), (unsigned __int16)a3);
    sub_2A884();
  }
  return pthread_mutex_unlock(&stru_75F10);
}
