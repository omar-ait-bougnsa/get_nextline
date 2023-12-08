/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:29 by oait-bou          #+#    #+#             */
/*   Updated: 2023/12/04 16:54:38 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int chek_len(char *str)
{
    int i;
    i = 0;
    while(str[i] !='\0')
    {
        if(str[i] == '\n')
        return(1);
        i++;
    }
    return(0);
}
char *chek_rest(char *buf)
{
    int i;
    int len;
    i = 0;
    char *rst;
    len = strlen(buf);
    while(buf[i] != '\n' && buf[i] != '0')
        i++;
    rst = malloc(sizeof(char) * len - i + 1);
    memcpy(rst,&buf[i],len - i + 1);
    return (rst);

}
char *ft_line(char *str)
{
    int i;
    char *p;
    i = 0;
    while(str[i] != '\0' && str[i] != '\n')
        i++;
    p = malloc(i + 2);
    if(p== NULL)
        return(NULL);
  memcpy(p,str,i+1);
  str[i + 2] = '\0'; 
  return (p);
}
char *get_next_line(int fd)
{
    char buf[BUFFER_SIZE +1];
    char *ptr;
    static char *rest;
    char *next_len;
   ssize_t b = 1;
    if (rest == NULL)
      rest = ft_strjoin("","");
    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    while(b > 0)
    {
        b = read(fd,buf,BUFFER_SIZE);
        buf[b] = '\0';
       ptr = ft_strjoin(rest,buf);
        free(rest);
        rest = ptr;
        if (chek_len(buf)==1)
          break;
    }
    next_len= ft_line(rest);
    free(rest);
    rest = chek_rest(ptr);
    return(next_len);
}
int main()
  {
    int a = open("omar.text", O_CREAT | O_RDWR);

    char *b = get_next_line(a);
    char *c = get_next_line(a);
    printf("%s %s",b,c);
  }