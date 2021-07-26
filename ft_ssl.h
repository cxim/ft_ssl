//
// Created by cxim on 26.07.2021.
//

#ifndef FT_SSL_FT_SSL_H
#define FT_SSL_FT_SSL_H

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf/includes/printf.h"

#define MD5 "md5"
#define SHA256 "sha256"

typedef struct s_flags
{
	int p;
	int q;
	int r;
	int s;

}               t_flags;

typedef struct s_commands
{
	int md5;
	int sha256;

}               t_commands;

typedef struct s_all
{
	char *test_string_for_output;
	char *std_in;
	char *file;
	t_commands  *commands;
	t_flags *flags;
}               t_all;






#endif //FT_SSL_FT_SSL_H
