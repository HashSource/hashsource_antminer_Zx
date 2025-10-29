void __fastcall default_save_file(char *filename)
{
  char *v2; // r0

  if ( default_config && *default_config )
  {
    j_strcpy(filename, default_config);
  }
  else
  {
    if ( getenv("HOME") && *getenv("HOME") )
    {
      v2 = getenv("HOME");
      *(_WORD *)stpcpy(filename, v2) = 47;
    }
    else
    {
      *filename = 0;
    }
    strcat(filename, ".cgminer/");
    mkdir(filename, 0x1FFu);
    strcat(filename, "cgminer.conf");
  }
}
