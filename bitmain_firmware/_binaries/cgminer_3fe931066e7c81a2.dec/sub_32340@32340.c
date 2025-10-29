void __noreturn sub_32340()
{
  char v0[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( !pthread_mutex_lock(&stru_78CB8) )
  {
    if ( !pthread_mutex_unlock(&stru_78CB8) )
    {
      off_75ED8();
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        strcpy(v0, "API: killing cgminer");
        sub_38730(7, v0, 0);
      }
      sub_178F8();
    }
    sub_B84C("quit_thread", 4938);
  }
  sub_B774("quit_thread", 4937);
}
