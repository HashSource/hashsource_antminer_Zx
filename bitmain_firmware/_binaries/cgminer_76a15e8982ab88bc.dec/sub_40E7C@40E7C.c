int sub_40E7C()
{
  char v1[4096]; // [sp+0h] [bp-1000h] BYREF

  dword_9A2A0 = (int)calloc(1u, 0x40u);
  if ( !sub_2EFE4(dword_9A2A0, 0, (void *(*)(void *))sub_3F8BC, (void *)dword_9A2A0) )
    return pthread_detach(*(_DWORD *)(dword_9A2A0 + 12));
  if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
  {
    snprintf(v1, 0x1000u, "%s: create thread error for pic_heart_beat_func", "send_heart_beat_to_every_chain");
    sub_385C8(3, v1, 0);
  }
  return -3;
}
