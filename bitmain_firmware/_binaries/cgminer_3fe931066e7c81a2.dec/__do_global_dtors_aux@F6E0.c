int *_do_global_dtors_aux()
{
  int *result; // r0

  if ( !byte_76BD4 )
  {
    result = deregister_tm_clones();
    byte_76BD4 = 1;
  }
  return result;
}
