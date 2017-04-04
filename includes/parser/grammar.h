# ifndef MINISHELL_GRAMMAR_H
# define MINISHELL_GRAMMAR_H

t_bool	gr_complete_cmd(t_array *tokens, size_t where);

t_bool	gr_list(t_array *tokens, size_t where);

t_bool	gr_separator(t_array *tokens, size_t where);

t_bool	gr_separator_op(t_array *tokens, size_t where);

t_bool	gr_and_or(t_array *tokens, size_t where);

t_bool	gr_linebreak(t_array *tokens, size_t where);

t_bool	gr_newline_list(t_array *tokens, size_t where);

t_bool	gr_pipeline(t_array *tokens, size_t where);

t_bool	gr_check_or_if(t_array *tokens, size_t where);

t_bool	gr_check_and_if(t_array *tokens, size_t where);

t_bool	gr_pipe_sequence(t_array *tokens, size_t where);

t_bool	gr_simple_command(t_array *tokens, size_t where);

t_bool	gr_command(t_array *tokens, size_t where);

t_bool	gr_cmd_suffix(t_array *tokens, size_t where);

t_bool	gr_cmd_prefix(t_array *tokens, size_t where);

t_bool	gr_cmd_word(t_array *tokens, size_t where);

t_bool	gr_cmd_name(t_array *tokens, size_t where);

t_bool	gr_io_redirect(t_array *tokens, size_t where);

t_bool	gr_io_file(t_array *tokens, size_t where);

t_bool	gr_io_here(t_array *tokens, size_t where);

t_bool	gr_filename(t_array *tokens, size_t where);

t_bool	gr_here_end(t_array *tokens, size_t where);

#endif MINISHELL_GRAMMAR_H

/*
**static const uint32_t grammar[SYM_MAX][SYM_MAX][4] =
**{
**complete_command
**	{
**		{
**			list,
**			separator
**		},
**		{
**			list
**		}
**	},
** list
**	{
**		{
**			list,
**			separator_op,
**			and_or
**		},
**		{
**			and_or
**		}
**	},
** and_or
**	{
**		{
**				pipeline
**		},
**			{
**					and_or,
**					E_TOKEN_AND_IF,
**					linebreak,
**					pipeline
**			},
**			{
**					and_or,
**					E_TOKEN_OR_IF,
**					linebreak,
**					pipeline
**		}
**	},
** pipeline
**	{
**		{
**			pipe_sequence
**		}
**	},
**newline_list
**	{
**		{
**			E_TOKEN_NEWLINE
**		},
**		{
**			newline_list,
**				E_TOKEN_NEWLINE
**		}
**	},
** separator_op
**	{
**		{
**			'&',
**			';'
**		}
**	},
**separator
**	{
**		{
**			separator_op,
**			linebreak
**		}
**	},
**linebreak
**	{
**		{
**			newline_list
**		}
**	},
**pipe_sequence
**	{
**		{
**			command
**		},
**		{
**			pipe_sequence,
**			'|',
**			linebreak,
**			command
**		}
**	},
**command
**	{
**		{
**			simple_command
**		}
**	},
**simple_command
**	{
**		{
**			cmd_prefix,
**			cmd_word,
**			cmd_suffix
**		},
**		{
**			cmd_prefix,
**			cmd_word
**		},
**		{
**			cmd_prefix
**		},
**		{
**			cmd_name,
**			cmd_suffix
**		},
**		{
**			cmd_name
**		}
**	},
**cmd_prefix
**	{
**		{
**			io_redirect
**		},
**		{
**			cmd_prefix,
**			io_redirect
**		}
**	},
**cmd_word
**	{
**		{
**				E_TOKEN_WORD
**		}
**	},
**cmd_name
**	{
**		{
**				E_TOKEN_WORD
**		}
**	},
**cmd_suffix
**	{
**		{
**			io_redirect
**		},
**		{
**			cmd_suffix,
**			io_redirect
**		},
**		{
**				E_TOKEN_WORD
**		},
**		{
**			cmd_suffix,
**				E_TOKEN_WORD
**		}
**	},
**io_redirect
**	{
**		{
**			io_file
**		},
**		{
**				E_TOKEN_IO_NUMBER,
**			io_file
**		},
**		{
**			io_here
**		},
**		{
**				E_TOKEN_IO_NUMBER,
**			io_here
**		}
**	},
**io_file
**	{
**		{
**			'<',
**			filename
**		},
**		{
**				E_TOKEN_LESSAND,
**			filename
**		},
**		{
**			'>',
**			filename
**		},
**		{
**				E_TOKEN_GREATAND,
**			filename
**		},
**		{
**				E_TOKEN_DGREAT,
**			filename
**		},
**		{
**				E_TOKEN_LESSGREAT,
**			filename
**		}
**	},
**io_here
**	{
**		{
**				E_TOKEN_DLESS,
**			here_end
**		}
**	},
**filename
**	{
**		{
**				E_TOKEN_WORD
**		}
**	},
**here_end
**	{
**		{
**				E_TOKEN_WORD
**		}
**	}
**};
*/
