int sub_32248()
{
  char v1[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( pthread_mutex_lock(&stru_78CB8) )
    sub_B774("restart_thread", 4951);
  if ( pthread_mutex_unlock(&stru_78CB8) )
    sub_B84C("restart_thread", 4952);
  off_75ED8();
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy(v1, "API: restarting cgminer");
    sub_38730(7, v1, 0);
  }
  sub_1D7C8();
  return 0;
}
