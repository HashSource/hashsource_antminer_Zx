int __fastcall sub_499D4(void *a1)
{
  char v3[4100]; // [sp+0h] [bp-1004h] BYREF

  dword_7C060 = (int)calloc(1u, 0x40u);
  if ( sub_2F174(dword_7C060, 0, (void *(*)(void *))sub_44B5C, a1) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(v3, 0x1000u, "%s: create thread for check miner_status", "create_bitmain_check_miner_status_pthread");
      sub_38730(7, v3, 0);
    }
    return -5;
  }
  else
  {
    pthread_detach(*(_DWORD *)(dword_7C060 + 12));
    return sub_2A92C();
  }
}
