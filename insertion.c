/*
 * Copyright (C) 2011 Guilherme P. Gonçalves

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdlib.h>
#include <assert.h>

static void insertionsort(int *target, int s, int e);
int partition(int *target, int s, int e);
static void _quicksort(int *target, int s, int e);

static void _quicksort(int *target, int s, int e) {
	int p, length;

	length = e - s + 1;
	if (length <= 1) {
		return;
	}

	if (length <= 8) {
		insertionsort(target, s, e);
		return;
	}

	p = partition(target, s, e);
	_quicksort(target, s, p-1);
	_quicksort(target, p+1, e);

	return;
}

static void insertionsort(int *target, int s, int e) {
	int i, j, tmp;

	for (i = s+1; i <= e; i++) {
		tmp = target[i];
		for (j = i; j > s && target[j-1] > tmp; j--) {
			target[j] = target[j-1];
		}

		target[j] = tmp;
	}

	return;
}

void quicksort(int *target, int size) {
	_quicksort(target, 0, size -1);

	return;
}
