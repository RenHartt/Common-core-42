/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:35:46 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/06 18:48:55 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_stack
{
	int				nbr;
	int				nbr_init;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_move
{
	int	dira;
	int	dirb;
	int	cost;
	int	costa;
	int	costb;
}				t_move;

t_stack	*ft_lstnew(int nbr);
void	ft_lstadd_back(t_stack *list, int nbr);
void	ft_lstfree(t_stack *list);
int		ft_lstsize(t_stack *list);
int		ft_lstlast(t_stack *a);
int		ft_lstfind_min(t_stack *a);
int		ft_lstfind_max(t_stack *a);

int		ft_find_index(t_stack *a, int nbr);
int		ft_find_final_index(t_stack *a, int nbr);

void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);

void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);

void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);

void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

void	ft_a_to_b(t_stack **a, t_stack **b);
void	ft_b_to_a(t_stack **a, t_stack **b);

void	ft_set_space(char *str);
void	ft_set_nbr_to_index(t_stack *a);

size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_free_tab(char **s);
size_t	ft_countwords(char *s, char c);
size_t	ft_countletters(char *s, char c);
char	**ft_split(char *s, char c);

int		ft_atoi(char *str);
double	ft_atol(char *str);

int		*ft_one_arg(char **argv);
int		*ft_many_arg(int argc, char **argv);

int		ft_is_digit(char c);
int		ft_is_double(char **str);
int		ft_is_number(char *str);
int		ft_is_int(char **str);
void	ft_print_list(t_stack *a);

#endif