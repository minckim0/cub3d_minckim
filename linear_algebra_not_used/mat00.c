/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 04:27:59 by minckim           #+#    #+#             */
/*   Updated: 2020/07/07 04:35:16 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_algebra.h"

t_mat	mat_new(real *a)
{
	t_mat	m;

	m.a = a[0];
	m.b = a[1];
	m.c = a[2];
	m.d = a[3];
	m.e = a[4];
	m.f = a[5];
	m.g = a[6];
	m.h = a[7];
	m.i = a[8];
	return (m);
}

t_mat	mat_add(t_mat a, t_mat b)
{
	a.a += b.a;
	a.b += b.b;
	a.c += b.c;
	a.d += b.d;
	a.e += b.e;
	a.f += b.f;
	a.g += b.g;
	a.h += b.h;
	a.i += b.i;
	return (a);
}

t_mat	mat_sub(t_mat a, t_mat b)
{
	a.a -= b.a;
	a.b -= b.b;
	a.c -= b.c;
	a.d -= b.d;
	a.e -= b.e;
	a.f -= b.f;
	a.g -= b.g;
	a.h -= b.h;
	a.i -= b.i;
	return (a);
}

t_mat	mat_mul(t_mat a, t_mat b)
{
	t_mat	r;

	r.a = a.a * b.a + a.b * b.d + a.c * b.g;
	r.b = a.a * b.b + a.b * b.e + a.c * b.h;
	r.c = a.a * b.c + a.b * b.f + a.c * b.i;
	r.d = a.d * b.a + a.e * b.d + a.f * b.g;
	r.e = a.d * b.b + a.e * b.e + a.f * b.h;
	r.f = a.d * b.c + a.e * b.f + a.f * b.i;
	r.g = a.g * b.a + a.h * b.d + a.i * b.g;
	r.h = a.g * b.b + a.h * b.e + a.i * b.h;
	r.i = a.g * b.c + a.h * b.f + a.i * b.i;
	return (r);
}