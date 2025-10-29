int gpio_uninit()
{
  int result; // r0

  if ( dword_1852F4 )
  {
    dword_18532C = 0;
    pthread_join(dword_185330, 0);
    pthread_mutex_destroy(&stru_1852F8);
    delete_c_map((void (__fastcall ***)(_DWORD))dword_185310);
    dword_1852F4 = 0;
    return pthread_mutex_destroy(&stru_185314);
  }
  return result;
}
