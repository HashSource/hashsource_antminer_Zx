uint8_t __cdecl hex2val(const char *base, size_t off)
{
  char tmp42[1027]; // [sp+14h] [bp+Ch] BYREF
  char c; // [sp+417h] [bp+40Fh]

  c = base[off];
  if ( (unsigned __int8)c > 0x2Fu && (unsigned __int8)c <= 0x39u )
    return c - 48;
  if ( (unsigned __int8)c > 0x60u && (unsigned __int8)c <= 0x66u )
    return c - 87;
  if ( (unsigned __int8)c > 0x40u && (unsigned __int8)c <= 0x46u )
    return c - 55;
  if ( use_syslog || opt_log_output || opt_log_level >= 0 )
  {
    snprintf(tmp42, 0x400u, "Invalid hex char at offset %zd: ...%c...\n", off, (unsigned __int8)c);
    applog(0, tmp42, 0);
  }
  return 0;
}
