/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:00:03 by tscasso           #+#    #+#             */
/*   Updated: 2023/02/23 17:00:07 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*

** La fonction ft_allocate est une fonction statique qui prend trois arguments: 
   un tableau de pointeurs vers des caractères tab 
   une chaîne de caractères s et un caractère sep.

** Cette fonction est utilisée pour allouer de la mémoire
   et stocker chaque mot de la chaîne s séparée 
   par le caractère sep dans le tableau tab.

Voici les étapes qu'elle suit pour cela:

* Définition de deux pointeurs, tab_p initialisé à tab et tmp initialisé à s.

* Une boucle while parcourt la chaîne s tant que le pointeur 
  tmp pointe vers une valeur non nulle.

* La première boucle while passe par-dessus tous les caractères sep en 
  début de chaîne
  pour s'assurer que tmp pointe bien vers un caractère différent de sep.

* La deuxième boucle while parcourt la chaîne s jusqu'à la fin
  ou jusqu'à ce qu'elle rencontre le caractère sep.

* Si tmp pointe sur le caractère sep ou si tmp est plus grand que s,
  cela signifie qu'un mot a été trouvé et qu'il peut être stocké dans tab. 
  Pour cela, on appelle la fonction ft_substr pour 
  allouer de la mémoire pour le mot trouvé

* On copie la sous-chaîne correspondant au mot dans *tab_p 
  et on déplace le pointeur s 
  sur le caractère suivant le dernier caractère du mot trouvé.

* On incrémente également le pointeur tab_p pour passer 
  au prochain élément du tableau tab.

La dernière instruction assigne NULL au dernier élément de tab.

*/

static void	ft_allocate(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char const	*tmp;

	tmp = s;
	tab_p = tab;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*tab_p = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab_p;
		}
	}
	*tab_p = NULL;
}
/*

** La fonction ft_count_words est une fonction statique qui 
   prend deux arguments:
   une chaîne de caractères s et un caractère sep.

** Cette fonction est utilisée pour compter le nombre de mots 
   dans la chaîne s séparée par le caractère sep.

Voici les étapes qu'elle suit pour cela:

* Définition d'une variable word_count initialisée à 0.

* Une boucle while parcourt la chaîne s tant que le pointeur s 
  pointe vers une valeur non nulle.

* La première boucle while passe par-dessus tous les caractères sep 
  en début de chaîne
  pour s'assurer que s pointe bien vers un caractère différent de sep.

* Si s pointe sur un caractère différent de NULL, cela signifie qu'un mot
  a été trouvé
  et word_count est incrémenté.

* La dernière boucle while parcourt la chaîne s jusqu'à la fin ou
  jusqu'à ce qu'elle rencontre le caractère sep.

* À la fin de la boucle while, la fonction retourne la valeur word_count.

*/

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			++s;
	}
	return (word_count);
}
/*

** Sépare la chaîne `s` en mots séparés par `c` 
   et renvoie un tableau de pointeurs vers ces mots.

** Vérifie que la chaîne `s` n'est pas nulle.

** Compte le nombre de mots dans la chaîne `s`.

** Alloue de la mémoire pour stocker les pointeurs vers les mots.

** Stocke chaque mot dans le tableau `new`.

*/

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}
