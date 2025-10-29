void __cdecl delay(int seconds)
{
  int v1; // r3
  char tmp42[1024]; // [sp+Ch] [bp+Ch] BYREF
  int i; // [sp+40Ch] [bp+40Ch]

  i = 0;
  while ( 1 )
  {
    v1 = i++;
    if ( v1 >= seconds )
      break;
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      snprintf(tmp42, 0x400u, "remain %d seconds......\n", seconds - i);
      applog(2, tmp42, 0);
    }
    sleep(1u);
  }
}
