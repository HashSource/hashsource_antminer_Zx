void __fastcall sub_30AC8(int a1, int a2, int a3)
{
  char *v4; // r7
  signed int v5; // r0
  const char *v6; // r3
  signed int v7; // r4
  int v8; // r5
  int v9; // r10
  _BOOL4 v10; // r3
  fd_set *p_tv_usec; // r3
  int v12; // r0
  ssize_t v13; // r0
  ssize_t v14; // r12
  int v15; // r0
  char *v16; // r0
  ssize_t v17; // [sp+8h] [bp-894h]
  ssize_t v18; // [sp+8h] [bp-894h]
  signed int v20; // [sp+Ch] [bp-890h]
  struct timeval timeout; // [sp+10h] [bp-88Ch] BYREF
  fd_set writefds; // [sp+18h] [bp-884h] BYREF
  char s[2040]; // [sp+98h] [bp-804h] BYREF

  v4 = *(char **)(a1 + 4);
  if ( *(_BYTE *)(a1 + 13) )
  {
    *(_WORD *)&v4[strlen(*(const char **)(a1 + 4))] = 93;
    if ( !a3 )
      goto LABEL_3;
  }
  else if ( !a3 )
  {
    goto LABEL_3;
  }
  strcat(v4, ",\"id\":1}");
LABEL_3:
  v5 = strlen(v4);
  v20 = v5 + 1;
  if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    if ( v5 > 10 )
      v6 = "...";
    else
      v6 = "";
    snprintf(s, 0x800u, "API: send reply: (%d) '%.10s%s'", v20, v4, v6);
    sub_38438(7, s, 0);
  }
  v7 = v20;
  v8 = 0;
  v9 = 0;
  while ( 1 )
  {
    v10 = v7 > 0;
    if ( v9 > 4 )
      v10 = 0;
    if ( !v10 )
      break;
    p_tv_usec = (fd_set *)&timeout.tv_usec;
    timeout.tv_sec = 0;
    timeout.tv_usec = 50000;
    do
    {
      p_tv_usec->__fds_bits[1] = 0;
      p_tv_usec = (fd_set *)((char *)p_tv_usec + 4);
    }
    while ( p_tv_usec != (fd_set *)&writefds.__fds_bits[31] );
    writefds.__fds_bits[a2 / 32] |= 1 << (a2 % 32);
    v12 = select(a2 + 1, 0, &writefds, 0, &timeout);
    if ( v12 <= 0 )
    {
      if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
      {
        snprintf(s, 0x800u, "API: send select failed (%d)", v12);
        sub_38438(4, s, 0);
      }
      return;
    }
    v13 = send(a2, v4, v7, 0);
    ++v8;
    v14 = v13;
    if ( v13 < 0 )
    {
      v15 = *_errno_location();
      if ( v15 != 11 )
      {
        if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
        {
          v16 = strerror(v15);
          snprintf(s, 0x800u, "API: send (%d:%d) failed: %s", v20, v20 - v7, v16);
          sub_38438(4, s, 0);
        }
        return;
      }
LABEL_25:
      ++v9;
    }
    else if ( v8 == 1 )
    {
      if ( v13 != v7 )
      {
        if ( !byte_630C1 || !byte_632F0 && !byte_630C0 && dword_60964 <= 6 )
          goto LABEL_24;
        v17 = v13;
        snprintf(s, 0x800u, "API: sent %d of %d first go", v13, v7);
        goto LABEL_23;
      }
      if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
      {
        v18 = v13;
        snprintf(s, 0x800u, "API: sent all of %d first go", v13);
        goto LABEL_41;
      }
LABEL_42:
      v7 -= v14;
      v4 += v14;
    }
    else
    {
      if ( v13 == v7 )
      {
        if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
        {
          v18 = v13;
          snprintf(s, 0x800u, "API: sent all of remaining %d (sendc=%d)", v13, v8);
LABEL_41:
          sub_38438(7, s, 0);
          v14 = v18;
          goto LABEL_42;
        }
        goto LABEL_42;
      }
      if ( !byte_630C1 || !byte_632F0 && !byte_630C0 && dword_60964 <= 6 )
        goto LABEL_24;
      v17 = v13;
      snprintf(s, 0x800u, "API: sent %d of remaining %d (sendc=%d)", v13, v7, v8);
LABEL_23:
      sub_38438(7, s, 0);
      v14 = v17;
LABEL_24:
      v7 -= v14;
      v4 += v14;
      if ( !v14 )
        goto LABEL_25;
    }
  }
}
