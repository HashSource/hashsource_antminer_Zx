int __cdecl read_dc_dc(void *args, uint8_t which_i2c, uint8_t i2c_dev_addr, uint8_t reg, uint8_t *value, int len)
{
  int v6; // r4
  uint8_t send_data[9]; // [sp+14h] [bp+Ch] BYREF
  uint8_t read_back_data[16]; // [sp+20h] [bp+18h] BYREF
  uint8_t crc_data[2]; // [sp+30h] [bp+28h]
  uint8_t length; // [sp+32h] [bp+2Ah]
  uint8_t which_chain; // [sp+33h] [bp+2Bh]
  int i_1; // [sp+34h] [bp+2Ch]
  int i_0; // [sp+38h] [bp+30h]
  uint8_t i; // [sp+3Dh] [bp+35h]
  uint16_t crc; // [sp+3Eh] [bp+36h]
  _BYTE v19[4]; // [sp+40h] [bp+38h] BYREF

  which_chain = *(_BYTE *)args;
  length = 7;
  *(_WORD *)crc_data = 255;
  *(_DWORD *)read_back_data = 255;
  memset(&read_back_data[4], 0, 12);
  crc = 0;
  *(_DWORD *)send_data = 839363157;
  send_data[8] = 0;
  *(_DWORD *)&send_data[4] = (unsigned __int8)(2 * i2c_dev_addr) | 1;
  send_data[5] = reg;
  send_data[6] = len;
  for ( i_0 = 2; length > i_0; ++i_0 )
    crc += send_data[i_0];
  crc_data[0] = HIBYTE(crc);
  send_data[7] = HIBYTE(crc);
  crc_data[1] = crc;
  send_data[8] = crc;
  pthread_mutex_lock(&i2c_mutex);
  for ( i = 0; i < length + 2; ++i )
    write_pic(which_i2c, which_chain, v19[i - 44]);
  usleep(0x186A0u);
  memset(read_back_data, 0, sizeof(read_back_data));
  for ( i = 0; i < len + 5; ++i )
  {
    v6 = i;
    read_back_data[v6] = read_pic(which_i2c, which_chain);
  }
  pthread_mutex_unlock(&i2c_mutex);
  usleep((__useconds_t)&nonce_fifo.nonce_buffer[508].Nonce[1188]);
  if ( read_back_data[1] == 50 && read_back_data[2] == 1 )
  {
    for ( i_1 = 0; i_1 < len; ++i_1 )
      value[i_1] = v19[i_1 - 29];
    return 0;
  }
  else
  {
    printf(
      "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x\n",
      "read_dc_dc",
      read_back_data[0],
      read_back_data[1],
      read_back_data[2],
      read_back_data[3]);
    return -1;
  }
}
