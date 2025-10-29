int _do_global_dtors_aux()
{
  int result; // r0

  if ( !completed_10529 )
  {
    result = deregister_tm_clones();
    completed_10529 = 1;
  }
  return result;
}
