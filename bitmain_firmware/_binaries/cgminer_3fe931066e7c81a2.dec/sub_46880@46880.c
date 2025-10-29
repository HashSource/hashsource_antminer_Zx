int sub_46880()
{
  char v1[4096]; // [sp+0h] [bp-1000h] BYREF

  dword_9D4B0 = (int)calloc(1u, 0x40u);
  if ( sub_2F174(dword_9D4B0, 0, (void *(*)(void *))sub_47354, 0) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(v1, 0x1000u, "%s: create thread for check miner_status", "create_bitmain_scan_freq_pthread");
      sub_38730(7, v1, 0);
    }
    return -5;
  }
  else
  {
    pthread_detach(*(_DWORD *)(dword_9D4B0 + 12));
    sub_2A92C();
    return 0;
  }
}
