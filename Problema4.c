#include <stdio.h>
#define L 1000

void F_digit(int digit, int display[L][L], int len, int width, int N, int M)
{
	int a, b, c, d, e, f, g;
	if (digit == 0) {
		a = 1; b = 1; c = 1; d = 1; e = 1; f = 1; g = 0;
	} else if (digit == 1) {
		a = 0; b = 1; c = 1; d = 0; e = 0; f = 0; g = 0;
	} else if (digit == 2) {
		a = 1; b = 1; c = 0; d = 1; e = 1; f = 0; g = 1;
	} else if (digit == 3) {
		a = 1; b = 1; c = 1; d = 1; e = 0; f = 0; g = 1;
	} else if (digit == 4) {
		a = 0; b = 1; c = 1; d = 0; e = 0; f = 1; g = 1;
	} else if (digit == 5) {
		a = 1; b = 0; c = 1; d = 1; e = 0; f = 1; g = 1;
	} else if (digit == 6) {
		a = 1; b = 0; c = 1; d = 1; e = 1; f = 1; g = 1;
	} else if (digit == 7) {
		a = 1; b = 1; c = 1; d = 0; e = 0; f = 0; g = 0;
	} else if (digit == 8) {
		a = 1; b = 1; c = 1; d = 1; e = 1; f = 1; g = 1;
	} else if (digit == 9) {
		a = 1; b = 1; c = 1; d = 1; e = 0; f = 1; g = 1;
	} else
		printf("The input given is not a digit.\n");
	if (a == 1) {
		for (int i = 0; i < width; i++) {
			for (int j = width; j < len + width; j++) {
				display[i][j] = 1;
			}
		}
	}
	if (b == 1) {
		for (int i = width; i < len + width; i++) {
			for (int j = len + width; j <= M; j++) {
				display[i][j] = 1;
			}
		}
	}
	if (c == 1) {
		for (int i = 2 * width + len; i < N - width; i++) {
			for (int j = len + width; j <= M; j++) {
				display[i][j] = 1;
			}
		}
	}
	if (d == 1) {
		for (int i = N - width; i <= N; i++) {
			for (int j = width; j < len + width; j++) {
				display[i][j] = 1;
			}
		}
	}
	if (e == 1) {
		for (int i = 2 * width + len; i < N - width; i++) {
			for (int j = 0; j < width; j++) {
				display[i][j] = 1;
			}
		}
	}
	if (f == 1) {
		for (int i = width; i < len + width; i++) {
			for (int j = 0; j < width; j++) {
				display[i][j] = 1;
			}
		}
	}
	if (g == 1) {
		for (int i = width + len; i < 2 * width + len; i++) {
			for (int j = width; j < len + width; j++) {
				display[i][j] = 1;
			}
		}
	}
}

void W_command(long count, int display[L][L], int last[L][L], int N, int M)
{
for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
		if (display[i][j] == 1) {
			if (i - count < 0) {
				long remaining = (-1) * (i - count);
				if (N - remaining < 0) {
					if (remaining % N != 0)
						remaining %= N;
					else
						remaining = N;
				}
				display[i][j] = 0;
				last[N - remaining][j] = 1;
			} else {
				display[i][j] = 0;
				display[i - count][j] = 1;
			}
		}
	}
}

for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
		if (last[i][j] == 1) {
			display[i][j] = 1;
			last[i][j] = 0;
		}
	}
}

}

void S_command(long count, int display[L][L], int last[L][L], int N, int M)
{
for (int i = N - 1; i >= 0; i--) {
	for (int j = 0; j < M; j++) {
		if (display[i][j] == 1) {
			if (i + count >= N) {
				long remaining = i + count - N;
				if (remaining - N >= 0) {
					remaining %= N;
				}
				display[i][j] = 0;
				last[remaining][j] = 1;
			} else {
				display[i][j] = 0;
				display[i + count][j] = 1;
			}
		}
	}
}

for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
		if (last[i][j] == 1) {
			display[i][j] = 1;
			last[i][j] = 0;
		}
	}
}

}

void D_command(long count, int display[L][L], int last[L][L], int N, int M)
{
for (int i = 0; i < N; i++) {
	for (int j = M - 1; j >= 0; j--) {
		if (display[i][j] == 1) {
			if (j + count >= M) {
				long remaining = j + count - M;
				if (remaining - M >= 0) {
					remaining %= M;
				}
				display[i][j] = 0;
				last[i][remaining] = 1;
			} else {
				display[i][j] = 0;
				display[i][j + count] = 1;
			}
		}
	}
}

for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
		if (last[i][j] == 1) {
			display[i][j] = 1;
			last[i][j] = 0;
		}
	}
}

}

void A_command(long count, int display[L][L], int last[L][L], int N, int M)
{
for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
		if (display[i][j] == 1) {
			if (j - count < 0) {
				long remaining = (-1) * (j - count);
				if (M - remaining <= 0) {
					if (remaining % M != 0)
						remaining %= M;
					else
						remaining = M;
				}
				display[i][j] = 0;
				last[i][M - remaining] = 1;
			} else {
				display[i][j] = 0;
				display[i][j - count] = 1;
			}
		}
	}
}

for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
		if (last[i][j] == 1) {
			display[i][j] = 1;
			last[i][j] = 0;
		}
	}
}

}

int main(void)
{
	int display[L][L] = {0};
	int N, M, len, width, digit;
	long count;
	char comanda;
	int last[L][L] = {0};
	scanf("%d%d%d", &N, &M, &len);
	width = len / 3;
	scanf(" %c", &comanda);
	while (comanda != 'Q') {
		if (comanda == 'F') {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					display[i][j] = 0;
			scanf("%d", &digit);
			F_digit(digit, display, len, width, N, M);
		} else if (comanda == 'W') {
			scanf("%ld", &count);
			W_command(count, display, last, N, M);
		} else if (comanda == 'S') {
			scanf("%ld", &count);
			S_command(count, display, last, N, M);
		} else if (comanda == 'D') {
			scanf("%ld", &count);
			D_command(count, display, last, N, M);
		} else if (comanda == 'A') {
			scanf("%ld", &count);
			A_command(count, display, last, N, M);
		} else if (comanda == 'P') {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (display[i][j] == 1)
						printf("^ ");
					else
						printf("  ");
				}
				printf("\n");
			}
			printf("\n");
		} else if ((comanda >= 'A') && (comanda <= 'Z')) {
			printf("Invalid command.\n");
		}
		scanf("%c", &comanda);
	}
	return 0;
}
