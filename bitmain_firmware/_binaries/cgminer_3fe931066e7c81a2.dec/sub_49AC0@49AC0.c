int sub_49AC0()
{
  char v1[4096]; // [sp+0h] [bp-1000h] BYREF

  dword_7C05C = (int)calloc(1u, 0x40u);
  if ( sub_2F174(dword_7C05C, 0, (void *(*)(void *))sub_3ABF4, (void *)dword_7C05C) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(
        v1,
        0x1000u,
        "%s: create thread for get hashrate from asic failed",
        "create_bitmain_get_hash_rate_pthread");
      sub_38730(7, v1, 0);
    }
    return -6;
  }
  else
  {
    pthread_detach(*(_DWORD *)(dword_7C05C + 12));
    return sub_2A92C();
  }
}
