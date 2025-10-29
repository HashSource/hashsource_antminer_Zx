void opt_log_stderr(const char *fmt, ...)
{
  va_list varg_r1; // [sp+14h] [bp+Ch] BYREF

  va_start(varg_r1, fmt);
  vfprintf((FILE *)stderr, fmt, varg_r1);
  fputc(10, (FILE *)stderr);
}
