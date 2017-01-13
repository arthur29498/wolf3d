/*
** wolf_messages.h for wolf3d in /home/arthur/delivery/wolf3d/include/
**
** Made by Arthur Philippe
** Login   <arthur.philippe@epitech.eu>
**
** Started on  Tue Jan 10 20:48:26 2017 Arthur Philippe
** Last update Tue Jan 10 21:13:02 2017 Arthur Philippe
*/

#ifndef WOLF_MESSAGES_H_
# define WOLF_MESSAGES_H_

# define MSG_INVALID_MAP	"Map is invalid "
# define MSG_FD_ERROR		" File related error: "
# define MSG_FC_ERROR		" File content error: "
# define MSG_MISSING_FILE	"No such file or directory "
# define MSG_PERMISSION		"Permission denied "
# define MSG_IS_DIR		"Is a directory "
# define MSG_UNKNOWN		"Unexpected file related error "
# define HINT_LOADING_MAP	"Loading map..."
# define HINT_OPENING_WINDOW	"Opening window... "
# define HINT_DONE		"[SUCCESS]\n"
# define HINT_LAUNCHED_GAME	"\nGame core is ready!\n\n"
# define HINT_FAIL		"[FAILURE]\n"
# define HINT_NEXT_LEVEL	"Loading next level... "
# define HINT_EXITED		"Game left.\n"
# define HINT_WIN		"You won. GG!\n"
# define HINT_NUKE_ENV		"Destroying environement..."
# define HINT_NUKE_CONTENT	" freed map content, "
# define HINT_NUKE_PTR		"freed map pointers, "
# define HINT_NUKE_ENV_ENDED	"freed env [SUCCESS]\n"
# define HINT_NUKE_WDW		"Destroying window... "
# define HINT_NUKE_PIXELS	"freed pixels, "
# define HINT_NUKE_FRAMEBUFFER	"freed framebuffer, "
# define HINT_NUKE_TEX		"freed texture and sprite, "
# define HINT_NUKE_WDW_ENDED	"destroyed window [SUCCESS]\n"

#endif /* !WOLF_MESSAGES_H_ */
