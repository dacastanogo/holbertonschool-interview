#include "slide_line.h"

/**
 * slide_line - function that slides and merges an array of integers
 * @line: points to an array of integers
 * @size: number of elements contained in the array line
 * @direction: sliding & merging direction, SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (!line || !size ||
	    (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);
	direction == SLIDE_LEFT ?
		slide_left(line, size)
		: slide_right(line, size);
	return (1);
}

/**
 * slide_left - function that slides and merges to the left
 * @line: points to an array of integers
 * @size: number of elements contained in the array line
 * Return: void
 */

void slide_left(int *line, size_t size)
{
	size_t i, k, l;

	for (i = 0; i < size - 1; i++)
	{
		if (!line[i])
		{
			l = i;
			for (k = i + 1; k <= size - 1; k++)
			{
				if (line[k])
				{
					line[l] = line[k];
					line[k] = 0;
					l++;
				}
			}
		}
		if (!line[i + 1])
		{
			l = i + 1;
			for (k = i + 2; k <= size - 1; k++)
			{
				if (line[k])
				{
					line[l] = line[k];
					line[k] = 0;
					l++;
				}
			}
		}
		if (line[i] && line[i + 1] &&
			line[i] == line[i + 1])
		{
			line[i] = line[i] * 2;
			line[i + 1] = 0;
		}
	}
}

/**
 * slide_right - function that slides and merges to the right
 * @line: points to an array of integers
 * @size: number of elements contained in the array line
 * Return: void
 */

void slide_right(int *line, size_t size)
{
	int i, k, l;

	size = (int)size;
	for (i = size - 1; i > 0; i--)
	{
		if (!line[i])
		{
			l = i;
			for (k = i - 1; k >= 0; k--)
			{
				if (line[k])
				{
					line[l] = line[k];
					line[k] = 0;
					l--;
				}
			}
		}
		if (!line[i - 1])
		{
			l = i - 1;
			for (k = i - 2; k >= 0; k--)
			{
				if (line[k])
				{
					line[l] = line[k];
					line[k] = 0;
					l--;
				}
			}
		}
		if (line[i] && line[i - 1] &&
		    line[i] == line[i - 1])
		{
			line[i] = line[i] * 2;
			line[i - 1] = 0;
		}
	}
}
