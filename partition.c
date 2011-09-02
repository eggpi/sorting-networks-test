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

/*
 * Partition array 'target' from start index 's' to end index 'e', inclusive.
 * Returns the index of the pivot.
 *
 * Note: Exhibits quadratic behavior on arrays of equal elements.
 */
int partition(int *target, int s, int e) {
	int i, j, p, tmp;

	/* get pivot from median of three */
	p = (s + e)/2;

	if (target[p] > target[s]) {
		if (target[e] > target[s]) {
			/* p > e > s or e > p > s */
			p = (target[p] > target[e]) ? e : p;
		} else p = s;
	} else {
		if (target[e] > target[p]) {
			/* s > e > p or e > s > p */
			p = (target[e] > target[s]) ? s : e;
		}
	}

	/* place pivot in the beginning */
	tmp = target[p];
	target[p] = target[s];
	target[s] = tmp;

	/* partition <= | pivot | >= */
	i = s;
	j = e;
	while (1) {
		while (i < e && target[i] <= target[s]) i++;
		while (j > s && target[j] >= target[s]) j--;

		if (i > j) break;

		tmp = target[i];
		target[i] = target[j];
		target[j] = tmp;

		i++;
		j--;
	}

	/* swap pivot back to its place */
	tmp = target[--i];
	target[i] = target[s];
	target[s] = tmp;

	return i;
}
