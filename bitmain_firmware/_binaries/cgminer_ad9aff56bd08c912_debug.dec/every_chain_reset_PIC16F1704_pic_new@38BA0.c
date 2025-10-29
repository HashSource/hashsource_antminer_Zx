void every_chain_reset_PIC16F1704_pic_new()
{
  uint8_t *chain_exist; // r5
  int i; // r4
  int v2; // t1
  const char *v3; // r2
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  chain_exist = dev.chain_exist;
  for ( i = 0; i != 4; ++i )
  {
    v2 = *chain_exist++;
    if ( v2 == 1 )
    {
      LOWORD(v3) = -27508;
      if ( use_syslog || opt_log_output || opt_log_level > 4 )
      {
        HIWORD(v3) = (unsigned int)&unk_59410 >> 16;
        snprintf(tmp42, 0x1000u, v3, i, "every_chain_reset_PIC16F1704_pic_new");
        applog(5, tmp42, 0);
      }
      pthread_mutex_lock(&iic_mutex);
      i2c_slave_addr = i;
      reset_PIC16F1704_pic_new();
      cgsleep_ms(100);
      pthread_mutex_unlock(&iic_mutex);
    }
  }
  cgsleep_ms(500);
}
