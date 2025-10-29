// local variable allocation has failed, the output may be wrong!
int __fastcall set_PIC16F1704_flash_pointer_new(unsigned __int8 flash_addr_h, unsigned __int8 flash_addr_l)
{
  char *v2; // r4
  int i; // r3
  int v4; // t1
  int v5; // r4
  int v6; // r7
  bool v7; // zf
  int result; // r0
  int v9; // [sp+10h] [bp-100Ch] BYREF
  unsigned __int8 flash_addr_ha; // [sp+14h] [bp-1008h]
  unsigned __int8 v11; // [sp+15h] [bp-1007h]
  char v12; // [sp+16h] [bp-1006h]
  char v13; // [sp+17h] [bp-1005h]
  char tmp42[4100]; // [sp+18h] [bp-1004h] BYREF

  flash_addr_ha = flash_addr_h;
  v13 = flash_addr_l + 7 + flash_addr_h;
  v12 = (unsigned __int16)(flash_addr_l + 7 + flash_addr_h) >> 8;
  v11 = flash_addr_l;
  v9 = 17214037;
  v2 = (char *)&v9 + 1;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 85; ; i = v4 )
  {
    i2c_write(i | 0xA00000 | (i2c_slave_addr << 16));
    if ( tmp42 == v2 )
      break;
    v4 = (unsigned __int8)*v2++;
  }
  usleep(0x186A0u);
  v5 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  v6 = i2c_read((i2c_slave_addr << 16) | 0xA00000);
  pthread_mutex_unlock(&i2c_mutex);
  v7 = v6 == 1;
  if ( v6 == 1 )
    v7 = v5 == 1;
  if ( v7 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 4 )
    {
      snprintf(tmp42, 0x1000u, "%s ok", "set_PIC16F1704_flash_pointer_new");
      applog(5, tmp42, 0);
      return 1;
    }
    else
    {
      return 1;
    }
  }
  else if ( use_syslog || (result = opt_log_output) != 0 || opt_log_level > 2 )
  {
    snprintf(
      tmp42,
      0x1000u,
      "%s chain %d failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
      "set_PIC16F1704_flash_pointer_new",
      i2c_slave_addr,
      v5,
      v6);
    applog(3, tmp42, 0);
    return 0;
  }
  return result;
}
