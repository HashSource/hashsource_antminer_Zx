// local variable allocation has failed, the output may be wrong!
void __fastcall json_set_alloc_funcs(json_malloc_t malloc_fn, json_free_t free_fn)
{
  *(_QWORD *)&do_malloc = *(_QWORD *)&malloc_fn;
}
