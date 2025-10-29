char *__fastcall set_rotate(const char *arg, char *i)
{
  char *result; // r0

  pool_strategy_0 = pool_strategy::POOL_ROTATE;
  result = opt_set_intval(arg, &opt_rotate_period);
  if ( !result && (unsigned int)opt_rotate_period > 0x270F )
    return "Value out of range";
  return result;
}
