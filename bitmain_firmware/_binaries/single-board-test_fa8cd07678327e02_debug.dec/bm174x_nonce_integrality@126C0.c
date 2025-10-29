int __cdecl bm174x_nonce_integrality(uint8_t chipid, uint8_t nonce_array_id, int chainid)
{
  uint8_t chainida; // [sp+10h] [bp+0h]
  char tmp42[1026]; // [sp+1Ch] [bp+Ch] BYREF
  uint16_t crc16; // [sp+41Eh] [bp+40Eh] BYREF
  uint8_t *nonce_p; // [sp+420h] [bp+410h]
  int i; // [sp+424h] [bp+414h]

  chainida = chainid;
  for ( i = 0; i <= 15; ++i )
  {
    crc16 = CRC16_v1(g_nonce_list[nonce_array_id][chipid][i], 89);
    crc16 = HIBYTE(crc16) | (crc16 << 8);
    if ( memcmp(&crc16, &g_nonce_list[chipid][nonce_array_id][i][89], 2u) )
    {
      if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        snprintf(
          tmp42,
          0x400u,
          "%s CRC error. cal-crc=%x, chip-crc=%02x%02x\n",
          "bm174x_nonce_integrality",
          crc16,
          g_nonce_list[chipid][nonce_array_id][i][89],
          g_nonce_list[chipid][nonce_array_id][i][90]);
        applog(0, tmp42, 0);
      }
      return -1;
    }
  }
  for ( i = 0; i <= 15; ++i )
  {
    if ( (g_nonce_list[chipid][nonce_array_id][i][0] & 0xF) != i )
    {
      if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        snprintf(tmp42, 0x400u, "nonce is not continous i=%d\n", i);
        applog(0, tmp42, 0);
      }
      return -1;
    }
  }
  for ( i = 0; i <= 14; ++i )
  {
    if ( g_nonce_list[chipid][nonce_array_id][i][1] != g_nonce_list[chipid][nonce_array_id][i + 1][1] )
    {
      if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        snprintf(
          tmp42,
          0x400u,
          "chip_addr is different %02x != %02x\n",
          g_nonce_list[chipid][nonce_array_id][i][1],
          g_nonce_list[chipid][nonce_array_id][i + 1][1]);
        applog(0, tmp42, 0);
      }
      return -1;
    }
  }
  for ( i = 0; i <= 14; ++i )
  {
    if ( g_nonce_list[chipid][nonce_array_id][i][2] != g_nonce_list[chipid][nonce_array_id][i + 1][2] )
    {
      if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        snprintf(
          tmp42,
          0x400u,
          "workID is different %02x != %02x\n",
          g_nonce_list[chipid][nonce_array_id][i][2],
          g_nonce_list[chipid][nonce_array_id][i + 1][2]);
        applog(0, tmp42, 0);
      }
      return -1;
    }
  }
  for ( i = 0; ; ++i )
  {
    if ( i > 14 )
    {
      nonce_p = g_nonce[nonce_array_id][chipid].Nonce;
      for ( i = 0; i <= 14; ++i )
      {
        memcpy(nonce_p, &g_nonce_list[chipid][nonce_array_id][i][4], 0x55u);
        nonce_p += 85;
      }
      memcpy(nonce_p, &g_nonce_list[nonce_array_id][chipid][15][4], 0x45u);
      memcpy(
        g_nonce[nonce_array_id][chipid].chip_nonce,
        &g_nonce_list[nonce_array_id][chipid][15][85],
        sizeof(g_nonce[nonce_array_id][chipid].chip_nonce));
      g_nonce[chipid][nonce_array_id].chip_addr = g_nonce_list[chipid][nonce_array_id][15][1];
      g_nonce[chipid][nonce_array_id].work_id = g_nonce_list[chipid][nonce_array_id][15][2];
      g_nonce[chipid][nonce_array_id].nonce_id = g_nonce_list[chipid][nonce_array_id][15][3];
      g_nonce[chipid][nonce_array_id].diff0 = g_nonce_list[chipid][nonce_array_id][15][76];
      memcpy(
        g_nonce[chipid][nonce_array_id].sha256,
        &g_nonce_list[nonce_array_id][chipid][15][77],
        sizeof(g_nonce[chipid][nonce_array_id].sha256));
      g_nonce[chipid][nonce_array_id].chain_id = chainida;
      return 0;
    }
    if ( g_nonce_list[chipid][nonce_array_id][i][3] != g_nonce_list[chipid][nonce_array_id][i + 1][3] )
      break;
  }
  if ( use_syslog || opt_log_output || opt_log_level >= 0 )
  {
    snprintf(
      tmp42,
      0x400u,
      "nonceID is different %02x != %02x chipid=%d\n",
      g_nonce_list[chipid][nonce_array_id][i][3],
      g_nonce_list[chipid][nonce_array_id][i + 1][3],
      chipid);
    applog(0, tmp42, 0);
  }
  return -1;
}
