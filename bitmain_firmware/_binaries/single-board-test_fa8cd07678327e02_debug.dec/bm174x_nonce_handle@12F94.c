int __cdecl bm174x_nonce_handle(uint8_t *str, int len, uint32_t chainid, int addr_interval)
{
  uint32_t v5; // r2
  char tmp42[1024]; // [sp+14h] [bp+14h] BYREF
  int ret; // [sp+414h] [bp+414h]
  uint8_t nonce_array_id; // [sp+41Bh] [bp+41Bh]
  uint8_t nonceid; // [sp+41Ch] [bp+41Ch]
  uint8_t chipid; // [sp+41Dh] [bp+41Dh]
  uint8_t chipaddr; // [sp+41Eh] [bp+41Eh]
  uint8_t index; // [sp+41Fh] [bp+41Fh]

  index = str[2] & 0xF;
  chipaddr = str[3];
  chipid = chipaddr / addr_interval;
  nonceid = str[5];
  nonce_array_id = 0;
  ret = 1;
  memcpy((char *)g_nonce_list[chipid] + 91 * index, str + 2, len - 2);
  if ( index != 15 )
    return 1;
  ret = bm174x_nonce_integrality(chipid, nonce_array_id, chainid);
  if ( ret >= 0 )
  {
    push_nonce(&g_nonce[nonce_array_id][chipid]);
    return 0;
  }
  else
  {
    if ( use_syslog || opt_log_output || opt_log_level > 0 )
    {
      v5 = total_error_7672++;
      snprintf(tmp42, 0x400u, "receive a error nonce. total = %u\n", v5);
      applog(1, tmp42, 0);
    }
    return -1;
  }
}
