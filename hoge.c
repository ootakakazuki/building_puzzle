#include <stdio.h>

int g_up_box[4];
int g_down_box[4];
int g_left_box[4];
int g_right_box[4];
char field[4][4];
int seg[4] = {8, 16, 24, 31};

int		from_up_check(int j)
{
	int		k = 1;
	int		max_count = 1;
	int		pro_val = (field[0][j] - '0');
	while (k <= 3)
	{
		if (pro_val < (field[k][j] - '0'))
		{
			pro_val = field[k][j] - '0';
			max_count++;
		}
		k++;
	}
	return (max_count == g_up_box[j]) ? 1 : 0;
}


int		from_down_check(int j)
{
	int		k = 2;
	int		max_count = 1;
	int		pro_val = (field[3][j] - '0');
	while (k <= 3)
	{
		if (pro_val < (field[k][j] - '0'))
		{
			pro_val = field[k][j] - '0';
			max_count++;
		}
		k--;
	}
	return (max_count == g_down_box[j]) ? 1 : 0;
}


int		from_left_check(int i)
{
	int		k = 1;
	int		max_count = 1;
	int		pro_val = (field[i][0] - '0');
	while (k <= 3)
	{
		if (pro_val < (field[i][k] - '0'))
		{
			pro_val = field[i][k] - '0';
			max_count++;
		}
		k++;
	}
	return (max_count == g_left_box[i]) ? 1 : 0;
}


int		from_right_check(int i)
{
	int		k = 2;
	int		max_count = 1;
	int		pro_val = (field[i][3] - '0');
	while (k >= 0)
	{
		if (pro_val < (field[i][k] - '0'))
		{
			pro_val = field[i][k] - '0';
			max_count++;
		}
		k--;
	}
	return (max_count == g_right_box[i]) ? 1 : 0;
}




int		row_check(int num, int i, int j)
{
	int		j_tmp = 0;
	
	while (j_tmp < j)
	{
		if (field[i][j_tmp] == num) return 0;
		j_tmp++;
	}
	return 1;
}

int		col_check(int num, int i, int j)
{
	int 	i_tmp = 0;

	while (i_tmp < i)
	{
		if (field[i_tmp][j] == num) return 0;
		i_tmp++;
	}
	return 1;
}

void	print_field()
{
	int 	i = 0;

	while (i < 4)
	{
		int j = 0;
		while (j < 4)
		{
			if (j == 3)
			{
				printf("%d\n", field[i][j]);
			}
			else
			{
				 printf("%d ", field[i][j]);
			}
			j++;
		}
		i++;
	}
	printf("\n");
}

// 再帰を利用して数を入力
int		back_track(int i, int j)
{
	int		num = 1;

	if (i == 4) {
		printf("pass");
		print_field();
		return 1;
	}
	
	while (num < 5)
	{
		if (!row_check(num, i, j) || !col_check(num, i, j))
		{
			num++;
			continue;
		}
		field[i][j] = num;
		print_field();
		if (j == 3 && from_right_check(i) && from_left_check(i) && back_track(i + 1, 0))
		{
			return 1;
			//field[i][j] = 0;	
		}
		else if (i == 3 && !col_check(num, i, j) && from_up_check(j) && from_down_check(j) && back_track(i, j + 1))
		{
			return 1;
			//field[i][j] = 0;
		}
		else 
		{
			if (back_track(i, j + 1))
			{
				return 1;
			}
		}
		field[i][j] = 0;	
		num++;
	}
	return 0;
}


int		isNum(char c)
{
	return ((c >= 49 && c <= 52) ? 1  : 0);
}


int		char_len(char *str)
{
	int 	i = 0;
	int 	re = 0;
	while (i < 32 && str[i] != 0)
	{		
		i++;
		re++;
	}
	printf("re=%d \n", re);
	return re;
}


int		main(int argc, char **argv)
{

	int		i = 0;
	int 	j = 0;
	int a = char_len(argv[1]);
	if (a != 31)
	{
		// 31文字ないときに出力
		printf("%d%s",a, "ERROR1");
		return 0;
	}
	while (i < 4)
	{
		while (j < seg[i])
		{
			int m = (j % 8) / 2;
			if (j % 2 == 0)
			{
				if (i == 0)
				{
					g_up_box[m] = (argv[1][j] - '0');
				}
				else if (i == 1)
				{
					g_down_box[m] = (argv[1][j] - '0');
				}
				else if (i == 2)
				{
					g_left_box[m] = (argv[1][j] - '0');
				}
				else
				{
					g_right_box[m] = (argv[1][j] - '0');
				}
			}
			j++;
		}
		i++;
	}	
	if (!back_track(0, 0))
	{
		// 与えられた引数で解がでないときに出力
		printf("%s", "ERROR2\n");
	}
	
	
	return 0;
}

