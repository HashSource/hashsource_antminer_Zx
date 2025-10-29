int sub_49BE8()
{
  char v1[4096]; // [sp+0h] [bp-1000h] BYREF

  dword_7C12C = (int)calloc(1u, 0x40u);
  if ( sub_2F174(dword_7C12C, 0, (void *(*)(void *))sub_48A18, (void *)dword_7C12C) )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(v1, 0x1000u, "%s: create thread for read temp", "create_bitmain_read_temp_pthread");
      sub_38730(7, v1, 0);
    }
    return -7;
  }
  else
  {
    pthread_detach(*(_DWORD *)(dword_7C12C + 12));
    return sub_2A92C();
  }
}
