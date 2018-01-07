#include "ft_printf.h"

void	ft_wchar(wchar_t chr, t_var *var, int i)
{
  if (chr > 0)
    var->i_buf -= i;
  if (chr <= 0x7F) //127
      var->buf[var->i_buf++] = chr;
  else if (chr <= 0x7FF) //2047
    {
      var->buf[var->i_buf++] = (chr >> 6) + 0xC0; //192
      var->buf[var->i_buf++] = (chr & 0x3F) + 0x80; //63 128
    }
  else if (chr <= 0xFFFF) //65535
    {
      var->buf[var->i_buf++] = (chr >> 12) + 0xE0; //224
      var->buf[var->i_buf++] = ((chr >> 6) & 0x3F) + 0x80; //63 128
      var->buf[var->i_buf++] = (chr & 0x3F) + 0x80; //63 128
    }
  else if (chr <= 0x10FFFF) //1114111 
    {
      var->buf[var->i_buf++] = (chr >> 18) + 0xF0; // 240
      var->buf[var->i_buf++] = ((chr >> 12) & 0x3F) + 0x80; //63 128
      var->buf[var->i_buf++] = ((chr >> 6) & 0x3F) + 0x80; //63 128
      var->buf[var->i_buf++] = (chr & 0x3F) + 0x80; //63 128
    }
}
