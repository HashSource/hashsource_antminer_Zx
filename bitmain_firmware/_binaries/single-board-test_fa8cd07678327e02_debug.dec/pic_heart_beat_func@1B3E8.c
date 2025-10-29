void *__cdecl __noreturn pic_heart_beat_func(void *arg)
{
  unsigned __int8 which_i2c; // [sp+Ah] [bp+Ah]
  unsigned __int8 which_chain; // [sp+Bh] [bp+Bh]

  which_chain = *(_BYTE *)arg;
  which_i2c = *((_BYTE *)arg + 1);
  while ( 1 )
  {
    heart_beat_PIC16F1704(which_chain, which_i2c);
    sleep(0xAu);
  }
}
