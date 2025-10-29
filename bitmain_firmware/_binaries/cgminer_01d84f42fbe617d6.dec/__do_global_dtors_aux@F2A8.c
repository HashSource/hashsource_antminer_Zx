int *_do_global_dtors_aux()
{
  int *result; // r0

  if ( !byte_60E84 )
  {
    result = deregister_tm_clones();
    byte_60E84 = 1;
  }
  return result;
}
