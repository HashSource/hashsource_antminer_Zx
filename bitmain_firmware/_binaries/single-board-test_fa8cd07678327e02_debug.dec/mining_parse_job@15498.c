void __cdecl mining_parse_job(
        char *str,
        uint8_t *target,
        int target_len,
        char *job_id,
        int job_id_len,
        uint8_t *header,
        int header_len,
        int *fixed_nonce_bytes)
{
  char v8; // r5
  char v9; // r5
  char v10; // r5
  char tmp42[1024]; // [sp+10h] [bp+10h] BYREF
  uint32_t i; // [sp+410h] [bp+410h]
  uint32_t str_i; // [sp+414h] [bp+414h]

  str_i = 0;
  i = 0;
  while ( i < target_len )
  {
    v8 = 16 * hex2val(str, str_i);
    target[i++] = hex2val(str, str_i + 1) + v8;
    str_i += 2;
  }
  if ( str[str_i] != 32 )
    _assert_fail("str[str_i] == ' '", "bm174x/equihash-miner.c", 0x152u, "mining_parse_job");
  ++str_i;
  for ( i = 0; i < job_id_len && str[str_i] != 32; job_id[i++] = str[str_i++] )
    ;
  if ( str[str_i] != 32 )
    _assert_fail("str[str_i] == ' '", "bm174x/equihash-miner.c", 0x158u, "mining_parse_job");
  if ( i >= job_id_len )
    _assert_fail("i < job_id_len", "bm174x/equihash-miner.c", 0x159u, "mining_parse_job");
  job_id[i] = 0;
  ++str_i;
  i = 0;
  while ( i < header_len && str[str_i] != 32 )
  {
    v9 = 16 * hex2val(str, str_i);
    header[i++] = hex2val(str, str_i + 1) + v9;
    str_i += 2;
  }
  if ( str[str_i] != 32 )
    _assert_fail("str[str_i] == ' '", "bm174x/equihash-miner.c", 0x160u, "mining_parse_job");
  ++str_i;
  *fixed_nonce_bytes = 0;
  while ( i < header_len && str[str_i] )
  {
    v10 = 16 * hex2val(str, str_i);
    header[i++] = hex2val(str, str_i + 1) + v10;
    str_i += 2;
    ++*fixed_nonce_bytes;
  }
  if ( str[str_i] )
    _assert_fail("!str[str_i]", "bm174x/equihash-miner.c", 0x16Bu, "mining_parse_job");
  if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 3) )
  {
    snprintf(tmp42, 0x400u, "Randomizing %d bytes in nonce\n", header_len - i - 12);
    applog(4, tmp42, 0);
  }
  randomize(&header[i], header_len - i - 12);
  memset(&header[header_len - 12], 0, 0xCu);
}
