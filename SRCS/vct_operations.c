/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:05:55 by phunguye          #+#    #+#             */
/*   Updated: 2023/07/08 15:40:43 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/miniRT.h"
# include <stdlib.h>
# include <math.h>
# include <time.h>

t_vct set_vct(float x, float y, float z, float alpha) {
	t_vct new;
	new.x = x;
	new.y = y;
	new.z = z;
	new.alpha = alpha;
	return(new);
}

float randomFloat() {
    return (float)rand() / RAND_MAX;
}

t_vct rand_vct()
{
  srand(time(NULL));
  t_vct ret = set_vct(randomFloat(), randomFloat(), randomFloat(), 0);
  ret = unit_vct(ret);
  return(ret);
}

t_vct vct_add(t_vct vct1, t_vct vct2) {
	t_vct new;
	new.x = vct1.x + vct2.x;
	new.y = vct1.y + vct2.y;
	new.z = vct1.z + vct2.z;
	return(new);
}

t_vct vct_sub(t_vct vct1, t_vct vct2) {
	t_vct new;
	new.x = vct1.x - vct2.x;
	new.y = vct1.y - vct2.y;
	new.z = vct1.z - vct2.z;
	return(new);
}

t_vct vct_scalar_prod(float scalar, t_vct vct1) {
	t_vct new;
	new.x = vct1.x * scalar;
	new.y = vct1.y * scalar;
	new.z = vct1.z * scalar;
	return(new);
}

float vct_magnitude(t_vct vct) {
	float magnitude;

	magnitude = sqrt(vct.x*vct.x+vct.y*vct.y+vct.z*vct.z);
	return(magnitude);
}

t_vct unit_vct(t_vct direction) {
	t_vct unit_vct;
	float magnitude;

	magnitude = vct_magnitude(direction);
	unit_vct = vct_scalar_prod(1/magnitude, direction);
	return(unit_vct);
}

float vct_dot_prod(t_vct vct1, t_vct vct2) {
	float dot_prod;

	dot_prod = vct1.x*vct2.x + vct1.y*vct2.y + vct1.z*vct2.z;
	return(dot_prod);
}

t_vct vct_cross_prod(t_vct vct1, t_vct vct2) {
	t_vct new;
	new.x = vct1.y * vct2.z - vct1.z * vct2.y;
	new.y = vct1.z * vct2.x - vct1.x * vct2.z;
	new.z = vct1.x * vct2.y - vct1.y * vct2.x;
	return(new);
}

float discrim(float a, float b, float c) {
	float disc;
	disc = (b*b) - (4*a*c);
	return(disc);
}

float quadratic_sol(float a, float b, float c) {
	float disc;
	float sol;
	disc = discrim(a,b,c);
	sol = ((-1*b) - sqrt(disc))/(2*a);
	return(sol);
}

float quadratic_sol2(float a, float b, float c) {
	float disc;
	float sol;
	disc = discrim(a,b,c);
	sol = ((-1*b) + sqrt(disc))/(2*a);
	return(sol);
}

t_vct rotateX(t_vct vector, float angle) {
    float radians = angle * M_PI / 180.0;
    float newY = cos(radians) * vector.y - sin(radians) * vector.z;
    float newZ = sin(radians) * vector.y + cos(radians) * vector.z;
    vector.y = newY;
    vector.z = newZ;
    return vector;
}

t_vct rotateY(t_vct vector, float angle) {
    float radians = angle * M_PI / 180.0;
    float newX = cos(radians) * vector.x + sin(radians) * vector.z;
    float newZ = -sin(radians) * vector.x + cos(radians) * vector.z;
    vector.x = newX;
    vector.z = newZ;
    return vector;
}
