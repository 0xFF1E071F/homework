//��1.ͳ����ĸ��ʹ��Ƶ��
 
#include<stdio.h>
#include<ctype.h>

//ת����Сд��ĸ
void lower(char *str){
	int i;
	for(i = 0; str[i] != '\0'; i++){
		if(isupper(str[i]))
			str[i] += 32;
	}
}

//ͳ�Ƹ���ĸ���ֵ�Ƶ��
void count(char *str, int *arr){
	int i, tmp;
	for(i = 0; str[i] != '\0'; i++){
		tmp = str[i] - 'a';
		arr[tmp]++;
	}
}

//��ʼ����ĸ˳��
void initArr(int *arr){
	int i;
	for(i = 0; i < 26; i++)
		arr[i] = i;
}

//������������ֵ
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//����
void sort(int *_letters, int *arr){
	int i, j, k;
	for(i = 0; i < 25; i++){
		k = i; 
		for(j = i + 1; j < 26; j++){
			if(_letters[k] < _letters[j])
				k = j;
		}
		if(i != k){
			swap(&_letters[k], &_letters[i]);
			swap(&arr[k], &arr[i]);
		}
	}
}

void print(int *_letters, int *arr){
	int i;
	for(i = 0; i < 26; i++){
		printf("%c : %d\n", arr[i]+'a', _letters[i]);
	}
}

int main(){
	int letters[26] = {0};
	int Arr[26];	//������ĸ��˳��
	char string[200];
	gets(string);
	lower(string);
	count(string, letters);
	initArr(Arr);
	sort(letters, Arr);
	print(letters, Arr);
	return 0;
}
