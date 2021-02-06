#include <stdio.h>

int g_up_box[4];
int g_down_box[4];
int g_left_box[4];
int g_right_box[4];
char field[4][4];


int		from_up_check(int j)
{
	int		k = 0;
	int		max_count = 0;
	int		pro_val = (field[3][j] - '0');
	while (k <= 3)
	{
		if (pro_val < (field[k][j] - '0')
		{
			pro_val = field[i][k] - '0';
			max_count++;
		}
		k++;
	}
	return (max_count == g_up_box) ? 1 : 0;
}


int		from_down_check(int j)
{
	int		k = 2;
	int		max_count = 0;
	int		pro_val = (field[3][j] - '0');
	while (k <= 3)
	{
		if (pro_val < (field[k][j] - '0')
		{
			pro_val = field[k][j] - '0';
			max_count++;
		}
		k--;
	}
	return (max_count == g_down_box) ? 1 : 0;
}


int		from_left_check(int i)
{
	int		k = 0;
	int		max_count = 0;
	int		pro_val = (field[i][3] - '0');
	while (k <= 3)
	{
		if (pro_val < (field[i][k] - '0')
		{
			pro_val = field[i][k] - '0';
			max_count++;
		}
		k++;
	}
	return (max_count == g_left_box) ? 1 : 0;
}


int		from_right_check(int i)
{
	int		k = 2;
	int		max_count = 0;
	int		pro_val = (field[i][3] - '0');
	while (k >= 0)
	{
		if (pro_val < (field[i][k] - '0')
		{
			pro_val = field[i][k] - '0';
			max_count++;
		}
		k--;
	}
	return (max_count == g_right_box) ? 1 : 0;
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

int		col_check(int num, int i)
{
	int 	i_tmp = 0;

	while (i_tmp < 3)
	{
		if (field[i_tmp][3] == num) return 0;
		i_tmp++;
	}
	return 1;
}

void	print_field()
{
	int 	i = 0;
	int 	j = 0;

	while (i < 4)
	{
		while (j < 4)
		{
			(j == 3) ? printf("%s\n", field[i][j]) : printf("%s", field[i][j]);;
			j++;
		}
		i++;
	}

// 再帰を利用して数を入力
int		back_track(int i, int j)
{
	int		num = 1;

	if (i == 3 && j == 4) {
		print_field();
		return 1;
	}
	
	while (num < 5)
	{
		if (!row_check(num, i, j))continue;
		field[i][j] = num;	
		if (j == 3 && !from_right_check(i) && !from_left_check(i))
		{
			field[i][j] = 0;	
		}
		if (i == 3 && !col_check() && back_track(i + 1, j))
		{
			field[i][j] = 0;
		}
		if (back_track(i, j + 1))
		{
			field[i][j] = 0;	
		}
		
		num++;
	}
	return 0;
}


int		isNum(char c)
{
	return ((c >= 49 && c <= 52) ? 1  : 0);
}


int		char_len(char **str)
{
	int 	i = 0;
	int 	re = 0;
	while (i < 32)
	{
		
		i++;
	}
	return re;
}


int		main(int argc, char **argv)
{
	int		i = 0;
	
	if (char_len(argv) != 31)
	{
		printf("%s", "ERROR");
		return;
	}

	while (i < 32)
	(
		argv[i]
		if (i % 2 == 0 && )
		{
			
		}
		i++;
	)
	if (!back_track(0, 0))
	{
		printf("%s", "ERROR");
	}
}

