/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:30:15 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/01 19:12:47 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_PROCESS_H
# define EXECUTE_PROCESS_H

# define EXE_BITS (0x49)
typedef struct s_command	t_command;

int		execute_other(t_command *command);

#endif
