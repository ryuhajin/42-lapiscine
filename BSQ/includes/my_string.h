/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:22:35 by jooahn            #+#    #+#             */
/*   Updated: 2023/03/02 02:58:43 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STRING_H
# define MY_STRING_H

int		ft_strlen(char *str);
int		get_input_width(char **input);
int		get_input_height(char **input);
char	*alloc_strcat(char *dst, char *src);
char	**ft_split(char *str);
char	*ft_strncpy(char *src, int n);

#endif
