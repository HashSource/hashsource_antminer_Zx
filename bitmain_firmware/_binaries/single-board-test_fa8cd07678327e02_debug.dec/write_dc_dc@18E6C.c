int __cdecl write_dc_dc(void *args, uint8_t which_i2c, uint8_t i2c_dev_addr, uint8_t reg, uint8_t *data, int len)
{
  int v6; // r4
  uint8_t send_data[16]; // [sp+10h] [bp+8h] BYREF
  uint8_t read_back_data[16]; // [sp+20h] [bp+18h] BYREF
  uint8_t crc_data[2]; // [sp+30h] [bp+28h]
  uint8_t length; // [sp+32h] [bp+2Ah]
  uint8_t which_chain; // [sp+33h] [bp+2Bh]
  int j; // [sp+34h] [bp+2Ch]
  int i_0; // [sp+38h] [bp+30h]
  uint8_t i; // [sp+3Dh] [bp+35h]
  uint16_t crc; // [sp+3Eh] [bp+36h]
  _BYTE v21[4]; // [sp+40h] [bp+38h] BYREF

  which_chain = *(_BYTE *)args;
  *(_WORD *)crc_data = 255;
  *(_DWORD *)read_back_data = 255;
  memset(&read_back_data[4], 0, 12);
  crc = 0;
  memset(&send_data[6], 0, 10);
  length = len + 6;
  printf("%s dev addr = %02x\n", "write_dc_dc", i2c_dev_addr);
  send_data[0] = 85;
  send_data[1] = -86;
  send_data[2] = len + 6;
  send_data[3] = 50;
  send_data[4] = 2 * i2c_dev_addr;
  send_data[5] = reg;
  for ( i_0 = 0; i_0 < len; ++i_0 )
    v21[i_0 - 42] = data[i_0];
  for ( j = 2; len + 6 > j; ++j )
    crc += send_data[j];
  crc_data[0] = HIBYTE(crc);
  crc_data[1] = crc;
  v21[len - 42] = HIBYTE(crc);
  v21[len - 41] = crc_data[1];
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i < length + 2; ++i )
    write_pic(which_i2c, which_chain, v21[i - 48]);
  usleep(0x186A0u);
  memset(read_back_data, 0, sizeof(read_back_data));
  for ( i = 0; i <= 4u; ++i )
  {
    v6 = i;
    read_back_data[v6] = read_pic(which_i2c, which_chain);
  }
  pthread_mutex_unlock(&i2c_mutex);
  if ( read_back_data[1] == 50 && read_back_data[2] == 1 )
    return 0;
  printf(
    "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x\n\n",
    "write_dc_dc",
    read_back_data[0],
    read_back_data[1],
    read_back_data[2],
    read_back_data[3]);
  return -1;
}
