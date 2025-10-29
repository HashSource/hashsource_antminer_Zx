int sub_498F4()
{
  char v1[4096]; // [sp+0h] [bp-1000h] BYREF

  dword_7C284 = (int)calloc(1u, 0x40u);
  if ( sub_2F174(dword_7C284, 0, (void *(*)(void *))sub_3AA9C, 0) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(v1, 0x1000u, "%s: create thread for check miner_status", "create_bitmain_check_fan_pthread");
      sub_38730(7, v1, 0);
    }
    return -8;
  }
  else
  {
    pthread_detach(*(_DWORD *)(dword_7C284 + 12));
    return sub_2A92C();
  }
}
