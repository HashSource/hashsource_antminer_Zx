int sub_48A54()
{
  char v1[4096]; // [sp+0h] [bp-1000h] BYREF

  dword_78F54 = (int)calloc(1u, 0x40u);
  if ( sub_2EFE4(dword_78F54, 0, (void *(*)(void *))sub_47748, (void *)dword_78F54) )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(v1, 0x1000u, "%s: create thread for read temp", "create_bitmain_read_temp_pthread");
      sub_385C8(7, v1, 0);
    }
    return -7;
  }
  else
  {
    pthread_detach(*(_DWORD *)(dword_78F54 + 12));
    return sub_2A884();
  }
}
