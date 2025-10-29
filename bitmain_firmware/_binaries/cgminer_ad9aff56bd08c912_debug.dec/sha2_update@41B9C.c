void __fastcall sha2_update(sha2_context *ctx, const unsigned __int8 *input, int ilen)
{
  if ( ilen > 0 )
    sha2_update_0(ctx, input, ilen);
}
