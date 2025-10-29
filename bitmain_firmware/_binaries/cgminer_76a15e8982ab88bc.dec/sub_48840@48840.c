int __fastcall sub_48840(void *a1)
{
  char v3[4100]; // [sp+0h] [bp-1004h] BYREF

  dword_78E88 = (int)calloc(1u, 0x40u);
  if ( sub_2EFE4(dword_78E88, 0, (void *(*)(void *))sub_43F14, a1) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(v3, 0x1000u, "%s: create thread for check miner_status", "create_bitmain_check_miner_status_pthread");
      sub_385C8(7, v3, 0);
    }
    return -5;
  }
  else
  {
    pthread_detach(*(_DWORD *)(dword_78E88 + 12));
    return sub_2A884();
  }
}
