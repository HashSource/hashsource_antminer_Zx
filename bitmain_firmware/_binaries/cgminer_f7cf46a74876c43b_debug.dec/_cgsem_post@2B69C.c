void __fastcall cgsem_post(cgsem_t *cgsem, const char *file, const char *func, const int line)
{
  if ( sem_post(cgsem) )
    cgsem_post_0(cgsem, file, func, line);
}
