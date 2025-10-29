void __fastcall _libc_csu_init(int argc, char **argv, char **envp)
{
  int v6; // r5
  int i; // r4
  void (__fastcall *v8)(int, char **, char **); // r3

  init_proc();
  v6 = &_do_global_dtors_aux_fini_array_entry - &_frame_dummy_init_array_entry;
  if ( v6 )
  {
    for ( i = 0; i != v6; ++i )
    {
      v8 = (void (__fastcall *)(int, char **, char **))*(&_frame_dummy_init_array_entry + i);
      v8(argc, argv, envp);
    }
  }
}
