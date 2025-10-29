void __fastcall sub_49700(int a1, int a2)
{
  char v4[4100]; // [sp+0h] [bp-1004h] BYREF

  pthread_mutex_lock(&stru_79134);
  sub_46434(a1, a2);
  pthread_mutex_unlock(&stru_79134);
  sub_481B4();
  sub_2A92C();
  sub_4952C(a2, 1);
  sub_2A92C();
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(v4, 0x1000u, "%s DONE!", "recheck_asic_num");
    sub_38730(5, v4, 0);
  }
}
