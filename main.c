#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int has_word(const char *, char[80]);

int main(){


	const char *str_values[5] = {"PSFKGRAPEYUVNSA", "GJWLSUNGWIOIGN", "GUTJUSTTSHJRUI", "DFINUADIFFUSEWG"};
	int x;
	char answer[80];
	int viewed = false;
	int wrongs = 0;
	int rights = 0;
	time_t time_now = 0;

	time_now = time(NULL);
	
	for(x = 0; x < 4; x++){

		if(viewed == false){

			system("clear");
			while(time_now + 2 > time(NULL)){
				
				printf("%s\n", str_values[x]);
			
				sleep(1);
				system("clear");
			}
			viewed = true;
		}

		if(viewed){
			printf("Enter the word you found: ");
			scanf("%s", answer);
			int b_word = has_word(str_values[x], answer);
			
			if(b_word == 0){
				system("clear");
				rights += 1;
				printf("You got it right! Answer: %s\n", answer);
			}
			if(b_word != 0){
				system("clear");
				wrongs += 1;
				printf("You got it wrong. [%d/4] wrong answers.\n", wrongs);
			}

			if(rights >= 4 || wrongs >= 4){
				break;
			}

			for(int i = 1; i <= 3; i++){
				
				printf("Next letters in: %d\n", i);
				sleep(1);
			}


			viewed = false;
			time_now = time(NULL);
		}

		

	}

	system("clear");	
	if(rights > wrongs){
		printf("YOU WON!!\n");
	} else {
		printf("You lost... \n[%d/4] wrong answers.\n", wrongs);	
	}


	return 0;
}


int has_word(const char *str_values, char answer[80]){
	
	for(int i = 0; i < strlen(answer); i++){
		answer[i] = toupper(answer[i]);
	}

	char *str_pos = strstr(str_values, answer);
	if(str_pos == NULL){
		return -1;
	} else {

		return 0;
	}


}
