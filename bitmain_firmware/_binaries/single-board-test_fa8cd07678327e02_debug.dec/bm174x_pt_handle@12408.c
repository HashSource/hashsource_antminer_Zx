void __cdecl bm174x_pt_handle(uint8_t *str, int len, uint8_t chainid)
{
  unsigned __int16 v3; // r0
  char tmp42[1024]; // [sp+20h] [bp+10h] BYREF
  FILE *fpt; // [sp+420h] [bp+410h]
  uint16_t crc16; // [sp+426h] [bp+416h]
  pattern_test_respond *pt; // [sp+428h] [bp+418h]
  int i; // [sp+42Ch] [bp+41Ch]

  pt = (pattern_test_respond *)str;
  v3 = CRC16_v1(str + 2, len - 4);
  crc16 = HIBYTE(v3) | (v3 << 8);
  if ( crc16 == pt->crc16 )
  {
    fpt = fopen("./pattern_result.txt", "a+");
    if ( fpt )
    {
      for ( i = 0; i <= 127; ++i )
        dump_str(fpt, 0, &pt->pt_result_data[8 * i], 8);
      fclose(fpt);
    }
    else if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      strcpy(tmp42, "open failed pattern_result.txt\n");
      applog(2, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    snprintf(
      tmp42,
      0x400u,
      "%s chainid=%d cal crc = %04x, chip crc = %04x\n",
      "bm174x_pt_handle",
      chainid,
      crc16,
      pt->crc16);
    applog(2, tmp42, 0);
  }
}
