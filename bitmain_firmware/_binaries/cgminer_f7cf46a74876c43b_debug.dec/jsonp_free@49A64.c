void __fastcall jsonp_free(void *ptr)
{
  if ( ptr )
    do_free(ptr);
}
