int *_do_global_dtors_aux()
{
  int *result; // r0

  if ( !completed_9251 )
  {
    result = deregister_tm_clones();
    completed_9251 = 1;
  }
  return result;
}
