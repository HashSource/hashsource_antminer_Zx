int sub_320B8()
{
  char v1[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( pthread_mutex_lock(&stru_75AF8) )
    sub_B6BC("restart_thread", 4951);
  if ( pthread_mutex_unlock(&stru_75AF8) )
    sub_B794("restart_thread", 4952);
  off_72D18();
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    strcpy(v1, "API: restarting cgminer");
    sub_385C8(7, v1, 0);
  }
  sub_1D138();
  return 0;
}
