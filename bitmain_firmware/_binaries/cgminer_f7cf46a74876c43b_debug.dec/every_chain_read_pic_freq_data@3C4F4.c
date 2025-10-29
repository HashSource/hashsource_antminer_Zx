int __fastcall every_chain_read_pic_freq_data(unsigned __int8 (*freq_table)[9])
{
  uint8_t *chain_exist; // r5
  int data_from_PIC16F1704_flash; // r6
  int v4; // r4
  int v5; // t1
  int v7; // r1
  unsigned __int8 *v8; // r12
  unsigned __int8 v9; // r3
  unsigned __int8 buf[9]; // [sp+4h] [bp-100Ch] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  chain_exist = dev.chain_exist;
  data_from_PIC16F1704_flash = 1;
  v4 = 0;
  while ( 1 )
  {
    v5 = *chain_exist++;
    if ( v5 == 1 )
      break;
LABEL_3:
    if ( ++v4 == 4 )
      return data_from_PIC16F1704_flash;
  }
  memset(buf, 0, sizeof(buf));
  pthread_mutex_lock(&iic_mutex);
  i2c_slave_addr = v4;
  data_from_PIC16F1704_flash = read_data_from_PIC16F1704_flash(buf, 0, 9u);
  cgsleep_ms(100);
  pthread_mutex_unlock(&iic_mutex);
  if ( data_from_PIC16F1704_flash )
  {
    if ( data_from_PIC16F1704_flash > 0 )
    {
      xxtea_decode((uint32_t *)&buf[1], 2, sec_key[v4]);
      v7 = *(_DWORD *)&buf[4];
      v8 = &(*freq_table)[9 * v4];
      v9 = buf[8];
      *(_DWORD *)v8 = *(_DWORD *)buf;
      *((_DWORD *)v8 + 1) = v7;
      v8[8] = v9;
    }
    goto LABEL_3;
  }
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "chain%d pic not support flash data storage, adopt file mode\n", v4);
    applog(5, tmp42, 0);
  }
  return data_from_PIC16F1704_flash;
}
