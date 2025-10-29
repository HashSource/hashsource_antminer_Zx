void __noreturn sub_321B0()
{
  char v0[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( !pthread_mutex_lock(&stru_75AF8) )
  {
    if ( !pthread_mutex_unlock(&stru_75AF8) )
    {
      off_72D18();
      if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
      {
        strcpy(v0, "API: killing cgminer");
        sub_385C8(7, v0, 0);
      }
      sub_17830();
    }
    sub_B794("quit_thread", 4938);
  }
  sub_B6BC("quit_thread", 4937);
}
