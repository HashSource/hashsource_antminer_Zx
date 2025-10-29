void *__fastcall jsonp_malloc(size_t size)
{
  if ( size )
    return do_malloc(size);
  return (void *)size;
}
