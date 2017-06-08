%token  WORD
%token  NEWLINE
%token  IO_NUMBER
%token  DLESS
%token  DGREAT
%token  LESSAND
%token  GREATAND
%token  LESSGREAT

%tokentemplate E_TOKEN_

%fileincludename enum

%include parser/parser.h

%start  e_program

%%

e_program          : e_linebreak e_complete_commands e_linebreak
| e_linebreak
;
e_complete_commands : e_complete_commands e_newline_list e_complete_command
|                                e_complete_command
;
e_complete_command : e_list e_separator_op
| e_list
;
e_list             : e_list e_separator_op e_and_or
|                   e_and_or
;
e_and_or           : e_pipeline
;
e_pipeline         : e_pipe_sequence
;
e_pipe_sequence    :                             e_command
| e_pipe_sequence '|' e_linebreak e_command
;
e_command          : e_simple_command
;
e_simple_command   : e_cmd_prefix e_cmd_word e_cmd_suffix
| e_cmd_prefix e_cmd_word
| e_cmd_prefix
| e_cmd_name e_cmd_suffix
| e_cmd_name
;
e_cmd_name         : WORD
;
e_cmd_word         : WORD
;
e_cmd_prefix       :            e_io_redirect
| e_cmd_prefix e_io_redirect
;
e_cmd_suffix       :            e_io_redirect
| e_cmd_suffix e_io_redirect
|            WORD
| e_cmd_suffix WORD
;
e_io_redirect      :           e_io_file
| IO_NUMBER e_io_file
|           e_io_here
| IO_NUMBER e_io_here
;
e_io_file          : '<'       e_filename
| LESSAND   e_filename
| '>'       e_filename
| GREATAND  e_filename
| DGREAT    e_filename
| LESSGREAT e_filename
;
e_filename         : WORD
;
e_io_here          : DLESS     e_here_end
;
e_here_end         : WORD
;
e_newline_list     :              NEWLINE
| e_newline_list NEWLINE
;
e_linebreak        : e_newline_list
;
e_separator_op     : ';'
;
e_separator        : e_separator_op e_linebreak
| e_complete_commands
;
e_sequential_sep   : ';' e_linebreak
| e_complete_commands
;
