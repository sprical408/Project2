#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm time1, time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    stat("text1",&stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
	stat("text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    time1 = *localtime(&stat1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    time2 = *localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    int size1 = (int)stat1.st_size;
    int size2 = (int)stat2.st_size;

    printf("size compare\n");

    if(size1>size2){
        printf("text1 is bigger\n\n");
    }
    else if(size1<size2){
        printf("text2 is bigger\n\n");
    }
    else
        printf("sizes are equal\n\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    int block1 = (int)stat1.st_blocks;
	int block2 = (int)stat2.st_blocks;

	printf("block compare\n");

	if(block1 < block2) {
		printf("text2 is bigger\n\n");
	} else if(block1 > block2) {
		printf("text1 is bigger\n\n");
	} else {
		printf("same size\n\n");
	}

}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    int mon_1 = time1.tm_mon;
    int day_1 = time1.tm_mday;
    int mon_2 = time2.tm_mon;
    int day_2 = time2.tm_mday;

    printf("date compare\n");

    if(mon_1>mon_2){
        printf("text2 is early\n\n");
    }
    else if(mon_1<mon_2){
        printf("text1 is early\n\n");
    }
    else
    {
        if(day_1>day_2){
            printf("text2 is early\n\n");
        }
        else if(day_1<day_2){
            printf("text1 is early\n\n");
        }
        else
            printf("same time\n\n");
        
    }
    
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
   int hour_1 = time1.tm_hour;
   int min_1 = time1.tm_min;
   int hour_2 = time2.tm_hour;
   int min_2 = time2.tm_min;


   printf("time compare\n");
   if(hour_1 > hour_2) {
	   printf("text2 is early\n\n");
   } else if(hour_1 < hour_2) {
	   printf("text1 is early\n\n");
   } else {
	   if(min_1 > min_2) {
		   printf("text2 is early\n\n");
	   } else if(min_1 < min_2) {
		   printf("text1 is early\n\n");
	   } else {
		   printf("same time\n\n");
	   }
   }
}
