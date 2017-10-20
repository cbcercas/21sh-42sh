#include <types/bool.h>
#include <parser/enum.h>

t_bool	is_token_type(t_token_type t)
{
	if (t > E_TOKEN_NONE && t < E_TOKEN_MAX)
		return (true);
	else
		return (false);
};