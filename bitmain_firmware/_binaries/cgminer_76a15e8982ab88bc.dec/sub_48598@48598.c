int sub_48598()
{
  char v1[4096]; // [sp+0h] [bp-1000h] BYREF

  dword_79078 = (int)calloc(1u, 0x40u);
  if ( sub_2EFE4(dword_79078, 0, (void *(*)(void *))sub_3A934, 0) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(v1, 0x1000u, "%s: create thread for check miner_status", "create_bitmain_check_fan_pthread");
      sub_385C8(7, v1, 0);
    }
    return -8;
  }
  else
  {
    pthread_detach(*(_DWORD *)(dword_79078 + 12));
    return sub_2A884();
  }
}
