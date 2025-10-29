int sub_45DE8()
{
  char v1[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( access("/config/chips_freq.config", 0) )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      strcpy(v1, "Goto scan mode and find the best frequency\n");
      sub_385C8(5, v1, 0);
    }
    return sub_45B48();
  }
  else if ( *(unsigned __int16 *)((char *)&dword_9A4CC + 1) == 681 )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      strcpy(v1, "Goto balance mode\n");
      sub_385C8(5, v1, 0);
    }
    return sub_45C28();
  }
  else
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      strcpy(v1, "Goto turbo mode\n");
      sub_385C8(5, v1, 0);
    }
    return sub_45D08();
  }
}
