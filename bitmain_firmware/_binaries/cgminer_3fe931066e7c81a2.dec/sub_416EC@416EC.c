int sub_416EC()
{
  char v1[4096]; // [sp+0h] [bp-1000h] BYREF

  dword_9D4AC = (int)calloc(1u, 0x40u);
  if ( !sub_2F174(dword_9D4AC, 0, (void *(*)(void *))sub_40034, (void *)dword_9D4AC) )
    return pthread_detach(*(_DWORD *)(dword_9D4AC + 12));
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
  {
    snprintf(v1, 0x1000u, "%s: create thread error for pic_heart_beat_func", "send_heart_beat_to_every_chain");
    sub_38730(3, v1, 0);
  }
  return -3;
}
