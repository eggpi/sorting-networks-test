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

int partition(int *target, int s, int e);
static void _quicksort(int *target, int s, int e);

#define SWAP(target, i, j) \
if ((target)[i] > (target)[j]) { \
	int tmp; \
	tmp = (target)[i]; \
	(target)[i] = (target)[j]; \
	(target)[j] = tmp; \
}

#define NSORT2(target) \
SWAP((target), 0, 1)

#define NSORT3(target) \
SWAP((target), 1, 2); SWAP((target), 0, 2); SWAP((target), 0, 1);

#define NSORT4(target) \
SWAP((target), 0, 1); SWAP((target), 2, 3); SWAP((target), 0, 2); \
SWAP((target), 1, 3); SWAP((target), 1, 2);

#define NSORT5(target) \
SWAP((target), 0, 1); SWAP((target), 3, 4); SWAP((target), 2, 4); \
SWAP((target), 2, 3); SWAP((target), 0, 3); SWAP((target), 0, 2); \
SWAP((target), 1, 4); SWAP((target), 1, 3); SWAP((target), 1, 2);

#define NSORT6(target) \
SWAP((target), 1, 2); SWAP((target), 0, 2); SWAP((target), 0, 1); \
SWAP((target), 4, 5); SWAP((target), 3, 5); SWAP((target), 3, 4); \
SWAP((target), 0, 3); SWAP((target), 1, 4); SWAP((target), 2, 5); \
SWAP((target), 2, 4); SWAP((target), 1, 3); SWAP((target), 2, 3);

#define NSORT7(target) \
SWAP((target), 1, 2); SWAP((target), 0, 2); SWAP((target), 0, 1); \
SWAP((target), 3, 4); SWAP((target), 5, 6); SWAP((target), 3, 5); \
SWAP((target), 4, 6); SWAP((target), 4, 5); SWAP((target), 0, 4); \
SWAP((target), 0, 3); SWAP((target), 1, 5); SWAP((target), 2, 6); \
SWAP((target), 2, 5); SWAP((target), 1, 3); SWAP((target), 2, 4); \
SWAP((target), 2, 3);

#define NSORT8(target) \
SWAP((target), 0, 1); SWAP((target), 2, 3); SWAP((target), 0, 2); \
SWAP((target), 1, 3); SWAP((target), 1, 2); SWAP((target), 4, 5); \
SWAP((target), 6, 7); SWAP((target), 4, 6); SWAP((target), 5, 7); \
SWAP((target), 5, 6); SWAP((target), 0, 4); SWAP((target), 1, 5); \
SWAP((target), 1, 4); SWAP((target), 2, 6); SWAP((target), 3, 7); \
SWAP((target), 3, 6); SWAP((target), 2, 4); SWAP((target), 3, 5); \
SWAP((target), 3, 4);

static void _quicksort(int *target, int s, int e) {
	int p, size;

	size = e - s + 1;
	if (size <= 1) {
		return;
	}

	switch (size) {
		case 2:
			NSORT2(target + s);
			break;
		case 3:
			NSORT3(target + s);
			break;
		case 4:
			NSORT4(target + s);
			break;
		case 5:
			NSORT5(target + s);
			break;
		case 6:
			NSORT6(target + s);
			break;
		case 7:
			NSORT7(target + s);
			break;
		case 8:
			NSORT8(target + s);
			break;
		default:
			p = partition(target, s, e);
			_quicksort(target, s, p-1);
			_quicksort(target, p+1, e);
	}

	return;
}

void quicksort(int *target, int size) {
	_quicksort(target, 0, size -1);

	return;
}
