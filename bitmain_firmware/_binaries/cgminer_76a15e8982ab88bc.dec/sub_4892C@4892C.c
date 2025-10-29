int sub_4892C()
{
  char v1[4096]; // [sp+0h] [bp-1000h] BYREF

  dword_78E84 = (int)calloc(1u, 0x40u);
  if ( sub_2EFE4(dword_78E84, 0, (void *(*)(void *))sub_3AA8C, (void *)dword_78E84) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(
        v1,
        0x1000u,
        "%s: create thread for get hashrate from asic failed",
        "create_bitmain_get_hash_rate_pthread");
      sub_385C8(7, v1, 0);
    }
    return -6;
  }
  else
  {
    pthread_detach(*(_DWORD *)(dword_78E84 + 12));
    return sub_2A884();
  }
}
