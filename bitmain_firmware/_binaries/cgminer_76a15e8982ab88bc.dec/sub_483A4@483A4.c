void __fastcall sub_483A4(int a1, int a2)
{
  char v4[4100]; // [sp+0h] [bp-1004h] BYREF

  pthread_mutex_lock(&stru_75F74);
  sub_45700(a1, a2);
  pthread_mutex_unlock(&stru_75F74);
  sub_46EEC();
  sub_2A884();
  sub_481D0(a2, 1);
  sub_2A884();
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(v4, 0x1000u, "%s DONE!", "recheck_asic_num");
    sub_385C8(5, v4, 0);
  }
}
