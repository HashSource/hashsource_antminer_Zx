int ui_uninit()
{
  int result; // r0

  if ( dword_185690 )
  {
    dword_18565C[0] = 0;
    pthread_join(dword_185694, 0);
    delete_c_map((void (__fastcall ***)(_DWORD))dword_185678);
    pthread_mutex_destroy(&stru_185660);
    gpio_unreg_callback(921, (int)sub_AD6A8);
    gpio_unreg_callback(943, (int)sub_AD6A8);
    gpio_unexport(941);
    gpio_unexport(942);
    gpio_unexport(921);
    gpio_unexport(943);
    result = gpio_uninit();
    dword_185690 = 0;
  }
  return result;
}
