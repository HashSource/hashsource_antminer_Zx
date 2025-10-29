void __fastcall init(int argc, char **argv, char **envp)
{
  void (__fastcall **v6)(int, char **, char **); // r5
  int v7; // r6
  int i; // r4
  void (__fastcall *v9)(int, char **, char **); // t1

  init_proc();
  v6 = (void (__fastcall **)(int, char **, char **))&_frame_dummy_init_array_entry;
  v7 = &_do_global_dtors_aux_fini_array_entry - &_frame_dummy_init_array_entry;
  if ( v7 )
  {
    for ( i = 0; i != v7; ++i )
    {
      v9 = *v6++;
      v9(argc, argv, envp);
    }
  }
}
