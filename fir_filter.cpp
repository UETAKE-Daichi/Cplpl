#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	char input_filename  = *argv[1];
	char output_filename = *argv[2];
	
	FILE *input_fp;
	FILE *output_fp;

	char input_data[100]; //入力文字列データ
	int data[100]; //入力整数データ用
	int out[100] ;
	int i = 0;
	int count=0;

	for(i = 0 ; i < 100;i++){
		data[i]=0;
		out[i]=0;
	}


	if ((input_fp = fopen(argv[1], "r")) == NULL)
    {
        printf("inputファイルが存在しません。プログラムを終了します。\n");
        exit(1);
    }
	
	
	if ((output_fp = fopen(argv[2], "w")) == NULL)
    {
        printf("outputファイルが存在しません。プログラムを終了します。\n");
        exit(1);
    }

	count = 9;
	//入力読み込み
	while(fgets(input_data, 100, input_fp ) != NULL ){
		data[count] =  atoi(input_data);
		count++;
		
	}
	

	//計算
	for(i = 9; i < 28; i++ ){
		out[i] = (480*data[i] +
				  268*data[i-1]+
				  145*data[i-2]+
				   71*data[i-3]+
				   35*data[i-4]+
				   13*data[i-5]+
				    6*data[i-6]+
					3*data[i-7]+
					2*data[i-8]+
				    1*data[i-9])/1024;
		printf("%d \n",out[i]);

		//fputs(out[i],output_fp);
	}



	
}
