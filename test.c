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

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void quicksort(int *target, int size);

/* Make sure the sort worked.
 * Add this to main() if needed.
 */
void check(int *target, unsigned int size) {
	int i;

	for (i = 0; i < size -1; i++) {
		assert(target[i] <= target[i+1]);
	}
}

int main(int argc, char *argv[]) {
	int *target;
	int i, stime;
	unsigned int test_size;

	if (argc < 3) {
		fprintf(stderr, "Invocation: %s <type of input> <test size>\n",
		        argv[0]);
		return 1;
	}

	test_size = atoi(argv[2]);
	target = malloc(test_size * sizeof(int));
	if (!target) {
		return 1;
	}

	switch (argv[1][0]) {
		case 'r':
			/* test random disposition */
			srand(time(NULL));
			for (i = 0; i < test_size; i++) {
				target[i] = rand() % test_size;
			}

			break;

		case 'a':
			/* ascending numbers (input already sorted) */
			for (i = 0; i < test_size; i++) {
				target[i] = i;
			}

			break;

		case 'd':
			/* descending numbers (input in reverse order) */
			for (i = test_size -1; i >= 0; i--) {
				target[i] = i;
			}

			break;

		case 'e':
		default:
			/* all elements equal */
			for (i = 0; i < test_size; i++) {
				target[i] = 0;
			}

			break;
		}

	quicksort(target, test_size);

	free(target);
	return 0;
}
