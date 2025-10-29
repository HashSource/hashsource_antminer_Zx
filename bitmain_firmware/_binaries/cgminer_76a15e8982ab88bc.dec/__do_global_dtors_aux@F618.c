int *_do_global_dtors_aux()
{
  int *result; // r0

  if ( !byte_73A0C )
  {
    result = deregister_tm_clones();
    byte_73A0C = 1;
  }
  return result;
}
