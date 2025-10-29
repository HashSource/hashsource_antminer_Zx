void *__fastcall __noreturn pic_heart_beat_func_new(void *arg)
{
  uint8_t *chain_exist; // r5
  int v2; // r4
  char tmp42[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    strcpy(tmp42, "pic_heart_beat_func_new");
    applog(5, tmp42, 0);
  }
  while ( 1 )
  {
    chain_exist = dev.chain_exist;
    v2 = 0;
    sleep(0xAu);
    do
    {
      if ( *chain_exist++ )
      {
        if ( send_heart )
        {
          pthread_mutex_lock(&iic_mutex);
          i2c_slave_addr = v2;
          heart_beat_PIC16F1704_new();
          cgsleep_ms(100);
          pthread_mutex_unlock(&iic_mutex);
        }
      }
      ++v2;
    }
    while ( v2 != 4 );
  }
}
