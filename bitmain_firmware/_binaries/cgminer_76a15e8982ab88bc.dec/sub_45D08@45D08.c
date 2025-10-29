int sub_45D08()
{
  char v1[4096]; // [sp+0h] [bp-1000h] BYREF

  dword_9A2A4 = (int)calloc(1u, 0x40u);
  if ( sub_2EFE4(dword_9A2A4, 0, (void *(*)(void *))sub_42894, 0) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(v1, 0x1000u, "%s: create thread for check miner_status", "create_bitmain_turbo_mode_monitor_pthread");
      sub_385C8(7, v1, 0);
    }
    return -5;
  }
  else
  {
    pthread_detach(*(_DWORD *)(dword_9A2A4 + 12));
    return sub_2A884();
  }
}
