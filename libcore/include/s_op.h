/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 14:56:23 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/29 15:22:16 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_OP_H
# define S_OP_H

struct	s_op
{
	char	mnu[5];
	int		argc;
	int		arg_type[3];
	char	bytecode;
	int		cost;
	char	description[64];
	int		unknown1;
	int		unknown2;
};

#endif S_OP_H